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
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int ifPin = 0, ifId = 1, ifOperacja = 0, ifKwota = 0;

char* klawiter(){

	uint8_t newline[1] = {10};
	uint16_t size = 1;
	uint8_t pom[1];

	while(1){
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, 1);
		//1
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/1",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '1';
		}

		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/2",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '2';
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/3",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '3';
		}

		//2
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 0);
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/4",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '4';
		}

		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/5",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '5';
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/6",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '6';
		}

		//3
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 0);
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/7",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '7';
		}

		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/8",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '8';
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/9",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '9';
		}

		//4
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, 0);
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/*",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '*';
		}

		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){
			while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/0",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '0';
		}

		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==0){}
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/sendKey/test/#",72 ,100);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			HAL_UART_Receive(&huart3, pom, 1, 500);
			return '#';
		}
	}

}

void getuid(char * uid){
	char temp;
	for(int i=0; i<12; i++){
			temp = klawiter();
			uid[i] = temp;
		}
}

void getpin(char * pin){
	char temp;

	for(int i=0; i<4; i++){
		temp = klawiter();
		pin[i] = temp;
	}

}

void getPin(char * pin){
	char temp[4];
	while(ifPin != 1){
	getpin(pin);
	HAL_Delay(50);
	if(strcmp(pin,temp)) ifPin = 1; 
	else {
		
	}}

}

char getOperacja(){
	char op = klawiter();
	while(ifOperacja != 1){
	if(op == '1' || op == '2' || op == '3'|| op == '4' || op == '5')
	ifOperacja = 1;

	else {
		
	}}

	return op;
}

void getKwota(char * kwota){
int pom = 0;
char ilosc;
while(pom != 1){
	ilosc = klawiter();
if(ilosc > 48 && ilosc < 54) //sprawdzenie czy miesci sie miedzy 1 a 5
pom = 1;
else {
	
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

char readId[83] = "GetHttpRequest:http://ptm23.azurewebsites.net/api/Device/setDisplay/test/cardread/0";

void getKwota2(char * kwota){
int pom = 0;

		//kwota niestandardowa
			char temp;
			int licznik = 0;
			

			while(temp != '#' && licznik < 4){
				temp = klawiter();
				kwota[licznik] = temp;
				licznik++;
			}

			ifKwota = 1;

			if(kwota[licznik-2] != 0){
				ifKwota = 0;

		}
	}




void UID (char * uid){
	uint8_t sendUART[9] = "GetLastId";
	uint8_t newline[1] = {10};
	uint16_t size = 1;
	uint16_t sizeSendUART = 9;
	uint16_t sizeReceiveUART = 1;
	uint8_t pom[1];
	int i = 0;

	//do{
	HAL_UART_Transmit(&huart3, sendUART, sizeSendUART, 50);
	HAL_Delay(10);
	HAL_UART_Transmit(&huart3, newline, size, 50);
	HAL_Delay(10);
	do
	{
		if(HAL_UART_Receive(&huart3, pom, sizeReceiveUART, 100) == HAL_OK){
		if(pom[0] == 10) break;
		uid[i] = pom[0];
		i++;
		}
		HAL_Delay(10);
	}while(i<12);
	//HAL_UART_Receive(&huart3, pom, sizeReceiveUART, 100);
	//HAL_UART_Receive(&huart3, pom, sizeReceiveUART, 100);
	//if(uid[0] != 110)break;
	HAL_Delay(2000);
	//}while(1);

}

void saldo(const char * id){
	uint8_t newline[1] = {10};
	uint16_t size = 1;
	HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/setDisplay/test/balance/", 82, 5000);
				HAL_UART_Transmit(&huart3, id, 12, 5000);
				HAL_UART_Transmit(&huart3, newline, size, 50);
}


void widok(int n){
	uint8_t newline[1] = {10};
	uint16_t size = 1;
//uint8_t pom[1];
	switch(n){
	case(1):
		HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/setDisplay/test/menu/0", 80, 5000);
	HAL_UART_Transmit(&huart3, newline, size, 50);
	break;
	case(2):
		HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/setDisplay/test/cardread/0", 84, 5000);
	HAL_UART_Transmit(&huart3, newline, size, 50);
	break;
	case(3):
		HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/setDisplay/test/deposit/0", 83, 5000);
	HAL_UART_Transmit(&huart3, newline, size, 50);
	break;
	case(4):
		HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/setDisplay/test/pin/0", 79, 5000);
	HAL_UART_Transmit(&huart3, newline, size, 50);
	break;
	case(5):
		HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/setDisplay/test/transfer/0", 84, 5000);
	HAL_UART_Transmit(&huart3, newline, size, 50);
	break;

	case(6):
		HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/setDisplay/test/withdrawal/0", 86, 5000);
	HAL_UART_Transmit(&huart3, newline, size, 50);
	break;
	}

	//HAL_UART_Receive(&huart3, pom, 1, 100);
	//HAL_UART_Receive(&huart3, pom, 1, 100);
	//HAL_UART_Receive(&huart3, pom, 1, 100);
	//HAL_UART_Receive(&huart3, pom, 1, 100);

}


void getData(const uint8_t * id){
	char pin2[4];
	char uid[8];
	char kwota[4] = {'0', '0', '0', '0'};
int koniec = 0;
	char operacja;
	uint8_t pin[4];
	uint8_t getpin[60] = "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/";
	uint8_t newline[1] = {10};
	uint8_t pinlast[4] = "/pin";
	uint16_t size2 = 60;
	uint16_t size = 1;
	uint8_t stankonta[4];
	uint8_t pom[1];
	int i = 0;


	widok(4);
	if(ifId == 1){
		getPin(pin2);
		HAL_Delay(15);
		HAL_UART_Transmit(&huart3, getpin, size2, 5000);
				HAL_Delay(15);
				HAL_UART_Transmit(&huart3, id, 12, 6000);
				HAL_Delay(15);
				HAL_UART_Transmit(&huart3, pinlast, 4, 5000);
				HAL_Delay(15);
				HAL_UART_Transmit(&huart3, newline, size, 50);
				HAL_Delay(15);
				HAL_UART_Receive(&huart3, pom, 1, 100);
		do{
			if(HAL_UART_Receive(&huart3, pom, 1, 100) == HAL_OK){
					if(pom[0] == 10) break;
					pin[i] = pom[0];
					i++;
			}}while(i<4);
		if(memcmp(pin,pin2,4) == 0){
			widok(1);
		}
		else{
			uint8_t error[93] = "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/showPopup/test/error/Z%C5%82y%20pin";
			HAL_UART_Transmit(&huart3, error, 93, 5000);
			ifPin = 0;
		}

		HAL_UART_Transmit(&huart3, newline, size, 50);
}

do{
	if(ifPin == 1 && ifId == 1){
		operacja = getOperacja();
		if(operacja == '5') {
		HAL_UART_Transmit(&huart3, "ClearLastId", 11, 5000);
		HAL_UART_Transmit(&huart3, newline, size, 50);
		HAL_UART_Receive(&huart3, pom, 1, 100);
		HAL_UART_Receive(&huart3, pom, 1, 100);
		HAL_UART_Receive(&huart3, pom, 1, 100);
		HAL_UART_Receive(&huart3, pom, 1, 100);
		koniec=1;
		}
	}


	if(ifPin == 1 && ifId == 1 && ifOperacja == 1 && operacja == '1'){ 
			saldo(id);
			klawiter();
			widok(1);
			//wyslanie kwoty na serwer
		}
	else if(ifPin == 1 && ifId == 1 && ifOperacja == 1 && operacja == '3'){ 
		widok(3);
		getKwota2(kwota);
		HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/",60, 5000);
		HAL_UART_Transmit(&huart3, id, 12, 5000);
		HAL_UART_Transmit(&huart3, "/balance", 8, 5000);
		i =0;
		HAL_UART_Receive(&huart3, pom, 1, 100);
		do{
		if(HAL_UART_Receive(&huart3, pom, 1, 100) == HAL_OK){
							if(pom[0] == 10) break;
							stankonta[i] = pom[0];
							i++;
					}}while(i<4);

		int wplata = atoi(kwota);
		int stan = atoi(stankonta);

			stan = (stan+wplata);
			itoa(stan, stankonta, 10);
			

			//GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/0/balance/{NowaKwota}

			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/",60, 5000);
			HAL_UART_Transmit(&huart3, id, 12, 5000);
			HAL_UART_Transmit(&huart3, "/balance/", 9, 5000);
			HAL_UART_Transmit(&huart3, stankonta, 4, 5000);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 50);
			HAL_UART_Receive(&huart3, pom, 1, 50);
			HAL_Delay(100);
			HAL_UART_Transmit(&huart3,"GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/showPopup/test/success/Transakcja%20przebieg%C5%82a%20pomy%C5%9Blnie",126,5000);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_Delay(100);
			HAL_UART_Receive(&huart3, pom, 1, 50);
			HAL_UART_Receive(&huart3, pom, 1, 50);
			HAL_Delay(100);
			widok(1);
			HAL_Delay(100);

		HAL_Delay(10);

		//wyslanie kwoty na serwer
	}

	else if(ifPin == 1 && ifId == 1 && ifOperacja == 1 && operacja == '4'){ 
			widok(6);
			getKwota(kwota);
			HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/",60, 5000);
			HAL_UART_Transmit(&huart3, id, 12, 5000);
			HAL_UART_Transmit(&huart3, "/balance", 8, 5000);
			i =0;
			HAL_UART_Receive(&huart3, pom, 1, 100);
			do{
			if(HAL_UART_Receive(&huart3, pom, 1, 100) == HAL_OK){
								if(pom[0] == 10) break;
								stankonta[i] = pom[0];
								i++;
						}}while(i<4);

			int wyplata = atoi(kwota);
			int stan = atoi(stankonta);
		if(wyplata <= stan){
				stan = (stan-wyplata);
				itoa(stan, stankonta, 10);
				//stankonta = inttouint8(stan);

				//GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/0/balance/{NowaKwota}

				HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/",60, 5000);
				HAL_UART_Transmit(&huart3, id, 12, 5000);
				HAL_UART_Transmit(&huart3, "/balance/", 9, 5000);
				HAL_UART_Transmit(&huart3, stankonta, 4, 5000);
				HAL_UART_Transmit(&huart3, newline, size, 50);
				HAL_UART_Receive(&huart3, pom, 1, 50);
				HAL_UART_Receive(&huart3, pom, 1, 50);
				HAL_Delay(100);
				HAL_UART_Transmit(&huart3,"GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/showPopup/test/success/Transakcja%20przebieg%C5%82a%20pomy%C5%9Blnie",126,5000);
				HAL_UART_Transmit(&huart3, newline, size, 50);
				HAL_Delay(100);
				HAL_UART_Receive(&huart3, pom, 1, 50);
				HAL_UART_Receive(&huart3, pom, 1, 50);
				HAL_Delay(100);
				widok(1);
				HAL_Delay(100);
		}
		else {
			uint8_t braksrodkow[120] = "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/showPopup/test/error/Wpisana%20kwota%20jest%20zbyt%20du%C5%BCa";
			HAL_UART_Transmit(&huart3, braksrodkow, 120, 5000);
			HAL_UART_Transmit(&huart3, newline, size, 50);
			HAL_UART_Receive(&huart3, pom, 1, 100);
			HAL_UART_Receive(&huart3, pom, 1, 100);
			HAL_Delay(100);
			widok(6);
			HAL_Delay(100);
		}

			
		}


	else if(ifPin == 1 && ifId == 1 && ifOperacja == 1 && operacja == '2'){
		widok(5);
		uint8_t idvol2[12];
		char kwota2[4] = {'0','0','0','0'};
		getuid(idvol2);
		getKwota2(kwota2);
		int ifok = 0;
		HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/",60, 5000);
					HAL_UART_Transmit(&huart3, id, 12, 5000);
					HAL_UART_Transmit(&huart3, "/balance", 8, 5000);
					i = 0;
					HAL_UART_Receive(&huart3, pom, 1, 100);
					do{
					if(HAL_UART_Receive(&huart3, pom, 1, 100) == HAL_OK){
										if(pom[0] == 10) break;
										stankonta[i] = pom[0];
										i++;
								}}while(i<4);

					int wyplata = atoi(kwota2);
					int stan = atoi(stankonta);
				if(wyplata <= stan){
						stan = (stan-wyplata);
						itoa(stan, stankonta, 10);
						//stankonta = inttouint8(stan);

						//GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/0/balance/{NowaKwota}
						HAL_UART_Receive(&huart3, pom, 1, 50);
						HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/",60, 5000);
						HAL_UART_Transmit(&huart3, id, 12, 5000);
						HAL_UART_Transmit(&huart3, "/balance/", 9, 5000);
						HAL_UART_Transmit(&huart3, stankonta, 4, 5000);
						HAL_UART_Transmit(&huart3, newline, size, 50);
						ifok = 1;
				}
				else {
					uint8_t braksrodkow[120] = "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/showPopup/test/error/Wpisana%20kwota%20jest%20zbyt%20du%C5%BCa";
					HAL_UART_Transmit(&huart3, braksrodkow, 120, 5000);
					HAL_UART_Transmit(&huart3, newline, size, 50);
					HAL_UART_Receive(&huart3, pom, 1, 100);
					HAL_UART_Receive(&huart3, pom, 1, 100);
					HAL_Delay(100);
					widok(5);
					HAL_Delay(100);
				}


if(ifok ==1){
	HAL_Delay(1000);
				HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/",60, 5000);
						HAL_UART_Transmit(&huart3, idvol2, 12, 5000);
						HAL_UART_Transmit(&huart3, "/balance", 8, 5000);
						i=0;
						HAL_UART_Receive(&huart3, pom, 1, 100);
						HAL_UART_Receive(&huart3, pom, 1, 100);
						do{
						if(HAL_UART_Receive(&huart3, pom, 1, 100) == HAL_OK){
											if(pom[0] == 10) break;
											stankonta[i] = pom[0];
											i++;
									}}while(i<4);

						int wplata = atoi(kwota2);
						int stan = atoi(stankonta);

							stan = (stan+wplata);
							itoa(stan, stankonta, 10);

							HAL_UART_Transmit(&huart3, "GetHttpRequest:http://ptmp23.azurewebsites.net/api/Accounts/",60, 5000);
							HAL_UART_Transmit(&huart3, idvol2, 12, 5000);
							HAL_UART_Transmit(&huart3, "/balance/", 9, 5000);
							HAL_UART_Transmit(&huart3, stankonta, 4, 5000);
							HAL_UART_Transmit(&huart3, newline, size, 50);
							HAL_UART_Receive(&huart3, pom, 1, 50);
							HAL_UART_Receive(&huart3, pom, 1, 50);
							HAL_Delay(150);
							HAL_UART_Transmit(&huart3,"GetHttpRequest:http://ptmp23.azurewebsites.net/api/Device/showPopup/test/success/Transakcja%20przebieg%C5%82a%20pomy%C5%9Blnie",126,5000);
							HAL_UART_Transmit(&huart3, newline, size, 50);
							HAL_Delay(150);
							HAL_UART_Receive(&huart3, pom, 1, 50);
							HAL_UART_Receive(&huart3, pom, 1, 50);
							HAL_Delay(100);
							widok(1);
							HAL_Delay(100);

}

}
HAL_Delay(150);
}while(koniec != 1);


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
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  uint8_t id[12];
  //getData();
 // UID(id);

  uint8_t sendUART[3] = {65, 'B', 10};
  uint16_t sizeSendUART = 3;
  uint8_t receiveUART[1];
  uint16_t sizeReceiveUART = 1;
  uint8_t pom[1];
 // UID(id);
  //getData(id);
//klawiter();
  //HAL_Delay(500);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //widok()


	  UID(id);
	  getData(id);
	  widok(2);
	  HAL_UART_Receive(&huart3, pom, 1, 100);
	  HAL_UART_Receive(&huart3, pom, 1, 100);  //czyszczenie bufora
	  HAL_UART_Receive(&huart3, pom, 1, 100);
	  HAL_UART_Receive(&huart3, pom, 1, 100);
	  HAL_Delay(500);
	  ifPin = 0;
	  ifId = 0;
	  ifOperacja = 0;
	  ifKwota = 0;
	  HAL_Delay(50);
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
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 9600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

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
  __HAL_RCC_GPIOB_CLK_ENABLE();
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
