/**
  ******************************************************************************
  * @file    gd32f1x0_wwdg.h
  * @author  MCU SD
  * @version V2.0.0
  * @date    15-Jan-2016
  * @brief   WWDG header file of the firmware library.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F1X0_WWDG_H
#define __GD32F1X0_WWDG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gd32f1x0.h"

/** @addtogroup GD32F1x0_Firmware
  * @{
  */

/** @defgroup WWDG
  * @{
  */ 

/** @defgroup WWDG_Exported_Constants
  * @{
  */
#define WWDG_PRESCALER_1    ((uint32_t)0x00000000) /*!< Pre-frequency dividing coefficients of the watchdog is 1 */
#define WWDG_PRESCALER_2    ((uint32_t)0x00000080) /*!< Pre-frequency dividing coefficients of the watchdog is 2 */
#define WWDG_PRESCALER_4    ((uint32_t)0x00000100) /*!< Pre-frequency dividing coefficients of the watchdog is 4 */
#define WWDG_PRESCALER_8    ((uint32_t)0x00000180) /*!< Pre-frequency dividing coefficients of the watchdog is 8 */

/**
  * @}
  */

/** @defgroup WWDG_Exported_Functions
  * @{
  */
void WWDG_DeInit(void);
void WWDG_SetPrescalerValue(uint32_t PrescalerValue);
void WWDG_SetWindowValue(uint8_t WindowValue);
void WWDG_EnableInt(void);
void WWDG_SetCounterValue(uint8_t CounterValue);
void WWDG_Enable(uint8_t CounterValue);
TypeState WWDG_GetBitState(void);
void WWDG_ClearBitState(void);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __GD32F1X0_WWDG_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2016 GIGADEVICE *****END OF FILE****/
