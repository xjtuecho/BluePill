/**
  **************************************************************************
  * File   : at32f4xx_syscfg.h
  * Version: V1.3.0
  * Date   : 2021-03-18
  * Brief  : at32f4xx SYSCFG header file
  **************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32F4XX_SYSCFG_H
#define __AT32F4XX_SYSCFG_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "at32f4xx.h"

/** @addtogroup at32f4xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup SYSCFG
  * @{
  */

#if defined (AT32F421xx)

/** @defgroup SYSCFG_Exported_Constants
  * @{
  */ 

/** @defgroup SYSCFG_EXTI_Port_Sources 
  * @{
  */ 
#define EXTI_PortSourceGPIOA       ((uint8_t)0x00)
#define EXTI_PortSourceGPIOB       ((uint8_t)0x01)
#define EXTI_PortSourceGPIOC       ((uint8_t)0x02)
#define EXTI_PortSourceGPIOD       ((uint8_t)0x03)
#define EXTI_PortSourceGPIOF       ((uint8_t)0x05)

#define IS_EXTI_PORT_SOURCE(PORTSOURCE) (((PORTSOURCE) == EXTI_PortSourceGPIOA) || \
                                         ((PORTSOURCE) == EXTI_PortSourceGPIOB) || \
                                         ((PORTSOURCE) == EXTI_PortSourceGPIOC) || \
                                         ((PORTSOURCE) == EXTI_PortSourceGPIOD) || \
                                         ((PORTSOURCE) == EXTI_PortSourceGPIOF)) 
/**
  * @}
  */

/** @defgroup SYSCFG_EXTI_Pin_sources 
  * @{
  */ 
#define EXTI_PinSource0            ((uint8_t)0x00)
#define EXTI_PinSource1            ((uint8_t)0x01)
#define EXTI_PinSource2            ((uint8_t)0x02)
#define EXTI_PinSource3            ((uint8_t)0x03)
#define EXTI_PinSource4            ((uint8_t)0x04)
#define EXTI_PinSource5            ((uint8_t)0x05)
#define EXTI_PinSource6            ((uint8_t)0x06)
#define EXTI_PinSource7            ((uint8_t)0x07)
#define EXTI_PinSource8            ((uint8_t)0x08)
#define EXTI_PinSource9            ((uint8_t)0x09)
#define EXTI_PinSource10           ((uint8_t)0x0A)
#define EXTI_PinSource11           ((uint8_t)0x0B)
#define EXTI_PinSource12           ((uint8_t)0x0C)
#define EXTI_PinSource13           ((uint8_t)0x0D)
#define EXTI_PinSource14           ((uint8_t)0x0E)
#define EXTI_PinSource15           ((uint8_t)0x0F)

#define IS_EXTI_PIN_SOURCE(PINSOURCE) (((PINSOURCE) == EXTI_PinSource0) || \
                                       ((PINSOURCE) == EXTI_PinSource1) || \
                                       ((PINSOURCE) == EXTI_PinSource2) || \
                                       ((PINSOURCE) == EXTI_PinSource3) || \
                                       ((PINSOURCE) == EXTI_PinSource4) || \
                                       ((PINSOURCE) == EXTI_PinSource5) || \
                                       ((PINSOURCE) == EXTI_PinSource6) || \
                                       ((PINSOURCE) == EXTI_PinSource7) || \
                                       ((PINSOURCE) == EXTI_PinSource8) || \
                                       ((PINSOURCE) == EXTI_PinSource9) || \
                                       ((PINSOURCE) == EXTI_PinSource10) || \
                                       ((PINSOURCE) == EXTI_PinSource11) || \
                                       ((PINSOURCE) == EXTI_PinSource12) || \
                                       ((PINSOURCE) == EXTI_PinSource13) || \
                                       ((PINSOURCE) == EXTI_PinSource14) || \
                                       ((PINSOURCE) == EXTI_PinSource15))
/**
  * @}
  */

/** @defgroup SYSCFG_PA11_PA12_Remap_Config 
  * @{
  */ 
#define SYSCFG_GPIORemap_PA11_PA12  ((uint32_t)0x00000010)    /* PA11 and PA12 remapping bit for small packages (28 and 20 pins). */

/**
  * @}
  */

/** @defgroup SYSCFG_Memory_Remap_Config 
  * @{
  */ 
#define SYSCFG_MemoryRemap_Flash                ((uint8_t)0x00)
#define SYSCFG_MemoryRemap_SystemMemory         ((uint8_t)0x01)
#define SYSCFG_MemoryRemap_SRAM                 ((uint8_t)0x03)


