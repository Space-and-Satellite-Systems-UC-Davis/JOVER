#include "TestDefinition.h"
#include "print_scan.h"
#include <stdio.h>
#include <stdint.h>

/*
 * How to run:
 *   - Connect a serial terminal to USART1 TX
 *
 * Expected output:
 *   TEST printMsg: 42 hello
 *   TEST printByte text
 *   TEST printf: 7
 *   JOVER
 *   
 *
 * Returns NEEDS_VERIFICATION because a person has to check the terminal.
 */
TestStatus testFunction_print_scan() {
	
	printer_init();

	printMsg("TEST printMsg: %d %s\r\n", 42, "hello");

	const uint8_t text[] = {'T', 'E', 'S', 'T', ' ', 'p','r','i','n','t','B','y','t','e',' ','t','e','x','t','\r','\n' };
	printByte(text, sizeof text);

	printf("TEST printf: %d\r\n", 7);

	const uint8_t binary[] = { 0x4A, 0x4F, 0x56, 0x45, 0x52 };
	printByte(binary, sizeof binary);

	return NEEDS_VERIFICATION;
}
