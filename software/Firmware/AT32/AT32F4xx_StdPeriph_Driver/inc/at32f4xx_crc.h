/**
  **************************************************************************
  * File   : at32f4xx_crc.h
  * Version: V1.3.0
  * Date   : 2021-03-18
  * Brief  : at32f4xx CRC header file
  **************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32F4XX_CRC_H
#define __AT32F4XX_CRC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "at32f4xx.h"

/** @addtogroup at32f4xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup CRC
  * @{
  */

/** @defgroup CRC_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup CRC_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @defgroup CRC_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup CRC_Exported_Functions
  * @{
  */
void CRC_SetIDTReg(uint8_t IDValue);
uint8_t CRC_GetIDTReg(void);
void CRC_ResetDT(void);
uint32_t CRC_CalculateCRC(uint32_t Data);
uint32_t CRC_CalculateBlkCRC(uint32_t pBuffer[], uint32_t BufferLength);
uint32_t CRC_GetCRC(void);


#ifdef __cplusplus
}
#endif

#endif /* __AT32F4XX_CRC_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */


