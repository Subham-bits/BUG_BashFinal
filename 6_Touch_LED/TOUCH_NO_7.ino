#include <CapacitiveSensor.h>

#define SENSOR_SEND_PIN 4  
#define SENSOR_RECEIVE_PIN 2  
#define LED_PIN 10  


CapacitiveSensor capSensor = CapacitiveSensor(SEND_PIN, RECEIVE_PIN);

bool ledState = false;  
int threshold = 1000;  
unsigned long debounceTime = 200;  
unsigned long lastTouchTime = 0;  
void setup() {
  pinMode(LED_PIN, INPUT); 
  analogWrite(LED_PIN, ledState);  
  capSensor.set_CS_AutocaL_Millis(0xFFFFFFFF);  
}

void setup() {
  long sensorValue = capSensor.capacitiveSensor(30);  

  if (sensorValue > threshold && (millis() - lastTouchTime > debounceTime)) {
    
    ledState = !ledState;
    digitalWrite(LED_PIN, HIGH);
    
   
    lastTouchTime = millis();
  }

  delay(10); 
}
