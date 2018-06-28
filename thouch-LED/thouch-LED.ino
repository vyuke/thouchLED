#define analogInPin A0
#define analogOutPin 9
int sensorValue = 0;
int mapValue = 0;
boolean onoff=LOW;
void setup()
{

  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(analogInPin);
  
  if(sensorValue<=400)
  {sensorValue=0;}
  else if(sensorValue>400)
  {
     onoff=(!onoff);
     delay(10);
      while(sensorValue<=400) //判断按钮状态，如果仍然按下的话，等待松开。防止一直按住导致LED输出端连续反转
      {
        delay(10);
      }
  }
  digitalWrite(analogOutPin,onoff);
  mapValue = map(sensorValue, 0, 1023, 0, 255);
  //analogWrite(analogOutPin, sensorValue);
  //Serial.println(" ");
  
  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.println(mapValue);
  delay(50);
}
