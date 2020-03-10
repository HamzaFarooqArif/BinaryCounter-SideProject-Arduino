//Global configuration
int maxDevices = 10;
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

void toBinaryPins(int val)
{
  if(val == 1)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  if(val == 2)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  if(val == 3)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  if(val == 4)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  if(val == 5)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  if(val == 6)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  if(val == 7)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  if(val == 8)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  if(val == 9)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  if(val == 10)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  if(val == 11)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  if(val == 12)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  if(val == 13)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  if(val == 14)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  if(val == 15)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  }
  if(mypulse < threshold && isPushed)
  {
    isPushed = false;
  }
  toBinaryPins(counter);
  Serial.println(counter);
}
