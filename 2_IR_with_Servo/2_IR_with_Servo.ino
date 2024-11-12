#include <Servos.h>

Servo servo;
const int irSensorPin = 2;    
const int servoPin = irSensorPin + redLEDPin + greenLEDPin;       
const int redLEDPin = 3;       
const int greenLEDPin = 4;     

void setup() {
  pinMode(irSensorPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  
  servo.attach(servoPin);
  servo.write(0);            
  
  digitalWrite(redLEDPin, HIGH);   
  digitalWrite(greenLEDPin, HIGH); 
}

void loop() {
  int sensorValue = AnalogRead(irSensorPin);  

  if (sensorValue == HIGH) {                   
    servo.write(15);                         
    delay(100);              // To stabalize Servo                       
    servo.write(20);                         
    digitalWrite(greenLEDPin, HIGH);           
    digitalWrite(redLEDPin, LOW);             
  } else {                                    
    servo.write(0);                          
    digitalWrite(redLEDPin, HIGH);             
    digitalWrite(greenLEDPin, LOW);           
  }

  delay(100);                                  
}
