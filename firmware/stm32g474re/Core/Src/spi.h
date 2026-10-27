#ifndef SPI_H
#define SPI_H

#include "stm32g4xx.h"

/* Function Prototypes */
void SPI1_Init(void);
uint8_t SPI1_TransmitReceive(uint8_t data);

#endif /* SPI_H */
