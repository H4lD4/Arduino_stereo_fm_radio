#include <LiquidCrystal.h>
#include <Wire.h>
#include <TEA5767Radio.h>

TEA5767Radio radio = TEA5767Radio();
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int startFrequencyInt = 8700;
int endFrequencyInt = 10700;
int frequencyInt = 0;
float previousFrequency = 0;

void setup()
{
  startRadio();
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop()
{
  int valueA1 = 0;
  
  for(int i=0;i<30;i++)
  {
     valueA1 = valueA1 + analogRead(A1);   
     delay(1);
  }

  valueA1 = valueA1 / 30;
  frequencyInt = map(valueA1, 2, 1014, startFrequencyInt, endFrequencyInt); // Analog value from 87.0 MHz to 107.00MHz
  float frequency = frequencyInt / 100.0f;
  
  if(frequency - previousFrequency >= 0.1f || previousFrequency - frequency >= 0.1f)
  {
    radio.setFrequency(frequency);
    
    // clear display to remove doubled characters
    if (frequency < 100.0f && previousFrequency >= 100.0f) lcd.clear();
    
    previousFrequency = frequency;
  }
  
  printStationName(frequency);
  printFrequency(frequency);
}

void startRadio()
{
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
  Wire.begin();
  lcd.print("Welcome");
  delay(1000);
  lcd.clear();
  lcd.print("starting radio");
  delay(1000);
  lcd.clear();
}

void printStationName(float frequency)
{
  lcd.setCursor(0, 0);

  if(frequency >= 87.50f && frequency <= 87.70f) {
    lcd.print("Impuls");
  }
  else if(frequency >= 90.30f && frequency <= 90.50f) {
    lcd.print("CR Vltava");
  }
  else if(frequency >= 92.50f && frequency <= 92.65f) {
    lcd.print("CR Plus");
  }
  else if(frequency >= 93.00f && frequency <= 93.20f) {
    lcd.print("CR Brno");
  }
  else if(frequency >= 94.00f && frequency <= 94.20f) {
    lcd.print("Dalnice");
  }
  else if(frequency >= 95.00f && frequency <= 95.20f) {
    lcd.print("CR Radiozurnal");
  }
  else if(frequency >= 96.70f && frequency <= 96.90f) {
    lcd.print("Country Morava");
  }
  else if(frequency >= 97.50f && frequency <= 97.70f) {
    lcd.print("Hey Radio");
  }
  else if(frequency >= 101.90f && frequency <= 102.10f) {
    lcd.print("CR Dvojka");
  }
  else if(frequency >= 102.90f && frequency <= 103.10f) {
    lcd.print("Radio Krokodyl");
  }
  else if(frequency >= 103.30f && frequency <= 103.50f) {
    lcd.print("Radio Petrov");
  }
  else if(frequency >= 104.40f && frequency <= 104.60f) {
    lcd.print("Frekvence 1");
  }
  else if(frequency >= 105.40f && frequency <= 105.60f) {
    lcd.print("Evropa 2");
  }
  else if(frequency >= 106.40f && frequency <= 106.60f) {
    lcd.print("CR Brno");
  }
  else {
    lcd.print("                ");
  }
}

void printFrequency(float frequency)
{
  lcd.setCursor(0, 1);
  lcd.write(183);    // Japanese character that looks like an antenna
  lcd.print(" FM ");
  lcd.print(frequency,1);
  lcd.print(" MHz ");
}
