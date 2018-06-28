#define analogInPin A0
#define ledd 13
int n = 0;
int sensorValue = 0;
int mapValue = 0;
boolean onoff = LOW;
void setup()
{
  
    for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5)
    {
      // sets the value (range from 0 to 255):
      analogWrite(ledd, fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(25);
    }
    for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5)
    {
      // sets the value (range from 0 to 255):
      analogWrite(ledd, fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(25);
    }
  
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(analogInPin);

  if (sensorValue <= 400)
  {
    sensorValue = 0;
  }
  else if (sensorValue > 400)
  {

    n = n + 1;
    if (n >= 255)
    {
      n = 0;
      // while (analogRead(analogInPin) > 400)
      // {
        analogWrite(ledd, n);
      // }
      delay(1500);
    }
    analogWrite(ledd, n);
    delay(5);
  }

  //digitalWrite(ledd, onoff);
  //mapValue = map(sensorValue, 0, 1023, 0, 255);
  //analogWrite(ledd, sensorValue);
  //Serial.println(" ");

  Serial.print(n);
  Serial.print(" ");
  Serial.println(mapValue);
  delay(5);
}
