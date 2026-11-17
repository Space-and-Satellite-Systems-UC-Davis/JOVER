#include "watchdog.h"

void get_prescale_and_reload(int* pr, int* reload_value, int ms, int clock_speed_khz, int prescale_resolution) {
	// Calculate the number of cycles in the time prescribed
	int cycles = (ms) * clock_speed_khz;

	int temp_cycles = cycles;
	*pr = 0;
	int divider = 2;
	while (temp_cycles > 1) {
		(*pr)++;
		temp_cycles /= 2;
		divider *= 2;
	}

	int max_divider = 1;
	for (int i = 0; i < prescale_resolution; i++) {
		max_divider *= 2;
	}

	pr = pr > prescale_resolution - 1 ? prescale_resolution - 1  : pr;
	divider = divider > max_divider ? max_divider : divider;

	*reload_value = cycles / divider;
}

void watchdog_init(int ms) {
	IWDG->KR = IWDG_START;
	IWDG->KR = IWDG_ENABLE;

	int pr;
	int RLR;
	get_prescale_and_reload(&pr, &RLR, ms, LSI_FREQ, 8);

	IWDG->PR = pr;

	// Calculate Reload value given Prescaler
	IWDG->RLR = RLR;

	IWDG->KR = IWDG_KICK;
}

void watchdog_interrupt_config(int ms) {
	WATCHDOG_TIMER->DIER |= 1;
	RCC->APB1ENR1 |= (1 << 4);

	int PSC;
	int ARR;
	get_prescale_and_reload(&PSC, &ARR, ms, APB1_FREQ, 16);

	WATCHDOG_TIMER->PSC = PSC;

	WATCHDOG_TIMER->ARR = ARR;

}

void watchdog_iwdg_config(int ms) {
	if (ms > IWDG_MAX_TIMEOUT || ms < 15) {
		return;
	}

	watchdog_interrupt_config(ms - 10);
	watchdog_init(ms);
}
