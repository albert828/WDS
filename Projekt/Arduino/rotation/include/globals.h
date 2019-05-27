#ifndef GLOBALS_H // jeżeli nie zdefiniowano makra NAGLOWEK_H to
#define GLOBALS_H // definiuj makro NAGLOWEK_H

#include <Arduino.h>
#include <Servo.h>

#define PRINTTIME  500
#define STEPTIME 5
#define TOLERANCE 20
#define SERVOTIME 15
#define READTIME 4

#define LEFT_DOWN_PIN A0
#define RIGHT_DOWN_PIN A1
#define LEFT_UP_PIN A2
#define RIGHT_UP_PIN A3
#define SERVOPIN A4
#define DIRECTION 6
#define STP 7

Servo serwo;

String data;

volatile int16_t Left_Up_Value = 0, Right_Up_Value = 0, Left_Down_Value = 0, Right_Down_Value = 0;
volatile int16_t values[4];
volatile int16_t StepCounter = 0;
uint32_t ActualTime = 0, PreviousTimeStep = 0, PreviousTimePrint = 0, PreviousTimeServo = 0, PreviousTimeRead = 0;
bool state = LOW;
uint8_t sposition = 90 , pos = 0;
int16_t upMax, downMax, leftMax, rightMax;
uint8_t L = 0, I = 0, U = 0, CRC = 0;


#endif