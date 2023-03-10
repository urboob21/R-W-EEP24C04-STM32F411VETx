
#include "main.h"
#include "stdbool.h"
#include "serial.h"
#include <stdlib.h>
// DIA CHI EEPROM
#define EE04_ADD_READ 			 0xA0 	//1010 0000
#define EE04_ADD_WRITE_PAGE1 0xA0		//1010 0000
#define EE04_ADD_WRITE_PAGE2 0xA2
//
UART_HandleTypeDef huart2;
I2C_HandleTypeDef hi2c1;

DMA_HandleTypeDef hdma_i2c1_rx;
DMA_HandleTypeDef hdma_i2c1_tx;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;
//
uint8_t *pBuff;
uint8_t RiData[512];
uint8_t RiData_2a[1];
uint8_t RiData_2b[5];
uint8_t len;
extern uint8_t RxData[10];
//extern uint8_t TxData[514]; 
//extern uint8_t TxData_2a[3]; 
//extern uint8_t TxData_2b[7]; 

extern uint8_t r_cmd[1];
extern uint8_t r_address[2];
extern uint8_t r_data[5];
extern bool r_DataAvailable;
uint16_t address;
extern uint8_t STX[];
extern uint8_t ETX[];
//int dem=0;
//int dem1=0;
uint8_t mode1={0x41U};  //read EEPROOM
uint8_t mode3={0x43U};  //write 1 byte
uint8_t mode4={0x44U};	// write 1 block = 5bytes
uint8_t mode2a={0x46U};	// read 1 byte
uint8_t mode2b={0x47U};	// read 5 bytes

//
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);

int main(void)
	{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
	HAL_UART_Receive_DMA(&huart2,RxData,10); 
  while (1)
  {
	
		if(r_DataAvailable)
			{
				if(StrCompare(r_cmd,&mode1,1)) //doc all EEPROM
					{
												r_DataAvailable=false;

					HAL_I2C_Mem_Read_DMA(&hi2c1,0xA0,0,I2C_MEMADD_SIZE_8BIT,RiData,512);
					}
				else if(StrCompare(r_cmd,&mode2a,1)) //doc 1 byte 
					{
						r_DataAvailable=false;
						if(address<256) 
					HAL_I2C_Mem_Read_DMA(&hi2c1,0xA0,address,I2C_MEMADD_SIZE_8BIT,RiData_2a,1);
						else if(address>=256)
						HAL_I2C_Mem_Read_DMA(&hi2c1,0xA2,address,I2C_MEMADD_SIZE_8BIT,RiData_2a,1);	
					}
					
				else if(StrCompare(r_cmd,&mode2b,1)) //doc 5 bytes
					{
						r_DataAvailable=false;
						if(address<256)
						HAL_I2C_Mem_Read_DMA(&hi2c1,0xA0,address,I2C_MEMADD_SIZE_8BIT,RiData_2b,5);
						else if(address>=256)
						HAL_I2C_Mem_Read_DMA(&hi2c1,0xA2,address,I2C_MEMADD_SIZE_8BIT,RiData_2b,5);	
					}
					
				else if(StrCompare(r_cmd,&mode3,1)) //ghi 1 bytes
					{
						r_DataAvailable=false;
						if(address<256)
						{
							HAL_I2C_Mem_Write(&hi2c1,EE04_ADD_WRITE_PAGE1,address,I2C_MEMADD_SIZE_8BIT,r_data,1,100);
						}
						else if(address>=256)
						{
							HAL_I2C_Mem_Write(&hi2c1,EE04_ADD_WRITE_PAGE2,address,I2C_MEMADD_SIZE_8BIT,r_data,1,100);
						}
						
					}
				else if(StrCompare(r_cmd,&mode4,1)) //ghi 5 bytes
					{
						r_DataAvailable=false;
						//x=address&0x0F;
			if(address<256)   											//0-255
						{
							if((address&0x0F) > 0x0BU)
							{
								len=0x0FU-(address&0x0F)+1;
								HAL_I2C_Mem_Write(&hi2c1,EE04_ADD_WRITE_PAGE1,address,I2C_MEMADD_SIZE_8BIT,r_data,len,100);
								HAL_Delay(10);
								HAL_I2C_Mem_Write(&hi2c1,EE04_ADD_WRITE_PAGE1,address+len,I2C_MEMADD_SIZE_8BIT,r_data+len,5-len,100);
							}
							else 
							{
							HAL_I2C_Mem_Write(&hi2c1,EE04_ADD_WRITE_PAGE1,address,I2C_MEMADD_SIZE_8BIT,r_data,5,100);
							}
						}
				else if(address>=256) 										//256-512
						{
							if((address&0x0F) > 0x0BU)
							{
								len=0x0FU-(address&0x0F)+1;
								HAL_I2C_Mem_Write(&hi2c1,EE04_ADD_WRITE_PAGE2,address,I2C_MEMADD_SIZE_8BIT,r_data,len,100);
							HAL_Delay(10);
								HAL_I2C_Mem_Write(&hi2c1,EE04_ADD_WRITE_PAGE2,address+len,I2C_MEMADD_SIZE_8BIT,r_data+len,5-len,100);
							}
							else 
							{
							HAL_I2C_Mem_Write(&hi2c1,EE04_ADD_WRITE_PAGE2,address,I2C_MEMADD_SIZE_8BIT,r_data,5,100);
							}
						}
					}
			else 
					r_DataAvailable=false;
			}
  }

}

// Ngat doc I2C
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c)  // read EEPROM ->(DMA)->Ridata -> UART -> OUT
{
	
	if(hi2c->Instance==hi2c1.Instance)
	{
		if(StrCompare(r_cmd,&mode1,1))
		{
					pBuff=(uint8_t*)malloc(512);
			{
			memcpy(pBuff,STX,1);
			memcpy(pBuff+1,RiData,sizeof(RiData));
			memcpy(pBuff+513,ETX,1);
			HAL_UART_Transmit_DMA(&huart2,pBuff,514);
			}
				
		}
		else if(StrCompare(r_cmd,&mode2a,1))
		{
			pBuff=(uint8_t*)malloc(3);
			memcpy(pBuff,STX,1);
			memcpy(pBuff+1,RiData_2a,sizeof(RiData_2a));
			memcpy(pBuff+2,ETX,1);
			HAL_UART_Transmit_DMA(&huart2,pBuff,3);
		}
				else if(StrCompare(r_cmd,&mode2b,1))
		{
			pBuff=(uint8_t*)malloc(7);
			memcpy(pBuff,STX,1);
			memcpy(pBuff+1,RiData_2b,sizeof(RiData_2b));
			memcpy(pBuff+6,ETX,1);
			HAL_UART_Transmit_DMA(&huart2,pBuff,7);
		}
				
	}

}
// Ngat ghi I2C
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c)  //write
{
	if(hi2c->Instance==hi2c1.Instance)
	{
		HAL_Delay(10);
	}
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
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 200;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */



static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream0_IRQn);
  /* DMA1_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream1_IRQn);
  /* DMA1_Stream5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
  /* DMA1_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

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

