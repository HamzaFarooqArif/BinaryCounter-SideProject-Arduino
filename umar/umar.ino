#include <EEPROM.h>

//Global configuration
int maxDevices = 10;
int counter = 0;

//Sensor configuration
int threshold = 500;
int mypulse = 0;
bool isPushed = false;

//Led pin configuration
int led1=3;
int led2=8;
int led3=9;
int led4=10;

//Rom Configuration
int addr = 0;

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  
  counter = loadCounter();
}

void loop() {
  mypulse = analogRead(A0);
  if(mypulse > threshold && !isPushed)
  {
    isPushed = true;
    digitalWrite(LED_BUILTIN, LOW);
  }
  if(mypulse < threshold && isPushed)
  {
    if(counter < maxDevices)
    {
      counter++;  
    }
    else
    {
      counter = 1;
    }
    isPushed = false;
    digitalWrite(LED_BUILTIN, HIGH);
  }
  
  toBinaryPins(counter);
  writeToMemory(counter);
  
  Serial.println(counter);
}
