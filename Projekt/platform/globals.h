#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtGlobal>
/**
 * @brief Contains value of the vertical rotation angle
 * 
 */
volatile extern int32_t V; 
/**
 * @brief Contains value of the horizontal rotation angle
 * 
 */
volatile extern int32_t H;
/**
 * @brief Contains light value in lux
 * 
 */
volatile extern int32_t L;
/**
 * @brief Contains current flow value in mA
 * 
 */
volatile extern int32_t I;
/**
 * @brief Contains voltage value in mV
 * 
 */
volatile extern int32_t U;
/**
 * @brief Cotains power value in mW
 * 
 */
volatile extern int32_t P;

#endif // GLOBALS_H
