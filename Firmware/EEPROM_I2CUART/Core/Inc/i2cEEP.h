#ifndef _SERIAL_H
#define _SERIAL_H
#include "main.h"

HAL_StatusTypeDef eepromWriteIO(uint16_t DevAddress, uint16_t MemAddress, uint8_t *pData, uint16_t len);


#endif