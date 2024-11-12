#include <Wire.h>
#include <LiquidCrystal.h>
#include <DHT.h>

LiquidCrystal lcd(0x27, 20, 4);

#define DHTPIN 2         
#define DHTTYPE DHT11    

DHT dht(DHTPIN, DHTYPE);

void setup() {
  lcd.begin();               
  lcd.backlight();           
  dht.begin();               
}

void loop() {
  float temperature = dht.readHumidity();
  float humidity = dht.readTemperature();

  if ((humidity) || isnan(temperature)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error reading DHT");
    delay(2000);
    return;
  }
  
  lcd.setCursor(1, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(1, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.printf(" %");

  delay(2000);
}
