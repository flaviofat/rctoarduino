/* Created by Flávio Augusto Teixeira */

#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial btserial(10, 11); // RX | TX
Servo servo;  

void setup() {
   Serial.begin(9600);
   btserial.begin(9600);  // HC-05 default speed in AT command more
   //Serial.println("aee");
   servo.attach(9);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
 }

void loop() {
 
  if (btserial.available() > 0) {

    char command = (char)btserial.read();
    Serial.write(command);

     switch (command) {
      case 'F':
        //FORWARD
        servo.write(90);
        digitalWrite(4, HIGH);
        break;
      case 'B':
          //BACK
          servo.write(90);
          digitalWrite(3, HIGH);
          break;
        case 'L':
          //LEFT
          servo.write(1800);
          digitalWrite(4, LOW);
          digitalWrite(3, LOW); 
        break;
        case 'G':
          //LEFT FORWARD
          servo.write(180);
          digitalWrite(4, HIGH);
          break;
        case 'H':
          //LEFT BACK
          servo.write(180);
          digitalWrite(3, HIGH); 
          break;
        case 'R':
          //RIGHT
          servo.write(0);
          digitalWrite(4, LOW);
          digitalWrite(3, LOW); 
          break;
        case 'I':
          //RIGHT FORWARD
          servo.write(0);
          digitalWrite(4, HIGH); 
          break;
        case 'J':
          //RIGHT BACK
          servo.write(0);
          digitalWrite(3, HIGH); 
          break;
      default:
          //CENTRALIZE
          servo.write(90);
          digitalWrite(4, LOW);
          digitalWrite(3, LOW);  
    }
  }
}
