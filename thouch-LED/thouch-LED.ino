#define analogInPin A0
#define analogOutPin 9
int sensorValue = 0;
void setup()
{

  Serial.begin(115200);
}

void loop()
{
  sensorValue = analogRead(analogInPin);
  sensorValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPin, sensorValue);
  Serial.println(sensorValue);
  delay(10);
}
