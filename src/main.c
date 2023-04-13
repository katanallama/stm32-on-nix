/**
 * @file    main.c
 * @brief   This file contains the "Hello, World." for an STM32F103RB
 * @date    Date of creation: [insert date of creation]
 * @author  [insert author]
 *
 * This module initializes an ADC and sets up a GPIO pin on port A, pin 5 as an
 * output push-pull. The main function then toggles the state of the GPIO pin
 * every 500ms using a busy loop.
 */

#include "stm32f10x.h"

int main(void) {
  // Enable GPIOA clock
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

  // Set PA05 as output push-pull
  GPIOA->CRL &= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF5);
  GPIOA->CRL |= GPIO_CRL_MODE5_0;

  while (1) {
    // Toggle PA05 every 500 ms
    GPIOA->ODR ^= GPIO_ODR_ODR5;
    for (volatile int i = 0; i < 100000; i++)
      ;
  }
}
