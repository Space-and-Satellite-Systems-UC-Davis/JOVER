#include "spi.h"

void SPI1_Init(void) {
    /* 1. Enable GPIO and SPI clocks via RCC */

    /* 2. Configure GPIO pins (MODER, AFR, OSPEEDR) for SCK, MISO, MOSI */

    /* 3. Configure SPI Control Registers (CR1, CR2) for baud rate, master mode, etc. */

    /* 4. Enable SPI */
}

uint8_t SPI1_TransmitReceive(uint8_t data) {
    /* Wait for TXE (Transmit buffer empty), send data, wait for RXNE, return data */
    return 0;
}

