/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include <stdint.h>
#include <string.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int ifPin = 0, ifId = 1, ifOperacja = 0, ifKwota = 0;

char* klawiter(){
	while(1){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, 1);
		//1
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){}
			return '1';
		}

		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){}
			return '2';
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){}
			return '3';
		}

		//2
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 0);
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){}
			return '4';
		}

		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){}
			return '5';
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){}
			return '6';
		}

		//3
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){}
			return '7';
		}

		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){}
			return '8';
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){}
			return '9';
		}

		//4
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, 0);
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){}
			return '*';
		}

		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){}
			return '0';
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){}
			return '#';
		}
	}

}

void getuid(char * uid){
	char temp;
	for(int i=0; i<8; i++){ //zakladajac ze uid ma 8 znakow, znowu nie pamietam ile mialo
			temp = klawiter();
			uid[i] = temp;
		}
}

void pin(char * pin){
	char temp;

	for(int i=0; i<4; i++){
		temp = klawiter();
		pin[i] = temp;
	}

}

void getPin(char * pin){
	char temp[4];
	//tutaj musi byc pobranie poprawnego pinu od wifi i zapisanie do temp
	while(IfPin != 1){
	pin(pin); //wczytanie pinu od użytkownika
	if(pin == temp) ifPin = 1; //jak jest dobry to super pętla się kończy, tylko nwm czy iteracyjnie nie bedzie trzeba porównać
	else {
		//i tu wyslanie informacji o błędzie na serwer żeby wyświetliło się użytkownikowi, że musi jeszcze raz wpisać go
	}}

}

char getOperacja(){
	char op = klawiter();
	while(ifOperacja != 1){
	if(op == '1' || op == '2' || op == '3')
	ifOperacja = 1;
	else {
		//wyslanie informacji na serwer, poproszenie uzytkownika o wpisanie numeru operacji jeszcze raz
	}}

	return op;
}

void getKwota(char * kwota){
int pom = 0;
while(pom != 1){
	char ilosc = klawiter();
if(ilosc > 48 && ilosc < 54) //sprawdzenie czy miesci sie miedzy 1 a 5
pom = 1;
else {
	//na serwer - blad, nie ma takiej opcji, wpisz jeszcze raz
}}
	switch(ilosc){
		case '1':{
			kwota[2] = '2'; //20
			ifKwota = 1;
			break;
		}
		case '2':{
			kwota[2] = '5'; //50
			ifKwota = 1;
			break;
		}
		case '3':{
			kwota[1] = '1'; //100
			ifKwota = 1;
			break;
		}
		case '4':{
			kwota[1] = '2'; //200
			ifKwota = 1;
			break;
		}
		case '5':{ //kwota niestandardowa
			char temp;
			int licznik = 0;
			//int liczba = 0;

			while(temp != '#' && licznik < 4){
				temp = klawiter();
				kwota[licznik] = temp;
				licznik++;
			}

			ifKwota = 1;

			if(kwota[licznik-2] != 0){
				ifKwota = 0;
			}

			break;
		}
	}
}

void getData(){
	char pin[4];
	char uid[8];
	char kwota[4] = {'0', '0', '0', '0'};
	char operacja;

	if(ifId == 1){
		getPin(pin);
	}


	if(ifPin == 1 && ifId == 1){
		operacja = getOperacja();
		//wyslanie informacji o wybranej operacji na serwer
	}
	if(ifPin == 1 && ifId == 1 && ifOperacja == 1 && operacja == '3'){ //zakladajac ze przelew jest jako operacja 3
		getuid(uid);
		//wyslanie uid na serwer
		// odebranie informacji czy istnieje taki użytkownik, jak nie to powtorzyc getuid() potem jakas tu petle wstawic
		getKwota(kwota);
		//wyslanie info na serwer
	}

	else if(ifPin == 1 && ifId == 1 && ifOperacja == 1){ //tu pojdzie reszta operacji
		getKwota(kwota);
		//wyslanie kwoty na serwer
	}
	//zerowanie flag
}
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
  while (1)
  {



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

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC6 PC8 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PD0 PD1 PD2 PD3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
