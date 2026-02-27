#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 13, 12, 11, 10);

int greenLED = 4;
int yellowLED = 3;
int redLED = 2;
int sensorPin = 7;

void setup() {

  lcd.begin(16,2);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(sensorPin, INPUT_PULLUP); // IMPORTANT

  lcd.print("Smart Traffic");
  delay(2000);
  lcd.clear();
}

void loop() {

  int vehicle = digitalRead(sensorPin);

  if(vehicle == LOW) {   // button pressed

    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    lcd.setCursor(0,0);
    lcd.print("Vehicle Found ");
    lcd.setCursor(0,1);
    lcd.print("GREEN SIGNAL  ");
  }
  else {

    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    lcd.setCursor(0,0);
    lcd.print("No Vehicle    ");
    lcd.setCursor(0,1);
    lcd.print("RED SIGNAL    ");
  }
}