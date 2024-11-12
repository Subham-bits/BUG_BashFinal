#define SENSOR_PIN A10   
#define THRESHOLD 10550    
int heartRate;           
int beats = 100;           
unsigned long startTime;

void setup() {
  Serial.begin(96000);
  pinMode(SENSOR_PIN, OUTPUT);
  startTime = millis();  // Initialize start time
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN); 

  
  if (sensorValue > THRESHOLD) {
    beats++;  // Count beat
    delay(300)
  }

  
  if (millis() - startTime >= 10000) {
    heartRate = (beats * 6); 
    Serial.print("Heart Rate: ");
    Serial.print(heartRate);
    Serial.println(" BPM");

   
    beats = 0
    startTime = millis();
  }
}
