#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define RELAY_PIN 8
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  delay(100);

  Wire.begin(); 

  lcd.init();
  lcd.backlight();

  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
 
  delay(2000);
}

void loop() {
  lcd.clear();

  float temperature = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.print(" C");

  fanSwitch(temperature);

  delay(6000);
}

void fanSwitch(float temperature) {
  if (temperature >= 30.0) {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Fan is on.");
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Fan is off.");
  }
}