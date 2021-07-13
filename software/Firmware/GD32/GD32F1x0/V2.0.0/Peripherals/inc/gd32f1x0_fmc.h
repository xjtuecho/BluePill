/**
  ******************************************************************************
  * @file    gd32f1x0_fmc.h
  * @author  MCU SD
  * @version V2.0.0
  * @date    15-Jan-2016
  * @brief   FMC header file of the firmware library.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F1X0_FMC_H
#define __GD32F1X0_FMC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gd32f1x0.h"

/** @addtogroup GD32F1x0_Firmware
  * @{
  */

/** @addtogroup FMC
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup FMC_Exported_Types
  * @{
  */

/** 
  * @brief  FMC State
  */ 
typedef enum
{
    FMC_READY,                                                 /*!< flash state ready */
    FMC_BSY,                                                   /*!< flash state busy */
    FMC_WRPERR,                                                /*!< flash state write protect error */
    FMC_PGERR,                                                 /*!< flash state program error */
    FMC_TIMEOUT_ERR                                            /*!< flash state timeout error */
}FMC_State;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
  
/** @defgroup FMC_Exported_Constants
  * @{
  */ 

/** @defgroup FMC_Interrupts 
  * @{
  */
   
#define FMC_INT_EOP                     FMC_CMR_ENDIE          /*!< End of programming interrupt source */
#define FMC_INT_ERR                     FMC_CMR_ERIE           /*!< Error interrupt source */
/**
  * @}
  */

/** @defgroup FMC_Option_Bytes_Write_Protection 
  * @{
  */
#define WRP_SECTOR0                     ((uint32_t)0x00000001) /*!< Write protection of sector 0 */
#define WRP_SECTOR1                     ((uint32_t)0x00000002) /*!< Write protection of sector 1 */
#define WRP_SECTOR2                     ((uint32_t)0x00000004) /*!< Write protection of sector 2 */
#define WRP_SECTOR3                     ((uint32_t)0x00000008) /*!< Write protection of sector 3 */
#define WRP_SECTOR4                     ((uint32_t)0x00000010) /*!< Write protection of sector 4 */
#define WRP_SECTOR5                     ((uint32_t)0x00000020) /*!< Write protection of sector 5 */
#define WRP_SECTOR6                     ((uint32_t)0x00000040) /*!< Write protection of sector 6 */
#define WRP_SECTOR7                     ((uint32_t)0x00000080) /*!< Write protection of sector 7 */
#define WRP_SECTOR8                     ((uint32_t)0x00000100) /*!< Write protection of sector 8 */
#define WRP_SECTOR9                     ((uint32_t)0x00000200) /*!< Write protection of sector 9 */
#define WRP_SECTOR10                    ((uint32_t)0x00000400) /*!< Write protection of sector 10 */
#define WRP_SECTOR11                    ((uint32_t)0x00000800) /*!< Write protection of sector 11 */
#define WRP_SECTOR12                    ((uint32_t)0x00001000) /*!< Write protection of sector 12 */
#define WRP_SECTOR13                    ((uint32_t)0x00002000) /*!< Write protection of sector 13 */
#define WRP_SECTOR14                    ((uint32_t)0x00004000) /*!< Write protection of sector 14 */
#define WRP_SECTOR15                    ((uint32_t)0x00008000) /*!< Write protection of sector 15 */

#define WRP_ALLSECTORS                  ((uint32_t)0x0000FFFF) /*!< Write protection of all Sectors */

/**
  * @}
  */
  

/** @defgroup FMC_Option_Bytes_Read_Protection 
  * @{
  */
#define RDP_LEVEL_0                     ((uint8_t)0xA5)        /*!< Protection level 0 */
#define RDP_LEVEL_1                     ((uint8_t)0xBB)        /*!< Protection level 1 */
#define RDP_LEVEL_2                     ((uint8_t)0xCC)        /*!< Protection level 2 */

/**
  * @}
  */ 

/** @defgroup FMC_Option_Bytes_IWatchdog 
  * @{
  */
#define OB_IWDG_SW                      ((uint8_t)0x01)        /*!< Software IWDG selected */
#define OB_IWDG_HW                      ((uint8_t)0x00)        /*!< Hardware IWDG selected */

/**
  * @}
  */

/** @defgroup FMC_Option_Bytes_nRST_DEEPSLEEP 
  * @{
  */
#define OB_DEEPSLEEP_NORST              ((uint8_t)0x02)        /*!< No reset generated when entering in DEEPSLEEP */
#define OB_DEEPSLEEP_RST                ((uint8_t)0x00)        /*!< Reset generated when entering in DEEPSLEEP */

/**
  * @}
  */

