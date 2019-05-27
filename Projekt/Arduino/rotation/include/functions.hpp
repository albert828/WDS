#ifndef FUNCTIONS_HPP // jeżeli nie zdefiniowano makra NAGLOWEK_H to
#define FUNCTIONS_HPP // definiuj makro NAGLOWEK_H

#include<globals.h>

void ReadLight();
void SetServoPosition();
void SetStepperPosition();
int16_t FindMax();
char CRC8(const char *data,int len);
void SendData();

inline bool VerticalDiff()
{
  upMax = ( values[2] > values[3] ? values[2] : values[3] );
  downMax = ( values[0] > values[1] ? values[0] : values[1] );
  return ( abs(upMax - downMax) > TOLERANCE ? true : false );
}

inline bool HorizontalDiff()
{
  leftMax = ( values[0] > values[2] ? values[0] : values[2] );
  rightMax = ( values[1] > values[3] ? values[1] : values[3]);
  return ( abs(leftMax - rightMax) > TOLERANCE ? true : false);
}
#endif