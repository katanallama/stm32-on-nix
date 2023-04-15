/*
 * @file    main.c
 * @brief   This file contains the "Hello, World." for an STM32F103RB
 * @date    Date of creation: [insert date of creation]
 * @author  [insert author]
 *
 * This module initializes an the prints out a "Hello, World!" using the UART comms on the stm32
 * Any characters entered in the serial terminal will be echo'd back
 * Note: printf is overridden using __write, if not seeing output on the serial comm terminal, use
 * "\n" to flush the buffer.
 */

#include <stdio.h>
#include <uart.h>
#include <utils.h>

int main(void) {
  PowerPeripherals();
  InitLED();
  InitUart();

  printf("Hello, World!\n");
  while (1) {
    // Echo input over UART
    Echo();
    /* Blinky(); */
  }
}