/** @defgroup FMC_Option_Bytes_nRST_STDBY 
  * @{
  */
#define OB_STDBY_NORST                  ((uint8_t)0x04)        /*!< No reset generated when entering in STANDBY */
#define OB_STDBY_RST                    ((uint8_t)0x00)        /*!< Reset generated when entering in STANDBY */

/**
  * @}
  */

/** @defgroup FMC_Option_Bytes_BOOT1
  * @{
  */
#define OB_BOOT1_RESET                  ((uint8_t)0x00)        /*!< BOOT1 Reset */
#define OB_BOOT1_SET                    ((uint8_t)0x10)        /*!< BOOT1 Set */

/**
  * @}
  */

/** @defgroup FMC_Option_Bytes_VDDA_Analog_Monitoring
  * @{
  */
#define OB_VDDA_ANALOG_ON               ((uint8_t)0x00)        /*!< Analog monitoring on VDDA Power source ON */
#define OB_VDDA_ANALOG_OFF              ((uint8_t)0x20)        /*!< Analog monitoring on VDDA Power source OFF */

/**
  * @}
  */    

/** @defgroup FMC_Option_Bytes_SRAM_Parity_Enable 
  * @{
  */

#define OB_SRAM_PARITY_SET              ((uint8_t)0x00)        /*!< SRAM parity enable Set */
#define OB_SRAM_PARITY_RESET            ((uint8_t)0x40)        /*!< SRAM parity enable reset */

/**
  * @}
  */ 
  
/** @defgroup FMC_Flags 
  * @{
  */ 

#define FMC_FLAG_BSY                    FMC_CSR_BUSY           /*!< FMC Busy flag */
#define FMC_FLAG_PERR                   FMC_CSR_PGEF           /*!< FMC Programming error flag */
#define FMC_FLAG_WERR                   FMC_CSR_WPEF           /*!< FMC Write protected error flag */
#define FMC_FLAG_EOP                    FMC_CSR_ENDF           /*!< FMC End of Programming flag */

/**
  * @}
  */ 

/** @defgroup FMC_Timeout_definition 
  * @{
  */ 
#define FMC_TIMEOUT_COUNT               ((uint32_t)0x000F0000) /*!< Timeout count */

/**
  * @}
  */ 

/**
  * @}
  */ 

/** @defgroup FMC_Exported_Functions
  * @{
  */

/** 
  * @brief  FMC memory functions.
  */
/* FMC Main Memory Programming functions *****************************************/
void FMC_Unlock(void);
void FMC_Lock(void);
FMC_State FMC_ErasePage(uint32_t Page_Address);
FMC_State FMC_MassErase(void);
FMC_State FMC_ProgramWord(uint32_t Address, uint32_t Data);
FMC_State FMC_ProgramHalfWord(uint32_t Address, uint16_t Data);
#ifdef GD32F170_190
FMC_State FMC_ReProgramWord(uint32_t Address, uint32_t Data);
#endif /* GD32F170_190 */
/* FMC Option Bytes Programming functions *****************************************/
void FMC_OB_Unlock(void);
void FMC_OB_Lock(void);
void FMC_OB_Reset(void);
FMC_State FMC_OB_Erase(void);
FMC_State FMC_OB_EnableWRP(uint32_t OB_WRP);
FMC_State FMC_OB_RDPConfig(uint8_t OB_RDP);
FMC_State FMC_OB_UserConfig(uint8_t OB_IWDG, uint8_t OB_DEEPSLEEP, uint8_t OB_STDBY);
FMC_State FMC_OB_BOOTConfig(uint8_t OB_BOOT1);
FMC_State FMC_OB_VDDAConfig(uint8_t OB_VDDA_ANALOG);
FMC_State FMC_OB_SRAMParityConfig(uint8_t OB_SRAM_Parity);
FMC_State FMC_OB_WriteUser(uint8_t OB_USER);
FMC_State FMC_ProgramOptionByteData(uint32_t Address, uint8_t Data);
uint8_t FMC_OB_GetUser(void);
uint32_t FMC_OB_GetWRP(void);
TypeState FMC_OB_GetRDP(void);

/* FMC Interrupts and flags management functions **********************************/
void FMC_INTConfig(uint32_t FMC_INT, TypeState NewValue);
TypeState FMC_GetBitState(uint32_t FMC_FLAG);
void FMC_ClearBitState(uint32_t FMC_FLAG);
FMC_State FMC_GetState(void);
FMC_State FMC_WaitReady(uint32_t uCount);

#ifdef __cplusplus
}
#endif

#endif /* __GD32F1X0_FMC_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT 2016 GIGADEVICE *****END OF FILE****/
