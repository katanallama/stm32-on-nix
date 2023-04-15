#ifndef LIB_UART_H_
#define LIB_UART_H_

#include "stm32f1xx.h"
#include <string.h>

void PowerPeripherals();

/**
 * @brief Initializes the USART2 peripheral on the STM32 microcontroller for
 * UART communication
 * @details This function sets the system clock frequency, enables the USART2
 * peripheral clock, and configures GPIOA pins 2 and 3 for USART2 RX and TX. It
 * also sets the baud rate to 230400 and enables the USART2 receiver,
 * transmitter, and peripheral.
 */
void InitUart(void);

/**
 * @brief Gets the next byte of input from the USART2 peripheral
 * @details This function waits until a byte is available on the USART2
 * peripheral and returns the byte.
 * @return The next byte of input from the USART2 peripheral, in uint8_t
 */
uint8_t GetInputUart();

/**
 * @brief Sends data over the USART2 peripheral
 * @details This function is used by printf to send data over the USART2
 * peripheral. It waits until the transmit buffer is empty and then sends each
 * byte of data in sequence.
 * @param[in] handle The handle for the stream (ignored)
 * @param[in] data The data to send
 * @param[in] size The number of bytes to send
 * @return The number of bytes successfully sent
 */
int _write(int handle, char *data, int size);

/**
 * @brief Continuously reads received characters from USART2 and prints them
 * @details This function continuously waits for a character to be received on
 * USART2 and prints it using printf.
 */
void Read();

/**
 * @brief Echos characters received over USART2
 * @details This function waits for a character to be received on USART2, then
 * echoes it back by writing it to the USART2 transmit data register. It
 * continues to wait for and echo characters in an infinite loop.
 */
void Echo();

/**
 * @brief USART2 interrupt handler
 * @details This function handles interrupts for USART2, specifically the
 * 'Receive register not empty' interrupt. It reads data from the receive data
 * register and copies it into a buffer.
 */
void USART2_IRQn_handler(void);

#endif
