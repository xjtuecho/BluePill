/**
  **************************************************************************
  * File   : at32f4xx_gpio_ex.h
  * Version: V1.3.0
  * Date   : 2021-03-18
  * Brief  : at32f4xx GPIO extended header file
  **************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32F4XX_GPIO_EX_H
#define __AT32F4XX_GPIO_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "at32f4xx.h"

#if defined (AT32F421xx)

/** @addtogroup at32f4xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */

/** @defgroup GPIO_Exported_Types
  * @{
  */

#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == GPIOA) || \
                                    ((PERIPH) == GPIOB) || \
                                    ((PERIPH) == GPIOC) || \
                                    ((PERIPH) == GPIOF))

                                     
/** 
  * @brief  Output Maximum frequency selection  
  */

typedef enum
{
  GPIO_MaxSpeed_10MHz = 1,
  GPIO_MaxSpeed_2MHz,
  GPIO_MaxSpeed_50MHz = 2
}GPIOMaxSpeed_Type;

#define IS_GPIO_MAXSPEED(MAXSPEED) (((MAXSPEED) == GPIO_MaxSpeed_10MHz) ||\
                                    ((MAXSPEED) == GPIO_MaxSpeed_2MHz)  || \
                                    ((MAXSPEED) == GPIO_MaxSpeed_50MHz))

/** 
  * @brief  Configuration Mode enumeration  
  */

typedef enum
{
  GPIO_Mode_IN   = 0x00, /*!< GPIO Input Mode              */
  GPIO_Mode_OUT  = 0x01, /*!< GPIO Output Mode             */
  GPIO_Mode_AF   = 0x02, /*!< GPIO Alternate function Mode */
  GPIO_Mode_AN   = 0x03  /*!< GPIO Analog In/Out Mode      */
}GPIOMode_Type;

#define IS_GPIO_MDE(MDE) (((MDE) == GPIO_Mode_IN) || ((MDE) == GPIO_Mode_OUT) || \
                          ((MDE) == GPIO_Mode_AF) || ((MDE) == GPIO_Mode_AN))

/** 
  * @brief Output_type_enumeration
  */
typedef enum
{
  GPIO_OutType_PP = 0x00,
  GPIO_OutType_OD = 0x01
}GPIOOut_Type;

#define IS_GPIO_OTYPE(OTYPE) (((OTYPE) == GPIO_OutType_PP) || ((OTYPE) == GPIO_OutType_OD))

/** 
  * @brief Configuration_Pull-Up_Pull-Down_enumeration 
  */
typedef enum
{
  GPIO_Pull_NOPULL = 0x00,
  GPIO_Pull_PU     = 0x01,
  GPIO_Pull_PD     = 0x02
}GPIOPull_Type;

#define IS_GPIO_PUPD(PUPD) (((PUPD) == GPIO_Pull_NOPULL) || ((PUPD) == GPIO_Pull_PU) || \
                            ((PUPD) == GPIO_Pull_PD))

/** 
  * @brief  GPIO Init structure definition  
  */

typedef struct
{
  uint16_t GPIO_Pins;               /*!< Specifies the GPIO pins to be configured.
                                      This parameter can be any value of @ref GPIO_pins_define */

  GPIOMaxSpeed_Type GPIO_MaxSpeed;  /*!< Specifies the speed for the selected pins.
                                      This parameter can be a value of @ref GPIOMaxSpeed_Type */

  GPIOMode_Type GPIO_Mode;          /*!< Specifies the operating mode for the selected pins.
                                      This parameter can be a value of @ref GPIOMode_Type */

  GPIOOut_Type GPIO_OutType;   /*!< Specifies the operating output type for the selected pins.
                                       This parameter can be a value of @ref GPIOOut_Type  */

  GPIOPull_Type GPIO_Pull;     /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                                       This parameter can be a value of @ref GPIOPull_Type   */
}GPIO_InitType;


/** 
  * @brief  Bit_SET and Bit_RESET enumeration  
  */

typedef enum
{
  Bit_RESET = 0,
  Bit_SET
}BitState;

#define IS_GPIO_BIT_STATE(STATE) (((STATE) == Bit_RESET) || ((STATE) == Bit_SET))

/**
  * @}
  */

/** @defgroup GPIO_Exported_Constants
  * @{
  */

/** @defgroup GPIO_pins_define 
  * @{
  */

