#include <Arduino.h>
#define DIRECTION 6
#define STP 7
#define STEPTIME 50

uint32_t ActualTime = 0, PreviousTimeStep = 0;
int16_t StepCounter = 0;
bool state = LOW;


void setup()
{
  pinMode(DIRECTION, OUTPUT);
  digitalWrite(DIRECTION, HIGH);
  pinMode(STP, OUTPUT);
  Serial.begin(9600);
  pinMode(DIRECTION, OUTPUT);
  digitalWrite(DIRECTION, HIGH);
  pinMode(STP, OUTPUT);
}

void loop()
{
  ActualTime = millis();
  if ((ActualTime - PreviousTimeStep) >= STEPTIME)
  {
    PreviousTimeStep = ActualTime;
    ++StepCounter;
  digitalWrite(STP, state);
  state = !state;
    Serial.println(StepCounter);
  }
}