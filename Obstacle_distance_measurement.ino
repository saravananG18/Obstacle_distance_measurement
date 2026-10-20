#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trigPin = 9;
int echoPin = 10;
int ledPin = 7;
int buzzerPin = 6;

long duration;
float distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}

void loop()
{
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Measure ECHO time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.0343 / 2;

  // Display distance
  lcd.setCursor(0, 0);
  lcd.print("Distance:       ");

  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm     ");

  // LED and buzzer
  if (distance < 10)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }
  else if (distance < 30)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, LOW);
  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(100);
}