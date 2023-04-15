#ifndef LIB_UTILS_H_
#define LIB_UTILS_H_

#include "stm32f1xx.h"

/**
 * @brief Power on peripheral devices needed for communication
 * and GPIO operations.
 */
void PowerPeripherals();

/**
 * @brief Implement a delay function.
 * @param del The number of cycles to delay.
 */
void Delay(int del);

/**
 * @brief Initialize PP GPIO on pin PA05.
 * @detail  This function configures pin PA05 as an output pin in push-pull
 * mode. This allows the pin to drive an LED or any other device that requires a
 * push-pull output.
 */
void InitLED();

/**
 * @brief Toggle the LED connected to pin PA05 every 500 ms.
 * @deatil This function toggles the state of pin PA05 every ~500 milliseconds
 */
void Blinky();

#endif
