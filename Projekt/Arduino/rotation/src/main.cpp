#include <limits.h>
#include "functions.h"
#include <StaticThreadController.h>
#include <Wire.h>

void setup()
{
  // put your setup code here, to run once:
  pinMode(DIRECTION, OUTPUT);
  digitalWrite(DIRECTION, HIGH);
  pinMode(STP, OUTPUT);
  Serial.begin(9600,SERIAL_8E1);
  serwo.attach(SERVOPIN);
  serwo.write(sposition);
  Wire.setClock(400000);
  LightSensor.begin();
  delay(500);
}

StaticThreadController<5> tControler(&tRead, &tSendData, &tSetServoPosition, &tSetStepperPosition, &tReadBH);



void loop()
{
  tControler.run();
}



void ReadLight()
{
  Left_Down_Value = analogRead(LEFT_DOWN_PIN);
  Right_Down_Value = analogRead(RIGHT_DOWN_PIN);
  Left_Up_Value = analogRead(LEFT_UP_PIN);
  Right_Up_Value = analogRead(RIGHT_UP_PIN);
  values[0] = Left_Down_Value;
  values[1] = Right_Down_Value;
  values[2] = Left_Up_Value;
  values[3] = Right_Up_Value;
}

void SetStepperPosition()
{
  if (HorizontalDiff())
  {
    if (sposition > 90)
    {
      //left max
      if ((pos == 0) || (pos == 2))
      {
        digitalWrite(DIRECTION, HIGH);
        ++StepCounter;
      }
      else
      {
        digitalWrite(DIRECTION, LOW);
        --StepCounter;
      }
    }
    else
    {
      if ((pos == 1) || (pos == 3))
      {
        digitalWrite(DIRECTION, HIGH);
        ++StepCounter;
      }
      else
      {
        digitalWrite(DIRECTION, LOW);
        --StepCounter;
      }
    }
    digitalWrite(STP, state);
    state = !state;
  }
}

void SetServoPosition()
{
  if (VerticalDiff())
  {
    //down position max
    if ((pos == 0) || (pos == 1))
    {
      if (sposition > 0)
        serwo.write(--sposition);
    }
    else
    {
      if (sposition < 180)
        serwo.write(++sposition);
    }
  }
}

int16_t FindMax()
{
  int max_v = INT_MIN;
  int max_i = 0;
  for (uint16_t i = 0; i < sizeof(values) / sizeof(values[0]); i++)
  {
    if (values[i] > max_v)
    {
      max_v = values[i];
      max_i = i;
    }
  }
  return max_i;
}

char CRC8(const char *data, int len)
{
  char crc = 0x00;
  char extract;
  char sum;
  for (int i = 0; i < len; i++)
  {
    extract = *data;
    for (char tempI = 8; tempI; tempI--)
    {
      sum = (crc ^ extract) & 0x01;
      crc >>= 1;
      if (sum)
        crc ^= 0x8C;
      extract >>= 1;
    }
    data++;
  }
  return crc;
}

void SendData()
{
  I = Right_Up_Value/100;
  U = Left_Down_Value;
  int V = map(sposition, 0, 180, -60, 60);
  int16_t H = ( (( static_cast<int32_t>(StepCounter) * 180 ) / 1360) % 360 );
  data = String("H");
  data += String(H , DEC); //z wolframa rownanie 1367 krokow (*2 Counter) na 360 stopni
  data += String(" V");
  data += String(V, DEC);
  data += String(" L");
  data += String(L, DEC);
  data += String(" U");
  data += String(U, DEC);
  data += String(" I");
  data += String( I , DEC);
  data += String(" P");
  data += String(( U * I ), DEC);

  CRC = CRC8(data.c_str(), data.length());
  data += String(" CRC");
  data += String(CRC, DEC);
  data += String('\n');
  Serial.print(data);
}