#define GPIO_Pins_0                 ((uint16_t)0x0001)  /*!< Pin 0 selected */
#define GPIO_Pins_1                 ((uint16_t)0x0002)  /*!< Pin 1 selected */
#define GPIO_Pins_2                 ((uint16_t)0x0004)  /*!< Pin 2 selected */
#define GPIO_Pins_3                 ((uint16_t)0x0008)  /*!< Pin 3 selected */
#define GPIO_Pins_4                 ((uint16_t)0x0010)  /*!< Pin 4 selected */
#define GPIO_Pins_5                 ((uint16_t)0x0020)  /*!< Pin 5 selected */
#define GPIO_Pins_6                 ((uint16_t)0x0040)  /*!< Pin 6 selected */
#define GPIO_Pins_7                 ((uint16_t)0x0080)  /*!< Pin 7 selected */
#define GPIO_Pins_8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
#define GPIO_Pins_9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
#define GPIO_Pins_10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
#define GPIO_Pins_11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
#define GPIO_Pins_12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
#define GPIO_Pins_13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
#define GPIO_Pins_14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
#define GPIO_Pins_15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
#define GPIO_Pins_All               ((uint16_t)0xFFFF)  /*!< All pins selected */

#define IS_GPIO_PINS(PINS) ((((PINS) & (uint16_t)0x00) == 0x00) && ((PINS) != (uint16_t)0x00))

#define IS_GET_GPIO_PINS(PINS)      (((PINS) == GPIO_Pins_0)  || \
                                     ((PINS) == GPIO_Pins_1)  || \
                                     ((PINS) == GPIO_Pins_2)  || \
                                     ((PINS) == GPIO_Pins_3)  || \
                                     ((PINS) == GPIO_Pins_4)  || \
                                     ((PINS) == GPIO_Pins_5)  || \
                                     ((PINS) == GPIO_Pins_6)  || \
                                     ((PINS) == GPIO_Pins_7)  || \
                                     ((PINS) == GPIO_Pins_8)  || \
                                     ((PINS) == GPIO_Pins_9)  || \
                                     ((PINS) == GPIO_Pins_10) || \
                                     ((PINS) == GPIO_Pins_11) || \
                                     ((PINS) == GPIO_Pins_12) || \
                                     ((PINS) == GPIO_Pins_13) || \
                                     ((PINS) == GPIO_Pins_14) || \
                                     ((PINS) == GPIO_Pins_15))

/**
  * @}
  */


/** @defgroup GPIO_Port_Sources 
  * @{
  */

#define GPIO_PortSourceGPIOA       ((uint8_t)0x00)
#define GPIO_PortSourceGPIOB       ((uint8_t)0x01)
#define GPIO_PortSourceGPIOC       ((uint8_t)0x02)
#define GPIO_PortSourceGPIOF       ((uint8_t)0x05)
#define IS_GPIO_EVENTOUT_PORT_SOURCE(PORTSOURCE) (((PORTSOURCE) == GPIO_PortSourceGPIOA) || \
                                                  ((PORTSOURCE) == GPIO_PortSourceGPIOB) || \
                                                  ((PORTSOURCE) == GPIO_PortSourceGPIOC))

#define IS_GPIO_EXTI_PORT_SOURCE(PORTSOURCE)     (((PORTSOURCE) == GPIO_PortSourceGPIOA) || \
                                                  ((PORTSOURCE) == GPIO_PortSourceGPIOB) || \
                                                  ((PORTSOURCE) == GPIO_PortSourceGPIOC) || \
                                                  ((PORTSOURCE) == GPIO_PortSourceGPIOF))

/**
  * @}
  */

/** @defgroup GPIO_Pin_sources 
  * @{
  */

#define GPIO_PinsSource0            ((uint8_t)0x00)
#define GPIO_PinsSource1            ((uint8_t)0x01)
#define GPIO_PinsSource2            ((uint8_t)0x02)
#define GPIO_PinsSource3            ((uint8_t)0x03)
#define GPIO_PinsSource4            ((uint8_t)0x04)
#define GPIO_PinsSource5            ((uint8_t)0x05)
#define GPIO_PinsSource6            ((uint8_t)0x06)
#define GPIO_PinsSource7            ((uint8_t)0x07)
#define GPIO_PinsSource8            ((uint8_t)0x08)
#define GPIO_PinsSource9            ((uint8_t)0x09)
#define GPIO_PinsSource10           ((uint8_t)0x0A)
#define GPIO_PinsSource11           ((uint8_t)0x0B)
#define GPIO_PinsSource12           ((uint8_t)0x0C)
#define GPIO_PinsSource13           ((uint8_t)0x0D)
#define GPIO_PinsSource14           ((uint8_t)0x0E)
#define GPIO_PinsSource15           ((uint8_t)0x0F)

