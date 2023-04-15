#include "uart.h"
#include <stdio.h>

volatile char input = '\0';


void InitUart(void) {
  SystemCoreClock = 8000000;
  RCC->APB1ENR |= (RCC_APB1ENR_USART2EN);
  GPIOA->CRL &=
      ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2 | GPIO_CRL_MODE3 | GPIO_CRL_CNF3);
  GPIOA->CRL |=
      (GPIO_CRL_MODE2_0 | GPIO_CRL_CNF2_1 | GPIO_CRL_MODE3 | GPIO_CRL_MODE3_0);

  uint16_t usartdiv = SystemCoreClock / 230769;
  USART2->BRR = (((usartdiv / 16) << USART_BRR_DIV_Mantissa_Pos) |
                 ((usartdiv % 16) << USART_BRR_DIV_Fraction_Pos));
  USART2->CR1 |= (USART_CR1_RE | USART_CR1_TE | USART_CR1_UE);
}

uint8_t GetInputUart() {
  while (!(USART2->SR & USART_SR_RXNE)) {
  };
  input = USART2->DR;
  /* printf("\n%c\n", input); */
  return input;
}

int _write(int handle, char *data, int size) {
  int it = size;
  while (it--) {
    while (!(USART2->SR & USART_SR_TXE)) {
    };
    USART2->DR = *data++;
  }
  return size;
}

void Read() {
  while (1) {
    __WFI();
    printf("%c\n", input);
  }
}

void Echo() {
  while (1) {
    while (!(USART2->SR & USART_SR_RXNE)) {
    };
    printf("%c\n", USART2->DR);
  }
}

void USART2_IRQn_handler(void) {
  if (USART2->SR & USART_SR_RXNE) {
    input = USART2->DR;
  }
}
