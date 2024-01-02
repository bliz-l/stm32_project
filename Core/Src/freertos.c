/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "relocate.h"
#include "tim.h"
#include "stm32f4xx_hal_tim.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
static uint16_t record;
extern float freq; 
extern float duty;
/* USER CODE END Variables */
/* Definitions for ComTask */
osThreadId_t ComTaskHandle;
const osThreadAttr_t ComTask_attributes = {
  .name = "ComTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for MainTask */
osThreadId_t MainTaskHandle;
const osThreadAttr_t MainTask_attributes = {
  .name = "MainTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartComTask(void *argument);
void StartMainTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of ComTask */
  ComTaskHandle = osThreadNew(StartComTask, NULL, &ComTask_attributes);

  /* creation of MainTask */
  MainTaskHandle = osThreadNew(StartMainTask, NULL, &MainTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartComTask */
/**
  * @brief  Function implementing the ComTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartComTask */
void StartComTask(void *argument)
{
  /* USER CODE BEGIN StartComTask */
  /* Infinite loop */
  for(;;)
  {
	// printf("ON Com Task\n");
  //   osDelay(1000);
	// printf("Com Task END\n");
  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 250);
  osDelay(2000);
  printf("freq: %f, duty: %f\n", freq, duty);
  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 500);
  osDelay(2000);
  printf("freq: %f, duty: %f\n", freq, duty);
  }
  /* USER CODE END StartComTask */
}

/* USER CODE BEGIN Header_StartMainTask */
/**
* @brief Function implementing the MainTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartMainTask */
void StartMainTask(void *argument)
{
  /* USER CODE BEGIN StartMainTask */
  /* Infinite loop */
  for(;;)
  {
	HAL_GPIO_TogglePin(LED_SIG_GPIO_Port, LED_SIG_Pin);
	printf("≤‚ ‘“ªœ¬∞…£°\n");
	printf("R\n");
    osDelay(2000);
  }
  /* USER CODE END StartMainTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

