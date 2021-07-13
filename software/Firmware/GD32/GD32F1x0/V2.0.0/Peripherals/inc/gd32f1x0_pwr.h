/**
  ******************************************************************************
  * @file    gd32f1x0_pwr.h
  * @author  MCU SD 
  * @version V2.0.0
  * @date    15-Jan-2016
  * @brief   PWR header file of the firmware library.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F1X0_PWR_H
#define __GD32F1X0_PWR_H

#ifdef __cplusplus
    extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gd32f1x0.h"

/** @addtogroup GD32F1x0_Firmware
  * @{
  */

/** @addtogroup PWR
  * @{
  */ 

/** @defgroup PWR_Exported_Constants
  * @{
  */ 

/** @defgroup PWR_Low_Voltage_Detector_Threshold 
  * @{
  */ 
#ifdef GD32F170_190
#define PWR_LVDT_0                    PWR_CTLR_LVDT_2V4
#define PWR_LVDT_1                    PWR_CTLR_LVDT_2V7
#define PWR_LVDT_2                    PWR_CTLR_LVDT_3V0
#define PWR_LVDT_3                    PWR_CTLR_LVDT_3V3
#define PWR_LVDT_4                    PWR_CTLR_LVDT_3V6
#define PWR_LVDT_5                    PWR_CTLR_LVDT_3V9
#define PWR_LVDT_6                    PWR_CTLR_LVDT_4V2
#define PWR_LVDT_7                    PWR_CTLR_LVDT_4V5 
#endif /* GD32F170_190 */

#ifdef GD32F130_150
#define PWR_LVDT_0                    PWR_CTLR_LVDT_2V2
#define PWR_LVDT_1                    PWR_CTLR_LVDT_2V3
#define PWR_LVDT_2                    PWR_CTLR_LVDT_2V4
#define PWR_LVDT_3                    PWR_CTLR_LVDT_2V5
#define PWR_LVDT_4                    PWR_CTLR_LVDT_2V6
#define PWR_LVDT_5                    PWR_CTLR_LVDT_2V7
#define PWR_LVDT_6                    PWR_CTLR_LVDT_2V8
#define PWR_LVDT_7                    PWR_CTLR_LVDT_2V9 
#endif /* GD32F130_150 */
/**
  * @}
  */

/** @defgroup PWR_WKUP_Pins 
  * @{
  */
#define PWR_WKUP_PIN_1                PWR_STR_WUPE1
#define PWR_WKUP_PIN_2                PWR_STR_WUPE2

/**
  * @}
  */
  
 
/** @defgroup PWR_LDO_state_in_Deep-sleep_mode 
  * @{
  */
#define PWR_LDO_ON                    ((uint32_t)0x00000000)
#define PWR_LDO_LOWPOWER              PWR_CTLR_LDOLP

/**
  * @}
  */

/** @defgroup PWR_Sleep_mode_entry 
  * @{
  */
#define PWR_SLEEPENTRY_WFI            ((uint8_t)0x01)
#define PWR_SLEEPENTRY_WFE            ((uint8_t)0x02)

/**
  * @}
  */

/** @defgroup PWR_Deep-sleep_mode_entry 
  * @{
  */
#define PWR_DEEPSLEEPENTRY_WFI        ((uint8_t)0x01)
#define PWR_DEEPSLEEPENTRY_WFE        ((uint8_t)0x02)
 
/**
  * @}
  */

/** @defgroup PWR_Standby_mode_entry 
  * @{
  */
#define PWR_STDBYENTRY_WFI            ((uint8_t)0x01)
#define PWR_STDBYENTRY_WFE            ((uint8_t)0x02)
 
/**
  * @}
  */

/** @defgroup PWR_Flag 
  * @{
  */
#define PWR_FLAG_WKUP                 PWR_STR_WUF
#define PWR_FLAG_STB                  PWR_STR_SBF
#define PWR_FLAG_LVDF                 PWR_STR_LVDF

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup PWR_Exported_Functions
  * @{
  */
void PWR_DeInit(void);
void PWR_BackupAccess_Enable(TypeState NewValue);
void PWR_LVDConfig(uint32_t PWR_LVDT, TypeState NewValue);
void PWR_WKUP_Pin_Enable(uint32_t PWR_WKUP_PIN, TypeState NewValue);
void PWR_SLEEPMode_Entry(uint8_t PWR_SLEEPENTRY);
void PWR_DEEPSLEEPMode_Entry(uint32_t PWR_LDO, uint8_t PWR_DEEPSLEEPENTRY);
void PWR_STDBYMode_Entry(uint8_t PWR_STDBYENTRY);
TypeState PWR_GetBitState(uint32_t PWR_FLAG);
void PWR_ClearBitState(uint32_t PWR_FLAG);

#ifdef __cplusplus
}
#endif

#endif /* __GD32F1X0_PWR_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2016 GIGADEVICE *****END OF FILE****/
