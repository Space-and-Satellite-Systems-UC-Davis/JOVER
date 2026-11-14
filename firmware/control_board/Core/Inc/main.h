/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DIR3_Pin GPIO_PIN_5
#define DIR3_GPIO_Port GPIOE
#define DIR4_Pin GPIO_PIN_3
#define DIR4_GPIO_Port GPIOC
#define DIR5_Pin GPIO_PIN_2
#define DIR5_GPIO_Port GPIOF
#define DIR6_Pin GPIO_PIN_4
#define DIR6_GPIO_Port GPIOA
#define NSS_Pin GPIO_PIN_4
#define NSS_GPIO_Port GPIOC
#define INT2_Pin GPIO_PIN_5
#define INT2_GPIO_Port GPIOC
#define INT1_Pin GPIO_PIN_0
#define INT1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOE
#define LED3_Pin GPIO_PIN_9
#define LED3_GPIO_Port GPIOE
#define LASER_Pin GPIO_PIN_11
#define LASER_GPIO_Port GPIOE
#define L_SW1_Pin GPIO_PIN_12
#define L_SW1_GPIO_Port GPIOE
#define L_SW2_Pin GPIO_PIN_13
#define L_SW2_GPIO_Port GPIOE
#define L_SW3_Pin GPIO_PIN_14
#define L_SW3_GPIO_Port GPIOE
#define LED5_Pin GPIO_PIN_15
#define LED5_GPIO_Port GPIOE
#define LED4_Pin GPIO_PIN_10
#define LED4_GPIO_Port GPIOB
#define LED6_Pin GPIO_PIN_11
#define LED6_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOB
#define NSS2_Pin GPIO_PIN_8
#define NSS2_GPIO_Port GPIOD
#define U_SW2_Pin GPIO_PIN_10
#define U_SW2_GPIO_Port GPIOD
#define U_SW1_Pin GPIO_PIN_11
#define U_SW1_GPIO_Port GPIOD
#define TRI_G_Pin GPIO_PIN_12
#define TRI_G_GPIO_Port GPIOD
#define TRI_R_Pin GPIO_PIN_13
#define TRI_R_GPIO_Port GPIOD
#define TRI_B_Pin GPIO_PIN_14
#define TRI_B_GPIO_Port GPIOD
#define DIR1_Pin GPIO_PIN_3
#define DIR1_GPIO_Port GPIOB
#define DIR2_Pin GPIO_PIN_9
#define DIR2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