#define IS_GPIO_PINS_SOURCE(PINSSOURCE) (((PINSSOURCE) == GPIO_PinsSource0)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource1)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource2)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource3)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource4)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource5)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource6)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource7)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource8)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource9)  || \
                                         ((PINSSOURCE) == GPIO_PinsSource10) || \
                                         ((PINSSOURCE) == GPIO_PinsSource11) || \
                                         ((PINSSOURCE) == GPIO_PinsSource12) || \
                                         ((PINSSOURCE) == GPIO_PinsSource13) || \
                                         ((PINSSOURCE) == GPIO_PinsSource14) || \
                                         ((PINSSOURCE) == GPIO_PinsSource15))

/**
  * @}
  */

/** @defgroup GPIO_Alternate_function_selection_define 
  * @{
  */

/** 
  * @brief  AF 0 selection
  */
#define GPIO_AF_0            ((uint8_t)0x00) /* WKUP, EVENTOUT, TIM15, SPI1, TIM17,
                                                MCO, SWDAT, SWCLK, TIM14, BOOT,
                                                USART1, CEC, IR_OUT, SPI2 */
/** 
  * @brief  AF 1 selection
  */
#define GPIO_AF_1            ((uint8_t)0x01) /* USART2, CEC, Tim3, USART1, USART2,
                                                EVENTOUT, I2C1, I2C2, TIM15 */
/** 
  * @brief  AF 2 selection
  */
#define GPIO_AF_2            ((uint8_t)0x02) /* TIM2, TIM1, EVENTOUT, TIM16, TIM17 */
/** 
  * @brief  AF 3 selection
  */
#define GPIO_AF_3            ((uint8_t)0x03) /* TS, I2C1, TIM15, EVENTOUT */

/** 
  * @brief  AF 4 selection
  */
#define GPIO_AF_4            ((uint8_t)0x04) /* TIM14 */
/** 
  * @brief  AF 5 selection
  */
#define GPIO_AF_5            ((uint8_t)0x05) /* TIM16, TIM17 */

/** 
  * @brief  AF 6 selection
  */
#define GPIO_AF_6            ((uint8_t)0x06) /* EVENTOUT */
/** 
  * @brief  AF 7 selection
  */
#define GPIO_AF_7            ((uint8_t)0x07) /* COMP1 OUT and COMP2 OUT */

#define IS_GPIO_AF(AF)   (((AF) == GPIO_AF_0) || ((AF) == GPIO_AF_1) || \
                          ((AF) == GPIO_AF_2) || ((AF) == GPIO_AF_3) || \
                          ((AF) == GPIO_AF_4) || ((AF) == GPIO_AF_5) || \
                          ((AF) == GPIO_AF_6) || ((AF) == GPIO_AF_7))
                          
/**
  * @}
  */
  
/**
  * @}
  */

/** @defgroup GPIO_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Exported_Functions
  * @{
  */

void GPIO_Reset(GPIO_Type* GPIOx);
void GPIO_Init(GPIO_Type* GPIOx, GPIO_InitType* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitType* GPIO_InitStruct);
uint8_t GPIO_ReadInputDataBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(GPIO_Type* GPIOx);
uint8_t GPIO_ReadOutputDataBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(GPIO_Type* GPIOx);
void GPIO_SetBits(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin, BitState BitVal);
void GPIO_Write(GPIO_Type* GPIOx, uint16_t PortVal);
void GPIO_PinsLockConfig(GPIO_Type* GPIOx, uint16_t GPIO_Pin);
void GPIO_PinsEnhanceSlewRate(GPIO_Type* GPIOx, uint16_t GPIO_Pin, FunctionalState NewState);
void GPIO_PinsHugeDriven(GPIO_Type* GPIOx, uint16_t GPIO_Pin, FunctionalState NewState);
void GPIO_PinAFConfig(GPIO_Type* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF);
#if defined (AT32F421PF4P7) || defined (AT32F421PF8P7)
void GPIO_F421PFxP7_LowPower(void);
#endif /* AT32F421PF4P7 || AT32F421PF8P7 */
#endif /* AT32F421xx */

#ifdef __cplusplus
}
#endif

#endif /* __AT32F4XX_GPIO_EX_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */


