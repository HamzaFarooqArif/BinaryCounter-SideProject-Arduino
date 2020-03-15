//Global configuration
int maxDevices = 15;
int counter = 0;

//Sensor configuration
int threshold = 500;
int mypulse = 0;
bool isPushed = false;

//Led pin configuration
int led1=4;
int led2=5;
int led3=6;
int led4=7;

//Rom Configuration
int chipEnable = 8;
int writeEnable = 9;

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

void loadCounter()
{
  int ledRead1 = analogRead(A4);
  int ledRead2 = analogRead(A3);
  int ledRead3 = analogRead(A2);
  int ledRead4 = analogRead(A1);

  if(ledRead1 < threshold && ledRead2 < threshold && ledRead3 < threshold && ledRead4 < threshold)
  {
    counter = 0;
  }
  else if(ledRead1 > threshold && ledRead2 < threshold && ledRead3 < threshold && ledRead4 < threshold)
  {
    counter = 1;
  }
  else if(ledRead1 < threshold && ledRead2 > threshold && ledRead3 < threshold && ledRead4 < threshold)
  {
    counter = 2;
  }
  else if(ledRead1 > threshold && ledRead2 > threshold && ledRead3 < threshold && ledRead4 < threshold)
  {
    counter = 3;
  }
  else if(ledRead1 < threshold && ledRead2 < threshold && ledRead3 > threshold && ledRead4 < threshold)
  {
    counter = 4;
  }
  else if(ledRead1 > threshold && ledRead2 < threshold && ledRead3 > threshold && ledRead4 < threshold)
  {
    counter = 5;
  }
  else if(ledRead1 < threshold && ledRead2 > threshold && ledRead3 > threshold && ledRead4 < threshold)
  {
    counter = 6;
  }
  else if(ledRead1 > threshold && ledRead2 > threshold && ledRead3 > threshold && ledRead4 < threshold)
  {
    counter = 7;
  }
  else if(ledRead1 < threshold && ledRead2 < threshold && ledRead3 < threshold && ledRead4 > threshold)
  {
    counter = 8;
  }
  else if(ledRead1 > threshold && ledRead2 < threshold && ledRead3 < threshold && ledRead4 > threshold)
  {
    counter = 9;
  }
  else if(ledRead1 < threshold && ledRead2 > threshold && ledRead3 < threshold && ledRead4 > threshold)
  {
    counter = 10;
  }
  else if(ledRead1 > threshold && ledRead2 > threshold && ledRead3 < threshold && ledRead4 > threshold)
  {
    counter = 11;
  }
  else if(ledRead1 < threshold && ledRead2 < threshold && ledRead3 > threshold && ledRead4 > threshold)
  {
    counter = 12;
  }
  else if(ledRead1 > threshold && ledRead2 < threshold && ledRead3 > threshold && ledRead4 > threshold)
  {
    counter = 13;
  }
  else if(ledRead1 < threshold && ledRead2 > threshold && ledRead3 > threshold && ledRead4 > threshold)
  {
    counter = 14;
  }
  else if(ledRead1 > threshold && ledRead2 > threshold && ledRead3 > threshold && ledRead4 > threshold)
  {
    counter = 15;
  }
}

void writeToMemory()
{
  digitalWrite(chipEnable, HIGH);
  delay(1);
  digitalWrite(writeEnable, LOW);
  delay(1);
  digitalWrite(writeEnable, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  
  pinMode (chipEnable, OUTPUT);
  pinMode (writeEnable, OUTPUT);
  
  loadCounter();
}

void loop() {
  mypulse = analogRead(A0);
  if(mypulse > threshold && !isPushed)
  {
    if(counter < maxDevices)
    {
      counter++;  
    }
    else
    {
      counter = 1;
    }
    isPushed = true;
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if(mypulse < threshold && isPushed)
  {
    isPushed = false;
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  toBinaryPins(counter);
  writeToMemory();
  
  //Serial.println(counter);
}