#define IS_SYSCFG_MEMORY_REMAP(REMAP) (((REMAP) == SYSCFG_MemoryRemap_Flash) || \
                                       ((REMAP) == SYSCFG_MemoryRemap_SystemMemory) || \
                                       ((REMAP) == SYSCFG_MemoryRemap_SRAM))

/**
  * @}
  */

/** @defgroup SYSCFG_DMA_Remap_Config 
  * @{
  */ 
#define SYSCFG_DMARemap_TIM17       SYSCFG_CFGR1_TIM17_DMA_RMP    /* Remap TIM17 DMA requests from channel1 to channel2 */
#define SYSCFG_DMARemap_TIM16       SYSCFG_CFGR1_TIM16_DMA_RMP    /* Remap TIM16 DMA requests from channel3 to channel4 */
#define SYSCFG_DMARemap_USART1Rx    SYSCFG_CFGR1_USART1RX_DMA_RMP /* Remap USART1 Rx DMA requests from channel3 to channel5 */
#define SYSCFG_DMARemap_USART1Tx    SYSCFG_CFGR1_USART1TX_DMA_RMP /* Remap USART1 Tx DMA requests from channel2 to channel4 */
#define SYSCFG_DMARemap_ADC1        SYSCFG_CFGR1_ADC_DMA_RMP      /* Remap ADC1 DMA requests from channel1 to channel2 */
  
#define IS_SYSCFG_DMA_REMAP(REMAP) (((REMAP) == SYSCFG_DMARemap_TIM17) || \
                                    ((REMAP) == SYSCFG_DMARemap_TIM16) || \
                                    ((REMAP) == SYSCFG_DMARemap_USART1Rx) || \
                                    ((REMAP) == SYSCFG_DMARemap_USART1Tx) || \
                                    ((REMAP) == SYSCFG_DMARemap_ADC1))

/**
  * @}
  */
  
/** @defgroup SYSCFG_IRTMR_Mode_Config 
  * @{
  */ 
#define SYSCFG_IRTMR_Mode_TIM16       SYSCFG_CFGR1_TIM16_IRTMR_MODE    /* IRTMR MODE1: TIM16 */
#define SYSCFG_IRTMR_Mode_USART1      SYSCFG_CFGR1_USART1_IRTMR_MODE   /* IRTMR MODE1: USART1 */
#define SYSCFG_IRTMR_Mode_USART2      SYSCFG_CFGR1_USART2_IRTMR_MODE   /* IRTMR MODE1: USART2 */

  
#define IS_SYSCFG_IRTMR_MODE(MODE) (((MODE) == SYSCFG_IRTMR_Mode_TIM16) || \
                                    ((MODE) == SYSCFG_IRTMR_Mode_USART1) || \
                                    ((MODE) == SYSCFG_IRTMR_Mode_USART2))

/**
  * @}
  */
  
/** @defgroup SYSCFG_IRTMR_Pol_Config 
  * @{
  */ 
#define SYSCFG_IRTMR_Pol_High       SYSCFG_CFGR1_Pol_IRTMR_HIGH    /* IRTMR Pol: high */
#define SYSCFG_IRTMR_Pol_Low        SYSCFG_CFGR1_Pol_IRTMR_LOW     /* IRTMR Pol: low */

  
#define IS_SYSCFG_IRTMR_POL(POL)   (((POL) == SYSCFG_CFGR1_Pol_IRTMR_HIGH) || \
                                    ((POL) == SYSCFG_CFGR1_Pol_IRTMR_LOW))

/**
  * @}
  */
  
/**
  * @}
  */

void SYSCFG_DeInit(void);
void SYSCFG_MemoryRemapConfig(uint32_t SYSCFG_MemoryRemap);
void SYSCFG_DMAChannelRemapConfig(uint32_t SYSCFG_DMARemap, FunctionalState NewState);
void SYSCFG_I2CFastModePlusConfig(uint32_t SYSCFG_I2CFastModePlus, FunctionalState NewState);
void SYSCFG_EXTILineConfig(uint8_t EXTI_PortSourceGPIOx, uint8_t EXTI_PinSourcex);
void SYSCFG_IRTMRConfig(uint32_t IRTMR_Mode,uint32_t IR_Pol);
void SYSCFG_GPIORemapConfig(FunctionalState NewState);

#endif /*__AT32F4XX_SYSCFG_H */

#ifdef __cplusplus
}
#endif

#endif /* AT32F421xx */

/**
  * @}
  */ 

/**
  * @}
  */
