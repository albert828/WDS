#ifndef GLOBALS_H // jeżeli nie zdefiniowano makra NAGLOWEK_H to
#define GLOBALS_H // definiuj makro NAGLOWEK_H

#include <Arduino.h>
#include <Servo.h>
#include <Thread.h>
#include <Wire.h>
#include <BH1750FVI.h>

#define PRINTTIME  100
#define STEPTIME 5
#define TOLERANCE 20
#define SERVOTIME 15
#define READTIME 4
#define BHTIME 277

#define LEFT_DOWN_PIN A0
#define RIGHT_DOWN_PIN A1
#define LEFT_UP_PIN A2
#define RIGHT_UP_PIN A3
#define SERVOPIN A4
#define DIRECTION 6
#define STP 7

Servo serwo;

BH1750FVI LightSensor(BH1750_DEFAULT_I2CADDR, BH1750_CONTINUOUS_LOW_RES_MODE, BH1750_SENSITIVITY_DEFAULT, BH1750_ACCURACY_DEFAULT);

String data;

volatile int16_t Left_Up_Value = 0, Right_Up_Value = 0, Left_Down_Value = 0, Right_Down_Value = 0;
int16_t upMax, downMax, leftMax, rightMax;
volatile int16_t values[4];

volatile int16_t StepCounter = 0;
bool state = LOW;

uint8_t sposition = 90 , pos = 0;

uint8_t L = 0, I = 0, U = 0, CRC = 0;

uint32_t baudRate;

#endif