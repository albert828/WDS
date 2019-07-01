#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtGlobal>

/**
 * @brief Value of the vertical rotation angle in degrees
 * 
 */
volatile extern int32_t V = 0;
/**
 * @brief Value of the horizontal rotation angle in degrees
 * 
 */
volatile extern int32_t H = 0;
/**
 * @brief Value of the light intensivity in lx
 * 
 */
volatile extern int32_t L = 0;
/**
 * @brief Value of the current flow in mA
 * 
 */
volatile extern int32_t I = 0;
/**
 * @brief Value of the voltage in mV
 * 
 */
volatile extern int32_t U = 0;
/**
 * @brief Value of the recived power in mW
 * 
 */
volatile extern int32_t P = 0;

#endif // GLOBALS_H
