#include "main.h"
#include "stdbool.h"
#include "i2cEEP.h"

/*
 * brief: Used to write data array into specified EEPROM memory location
 * param: DevAddress: EEPROM device address
 * param: MemAddress: Memory address location of EEPROM that data needs to be written to.
 * param: pData: base address of data array that needs to be written in EEPROM
 * param: len: Total number of bytes need to write into EEPROM in bytes
 */

HAL_StatusTypeDef eepromWriteIO(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData, uint16_t len) 
{
  HAL_StatusTypeDef returnValue = HAL_ERROR;
  uint8_t data[18] = {0};
	
	uint16_t completed = 0;
	if(MemAddress + len < 4000)
	{
		while(len >= 16)
		{
			/* We compute the MSB and LSB parts of the memory address */
			data[1] = (uint8_t) ((MemAddress & 0xFF00) >> 8);
			data[0] = (uint8_t) (MemAddress & 0xFF);

			/* And copy the content of the pData array in the temporary buffer */
			memcpy(data+2, pData+completed, ONEPAGE);
			completed += ONEPAGE;
				
			returnValue = HAL_I2C_Master_Transmit(&eepromI2c, DevAddress, data, ONEPAGE+2, HAL_MAX_DELAY);
			if(returnValue != HAL_OK)
				return returnValue;

			len -= ONEPAGE;
			MemAddress += ONEPAGE;
			
			/* We wait until the EEPROM effectively stores data in memory */
			while(HAL_I2C_Master_Transmit(&eepromI2c, DevAddress, 0, 0, HAL_MAX_DELAY) != HAL_OK);
			returnValue = HAL_OK;
		
		}
		if(len > 0)
		{
			data[1] = (uint8_t) ((MemAddress & 0xFF00) >> 8);
			data[0] = (uint8_t) (MemAddress & 0xFF);

			/* And copy the content of the pData array in the temporary buffer */
			memcpy(data+2, pData+completed, len);
			
			returnValue = HAL_I2C_Master_Transmit(&eepromI2c, DevAddress, data, len+2, HAL_MAX_DELAY);
			if(returnValue != HAL_OK)
				return returnValue;
			
			while(HAL_I2C_Master_Transmit(&eepromI2c, DevAddress, 0, 0, HAL_MAX_DELAY) != HAL_OK);
			returnValue = HAL_OK;
		}
	}	
  return returnValue;
}