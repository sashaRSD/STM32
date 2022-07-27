#include "stm32f4xx.h"
#include "flash.h"


uint32_t Flash_Read(uint32_t Data_adr)
{
	return *(uint32_t*) Data_adr;
}

void Flash_Write(uint32_t Data_adr, uint32_t Data)
{
	FLASH_Unlock();
	FLASH_EraseSector(FLASH_Sector_5,VoltageRange_3);
	FLASH_ProgramWord(Data_adr, Data);
	FLASH_Lock();
}
