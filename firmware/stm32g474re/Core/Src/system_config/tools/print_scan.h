

#ifndef REALOP1_PRINT_SCAN_H_
#define REALOP1_PRINT_SCAN_H_

/**
 * Initializes the internal systems needed for Console Printing
 *
 * @param none
 *
 * @returns none
 */
void printer_init();

/**
 * Prints a byte sequence to the console
 *
 * @param bytes The byte array to be printed
 *
 * @returns None
 */
void printByte(const uint8_t bytes[], size_t len);

/**
 * Prints a variable length string to the console
 *
 * @param message The string (character array) to be printed
 *
 * @returns None
 */
void printMsg(const char *message, ...);

#endif
