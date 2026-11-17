#include "stm32g474xx.h"
#include "TestDefinition.h"
#include "watchdog.h"
#include "Timers/systick.h"
#include "GPIO/tests.h"

TestStatus testFunction_Watchdog_Reset() {
	watchdog_init(2000);
	systick_init(1000);

	systick_delay_ticks(2100);

	gpio_test2();

	return FAIL;
}
