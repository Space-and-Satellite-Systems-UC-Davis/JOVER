#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <UART/uart.h>
#include "print_scan.h"


#define ConsoleUART 	USART1

//Bit Per Second
#define UART_BANDRATE 115200


void printer_init() {
    usart_init(ConsoleUART, UART_BANDRATE);
}

void printByte(const uint8_t bytes[], size_t len) {
    usart_transmitBytes(ConsoleUART, (const uint8_t*)bytes, len);
}

void printMsg(const char* message, ...) {
    char final[128];

    va_list args;
    va_start(args, message);
    vsnprintf(final, sizeof final, message, args);

    va_end(args);

    usart_transmitStr(ConsoleUART, final);
}

//Eats first printf fault
int __io_putchar(int ch) {
	uint8_t byte = (uint8_t)ch;
	usart_transmitBytes(ConsoleUART, &byte, 1);
	return ch;
}
