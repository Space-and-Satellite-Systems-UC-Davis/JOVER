#ifndef UART_H
#define UART_H

#include "stm32g474xx.h"
#include <stdint.h>
#include <stdbool.h>

#define GPIO_AFRX_AF7 0b0111UL
#define GPIO_AFRX_AF5 0b0101UL

/*
 * Initializes the UART hardware to conduct UART communication with
 * 1 start bit, 8 data bits, 1 stop bits, No parity
 *
 * @param bus        The USART Bus that needs initialization
 * @param baud_rate  The desired Baud Rate of the UART system
 *
 * @returns None
 */
bool usart_init(USART_TypeDef *bus, int baud_rate);

/*
 * Utilizes USART hardware transmitter to send a variable length string
 *
 * @param bus       The USART Bus doing the transmission
 * @param message   The string (character array) being sent
 *
 * @returns None
 */
void usart_transmitStr(USART_TypeDef *bus, uint8_t message[]);

/*
 * Utilizes USART hardware transmitter to send a fixed length byte stream
 *
 * @param bus       The USART Bus doing the transmission
 * @param message   The string (character array) being sent
 *
 * @returns None
 */
void usart_transmitBytes(USART_TypeDef *bus, uint8_t message[], int nbytes);

/*
 * Returns the status of the USART receiver's FIFO buffer
 *
 * @param None
 * @returns Whether the buffer has
 */
bool usart_receiveBufferNotEmpty(USART_TypeDef *bus);

/*
 * Utilizes the USART hardware receiver to get `size` number of bytes from a FIFO buffer.
 * Will wait for more bytes in case enough aren't available.
 * Incorporates a timeout system for safety.
 *
 * @param bus		The USART Bus that will be receiving
 * @param buffer	The buffer where the received bytes must be stored. Length is assumed to be >= `size`
 * @param size		The number of bytes to receive and store
 *
 * @returns			The number of bytes actually received and stored ( <= `size`)
 */
int usart_receiveBytes(USART_TypeDef *bus, uint8_t buffer[], uint16_t size);

/*
 * Empties the receive buffer.
 *
 * @param bus		The USART Bus that will be receiving
 */
void usart_flushrx(USART_TypeDef* bus);


#endif
