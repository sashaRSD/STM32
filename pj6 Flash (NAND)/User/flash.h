#ifndef __FLASH_H
#define __FLASH_H

#include "stm32f4xx.h"
#define ADDRESS 0x08020000

uint32_t Flash_Read(uint32_t Data_adr);
void Flash_Write(uint32_t Data_adr, uint32_t Data);

#endif
