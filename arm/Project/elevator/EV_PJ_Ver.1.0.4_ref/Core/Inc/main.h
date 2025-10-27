/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define STEP2_IN6_Pin GPIO_PIN_0
#define STEP2_IN6_GPIO_Port GPIOC
#define STEP2_IN5_Pin GPIO_PIN_1
#define STEP2_IN5_GPIO_Port GPIOC
#define STEP2_IN7_Pin GPIO_PIN_2
#define STEP2_IN7_GPIO_Port GPIOC
#define STEP2_IN8_Pin GPIO_PIN_3
#define STEP2_IN8_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_1
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_4
#define LED3_GPIO_Port GPIOA
#define BTN1_Pin GPIO_PIN_5
#define BTN1_GPIO_Port GPIOA
#define BTN7_Pin GPIO_PIN_5
#define BTN7_GPIO_Port GPIOC
#define LED4_Pin GPIO_PIN_0
#define LED4_GPIO_Port GPIOB
#define STEP1_IN1_Pin GPIO_PIN_1
#define STEP1_IN1_GPIO_Port GPIOB
#define FNDB_Pin GPIO_PIN_10
#define FNDB_GPIO_Port GPIOB
#define STEP1_IN4_Pin GPIO_PIN_13
#define STEP1_IN4_GPIO_Port GPIOB
#define STEP1_IN3_Pin GPIO_PIN_14
#define STEP1_IN3_GPIO_Port GPIOB
#define STEP1_IN2_Pin GPIO_PIN_15
#define STEP1_IN2_GPIO_Port GPIOB
#define BTB6_Pin GPIO_PIN_6
#define BTB6_GPIO_Port GPIOC
#define FNDG_Pin GPIO_PIN_7
#define FNDG_GPIO_Port GPIOC
#define BTN5_Pin GPIO_PIN_8
#define BTN5_GPIO_Port GPIOC
#define BTN4_Pin GPIO_PIN_9
#define BTN4_GPIO_Port GPIOC
#define FNDA_Pin GPIO_PIN_8
#define FNDA_GPIO_Port GPIOA
#define FNDF_Pin GPIO_PIN_9
#define FNDF_GPIO_Port GPIOA
#define FNDDP_Pin GPIO_PIN_10
#define FNDDP_GPIO_Port GPIOA
#define BTN8_Pin GPIO_PIN_12
#define BTN8_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_15
#define BUZZER_GPIO_Port GPIOA
#define PHOTO1_Pin GPIO_PIN_10
#define PHOTO1_GPIO_Port GPIOC
#define PHOTO1_EXTI_IRQn EXTI15_10_IRQn
#define PHOTO2_Pin GPIO_PIN_11
#define PHOTO2_GPIO_Port GPIOC
#define PHOTO2_EXTI_IRQn EXTI15_10_IRQn
#define PHOTO3_Pin GPIO_PIN_2
#define PHOTO3_GPIO_Port GPIOD
#define PHOTO3_EXTI_IRQn EXTI2_IRQn
#define FNDC_Pin GPIO_PIN_3
#define FNDC_GPIO_Port GPIOB
#define FNDE_Pin GPIO_PIN_4
#define FNDE_GPIO_Port GPIOB
#define FNDD_Pin GPIO_PIN_5
#define FNDD_GPIO_Port GPIOB
#define I2C1_SCL_LCD_Pin GPIO_PIN_6
#define I2C1_SCL_LCD_GPIO_Port GPIOB
#define I2C1_SDA_LCD_Pin GPIO_PIN_7
#define I2C1_SDA_LCD_GPIO_Port GPIOB
#define BTN3_Pin GPIO_PIN_8
#define BTN3_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_9
#define BTN2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
