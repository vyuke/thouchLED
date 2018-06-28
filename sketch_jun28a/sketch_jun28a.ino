#define analogInPin A0
#define ledd 13
int n = 0;
int sensorValue = 0;
int mapValue = 0;
boolean onoff = LOW;
void setup()
{

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
    }
    analogWrite(ledd, n);
    delay(10);
  }

  //digitalWrite(ledd, onoff);
  //mapValue = map(sensorValue, 0, 1023, 0, 255);
  //analogWrite(ledd, sensorValue);
  //Serial.println(" ");

  Serial.print(n);
  Serial.print(" ");
  Serial.println(mapValue);
  delay(10);
}
