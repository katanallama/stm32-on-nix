#include <utils.h>

void PowerPeripherals() {
  RCC->APB1ENR |= (RCC_APB1ENR_USART2EN);
  RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN |
                   RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPDEN);
}

void Delay(int del) {
  unsigned volatile int c, d;
  for (c = 1; c <= del; c++) {
    for (d = 1; d <= del; d++) {
    }
  }
}

void InitLED() {
  GPIOA->CRL &= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF5);
  GPIOA->CRL |= GPIO_CRL_MODE5_0;
}

void Blinky() {
  // Toggle PA05 every 500 ms
  GPIOA->ODR ^= GPIO_ODR_ODR5;
  for (volatile int i = 0; i < 100000; i++)
    ;
}
