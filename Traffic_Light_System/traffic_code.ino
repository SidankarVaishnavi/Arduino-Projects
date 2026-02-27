#include <LiquidCrystal.h>

// LCD pins (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(9, 8, 13, 12, 11, 10);

// LED pins
int greenLED = 4;
int yellowLED = 3;
int redLED = 2;

void setup() {

  lcd.begin(16, 2);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  lcd.print("Traffic System");
  delay(2000);
  lcd.clear();
}

void loop() {

  // GREEN LIGHT
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);

  lcd.setCursor(0,0);
  lcd.print("GREEN LIGHT   ");
  delay(5000);

  // YELLOW LIGHT
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, LOW);

  lcd.clear();
  lcd.print("YELLOW LIGHT  ");
  delay(2000);

  // RED LIGHT
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);

  lcd.clear();
  lcd.print("RED LIGHT     ");
  delay(5000);
}