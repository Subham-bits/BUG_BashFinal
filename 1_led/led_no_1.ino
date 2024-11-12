void setup() {
 // pinMode(13,INPUT);
  
}
int buttonState = 0;
buttonState = digitalRead(15);
void loop() {
  for (int i = 9; i < 14; i++) { 
    
    delay(1000);
    digitalWrite(i, HIGH);
    
  }
   for (int i = 9; i < 14; i++) { 
    
    delay(1000);
    digitalWrite(i, LOW);
    
  }
 

  
  if (buttonState == 1) {

    digitalWrite(16, HIGH);
  } else {
    
    digitalWrite(13, LOW);
  }
}