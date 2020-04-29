#include <EEPROM.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 6, 2);

//Global configuration
int maxDevices = 10;

//Sensor configuration
int threshold = 500;
int sensorRead = 0;
int reverseRead = 0;

//Led pin configuration
int led1=3;
int led2=8;
int led3=9;
int led4=10;

//Rom Configuration
int addr = 0;

//Intermediate Variables
bool isPushed = false;
int counter = 0;

void toBinaryPins(int val)
{
  if(val == 0)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val == 1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val == 2)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val == 3)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if(val == 4)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if(val == 5)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if(val == 6)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if(val == 7)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if(val == 8)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  else if(val == 9)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  else if(val == 10)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  else if(val == 11)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  else if(val == 12)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  else if(val == 13)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  else if(val == 14)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  else if(val == 15)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}

int loadCounter()
{
  int val = EEPROM.read(addr);
  if(0 <= val && val <= maxDevices)
  {
    return val;
  }
  return 0;
}

void writeToMemory(int val)
{
  EEPROM.write(addr, val);
}

void updateCounter()
{
  sensorRead = analogRead(A0);
  reverseRead = analogRead(A1);
  
  if(sensorRead > threshold && !isPushed)
  {
    isPushed = true;
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if(sensorRead < threshold && isPushed)
  {
    isPushed = false;
    digitalWrite(LED_BUILTIN, HIGH);
    varyCounter(reverseRead);
  }
}

void varyCounter(int reverse)
{
  if(reverse > threshold)
  {
    if(counter == 1)
    {
      counter = maxDevices;
    }
    else
    {
      counter--;  
    }
  }
  else
  {
    if(counter == maxDevices)
    {
      counter = 1;
    }
    else
    {
      counter++;  
    } 
  }
}

void updateLcd()
{
  lcd.setCursor(8, 0);
  if(counter < 10)
  {
    lcd.print("0");
    lcd.print(counter);
  }
  else
  {
    lcd.print(counter);  
  }
  lcd.setCursor(8, 1);
  if(reverseRead > threshold)
  {
    lcd.print(" TRUE");
  }
  else
  {
    lcd.print("FALSE");
  }
}

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  counter = loadCounter();

  lcd.setCursor(0, 0);
  lcd.print("Tool Controller");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Counter:");
  lcd.setCursor(0,1);
  lcd.print("Reverse:");
}

void loop() {
  updateCounter();
  toBinaryPins(counter);
  writeToMemory(counter);
  updateLcd();
  //Serial.println(counter);
}
