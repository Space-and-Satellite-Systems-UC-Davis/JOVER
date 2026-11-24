# Table of Occupied Components on the Control Board

We have different components which are occupied by certain tasks. When selecting one of the listed component types, please consult the table to see if it's already being used elsewhere.

## Timers
| Component | Current usage | Can use? |
|-------|-----|-----|
| SysTick | FreeRTOS/Micro-ROS  | BUSY. Don't touch `SysTick_Config()`/`SysTick_Handler()` |
| HRTIM   | None  | YES | 
| LPTIM   | None  | YES | 
| TIM1   | None  | YES | 
| TIM2   | None  | YES | 
| TIM3   | Watchdog kick | BUSY | 
| TIM4   | None  | YES | 
| TIM5   | None  | YES | 
| TIM6   | None  | YES | 
| TIM7   | None  | YES | 
| TIM8   | None  | YES | 
| TIM15   | None  | YES | 
| TIM16   | None  | YES | 
| TIM17   | None  | YES | 
| TIM20   | None  | YES | 