/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LiquidCrystal.h"
#include <stdint.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

// ---- Testes (somente pode habilitar um por vez) ---------------------------*/
//#define AutoScroll
//#define Blink
//#define Cursor
//#define CustomCharacter
//#define Display
#define HelloWorld
//#define Scroll
//#define TextDirection
//#define SetCursor


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

#ifdef AutoScroll
  char buffer[10];
  LiquidCrystal lcd;
  begin(&lcd,16,2,LCD_5x8DOTS);
#endif

#ifdef Blink
  LiquidCrystal lcd;
  begin(&lcd,16,2,LCD_5x8DOTS);
  print(&lcd, "hello, world!");
#endif

#ifdef Cursor
  LiquidCrystal lcd;
  begin(&lcd,16,2,LCD_5x8DOTS);
  print(&lcd, "hello, world!");
#endif

#ifdef CustomCharacter
  // make some custom characters:
  unsigned char heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
  };

  unsigned char smiley[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000
  };

  unsigned char frownie[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b10001
  };

  unsigned char armsDown[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01010
  };

  unsigned char armsUp[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b01010
  };

  char buffer[10];
  LiquidCrystal lcd;
  begin(&lcd,16,2,LCD_5x8DOTS);

  // create a new character
  createChar(&lcd, 0, heart);
  // create a new character
  createChar(&lcd, 1, smiley);
  // create a new character
  createChar(&lcd, 2, frownie);
  // create a new character
  createChar(&lcd, 3, armsDown);
  // create a new character
  createChar(&lcd, 4, armsUp);

  // set the cursor to the top left
  setCursor(&lcd, 0, 0);

  // Print a message to the LCD.
  print(&lcd, "I ");
  write(&lcd,(unsigned char) 0); // when calling lcd.write() '0' must be cast as a byte
  print(&lcd," STM32! ");
  write(&lcd,(unsigned char)1);
#endif

#ifdef Display
  LiquidCrystal lcd;
  begin(&lcd,16,2,LCD_5x8DOTS);
  print(&lcd, "hello, world!");
#endif

#ifdef HelloWorld
  char buffer[10];
  LiquidCrystal lcd;
  begin(&lcd,16,2,LCD_5x8DOTS);
  print(&lcd, "hello, world!");
#endif

#ifdef Scroll
  LiquidCrystal lcd;
  begin(&lcd,16,2,LCD_5x8DOTS);
  print(&lcd, "hello, world!");
  HAL_Delay(1000);
#endif

#ifdef TextDirection
  int thisChar = 'a';
  LiquidCrystal lcd;
  begin(&lcd,16,2,LCD_5x8DOTS);
  cursor(&lcd);
#endif

#ifdef SetCursor
  char buffer[10];
  unsigned char col = 16;
  unsigned char row = 2;
  LiquidCrystal lcd;

  begin(&lcd,col,row,LCD_5x8DOTS);
#endif

  while (1){

	#ifdef AutoScroll
	  // set the cursor to (0,0):
		setCursor(&lcd, 0, 0);
		// print from 0 to 9:
		for (int thisChar = 0; thisChar < 10; thisChar++) {
			sprintf(buffer, "%d", thisChar);
			print(&lcd, buffer);
			HAL_Delay(500);
		}

		// set the cursor to (16,1):
		setCursor(&lcd, 16, 1);
		// set the display to automatically scroll:
		autoscroll(&lcd);
		// print from 0 to 9:
		for (int thisChar = 0; thisChar < 10; thisChar++) {
			sprintf(buffer, "%d", thisChar);
			print(&lcd, buffer);
			HAL_Delay(500);
		}
		// turn off automatic scrolling
		noAutoscroll(&lcd);

		// clear screen for the next loop:
		clear(&lcd);
	#endif

	#ifdef Blink
	  noBlink(&lcd);
	  HAL_Delay(2000);
	  blink(&lcd);
	  HAL_Delay(2000);
	#endif

	#ifdef Cursor
	  noCursor(&lcd);
	  HAL_Delay(2000);
	  cursor(&lcd);
	  HAL_Delay(2000);
	#endif

	#ifdef CustomCharacter
	  setCursor(&lcd, 4, 1);
	  // draw the little man, arms down:
	  write(&lcd,3);
	  HAL_Delay(500);
	  setCursor(&lcd, 4, 1);
	  // draw him arms up:
	  write(&lcd,4);
	  HAL_Delay(500);
	#endif

	#ifdef Display
	  noDisplay(&lcd);
	  HAL_Delay(2000);
	  display(&lcd);
	  HAL_Delay(2000);
	#endif

	#ifdef HelloWorld
	  setCursor(&lcd, 0, 1);
	  sprintf(buffer, "%d", HAL_GetTick()/1000);
	  print(&lcd, buffer);
	#endif

	#ifdef Scroll
	  // scroll 13 positions (string length) to the left
	  // to move it offscreen left:
	  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
	      // scroll one position left:
	      scrollDisplayLeft(&lcd);
	      // wait a bit:
	      HAL_Delay(150);
	  }

	  // scroll 29 positions (string length + display length) to the right
	  // to move it offscreen right:
	  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
		  // scroll one position right:
	      scrollDisplayRight(&lcd);
	      // wait a bit:
	      HAL_Delay(150);
	  }

	  // scroll 16 positions (display length + string length) to the left
	  // to move it back to center:
	  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
	      // scroll one position left:
	      scrollDisplayLeft(&lcd);
	      // wait a bit:
	      HAL_Delay(150);
	  }

	  // delay at the end of the full loop:
	  HAL_Delay(1000);
	#endif

	#ifdef TextDirection
	  // reverse directions at 'm':
	  if (thisChar == 'm') {
		// go right for the next letter
		rightToLeft(&lcd);
	  }
	  // reverse again at 's':
	  if (thisChar == 's') {
		// go left for the next letter
		leftToRight(&lcd);
	  }
	  // reset at 'z':
	  if (thisChar > 'z') {
		// go to (0,0):
		home(&lcd);
		// start again at 0
		thisChar = 'a';
	  }
	  // print the character
	  write(&lcd, thisChar);
	  // wait a second:
	  HAL_Delay(1000);
	  // increment the letter:
	  thisChar++;
	#endif

	#ifdef SetCursor
	  setCursor(&lcd, (col/2)/2, 0);

	  sprintf(buffer, "%dx%d", col,row);
	  print(&lcd, buffer);
	  HAL_Delay(1000);
	  clear(&lcd);

	  for (unsigned char i = 0; i < row; i++){
		  for (unsigned char j = 0; j < col; j++){
			  setCursor(&lcd, j, i);
			  sprintf(buffer, "%X", j);
			  print(&lcd, buffer);
			  HAL_Delay(250);
		  }
	  }
	  HAL_Delay(1000);
	  clear(&lcd);
	#endif

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin
                          |LCD_RS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD_EN_Pin|LCD_RW_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LCD_D7_Pin LCD_D6_Pin LCD_D5_Pin LCD_D4_Pin
                           LCD_RS_Pin */
  GPIO_InitStruct.Pin = LCD_D7_Pin|LCD_D6_Pin|LCD_D5_Pin|LCD_D4_Pin
                          |LCD_RS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_EN_Pin LCD_RW_Pin */
  GPIO_InitStruct.Pin = LCD_EN_Pin|LCD_RW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
