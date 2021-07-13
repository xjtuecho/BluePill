/**
  **************************************************************************
  * File   : system_at32f4xx.h
  * Version: V1.3.0
  * Date   : 2021-03-18
  * Brief  : CMSIS Cortex-M4 system header file.
  **************************************************************************
  */


/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup at32f4xx_system
  * @{
  */

/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef __SYSTEM_AT32F4XX_H
#define __SYSTEM_AT32F4XX_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup AT32F4xx_System_Includes
  * @{
  */

/**
  * @}
  */


/** @addtogroup AT32F4xx_System_Exported_types
  * @{
  */

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */

/**
  * @}
  */

/** @addtogroup AT32F4xx_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup AT32F4xx_System_Exported_Macros
  * @{
  */
#define HSE_STABLE_DELAY             (5000u)
#define PLL_STABLE_DELAY             (500u)
/**
  * @}
  */

/** @addtogroup AT32F4xx_System_Exported_Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_AT32F4XX_H */

/**
  * @}
  */

/**
  * @}
  */

