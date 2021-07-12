/**
  ******************************************************************************
  * @file    gd32f1x0.h
  * @author  MCU SD
  * @version V2.0.0
  * @date    15-Jan-2016
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File..
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup GD32f1x0
  * @{
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GD32F1X0_H
#define __GD32F1X0_H

#ifdef __cplusplus
 extern "C" {
#endif 
  
/** @addtogroup Library_configuration_section
  * @{
  */
  
/* Uncomment the line below according to the target GD32F1x0 device used in your 
   application 
  */

#if !defined (GD32F1x0)
  #define GD32F1x0    /*!< GD32F1x0: GD32F1x0 devices */
#endif


#if !defined (GD32F1x0)
 #error "Please select first the target GD32F1x0 device used in your application (in gd32f1x0.h file)"
#endif /* GD32F1x0 */
#if!defined (GD32F170_190)&&!defined (GD32F130_150)
 #error "Please select GD32F1x0 device category( GD32F130_150 or GD32F170_190 )"
#endif /* GD32F1x0 */
#if defined (GD32F170_190)&& defined (GD32F130_150)
 #error "Please select one GD32F1x0 device category( GD32F130_150 or GD32F170_190 )"
#endif /* GD32F1x0 */

#if !defined  USE_STDPERIPH_DRIVER
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will 
   be based on direct access to peripherals registers 
   */
  /*#define USE_STDPERIPH_DRIVER*/
#endif /* USE_STDPERIPH_DRIVER */

/**
 * @brief In the following line adjust the value of External High Speed oscillator (HSE)
   used in your application 
   
   Tip: To avoid modifying this file each time you need to use different HSE, you
        can define the HSE value in your toolchain compiler preprocessor.
  */
#if !defined  (HSE_VALUE)     
#define HSE_VALUE    ((uint32_t)8000000) /*!< Value of the External oscillator in Hz*/
#endif /* HSE_VALUE */

/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) Startup 
   Timeout value 
   */
#if !defined  (HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x0800) /*!< Time out for HSE start up */
#endif /* HSE_STARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the Internal High Speed oscillator (HSI) Startup 
   Timeout value 
   */
#if !defined  (HSI_STARTUP_TIMEOUT)
#define HSI_STARTUP_TIMEOUT   ((uint16_t)0x0500) /*!< Time out for HSI start up */
#endif /* HSI_STARTUP_TIMEOUT */

#if !defined  (HSI_VALUE) 
#define HSI_VALUE  ((uint32_t)8000000)       /*!< Value of the Internal High Speed oscillator in Hz.
                                                  The real value may vary depending on the variations
                                                  in voltage and temperature.  */
#endif /* HSI_VALUE */


#ifdef GD32F170_190
#if !defined  (HSI28_VALUE)                                                                                 
#define HSI28_VALUE ((uint32_t)28000000)     /*!< Value of the Internal High Speed oscillator for ADC in Hz.
                                                  The real value may vary depending on the variations       
                                                  in voltage and temperature.  */                           
#endif /* HSI28_VALUE */  
#else 
#if !defined  (HSI14_VALUE) 
#define HSI14_VALUE ((uint32_t)14000000)     /*!< Value of the Internal High Speed oscillator for ADC in Hz.
                                                  The real value may vary depending on the variations
                                                  in voltage and temperature.  */
#endif /* HSI14_VALUE */
#endif /* GD32F170_190 */



#if !defined  (LSI_VALUE) 
#define LSI_VALUE  ((uint32_t)40000)         /*!< Value of the Internal Low Speed oscillator in Hz
                                                  The real value may vary depending on the variations
                                                  in voltage and temperature.  */
#endif /* LSI_VALUE */

#if !defined  (LSE_VALUE) 
#define LSE_VALUE  ((uint32_t)32768)         /*!< Value of the External Low Speed oscillator in Hz */
#endif /* LSE_VALUE */


/**
 * @brief GD32F1x0 Firmware Library version number V2.0
   */
#define __GD32F1x0_STDPERIPH_VERSION_MAIN   (0x02) /*!< [31:24] main version */
#define __GD32F1x0_STDPERIPH_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version */
#define __GD32F1x0_STDPERIPH_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define __GD32F1x0_STDPERIPH_VERSION_RC     (0x00) /*!< [7:0]  release candidate */ 
#define __GD32F1x0_STDPERIPH_VERSION        ((__GD32F1x0_STDPERIPH_VERSION_MAIN << 24)\
                                            |(__GD32F1x0_STDPERIPH_VERSION_SUB1 << 16)\
                                            |(__GD32F1x0_STDPERIPH_VERSION_SUB2 << 8)\
                                            |(__GD32F1x0_STDPERIPH_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
 * @brief Configuration of the Cortex-M3 Processor and Core Peripherals 
 */
#define __MPU_PRESENT             1        /*!!< GD32F1x0 do not provide MPU                             */
#define __NVIC_PRIO_BITS          4        /*!< GD32F1x0 uses 4 Bits for the Priority Levels             */
#define __VENDOR_SYSTICKCONFIG    0        /*!< Set to 1 if different SysTick Config is used             */

/*!< Interrupt Number Definition */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ********************************************************/
    NonMaskableInt_IRQn          = -14,    /*!< 2 Non Maskable Interrupt                                 */
    MemoryManagement_IRQn        = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt                  */
    BusFault_IRQn                = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                          */
    UsageFault_IRQn              = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                        */
    SVCall_IRQn                  = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                           */
    DebugMonitor_IRQn            = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                     */
    PendSV_IRQn                  = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                           */
    SysTick_IRQn                 = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                       */

/******  GD32F1x0 specific Interrupt Numbers ***********************************************************/
    WWDG_IRQn                    = 0,      /*!< Window WatchDog Interrupt                                */
    LVD_IRQn                     = 1,      /*!< LVD through EXTI Line detect Interrupt                   */
    RTC_IRQn                     = 2,      /*!< RTC through EXTI Line Interrupt                          */
    FMC_IRQn                     = 3,      /*!< FMC Interrupt                                            */
    RCC_IRQn                     = 4,      /*!< RCC Interrupt                                            */
    EXTI0_1_IRQn                 = 5,      /*!< EXTI Line 0 and 1 Interrupts                             */
    EXTI2_3_IRQn                 = 6,      /*!< EXTI Line 2 and 3 Interrupts                             */
    EXTI4_15_IRQn                = 7,      /*!< EXTI Line 4 to 15 Interrupts                             */
    TSI_IRQn                     = 8,      /*!< TSI Interrupt                                             */
    DMA1_Channel1_IRQn           = 9,      /*!< DMA1 Channel 1 Interrupt                                 */
    DMA1_Channel2_3_IRQn         = 10,     /*!< DMA1 Channel 2 and Channel 3 Interrupts                  */
    DMA1_Channel4_5_IRQn         = 11,     /*!< DMA1 Channel 4 and Channel 5 Interrupts                  */
    ADC1_CMP_IRQn                = 12,     /*!< ADC1, CMP1 and CMP2 Interrupts                           */
    TIMER1_BRK_UP_TRG_COM_IRQn   = 13,     /*!< TIMER1 Break, Update, Trigger and Commutation Interrupts */
    TIMER1_CC_IRQn               = 14,     /*!< TIMER1 Capture Compare Interrupt                         */
    TIMER2_IRQn                  = 15,     /*!< TIMER2 Interrupt                                         */
    TIMER3_IRQn                  = 16,     /*!< TIMER3 Interrupt                                         */
    TIMER6_DAC_IRQn              = 17,     /*!< TIMER6 and DAC Interrupts                                */
    TIMER14_IRQn                 = 19,     /*!< TIMER14 Interrupt                                        */
    TIMER15_IRQn                 = 20,     /*!< TIMER15 Interrupt                                        */
    TIMER16_IRQn                 = 21,     /*!< TIMER16 Interrupt                                        */
    TIMER17_IRQn                 = 22,     /*!< TIMER17 Interrupt                                        */
    I2C1_EV_IRQn                 = 23,     /*!< I2C1 Event Interrupt                                     */
    I2C2_EV_IRQn                 = 24,     /*!< I2C2 Event Interrupt                                     */
    SPI1_IRQn                    = 25,     /*!< SPI1 Interrupt                                           */
    SPI2_IRQn                    = 26,     /*!< SPI2 Interrupt                                           */
    USART1_IRQn                  = 27,     /*!< USART1 Interrupt                                         */
    USART2_IRQn                  = 28,     /*!< USART2 Interrupt                                         */
    CEC_IRQn                     = 30,     /*!< CEC Interrupt                                            */
    I2C1_ER_IRQn                 = 32,     /*!< I2C1 Error Interrupt                                     */
    I2C2_ER_IRQn                 = 34,     /*!< I2C2 Error Interrupt                                     */
    I2C3_EV_IRQn                 = 35,     /*!< I2C3 Event Interrupt                                     */
    I2C3_ER_IRQn                 = 36,     /*!< I2C3 Error Interrupt                                     */
    USB_FS_LP_IRQn               = 37,     /*!< USB_FS_LP Interrupt                                      */
    USB_FS_HP_IRQn               = 38,     /*!< USB_FS_HP Interrupt                                      */
    USBWakeUp_IRQChannel         = 42,     /*!< USB_WKUP Interrupt                                       */
    CAN1_TX_IRQn                 = 43,     /*!< CAN1 TX Interrupt                                        */
    CAN1_RX0_IRQn                = 44,     /*!< CAN1 RX0 Interrupt                                       */
    CAN1_RX1_IRQn                = 45,     /*!< CAN1 RX1 Interrupt                                       */
    CAN1_SCE_IRQn                = 46,     /*!< CAN1 SCE Interrupt                                       */
    LCD_IRQn                     = 47,     /*!< LCD Interrupt                                            */
    DMA1_Channel6_7_IRQn         = 48,     /*!< DMA1 Channel 4 and Channel 5 Interrupts                  */
    SPI3_IRQn                    = 51,     /*!< SPI3 global Interrupt                                    */ 
    CAN2_TX_IRQn                 = 70,     /*!< CAN2 TX Interrupt                                        */
    CAN2_RX0_IRQn                = 71,     /*!< CAN2 RX0 Interrupt                                       */
    CAN2_RX1_IRQn                = 72,     /*!< CAN2 RX1 Interrupt                                       */
    CAN2_SCE_IRQn                = 73,     /*!< CAN2 SCE Interrupt                                       */ 
} IRQn_Type;

/**
  * @}
  */

/* Includes ------------------------------------------------------------------*/
#include "core_cm3.h"
#include "system_gd32f1x0.h"
#include <stdint.h>

/** @addtogroup Exported_types
  * @{
  */  
typedef enum {ERROR = 0, SUCCESS = !ERROR, RESET = 0, SET = !RESET, DISABLE = 0, ENABLE = !DISABLE} TypeState;

/** @addtogroup Peripheral_registers_structures
  * @{
  */   


/** 
  * @brief Analog to Digital Converter  
  */
typedef struct
{
    __IO uint32_t STR;                 /*!< ADC status register,                          Address offset: 0x00  */
    __IO uint32_t CTLR1;               /*!< ADC control register 1,                       Address offset: 0x04  */
    __IO uint32_t CTLR2;               /*!< ADC control register 2,                       Address offset: 0x08  */
    __IO uint32_t SPT1;                /*!< ADC sample time register 1,                   Address offset: 0x0C  */
    __IO uint32_t SPT2;                /*!< ADC sample time register 2,                   Address offset: 0x10  */
    __IO uint32_t ICOS1;               /*!< ADC inserted channel data offset register 1,  Address offset: 0x14  */
    __IO uint32_t ICOS2;               /*!< ADC inserted channel data offset register 2,  Address offset: 0x18  */
    __IO uint32_t ICOS3;               /*!< ADC inserted channel data offset register 3,  Address offset: 0x1C  */
    __IO uint32_t ICOS4;               /*!< ADC inserted channel data offset register 4,  Address offset: 0x20  */
    __IO uint32_t AWHT;                /*!< ADC watchdog high threshold register,         Address offset: 0x24  */
    __IO uint32_t AWLT;                /*!< ADC watchdog low threshold register,          Address offset: 0x28  */
    __IO uint32_t RSQ1;                /*!< ADC regular sequence register 1,              Address offset: 0x2C  */
    __IO uint32_t RSQ2;                /*!< ADC regular sequence register 2,              Address offset: 0x30  */
    __IO uint32_t RSQ3;                /*!< ADC regular sequence register 3,              Address offset: 0x34  */
    __IO uint32_t ISQ;                 /*!< ADC inserted sequence register,               Address offset: 0x38  */
    __IO uint32_t IDTR1;               /*!< ADC inserted data register 1,                 Address offset: 0x3C  */
    __IO uint32_t IDTR2;               /*!< ADC inserted data register 2,                 Address offset: 0x40  */
    __IO uint32_t IDTR3;               /*!< ADC inserted data register 3                  Address offset: 0x44  */
    __IO uint32_t IDTR4;               /*!< ADC inserted data register 4,                 Address offset: 0x48  */
    __IO uint32_t RDTR;                /*!< ADC regular data register,                    Address offset: 0x4C  */
#ifdef GD32F170_190
    uint32_t  RESERVED[12];            /*!< Reserved,                                     Address offset: 0x50-0x7C  */
    __IO uint32_t OVSCR;               /*!< ADC oversample control register,              Address offset: 0x80  */
#endif /* GD32F170_190 */
} ADC_TypeDef;


#ifdef GD32F170_190
 /** 
  * @brief Controller Area Network TxMailBox 
  */
typedef struct
{
    __IO uint32_t TMIR;                /*!< CAN transmit mailbox identifier register,     Address offset: 0x180, 0x190, 0x1A0 */
    __IO uint32_t TMPR;                /*!< CAN transmit mailbox property register,       Address offset: 0x184, 0x194, 0x1A4 */
    __IO uint32_t TMD0R;               /*!< CAN transmit mailbox data0 register,          Address offset: 0x188, 0x198, 0x1A8 */
    __IO uint32_t TMD1R;               /*!< CAN transmit mailbox data1 register,          Address offset: 0x18C, 0x19C, 0x1AC */
} CAN_TxMailBox_TypeDef;

/** 
  * @brief Controller Area Network FIFOMailBox 
  */
typedef struct
{
    __IO uint32_t RFMIR;               /*!< CAN receive FIFO mailbox identifier register, Address offset: 0x1B0, 0x1C0 */
    __IO uint32_t RFMPR;               /*!< CAN receive FIFO mailbox property register,   Address offset: 0x1B4, 0x1C4 */
    __IO uint32_t RFMD0R;              /*!< CAN receive FIFO mailbox data0 register,      Address offset: 0x1B8, 0x1C8 */
    __IO uint32_t RFMD1R;              /*!< CAN receive FIFO mailbox data1 register,      Address offset: 0x1BC, 0x1CC */
} CAN_FIFOMailBox_TypeDef;

/** 
  * @brief Controller Area Network FilterRegister 
  */ 
typedef struct
{                          
    __IO uint32_t FD0R;                /*!< CAN filter x data 0 register ,                Address offset: 0x240..0x318 */
    __IO uint32_t FD1R;                /*!< CAN filter x data 1 register ,                Address offset: 0x244..0x31C */
} CAN_FilterRegister_TypeDef;

/** 
  * @brief Controller Area Network 
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< CAN control register,                         Address offset: 0x00 */
    __IO uint32_t STR;                 /*!< CAN status register,                          Address offset: 0x04 */
    __IO uint32_t TSTR;                /*!< CAN transmit status register,                 Address offset: 0x08 */
    __IO uint32_t RFR0;                /*!< CAN receive FIFO0 register,                   Address offset: 0x0C */
    __IO uint32_t RFR1;                /*!< CAN receive FIFO0 register,                   Address offset: 0x10 */
    __IO uint32_t IER;                 /*!< CAN interrupt enable register,                Address offset: 0x14 */
    __IO uint32_t ER;                  /*!< CAN error register,                           Address offset: 0x18 */
    __IO uint32_t BTR;                 /*!< CAN bit timing register,                      Address offset: 0x1C */
    uint32_t  RESERVED0[88];           /*!<Reserved,                                      Address offset: 0x20 */
    CAN_TxMailBox_TypeDef TxMailBox[3];/*!< CAN transmit mailbox struct,                  Address offset: 0x180 */
    CAN_FIFOMailBox_TypeDef FIFOMailBox[2];/*!< CAN receive FIFO mailbox struct,          Address offset: 0x1B0 */
    uint32_t  RESERVED1[12];           /*!<Reserved,                                      Address offset: 0x1C0 */
    __IO uint32_t FCTLR;               /*!< CAN filter control register,                  Address offset: 0x200 */   
    __IO uint32_t FMR;                 /*!< CAN filter mode register,                     Address offset: 0x204 */
    uint32_t  RESERVED2;               /*!<Reserved,                                      Address offset: 0x208 */
    __IO uint32_t FSR;                 /*!< CAN filter scale register,                    Address offset: 0x20C */
    uint32_t  RESERVED3;               /*!<Reserved,                                      Address offset: 0x210 */
    __IO uint32_t FAFR;                /*!< CAN filter associated FIFO register,          Address offset: 0x214 */
    uint32_t  RESERVED4;               /*!<Reserved,                                      Address offset: 0x218 */
    __IO uint32_t FWR;                 /*!< CAN filter working register,                  Address offset: 0x21C */
    uint32_t  RESERVED5[8];            /*!<Reserved,                                      Address offset: 0x220 */
    CAN_FilterRegister_TypeDef FilterRegister[28]; /*!< CAN FilterRegister struct,        Address offset: 0x240 */
    uint32_t  RESERVED6[55];           /*!<Reserved,                                      Address offset: 0x320 */
    __IO uint32_t CAN_PHYCR;           /*!< CAN PHY control register,                     Address offset: 0x3FC */
} CAN_TypeDef;
#endif /* GD32F170_190 */

/** 
  * @brief HDMI-CEC 
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< CEC control register,                         Address offset:0x00 */
    __IO uint32_t SR;                  /*!< CEC configuration register,                   Address offset:0x04 */
    __IO uint32_t TDTR;                /*!< CEC TDTR data register ,                      Address offset:0x08 */
    __IO uint32_t RDTR;                /*!< CEC RDTR Data Register,                       Address offset:0x0C */
    __IO uint32_t ISTR;                /*!< CEC Interrupt and Status Register,            Address offset:0x10 */
    __IO uint32_t IER;                 /*!< CEC interrupt enable register,                Address offset:0x14 */
}CEC_TypeDef;

/**
  * @brief Comparator 
  */
typedef struct
{
    __IO uint32_t CSR;                 /*!< CMP comparator control and status register,   Address offset: 0x1C */
} CMP_TypeDef;


/** 
  * @brief CRC calculation unit 
  */
typedef struct
{
    __IO uint32_t DTR;                 /*!< CRC Data register,                            Address offset: 0x00 */
    __IO uint8_t  FDTR;                /*!< CRC Independent data register,                Address offset: 0x04 */
    uint8_t   RESERVED0;               /*!< Reserved,                                     Address offset: 0x05 */
    uint16_t  RESERVED1;               /*!< Reserved,                                     Address offset: 0x06 */
    __IO uint32_t CTLR;                /*!< CRC Control register,                         Address offset: 0x08 */
    uint32_t  RESERVED2;               /*!< Reserved,                                     Address offset: 0x0C */
    __IO uint32_t IDTR;                /*!< Initial CRC value register,                   Address offset: 0x10 */
} CRC_TypeDef;

/** 
  * @brief Digital to Analog Converter
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< DAC control register                                Address offset: 0x00     */
    __IO uint32_t SWTR;                /*!< DAC software trigger register                       Address offset: 0x04     */
    __IO uint32_t DAC1_R12DHR;         /*!< DAC1 12-bit right-aligned data holding register     Address offset: 0x08     */
    __IO uint32_t DAC1_L12DHR;         /*!< DAC1 12-bit left-aligned data holding register      Address offset: 0x0C     */
    __IO uint32_t DAC1_R8DHR;          /*!< DAC1 8-bit right-aligned data holding register      Address offset: 0x10     */
#ifdef GD32F170_190
    __IO uint32_t DAC2_R12DHR;         /*!< DAC2 12-bit right-aligned data holding register     Address offset: 0x14     */
    __IO uint32_t DAC2_L12DHR;         /*!< DAC2 12-bit left-aligned data holding register      Address offset: 0x18     */
    __IO uint32_t DAC2_R8DHR;          /*!< DAC2 8-bit right-aligned data holding register      Address offset: 0x1C     */
    __IO uint32_t DACD_R12DHR;         /*!< Dual DAC 12-bit right-aligned data holding register Address offset: 0x20     */
    __IO uint32_t DACD_L12DHR;         /*!< Dual DAC 12-bit left-aligned data holding register  Address offset: 0x24     */
    __IO uint32_t DACD_R8DHR;          /*!< Dual DAC 8-bit right-aligned data holding register  Address offset: 0x28     */
#endif  /* GD32F170_190 */
    __IO uint32_t DAC1_ODR;            /*!< DAC1 output data register                           Address offset: 0x2C     */
#ifdef GD32F170_190
    __IO uint32_t DAC2_ODR;            /*!< DAC2 output data register                           Address offset: 0x30     */
#endif  /* GD32F170_190 */
    __IO uint32_t STR;                 /*!< DAC status register                                 Address offset: 0x34     */
} DAC_TypeDef;

/** 
  * @brief Debug MCU
  */
typedef struct
{
    __IO uint32_t IDR;                 /*!< MCU device ID code,                           Address offset: 0x00 */
    __IO uint32_t CTLR1;               /*!< Debug MCU CTLR1 register,                     Address offset: 0x04 */
    __IO uint32_t CTLR2;               /*!< Debug MCU CTLR1 register,                     Address offset: 0x08 */
}MCUDBG_TypeDef;

/** 
  * @brief DMA Controller
  */
typedef struct
{
    __IO uint32_t CTLRx;               /*!< DMA channel x configuration register          Address offset: 0x00 */
    __IO uint32_t RCNTx;               /*!< DMA channel x number of data register         Address offset: 0x04 */
    __IO uint32_t PBARx;               /*!< DMA channel x peripheral address register     Address offset: 0x08 */
    __IO uint32_t MBARx;               /*!< DMA channel x memory address register         Address offset: 0x0C*/
} DMA_Channel_TypeDef;

typedef struct
{
    __IO uint32_t IFR;                 /*!< DMA interrupt status register,                Address offset: 0x00 */
    __IO uint32_t ICR;                 /*!< DMA interrupt flag clear register,            Address offset: 0x04 */
} DMA_TypeDef;

/** 
  * @brief External Interrupt/Event Controller
  */
typedef struct
{
    __IO uint32_t IER;                 /*!<EXTI Interrupt enable register,                Address offset: 0x00 */
    __IO uint32_t EER;                 /*!<EXTI Event enable register,                    Address offset: 0x04 */
    __IO uint32_t RTE;                 /*!<EXTI Rising edge trigger selection register,   Address offset: 0x08 */
    __IO uint32_t FTE;                 /*!<EXTI Falling edge trigger selection register,  Address offset: 0x0C */
    __IO uint32_t SIE;                 /*!<EXTI Software interrupt event register,        Address offset: 0x10 */
    __IO uint32_t PD;                  /*!<EXTI Pending register,                         Address offset: 0x14 */
}EXTI_TypeDef;

/** 
  * @brief FMC Registers
  */
typedef struct
{
    __IO uint32_t RESR;                /*!<FMC access control register,                   Address offset: 0x00 */
    __IO uint32_t UKEYR;               /*!<FMC key register,                              Address offset: 0x04 */
    __IO uint32_t OBKEYR;              /*!<FMC OBKEYR register,                           Address offset: 0x08 */
    __IO uint32_t CSR;                 /*!<FMC status register,                           Address offset: 0x0C */
    __IO uint32_t CMR;                 /*!<FMC control register,                          Address offset: 0x10 */
    __IO uint32_t AR;                  /*!<FMC address register,                          Address offset: 0x14 */
    __IO uint32_t RESERVED;            /*!<Reserved,                                      Address offset: 0x18 */
    __IO uint32_t OPTR;                /*!<FMC option bytes register,                     Address offset: 0x1C */
    __IO uint32_t WPR;                 /*!<FMC option bytes register,                     Address offset: 0x20 */
    __IO uint32_t RESERVED1[54];       /*!<Reserved,                                      Address offset: 0x24 */
    __IO uint32_t WSCR;                /*!<FMC wait state control register ,              Address offset: 0xFC */
    __IO uint32_t RES_ID1;             /*!<Product reserved ID code register 1 ,          Address offset: 0x100 */
    __IO uint32_t RES_ID2;             /*!<Product reserved ID code register 2 ,          Address offset: 0x104 */

} FMC_TypeDef;

/** 
  * @brief Option Bytes Registers
  */
typedef struct
{
    __IO uint16_t RDP;                 /*!<FMC option byte Read protection,               Address offset: 0x00 */
    __IO uint16_t USER;                /*!<FMC option byte user options,                  Address offset: 0x02 */
    uint16_t RESERVED0;                /*!< Reserved,                                     Address offset: 0x04 */
    uint16_t RESERVED1;                /*!< Reserved,                                     Address offset: 0x06 */
    __IO uint16_t WRP0;                /*!<FMC option byte write protection 0,            Address offset: 0x08 */
    __IO uint16_t WRP1;                /*!<FMC option byte write protection 1,            Address offset: 0x0C */
} OB_TypeDef;
  
/** 
  * @brief General Purpose IO
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< GPIO port control register,                   Address offset: 0x00      */
    __IO uint32_t OMODE;               /*!< GPIO port output mode register,               Address offset: 0x04      */
    __IO uint32_t OSPD;                /*!< GPIO port output speed register,              Address offset: 0x08      */
    __IO uint32_t PUPD;                /*!< GPIO port pull-up/pull-down register,         Address offset: 0x0C      */
    __IO uint32_t DIR;                 /*!< GPIO port data input register,                Address offset: 0x10      */
    __IO uint32_t DOR;                 /*!< GPIO port data output register,               Address offset: 0x14      */
    __IO uint32_t BOR;                 /*!< GPIO port bit operation register,             Address offset: 0x18      */
    __IO uint32_t LOCKR;               /*!< GPIO port configuration lock register,        Address offset: 0x1C      */
    __IO uint32_t AFS[2];              /*!< GPIO alternate function selected register,    Address offset: 0x20-0x24 */
    __IO uint32_t BCR;                 /*!< GPIO bit clear register,                      Address offset: 0x28      */
#ifdef GD32F170_190
    __IO uint32_t TGR;                 /*!< GPIO bit toggle register,                     Address offset: 0x2C      */
#endif  /* GD32F170_190 */
} GPIO_TypeDef;

/** 
  * @brief SysTem Configuration
  */
typedef struct
{
    __IO uint32_t R1;                  /*!< SYSCFG configuration register 1,              Address offset: 0x00      */
#ifdef GD32F130_150
    uint32_t RESERVED;                 /*!< Reserved,                                     Address offset: 0x04      */
#elif defined(GD32F170_190)
    __IO uint32_t R2;                  /*!< SYSCFG configuration register 2               Address offset: 0x04      */
#endif /* GD32F130_150 */
    __IO uint32_t EXTISS[4];           /*!< SYSCFG EXTI sources selection register,       Address offset: 0x14-0x08 */
    __IO uint32_t R3;                  /*!< SYSCFG configuration register 3,              Address offset: 0x18      */
} SYSCFG_TypeDef;

/** 
  * @brief Inter-integrated Circuit Interface
  */
typedef struct
{
    __IO uint16_t CTLR1;               /*!< I2Ccontrol register 1,                        Address offset: 0x00      */
    uint16_t  RESERVED0;               /*!< Reserved,                                     Address offset: 0x02      */
    __IO uint16_t CTLR2;               /*!< I2Ccontrol register 2,                        Address offset: 0x04      */
    uint16_t  RESERVED1;               /*!< Reserved,                                     Address offset: 0x06      */
    __IO uint16_t AR1;                 /*!< I2C own address register 1 ,                  Address offset: 0x08      */
    uint16_t  RESERVED2;               /*!< Reserved,                                     Address offset: 0x0A      */
    __IO uint16_t AR2;                 /*!< I2C own address register 2,                   Address offset: 0x0C      */
    uint16_t  RESERVED3;               /*!< Reserved,                                     Address offset: 0x0E      */
    __IO uint16_t DTR;                 /*!< I2C transfer buffer register ,                Address offset: 0x10      */
    uint16_t  RESERVED4;               /*!< Reserved,                                     Address offset: 0x12      */
    __IO uint16_t STR1;                /*!< I2C transfer status register 1,               Address offset: 0x14      */
    uint16_t  RESERVED5;               /*!< Reserved,                                     Address offset: 0x16      */
    __IO uint16_t STR2;                /*!< I2C transfer status register 2,               Address offset: 0x18      */
    uint16_t  RESERVED6;               /*!< Reserved,                                     Address offset: 0x1A      */
    __IO uint16_t CLKR;                /*!< I2Cclock configure register,                  Address offset: 0x1C      */
    uint16_t  RESERVED7;               /*!< Reserved,                                     Address offset: 0x1E      */
    __IO uint16_t RTR;                 /*!< I2C Rise Time register ,                      Address offset: 0x20      */
    uint16_t  RESERVED8;               /*!< Reserved,                                     Address offset: 0x22      */
#ifdef GD32F170_190
    uint16_t  RESERVED9[46];           /*!< Reserved,                                     Address offset: 0x24      */
    __IO uint16_t SAMCSR;              /*!< I2C SAM Control and Status register,          Address offset: 0x80      */
#endif /* GD32F170_190 */
} I2C_TypeDef;

#ifdef GD32F170_190
/** 
  * @brief Programmable Current and Voltage Reference
  */
typedef struct
{
    uint32_t  RESERVED[192];
    __IO uint32_t CTLR;                /*!< IVREF control register                       Address offset: 0x300   */
} IVREF_TypeDef;
#endif  /* GD32F170_190 */

/** 
  * @brief Independent WATCHDOG
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< IWDG Control register,                       Address offset: 0x00 */
    __IO uint32_t PSR;                 /*!< IWDG Prescaler register,                     Address offset: 0x04 */
    __IO uint32_t RLDR;                /*!< IWDG Reload register,                        Address offset: 0x08 */
    __IO uint32_t STR;                 /*!< IWDG Status register,                        Address offset: 0x0C */
    __IO uint32_t WND;                 /*!< IWDG Window register,                        Address offset: 0x10 */
} IWDG_TypeDef;

#ifdef GD32F170_190
/** 
  * @brief Lcd controller
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< LCD control register,                        Address offset: 0x00  */
    __IO uint32_t CFGR;                /*!< LCD configuration register,                  Address offset: 0x04  */
    __IO uint32_t SFR;                 /*!< LCD status flag register,                    Address offset: 0x08  */
    __IO uint32_t ICR;                 /*!< LCD interrupt clear register,                Address offset: 0x0C  */
    uint32_t RESERVED;                 /*!< Reserved                                     Address offset: 0x10  */
    __IO uint32_t DATA0;               /*!< LCD data register0,                          Address offset: 0x14  */
    uint32_t RESERVED1;                /*!< Reserved                                     Address offset: 0x18  */
    __IO uint32_t DATA1;               /*!< LCD data register1,                          Address offset: 0x1C  */
    uint32_t RESERVED2;                /*!< Reserved                                     Address offset: 0x20  */
    __IO uint32_t DATA2;               /*!< LCD data register2,                          Address offset: 0x24  */
    uint32_t RESERVED3;                /*!< Reserved                                     Address offset: 0x28  */
    __IO uint32_t DATA3;               /*!< LCD data register3,                          Address offset: 0x2C  */
    uint32_t RESERVED4;                /*!< Reserved                                     Address offset: 0x30  */
    __IO uint32_t DATA4;               /*!< LCD data register4,                          Address offset: 0x34  */
    uint32_t RESERVED5;                /*!< Reserved                                     Address offset: 0x38  */
    __IO uint32_t DATA5;               /*!< LCD data register5,                          Address offset: 0x3C  */
    uint32_t RESERVED6;                /*!< Reserved                                     Address offset: 0x40  */
    __IO uint32_t DATA6;               /*!< LCD data register6,                          Address offset: 0x44  */
    uint32_t RESERVED7;                /*!< Reserved                                     Address offset: 0x4C  */
    __IO uint32_t DATA7;               /*!< LCD data register7,                          Address offset: 0x50  */
    uint32_t RESERVED8;                /*!< Reserved                                     Address offset: 0x54  */
} LCD_TypeDef;
#endif /* GD32F170_190 */

#ifdef GD32F170_190
/** 
  * @brief Operational amplifiers
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< OPAMP control register                             Address offset: 0x00     */
    __IO uint32_t OTR;                 /*!< OPAMP offset trimming register for normal mode     Address offset: 0x04     */
    __IO uint32_t LPOTR;               /*!< OPAMP offset trimming register for low power mode  Address offset: 0x08     */
} OPAMP_TypeDef; 
#endif  /* GD32F170_190 */

/** 
  * @brief Power Control
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< PWR power control register,                  Address offset: 0x00 */
    __IO uint32_t STR;                 /*!< PWR power status register,                   Address offset: 0x04 */
} PWR_TypeDef;

/** 
  * @brief Reset and Clock Control
  */
typedef struct
{
    __IO uint32_t GCCR;                /*!< RCC clock control register,                  Address offset: 0x00  */
    __IO uint32_t GCFGR;               /*!< RCC clock configuration register,            Address offset: 0x04  */
    __IO uint32_t GCIR;                /*!< RCC clock interrupt register,                Address offset: 0x08  */
    __IO uint32_t APB2RCR;             /*!< RCC APB2 peripheral reset register,          Address offset: 0x0C  */
    __IO uint32_t APB1RCR;             /*!< RCC APB1 peripheral reset register,          Address offset: 0x10  */
    __IO uint32_t AHBCCR;              /*!< RCC AHB peripheral clock register,           Address offset: 0x14  */
    __IO uint32_t APB2CCR;             /*!< RCC APB2 peripheral clock enable register,   Address offset: 0x18  */
    __IO uint32_t APB1CCR;             /*!< RCC APB1 peripheral clock enable register,   Address offset: 0x1C  */
    __IO uint32_t BDCR;                /*!< RCC Backup domain control register,          Address offset: 0x20  */
    __IO uint32_t GCSR;                /*!< RCC clock control & status register,         Address offset: 0x24  */
    __IO uint32_t AHBRCR;              /*!< RCC AHB peripheral reset register,           Address offset: 0x28  */
    __IO uint32_t GCFGR2;              /*!< RCC clock configuration register 2,          Address offset: 0x2C  */
    __IO uint32_t GCFGR3;              /*!< RCC clock configuration register 3,          Address offset: 0x30  */
    __IO uint32_t GCCR2;               /*!< RCC clock control register 2,                Address offset: 0x34  */
#ifdef GD32F170_190
    __IO uint32_t RESERVED[ 18 ];      /*!< Reserved,                                    Address offset: 0x38  */                                                                             
    __IO uint32_t GCFGR4;              /*!< RCC clock configuration register 4,          Address offset: 0x80  */
    __IO uint32_t RESERVED1[ 29 ];     /*!< Reserved,                                    Address offset: 0x84  */
#else
    __IO uint32_t RESERVED[ 48 ];      /*!< Reserved,                                    Address offset: 0x38  */
#endif /* GD32F170_190 */      
    __IO uint32_t RCC_I2C3CCR;         /*!< I2C3 Clock control register,                 Address offset: 0xF8  */
    __IO uint32_t RCC_I2C3RCR;         /*!< I2C3 Reset control register,                 Address offset: 0xFC  */
    __IO uint32_t RCC_VC_KEY  ;        /*!< Voltage Key register ,                       Address offset: 0x100 */
#ifdef GD32F170_190
    __IO uint32_t RESERVED2[ 12 ];     /*!< Reserved,                                    Address offset: 0x104 */
#else
    __IO uint32_t RESERVED1[ 12 ];     /*!< Reserved,                                    Address offset: 0x104 */
#endif /* GD32F170_190 */
    __IO uint32_t RCC_DEEPSLEEP_VC ;   /*!< RCC deep-sleep mode voltage register ,       Address offset: 0x134 */
#ifdef  GD32F130_150
    __IO uint32_t RCC_PDR_S;           /*!< RCC power down voltage select register,      Address offset: 0x138 */
#endif /* GD32F130_150 */
} RCC_TypeDef;
 

/** 
  * @brief Real-Time Clock
  */
typedef struct
{
    __IO uint32_t TR;                  /*!< RTC time register,                                         Address offset: 0x00 */
    __IO uint32_t DR;                  /*!< RTC date register,                                         Address offset: 0x04 */
    __IO uint32_t CTLR;                /*!< RTC control register,                                      Address offset: 0x08 */
    __IO uint32_t STR;                 /*!< RTC initialization and status register,                    Address offset: 0x0C */
    __IO uint32_t PSCR;                /*!< RTC prescaler register,                                    Address offset: 0x10 */
    uint32_t RESERVED0;                /*!< Reserved,                                                  Address offset: 0x14 */
    uint32_t RESERVED1;                /*!< Reserved,                                                  Address offset: 0x18 */
    __IO uint32_t ALRMR;               /*!< RTC alarm A register,                                      Address offset: 0x1C */
    uint32_t RESERVED2;                /*!< Reserved,                                                  Address offset: 0x20 */
    __IO uint32_t WPR;                 /*!< RTC write protection register,                             Address offset: 0x24 */
    __IO uint32_t SSR;                 /*!< RTC sub second register,                                   Address offset: 0x28 */
    __IO uint32_t SHIFTCTLR;           /*!< RTC shift control register,                                Address offset: 0x2C */
    __IO uint32_t TSTR;                /*!< RTC time stamp time register,                              Address offset: 0x30 */
    __IO uint32_t TSDR;                /*!< RTC time stamp date register,                              Address offset: 0x34 */
    __IO uint32_t TSSSR;               /*!< RTC time-stamp sub second register,                        Address offset: 0x38 */
    __IO uint32_t CCR;                 /*!< RTC calibration register,                                  Address offset: 0x3C */
    __IO uint32_t TAFCR;               /*!< RTC tamper and alternate function configuration register,  Address offset: 0x40 */
    __IO uint32_t ALARMSSR;            /*!< RTC alarm A sub second register,                           Address offset: 0x44 */
    uint32_t RESERVED3;                /*!< Reserved,                                                  Address offset: 0x48 */
    uint32_t RESERVED4;                /*!< Reserved,                                                  Address offset: 0x4C */
    __IO uint32_t BKP0R;               /*!< RTC backup register 0,                                     Address offset: 0x50 */
    __IO uint32_t BKP1R;               /*!< RTC backup register 1,                                     Address offset: 0x54 */
    __IO uint32_t BKP2R;               /*!< RTC backup register 2,                                     Address offset: 0x58 */
    __IO uint32_t BKP3R;               /*!< RTC backup register 3,                                     Address offset: 0x5C */
    __IO uint32_t BKP4R;               /*!< RTC backup register 4,                                     Address offset: 0x60 */
} RTC_TypeDef;

/** 
  * @brief Serial Peripheral Interface
  */
typedef struct
{
    __IO uint16_t CTLR1;               /*!< SPI Control register 1 (not used in I2S mode),             Address offset: 0x00 */
    uint16_t  RESERVED0;               /*!< Reserved,                                                  Address offset: 0x02 */
    __IO uint16_t CTLR2;               /*!< SPI Control register 2,                                    Address offset: 0x04 */
    uint16_t  RESERVED1;               /*!< Reserved,                                                  Address offset: 0x06 */
    __IO uint16_t STR;                 /*!< SPI Status register,                                       Address offset: 0x08 */
    uint16_t  RESERVED2;               /*!< Reserved,                                                  Address offset: 0x0A */
    __IO uint16_t DTR;                 /*!< SPI data register,                                         Address offset: 0x0C */
    uint16_t  RESERVED3;               /*!< Reserved,                                                  Address offset: 0x0E */
    __IO uint16_t CPR;                 /*!< SPI CRC polynomial register (not used in I2S mode),        Address offset: 0x10 */
    uint16_t  RESERVED4;               /*!< Reserved,                                                  Address offset: 0x12 */
    __IO uint16_t RCR;                 /*!< SPI Rx CRC register (not used in I2S mode),                Address offset: 0x14 */
    uint16_t  RESERVED5;               /*!< Reserved,                                                  Address offset: 0x16 */
    __IO uint16_t TCR;                 /*!< SPI Tx CRC register (not used in I2S mode),                Address offset: 0x18 */
    uint16_t  RESERVED6;               /*!< Reserved,                                                  Address offset: 0x1A */
    __IO uint16_t I2SCTLR;             /*!< SPI_I2S configuration register,                            Address offset: 0x1C */
    uint16_t  RESERVED7;               /*!< Reserved,                                                  Address offset: 0x1E */
    __IO uint16_t I2SCKP;              /*!< SPI_I2S prescaler register,                                Address offset: 0x20 */
    uint16_t  RESERVED8;               /*!< Reserved,                                                  Address offset: 0x22 */
#ifdef GD32F170_190
    uint16_t  RESERVED9[46];           /*!< Reserved,                                                  Address offset: 0x24 */
    __IO uint16_t SPIQWCR;             /*!< SPI quad wire control register,                            Address offset: 0x80 */
    uint16_t  RESERVED10;              /*!< Reserved,                                                  Address offset: 0x82 */   
#endif /* GD32F170_190 */
} SPI_TypeDef;


/** 
  * @brief TIMER
  */
typedef struct
{
    __IO uint16_t CTLR1;               /*!< TIMER control register 1,                     Address offset: 0x00 */
    uint16_t      RESERVED0;           /*!< Reserved,                                     Address offset: 0x02 */
    __IO uint16_t CTLR2;               /*!< TIMER control register 2,                     Address offset: 0x04 */
    uint16_t      RESERVED1;           /*!< Reserved,                                     Address offset: 0x06 */
    __IO uint16_t SMC;                 /*!< TIMER slave Mode Control register,            Address offset: 0x08 */
    uint16_t      RESERVED2;           /*!< Reserved,                                     Address offset: 0x0A */
    __IO uint16_t DIE;                 /*!< TIMER DMA/interrupt enable register,          Address offset: 0x0C */
    uint16_t      RESERVED3;           /*!< Reserved,                                     Address offset: 0x0E */
    __IO uint16_t STR;                 /*!< TIMER status register,                        Address offset: 0x10 */
    uint16_t      RESERVED4;           /*!< Reserved,                                     Address offset: 0x12 */
    __IO uint16_t EVG;                 /*!< TIMER event generation register,              Address offset: 0x14 */
    uint16_t      RESERVED5;           /*!< Reserved,                                     Address offset: 0x16 */
    __IO uint16_t CHCTLR1;             /*!< TIMER  capture/compare mode register 1,       Address offset: 0x18 */
    uint16_t      RESERVED6;           /*!< Reserved,                                     Address offset: 0x1A */
    __IO uint16_t CHCTLR2;             /*!< TIMER  capture/compare mode register 2,       Address offset: 0x1C */
    uint16_t      RESERVED7;           /*!< Reserved,                                     Address offset: 0x1E */
    __IO uint16_t CHE;                 /*!< TIMER capture/compare enable register,        Address offset: 0x20 */
    uint16_t      RESERVED8;           /*!< Reserved,                                     Address offset: 0x22 */
    __IO uint32_t CNT;                 /*!< TIMER counter register,                       Address offset: 0x24 */
    __IO uint16_t PSC;                 /*!< TIMER prescaler register,                     Address offset: 0x28 */
    uint16_t      RESERVED10;          /*!< Reserved,                                     Address offset: 0x2A */
    __IO uint32_t CARL;                /*!< TIMER auto-reload register,                   Address offset: 0x2C */
    __IO uint16_t CREP;                /*!< TIMER  repetition counter register,           Address offset: 0x30 */
    uint16_t      RESERVED12;          /*!< Reserved,                                     Address offset: 0x32 */
    __IO uint32_t CHCC1;               /*!< TIMER capture/compare register 1,             Address offset: 0x34 */
    __IO uint32_t CHCC2;               /*!< TIMER capture/compare register 2,             Address offset: 0x38 */
    __IO uint32_t CHCC3;               /*!< TIMER capture/compare register 3,             Address offset: 0x3C */
    __IO uint32_t CHCC4;               /*!< TIMER capture/compare register 4,             Address offset: 0x40 */
    __IO uint16_t BKDT;                /*!< TIMER break and dead-time register,           Address offset: 0x44 */
    uint16_t      RESERVED17;          /*!< Reserved,                                     Address offset: 0x26 */
    __IO uint16_t DCTLR;               /*!< TIMER DMA control register,                   Address offset: 0x48 */
    uint16_t      RESERVED18;          /*!< Reserved,                                     Address offset: 0x4A */
    __IO uint16_t DTRSF;               /*!< TIMER DMA address for full transfer register, Address offset: 0x4C */
    uint16_t      RESERVED19;          /*!< Reserved,                                     Address offset: 0x4E */
    __IO uint16_t RMP;                 /*!< TIMER CLK register,                           Address offset: 0x50 */
#ifdef GD32F130_150
    uint16_t      RESERVED20;          /*!< Reserved,                                     Address offset: 0x52 */
#endif  /* GD32F130_150 */
#ifdef GD32F170_190
    uint16_t      RESERVED20[84];      /*!< Reserved,                                     Address offset: 0x52 */
    __IO uint16_t CFGR;                /*!< TIMER configuration register,                 Address offset: 0xFC */
    uint16_t      RESERVED21;          /*!< Reserved,                                     Address offset: 0xFE */
#endif   /* GD32F170_190 */
} TIMER_TypeDef;


/** 
  * @brief Touch Sensing Controller (TSI)
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< TSI control register,                         Address offset: 0x00    */
    __IO uint32_t IER;                 /*!< TSI interrupt enable register,                Address offset: 0x04    */
    __IO uint32_t CEFR;                /*!< TSI interrupt clear register,                 Address offset: 0x08    */ 
    __IO uint32_t STR;                 /*!< TSI interrupt status register,                Address offset: 0x0C    */
    __IO uint32_t PHMR;                /*!< TSI I/O hysteresis control register,          Address offset: 0x10    */
    __IO uint32_t RESERVED1;           /*!< Reserved,                                     Address offset: 0x14    */
    __IO uint32_t ASWR;                /*!< TSI I/O analog switch control register,       Address offset: 0x18    */
    __IO uint32_t RESERVED2;           /*!< Reserved,                                     Address offset: 0x1C    */
    __IO uint32_t SPR;                 /*!< TSI I/O sampling control register,            Address offset: 0x20    */
    __IO uint32_t RESERVED3;           /*!< Reserved,                                     Address offset: 0x24    */
    __IO uint32_t CPR;                 /*!< TSI I/O channel control register,             Address offset: 0x28    */
    __IO uint32_t RESERVED4;           /*!< Reserved,                                     Address offset: 0x2C    */
    __IO uint32_t GCTLR;               /*!< TSI I/O group control status register,        Address offset: 0x30    */
    __IO uint32_t GXCYCNR[6];          /*!< TSI I/O group x counter register,             Address offset: 0x34-48 */
} TSI_TypeDef;

/** 
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
typedef struct
{
    __IO uint32_t CTLR1;               /*!< USART Control register 1,                     Address offset: 0x00 */
    __IO uint32_t CTLR2;               /*!< USART Control register 2,                     Address offset: 0x04 */
    __IO uint32_t CTLR3;               /*!< USART Control register 3,                     Address offset: 0x08 */
    __IO uint16_t BRR;                 /*!< USART Baud rate register,                     Address offset: 0x0C */
    uint16_t  RESERVED1;               /*!< Reserved,                                     Address offset: 0x0E */
    __IO uint16_t GTPR;                /*!< USART Guard time and prescaler register,      Address offset: 0x10 */
    uint16_t  RESERVED2;               /*!< Reserved,                                     Address offset: 0x12 */
    __IO uint32_t RTR;                 /*!< USART Receiver Time Out register,             Address offset: 0x14 */
    __IO uint16_t CMD;                 /*!< USART Request register,                       Address offset: 0x18 */
    uint16_t  RESERVED3;               /*!< Reserved,                                     Address offset: 0x1A */
    __IO uint32_t STR;                 /*!< USART Interrupt and status register,          Address offset: 0x1C */
    __IO uint32_t SCR;                 /*!< USART Interrupt flag Clear register,          Address offset: 0x20 */
    __IO uint16_t RDTR;                /*!< USART Receive Data register,                  Address offset: 0x24 */
    uint16_t  RESERVED4;               /*!< Reserved,                                     Address offset: 0x26 */
    __IO uint16_t TDTR;                /*!< USART Transmit Data register,                 Address offset: 0x28 */
    uint16_t  RESERVED5;               /*!< Reserved,                                     Address offset: 0x2A */
} USART_TypeDef;

/** 
  * @brief Window WATCHDOG
  */
typedef struct
{
    __IO uint32_t CTLR;                /*!< WWDG Control register,                        Address offset: 0x00 */
    __IO uint32_t CFR;                 /*!< WWDG Configuration register,                  Address offset: 0x04 */
    __IO uint32_t STR;                 /*!< WWDG Status register,                         Address offset: 0x08 */
} WWDG_TypeDef;

/**
  * @}
  */
  
/** @addtogroup Peripheral_memory_map
  * @{
  */
#define FLASH_BASE            ((uint32_t)0x08000000)           /*!< FLASH base address in the alias region         */
#define SRAM_BASE             ((uint32_t)0x20000000)           /*!< SRAM base address in the alias region          */
#define PERIPH_BASE           ((uint32_t)0x40000000)           /*!< Peripheral base address in the alias region    */

#define SRAM_BB_BASE          ((uint32_t)0x22000000)           /*!< SRAM base address in the bit-band region       */
#define PERIPH_BB_BASE        ((uint32_t)0x42000000)           /*!< Peripheral base address in the bit-band region */

/* Peripheral memory map */
#define APB1PERIPH_BASE        PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00000)

#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000)

#define TIMER2_BASE           (APB1PERIPH_BASE + 0x00000000)
#define TIMER3_BASE           (APB1PERIPH_BASE + 0x00000400)
#define TIMER6_BASE           (APB1PERIPH_BASE + 0x00001000)
#define TIMER14_BASE          (APB1PERIPH_BASE + 0x00002000)
#define LCD_BASE              (APB1PERIPH_BASE + 0x00002400)
#define RTC_BASE              (APB1PERIPH_BASE + 0x00002800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x00002C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x00003000)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x00003800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x00003C00)
#define USART2_BASE           (APB1PERIPH_BASE + 0x00004400)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x00005400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x00005800)

#define BXCAN1_BASE           (APB1PERIPH_BASE + 0x00006400)
#define BXCAN2_BASE           (APB1PERIPH_BASE + 0x00006800)


#define PWR_BASE              (APB1PERIPH_BASE + 0x00007000)
#define DAC_BASE              (APB1PERIPH_BASE + 0x00007400)
#define CEC_BASE              (APB1PERIPH_BASE + 0x00007800)
#define OPAMP_BASE            (APB1PERIPH_BASE + 0x00007C5C)
#define IVREF_BASE            (APB1PERIPH_BASE + 0x00007C00)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x0000C000)

#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x00010000)
#define CMP_BASE              (APB2PERIPH_BASE + 0x0001001C)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x00010400)
#define ADC_BASE              (APB2PERIPH_BASE + 0x00012400)
#define TIMER1_BASE           (APB2PERIPH_BASE + 0x00012C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00013000)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00013800)
#define TIMER15_BASE          (APB2PERIPH_BASE + 0x00014000)
#define TIMER16_BASE          (APB2PERIPH_BASE + 0x00014400)
#define TIMER17_BASE          (APB2PERIPH_BASE + 0x00014800)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x00000000)
#define DMA1_CHANNEL1_BASE    (DMA1_BASE + 0x00000008)
#define DMA1_CHANNEL2_BASE    (DMA1_BASE + 0x0000001C)
#define DMA1_CHANNEL3_BASE    (DMA1_BASE + 0x00000030)
#define DMA1_CHANNEL4_BASE    (DMA1_BASE + 0x00000044)
#define DMA1_CHANNEL5_BASE    (DMA1_BASE + 0x00000058)
#define DMA1_CHANNEL6_BASE    (DMA1_BASE + 0x0000006c)
#define DMA1_CHANNEL7_BASE    (DMA1_BASE + 0x00000080)
#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000)
#define FMC_R_BASE            (AHBPERIPH_BASE + 0x00002000)
#define OB_BASE               ((uint32_t)0x1FFFF800)
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000)
#define TSI_BASE              (AHBPERIPH_BASE + 0x00004000)

#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x00000000)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x00000400)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x00000800)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x00000C00)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x00001400)

#define MCUDBG_BASE           ((uint32_t)0xE0042000)

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */
#define TIMER2                ((TIMER_TypeDef *)TIMER2_BASE)
#define TIMER3                ((TIMER_TypeDef *)TIMER3_BASE)
#define TIMER6                ((TIMER_TypeDef *)TIMER6_BASE)
#define TIMER14               ((TIMER_TypeDef *)TIMER14_BASE)
#define LCD                   ((LCD_TypeDef *)LCD_BASE)
#define RTC                   ((RTC_TypeDef *)RTC_BASE)
#define WWDG                  ((WWDG_TypeDef *)WWDG_BASE)
#define IWDG                  ((IWDG_TypeDef *)IWDG_BASE)
#define SPI2                  ((SPI_TypeDef *)SPI2_BASE)
#define SPI3                  ((SPI_TypeDef *)SPI3_BASE)
#define USART2                ((USART_TypeDef *)USART2_BASE)
#define I2C1                  ((I2C_TypeDef *)I2C1_BASE)
#define I2C2                  ((I2C_TypeDef *)I2C2_BASE)
#define I2C3                  ((I2C_TypeDef *)I2C3_BASE)
#define CAN1                  ((CAN_TypeDef *)BXCAN1_BASE)
#define CAN2                  ((CAN_TypeDef *)BXCAN2_BASE)

#define PWR                   ((PWR_TypeDef *)PWR_BASE)
#define DAC                   ((DAC_TypeDef *)DAC_BASE)
#define CEC                   ((CEC_TypeDef *)CEC_BASE)
#define OPAMP                 ((OPAMP_TypeDef *)OPAMP_BASE)
#define IVREF                 ((IVREF_TypeDef *)IVREF_BASE)

#define SYSCFG                ((SYSCFG_TypeDef *)SYSCFG_BASE)
#define CMP                   ((CMP_TypeDef *)CMP_BASE)
#define EXTI                  ((EXTI_TypeDef *)EXTI_BASE)
#define ADC1                  ((ADC_TypeDef *)ADC_BASE)
#define TIMER1                ((TIMER_TypeDef *)TIMER1_BASE)
#define SPI1                  ((SPI_TypeDef *)SPI1_BASE)
#define USART1                ((USART_TypeDef *)USART1_BASE)
#define TIMER15               ((TIMER_TypeDef *)TIMER15_BASE)
#define TIMER16               ((TIMER_TypeDef *)TIMER16_BASE)
#define TIMER17               ((TIMER_TypeDef *)TIMER17_BASE)
#define MCUDBG                ((MCUDBG_TypeDef *)MCUDBG_BASE)

#define DMA1                  ((DMA_TypeDef *)DMA1_BASE)
#define DMA1_CHANNEL1         ((DMA_Channel_TypeDef *)DMA1_CHANNEL1_BASE)
#define DMA1_CHANNEL2         ((DMA_Channel_TypeDef *)DMA1_CHANNEL2_BASE)
#define DMA1_CHANNEL3         ((DMA_Channel_TypeDef *)DMA1_CHANNEL3_BASE)
#define DMA1_CHANNEL4         ((DMA_Channel_TypeDef *)DMA1_CHANNEL4_BASE)
#define DMA1_CHANNEL5         ((DMA_Channel_TypeDef *)DMA1_CHANNEL5_BASE)
#define DMA1_CHANNEL6         ((DMA_Channel_TypeDef *)DMA1_CHANNEL6_BASE)
#define DMA1_CHANNEL7         ((DMA_Channel_TypeDef *)DMA1_CHANNEL7_BASE)
#define FMC                   ((FMC_TypeDef *)FMC_R_BASE)
#define OB                    ((OB_TypeDef *)OB_BASE) 
#define RCC                   ((RCC_TypeDef *)RCC_BASE)
#define CRC                   ((CRC_TypeDef *)CRC_BASE)
#define TSI                   ((TSI_TypeDef *)TSI_BASE)

#define GPIOA                 ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                 ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                 ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                 ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOF                 ((GPIO_TypeDef *)GPIOF_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */
  
  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                        Analog to Digital Converter                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_STR register  *******************/
#define  ADC_STR_AWE                         ((uint8_t)0x01)                   /*!< Analog watchdog flag */
#define  ADC_STR_EOC                         ((uint8_t)0x02)                   /*!< End of conversion */
#define  ADC_STR_EOIC                        ((uint8_t)0x04)                   /*!< Injected channel end of conversion */
#define  ADC_STR_STIC                        ((uint8_t)0x08)                   /*!< Injected channel Start flag */
#define  ADC_STR_STRC                        ((uint8_t)0x10)                   /*!< Regular channel Start flag */

/*******************  Bit definition for ADC_CTLR1 register  ******************/
#define  ADC_CTLR1_AWCS                      ((uint32_t)0x0000001F)            /*!< AWCS[4:0] bits (Analog watchdog channel select bits) */
#define  ADC_CTLR1_AWCS_0                    ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  ADC_CTLR1_AWCS_1                    ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  ADC_CTLR1_AWCS_2                    ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  ADC_CTLR1_AWCS_3                    ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  ADC_CTLR1_AWCS_4                    ((uint32_t)0x00000010)            /*!< Bit 4 */

#define  ADC_CTLR1_EOCIE                     ((uint32_t)0x00000020)            /*!< Interrupt enable for EOC */
#define  ADC_CTLR1_AWEIE                     ((uint32_t)0x00000040)            /*!< Analog Watchdog interrupt enable */
#define  ADC_CTLR1_EOICIE                    ((uint32_t)0x00000080)            /*!< Interrupt enable for injected channels */
#define  ADC_CTLR1_SM                        ((uint32_t)0x00000100)            /*!< Scan mode */
#define  ADC_CTLR1_AWSSM                     ((uint32_t)0x00000200)            /*!< Enable the watchdog on a single channel in scan mode */
#define  ADC_CTLR1_ICA                       ((uint32_t)0x00000400)            /*!< Automatic injected group conversion */
#define  ADC_CTLR1_DISRC                     ((uint32_t)0x00000800)            /*!< Discontinuous mode on regular channels */
#define  ADC_CTLR1_DISIC                     ((uint32_t)0x00001000)            /*!< Discontinuous mode on injected channels */

#define  ADC_CTLR1_DISNUM                    ((uint32_t)0x0000E000)            /*!< DISNUM[2:0] bits (Discontinuous mode channel count) */
#define  ADC_CTLR1_DISNUM_0                  ((uint32_t)0x00002000)            /*!< Bit 0 */
#define  ADC_CTLR1_DISNUM_1                  ((uint32_t)0x00004000)            /*!< Bit 1 */
#define  ADC_CTLR1_DISNUM_2                  ((uint32_t)0x00008000)            /*!< Bit 2 */

#define  ADC_CTLR1_AWIEN                     ((uint32_t)0x00400000)            /*!< Analog watchdog enable on injected channels */
#define  ADC_CTLR1_AWREN                     ((uint32_t)0x00800000)            /*!< Analog watchdog enable on regular channels */

#ifdef GD32F170_190
#define  ADC_CTLR1_DRES                      ((uint32_t)0x03000000)            /*!< ADC resolution */
#define  ADC_CTLR1_DRES_0                    ((uint32_t)0x01000000)            /*!< Bit 0 */
#define  ADC_CTLR1_DRES_1                    ((uint32_t)0x02000000)            /*!< Bit 1 */
#endif /* GD32F170_190 */

/********************  Bit definition for ADC_CTLR2 register  *****************/
#define  ADC_CTLR2_ADCON                     ((uint32_t)0x00000001)            /*!< A/D Converter ON / OFF */
#define  ADC_CTLR2_CTN                       ((uint32_t)0x00000002)            /*!< Continuous Conversion */
#define  ADC_CTLR2_CLB                       ((uint32_t)0x00000004)            /*!< A/D Calibration */
#define  ADC_CTLR2_RSTCLB                    ((uint32_t)0x00000008)            /*!< Reset Calibration */
#define  ADC_CTLR2_DMA                       ((uint32_t)0x00000100)            /*!< Direct Memory access mode */
#define  ADC_CTLR2_DAL                       ((uint32_t)0x00000800)            /*!< Data Alignment */

#define  ADC_CTLR2_ETSIC                     ((uint32_t)0x00007000)            /*!< ETSIC[2:0] bits (External event select for injected group) */
#define  ADC_CTLR2_ETSIC_0                   ((uint32_t)0x00001000)            /*!< Bit 0 */
#define  ADC_CTLR2_ETSIC_1                   ((uint32_t)0x00002000)            /*!< Bit 1 */
#define  ADC_CTLR2_ETSIC_2                   ((uint32_t)0x00004000)            /*!< Bit 2 */

#define  ADC_CTLR2_ETEIC                     ((uint32_t)0x00008000)            /*!< External Trigger Conversion mode for injected channels */

#define  ADC_CTLR2_ETSRC                     ((uint32_t)0x000E0000)            /*!< ETSRC[2:0] bits (External Event Select for regular group) */
#define  ADC_CTLR2_ETSRC_0                   ((uint32_t)0x00020000)            /*!< Bit 0 */
#define  ADC_CTLR2_ETSRC_1                   ((uint32_t)0x00040000)            /*!< Bit 1 */
#define  ADC_CTLR2_ETSRC_2                   ((uint32_t)0x00080000)            /*!< Bit 2 */

#define  ADC_CTLR2_ETERC                     ((uint32_t)0x00100000)            /*!< External Trigger Conversion mode for regular channels */
#define  ADC_CTLR2_SWICST                    ((uint32_t)0x00200000)            /*!< Start Conversion of injected channels */
#define  ADC_CTLR2_SWRCST                    ((uint32_t)0x00400000)            /*!< Start Conversion of regular channels */
#define  ADC_CTLR2_TSVREN                    ((uint32_t)0x00800000)            /*!< Temperature Sensor and VREFINT Enable */
#define  ADC_CTLR2_VBATEN                    ((uint32_t)0x00C00000)            /*!< VBAT  Enable */

/******************  Bit definition for ADC_SPT1 register  ********************/
#define  ADC_SPT1_SPT10                      ((uint32_t)0x00000007)            /*!< SPT10[2:0] bits (Channel 10 Sample time selection) */
#define  ADC_SPT1_SPT10_0                    ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  ADC_SPT1_SPT10_1                    ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  ADC_SPT1_SPT10_2                    ((uint32_t)0x00000004)            /*!< Bit 2 */

#define  ADC_SPT1_SPT11                      ((uint32_t)0x00000038)            /*!< SPT11[2:0] bits (Channel 11 Sample time selection) */
#define  ADC_SPT1_SPT11_0                    ((uint32_t)0x00000008)            /*!< Bit 0 */
#define  ADC_SPT1_SPT11_1                    ((uint32_t)0x00000010)            /*!< Bit 1 */
#define  ADC_SPT1_SPT11_2                    ((uint32_t)0x00000020)            /*!< Bit 2 */

#define  ADC_SPT1_SPT12                      ((uint32_t)0x000001C0)            /*!< SPT12[2:0] bits (Channel 12 Sample time selection) */
#define  ADC_SPT1_SPT12_0                    ((uint32_t)0x00000040)            /*!< Bit 0 */
#define  ADC_SPT1_SPT12_1                    ((uint32_t)0x00000080)            /*!< Bit 1 */
#define  ADC_SPT1_SPT12_2                    ((uint32_t)0x00000100)            /*!< Bit 2 */

#define  ADC_SPT1_SPT13                      ((uint32_t)0x00000E00)            /*!< SPT13[2:0] bits (Channel 13 Sample time selection) */
#define  ADC_SPT1_SPT13_0                    ((uint32_t)0x00000200)            /*!< Bit 0 */
#define  ADC_SPT1_SPT13_1                    ((uint32_t)0x00000400)            /*!< Bit 1 */
#define  ADC_SPT1_SPT13_2                    ((uint32_t)0x00000800)            /*!< Bit 2 */

#define  ADC_SPT1_SPT14                      ((uint32_t)0x00007000)            /*!< SPT14[2:0] bits (Channel 14 Sample time selection) */
#define  ADC_SPT1_SPT14_0                    ((uint32_t)0x00001000)            /*!< Bit 0 */
#define  ADC_SPT1_SPT14_1                    ((uint32_t)0x00002000)            /*!< Bit 1 */
#define  ADC_SPT1_SPT14_2                    ((uint32_t)0x00004000)            /*!< Bit 2 */

#define  ADC_SPT1_SPT15                      ((uint32_t)0x00038000)            /*!< SPT15[2:0] bits (Channel 15 Sample time selection) */
#define  ADC_SPT1_SPT15_0                    ((uint32_t)0x00008000)            /*!< Bit 0 */
#define  ADC_SPT1_SPT15_1                    ((uint32_t)0x00010000)            /*!< Bit 1 */
#define  ADC_SPT1_SPT15_2                    ((uint32_t)0x00020000)            /*!< Bit 2 */

#define  ADC_SPT1_SPT16                      ((uint32_t)0x001C0000)            /*!< SPT16[2:0] bits (Channel 16 Sample time selection) */
#define  ADC_SPT1_SPT16_0                    ((uint32_t)0x00040000)            /*!< Bit 0 */
#define  ADC_SPT1_SPT16_1                    ((uint32_t)0x00080000)            /*!< Bit 1 */
#define  ADC_SPT1_SPT16_2                    ((uint32_t)0x00100000)            /*!< Bit 2 */

#define  ADC_SPT1_SPT17                      ((uint32_t)0x00E00000)            /*!< SPT17[2:0] bits (Channel 17 Sample time selection) */
#define  ADC_SPT1_SPT17_0                    ((uint32_t)0x00200000)            /*!< Bit 0 */
#define  ADC_SPT1_SPT17_1                    ((uint32_t)0x00400000)            /*!< Bit 1 */
#define  ADC_SPT1_SPT17_2                    ((uint32_t)0x00800000)            /*!< Bit 2 */

#ifdef GD32F170_190
#define  ADC_SPT1_SPT18                      ((uint32_t)0x07000000)            /*!< SPT17[2:0] bits (Channel 17 Sample time selection) */
#define  ADC_SPT1_SPT18_0                    ((uint32_t)0x01000000)            /*!< Bit 0 */
#define  ADC_SPT1_SPT18_1                    ((uint32_t)0x02000000)            /*!< Bit 1 */
#define  ADC_SPT1_SPT18_2                    ((uint32_t)0x04000000)            /*!< Bit 2 */
#endif /* GD32F170_190 */

/********************  Bit definition for ADC_SPT2 register  ******************/
#define  ADC_SPT2_SPT0                       ((uint32_t)0x00000007)            /*!< SPT0[2:0] bits (Channel 0 Sample time selection) */
#define  ADC_SPT2_SPT0_0                     ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  ADC_SPT2_SPT0_1                     ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  ADC_SPT2_SPT0_2                     ((uint32_t)0x00000004)            /*!< Bit 2 */

#define  ADC_SPT2_SPT1                       ((uint32_t)0x00000038)            /*!< SPT1[2:0] bits (Channel 1 Sample time selection) */
#define  ADC_SPT2_SPT1_0                     ((uint32_t)0x00000008)            /*!< Bit 0 */
#define  ADC_SPT2_SPT1_1                     ((uint32_t)0x00000010)            /*!< Bit 1 */
#define  ADC_SPT2_SPT1_2                     ((uint32_t)0x00000020)            /*!< Bit 2 */

#define  ADC_SPT2_SPT2                       ((uint32_t)0x000001C0)            /*!< SPT2[2:0] bits (Channel 2 Sample time selection) */
#define  ADC_SPT2_SPT2_0                     ((uint32_t)0x00000040)            /*!< Bit 0 */
#define  ADC_SPT2_SPT2_1                     ((uint32_t)0x00000080)            /*!< Bit 1 */
#define  ADC_SPT2_SPT2_2                     ((uint32_t)0x00000100)            /*!< Bit 2 */

#define  ADC_SPT2_SPT3                       ((uint32_t)0x00000E00)            /*!< SPT3[2:0] bits (Channel 3 Sample time selection) */
#define  ADC_SPT2_SPT3_0                     ((uint32_t)0x00000200)            /*!< Bit 0 */
#define  ADC_SPT2_SPT3_1                     ((uint32_t)0x00000400)            /*!< Bit 1 */
#define  ADC_SPT2_SPT3_2                     ((uint32_t)0x00000800)            /*!< Bit 2 */

#define  ADC_SPT2_SPT4                       ((uint32_t)0x00007000)            /*!< SPT4[2:0] bits (Channel 4 Sample time selection) */
#define  ADC_SPT2_SPT4_0                     ((uint32_t)0x00001000)            /*!< Bit 0 */
#define  ADC_SPT2_SPT4_1                     ((uint32_t)0x00002000)            /*!< Bit 1 */
#define  ADC_SPT2_SPT4_2                     ((uint32_t)0x00004000)            /*!< Bit 2 */

#define  ADC_SPT2_SPT5                       ((uint32_t)0x00038000)            /*!< SPT5[2:0] bits (Channel 5 Sample time selection) */
#define  ADC_SPT2_SPT5_0                     ((uint32_t)0x00008000)            /*!< Bit 0 */
#define  ADC_SPT2_SPT5_1                     ((uint32_t)0x00010000)            /*!< Bit 1 */
#define  ADC_SPT2_SPT5_2                     ((uint32_t)0x00020000)            /*!< Bit 2 */

#define  ADC_SPT2_SPT6                       ((uint32_t)0x001C0000)            /*!< SPT6[2:0] bits (Channel 6 Sample time selection) */
#define  ADC_SPT2_SPT6_0                     ((uint32_t)0x00040000)            /*!< Bit 0 */
#define  ADC_SPT2_SPT6_1                     ((uint32_t)0x00080000)            /*!< Bit 1 */
#define  ADC_SPT2_SPT6_2                     ((uint32_t)0x00100000)            /*!< Bit 2 */

#define  ADC_SPT2_SPT7                       ((uint32_t)0x00E00000)            /*!< SPT7[2:0] bits (Channel 7 Sample time selection) */
#define  ADC_SPT2_SPT7_0                     ((uint32_t)0x00200000)            /*!< Bit 0 */
#define  ADC_SPT2_SPT7_1                     ((uint32_t)0x00400000)            /*!< Bit 1 */
#define  ADC_SPT2_SPT7_2                     ((uint32_t)0x00800000)            /*!< Bit 2 */

#define  ADC_SPT2_SPT8                       ((uint32_t)0x07000000)            /*!< SPT8[2:0] bits (Channel 8 Sample time selection) */
#define  ADC_SPT2_SPT8_0                     ((uint32_t)0x01000000)            /*!< Bit 0 */
#define  ADC_SPT2_SPT8_1                     ((uint32_t)0x02000000)            /*!< Bit 1 */
#define  ADC_SPT2_SPT8_2                     ((uint32_t)0x04000000)            /*!< Bit 2 */

#define  ADC_SPT2_SPT9                       ((uint32_t)0x38000000)            /*!< SPT9[2:0] bits (Channel 9 Sample time selection) */
#define  ADC_SPT2_SPT9_0                     ((uint32_t)0x08000000)            /*!< Bit 0 */
#define  ADC_SPT2_SPT9_1                     ((uint32_t)0x10000000)            /*!< Bit 1 */
#define  ADC_SPT2_SPT9_2                     ((uint32_t)0x20000000)            /*!< Bit 2 */

/******************  Bit definition for ADC_ICOS1 register  *******************/
#define  ADC_ICOS1_ICOS1                     ((uint16_t)0x0FFF)                /*!< Data offset for injected channel 1 */

/******************  Bit definition for ADC_ICOS2 register  *******************/
#define  ADC_ICOS2_ICOS2                     ((uint16_t)0x0FFF)                /*!< Data offset for injected channel 2 */

/******************  Bit definition for ADC_ICOS3 register  *******************/
#define  ADC_ICOS3_ICOS3                     ((uint16_t)0x0FFF)                /*!< Data offset for injected channel 3 */

/******************  Bit definition for ADC_ICOS4 register  *******************/
#define  ADC_ICOS4_ICOS4                     ((uint16_t)0x0FFF)                /*!< Data offset for injected channel 4 */

/*******************  Bit definition for ADC_AWHT register  *******************/
#define  ADC_AWHT_AWHT                       ((uint16_t)0x0FFF)                /*!< Analog watchdog high threshold */

/*******************  Bit definition for ADC_AWLT register  *******************/
#define  ADC_AWLT_AWLT                       ((uint16_t)0x0FFF)                /*!< Analog watchdog low threshold */

/*******************  Bit definition for ADC_RSQ1 register  *******************/
#define  ADC_RSQ1_RSQ13                      ((uint32_t)0x0000001F)            /*!< RSQ13[4:0] bits (13th conversion in regular sequence) */
#define  ADC_RSQ1_RSQ13_0                    ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  ADC_RSQ1_RSQ13_1                    ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  ADC_RSQ1_RSQ13_2                    ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  ADC_RSQ1_RSQ13_3                    ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  ADC_RSQ1_RSQ13_4                    ((uint32_t)0x00000010)            /*!< Bit 4 */

#define  ADC_RSQ1_RSQ14                      ((uint32_t)0x000003E0)            /*!< RSQ14[4:0] bits (14th conversion in regular sequence) */
#define  ADC_RSQ1_RSQ14_0                    ((uint32_t)0x00000020)            /*!< Bit 0 */
#define  ADC_RSQ1_RSQ14_1                    ((uint32_t)0x00000040)            /*!< Bit 1 */
#define  ADC_RSQ1_RSQ14_2                    ((uint32_t)0x00000080)            /*!< Bit 2 */
#define  ADC_RSQ1_RSQ14_3                    ((uint32_t)0x00000100)            /*!< Bit 3 */
#define  ADC_RSQ1_RSQ14_4                    ((uint32_t)0x00000200)            /*!< Bit 4 */

#define  ADC_RSQ1_RSQ15                      ((uint32_t)0x00007C00)            /*!< RSQ15[4:0] bits (15th conversion in regular sequence) */
#define  ADC_RSQ1_RSQ15_0                    ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  ADC_RSQ1_RSQ15_1                    ((uint32_t)0x00000800)            /*!< Bit 1 */
#define  ADC_RSQ1_RSQ15_2                    ((uint32_t)0x00001000)            /*!< Bit 2 */
#define  ADC_RSQ1_RSQ15_3                    ((uint32_t)0x00002000)            /*!< Bit 3 */
#define  ADC_RSQ1_RSQ15_4                    ((uint32_t)0x00004000)            /*!< Bit 4 */

#define  ADC_RSQ1_RSQ16                      ((uint32_t)0x000F8000)            /*!< RSQ16[4:0] bits (16th conversion in regular sequence) */
#define  ADC_RSQ1_RSQ16_0                    ((uint32_t)0x00008000)            /*!< Bit 0 */
#define  ADC_RSQ1_RSQ16_1                    ((uint32_t)0x00010000)            /*!< Bit 1 */
#define  ADC_RSQ1_RSQ16_2                    ((uint32_t)0x00020000)            /*!< Bit 2 */
#define  ADC_RSQ1_RSQ16_3                    ((uint32_t)0x00040000)            /*!< Bit 3 */
#define  ADC_RSQ1_RSQ16_4                    ((uint32_t)0x00080000)            /*!< Bit 4 */

#define  ADC_RSQ1_RL                         ((uint32_t)0x00F00000)            /*!< RL[3:0] bits (Regular channel sequence length) */
#define  ADC_RSQ1_RL_0                       ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  ADC_RSQ1_RL_1                       ((uint32_t)0x00200000)            /*!< Bit 1 */
#define  ADC_RSQ1_RL_2                       ((uint32_t)0x00400000)            /*!< Bit 2 */
#define  ADC_RSQ1_RL_3                       ((uint32_t)0x00800000)            /*!< Bit 3 */

/*******************  Bit definition for ADC_RSQ2 register  *******************/
#define  ADC_RSQ2_RSQ7                       ((uint32_t)0x0000001F)            /*!< RSQ7[4:0] bits (7th conversion in regular sequence) */
#define  ADC_RSQ2_RSQ7_0                     ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  ADC_RSQ2_RSQ7_1                     ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  ADC_RSQ2_RSQ7_2                     ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  ADC_RSQ2_RSQ7_3                     ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  ADC_RSQ2_RSQ7_4                     ((uint32_t)0x00000010)            /*!< Bit 4 */

#define  ADC_RSQ2_RSQ8                       ((uint32_t)0x000003E0)            /*!< RSQ8[4:0] bits (8th conversion in regular sequence) */
#define  ADC_RSQ2_RSQ8_0                     ((uint32_t)0x00000020)            /*!< Bit 0 */
#define  ADC_RSQ2_RSQ8_1                     ((uint32_t)0x00000040)            /*!< Bit 1 */
#define  ADC_RSQ2_RSQ8_2                     ((uint32_t)0x00000080)            /*!< Bit 2 */
#define  ADC_RSQ2_RSQ8_3                     ((uint32_t)0x00000100)            /*!< Bit 3 */
#define  ADC_RSQ2_RSQ8_4                     ((uint32_t)0x00000200)            /*!< Bit 4 */

#define  ADC_RSQ2_RSQ9                       ((uint32_t)0x00007C00)            /*!< RSQ9[4:0] bits (9th conversion in regular sequence) */
#define  ADC_RSQ2_RSQ9_0                     ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  ADC_RSQ2_RSQ9_1                     ((uint32_t)0x00000800)            /*!< Bit 1 */
#define  ADC_RSQ2_RSQ9_2                     ((uint32_t)0x00001000)            /*!< Bit 2 */
#define  ADC_RSQ2_RSQ9_3                     ((uint32_t)0x00002000)            /*!< Bit 3 */
#define  ADC_RSQ2_RSQ9_4                     ((uint32_t)0x00004000)            /*!< Bit 4 */

#define  ADC_RSQ2_RSQ10                      ((uint32_t)0x000F8000)            /*!< RSQ10[4:0] bits (10th conversion in regular sequence) */
#define  ADC_RSQ2_RSQ10_0                    ((uint32_t)0x00008000)            /*!< Bit 0 */
#define  ADC_RSQ2_RSQ10_1                    ((uint32_t)0x00010000)            /*!< Bit 1 */
#define  ADC_RSQ2_RSQ10_2                    ((uint32_t)0x00020000)            /*!< Bit 2 */
#define  ADC_RSQ2_RSQ10_3                    ((uint32_t)0x00040000)            /*!< Bit 3 */
#define  ADC_RSQ2_RSQ10_4                    ((uint32_t)0x00080000)            /*!< Bit 4 */

#define  ADC_RSQ2_RSQ11                      ((uint32_t)0x01F00000)            /*!< RSQ11[4:0] bits (11th conversion in regular sequence) */
#define  ADC_RSQ2_RSQ11_0                    ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  ADC_RSQ2_RSQ11_1                    ((uint32_t)0x00200000)            /*!< Bit 1 */
#define  ADC_RSQ2_RSQ11_2                    ((uint32_t)0x00400000)            /*!< Bit 2 */
#define  ADC_RSQ2_RSQ11_3                    ((uint32_t)0x00800000)            /*!< Bit 3 */
#define  ADC_RSQ2_RSQ11_4                    ((uint32_t)0x01000000)            /*!< Bit 4 */

#define  ADC_RSQ2_RSQ12                      ((uint32_t)0x3E000000)            /*!< RSQ12[4:0] bits (12th conversion in regular sequence) */
#define  ADC_RSQ2_RSQ12_0                    ((uint32_t)0x02000000)            /*!< Bit 0 */
#define  ADC_RSQ2_RSQ12_1                    ((uint32_t)0x04000000)            /*!< Bit 1 */
#define  ADC_RSQ2_RSQ12_2                    ((uint32_t)0x08000000)            /*!< Bit 2 */
#define  ADC_RSQ2_RSQ12_3                    ((uint32_t)0x10000000)            /*!< Bit 3 */
#define  ADC_RSQ2_RSQ12_4                    ((uint32_t)0x20000000)            /*!< Bit 4 */

/*******************  Bit definition for ADC_RSQ3 register  *******************/
#define  ADC_RSQ3_RSQ1                       ((uint32_t)0x0000001F)            /*!< RSQ1[4:0] bits (1st conversion in regular sequence) */
#define  ADC_RSQ3_RSQ1_0                     ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  ADC_RSQ3_RSQ1_1                     ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  ADC_RSQ3_RSQ1_2                     ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  ADC_RSQ3_RSQ1_3                     ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  ADC_RSQ3_RSQ1_4                     ((uint32_t)0x00000010)            /*!< Bit 4 */

#define  ADC_RSQ3_RSQ2                       ((uint32_t)0x000003E0)            /*!< RSQ2[4:0] bits (2nd conversion in regular sequence) */
#define  ADC_RSQ3_RSQ2_0                     ((uint32_t)0x00000020)            /*!< Bit 0 */
#define  ADC_RSQ3_RSQ2_1                     ((uint32_t)0x00000040)            /*!< Bit 1 */
#define  ADC_RSQ3_RSQ2_2                     ((uint32_t)0x00000080)            /*!< Bit 2 */
#define  ADC_RSQ3_RSQ2_3                     ((uint32_t)0x00000100)            /*!< Bit 3 */
#define  ADC_RSQ3_RSQ2_4                     ((uint32_t)0x00000200)            /*!< Bit 4 */

#define  ADC_RSQ3_RSQ3                       ((uint32_t)0x00007C00)            /*!< RSQ3[4:0] bits (3rd conversion in regular sequence) */
#define  ADC_RSQ3_RSQ3_0                     ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  ADC_RSQ3_RSQ3_1                     ((uint32_t)0x00000800)            /*!< Bit 1 */
#define  ADC_RSQ3_RSQ3_2                     ((uint32_t)0x00001000)            /*!< Bit 2 */
#define  ADC_RSQ3_RSQ3_3                     ((uint32_t)0x00002000)            /*!< Bit 3 */
#define  ADC_RSQ3_RSQ3_4                     ((uint32_t)0x00004000)            /*!< Bit 4 */

#define  ADC_RSQ3_RSQ4                       ((uint32_t)0x000F8000)            /*!< RSQ4[4:0] bits (4th conversion in regular sequence) */
#define  ADC_RSQ3_RSQ4_0                     ((uint32_t)0x00008000)            /*!< Bit 0 */
#define  ADC_RSQ3_RSQ4_1                     ((uint32_t)0x00010000)            /*!< Bit 1 */
#define  ADC_RSQ3_RSQ4_2                     ((uint32_t)0x00020000)            /*!< Bit 2 */
#define  ADC_RSQ3_RSQ4_3                     ((uint32_t)0x00040000)            /*!< Bit 3 */
#define  ADC_RSQ3_RSQ4_4                     ((uint32_t)0x00080000)            /*!< Bit 4 */

#define  ADC_RSQ3_RSQ5                       ((uint32_t)0x01F00000)            /*!< RSQ5[4:0] bits (5th conversion in regular sequence) */
#define  ADC_RSQ3_RSQ5_0                     ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  ADC_RSQ3_RSQ5_1                     ((uint32_t)0x00200000)            /*!< Bit 1 */
#define  ADC_RSQ3_RSQ5_2                     ((uint32_t)0x00400000)            /*!< Bit 2 */
#define  ADC_RSQ3_RSQ5_3                     ((uint32_t)0x00800000)            /*!< Bit 3 */
#define  ADC_RSQ3_RSQ5_4                     ((uint32_t)0x01000000)            /*!< Bit 4 */

#define  ADC_RSQ3_RSQ6                       ((uint32_t)0x3E000000)            /*!< RSQ6[4:0] bits (6th conversion in regular sequence) */
#define  ADC_RSQ3_RSQ6_0                     ((uint32_t)0x02000000)            /*!< Bit 0 */
#define  ADC_RSQ3_RSQ6_1                     ((uint32_t)0x04000000)            /*!< Bit 1 */
#define  ADC_RSQ3_RSQ6_2                     ((uint32_t)0x08000000)            /*!< Bit 2 */
#define  ADC_RSQ3_RSQ6_3                     ((uint32_t)0x10000000)            /*!< Bit 3 */
#define  ADC_RSQ3_RSQ6_4                     ((uint32_t)0x20000000)            /*!< Bit 4 */

/*******************  Bit definition for ADC_ISQ register  ********************/
#define  ADC_ISQ_ISQ1                        ((uint32_t)0x0000001F)            /*!< ISQ1[4:0] bits (1st conversion in injected sequence) */  
#define  ADC_ISQ_ISQ1_0                      ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  ADC_ISQ_ISQ1_1                      ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  ADC_ISQ_ISQ1_2                      ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  ADC_ISQ_ISQ1_3                      ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  ADC_ISQ_ISQ1_4                      ((uint32_t)0x00000010)            /*!< Bit 4 */

#define  ADC_ISQ_ISQ2                        ((uint32_t)0x000003E0)            /*!< ISQ2[4:0] bits (2nd conversion in injected sequence) */
#define  ADC_ISQ_ISQ2_0                      ((uint32_t)0x00000020)            /*!< Bit 0 */
#define  ADC_ISQ_ISQ2_1                      ((uint32_t)0x00000040)            /*!< Bit 1 */
#define  ADC_ISQ_ISQ2_2                      ((uint32_t)0x00000080)            /*!< Bit 2 */
#define  ADC_ISQ_ISQ2_3                      ((uint32_t)0x00000100)            /*!< Bit 3 */
#define  ADC_ISQ_ISQ2_4                      ((uint32_t)0x00000200)            /*!< Bit 4 */

#define  ADC_ISQ_ISQ3                        ((uint32_t)0x00007C00)            /*!< ISQ3[4:0] bits (3rd conversion in injected sequence) */
#define  ADC_ISQ_ISQ3_0                      ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  ADC_ISQ_ISQ3_1                      ((uint32_t)0x00000800)            /*!< Bit 1 */
#define  ADC_ISQ_ISQ3_2                      ((uint32_t)0x00001000)            /*!< Bit 2 */
#define  ADC_ISQ_ISQ3_3                      ((uint32_t)0x00002000)            /*!< Bit 3 */
#define  ADC_ISQ_ISQ3_4                      ((uint32_t)0x00004000)            /*!< Bit 4 */

#define  ADC_ISQ_ISQ4                        ((uint32_t)0x000F8000)            /*!< ISQ4[4:0] bits (4th conversion in injected sequence) */
#define  ADC_ISQ_ISQ4_0                      ((uint32_t)0x00008000)            /*!< Bit 0 */
#define  ADC_ISQ_ISQ4_1                      ((uint32_t)0x00010000)            /*!< Bit 1 */
#define  ADC_ISQ_ISQ4_2                      ((uint32_t)0x00020000)            /*!< Bit 2 */
#define  ADC_ISQ_ISQ4_3                      ((uint32_t)0x00040000)            /*!< Bit 3 */
#define  ADC_ISQ_ISQ4_4                      ((uint32_t)0x00080000)            /*!< Bit 4 */

#define  ADC_ISQ_IL                          ((uint32_t)0x00300000)            /*!< IL[1:0] bits (Injected Sequence length) */
#define  ADC_ISQ_IL_0                        ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  ADC_ISQ_IL_1                        ((uint32_t)0x00200000)            /*!< Bit 1 */

/*******************  Bit definition for ADC_IDTR1 register  ******************/
#define  ADC_IDTR1_IDTR                      ((uint16_t)0xFFFF)                /*!< Injected data */

/*******************  Bit definition for ADC_IDTR2 register  ******************/
#define  ADC_IDTR2_IDTR                      ((uint16_t)0xFFFF)                /*!< Injected data */

/*******************  Bit definition for ADC_IDTR3 register  ******************/
#define  ADC_IDTR3_IDTR                      ((uint16_t)0xFFFF)                /*!< Injected data */

/*******************  Bit definition for ADC_IDTR4 register  ******************/
#define  ADC_IDTR4_IDTR                      ((uint16_t)0xFFFF)                /*!< Injected data */

/********************  Bit definition for ADC_RDTR register  ******************/
#define  ADC_RDTR_RDTR                       ((uint32_t)0x0000FFFF)            /*!< Regular data */

#ifdef GD32F170_190
/********************  Bit definition for ADC_OVSCR register  *****************/
#define  ADC_OVSCR_OVSE                      ((uint32_t)0x00000001)            /*!< OVSE bit */

#define  ADC_OVSCR_OVSR                      ((uint32_t)0x0000001C)            /*!< OVERSAMPLING_RATIO[2:0] bits */
#define  ADC_OVSCR_OVSR_0                    ((uint32_t)0x00000004)            /*!< Bit 0 */
#define  ADC_OVSCR_OVSR_1                    ((uint32_t)0x00000008)            /*!< Bit 1 */
#define  ADC_OVSCR_OVSR_2                    ((uint32_t)0x00000010)            /*!< Bit 2 */

#define  ADC_OVSCR_OVSS                      ((uint32_t)0x000001E0)            /*!< OVERSAMPLING_SHIFT[3:0] bits */  
#define  ADC_OVSCR_OVSS_0                    ((uint32_t)0x00000020)            /*!< Bit 0 */
#define  ADC_OVSCR_OVSS_1                    ((uint32_t)0x00000040)            /*!< Bit 1 */
#define  ADC_OVSCR_OVSS_2                    ((uint32_t)0x00000080)            /*!< Bit 2 */
#define  ADC_OVSCR_OVSS_3                    ((uint32_t)0x00000100)            /*!< Bit 3 */

#define  ADC_OVSCR_TOVS                      ((uint32_t)0x00000200)            /*!< TOVS bit */
#endif /* GD32F170_190 */


#ifdef GD32F170_190
/******************************************************************************/
/*                                                                            */
/*                         Controller Area Network                            */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CAN_CTLR register  *******************/
#define  CAN_CTLR_IWM                        ((uint16_t)0x0001)                /*!< Initial working mode */
#define  CAN_CTLR_SWM                        ((uint16_t)0x0002)                /*!< Sleep working mode */
#define  CAN_CTLR_TFO                        ((uint16_t)0x0004)                /*!< Transmit FIFO order */
#define  CAN_CTLR_RFOD                       ((uint16_t)0x0008)                /*!< Receive FIFO overwrite disable */
#define  CAN_CTLR_ARD                        ((uint16_t)0x0010)                /*!< Automatic retransmission disable */
#define  CAN_CTLR_AWK                        ((uint16_t)0x0020)                /*!< Automatic Wakeup */
#define  CAN_CTLR_ABOR                       ((uint16_t)0x0040)                /*!< Automatic Bus-Off recovery */
#define  CAN_CTLR_TTC                        ((uint16_t)0x0080)                /*!< Time Triggered Communication */
#define  CAN_CTLR_SR                         ((uint16_t)0x8000)                /*!< CAN software reset */
#define  CAN_CTLR_DFZ                        ((uint32_t)0x00010000)            /*!< CAN Debug freeze */

/*******************  Bit definition for CAN_STR register  ********************/
#define  CAN_STR_IWS                         ((uint16_t)0x0001)                /*!< Initial working state */
#define  CAN_STR_SWS                         ((uint16_t)0x0002)                /*!< Sleep working state */
#define  CAN_STR_EIF                         ((uint16_t)0x0004)                /*!< Error Interrupt Flag*/
#define  CAN_STR_WIF                         ((uint16_t)0x0008)                /*!< Status change interrupt flag of wakeup from sleep working mode */
#define  CAN_STR_SEIF                        ((uint16_t)0x0010)                /*!< Status change interrupt flag of sleep working mode entering */
#define  CAN_STR_TS                          ((uint16_t)0x0100)                /*!< Transmitting state */
#define  CAN_STR_RS                          ((uint16_t)0x0200)                /*!< Receiving state */
#define  CAN_STR_LASTRX                      ((uint16_t)0x0400)                /*!< Last sample value of Rx pin */
#define  CAN_STR_RX                          ((uint16_t)0x0800)                /*!< CAN Rx Signal */

/*******************  Bit definition for CAN_TSTR register  *******************/
#define  CAN_TSTR_MTF0                       ((uint32_t)0x00000001)            /*!< Mailbox 0 transmit finished */
#define  CAN_TSTR_MTFNE0                     ((uint32_t)0x00000002)            /*!< Mailbox 0 transmit finished and no error */
#define  CAN_TSTR_MAL0                       ((uint32_t)0x00000004)            /*!< Mailbox 0 arbitration lost */
#define  CAN_TSTR_MTE0                       ((uint32_t)0x00000008)            /*!< Mailbox 0 transmit error */
#define  CAN_TSTR_MST0                       ((uint32_t)0x00000080)            /*!< Mailbox 0 stop transmitting */

#define  CAN_TSTR_MTF1                       ((uint32_t)0x00000100)            /*!< Mailbox 1 transmit finished */
#define  CAN_TSTR_MTFNE1                     ((uint32_t)0x00000200)            /*!< Mailbox 1 transmit finished and no error */
#define  CAN_TSTR_MAL1                       ((uint32_t)0x00000400)            /*!< Mailbox 1 arbitration lost */
#define  CAN_TSTR_MTE1                       ((uint32_t)0x00000800)            /*!< Mailbox 1 transmit error */
#define  CAN_TSTR_MST1                       ((uint32_t)0x00008000)            /*!< Mailbox 1 stop transmitting */

#define  CAN_TSTR_MTF2                       ((uint32_t)0x00010000)            /*!< Mailbox 2 transmit finished */
#define  CAN_TSTR_MTFNE2                     ((uint32_t)0x00020000)            /*!< Mailbox 2 transmit finished and no error */
#define  CAN_TSTR_MAL2                       ((uint32_t)0x00040000)            /*!< Mailbox 2 arbitration lost */
#define  CAN_TSTR_MTE2                       ((uint32_t)0x00080000)            /*!< Mailbox 2 transmit error */
#define  CAN_TSTR_MST2                       ((uint32_t)0x00800000)            /*!< Mailbox 2 stop transmitting */

#define  CAN_TSTR_NUM                        ((uint32_t)0x03000000)            /*!< Mailbox number */

#define  CAN_TSTR_TME                        ((uint32_t)0x1C000000)            /*!< TME[2:0] bits */
#define  CAN_TSTR_TME0                       ((uint32_t)0x04000000)            /*!< Transmit mailbox 0 empty */
#define  CAN_TSTR_TME1                       ((uint32_t)0x08000000)            /*!< Transmit mailbox 1 empty */
#define  CAN_TSTR_TME2                       ((uint32_t)0x10000000)            /*!< Transmit mailbox 2 empty */

#define  CAN_TSTR_TMLS                       ((uint32_t)0xE0000000)            /*!< TMLS[2:0] bits */
#define  CAN_TSTR_TMLS0                      ((uint32_t)0x20000000)            /*!< Last sending Priority Flag for Mailbox 0 */
#define  CAN_TSTR_TMLS1                      ((uint32_t)0x40000000)            /*!< Last sending Priority Flag for Mailbox 1 */
#define  CAN_TSTR_TMLS2                      ((uint32_t)0x80000000)            /*!< Last sending Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RFR0 register  *******************/
#define  CAN_RFR0_RFL0                       ((uint8_t)0x03)                   /*!< Receive FIFO 0 length */
#define  CAN_RFR0_RFF0                       ((uint8_t)0x08)                   /*!< Receive FIFO 0 full */
#define  CAN_RFR0_RFO0                       ((uint8_t)0x10)                   /*!< Receive FIFO 0 overfull */
#define  CAN_RFR0_RFD0                       ((uint8_t)0x20)                   /*!< Receive FIFO 0 dequeue */

/*******************  Bit definition for CAN_RFR1 register  *******************/
#define  CAN_RFR1_RFL1                       ((uint8_t)0x03)                   /*!< Receive FIFO 1 length */
#define  CAN_RFR1_RFF1                       ((uint8_t)0x08)                   /*!< Receive FIFO 1 full */
#define  CAN_RFR1_RFO1                       ((uint8_t)0x10)                   /*!< Receive FIFO 1 overfull */
#define  CAN_RFR1_RFD1                       ((uint8_t)0x20)                   /*!< Receive FIFO 1 dequeue */

/********************  Bit definition for CAN_IER register  *******************/
#define  CAN_IER_TMEIE                       ((uint32_t)0x00000001)            /*!< Transmit mailbox empty interrupt enable */
#define  CAN_IER_RFNEIE0                     ((uint32_t)0x00000002)            /*!< Receive FIFO0 not empty interrupt enable */
#define  CAN_IER_RFFIE0                      ((uint32_t)0x00000004)            /*!< Receive FIFO0 full interrupt enable */
#define  CAN_IER_RFOIE0                      ((uint32_t)0x00000008)            /*!< Receive FIFO0 overfull interrupt enable */
#define  CAN_IER_RFNEIE1                     ((uint32_t)0x00000010)            /*!< Receive FIFO1 not empty interrupt enable */
#define  CAN_IER_RFFIE1                      ((uint32_t)0x00000020)            /*!< Receive FIFO1 full interrupt enable */
#define  CAN_IER_RFOIE1                      ((uint32_t)0x00000040)            /*!< Receive FIFO1 overfull interrupt enable */
#define  CAN_IER_WEIE                        ((uint32_t)0x00000100)            /*!< Warning error interrupt enable */
#define  CAN_IER_PEIE                        ((uint32_t)0x00000200)            /*!< Passive error interrupt enable */
#define  CAN_IER_BOIE                        ((uint32_t)0x00000400)            /*!< Bus-off interrupt enable */
#define  CAN_IER_ENIE                        ((uint32_t)0x00000800)            /*!< Error number interrupt enable */
#define  CAN_IER_EIE                         ((uint32_t)0x00008000)            /*!< Error Interrupt enable */
#define  CAN_IER_WIE                         ((uint32_t)0x00010000)            /*!< Wakeup Interrupt enable */
#define  CAN_IER_SWIE                        ((uint32_t)0x00020000)            /*!< Sleep working interrupt enable */

/********************  Bit definition for CAN_ER register  ********************/
#define  CAN_ER_WE                           ((uint32_t)0x00000001)            /*!< Warning error */
#define  CAN_ER_PE                           ((uint32_t)0x00000002)            /*!< Passive error */
#define  CAN_ER_BOE                          ((uint32_t)0x00000004)            /*!< Bus-off error */

#define  CAN_ER_ET                           ((uint32_t)0x00000070)            /*!< ET[2:0] bits (Error type) */
#define  CAN_ER_ET_0                         ((uint32_t)0x00000010)            /*!< Bit 0 */
#define  CAN_ER_ET_1                         ((uint32_t)0x00000020)            /*!< Bit 1 */
#define  CAN_ER_ET_2                         ((uint32_t)0x00000040)            /*!< Bit 2 */

#define  CAN_ER_TEC                          ((uint32_t)0x00FF0000)            /*!< Transmit Error Count */
#define  CAN_ER_REC                          ((uint32_t)0xFF000000)            /*!< Receive Error Count */

/*******************  Bit definition for CAN_BTR register  ********************/
#define  CAN_BTR_BRP                         ((uint32_t)0x000003FF)            /*!< Baud rate prescaler */
#define  CAN_BTR_BS1                         ((uint32_t)0x000F0000)            /*!< Bit Segment 1 */
#define  CAN_BTR_BS2                         ((uint32_t)0x00700000)            /*!< Bit Segment 2 */
#define  CAN_BTR_SJW                         ((uint32_t)0x03000000)            /*!< Resynchronization jump width */
#define  CAN_BTR_LCM                         ((uint32_t)0x40000000)            /*!< Loopback communication mode */
#define  CAN_BTR_SCM                         ((uint32_t)0x80000000)            /*!< Silent communication mode */

/******************  Bit definition for CAN_TMIR0 register  *******************/
#define  CAN_TMIR0_TE                        ((uint32_t)0x00000001)            /*!< Transmit enable */
#define  CAN_TMIR0_FT                        ((uint32_t)0x00000002)            /*!< Frame type */
#define  CAN_TMIR0_FF                        ((uint32_t)0x00000004)            /*!< Frame format */
#define  CAN_TMIR0_EFID                      ((uint32_t)0x001FFFF8)            /*!< The frame identifier */
#define  CAN_TMIR0_SFID                      ((uint32_t)0xFFE00000)            /*!< The frame identifier */

/******************  Bit definition for CAN_TMPR0 register  *******************/
#define  CAN_TMPR0_DLC                       ((uint32_t)0x0000000F)            /*!< Data length code */
#define  CAN_TMPR0_TSE                       ((uint32_t)0x00000100)            /*!< Time stamp enable */
#define  CAN_TMPR0_TS                        ((uint32_t)0xFFFF0000)            /*!< Time stamp */

/******************  Bit definition for CAN_TMD0R0 register  ******************/
#define  CAN_TMD0R0_DB0                      ((uint32_t)0x000000FF)            /*!< Data byte 0 */
#define  CAN_TMD0R0_DB1                      ((uint32_t)0x0000FF00)            /*!< Data byte 1 */
#define  CAN_TMD0R0_DB2                      ((uint32_t)0x00FF0000)            /*!< Data byte 2 */
#define  CAN_TMD0R0_DB3                      ((uint32_t)0xFF000000)            /*!< Data byte 3 */

/******************  Bit for CAN_TMD1R0 register  *****************************/
#define  CAN_TMD1R0_DB4                      ((uint32_t)0x000000FF)            /*!< Data byte 4 */
#define  CAN_TMD1R0_DB5                      ((uint32_t)0x0000FF00)            /*!< Data byte 5 */
#define  CAN_TMD1R0_DB6                      ((uint32_t)0x00FF0000)            /*!< Data byte 6 */
#define  CAN_TMD1R0_DB7                      ((uint32_t)0xFF000000)            /*!< Data byte 7 */

/******************  Bit definition for CAN_TMIR1 register  *******************/
#define  CAN_TMIR1_TE                        ((uint32_t)0x00000001)            /*!< Transmit enable */
#define  CAN_TMIR1_FT                        ((uint32_t)0x00000002)            /*!< Frame type */
#define  CAN_TMIR1_FF                        ((uint32_t)0x00000004)            /*!< Frame format */
#define  CAN_TMIR1_EFID                      ((uint32_t)0x001FFFF8)            /*!< The frame identifier */
#define  CAN_TMIR1_SFID                      ((uint32_t)0xFFE00000)            /*!< The frame identifier */

/******************  Bit definition for CAN_TMPR1 register  *******************/
#define  CAN_TMPR1_DLC                       ((uint32_t)0x0000000F)            /*!< Data length code */
#define  CAN_TMPR1_TSE                       ((uint32_t)0x00000100)            /*!< Time stamp enable */
#define  CAN_TMPR1_TS                        ((uint32_t)0xFFFF0000)            /*!< Time stamp */

/******************  Bit definition for CAN_TMD0R1 register  ******************/
#define  CAN_TMD0R1_DB0                      ((uint32_t)0x000000FF)            /*!< Data byte 0 */
#define  CAN_TMD0R1_DB1                      ((uint32_t)0x0000FF00)            /*!< Data byte 1 */
#define  CAN_TMD0R1_DB2                      ((uint32_t)0x00FF0000)            /*!< Data byte 2 */
#define  CAN_TMD0R1_DB3                      ((uint32_t)0xFF000000)            /*!< Data byte 3 */

/******************  Bit definition for CAN_TMD1R1 register  ******************/
#define  CAN_TMD1R1_DB4                      ((uint32_t)0x000000FF)            /*!< Data byte 4 */
#define  CAN_TMD1R1_DB5                      ((uint32_t)0x0000FF00)            /*!< Data byte 5 */
#define  CAN_TMD1R1_DB6                      ((uint32_t)0x00FF0000)            /*!< Data byte 6 */
#define  CAN_TMD1R1_DB7                      ((uint32_t)0xFF000000)            /*!< Data byte 7 */

/******************  Bit definition for CAN_TMIR2 register  *******************/
#define  CAN_TMIR2_TE                        ((uint32_t)0x00000001)            /*!< Transmit enable */
#define  CAN_TMIR2_FT                        ((uint32_t)0x00000002)            /*!< Frame type */
#define  CAN_TMIR2_FF                        ((uint32_t)0x00000004)            /*!< Frame format */
#define  CAN_TMIR2_EFID                      ((uint32_t)0x001FFFF8)            /*!< The frame identifier */
#define  CAN_TMIR2_SFID                      ((uint32_t)0xFFE00000)            /*!< The frame identifier */

/******************  Bit definition for CAN_TMPR2 register  *******************/
#define  CAN_TMPR2_DLC                       ((uint32_t)0x0000000F)            /*!< Data length code */
#define  CAN_TMPR2_TSE                       ((uint32_t)0x00000100)            /*!< Time stamp enable */
#define  CAN_TMPR2_TS                        ((uint32_t)0xFFFF0000)            /*!< Time stamp */

/******************  Bit definition for CAN_TMD0R2 register  ******************/
#define  CAN_TMD0R2_DB0                      ((uint32_t)0x000000FF)            /*!< Data byte 0 */
#define  CAN_TMD0R2_DB1                      ((uint32_t)0x0000FF00)            /*!< Data byte 1 */
#define  CAN_TMD0R2_DB2                      ((uint32_t)0x00FF0000)            /*!< Data byte 2 */
#define  CAN_TMD0R2_DB3                      ((uint32_t)0xFF000000)            /*!< Data byte 3 */

/******************  Bit definition for CAN_TMD1R2 register  ******************/
#define  CAN_TMD1R2_DB4                      ((uint32_t)0x000000FF)            /*!< Data byte 4 */
#define  CAN_TMD1R2_DB5                      ((uint32_t)0x0000FF00)            /*!< Data byte 5 */
#define  CAN_TMD1R2_DB6                      ((uint32_t)0x00FF0000)            /*!< Data byte 6 */
#define  CAN_TMD1R2_DB7                      ((uint32_t)0xFF000000)            /*!< Data byte 7 */

/******************  Bit definition for CAN_RFMIR0 register  ******************/
#define  CAN_RFMIR0_FT                       ((uint32_t)0x00000002)            /*!< Frame type */
#define  CAN_RFMIR0_FF                       ((uint32_t)0x00000004)            /*!< Frame format */
#define  CAN_RFMIR0_EFID                     ((uint32_t)0x001FFFF8)            /*!< The frame identifier */
#define  CAN_RFMIR0_SFID                     ((uint32_t)0xFFE00000)            /*!< The frame identifier */

/******************  Bit definition for CAN_RFMPR0 register  ******************/
#define  CAN_RFMPR0_DLC                      ((uint32_t)0x0000000F)            /*!< Data length code */
#define  CAN_RFMPR0_TSE                      ((uint32_t)0x00000100)            /*!< Time stamp enable */
#define  CAN_RFMPR0_TS                       ((uint32_t)0xFFFF0000)            /*!< Time stamp */

/******************  Bit definition for CAN_RFMD0R0 register  *****************/
#define  CAN_RFMD0R0_DB0                     ((uint32_t)0x000000FF)            /*!< Data byte 0 */
#define  CAN_RFMD0R0_DB1                     ((uint32_t)0x0000FF00)            /*!< Data byte 1 */
#define  CAN_RFMD0R0_DB2                     ((uint32_t)0x00FF0000)            /*!< Data byte 2 */
#define  CAN_RFMD0R0_DB3                     ((uint32_t)0xFF000000)            /*!< Data byte 3 */

/******************  Bit definition for CAN_RFMD1R0 register  *****************/
#define  CAN_RFMD1R0_DB4                     ((uint32_t)0x000000FF)            /*!< Data byte 4 */
#define  CAN_RFMD1R0_DB5                     ((uint32_t)0x0000FF00)            /*!< Data byte 5 */
#define  CAN_RFMD1R0_DB6                     ((uint32_t)0x00FF0000)            /*!< Data byte 6 */
#define  CAN_RFMD1R0_DB7                     ((uint32_t)0xFF000000)            /*!< Data byte 7 */

/******************  Bit definition for CAN_RFMIR1 register  ******************/
#define  CAN_RFMIR1_FT                       ((uint32_t)0x00000002)            /*!< Frame type */
#define  CAN_RFMIR1_FF                       ((uint32_t)0x00000004)            /*!< Frame format */
#define  CAN_RFMIR1_EFID                     ((uint32_t)0x001FFFF8)            /*!< The frame identifier */
#define  CAN_RFMIR1_SFID                     ((uint32_t)0xFFE00000)            /*!< The frame identifier */

/******************  Bit definition for CAN_RFMPR1 register  ******************/
#define  CAN_RFMPR1_DLC                      ((uint32_t)0x0000000F)            /*!< Data length code */
#define  CAN_RFMPR1_TSE                      ((uint32_t)0x00000100)            /*!< Time stamp enable */
#define  CAN_RFMPR1_TS                       ((uint32_t)0xFFFF0000)            /*!< Time stamp */

/******************  Bit definition for CAN_RFMD0R1 register  *****************/
#define  CAN_RFMD0R1_DB0                     ((uint32_t)0x000000FF)            /*!< Data byte 0 */
#define  CAN_RFMD0R1_DB1                     ((uint32_t)0x0000FF00)            /*!< Data byte 1 */
#define  CAN_RFMD0R1_DB2                     ((uint32_t)0x00FF0000)            /*!< Data byte 2 */
#define  CAN_RFMD0R1_DB3                     ((uint32_t)0xFF000000)            /*!< Data byte 3 */

/******************  Bit definition for CAN_RFMD1R1 register  *****************/
#define  CAN_RFMD1R1_DB4                     ((uint32_t)0x000000FF)            /*!< Data byte 4 */
#define  CAN_RFMD1R1_DB5                     ((uint32_t)0x0000FF00)            /*!< Data byte 5 */
#define  CAN_RFMD1R1_DB6                     ((uint32_t)0x00FF0000)            /*!< Data byte 6 */
#define  CAN_RFMD1R1_DB7                     ((uint32_t)0xFF000000)            /*!< Data byte 7 */

/*!< CAN filter registers */
/*******************  Bit definition for CAN_FCTLR register  ******************/
#define  CAN_FCTLR_FLD                       ((uint8_t)0x00000001)             /*!< Filter lock disable */
#define  CAN_FCTLR_HBC2F                     ((uint32_t)0x003F0000)            /*!< Header bank of CAN2 filter */

/*******************  Bit definition for CAN_FMR register  ********************/
#define  CAN_FMR_FM                          ((uint32_t)0x0FFFFFFF)            /*!< Filter Mode */
#define  CAN_FMR_FM0                         ((uint32_t)0x00000001)            /*!< Filter Init Mode bit 0 */
#define  CAN_FMR_FM1                         ((uint32_t)0x00000002)            /*!< Filter Init Mode bit 1 */
#define  CAN_FMR_FM2                         ((uint32_t)0x00000004)            /*!< Filter Init Mode bit 2 */
#define  CAN_FMR_FM3                         ((uint32_t)0x00000008)            /*!< Filter Init Mode bit 3 */
#define  CAN_FMR_FM4                         ((uint32_t)0x00000010)            /*!< Filter Init Mode bit 4 */
#define  CAN_FMR_FM5                         ((uint32_t)0x00000020)            /*!< Filter Init Mode bit 5 */
#define  CAN_FMR_FM6                         ((uint32_t)0x00000040)            /*!< Filter Init Mode bit 6 */
#define  CAN_FMR_FM7                         ((uint32_t)0x00000080)            /*!< Filter Init Mode bit 7 */
#define  CAN_FMR_FM8                         ((uint32_t)0x00000100)            /*!< Filter Init Mode bit 8 */
#define  CAN_FMR_FM9                         ((uint32_t)0x00000200)            /*!< Filter Init Mode bit 9 */
#define  CAN_FMR_FM10                        ((uint32_t)0x00000400)            /*!< Filter Init Mode bit 10 */
#define  CAN_FMR_FM11                        ((uint32_t)0x00000800)            /*!< Filter Init Mode bit 11 */
#define  CAN_FMR_FM12                        ((uint32_t)0x00001000)            /*!< Filter Init Mode bit 12 */
#define  CAN_FMR_FM13                        ((uint32_t)0x00002000)            /*!< Filter Init Mode bit 13 */
#define  CAN_FMR_FM14                        ((uint32_t)0x00004000)            /*!< Filter Init Mode bit 14 */
#define  CAN_FMR_FM15                        ((uint32_t)0x00008000)            /*!< Filter Init Mode bit 15 */
#define  CAN_FMR_FM16                        ((uint32_t)0x00010000)            /*!< Filter Init Mode bit 16 */
#define  CAN_FMR_FM17                        ((uint32_t)0x00020000)            /*!< Filter Init Mode bit 17 */
#define  CAN_FMR_FM18                        ((uint32_t)0x00040000)            /*!< Filter Init Mode bit 18 */
#define  CAN_FMR_FM19                        ((uint32_t)0x00080000)            /*!< Filter Init Mode bit 19 */
#define  CAN_FMR_FM20                        ((uint32_t)0x00100000)            /*!< Filter Init Mode bit 20 */
#define  CAN_FMR_FM21                        ((uint32_t)0x00200000)            /*!< Filter Init Mode bit 21 */
#define  CAN_FMR_FM22                        ((uint32_t)0x00400000)            /*!< Filter Init Mode bit 22 */
#define  CAN_FMR_FM23                        ((uint32_t)0x00800000)            /*!< Filter Init Mode bit 23 */
#define  CAN_FMR_FM24                        ((uint32_t)0x01000000)            /*!< Filter Init Mode bit 24 */
#define  CAN_FMR_FM25                        ((uint32_t)0x02000000)            /*!< Filter Init Mode bit 25 */
#define  CAN_FMR_FM26                        ((uint32_t)0x04000000)            /*!< Filter Init Mode bit 26 */
#define  CAN_FMR_FM27                        ((uint32_t)0x08000000)            /*!< Filter Init Mode bit 27 */

/*******************  Bit definition for CAN_FSR register  ********************/
#define  CAN_FSR_FS                          ((uint32_t)0x0FFFFFFF)            /*!< Filter Scale */
#define  CAN_FSR_FS0                         ((uint32_t)0x00000001)            /*!< Filter Scale bit 0 */
#define  CAN_FSR_FS1                         ((uint32_t)0x00000002)            /*!< Filter Scale bit 1 */
#define  CAN_FSR_FS2                         ((uint32_t)0x00000004)            /*!< Filter Scale bit 2 */
#define  CAN_FSR_FS3                         ((uint32_t)0x00000008)            /*!< Filter Scale bit 3 */
#define  CAN_FSR_FS4                         ((uint32_t)0x00000010)            /*!< Filter Scale bit 4 */
#define  CAN_FSR_FS5                         ((uint32_t)0x00000020)            /*!< Filter Scale bit 5 */
#define  CAN_FSR_FS6                         ((uint32_t)0x00000040)            /*!< Filter Scale bit 6 */
#define  CAN_FSR_FS7                         ((uint32_t)0x00000080)            /*!< Filter Scale bit 7 */
#define  CAN_FSR_FS8                         ((uint32_t)0x00000100)            /*!< Filter Scale bit 8 */
#define  CAN_FSR_FS9                         ((uint32_t)0x00000200)            /*!< Filter Scale bit 9 */
#define  CAN_FSR_FS10                        ((uint32_t)0x00000400)            /*!< Filter Scale bit 10 */
#define  CAN_FSR_FS11                        ((uint32_t)0x00000800)            /*!< Filter Scale bit 11 */
#define  CAN_FSR_FS12                        ((uint32_t)0x00001000)            /*!< Filter Scale bit 12 */
#define  CAN_FSR_FS13                        ((uint32_t)0x00002000)            /*!< Filter Scale bit 13 */
#define  CAN_FSR_FS14                        ((uint32_t)0x00004000)            /*!< Filter Scale bit 14 */
#define  CAN_FSR_FS15                        ((uint32_t)0x00008000)            /*!< Filter Scale bit 15 */
#define  CAN_FSR_FS16                        ((uint32_t)0x00010000)            /*!< Filter Scale bit 16 */
#define  CAN_FSR_FS17                        ((uint32_t)0x00020000)            /*!< Filter Scale bit 17 */
#define  CAN_FSR_FS18                        ((uint32_t)0x00040000)            /*!< Filter Scale bit 18 */
#define  CAN_FSR_FS19                        ((uint32_t)0x00080000)            /*!< Filter Scale bit 19 */
#define  CAN_FSR_FS20                        ((uint32_t)0x00100000)            /*!< Filter Scale bit 20 */
#define  CAN_FSR_FS21                        ((uint32_t)0x00200000)            /*!< Filter Scale bit 21 */
#define  CAN_FSR_FS22                        ((uint32_t)0x00400000)            /*!< Filter Scale bit 22 */
#define  CAN_FSR_FS23                        ((uint32_t)0x00800000)            /*!< Filter Scale bit 23*/
#define  CAN_FSR_FS24                        ((uint32_t)0x01000000)            /*!< Filter Scale bit 24 */
#define  CAN_FSR_FS25                        ((uint32_t)0x02000000)            /*!< Filter Scale bit 25 */
#define  CAN_FSR_FS26                        ((uint32_t)0x04000000)            /*!< Filter Scale bit 26 */
#define  CAN_FSR_FS27                        ((uint32_t)0x08000000)            /*!< Filter Scale bit 27 */

/******************  Bit definition for CAN_FAFR register  ********************/
#define  CAN_FAFR_FAF                        ((uint32_t)0x0FFFFFFF)            /*!< Filter associated with FIFO */
#define  CAN_FAFR_FAF0                       ((uint32_t)0x00000001)            /*!< Filter 0 associated with FIFO */
#define  CAN_FAFR_FAF1                       ((uint32_t)0x00000002)            /*!< Filter 1 associated with FIFO */
#define  CAN_FAFR_FAF2                       ((uint32_t)0x00000004)            /*!< Filter 2 associated with FIFO */
#define  CAN_FAFR_FAF3                       ((uint32_t)0x00000008)            /*!< Filter 3 associated with FIFO */
#define  CAN_FAFR_FAF4                       ((uint32_t)0x00000010)            /*!< Filter 4 associated with FIFO */
#define  CAN_FAFR_FAF5                       ((uint32_t)0x00000020)            /*!< Filter 5 associated with FIFO */
#define  CAN_FAFR_FAF6                       ((uint32_t)0x00000040)            /*!< Filter 6 associated with FIFO */
#define  CAN_FAFR_FAF7                       ((uint32_t)0x00000080)            /*!< Filter 7 associated with FIFO */
#define  CAN_FAFR_FAF8                       ((uint32_t)0x00000100)            /*!< Filter 8 associated with FIFO */
#define  CAN_FAFR_FAF9                       ((uint32_t)0x00000200)            /*!< Filter 9 associated with FIFO */
#define  CAN_FAFR_FAF10                      ((uint32_t)0x00000400)            /*!< Filter 10 associated with FIFO */
#define  CAN_FAFR_FAF11                      ((uint32_t)0x00000800)            /*!< Filter 11 associated with FIFO */
#define  CAN_FAFR_FAF12                      ((uint32_t)0x00001000)            /*!< Filter 12 associated with FIFO */
#define  CAN_FAFR_FAF13                      ((uint32_t)0x00002000)            /*!< Filter 13 associated with FIFO */
#define  CAN_FAFR_FAF14                      ((uint32_t)0x00004000)            /*!< Filter 14 associated with FIFO */
#define  CAN_FAFR_FAF15                      ((uint32_t)0x00008000)            /*!< Filter 15 associated with FIFO */
#define  CAN_FAFR_FAF16                      ((uint32_t)0x00010000)            /*!< Filter 16 associated with FIFO */
#define  CAN_FAFR_FAF17                      ((uint32_t)0x00020000)            /*!< Filter 17 associated with FIFO */
#define  CAN_FAFR_FAF18                      ((uint32_t)0x00040000)            /*!< Filter 18 associated with FIFO */
#define  CAN_FAFR_FAF19                      ((uint32_t)0x00080000)            /*!< Filter 19 associated with FIFO */
#define  CAN_FAFR_FAF20                      ((uint32_t)0x00100000)            /*!< Filter 20 associated with FIFO */
#define  CAN_FAFR_FAF21                      ((uint32_t)0x00200000)            /*!< Filter 21 associated with FIFO */
#define  CAN_FAFR_FAF22                      ((uint32_t)0x00400000)            /*!< Filter 22 associated with FIFO */
#define  CAN_FAFR_FAF23                      ((uint32_t)0x00800000)            /*!< Filter 23 associated with FIFO */
#define  CAN_FAFR_FAF24                      ((uint32_t)0x01000000)            /*!< Filter 24 associated with FIFO */
#define  CAN_FAFR_FAF25                      ((uint32_t)0x02000000)            /*!< Filter 25 associated with FIFO */
#define  CAN_FAFR_FAF26                      ((uint32_t)0x04000000)            /*!< Filter 26 associated with FIFO */
#define  CAN_FAFR_FAF27                      ((uint32_t)0x08000000)            /*!< Filter 27 associated with FIFO */

/*******************  Bit definition for CAN_FWR register  ********************/
#define  CAN_FWR_FW                          ((uint32_t)0x0FFFFFFF)            /*!< Filter working */
#define  CAN_FWR_FW0                         ((uint32_t)0x00000001)            /*!< Filter 0 working */
#define  CAN_FWR_FW1                         ((uint32_t)0x00000002)            /*!< Filter 1 working */
#define  CAN_FWR_FW2                         ((uint32_t)0x00000004)            /*!< Filter 2 working */
#define  CAN_FWR_FW3                         ((uint32_t)0x00000008)            /*!< Filter 3 working */
#define  CAN_FWR_FW4                         ((uint32_t)0x00000010)            /*!< Filter 4 working */
#define  CAN_FWR_FW5                         ((uint32_t)0x00000020)            /*!< Filter 5 working */
#define  CAN_FWR_FW6                         ((uint32_t)0x00000040)            /*!< Filter 6 working */
#define  CAN_FWR_FW7                         ((uint32_t)0x00000080)            /*!< Filter 7 working */
#define  CAN_FWR_FW8                         ((uint32_t)0x00000100)            /*!< Filter 8 working */
#define  CAN_FWR_FW9                         ((uint32_t)0x00000200)            /*!< Filter 9 working */
#define  CAN_FWR_FW10                        ((uint32_t)0x00000400)            /*!< Filter 10 working */
#define  CAN_FWR_FW11                        ((uint32_t)0x00000800)            /*!< Filter 11 working */
#define  CAN_FWR_FW12                        ((uint32_t)0x00001000)            /*!< Filter 12 working */
#define  CAN_FWR_FW13                        ((uint32_t)0x00002000)            /*!< Filter 13 working */
#define  CAN_FWR_FW14                        ((uint32_t)0x00004000)            /*!< Filter 14 working */
#define  CAN_FWR_FW15                        ((uint32_t)0x00008000)            /*!< Filter 15 working */
#define  CAN_FWR_FW16                        ((uint32_t)0x00010000)            /*!< Filter 16 working */
#define  CAN_FWR_FW17                        ((uint32_t)0x00020000)            /*!< Filter 17 working */
#define  CAN_FWR_FW18                        ((uint32_t)0x00040000)            /*!< Filter 18 working */
#define  CAN_FWR_FW19                        ((uint32_t)0x00080000)            /*!< Filter 19 working */
#define  CAN_FWR_FW20                        ((uint32_t)0x00100000)            /*!< Filter 20 working */
#define  CAN_FWR_FW21                        ((uint32_t)0x00200000)            /*!< Filter 21 working */
#define  CAN_FWR_FW22                        ((uint32_t)0x00400000)            /*!< Filter 22 working */
#define  CAN_FWR_FW23                        ((uint32_t)0x00800000)            /*!< Filter 23 working */
#define  CAN_FWR_FW24                        ((uint32_t)0x01000000)            /*!< Filter 24 working */
#define  CAN_FWR_FW25                        ((uint32_t)0x02000000)            /*!< Filter 25 working */
#define  CAN_FWR_FW26                        ((uint32_t)0x04000000)            /*!< Filter 26 working */
#define  CAN_FWR_FW27                        ((uint32_t)0x08000000)            /*!< Filter 27 working */

/*******************  Bit definition for CAN_F0D0R register  ******************/
#define  CAN_F0D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F0D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F0D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F0D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F0D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F0D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F0D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F0D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F0D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F0D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F0D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F0D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F0D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F0D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F0D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F0D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F0D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F0D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F0D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F0D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F0D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F0D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F0D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F0D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F0D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F0D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F0D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F0D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F0D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F0D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F0D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F0D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F1D0R register  ******************/
#define  CAN_F1D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F1D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F1D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F1D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F1D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F1D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F1D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F1D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F1D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F1D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F1D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F1D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F1D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F1D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F1D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F1D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F1D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F1D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F1D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F1D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F1D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F1D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F1D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F1D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F1D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F1D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F1D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F1D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F1D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F1D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F1D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F1D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F2D0R register  ******************/
#define  CAN_F2D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F2D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F2D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F2D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F2D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F2D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F2D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F2D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F2D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F2D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F2D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F2D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F2D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F2D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F2D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F2D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F2D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F2D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F2D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F2D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F2D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F2D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F2D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F2D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F2D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F2D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F2D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F2D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F2D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F2D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F2D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F2D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F3D0R register  ******************/
#define  CAN_F3D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F3D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F3D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F3D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F3D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F3D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F3D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F3D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F3D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F3D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F3D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F3D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F3D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F3D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F3D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F3D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F3D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F3D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F3D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F3D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F3D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F3D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F3D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F3D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F3D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F3D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F3D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F3D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F3D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F3D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F3D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F3D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F4D0R register  ******************/
#define  CAN_F4D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F4D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F4D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F4D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F4D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F4D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F4D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F4D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F4D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F4D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F4D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F4D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F4D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F4D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F4D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F4D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F4D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F4D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F4D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F4D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F4D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F4D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F4D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F4D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F4D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F4D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F4D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F4D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F4D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F4D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F4D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F4D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F5D0R register  ******************/
#define  CAN_F5D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F5D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F5D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F5D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F5D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F5D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F5D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F5D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F5D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F5D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F5D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F5D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F5D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F5D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F5D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F5D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F5D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F5D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F5D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F5D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F5D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F5D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F5D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F5D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F5D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F5D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F5D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F5D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F5D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F5D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F5D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F5D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F6D0R register  ******************/
#define  CAN_F6D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F6D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F6D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F6D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F6D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F6D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F6D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F6D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F6D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F6D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F6D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F6D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F6D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F6D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F6D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F6D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F6D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F6D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F6D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F6D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F6D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F6D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F6D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F6D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F6D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F6D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F6D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F6D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F6D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F6D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F6D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F6D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F7D0R register  ******************/
#define  CAN_F7D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F7D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F7D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F7D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F7D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F7D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F7D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F7D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F7D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F7D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F7D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F7D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F7D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F7D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F7D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F7D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F7D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F7D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F7D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F7D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F7D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F7D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F7D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F7D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F7D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F7D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F7D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F7D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F7D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F7D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F7D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F7D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F8D0R register  ******************/
#define  CAN_F8D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F8D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F8D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F8D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F8D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F8D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F8D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F8D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F8D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F8D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F8D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F8D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F8D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F8D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F8D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F8D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F8D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F8D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F8D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F8D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F8D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F8D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F8D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F8D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F8D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F8D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F8D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F8D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F8D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F8D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F8D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F8D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F9D0R register  ******************/
#define  CAN_F9D0R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F9D0R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F9D0R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F9D0R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F9D0R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F9D0R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F9D0R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F9D0R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F9D0R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F9D0R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F9D0R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F9D0R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F9D0R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F9D0R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F9D0R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F9D0R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F9D0R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F9D0R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F9D0R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F9D0R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F9D0R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F9D0R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F9D0R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F9D0R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F9D0R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F9D0R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F9D0R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F9D0R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F9D0R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F9D0R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F9D0R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F9D0R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F10D0R register  *****************/
#define  CAN_F10D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F10D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F10D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F10D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F10D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F10D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F10D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F10D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F10D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F10D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F10D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F10D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F10D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F10D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F10D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F10D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F10D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F10D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F10D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F10D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F10D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F10D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F10D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F10D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F10D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F10D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F10D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F10D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F10D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F10D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F10D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F10D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F11D0R register  *****************/
#define  CAN_F11D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F11D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F11D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F11D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F11D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F11D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F11D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F11D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F11D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F11D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F11D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F11D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F11D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F11D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F11D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F11D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F11D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F11D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F11D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F11D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F11D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F11D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F11D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F11D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F11D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F11D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F11D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F11D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F11D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F11D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F11D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F11D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F12D0R register  *****************/
#define  CAN_F12D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F12D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F12D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F12D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F12D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F12D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F12D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F12D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F12D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F12D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F12D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F12D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F12D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F12D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F12D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F12D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F12D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F12D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F12D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F12D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F12D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F12D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F12D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F12D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F12D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F12D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F12D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F12D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F12D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F12D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F12D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F12D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F13D0R register  *****************/
#define  CAN_F13D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F13D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F13D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F13D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F13D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F13D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F13D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F13D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F13D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F13D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F13D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F13D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F13D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F13D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F13D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F13D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F13D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F13D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F13D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F13D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F13D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F13D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F13D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F13D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F13D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F13D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F13D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F13D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F13D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F13D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F13D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F13D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F14D0R register  *****************/
#define  CAN_F14D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F14D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F14D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F14D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F14D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F14D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F14D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F14D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F14D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F14D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F14D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F14D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F14D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F14D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F14D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F14D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F14D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F14D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F14D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F14D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F14D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F14D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F14D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F14D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F14D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F14D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F14D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F14D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F14D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F14D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F14D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F14D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F15D0R register  *****************/
#define  CAN_F15D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F15D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F15D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F15D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F15D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F15D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F15D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F15D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F15D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F15D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F15D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F15D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F15D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F15D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F15D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F15D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F15D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F15D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F15D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F15D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F15D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F15D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F15D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F15D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F15D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F15D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F15D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F15D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F15D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F15D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F15D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F15D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F16D0R register  *****************/
#define  CAN_F16D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F16D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F16D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F16D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F16D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F16D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F16D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F16D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F16D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F16D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F16D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F16D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F16D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F16D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F16D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F16D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F16D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F16D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F16D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F16D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F16D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F16D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F16D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F16D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F16D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F16D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F16D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F16D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F16D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F16D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F16D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F16D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F17D0R register  *****************/
#define  CAN_F17D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F17D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F17D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F17D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F17D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F17D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F17D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F17D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F17D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F17D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F17D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F17D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F17D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F17D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F17D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F17D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F17D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F17D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F17D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F17D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F17D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F17D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F17D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F17D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F17D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F17D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F17D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F17D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F17D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F17D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F17D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F17D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F18D0R register  *****************/
#define  CAN_F18D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F18D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F18D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F18D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F18D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F18D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F18D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F18D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F18D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F18D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F18D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F18D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F18D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F18D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F18D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F18D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F18D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F18D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F18D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F18D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F18D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F18D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F18D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F18D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F18D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F18D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F18D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F18D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F18D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F18D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F18D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F18D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F19D0R register  *****************/
#define  CAN_F19D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F19D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F19D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F19D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F19D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F19D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F19D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F19D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F19D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F19D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F19D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F19D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F19D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F19D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F19D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F19D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F19D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F19D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F19D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F19D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F19D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F19D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F19D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F19D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F19D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F19D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F19D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F19D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F19D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F19D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F19D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F19D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F20D0R register  *****************/
#define  CAN_F20D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F20D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F20D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F20D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F20D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F20D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F20D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F20D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F20D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F20D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F20D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F20D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F20D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F20D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F20D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F20D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F20D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F20D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F20D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F20D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F20D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F20D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F20D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F20D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F20D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F20D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F20D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F20D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F20D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F20D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F20D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F20D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F21D0R register  *****************/
#define  CAN_F21D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F21D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F21D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F21D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F21D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F21D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F21D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F21D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F21D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F21D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F21D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F21D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F21D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F21D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F21D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F21D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F21D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F21D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F21D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F21D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F21D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F21D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F21D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F21D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F21D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F21D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F21D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F21D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F21D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F21D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F21D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F21D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F22D0R register  *****************/
#define  CAN_F22D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F22D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F22D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F22D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F22D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F22D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F22D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F22D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F22D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F22D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F22D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F22D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F22D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F22D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F22D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F22D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F22D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F22D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F22D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F22D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F22D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F22D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F22D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F22D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F22D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F22D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F22D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F22D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F22D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F22D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F22D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F22D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F23D0R register  *****************/
#define  CAN_F23D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F23D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F23D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F23D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F23D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F23D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F23D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F23D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F23D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F23D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F23D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F23D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F23D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F23D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F23D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F23D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F23D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F23D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F23D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F23D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F23D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F23D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F23D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F23D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F23D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F23D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F23D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F23D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F23D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F23D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F23D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F23D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F24D0R register  *****************/
#define  CAN_F24D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F24D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F24D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F24D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F24D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F24D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F24D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F24D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F24D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F24D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F24D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F24D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F24D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F24D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F24D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F24D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F24D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F24D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F24D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F24D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F24D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F24D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F24D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F24D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F24D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F24D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F24D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F24D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F24D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F24D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F24D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F24D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F25D0R register  *****************/
#define  CAN_F25D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F25D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F25D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F25D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F25D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F25D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F25D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F25D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F25D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F25D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F25D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F25D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F25D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F25D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F25D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F25D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F25D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F25D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F25D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F25D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F25D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F25D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F25D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F25D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F25D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F25D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F25D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F25D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F25D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F25D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F25D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F25D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F26D0R register  *****************/
#define  CAN_F26D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F26D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F26D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F26D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F26D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F26D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F26D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F26D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F26D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F26D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F26D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F26D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F26D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F26D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F26D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F26D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F26D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F26D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F26D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F26D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F26D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F26D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F26D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F26D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F26D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F26D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F26D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F26D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F26D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F26D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F26D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F26D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F27D0R register  *****************/
#define  CAN_F27D0R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F27D0R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F27D0R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F27D0R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F27D0R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F27D0R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F27D0R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F27D0R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F27D0R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F27D0R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F27D0R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F27D0R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F27D0R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F27D0R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F27D0R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F27D0R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F27D0R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F27D0R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F27D0R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F27D0R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F27D0R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F27D0R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F27D0R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F27D0R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F27D0R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F27D0R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F27D0R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F27D0R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F27D0R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F27D0R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F27D0R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F27D0R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F0D1R register  ******************/
#define  CAN_F0D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F0D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F0D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F0D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F0D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F0D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F0D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F0D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F0D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F0D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F0D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F0D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F0D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F0D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F0D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F0D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F0D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F0D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F0D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F0D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F0D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F0D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F0D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F0D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F0D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F0D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F0D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F0D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F0D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F0D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F0D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F0D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F1D1R register  ******************/
#define  CAN_F1D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F1D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F1D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F1D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F1D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F1D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F1D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F1D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F1D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F1D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F1D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F1D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F1D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F1D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F1D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F1D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F1D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F1D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F1D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F1D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F1D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F1D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F1D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F1D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F1D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F1D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F1D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F1D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F1D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F1D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F1D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F1D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F2D1R register  ******************/
#define  CAN_F2D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F2D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F2D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F2D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F2D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F2D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F2D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F2D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F2D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F2D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F2D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F2D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F2D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F2D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F2D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F2D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F2D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F2D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F2D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F2D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F2D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F2D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F2D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F2D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F2D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F2D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F2D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F2D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F2D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F2D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F2D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F2D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F3D1R register  ******************/
#define  CAN_F3D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F3D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F3D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F3D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F3D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F3D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F3D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F3D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F3D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F3D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F3D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F3D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F3D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F3D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F3D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F3D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F3D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F3D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F3D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F3D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F3D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F3D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F3D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F3D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F3D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F3D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F3D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F3D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F3D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F3D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F3D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F3D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F4D1R register  ******************/
#define  CAN_F4D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F4D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F4D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F4D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F4D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F4D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F4D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F4D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F4D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F4D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F4D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F4D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F4D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F4D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F4D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F4D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F4D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F4D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F4D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F4D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F4D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F4D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F4D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F4D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F4D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F4D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F4D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F4D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F4D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F4D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F4D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F4D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F5D1R register  ******************/
#define  CAN_F5D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F5D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F5D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F5D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F5D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F5D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F5D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F5D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F5D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F5D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F5D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F5D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F5D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F5D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F5D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F5D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F5D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F5D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F5D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F5D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F5D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F5D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F5D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F5D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F5D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F5D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F5D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F5D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F5D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F5D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F5D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F5D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F6D1R register  ******************/
#define  CAN_F6D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F6D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F6D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F6D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F6D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F6D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F6D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F6D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F6D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F6D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F6D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F6D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F6D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F6D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F6D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F6D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F6D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F6D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F6D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F6D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F6D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F6D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F6D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F6D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F6D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F6D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F6D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F6D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F6D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F6D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F6D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F6D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F7D1R register  ******************/
#define  CAN_F7D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F7D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F7D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F7D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F7D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F7D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F7D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F7D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F7D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F7D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F7D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F7D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F7D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F7D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F7D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F7D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F7D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F7D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F7D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F7D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F7D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F7D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F7D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F7D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F7D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F7D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F7D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F7D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F7D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F7D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F7D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F7D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F8D1R register  ******************/
#define  CAN_F8D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F8D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F8D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F8D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F8D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F8D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F8D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F8D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F8D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F8D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F8D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F8D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F8D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F8D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F8D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F8D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F8D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F8D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F8D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F8D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F8D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F8D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F8D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F8D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F8D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F8D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F8D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F8D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F8D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F8D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F8D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F8D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F9D1R register  ******************/
#define  CAN_F9D1R_FD0                       ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F9D1R_FD1                       ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F9D1R_FD2                       ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F9D1R_FD3                       ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F9D1R_FD4                       ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F9D1R_FD5                       ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F9D1R_FD6                       ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F9D1R_FD7                       ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F9D1R_FD8                       ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F9D1R_FD9                       ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F9D1R_FD10                      ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F9D1R_FD11                      ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F9D1R_FD12                      ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F9D1R_FD13                      ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F9D1R_FD14                      ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F9D1R_FD15                      ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F9D1R_FD16                      ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F9D1R_FD17                      ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F9D1R_FD18                      ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F9D1R_FD19                      ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F9D1R_FD20                      ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F9D1R_FD21                      ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F9D1R_FD22                      ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F9D1R_FD23                      ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F9D1R_FD24                      ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F9D1R_FD25                      ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F9D1R_FD26                      ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F9D1R_FD27                      ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F9D1R_FD28                      ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F9D1R_FD29                      ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F9D1R_FD30                      ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F9D1R_FD31                      ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F10D1R register  *****************/
#define  CAN_F10D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F10D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F10D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F10D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F10D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F10D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F10D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F10D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F10D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F10D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F10D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F10D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F10D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F10D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F10D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F10D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F10D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F10D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F10D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F10D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F10D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F10D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F10D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F10D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F10D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F10D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F10D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F10D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F10D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F10D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F10D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F10D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F11D1R register  *****************/
#define  CAN_F11D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F11D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F11D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F11D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F11D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F11D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F11D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F11D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F11D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F11D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F11D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F11D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F11D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F11D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F11D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F11D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F11D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F11D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F11D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F11D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F11D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F11D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F11D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F11D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F11D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F11D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F11D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F11D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F11D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F11D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F11D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F11D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F12D1R register  *****************/
#define  CAN_F12D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F12D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F12D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F12D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F12D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F12D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F12D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F12D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F12D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F12D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F12D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F12D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F12D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F12D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F12D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F12D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F12D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F12D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F12D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F12D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F12D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F12D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F12D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F12D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F12D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F12D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F12D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F12D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F12D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F12D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F12D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F12D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F13D1R register  *****************/
#define  CAN_F13D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F13D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F13D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F13D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F13D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F13D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F13D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F13D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F13D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F13D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F13D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F13D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F13D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F13D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F13D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F13D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F13D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F13D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F13D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F13D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F13D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F13D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F13D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F13D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F13D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F13D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F13D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F13D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F13D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F13D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F13D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F13D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F14D1R register  *****************/
#define  CAN_F14D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F14D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F14D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F14D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F14D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F14D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F14D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F14D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F14D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F14D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F14D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F14D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F14D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F14D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F14D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F14D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F14D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F14D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F14D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F14D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F14D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F14D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F14D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F14D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F14D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F14D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F14D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F14D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F14D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F14D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F14D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F14D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F15D1R register  *****************/
#define  CAN_F15D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F15D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F15D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F15D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F15D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F15D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F15D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F15D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F15D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F15D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F15D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F15D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F15D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F15D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F15D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F15D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F15D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F15D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F15D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F15D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F15D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F15D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F15D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F15D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F15D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F15D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F15D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F15D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F15D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F15D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F15D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F15D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F16D1R register  *****************/
#define  CAN_F16D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F16D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F16D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F16D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F16D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F16D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F16D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F16D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F16D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F16D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F16D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F16D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F16D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F16D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F16D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F16D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F16D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F16D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F16D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F16D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F16D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F16D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F16D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F16D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F16D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F16D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F16D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F16D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F16D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F16D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F16D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F16D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F17D1R register  *****************/
#define  CAN_F17D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F17D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F17D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F17D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F17D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F17D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F17D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F17D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F17D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F17D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F17D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F17D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F17D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F17D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F17D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F17D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F17D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F17D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F17D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F17D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F17D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F17D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F17D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F17D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F17D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F17D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F17D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F17D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F17D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F17D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F17D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F17D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F18D1R register  *****************/
#define  CAN_F18D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F18D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F18D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F18D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F18D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F18D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F18D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F18D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F18D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F18D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F18D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F18D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F18D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F18D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F18D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F18D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F18D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F18D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F18D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F18D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F18D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F18D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F18D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F18D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F18D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F18D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F18D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F18D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F18D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F18D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F18D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F18D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F19D1R register  *****************/
#define  CAN_F19D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F19D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F19D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F19D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F19D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F19D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F19D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F19D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F19D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F19D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F19D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F19D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F19D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F19D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F19D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F19D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F19D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F19D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F19D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F19D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F19D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F19D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F19D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F19D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F19D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F19D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F19D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F19D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F19D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F19D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F19D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F19D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F20D1R register  *****************/
#define  CAN_F20D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F20D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F20D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F20D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F20D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F20D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F20D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F20D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F20D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F20D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F20D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F20D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F20D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F20D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F20D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F20D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F20D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F20D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F20D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F20D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F20D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F20D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F20D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F20D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F20D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F20D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F20D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F20D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F20D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F20D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F20D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F20D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F21D1R register  *****************/
#define  CAN_F21D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F21D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F21D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F21D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F21D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F21D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F21D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F21D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F21D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F21D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F21D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F21D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F21D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F21D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F21D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F21D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F21D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F21D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F21D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F21D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F21D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F21D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F21D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F21D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F21D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F21D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F21D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F21D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F21D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F21D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F21D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F21D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F22D1R register  *****************/
#define  CAN_F22D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F22D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F22D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F22D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F22D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F22D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F22D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F22D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F22D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F22D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F22D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F22D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F22D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F22D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F22D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F22D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F22D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F22D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F22D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F22D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F22D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F22D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F22D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F22D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F22D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F22D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F22D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F22D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F22D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F22D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F22D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F22D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F23D1R register  *****************/
#define  CAN_F23D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F23D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F23D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F23D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F23D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F23D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F23D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F23D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F23D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F23D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F23D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F23D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F23D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F23D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F23D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F23D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F23D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F23D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F23D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F23D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F23D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F23D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F23D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F23D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F23D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F23D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F23D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F23D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F23D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F23D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F23D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F23D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F24D1R register  *****************/
#define  CAN_F24D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F24D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F24D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F24D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F24D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F24D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F24D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F24D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F24D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F24D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F24D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F24D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F24D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F24D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F24D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F24D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F24D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F24D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F24D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F24D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F24D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F24D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F24D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F24D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F24D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F24D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F24D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F24D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F24D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F24D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F24D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F24D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F25D1R register  *****************/
#define  CAN_F25D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F25D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F25D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F25D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F25D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F25D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F25D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F25D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F25D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F25D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F25D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F25D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F25D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F25D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F25D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F25D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F25D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F25D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F25D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F25D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F25D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F25D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F25D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F25D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F25D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F25D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F25D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F25D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F25D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F25D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F25D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F25D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F26D1R register  *****************/
#define  CAN_F26D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F26D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F26D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F26D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F26D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F26D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F26D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F26D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F26D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F26D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F26D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F26D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F26D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F26D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F26D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F26D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F26D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F26D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F26D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F26D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F26D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F26D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F26D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F26D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F26D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F26D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F26D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F26D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F26D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F26D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F26D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F26D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_F27D1R register  *****************/
#define  CAN_F27D1R_FD0                      ((uint32_t)0x00000001)            /*!< Filter bit 0 */
#define  CAN_F27D1R_FD1                      ((uint32_t)0x00000002)            /*!< Filter bit 1 */
#define  CAN_F27D1R_FD2                      ((uint32_t)0x00000004)            /*!< Filter bit 2 */
#define  CAN_F27D1R_FD3                      ((uint32_t)0x00000008)            /*!< Filter bit 3 */
#define  CAN_F27D1R_FD4                      ((uint32_t)0x00000010)            /*!< Filter bit 4 */
#define  CAN_F27D1R_FD5                      ((uint32_t)0x00000020)            /*!< Filter bit 5 */
#define  CAN_F27D1R_FD6                      ((uint32_t)0x00000040)            /*!< Filter bit 6 */
#define  CAN_F27D1R_FD7                      ((uint32_t)0x00000080)            /*!< Filter bit 7 */
#define  CAN_F27D1R_FD8                      ((uint32_t)0x00000100)            /*!< Filter bit 8 */
#define  CAN_F27D1R_FD9                      ((uint32_t)0x00000200)            /*!< Filter bit 9 */
#define  CAN_F27D1R_FD10                     ((uint32_t)0x00000400)            /*!< Filter bit 10 */
#define  CAN_F27D1R_FD11                     ((uint32_t)0x00000800)            /*!< Filter bit 11 */
#define  CAN_F27D1R_FD12                     ((uint32_t)0x00001000)            /*!< Filter bit 12 */
#define  CAN_F27D1R_FD13                     ((uint32_t)0x00002000)            /*!< Filter bit 13 */
#define  CAN_F27D1R_FD14                     ((uint32_t)0x00004000)            /*!< Filter bit 14 */
#define  CAN_F27D1R_FD15                     ((uint32_t)0x00008000)            /*!< Filter bit 15 */
#define  CAN_F27D1R_FD16                     ((uint32_t)0x00010000)            /*!< Filter bit 16 */
#define  CAN_F27D1R_FD17                     ((uint32_t)0x00020000)            /*!< Filter bit 17 */
#define  CAN_F27D1R_FD18                     ((uint32_t)0x00040000)            /*!< Filter bit 18 */
#define  CAN_F27D1R_FD19                     ((uint32_t)0x00080000)            /*!< Filter bit 19 */
#define  CAN_F27D1R_FD20                     ((uint32_t)0x00100000)            /*!< Filter bit 20 */
#define  CAN_F27D1R_FD21                     ((uint32_t)0x00200000)            /*!< Filter bit 21 */
#define  CAN_F27D1R_FD22                     ((uint32_t)0x00400000)            /*!< Filter bit 22 */
#define  CAN_F27D1R_FD23                     ((uint32_t)0x00800000)            /*!< Filter bit 23 */
#define  CAN_F27D1R_FD24                     ((uint32_t)0x01000000)            /*!< Filter bit 24 */
#define  CAN_F27D1R_FD25                     ((uint32_t)0x02000000)            /*!< Filter bit 25 */
#define  CAN_F27D1R_FD26                     ((uint32_t)0x04000000)            /*!< Filter bit 26 */
#define  CAN_F27D1R_FD27                     ((uint32_t)0x08000000)            /*!< Filter bit 27 */
#define  CAN_F27D1R_FD28                     ((uint32_t)0x10000000)            /*!< Filter bit 28 */
#define  CAN_F27D1R_FD29                     ((uint32_t)0x20000000)            /*!< Filter bit 29 */
#define  CAN_F27D1R_FD30                     ((uint32_t)0x40000000)            /*!< Filter bit 30 */
#define  CAN_F27D1R_FD31                     ((uint32_t)0x80000000)            /*!< Filter bit 31 */

/*******************  Bit definition for CAN_PHYCR register  ******************/
#define  CAN_PHYCR_PHYEN                     ((uint32_t)0x00000001)            /*!< CAN PHY Enable */

#define  CAN_PHYCR_POMODE                    ((uint32_t)0x00000300)            /*!< POMODE[1:0] bits */
#define  CAN_PHYCR_POMODE_0                  ((uint32_t)0x00000100)            /*!< Bit 0 */
#define  CAN_PHYCR_POMODE_1                  ((uint32_t)0x00000200)            /*!< Bit 1 */
#endif /* GD32F170_190 */  


/******************************************************************************/
/*                                                                            */
/*                                 HDMI-CEC (CEC)                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CEC_CTLR register  *******************/
#define  CEC_CTLR_CECON                      ((uint32_t)0x00000001)            /*!< CEC Enable                        */
#define  CEC_CTLR_SOM                        ((uint32_t)0x00000002)            /*!< CEC Tx Start Of Message           */
#define  CEC_CTLR_EOM                        ((uint32_t)0x00000004)            /*!< CEC Tx End Of Message             */

/*******************  Bit definition for CEC_SR register  *********************/
#define  CEC_SR_SFTM                         ((uint32_t)0x00000007)            /*!< CEC Signal Free Time                */
#define  CEC_SR_RTOL                         ((uint32_t)0x00000008)            /*!< CEC Rx Tolerance                    */
#define  CEC_SR_RBRESTP                      ((uint32_t)0x00000010)            /*!< CEC Rx Stop                         */
#define  CEC_SR_RBREGEN                      ((uint32_t)0x00000020)            /*!< CEC Rx Bit Rising Error generation  */
#define  CEC_SR_RLBPEGEN                     ((uint32_t)0x00000040)            /*!< CEC Rx Long Period Error generation */
#define  CEC_SR_BCNG                         ((uint32_t)0x00000080)            /*!< CEC Broadcast no Error generation   */
#define  CEC_SR_SFTMOPT                      ((uint32_t)0x00000100)            /*!< CEC Signal Free Time optional       */
#define  CEC_SR_OADR                         ((uint32_t)0x7FFF0000)            /*!< CEC Own Address                     */
#define  CEC_SR_LSTNM                        ((uint32_t)0x80000000)            /*!< CEC Listen mode                     */

/*******************  Bit definition for CEC_TDTR register  *******************/
#define  CEC_TDTR_TXDATA                     ((uint32_t)0x000000FF)            /*!< CEC Tx Data                       */

/*******************  Bit definition for CEC_RDTR register  *******************/
#define  CEC_RDTR_RXDATA                     ((uint32_t)0x000000FF)            /*!< CEC Rx Data                       */

/*******************  Bit definition for CEC_ISTR register  *******************/
#define  CEC_ISTR_RBR                        ((uint32_t)0x00000001)            /*!< CEC Rx-Byte Received              */
#define  CEC_ISTR_REND                       ((uint32_t)0x00000002)            /*!< CEC End Of Reception              */
#define  CEC_ISTR_RO                         ((uint32_t)0x00000004)            /*!< CEC Rx-Overrun                    */
#define  CEC_ISTR_RBRE                       ((uint32_t)0x00000008)            /*!< CEC Rx Bit Rising Error           */
#define  CEC_ISTR_RSBPE                      ((uint32_t)0x00000010)            /*!< CEC Rx Short Bit period Error     */
#define  CEC_ISTR_RLBPE                      ((uint32_t)0x00000020)            /*!< CEC Rx Long Bit period Error      */
#define  CEC_ISTR_RAE                        ((uint32_t)0x00000040)            /*!< CEC Rx Missing Acknowledge        */
#define  CEC_ISTR_LSTARB                     ((uint32_t)0x00000080)            /*!< CEC Arbitration Lost              */
#define  CEC_ISTR_TBR                        ((uint32_t)0x00000100)            /*!< CEC Tx Byte Request               */
#define  CEC_ISTR_TEND                       ((uint32_t)0x00000200)            /*!< CEC End of Transmission           */
#define  CEC_ISTR_TU                         ((uint32_t)0x00000400)            /*!< CEC Tx-Buffer Underrun            */
#define  CEC_ISTR_TE                         ((uint32_t)0x00000800)            /*!< CEC Tx-Error                      */
#define  CEC_ISTR_TAE                        ((uint32_t)0x00001000)            /*!< CEC Tx Missing Acknowledge        */

/*******************  Bit definition for CEC_IER register  ********************/
#define  CEC_IER_RBRIE                       ((uint32_t)0x00000001)            /*!< CEC Rx-Byte Received IT Enable         */
#define  CEC_IER_RENDIE                      ((uint32_t)0x00000002)            /*!< CEC End Of Reception IT Enable         */
#define  CEC_IER_ROIE                        ((uint32_t)0x00000004)            /*!< CEC Rx-Overrun IT Enable               */
#define  CEC_IER_RBREIE                      ((uint32_t)0x00000008)            /*!< CEC Rx Bit Rising Error IT Enable      */
#define  CEC_IER_RSBPEIE                     ((uint32_t)0x00000010)            /*!< CEC Rx Short Bit period Error IT Enable*/
#define  CEC_IER_RLBPEIE                     ((uint32_t)0x00000020)            /*!< CEC Rx Long Bit period Error IT Enable */
#define  CEC_IER_RAEIE                       ((uint32_t)0x00000040)            /*!< CEC Rx Missing Acknowledge IT Enable   */
#define  CEC_IER_LSTARBIE                    ((uint32_t)0x00000080)            /*!< CEC Arbitration Lost IT Enable         */
#define  CEC_IER_TBRIE                       ((uint32_t)0x00000100)            /*!< CEC Tx Byte Request  IT Enable         */
#define  CEC_IER_TENDIE                      ((uint32_t)0x00000200)            /*!< CEC End of Transmission IT Enable      */
#define  CEC_IER_TUIE                        ((uint32_t)0x00000400)            /*!< CEC Tx-Buffer Underrun IT Enable       */
#define  CEC_IER_TEIE                        ((uint32_t)0x00000800)            /*!< CEC Tx-Error IT Enable                 */
#define  CEC_IER_TAEIE                       ((uint32_t)0x00001000)            /*!< CEC Tx Missing Acknowledge IT Enable   */


/******************************************************************************/
/*                                                                            */
/*                      Analog Comparators (CMP)                              */
/*                                                                            */
/******************************************************************************/
/***********************  Bit definition for CMP_CSR register  ****************/
#define  CMP_CSR_CMP1EN                      ((uint32_t)0x00000001)            /*!< CMP1 enable                       */
#define  CMP_CSR_CMP1SW                      ((uint32_t)0x00000002)            /*!< SW1 switch control                */

#define  CMP_CSR_CMP1M                       ((uint32_t)0x0000000C)            /*!< CMP1 power mode                   */
#define  CMP_CSR_CMP1M_0                     ((uint32_t)0x00000004)            /*!< CMP1 power mode bit 0             */
#define  CMP_CSR_CMP1M_1                     ((uint32_t)0x00000008)            /*!< CMP1 power mode bit 1             */

#define  CMP_CSR_CMP1MSEL                    ((uint32_t)0x00000070)            /*!< CMP1 inverting input select       */
#define  CMP_CSR_CMP1MSEL_0                  ((uint32_t)0x00000010)            /*!< CMP1 inverting input select bit 0 */
#define  CMP_CSR_CMP1MSEL_1                  ((uint32_t)0x00000020)            /*!< CMP1 inverting input select bit 1 */
#define  CMP_CSR_CMP1MSEL_2                  ((uint32_t)0x00000040)            /*!< CMP1 inverting input select bit 2 */

#define  CMP_CSR_CMP1OSEL                    ((uint32_t)0x00000700)            /*!< CMP1 output select                */
#define  CMP_CSR_CMP1OSEL_0                  ((uint32_t)0x00000100)            /*!< CMP1 output select bit 0          */
#define  CMP_CSR_CMP1OSEL_1                  ((uint32_t)0x00000200)            /*!< CMP1 output select bit 1          */
#define  CMP_CSR_CMP1OSEL_2                  ((uint32_t)0x00000400)            /*!< CMP1 output select bit 2          */

#define  CMP_CSR_CMP1PL                      ((uint32_t)0x00000800)            /*!< CMP1 output polarity              */

#define  CMP_CSR_CMP1HST                     ((uint32_t)0x00003000)            /*!< CMP1 hysteresis                   */
#define  CMP_CSR_CMP1HST_0                   ((uint32_t)0x00001000)            /*!< CMP1 hysteresis bit 0             */
#define  CMP_CSR_CMP1HST_1                   ((uint32_t)0x00002000)            /*!< CMP1 hysteresis bit 1             */

#define  CMP_CSR_CMP1O                       ((uint32_t)0x00004000)            /*!< CMP1 output level                 */
#define  CMP_CSR_CMP1LK                      ((uint32_t)0x00008000)            /*!< CMP1 lock                         */

#define  CMP_CSR_CMP2EN                      ((uint32_t)0x00010000)            /*!< CMP2 enable                       */

#define  CMP_CSR_CMP2M                       ((uint32_t)0x000C0000)            /*!< CMP2 power mode                   */
#define  CMP_CSR_CMP2M_0                     ((uint32_t)0x00040000)            /*!< CMP2 power mode bit 0             */
#define  CMP_CSR_CMP2M_1                     ((uint32_t)0x00080000)            /*!< CMP2 power mode bit 1             */

#define  CMP_CSR_CMP2MSEL                    ((uint32_t)0x00700000)            /*!< CMP2 inverting input select       */
#define  CMP_CSR_CMP2MSEL_0                  ((uint32_t)0x00100000)            /*!< CMP2 inverting input select bit 0 */
#define  CMP_CSR_CMP2MSEL_1                  ((uint32_t)0x00200000)            /*!< CMP2 inverting input select bit 1 */
#define  CMP_CSR_CMP2MSEL_2                  ((uint32_t)0x00400000)            /*!< CMP2 inverting input select bit 2 */

#define  CMP_CSR_WNDEN                       ((uint32_t)0x00800000)            /*!< CMParators window mode enable     */

#define  CMP_CSR_CMP2OSEL                    ((uint32_t)0x07000000)            /*!< CMP2 output select                */
#define  CMP_CSR_CMP2OSEL_0                  ((uint32_t)0x01000000)            /*!< CMP2 output select bit 0          */
#define  CMP_CSR_CMP2OSEL_1                  ((uint32_t)0x02000000)            /*!< CMP2 output select bit 1          */
#define  CMP_CSR_CMP2OSEL_2                  ((uint32_t)0x04000000)            /*!< CMP2 output select bit 2          */

#define  CMP_CSR_CMP2PL                      ((uint32_t)0x08000000)            /*!< CMP2 output polarity              */

#define  CMP_CSR_CMP2HST                     ((uint32_t)0x30000000)            /*!< CMP2 hysteresis                   */
#define  CMP_CSR_CMP2HST_0                   ((uint32_t)0x10000000)            /*!< CMP2 hysteresis bit 0             */
#define  CMP_CSR_CMP2HST_1                   ((uint32_t)0x20000000)            /*!< CMP2 hysteresis bit 1             */

#define  CMP_CSR_CMP2O                       ((uint32_t)0x40000000)            /*!< CMP2 output level                 */
#define  CMP_CSR_CMP2LK                      ((uint32_t)0x80000000)            /*!< CMP2 lock                         */


/******************************************************************************/
/*                                                                            */
/*                       CRC calculation unit (CRC)                           */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DTR register  ********************/
#define  CRC_DTR_DATA                        ((uint32_t)0xFFFFFFFF)            /*!< Data register bits */

/*******************  Bit definition for CRC_FDTR register  *******************/
#define  CRC_FDTR_FDR                        ((uint8_t)0xFF)                   /*!< General-purpose 8-bit data register bits */

/********************  Bit definition for CRC_CTLR register  ******************/
#define  CRC_CTLR_RESET                      ((uint32_t)0x00000001)            /*!< RESET the CRC computation unit bit */
#define  CRC_CTLR_REV_I                      ((uint32_t)0x00000060)            /*!< REV_I Reverse Input Data bits      */
#define  CRC_CTLR_REV_I_0                    ((uint32_t)0x00000020)            /*!< REV_I Bit 0                        */
#define  CRC_CTLR_REV_I_1                    ((uint32_t)0x00000040)            /*!< REV_I Bit 1                        */
#define  CRC_CTLR_REV_O                      ((uint32_t)0x00000080)            /*!< REV_O Reverse Output Data bits     */

/*******************  Bit definition for CRC_IDTR register  *******************/
#define  CRC_IDTR_IDAR                       ((uint32_t)0xFFFFFFFF)            /*!< Initial CRC value bits             */


/******************************************************************************/
/*                                                                            */
/*                    Digital to Analog Converter (DAC)                       */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DAC_CTLR register  ******************/
#define  DAC_CTLR_DEN1                       ((uint32_t)0x00000001)            /*!< DAC1 enable */
#define  DAC_CTLR_DBOFF1                     ((uint32_t)0x00000002)            /*!< DAC1 output buffer disable */
#define  DAC_CTLR_DTEN1                      ((uint32_t)0x00000004)            /*!< DAC1 Trigger enable */

#define  DAC_CTLR_DTSEL1                     ((uint32_t)0x00000038)            /*!< TSEL1[2:0] (DAC1 Trigger selection) */
#define  DAC_CTLR_DTSEL1_0                   ((uint32_t)0x00000008)            /*!< Bit 0 */
#define  DAC_CTLR_DTSEL1_1                   ((uint32_t)0x00000010)            /*!< Bit 1 */
#define  DAC_CTLR_DTSEL1_2                   ((uint32_t)0x00000020)            /*!< Bit 2 */

#define  DAC_CTLR_DDMAEN1                    ((uint32_t)0x00001000)            /*!< DAC1 DMA enable */
#define  DAC_CTLR_DDMAUDRIE1                 ((uint32_t)0x00002000)            /*!< DAC1 DMAUDRIE enable */

#ifdef GD32F170_190
#define  DAC_CTLR_DEN2                       ((uint32_t)0x00010000)            /*!< DAC2 enable */
#define  DAC_CTLR_DBOFF2                     ((uint32_t)0x00020000)            /*!< DAC2 output buffer disable */
#define  DAC_CTLR_DTEN2                      ((uint32_t)0x00040000)            /*!< DAC2 Trigger enable */

#define  DAC_CTLR_DTSEL2                     ((uint32_t)0x00380000)            /*!< TSEL2[2:0] (DAC2 Trigger selection) */
#define  DAC_CTLR_DTSEL2_0                   ((uint32_t)0x00080000)            /*!< Bit 0 */
#define  DAC_CTLR_DTSEL2_1                   ((uint32_t)0x00100000)            /*!< Bit 1 */
#define  DAC_CTLR_DTSEL2_2                   ((uint32_t)0x00200000)            /*!< Bit 2 */

#define  DAC_CTLR_DDMAEN2                    ((uint32_t)0x10000000)            /*!< DAC2 DMA enabled */
#define  DAC_CTLR_DDMAUDRIE2                 ((uint32_t)0x20000000)            /*!< DAC2 DMAUDRIE enable */
#endif  /* GD32F170_190 */

/*****************  Bit definition for DAC_SWTR register  *********************/
#define  DAC_SWTR_SWTR1                      ((uint8_t)0x01)                   /*!< DAC1 software trigger */

#ifdef GD32F170_190
#define  DAC_SWTR_SWTR2                      ((uint8_t)0x02)                   /*!< DAC2 software trigger */
#endif  /* GD32F170_190 */

/*****************  Bit definition for DAC1_R12DHR register  ******************/
#define  DAC1_R12DHR_DAC1_DHR                ((uint16_t)0x0FFF)                /*!< DAC1 12-bit Right aligned data */

/*****************  Bit definition for DAC1_L12DHR register  ******************/
#define  DAC1_L12DHR_DAC1_DHR                ((uint16_t)0xFFF0)                /*!< DAC1 12-bit Left aligned data */

/******************  Bit definition for DAC1_R8DHR register  ******************/
#define  DAC1_R8DHR_DAC1_DHR                 ((uint8_t)0xFF)                   /*!< DAC1 8-bit Right aligned data */

#ifdef GD32F170_190
/*******************  Bit definition for DAC2_R12DHR register  ****************/
#define  DAC2_R12DHR_DAC2_DHR                ((uint16_t)0x0FFF)                /*!< DAC2 12-bit Right aligned data */

/*******************  Bit definition for DAC2_L12DHR register  ****************/
#define  DAC2_L12DHR_DAC2_DHR                ((uint16_t)0xFFF0)                /*!< DAC2 12-bit Left aligned data */

/*********************Bit definition for DAC2_R8DHR register  *****************/
#define  DAC2_R8DHR_DAC2_DHR                 ((uint8_t)0xFF)                   /*!< DAC2 8-bit Right aligned data */

/*******************  Bit definition for DACD_R12DHR register  ****************/
#define  DACD_R12DHR_DAC1_DHR                ((uint32_t)0x00000FFF)            /*!< Dual DAC mode 12-bit right-aligned data holding register 
                                                                                    DAC1 12-bit Right aligned data */
#define  DACD_R12DHR_DAC2_DHR                ((uint32_t)0x0FFF0000)            /*!< Dual DAC mode 12-bit right-aligned data holding register 
                                                                                    DAC2 12-bit Right aligned data*/

/*******************  Bit definition for DACD_L12DHR register  ****************/
#define  DACD_L12DHR_DAC1_DHR                ((uint32_t)0x0000FFF0)            /*!< Dual DAC mode 12-bit Left-aligned data holding register
                                                                                    DAC1 12-bit Left aligned data */
#define  DACD_L12DHR_DAC2_DHR                ((uint32_t)0xFFF00000)            /*!< Dual DAC mode 12-bit Left-aligned data holding register 
                                                                                    DAC2 12-bit Left aligned data*/

/*******************  Bit definition for DACD_R8DHR register  *****************/
#define  DACD_R8DHR_DAC1_DHR                 ((uint16_t)0x00FF)                /*!< Dual DAC mode 8-bit right-aligned data holding register 
                                                                                    DAC1 8-bit Right aligned data*/
#define  DACD_R8DHR_DAC2_DHR                 ((uint16_t)0xFF00)                /*!< Dual DAC mode 8-bit right-aligned data holding register 
                                                                                    DAC1 8-bit Right aligned data*/
#endif  /* GD32F170_190 */


/*******************  Bit definition for DAC1_ODR register  *******************/
#define  DAC1_ODR_DAC1_ODR                   ((uint16_t)0x0FFF)                /*!< DAC1 output data */

#ifdef GD32F170_190
/*******************  Bit definition for DAC2_ODR register  *******************/
#define  DAC2_ODR_DAC2_ODR                   ((uint16_t)0x0FFF)                /*!< DAC2 output data */
#endif  /* GD32F170_190 */

/********************  Bit definition for DAC_STR register  *******************/
#define  DAC_STR_DDMA1UDR                    ((uint32_t)0x00002000)            /*!<DAC1 DMA underrun flag */

#ifdef GD32F170_190
#define  DAC_STR_DDMA2UDR                    ((uint32_t)0x20000000)            /*!<DAC2 DMA underrun flag */
#endif  /* GD32F170_190 */


/******************************************************************************/
/*                                                                            */
/*                           Debug MCU (MCUDBG)                               */
/*                                                                            */
/******************************************************************************/
/****************  Bit definition for MCUDBG_IDR register  ********************/                                                                     
#define  MCUDBG_IDR_ID                       ((uint32_t)0xFFFFFFFF)            /*!< MCUDBG ID code */                                                          
                                                                                                                                                                                                             
/******************  Bit definition for MCUDBG_CTLR1 register  ****************/                                                               
#define  MCUDBG_CTLR1_SLEEP_HOLD             ((uint32_t)0x00000001)            /*!< Debug sleep Mode */                                                 
#define  MCUDBG_CTLR1_DEEPSLEEP_HOLD         ((uint32_t)0x00000002)            /*!< Debug Deep-sleep Mode */                                            
#define  MCUDBG_CTLR1_STANDBY_HOLD           ((uint32_t)0x00000004)            /*!< Debug Standby mode */                                               
#define  MCUDBG_CTLR1_IWDG_HOLD              ((uint32_t)0x00000100)            /*!< Hold the iwdg counter clock for debug when core halted */           
#define  MCUDBG_CTLR1_WWDG_HOLD              ((uint32_t)0x00000200)            /*!< hold the wwdg counter clock for debug when core halted */           
#define  MCUDBG_CTLR1_TIMER1_HOLD            ((uint32_t)0x00000400)            /*!< Hold the Timer1 counter for debug when core halted */               
#define  MCUDBG_CTLR1_TIMER2_HOLD            ((uint32_t)0x00000800)            /*!< Hold the Timer2 counter for debug when core halted */               
#define  MCUDBG_CTLR1_TIMER3_HOLD            ((uint32_t)0x00001000)            /*!< Hold the Timer3 counter for debug when core halted */               

#ifdef GD32F170_190
#define  MCUDBG_CTLR1_CAN1_HOLD              ((uint32_t)0x00004000)            /*!< Hold the CAN1 for debug when core halted */                         
#endif /* GD32F170_190 */

#define  MCUDBG_CTLR1_I2C1_HOLD              ((uint32_t)0x00008000)            /*!< Hold the I2C1 SMBUS timeout for debug when core halted */           
#define  MCUDBG_CTLR1_I2C2_HOLD              ((uint32_t)0x00010000)            /*!< Hold the I2C2 SMBUS timeout for debug when core halted */           
#define  MCUDBG_CTLR1_I2C3_HOLD              ((uint32_t)0x00020000)            /*!< Hold the I2C3 SMBUS timeout for debug when core halted */           
#define  MCUDBG_CTLR1_TIMER6_HOLD            ((uint32_t)0x00080000)            /*!< Hold the Timer6 counter for debug when core halted */               

#ifdef GD32F170_190
#define  MCUDBG_CTLR1_CAN2_HOLD              ((uint32_t)0x00200000)            /*!< Hold the CAN2 for debug when core halted */                         
#endif /* GD32F170_190 */

#define  MCUDBG_CTLR1_TIMER14_HOLD           ((uint32_t)0x08000000)            /*!< Hold the Timer14 counter for debug when core halted */              
                                                                                                                                                  
/******************  Bit definition for MCUDBG_CTLR2 register  ****************/                                                                    
#define  MCUDBG_CTLR2_RTC_HOLD               ((uint32_t)0x00000400)            /*!< Hold the RTC counter for debug when core halted */                  
#define  MCUDBG_CTLR2_TIMER15_HOLD           ((uint32_t)0x00010000)            /*!< Hold the Timer15 counter for debug when core halted */              
#define  MCUDBG_CTLR2_TIMER16_HOLD           ((uint32_t)0x00020000)            /*!< Hold the Timer16 counter for debug when core halted */              
#define  MCUDBG_CTLR2_TIMER17_HOLD           ((uint32_t)0x00040000)            /*!< Hold the Timer17 counter for debug when core halted */    


/******************************************************************************/
/*                                                                            */
/*                           DMA Controller (DMA)                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for DMA_IFR register  ********************/
#define  DMA_IFR_GIF1                        ((uint32_t)0x00000001)            /*!< Channel 1 Global interrupt flag    */
#define  DMA_IFR_TCIF1                       ((uint32_t)0x00000002)            /*!< Channel 1 Transfer Complete flag   */
#define  DMA_IFR_HTIF1                       ((uint32_t)0x00000004)            /*!< Channel 1 Half Transfer flag       */
#define  DMA_IFR_ERRIF1                      ((uint32_t)0x00000008)            /*!< Channel 1 Transfer Error flag      */
#define  DMA_IFR_GIF2                        ((uint32_t)0x00000010)            /*!< Channel 2 Global interrupt flag    */
#define  DMA_IFR_TCIF2                       ((uint32_t)0x00000020)            /*!< Channel 2 Transfer Complete flag   */
#define  DMA_IFR_HTIF2                       ((uint32_t)0x00000040)            /*!< Channel 2 Half Transfer flag       */
#define  DMA_IFR_ERRIF2                      ((uint32_t)0x00000080)            /*!< Channel 2 Transfer Error flag      */
#define  DMA_IFR_HTIF3                       ((uint32_t)0x00000400)            /*!< Channel 3 Half Transfer flag       */
#define  DMA_IFR_ERRIF3                      ((uint32_t)0x00000800)            /*!< Channel 3 Transfer Error flag      */
#define  DMA_IFR_GIF3                        ((uint32_t)0x00000100)            /*!< Channel 3 Global interrupt flag    */
#define  DMA_IFR_TCIF3                       ((uint32_t)0x00000200)            /*!< Channel 3 Transfer Complete flag   */
#define  DMA_IFR_GIF4                        ((uint32_t)0x00001000)            /*!< Channel 4 Global interrupt flag    */
#define  DMA_IFR_TCIF4                       ((uint32_t)0x00002000)            /*!< Channel 4 Transfer Complete flag   */
#define  DMA_IFR_HTIF4                       ((uint32_t)0x00004000)            /*!< Channel 4 Half Transfer flag       */
#define  DMA_IFR_ERRIF4                      ((uint32_t)0x00008000)            /*!< Channel 4 Transfer Error flag      */
#define  DMA_IFR_GIF5                        ((uint32_t)0x00010000)            /*!< Channel 5 Global interrupt flag    */
#define  DMA_IFR_TCIF5                       ((uint32_t)0x00020000)            /*!< Channel 5 Transfer Complete flag   */
#define  DMA_IFR_HTIF5                       ((uint32_t)0x00040000)            /*!< Channel 5 Half Transfer flag       */
#define  DMA_IFR_ERRIF5                      ((uint32_t)0x00080000)            /*!< Channel 5 Transfer Error flag      */
#define  DMA_IFR_GIF6                        ((uint32_t)0x00100000)            /*!< Channel 6 Global interrupt flag    */
#define  DMA_IFR_TCIF6                       ((uint32_t)0x00200000)            /*!< Channel 6 Transfer Complete flag   */
#define  DMA_IFR_HTIF6                       ((uint32_t)0x00400000)            /*!< Channel 6 Half Transfer flag       */
#define  DMA_IFR_ERRIF6                      ((uint32_t)0x00800000)            /*!< Channel 6 Transfer Error flag      */
#define  DMA_IFR_GIF7                        ((uint32_t)0x01000000)            /*!< Channel 7 Global interrupt flag    */
#define  DMA_IFR_TCIF7                       ((uint32_t)0x02000000)            /*!< Channel 7 Transfer Complete flag   */
#define  DMA_IFR_HTIF7                       ((uint32_t)0x04000000)            /*!< Channel 7 Half Transfer flag       */
#define  DMA_IFR_ERRIF7                      ((uint32_t)0x08000000)            /*!< Channel 7 Transfer Error flag      */

/*******************  Bit definition for DMA_ICR register  ********************/
#define  DMA_ICR_GIC1                        ((uint32_t)0x00000001)            /*!< Channel 1 Global interrupt clear    */
#define  DMA_ICR_TCIC1                       ((uint32_t)0x00000002)            /*!< Channel 1 Transfer Complete clear   */
#define  DMA_ICR_HTIC1                       ((uint32_t)0x00000004)            /*!< Channel 1 Half Transfer clear       */
#define  DMA_ICR_ERRIC1                      ((uint32_t)0x00000008)            /*!< Channel 1 Transfer Error clear      */
#define  DMA_ICR_GIC2                        ((uint32_t)0x00000010)            /*!< Channel 2 Global interrupt clear    */
#define  DMA_ICR_TCIC2                       ((uint32_t)0x00000020)            /*!< Channel 2 Transfer Complete clear   */
#define  DMA_ICR_HTIC2                       ((uint32_t)0x00000040)            /*!< Channel 2 Half Transfer clear       */
#define  DMA_ICR_ERRIC2                      ((uint32_t)0x00000080)            /*!< Channel 2 Transfer Error clear      */
#define  DMA_ICR_GIC3                        ((uint32_t)0x00000100)            /*!< Channel 3 Global interrupt clear    */
#define  DMA_ICR_TCIC3                       ((uint32_t)0x00000200)            /*!< Channel 3 Transfer Complete clear   */
#define  DMA_ICR_HTIC3                       ((uint32_t)0x00000400)            /*!< Channel 3 Half Transfer clear       */
#define  DMA_ICR_ERRIC3                      ((uint32_t)0x00000800)            /*!< Channel 3 Transfer Error clear      */
#define  DMA_ICR_GIC4                        ((uint32_t)0x00001000)            /*!< Channel 4 Global interrupt clear    */
#define  DMA_ICR_TCIC4                       ((uint32_t)0x00002000)            /*!< Channel 4 Transfer Complete clear   */
#define  DMA_ICR_HTIC4                       ((uint32_t)0x00004000)            /*!< Channel 4 Half Transfer clear       */
#define  DMA_ICR_ERRIC4                      ((uint32_t)0x00008000)            /*!< Channel 4 Transfer Error clear      */
#define  DMA_ICR_GIC5                        ((uint32_t)0x00010000)            /*!< Channel 5 Global interrupt clear    */
#define  DMA_ICR_TCIC5                       ((uint32_t)0x00020000)            /*!< Channel 5 Transfer Complete clear   */
#define  DMA_ICR_HTIC5                       ((uint32_t)0x00040000)            /*!< Channel 5 Half Transfer clear       */
#define  DMA_ICR_ERRIC5                      ((uint32_t)0x00080000)            /*!< Channel 5 Transfer Error clear      */
#define  DMA_ICR_GIC6                        ((uint32_t)0x00100000)            /*!< Channel 6 Global interrupt clear    */   
#define  DMA_ICR_TCIC6                       ((uint32_t)0x00200000)            /*!< Channel 6 Transfer Complete clear   */
#define  DMA_ICR_HTIC6                       ((uint32_t)0x00400000)            /*!< Channel 6 Half Transfer clear       */
#define  DMA_ICR_ERRIC6                      ((uint32_t)0x00800000)            /*!< Channel 6 Transfer Error clear      */
#define  DMA_ICR_GIC7                        ((uint32_t)0x01000000)            /*!< Channel 7 Global interrupt clear    */
#define  DMA_ICR_TCIC7                       ((uint32_t)0x02000000)            /*!< Channel 7 Transfer Complete clear   */
#define  DMA_ICR_HTIC7                       ((uint32_t)0x04000000)            /*!< Channel 7 Half Transfer clear       */
#define  DMA_ICR_ERRIC7                      ((uint32_t)0x08000000)            /*!< Channel 7 Transfer Error clear      */

/*******************  Bit definition for DMA_CTLRx register  ******************/
#define  DMA_CTLRx_CHEN                      ((uint32_t)0x00000001)            /*!< Channel enable                      */
#define  DMA_CTLRx_TCIE                      ((uint32_t)0x00000002)            /*!< Transfer complete interrupt enable  */
#define  DMA_CTLRx_HTIE                      ((uint32_t)0x00000004)            /*!< Half Transfer interrupt enable      */
#define  DMA_CTLRx_ERRIE                     ((uint32_t)0x00000008)            /*!< Transfer error interrupt enable     */
#define  DMA_CTLRx_DIR                       ((uint32_t)0x00000010)            /*!< Data transfer direction             */
#define  DMA_CTLRx_CIRC                      ((uint32_t)0x00000020)            /*!< Circular mode                       */
#define  DMA_CTLRx_PNAGA                     ((uint32_t)0x00000040)            /*!< Peripheral increment mode           */
#define  DMA_CTLRx_MNAGA                     ((uint32_t)0x00000080)            /*!< Memory increment mode               */

#define  DMA_CTLRx_PSIZE                     ((uint32_t)0x00000300)            /*!< PSIZE[1:0] bits (Peripheral size)   */
#define  DMA_CTLRx_PSIZE_0                   ((uint32_t)0x00000100)            /*!< Bit 0                               */
#define  DMA_CTLRx_PSIZE_1                   ((uint32_t)0x00000200)            /*!< Bit 1                               */

#define  DMA_CTLRx_MSIZE                     ((uint32_t)0x00000C00)            /*!< MSIZE[1:0] bits (Memory size)       */
#define  DMA_CTLRx_MSIZE_0                   ((uint32_t)0x00000400)            /*!< Bit 0                               */
#define  DMA_CTLRx_MSIZE_1                   ((uint32_t)0x00000800)            /*!< Bit 1                               */

#define  DMA_CTLRx_PRIO                      ((uint32_t)0x00003000)            /*!< PRIO[1:0] bits(Channel Priority level)*/
#define  DMA_CTLRx_PRIO_0                    ((uint32_t)0x00001000)            /*!< Bit 0                               */
#define  DMA_CTLRx_PRIO_1                    ((uint32_t)0x00002000)            /*!< Bit 1                               */

#define  DMA_CTLRx_MEMTOMEM                  ((uint32_t)0x00004000)            /*!< Memory to memory mode               */

/******************  Bit definition for DMA_RCNTx register  *******************/
#define  DMA_RCNTx_RCNT                      ((uint32_t)0x0000FFFF)            /*!< Number of data to Transfer        */

/******************  Bit definition for DMA_PBARX register  *******************/
#define  DMA_PBARx_PBAR                      ((uint32_t)0xFFFFFFFF)            /*!< Peripheral Address                */

/******************  Bit definition for DMA_CMAR register  ********************/
#define  DMA_MBARx_MBAR                      ((uint32_t)0xFFFFFFFF)            /*!< Memory Address                    */


/******************************************************************************/
/*                                                                            */
/*                               SystemTick                                   */
/*                                                                            */
/******************************************************************************/
/*****************  Bit definition for SysTick_CTRL register  *****************/
#define  SYSTICK_CTRL_ENABLE                 ((uint32_t)0x00000001)            /*!< Counter enable */
#define  SYSTICK_CTRL_TICKINT                ((uint32_t)0x00000002)            /*!< Counting down to 0 pends the SysTick handler */
#define  SYSTICK_CTRL_CLKSOURCE              ((uint32_t)0x00000004)            /*!< Clock source */
#define  SYSTICK_CTRL_COUNTFLAG              ((uint32_t)0x00010000)            /*!< Count Flag */

/*****************  Bit definition for SysTick_LOAD register  *****************/
#define  SYSTICK_LOAD_RELOAD                 ((uint32_t)0x00FFFFFF)            /*!< Value to load into the SysTick Current Value Register when the counter reaches 0 */

/*****************  Bit definition for SysTick_VAL register  ******************/
#define  SYSTICK_VAL_CURRENT                 ((uint32_t)0x00FFFFFF)            /*!< Current value at the time the register is accessed */

/*****************  Bit definition for SysTick_CALIB register  ****************/
#define  SYSTICK_CALIB_TENMS                 ((uint32_t)0x00FFFFFF)            /*!< Reload value to use for 10ms timing */
#define  SYSTICK_CALIB_SKEW                  ((uint32_t)0x40000000)            /*!< Calibration value is not exactly 10 ms */
#define  SYSTICK_CALIB_NOREF                 ((uint32_t)0x80000000)            /*!< The reference clock is not provided */


/******************************************************************************/
/*                                                                            */
/*                  Nested Vectored Interrupt Controller                      */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for NVIC_ISER register  *******************/
#define  NVIC_ISER_SETENA                    ((uint32_t)0xFFFFFFFF)            /*!< Interrupt set enable bits */
#define  NVIC_ISER_SETENA_0                  ((uint32_t)0x00000001)            /*!< bit 0 */
#define  NVIC_ISER_SETENA_1                  ((uint32_t)0x00000002)            /*!< bit 1 */
#define  NVIC_ISER_SETENA_2                  ((uint32_t)0x00000004)            /*!< bit 2 */
#define  NVIC_ISER_SETENA_3                  ((uint32_t)0x00000008)            /*!< bit 3 */
#define  NVIC_ISER_SETENA_4                  ((uint32_t)0x00000010)            /*!< bit 4 */
#define  NVIC_ISER_SETENA_5                  ((uint32_t)0x00000020)            /*!< bit 5 */
#define  NVIC_ISER_SETENA_6                  ((uint32_t)0x00000040)            /*!< bit 6 */
#define  NVIC_ISER_SETENA_7                  ((uint32_t)0x00000080)            /*!< bit 7 */
#define  NVIC_ISER_SETENA_8                  ((uint32_t)0x00000100)            /*!< bit 8 */
#define  NVIC_ISER_SETENA_9                  ((uint32_t)0x00000200)            /*!< bit 9 */
#define  NVIC_ISER_SETENA_10                 ((uint32_t)0x00000400)            /*!< bit 10 */
#define  NVIC_ISER_SETENA_11                 ((uint32_t)0x00000800)            /*!< bit 11 */
#define  NVIC_ISER_SETENA_12                 ((uint32_t)0x00001000)            /*!< bit 12 */
#define  NVIC_ISER_SETENA_13                 ((uint32_t)0x00002000)            /*!< bit 13 */
#define  NVIC_ISER_SETENA_14                 ((uint32_t)0x00004000)            /*!< bit 14 */
#define  NVIC_ISER_SETENA_15                 ((uint32_t)0x00008000)            /*!< bit 15 */
#define  NVIC_ISER_SETENA_16                 ((uint32_t)0x00010000)            /*!< bit 16 */
#define  NVIC_ISER_SETENA_17                 ((uint32_t)0x00020000)            /*!< bit 17 */
#define  NVIC_ISER_SETENA_18                 ((uint32_t)0x00040000)            /*!< bit 18 */
#define  NVIC_ISER_SETENA_19                 ((uint32_t)0x00080000)            /*!< bit 19 */
#define  NVIC_ISER_SETENA_20                 ((uint32_t)0x00100000)            /*!< bit 20 */
#define  NVIC_ISER_SETENA_21                 ((uint32_t)0x00200000)            /*!< bit 21 */
#define  NVIC_ISER_SETENA_22                 ((uint32_t)0x00400000)            /*!< bit 22 */
#define  NVIC_ISER_SETENA_23                 ((uint32_t)0x00800000)            /*!< bit 23 */
#define  NVIC_ISER_SETENA_24                 ((uint32_t)0x01000000)            /*!< bit 24 */
#define  NVIC_ISER_SETENA_25                 ((uint32_t)0x02000000)            /*!< bit 25 */
#define  NVIC_ISER_SETENA_26                 ((uint32_t)0x04000000)            /*!< bit 26 */
#define  NVIC_ISER_SETENA_27                 ((uint32_t)0x08000000)            /*!< bit 27 */
#define  NVIC_ISER_SETENA_28                 ((uint32_t)0x10000000)            /*!< bit 28 */
#define  NVIC_ISER_SETENA_29                 ((uint32_t)0x20000000)            /*!< bit 29 */
#define  NVIC_ISER_SETENA_30                 ((uint32_t)0x40000000)            /*!< bit 30 */
#define  NVIC_ISER_SETENA_31                 ((uint32_t)0x80000000)            /*!< bit 31 */

/******************  Bit definition for NVIC_ICER register  *******************/
#define  NVIC_ICER_CLRENA                    ((uint32_t)0xFFFFFFFF)            /*!< Interrupt clear-enable bits */
#define  NVIC_ICER_CLRENA_0                  ((uint32_t)0x00000001)            /*!< bit 0 */
#define  NVIC_ICER_CLRENA_1                  ((uint32_t)0x00000002)            /*!< bit 1 */
#define  NVIC_ICER_CLRENA_2                  ((uint32_t)0x00000004)            /*!< bit 2 */
#define  NVIC_ICER_CLRENA_3                  ((uint32_t)0x00000008)            /*!< bit 3 */
#define  NVIC_ICER_CLRENA_4                  ((uint32_t)0x00000010)            /*!< bit 4 */
#define  NVIC_ICER_CLRENA_5                  ((uint32_t)0x00000020)            /*!< bit 5 */
#define  NVIC_ICER_CLRENA_6                  ((uint32_t)0x00000040)            /*!< bit 6 */
#define  NVIC_ICER_CLRENA_7                  ((uint32_t)0x00000080)            /*!< bit 7 */
#define  NVIC_ICER_CLRENA_8                  ((uint32_t)0x00000100)            /*!< bit 8 */
#define  NVIC_ICER_CLRENA_9                  ((uint32_t)0x00000200)            /*!< bit 9 */
#define  NVIC_ICER_CLRENA_10                 ((uint32_t)0x00000400)            /*!< bit 10 */
#define  NVIC_ICER_CLRENA_11                 ((uint32_t)0x00000800)            /*!< bit 11 */
#define  NVIC_ICER_CLRENA_12                 ((uint32_t)0x00001000)            /*!< bit 12 */
#define  NVIC_ICER_CLRENA_13                 ((uint32_t)0x00002000)            /*!< bit 13 */
#define  NVIC_ICER_CLRENA_14                 ((uint32_t)0x00004000)            /*!< bit 14 */
#define  NVIC_ICER_CLRENA_15                 ((uint32_t)0x00008000)            /*!< bit 15 */
#define  NVIC_ICER_CLRENA_16                 ((uint32_t)0x00010000)            /*!< bit 16 */
#define  NVIC_ICER_CLRENA_17                 ((uint32_t)0x00020000)            /*!< bit 17 */
#define  NVIC_ICER_CLRENA_18                 ((uint32_t)0x00040000)            /*!< bit 18 */
#define  NVIC_ICER_CLRENA_19                 ((uint32_t)0x00080000)            /*!< bit 19 */
#define  NVIC_ICER_CLRENA_20                 ((uint32_t)0x00100000)            /*!< bit 20 */
#define  NVIC_ICER_CLRENA_21                 ((uint32_t)0x00200000)            /*!< bit 21 */
#define  NVIC_ICER_CLRENA_22                 ((uint32_t)0x00400000)            /*!< bit 22 */
#define  NVIC_ICER_CLRENA_23                 ((uint32_t)0x00800000)            /*!< bit 23 */
#define  NVIC_ICER_CLRENA_24                 ((uint32_t)0x01000000)            /*!< bit 24 */
#define  NVIC_ICER_CLRENA_25                 ((uint32_t)0x02000000)            /*!< bit 25 */
#define  NVIC_ICER_CLRENA_26                 ((uint32_t)0x04000000)            /*!< bit 26 */
#define  NVIC_ICER_CLRENA_27                 ((uint32_t)0x08000000)            /*!< bit 27 */
#define  NVIC_ICER_CLRENA_28                 ((uint32_t)0x10000000)            /*!< bit 28 */
#define  NVIC_ICER_CLRENA_29                 ((uint32_t)0x20000000)            /*!< bit 29 */
#define  NVIC_ICER_CLRENA_30                 ((uint32_t)0x40000000)            /*!< bit 30 */
#define  NVIC_ICER_CLRENA_31                 ((uint32_t)0x80000000)            /*!< bit 31 */

/******************  Bit definition for NVIC_ISPR register  *******************/
#define  NVIC_ISPR_SETPEND                   ((uint32_t)0xFFFFFFFF)            /*!< Interrupt set-pending bits */
#define  NVIC_ISPR_SETPEND_0                 ((uint32_t)0x00000001)            /*!< bit 0 */
#define  NVIC_ISPR_SETPEND_1                 ((uint32_t)0x00000002)            /*!< bit 1 */
#define  NVIC_ISPR_SETPEND_2                 ((uint32_t)0x00000004)            /*!< bit 2 */
#define  NVIC_ISPR_SETPEND_3                 ((uint32_t)0x00000008)            /*!< bit 3 */
#define  NVIC_ISPR_SETPEND_4                 ((uint32_t)0x00000010)            /*!< bit 4 */
#define  NVIC_ISPR_SETPEND_5                 ((uint32_t)0x00000020)            /*!< bit 5 */
#define  NVIC_ISPR_SETPEND_6                 ((uint32_t)0x00000040)            /*!< bit 6 */
#define  NVIC_ISPR_SETPEND_7                 ((uint32_t)0x00000080)            /*!< bit 7 */
#define  NVIC_ISPR_SETPEND_8                 ((uint32_t)0x00000100)            /*!< bit 8 */
#define  NVIC_ISPR_SETPEND_9                 ((uint32_t)0x00000200)            /*!< bit 9 */
#define  NVIC_ISPR_SETPEND_10                ((uint32_t)0x00000400)            /*!< bit 10 */
#define  NVIC_ISPR_SETPEND_11                ((uint32_t)0x00000800)            /*!< bit 11 */
#define  NVIC_ISPR_SETPEND_12                ((uint32_t)0x00001000)            /*!< bit 12 */
#define  NVIC_ISPR_SETPEND_13                ((uint32_t)0x00002000)            /*!< bit 13 */
#define  NVIC_ISPR_SETPEND_14                ((uint32_t)0x00004000)            /*!< bit 14 */
#define  NVIC_ISPR_SETPEND_15                ((uint32_t)0x00008000)            /*!< bit 15 */
#define  NVIC_ISPR_SETPEND_16                ((uint32_t)0x00010000)            /*!< bit 16 */
#define  NVIC_ISPR_SETPEND_17                ((uint32_t)0x00020000)            /*!< bit 17 */
#define  NVIC_ISPR_SETPEND_18                ((uint32_t)0x00040000)            /*!< bit 18 */
#define  NVIC_ISPR_SETPEND_19                ((uint32_t)0x00080000)            /*!< bit 19 */
#define  NVIC_ISPR_SETPEND_20                ((uint32_t)0x00100000)            /*!< bit 20 */
#define  NVIC_ISPR_SETPEND_21                ((uint32_t)0x00200000)            /*!< bit 21 */
#define  NVIC_ISPR_SETPEND_22                ((uint32_t)0x00400000)            /*!< bit 22 */
#define  NVIC_ISPR_SETPEND_23                ((uint32_t)0x00800000)            /*!< bit 23 */
#define  NVIC_ISPR_SETPEND_24                ((uint32_t)0x01000000)            /*!< bit 24 */
#define  NVIC_ISPR_SETPEND_25                ((uint32_t)0x02000000)            /*!< bit 25 */
#define  NVIC_ISPR_SETPEND_26                ((uint32_t)0x04000000)            /*!< bit 26 */
#define  NVIC_ISPR_SETPEND_27                ((uint32_t)0x08000000)            /*!< bit 27 */
#define  NVIC_ISPR_SETPEND_28                ((uint32_t)0x10000000)            /*!< bit 28 */
#define  NVIC_ISPR_SETPEND_29                ((uint32_t)0x20000000)            /*!< bit 29 */
#define  NVIC_ISPR_SETPEND_30                ((uint32_t)0x40000000)            /*!< bit 30 */
#define  NVIC_ISPR_SETPEND_31                ((uint32_t)0x80000000)            /*!< bit 31 */

/******************  Bit definition for NVIC_ICPR register  *******************/
#define  NVIC_ICPR_CLRPEND                   ((uint32_t)0xFFFFFFFF)            /*!< Interrupt clear-pending bits */
#define  NVIC_ICPR_CLRPEND_0                 ((uint32_t)0x00000001)            /*!< bit 0 */
#define  NVIC_ICPR_CLRPEND_1                 ((uint32_t)0x00000002)            /*!< bit 1 */
#define  NVIC_ICPR_CLRPEND_2                 ((uint32_t)0x00000004)            /*!< bit 2 */
#define  NVIC_ICPR_CLRPEND_3                 ((uint32_t)0x00000008)            /*!< bit 3 */
#define  NVIC_ICPR_CLRPEND_4                 ((uint32_t)0x00000010)            /*!< bit 4 */
#define  NVIC_ICPR_CLRPEND_5                 ((uint32_t)0x00000020)            /*!< bit 5 */
#define  NVIC_ICPR_CLRPEND_6                 ((uint32_t)0x00000040)            /*!< bit 6 */
#define  NVIC_ICPR_CLRPEND_7                 ((uint32_t)0x00000080)            /*!< bit 7 */
#define  NVIC_ICPR_CLRPEND_8                 ((uint32_t)0x00000100)            /*!< bit 8 */
#define  NVIC_ICPR_CLRPEND_9                 ((uint32_t)0x00000200)            /*!< bit 9 */
#define  NVIC_ICPR_CLRPEND_10                ((uint32_t)0x00000400)            /*!< bit 10 */
#define  NVIC_ICPR_CLRPEND_11                ((uint32_t)0x00000800)            /*!< bit 11 */
#define  NVIC_ICPR_CLRPEND_12                ((uint32_t)0x00001000)            /*!< bit 12 */
#define  NVIC_ICPR_CLRPEND_13                ((uint32_t)0x00002000)            /*!< bit 13 */
#define  NVIC_ICPR_CLRPEND_14                ((uint32_t)0x00004000)            /*!< bit 14 */
#define  NVIC_ICPR_CLRPEND_15                ((uint32_t)0x00008000)            /*!< bit 15 */
#define  NVIC_ICPR_CLRPEND_16                ((uint32_t)0x00010000)            /*!< bit 16 */
#define  NVIC_ICPR_CLRPEND_17                ((uint32_t)0x00020000)            /*!< bit 17 */
#define  NVIC_ICPR_CLRPEND_18                ((uint32_t)0x00040000)            /*!< bit 18 */
#define  NVIC_ICPR_CLRPEND_19                ((uint32_t)0x00080000)            /*!< bit 19 */
#define  NVIC_ICPR_CLRPEND_20                ((uint32_t)0x00100000)            /*!< bit 20 */
#define  NVIC_ICPR_CLRPEND_21                ((uint32_t)0x00200000)            /*!< bit 21 */
#define  NVIC_ICPR_CLRPEND_22                ((uint32_t)0x00400000)            /*!< bit 22 */
#define  NVIC_ICPR_CLRPEND_23                ((uint32_t)0x00800000)            /*!< bit 23 */
#define  NVIC_ICPR_CLRPEND_24                ((uint32_t)0x01000000)            /*!< bit 24 */
#define  NVIC_ICPR_CLRPEND_25                ((uint32_t)0x02000000)            /*!< bit 25 */
#define  NVIC_ICPR_CLRPEND_26                ((uint32_t)0x04000000)            /*!< bit 26 */
#define  NVIC_ICPR_CLRPEND_27                ((uint32_t)0x08000000)            /*!< bit 27 */
#define  NVIC_ICPR_CLRPEND_28                ((uint32_t)0x10000000)            /*!< bit 28 */
#define  NVIC_ICPR_CLRPEND_29                ((uint32_t)0x20000000)            /*!< bit 29 */
#define  NVIC_ICPR_CLRPEND_30                ((uint32_t)0x40000000)            /*!< bit 30 */
#define  NVIC_ICPR_CLRPEND_31                ((uint32_t)0x80000000)            /*!< bit 31 */

/******************  Bit definition for NVIC_IABR register  *******************/
#define  NVIC_IABR_ACTIVE                    ((uint32_t)0xFFFFFFFF)            /*!< Interrupt active flags */
#define  NVIC_IABR_ACTIVE_0                  ((uint32_t)0x00000001)            /*!< bit 0 */
#define  NVIC_IABR_ACTIVE_1                  ((uint32_t)0x00000002)            /*!< bit 1 */
#define  NVIC_IABR_ACTIVE_2                  ((uint32_t)0x00000004)            /*!< bit 2 */
#define  NVIC_IABR_ACTIVE_3                  ((uint32_t)0x00000008)            /*!< bit 3 */
#define  NVIC_IABR_ACTIVE_4                  ((uint32_t)0x00000010)            /*!< bit 4 */
#define  NVIC_IABR_ACTIVE_5                  ((uint32_t)0x00000020)            /*!< bit 5 */
#define  NVIC_IABR_ACTIVE_6                  ((uint32_t)0x00000040)            /*!< bit 6 */
#define  NVIC_IABR_ACTIVE_7                  ((uint32_t)0x00000080)            /*!< bit 7 */
#define  NVIC_IABR_ACTIVE_8                  ((uint32_t)0x00000100)            /*!< bit 8 */
#define  NVIC_IABR_ACTIVE_9                  ((uint32_t)0x00000200)            /*!< bit 9 */
#define  NVIC_IABR_ACTIVE_10                 ((uint32_t)0x00000400)            /*!< bit 10 */
#define  NVIC_IABR_ACTIVE_11                 ((uint32_t)0x00000800)            /*!< bit 11 */
#define  NVIC_IABR_ACTIVE_12                 ((uint32_t)0x00001000)            /*!< bit 12 */
#define  NVIC_IABR_ACTIVE_13                 ((uint32_t)0x00002000)            /*!< bit 13 */
#define  NVIC_IABR_ACTIVE_14                 ((uint32_t)0x00004000)            /*!< bit 14 */
#define  NVIC_IABR_ACTIVE_15                 ((uint32_t)0x00008000)            /*!< bit 15 */
#define  NVIC_IABR_ACTIVE_16                 ((uint32_t)0x00010000)            /*!< bit 16 */
#define  NVIC_IABR_ACTIVE_17                 ((uint32_t)0x00020000)            /*!< bit 17 */
#define  NVIC_IABR_ACTIVE_18                 ((uint32_t)0x00040000)            /*!< bit 18 */
#define  NVIC_IABR_ACTIVE_19                 ((uint32_t)0x00080000)            /*!< bit 19 */
#define  NVIC_IABR_ACTIVE_20                 ((uint32_t)0x00100000)            /*!< bit 20 */
#define  NVIC_IABR_ACTIVE_21                 ((uint32_t)0x00200000)            /*!< bit 21 */
#define  NVIC_IABR_ACTIVE_22                 ((uint32_t)0x00400000)            /*!< bit 22 */
#define  NVIC_IABR_ACTIVE_23                 ((uint32_t)0x00800000)            /*!< bit 23 */
#define  NVIC_IABR_ACTIVE_24                 ((uint32_t)0x01000000)            /*!< bit 24 */
#define  NVIC_IABR_ACTIVE_25                 ((uint32_t)0x02000000)            /*!< bit 25 */
#define  NVIC_IABR_ACTIVE_26                 ((uint32_t)0x04000000)            /*!< bit 26 */
#define  NVIC_IABR_ACTIVE_27                 ((uint32_t)0x08000000)            /*!< bit 27 */
#define  NVIC_IABR_ACTIVE_28                 ((uint32_t)0x10000000)            /*!< bit 28 */
#define  NVIC_IABR_ACTIVE_29                 ((uint32_t)0x20000000)            /*!< bit 29 */
#define  NVIC_IABR_ACTIVE_30                 ((uint32_t)0x40000000)            /*!< bit 30 */
#define  NVIC_IABR_ACTIVE_31                 ((uint32_t)0x80000000)            /*!< bit 31 */

/******************  Bit definition for NVIC_PRI0 register  *******************/
#define  NVIC_IPR0_PRI_0                     ((uint32_t)0x000000FF)            /*!< Priority of interrupt 0 */
#define  NVIC_IPR0_PRI_1                     ((uint32_t)0x0000FF00)            /*!< Priority of interrupt 1 */
#define  NVIC_IPR0_PRI_2                     ((uint32_t)0x00FF0000)            /*!< Priority of interrupt 2 */
#define  NVIC_IPR0_PRI_3                     ((uint32_t)0xFF000000)            /*!< Priority of interrupt 3 */

/******************  Bit definition for NVIC_PRI1 register  *******************/
#define  NVIC_IPR1_PRI_4                     ((uint32_t)0x000000FF)            /*!< Priority of interrupt 4 */
#define  NVIC_IPR1_PRI_5                     ((uint32_t)0x0000FF00)            /*!< Priority of interrupt 5 */
#define  NVIC_IPR1_PRI_6                     ((uint32_t)0x00FF0000)            /*!< Priority of interrupt 6 */
#define  NVIC_IPR1_PRI_7                     ((uint32_t)0xFF000000)            /*!< Priority of interrupt 7 */

/******************  Bit definition for NVIC_PRI2 register  *******************/
#define  NVIC_IPR2_PRI_8                     ((uint32_t)0x000000FF)            /*!< Priority of interrupt 8 */
#define  NVIC_IPR2_PRI_9                     ((uint32_t)0x0000FF00)            /*!< Priority of interrupt 9 */
#define  NVIC_IPR2_PRI_10                    ((uint32_t)0x00FF0000)            /*!< Priority of interrupt 10 */
#define  NVIC_IPR2_PRI_11                    ((uint32_t)0xFF000000)            /*!< Priority of interrupt 11 */

/******************  Bit definition for NVIC_PRI3 register  *******************/
#define  NVIC_IPR3_PRI_12                    ((uint32_t)0x000000FF)            /*!< Priority of interrupt 12 */
#define  NVIC_IPR3_PRI_13                    ((uint32_t)0x0000FF00)            /*!< Priority of interrupt 13 */
#define  NVIC_IPR3_PRI_14                    ((uint32_t)0x00FF0000)            /*!< Priority of interrupt 14 */
#define  NVIC_IPR3_PRI_15                    ((uint32_t)0xFF000000)            /*!< Priority of interrupt 15 */

/******************  Bit definition for NVIC_PRI4 register  *******************/
#define  NVIC_IPR4_PRI_16                    ((uint32_t)0x000000FF)            /*!< Priority of interrupt 16 */
#define  NVIC_IPR4_PRI_17                    ((uint32_t)0x0000FF00)            /*!< Priority of interrupt 17 */
#define  NVIC_IPR4_PRI_18                    ((uint32_t)0x00FF0000)            /*!< Priority of interrupt 18 */
#define  NVIC_IPR4_PRI_19                    ((uint32_t)0xFF000000)            /*!< Priority of interrupt 19 */

/******************  Bit definition for NVIC_PRI5 register  *******************/
#define  NVIC_IPR5_PRI_20                    ((uint32_t)0x000000FF)            /*!< Priority of interrupt 20 */
#define  NVIC_IPR5_PRI_21                    ((uint32_t)0x0000FF00)            /*!< Priority of interrupt 21 */
#define  NVIC_IPR5_PRI_22                    ((uint32_t)0x00FF0000)            /*!< Priority of interrupt 22 */
#define  NVIC_IPR5_PRI_23                    ((uint32_t)0xFF000000)            /*!< Priority of interrupt 23 */

/******************  Bit definition for NVIC_PRI6 register  *******************/
#define  NVIC_IPR6_PRI_24                    ((uint32_t)0x000000FF)            /*!< Priority of interrupt 24 */
#define  NVIC_IPR6_PRI_25                    ((uint32_t)0x0000FF00)            /*!< Priority of interrupt 25 */
#define  NVIC_IPR6_PRI_26                    ((uint32_t)0x00FF0000)            /*!< Priority of interrupt 26 */
#define  NVIC_IPR6_PRI_27                    ((uint32_t)0xFF000000)            /*!< Priority of interrupt 27 */

/******************  Bit definition for NVIC_PRI7 register  *******************/
#define  NVIC_IPR7_PRI_28                    ((uint32_t)0x000000FF)            /*!< Priority of interrupt 28 */
#define  NVIC_IPR7_PRI_29                    ((uint32_t)0x0000FF00)            /*!< Priority of interrupt 29 */
#define  NVIC_IPR7_PRI_30                    ((uint32_t)0x00FF0000)            /*!< Priority of interrupt 30 */
#define  NVIC_IPR7_PRI_31                    ((uint32_t)0xFF000000)            /*!< Priority of interrupt 31 */

/******************  Bit definition for SCB_CPUID register  *******************/
#define  SCB_CPUID_REVISION                  ((uint32_t)0x0000000F)            /*!< Implementation defined revision number */
#define  SCB_CPUID_PARTNO                    ((uint32_t)0x0000FFF0)            /*!< Number of processor within family */
#define  SCB_CPUID_Constant                  ((uint32_t)0x000F0000)            /*!< Reads as 0x0F */
#define  SCB_CPUID_VARIANT                   ((uint32_t)0x00F00000)            /*!< Implementation defined variant number */
#define  SCB_CPUID_IMPLEMENTER               ((uint32_t)0xFF000000)            /*!< Implementer code. ARM is 0x41 */

/*******************  Bit definition for SCB_ICSR register  *******************/
#define  SCB_ICSR_VECTACTIVE                 ((uint32_t)0x000001FF)            /*!< Active ISR number field */
#define  SCB_ICSR_RETTOBASE                  ((uint32_t)0x00000800)            /*!< All active exceptions minus the IPSR_current_exception yields the empty set */
#define  SCB_ICSR_VECTPENDING                ((uint32_t)0x003FF000)            /*!< Pending ISR number field */
#define  SCB_ICSR_ISRPENDING                 ((uint32_t)0x00400000)            /*!< Interrupt pending flag */
#define  SCB_ICSR_ISRPREEMPT                 ((uint32_t)0x00800000)            /*!< It indicates that a pending interrupt becomes active in the next running cycle */
#define  SCB_ICSR_PENDSTCLR                  ((uint32_t)0x02000000)            /*!< Clear pending SysTick bit */
#define  SCB_ICSR_PENDSTSET                  ((uint32_t)0x04000000)            /*!< Set pending SysTick bit */
#define  SCB_ICSR_PENDSVCLR                  ((uint32_t)0x08000000)            /*!< Clear pending pendSV bit */
#define  SCB_ICSR_PENDSVSET                  ((uint32_t)0x10000000)            /*!< Set pending pendSV bit */
#define  SCB_ICSR_NMIPENDSET                 ((uint32_t)0x80000000)            /*!< Set pending NMI bit */

/*******************  Bit definition for SCB_VTOR register  *******************/
#define  SCB_VTOR_TBLOFF                     ((uint32_t)0x1FFFFF80)            /*!< Vector table base offset field */
#define  SCB_VTOR_TBLBASE                    ((uint32_t)0x20000000)            /*!< Table base in code(0) or RAM(1) */

/*!<*****************  Bit definition for SCB_AIRCR register  *****************/
#define  SCB_AIRCR_VECTRESET                 ((uint32_t)0x00000001)            /*!< System Reset bit */
#define  SCB_AIRCR_VECTCLRACTIVE             ((uint32_t)0x00000002)            /*!< Clear active vector bit */
#define  SCB_AIRCR_SYSRESETREQ               ((uint32_t)0x00000004)            /*!< Requests chip control logic to generate a reset */

#define  SCB_AIRCR_PRIGROUP                  ((uint32_t)0x00000700)            /*!< PRIGROUP[2:0] bits (Priority group) */
#define  SCB_AIRCR_PRIGROUP_0                ((uint32_t)0x00000100)            /*!< Bit 0 */
#define  SCB_AIRCR_PRIGROUP_1                ((uint32_t)0x00000200)            /*!< Bit 1 */
#define  SCB_AIRCR_PRIGROUP_2                ((uint32_t)0x00000400)            /*!< Bit 2  */

/* prority group configuration */
#define  SCB_AIRCR_PRIGROUP0                 ((uint32_t)0x00000000)            /*!< Priority group=0 (7 bits of pre-emption priority, 1 bit of subpriority) */
#define  SCB_AIRCR_PRIGROUP1                 ((uint32_t)0x00000100)            /*!< Priority group=1 (6 bits of pre-emption priority, 2 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP2                 ((uint32_t)0x00000200)            /*!< Priority group=2 (5 bits of pre-emption priority, 3 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP3                 ((uint32_t)0x00000300)            /*!< Priority group=3 (4 bits of pre-emption priority, 4 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP4                 ((uint32_t)0x00000400)            /*!< Priority group=4 (3 bits of pre-emption priority, 5 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP5                 ((uint32_t)0x00000500)            /*!< Priority group=5 (2 bits of pre-emption priority, 6 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP6                 ((uint32_t)0x00000600)            /*!< Priority group=6 (1 bit of pre-emption priority, 7 bits of subpriority) */
#define  SCB_AIRCR_PRIGROUP7                 ((uint32_t)0x00000700)            /*!< Priority group=7 (no pre-emption priority, 8 bits of subpriority) */

#define  SCB_AIRCR_ENDIANESS                 ((uint32_t)0x00008000)            /*!< Data endianness bit */
#define  SCB_AIRCR_VECTKEY                   ((uint32_t)0xFFFF0000)            /*!< Register key (VECTKEY) - Reads as 0xFA05 (VECTKEYSTAT) */

/*******************  Bit definition for SCB_SCR register  ********************/
#define  SCB_SCR_SLEEPONEXIT                 ((uint8_t)0x02)                   /*!< Sleep on exit bit */
#define  SCB_SCR_SLEEPDEEP                   ((uint8_t)0x04)                   /*!< Sleep deep bit */
#define  SCB_SCR_SEVONPEND                   ((uint8_t)0x10)                   /*!< Wake up from WFE */

/********************  Bit definition for SCB_CCR register  *******************/
#define  SCB_CCR_NONBASETHRDENA              ((uint16_t)0x0001)                /*!< Thread mode can be entered from any level in Handler mode by controlled return value */
#define  SCB_CCR_USERSETMPEND                ((uint16_t)0x0002)                /*!< Enables user code to write the Software Trigger Interrupt register to trigger (pend) a Main exception */
#define  SCB_CCR_UNALIGN_TRP                 ((uint16_t)0x0008)                /*!< Trap for unaligned access */
#define  SCB_CCR_DIV_0_TRP                   ((uint16_t)0x0010)                /*!< Trap on Divide by 0 */
#define  SCB_CCR_BFHFNMIGN                   ((uint16_t)0x0100)                /*!< Handlers running at priority -1 and -2 */
#define  SCB_CCR_STKALIGN                    ((uint16_t)0x0200)                /*!< On exception entry, the SP used prior to the exception is adjusted to be 8-byte aligned */

/*******************  Bit definition for SCB_SHPR register ********************/
#define  SCB_SHPR_PRI_N                      ((uint32_t)0x000000FF)            /*!< Priority of system handler 4,8, and 12. Mem Manage, reserved and Debug Monitor */
#define  SCB_SHPR_PRI_N1                     ((uint32_t)0x0000FF00)            /*!< Priority of system handler 5,9, and 13. Bus Fault, reserved and reserved */
#define  SCB_SHPR_PRI_N2                     ((uint32_t)0x00FF0000)            /*!< Priority of system handler 6,10, and 14. Usage Fault, reserved and PendSV */
#define  SCB_SHPR_PRI_N3                     ((uint32_t)0xFF000000)            /*!< Priority of system handler 7,11, and 15. Reserved, SVCall and SysTick */

/******************  Bit definition for SCB_SHCSR register  *******************/
#define  SCB_SHCSR_MEMFAULTACT               ((uint32_t)0x00000001)            /*!< MemManage is active */
#define  SCB_SHCSR_BUSFAULTACT               ((uint32_t)0x00000002)            /*!< BusFault is active */
#define  SCB_SHCSR_USGFAULTACT               ((uint32_t)0x00000008)            /*!< UsageFault is active */
#define  SCB_SHCSR_SVCALLACT                 ((uint32_t)0x00000080)            /*!< SVCall is active */
#define  SCB_SHCSR_MONITORACT                ((uint32_t)0x00000100)            /*!< Monitor is active */
#define  SCB_SHCSR_PENDSVACT                 ((uint32_t)0x00000400)            /*!< PendSV is active */
#define  SCB_SHCSR_SYSTICKACT                ((uint32_t)0x00000800)            /*!< SysTick is active */
#define  SCB_SHCSR_USGFAULTPENDED            ((uint32_t)0x00001000)            /*!< Usage Fault is pended */
#define  SCB_SHCSR_MEMFAULTPENDED            ((uint32_t)0x00002000)            /*!< MemManage is pended */
#define  SCB_SHCSR_BUSFAULTPENDED            ((uint32_t)0x00004000)            /*!< Bus Fault is pended */
#define  SCB_SHCSR_SVCALLPENDED              ((uint32_t)0x00008000)            /*!< SVCall is pended */
#define  SCB_SHCSR_MEMFAULTENA               ((uint32_t)0x00010000)            /*!< MemManage enable */
#define  SCB_SHCSR_BUSFAULTENA               ((uint32_t)0x00020000)            /*!< Bus Fault enable */
#define  SCB_SHCSR_USGFAULTENA               ((uint32_t)0x00040000)            /*!< UsageFault enable */

/*******************  Bit definition for SCB_CFSR register  *******************/
/*!< MFSR */
#define  SCB_CFSR_IACCVIOL                   ((uint32_t)0x00000001)            /*!< Instruction access violation */
#define  SCB_CFSR_DACCVIOL                   ((uint32_t)0x00000002)            /*!< Data access violation */
#define  SCB_CFSR_MUNSTKERR                  ((uint32_t)0x00000008)            /*!< Unstacking error */
#define  SCB_CFSR_MSTKERR                    ((uint32_t)0x00000010)            /*!< Stacking error */
#define  SCB_CFSR_MMARVALID                  ((uint32_t)0x00000080)            /*!< Memory Manage Address Register address valid flag */
/*!< BFSR */
#define  SCB_CFSR_IBUSERR                    ((uint32_t)0x00000100)            /*!< Instruction bus error flag */
#define  SCB_CFSR_PRECISERR                  ((uint32_t)0x00000200)            /*!< Precise data bus error */
#define  SCB_CFSR_IMPRECISERR                ((uint32_t)0x00000400)            /*!< Imprecise data bus error */
#define  SCB_CFSR_UNSTKERR                   ((uint32_t)0x00000800)            /*!< Unstacking error */
#define  SCB_CFSR_STKERR                     ((uint32_t)0x00001000)            /*!< Stacking error */
#define  SCB_CFSR_BFARVALID                  ((uint32_t)0x00008000)            /*!< Bus Fault Address Register address valid flag */
/*!< UFSR */
#define  SCB_CFSR_UNDEFINSTR                 ((uint32_t)0x00010000)            /*!< The processor attempt to execute an undefined instruction */
#define  SCB_CFSR_INVSTATE                   ((uint32_t)0x00020000)            /*!< Invalid combination of EPSR and instruction */
#define  SCB_CFSR_INVPC                      ((uint32_t)0x00040000)            /*!< Attempt to load EXC_RETURN into pc illegally */
#define  SCB_CFSR_NOCP                       ((uint32_t)0x00080000)            /*!< Attempt to use a coprocessor instruction */
#define  SCB_CFSR_UNALIGNED                  ((uint32_t)0x01000000)            /*!< Fault occurs when there is an attempt to make an unaligned memory access */
#define  SCB_CFSR_DIVBYZERO                  ((uint32_t)0x02000000)            /*!< Fault occurs when SDIV or DIV instruction is used with a divisor of 0 */

/*******************  Bit definition for SCB_HFSR register  *******************/
#define  SCB_HFSR_VECTTBL                    ((uint32_t)0x00000002)            /*!< Fault occurs because of vector table read on exception processing */
#define  SCB_HFSR_FORCED                     ((uint32_t)0x40000000)            /*!< Hard Fault activated when a configurable Fault was received and cannot activate */
#define  SCB_HFSR_DEBUGEVT                   ((uint32_t)0x80000000)            /*!< Fault related to debug */

/*******************  Bit definition for SCB_DFSR register  *******************/
#define  SCB_DFSR_HALTED                     ((uint8_t)0x01)                   /*!< Halt request flag */
#define  SCB_DFSR_BKPT                       ((uint8_t)0x02)                   /*!< BKPT flag */
#define  SCB_DFSR_DWTTRAP                    ((uint8_t)0x04)                   /*!< Data Watchpoint and Trace (DWT) flag */
#define  SCB_DFSR_VCATCH                     ((uint8_t)0x08)                   /*!< Vector catch flag */
#define  SCB_DFSR_EXTERNAL                   ((uint8_t)0x10)                   /*!< External debug request flag */

/*******************  Bit definition for SCB_MMFAR register  ******************/
#define  SCB_MMFAR_ADDRESS                   ((uint32_t)0xFFFFFFFF)            /*!< Mem Manage fault address field */

/*******************  Bit definition for SCB_BFAR register  *******************/
#define  SCB_BFAR_ADDRESS                    ((uint32_t)0xFFFFFFFF)            /*!< Bus fault address field */

/*******************  Bit definition for SCB_afsr register  *******************/
#define  SCB_AFSR_IMPDEF                     ((uint32_t)0xFFFFFFFF)            /*!< Implementation defined */


/******************************************************************************/
/*                                                                            */
/*                 External Interrupt/Event Controller (EXTI)                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for EXTI_IER register  *******************/
#define  EXTI_IER_IER0                       ((uint32_t)0x00000001)            /*!< Interrupt Enable Control on line 0 */
#define  EXTI_IER_IER1                       ((uint32_t)0x00000002)            /*!< Interrupt Enable Control on line 1 */
#define  EXTI_IER_IER2                       ((uint32_t)0x00000004)            /*!< Interrupt Enable Control on line 2 */
#define  EXTI_IER_IER3                       ((uint32_t)0x00000008)            /*!< Interrupt Enable Control on line 3 */
#define  EXTI_IER_IER4                       ((uint32_t)0x00000010)            /*!< Interrupt Enable Control on line 4 */
#define  EXTI_IER_IER5                       ((uint32_t)0x00000020)            /*!< Interrupt Enable Control on line 5 */
#define  EXTI_IER_IER6                       ((uint32_t)0x00000040)            /*!< Interrupt Enable Control on line 6 */
#define  EXTI_IER_IER7                       ((uint32_t)0x00000080)            /*!< Interrupt Enable Control on line 7 */
#define  EXTI_IER_IER8                       ((uint32_t)0x00000100)            /*!< Interrupt Enable Control on line 8 */
#define  EXTI_IER_IER9                       ((uint32_t)0x00000200)            /*!< Interrupt Enable Control on line 9 */
#define  EXTI_IER_IER10                      ((uint32_t)0x00000400)            /*!< Interrupt Enable Control on line 10 */
#define  EXTI_IER_IER11                      ((uint32_t)0x00000800)            /*!< Interrupt Enable Control on line 11 */
#define  EXTI_IER_IER12                      ((uint32_t)0x00001000)            /*!< Interrupt Enable Control on line 12 */
#define  EXTI_IER_IER13                      ((uint32_t)0x00002000)            /*!< Interrupt Enable Control on line 13 */
#define  EXTI_IER_IER14                      ((uint32_t)0x00004000)            /*!< Interrupt Enable Control on line 14 */
#define  EXTI_IER_IER15                      ((uint32_t)0x00008000)            /*!< Interrupt Enable Control on line 15 */
#define  EXTI_IER_IER16                      ((uint32_t)0x00010000)            /*!< Interrupt Enable Control on line 16 */
#define  EXTI_IER_IER17                      ((uint32_t)0x00020000)            /*!< Interrupt Enable Control on line 17 */

#ifdef GD32F130_150
#define  EXTI_IER_IER18                      ((uint32_t)0x00040000)            /*!< Interrupt Enable Control on line 18 */
#endif

#define  EXTI_IER_IER19                      ((uint32_t)0x00080000)            /*!< Interrupt Enable Control on line 19 */
#define  EXTI_IER_IER21                      ((uint32_t)0x00200000)            /*!< Interrupt Enable Control on line 21 */
#define  EXTI_IER_IER22                      ((uint32_t)0x00400000)            /*!< Interrupt Enable Control on line 22 */
#define  EXTI_IER_IER25                      ((uint32_t)0x02000000)            /*!< Interrupt Enable Control on line 25 */
#define  EXTI_IER_IER27                      ((uint32_t)0x08000000)            /*!< Interrupt Enable Control on line 27 */

/******************  Bit definition for EXTI_EER register  ********************/
#define  EXTI_EER_EER0                       ((uint32_t)0x00000001)            /*!< Event Enable Control on line 0 */
#define  EXTI_EER_EER1                       ((uint32_t)0x00000002)            /*!< Event Enable Control on line 1 */
#define  EXTI_EER_EER2                       ((uint32_t)0x00000004)            /*!< Event Enable Control on line 2 */
#define  EXTI_EER_EER3                       ((uint32_t)0x00000008)            /*!< Event Enable Control on line 3 */
#define  EXTI_EER_EER4                       ((uint32_t)0x00000010)            /*!< Event Enable Control on line 4 */
#define  EXTI_EER_EER5                       ((uint32_t)0x00000020)            /*!< Event Enable Control on line 5 */
#define  EXTI_EER_EER6                       ((uint32_t)0x00000040)            /*!< Event Enable Control on line 6 */
#define  EXTI_EER_EER7                       ((uint32_t)0x00000080)            /*!< Event Enable Control on line 7 */
#define  EXTI_EER_EER8                       ((uint32_t)0x00000100)            /*!< Event Enable Control on line 8 */
#define  EXTI_EER_EER9                       ((uint32_t)0x00000200)            /*!< Event Enable Control on line 9 */
#define  EXTI_EER_EER10                      ((uint32_t)0x00000400)            /*!< Event Enable Control on line 10 */
#define  EXTI_EER_EER11                      ((uint32_t)0x00000800)            /*!< Event Enable Control on line 11 */
#define  EXTI_EER_EER12                      ((uint32_t)0x00001000)            /*!< Event Enable Control on line 12 */
#define  EXTI_EER_EER13                      ((uint32_t)0x00002000)            /*!< Event Enable Control on line 13 */
#define  EXTI_EER_EER14                      ((uint32_t)0x00004000)            /*!< Event Enable Control on line 14 */
#define  EXTI_EER_EER15                      ((uint32_t)0x00008000)            /*!< Event Enable Control on line 15 */
#define  EXTI_EER_EER16                      ((uint32_t)0x00010000)            /*!< Event Enable Control on line 16 */
#define  EXTI_EER_EER17                      ((uint32_t)0x00020000)            /*!< Event Enable Control on line 17 */

#ifdef GD32F130_150
#define  EXTI_EER_EER18                      ((uint32_t)0x00040000)            /*!< Event Enable Control on line 18 */
#endif

#define  EXTI_EER_EER19                      ((uint32_t)0x00080000)            /*!< Event Enable Control on line 19 */
#define  EXTI_EER_EER21                      ((uint32_t)0x00200000)            /*!< Event Enable Control on line 21 */
#define  EXTI_EER_EER22                      ((uint32_t)0x00400000)            /*!< Event Enable Control on line 22 */
#define  EXTI_EER_EER25                      ((uint32_t)0x02000000)            /*!< Event Enable Control on line 25 */
#define  EXTI_EER_EER27                      ((uint32_t)0x08000000)            /*!< Event Enable Control on line 27 */

/*******************  Bit definition for EXTI_RTE register  *******************/
#define  EXTI_RTE_RTE0                       ((uint32_t)0x00000001)            /*!< Rising Edge Trigger Enabled for line 0 */
#define  EXTI_RTE_RTE1                       ((uint32_t)0x00000002)            /*!< Rising Edge Trigger Enabled for line 1 */
#define  EXTI_RTE_RTE2                       ((uint32_t)0x00000004)            /*!< Rising Edge Trigger Enabled for line 2 */
#define  EXTI_RTE_RTE3                       ((uint32_t)0x00000008)            /*!< Rising Edge Trigger Enabled for line 3 */
#define  EXTI_RTE_RTE4                       ((uint32_t)0x00000010)            /*!< Rising Edge Trigger Enabled for line 4 */
#define  EXTI_RTE_RTE5                       ((uint32_t)0x00000020)            /*!< Rising Edge Trigger Enabled for line 5 */
#define  EXTI_RTE_RTE6                       ((uint32_t)0x00000040)            /*!< Rising Edge Trigger Enabled for line 6 */
#define  EXTI_RTE_RTE7                       ((uint32_t)0x00000080)            /*!< Rising Edge Trigger Enabled for line 7 */
#define  EXTI_RTE_RTE8                       ((uint32_t)0x00000100)            /*!< Rising Edge Trigger Enabled for line 8 */
#define  EXTI_RTE_RTE9                       ((uint32_t)0x00000200)            /*!< Rising Edge Trigger Enabled for line 9 */
#define  EXTI_RTE_RTE10                      ((uint32_t)0x00000400)            /*!< Rising Edge Trigger Enabled for line 10 */
#define  EXTI_RTE_RTE11                      ((uint32_t)0x00000800)            /*!< Rising Edge Trigger Enabled for line 11 */
#define  EXTI_RTE_RTE12                      ((uint32_t)0x00001000)            /*!< Rising Edge Trigger Enabled for line 12 */
#define  EXTI_RTE_RTE13                      ((uint32_t)0x00002000)            /*!< Rising Edge Trigger Enabled for line 13 */
#define  EXTI_RTE_RTE14                      ((uint32_t)0x00004000)            /*!< Rising Edge Trigger Enabled for line 14 */
#define  EXTI_RTE_RTE15                      ((uint32_t)0x00008000)            /*!< Rising Edge Trigger Enabled for line 15 */
#define  EXTI_RTE_RTE16                      ((uint32_t)0x00010000)            /*!< Rising Edge Trigger Enabled for line 16 */
#define  EXTI_RTE_RTE17                      ((uint32_t)0x00020000)            /*!< Rising Edge Trigger Enabled for line 17 */

#ifdef GD32F130_150
#define  EXTI_RTE_RTE18                      ((uint32_t)0x00040000)            /*!< Rising Edge Trigger Enabled for line 18 */
#endif

#define  EXTI_RTE_RTE19                      ((uint32_t)0x00080000)            /*!< Rising Edge Trigger Enabled for line 19 */
#define  EXTI_RTE_RTE21                      ((uint32_t)0x00200000)            /*!< Rising Edge Trigger Enabled for line 21 */
#define  EXTI_RTE_RTE22                      ((uint32_t)0x00400000)            /*!< Rising Edge Trigger Enabled for line 22 */

/*******************  Bit definition for EXTI_FTE register ********************/
#define  EXTI_FTE_FTE0                       ((uint32_t)0x00000001)            /*!< Falling Edge Trigger Enabled for line 0 */
#define  EXTI_FTE_FTE1                       ((uint32_t)0x00000002)            /*!< Falling Edge Trigger Enabled for line 1 */
#define  EXTI_FTE_FTE2                       ((uint32_t)0x00000004)            /*!< Falling Edge Trigger Enabled for line 2 */
#define  EXTI_FTE_FTE3                       ((uint32_t)0x00000008)            /*!< Falling Edge Trigger Enabled for line 3 */
#define  EXTI_FTE_FTE4                       ((uint32_t)0x00000010)            /*!< Falling Edge Trigger Enabled for line 4 */
#define  EXTI_FTE_FTE5                       ((uint32_t)0x00000020)            /*!< Falling Edge Trigger Enabled for line 5 */
#define  EXTI_FTE_FTE6                       ((uint32_t)0x00000040)            /*!< Falling Edge Trigger Enabled for line 6 */
#define  EXTI_FTE_FTE7                       ((uint32_t)0x00000080)            /*!< Falling Edge Trigger Enabled for line 7 */
#define  EXTI_FTE_FTE8                       ((uint32_t)0x00000100)            /*!< Falling Edge Trigger Enabled for line 8 */
#define  EXTI_FTE_FTE9                       ((uint32_t)0x00000200)            /*!< Falling Edge Trigger Enabled for line 9 */
#define  EXTI_FTE_FTE10                      ((uint32_t)0x00000400)            /*!< Falling Edge Trigger Enabled for line 10 */
#define  EXTI_FTE_FTE11                      ((uint32_t)0x00000800)            /*!< Falling Edge Trigger Enabled for line 11 */
#define  EXTI_FTE_FTE12                      ((uint32_t)0x00001000)            /*!< Falling Edge Trigger Enabled for line 12 */
#define  EXTI_FTE_FTE13                      ((uint32_t)0x00002000)            /*!< Falling Edge Trigger Enabled for line 13 */
#define  EXTI_FTE_FTE14                      ((uint32_t)0x00004000)            /*!< Falling Edge Trigger Enabled for line 14 */
#define  EXTI_FTE_FTE15                      ((uint32_t)0x00008000)            /*!< Falling Edge Trigger Enabled for line 15 */
#define  EXTI_FTE_FTE16                      ((uint32_t)0x00010000)            /*!< Falling Edge Trigger Enabled for line 16 */
#define  EXTI_FTE_FTE17                      ((uint32_t)0x00020000)            /*!< Falling Edge Trigger Enabled for line 17 */

#ifdef GD32F130_150
#define  EXTI_FTE_FTE18                      ((uint32_t)0x00040000)            /*!< Falling Edge Trigger Enabled for line 18 */
#endif

#define  EXTI_FTE_FTE19                      ((uint32_t)0x00080000)            /*!< Falling Edge Trigger Enabled for line 19 */
#define  EXTI_FTE_FTE21                      ((uint32_t)0x00200000)            /*!< Falling Edge Trigger Enabled for line 21 */
#define  EXTI_FTE_FTE22                      ((uint32_t)0x00400000)            /*!< Falling Edge Trigger Enabled for line 22 */

/******************* Bit definition for EXTI_SIE register *********************/
#define  EXTI_SIE_SIE0                       ((uint32_t)0x00000001)            /*!< Interrupt/Event Software Trigger on line 0 */
#define  EXTI_SIE_SIE1                       ((uint32_t)0x00000002)            /*!< Interrupt/Event Software Trigger on line 1 */
#define  EXTI_SIE_SIE2                       ((uint32_t)0x00000004)            /*!< Interrupt/Event Software Trigger on line 2 */
#define  EXTI_SIE_SIE3                       ((uint32_t)0x00000008)            /*!< Interrupt/Event Software Trigger on line 3 */
#define  EXTI_SIE_SIE4                       ((uint32_t)0x00000010)            /*!< Interrupt/Event Software Trigger on line 4 */
#define  EXTI_SIE_SIE5                       ((uint32_t)0x00000020)            /*!< Interrupt/Event Software Trigger on line 5 */
#define  EXTI_SIE_SIE6                       ((uint32_t)0x00000040)            /*!< Interrupt/Event Software Trigger on line 6 */
#define  EXTI_SIE_SIE7                       ((uint32_t)0x00000080)            /*!< Interrupt/Event Software Trigger on line 7 */
#define  EXTI_SIE_SIE8                       ((uint32_t)0x00000100)            /*!< Interrupt/Event Software Trigger on line 8 */
#define  EXTI_SIE_SIE9                       ((uint32_t)0x00000200)            /*!< Interrupt/Event Software Trigger on line 9 */
#define  EXTI_SIE_SIE10                      ((uint32_t)0x00000400)            /*!< Interrupt/Event Software Trigger on line 10 */
#define  EXTI_SIE_SIE11                      ((uint32_t)0x00000800)            /*!< Interrupt/Event Software Trigger on line 11 */
#define  EXTI_SIE_SIE12                      ((uint32_t)0x00001000)            /*!< Interrupt/Event Software Trigger on line 12 */
#define  EXTI_SIE_SIE13                      ((uint32_t)0x00002000)            /*!< Interrupt/Event Software Trigger on line 13 */
#define  EXTI_SIE_SIE14                      ((uint32_t)0x00004000)            /*!< Interrupt/Event Software Trigger on line 14 */
#define  EXTI_SIE_SIE15                      ((uint32_t)0x00008000)            /*!< Interrupt/Event Software Trigger on line 15 */
#define  EXTI_SIE_SIE16                      ((uint32_t)0x00010000)            /*!< Interrupt/Event Software Trigger on line 16 */
#define  EXTI_SIE_SIE17                      ((uint32_t)0x00020000)            /*!< Interrupt/Event Software Trigger on line 17 */

#ifdef GD32F130_150
#define  EXTI_SIE_SIE18                      ((uint32_t)0x00040000)            /*!< Interrupt/Event Software Trigger on line 18 */
#endif

#define  EXTI_SIE_SIE19                      ((uint32_t)0x00080000)            /*!< Interrupt/Event Software Trigger on line 19 */
#define  EXTI_SIE_SIE21                      ((uint32_t)0x00200000)            /*!< Interrupt/Event Software Trigger on line 21 */
#define  EXTI_SIE_SIE22                      ((uint32_t)0x00400000)            /*!< Interrupt/Event Software Trigger on line 22 */

/******************  Bit definition for EXTI_PD register  *********************/
#define  EXTI_PD_PD0                         ((uint32_t)0x00000001)            /*!< Interrupt/Event Pending Status on line 0 */
#define  EXTI_PD_PD1                         ((uint32_t)0x00000002)            /*!< Interrupt/Event Pending Status on line 1 */
#define  EXTI_PD_PD2                         ((uint32_t)0x00000004)            /*!< Interrupt/Event Pending Status on line 2 */
#define  EXTI_PD_PD3                         ((uint32_t)0x00000008)            /*!< Interrupt/Event Pending Status on line 3 */
#define  EXTI_PD_PD4                         ((uint32_t)0x00000010)            /*!< Interrupt/Event Pending Status on line 4 */
#define  EXTI_PD_PD5                         ((uint32_t)0x00000020)            /*!< Interrupt/Event Pending Status on line 5 */
#define  EXTI_PD_PD6                         ((uint32_t)0x00000040)            /*!< Interrupt/Event Pending Status on line 6 */
#define  EXTI_PD_PD7                         ((uint32_t)0x00000080)            /*!< Interrupt/Event Pending Status on line 7 */
#define  EXTI_PD_PD8                         ((uint32_t)0x00000100)            /*!< Interrupt/Event Pending Status on line 8 */
#define  EXTI_PD_PD9                         ((uint32_t)0x00000200)            /*!< Interrupt/Event Pending Status on line 9 */
#define  EXTI_PD_PD10                        ((uint32_t)0x00000400)            /*!< Interrupt/Event Pending Status on line 10 */
#define  EXTI_PD_PD11                        ((uint32_t)0x00000800)            /*!< Interrupt/Event Pending Status on line 11 */
#define  EXTI_PD_PD12                        ((uint32_t)0x00001000)            /*!< Interrupt/Event Pending Status on line 12 */
#define  EXTI_PD_PD13                        ((uint32_t)0x00002000)            /*!< Interrupt/Event Pending Status on line 13 */
#define  EXTI_PD_PD14                        ((uint32_t)0x00004000)            /*!< Interrupt/Event Pending Status on line 14 */
#define  EXTI_PD_PD15                        ((uint32_t)0x00008000)            /*!< Interrupt/Event Pending Status on line 15 */
#define  EXTI_PD_PD16                        ((uint32_t)0x00010000)            /*!< Interrupt/Event Pending Status on line 16 */
#define  EXTI_PD_PD17                        ((uint32_t)0x00020000)            /*!< Interrupt/Event Pending Status on line 17 */

#ifdef GD32F130_150
#define  EXTI_PD_PD18                        ((uint32_t)0x00040000)            /*!< Interrupt/Event Pending Status on line 18 */
#endif

#define  EXTI_PD_PD19                        ((uint32_t)0x00080000)            /*!< Interrupt/Event Pending Status on line 19 */
#define  EXTI_PD_PD21                        ((uint32_t)0x00200000)            /*!< Interrupt/Event Pending Status on line 21 */
#define  EXTI_PD_PD22                        ((uint32_t)0x00400000)            /*!< Interrupt/Event Pending Status on line 22 */


/******************************************************************************/
/*                                                                            */
/*                      FMC Registers                                         */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for FMC_RESR register  *******************/
#define  FMC_RESR_WSCNT                      ((uint32_t)0x00000007)            /*!< LATENCY bit (Latency) */

/******************  Bit definition for FMC_UKEYR register  *******************/
#define  FMC_UKEYR_UKEY                      ((uint32_t)0xFFFFFFFF)            /*!< FPEC Key */

/*****************  Bit definition for FMC_OBKEYR register  *******************/
#define  FMC_OBKEYR_OBKEY                    ((uint32_t)0xFFFFFFFF)            /*!< Option Byte Key */

/******************  FMC Keys  ************************************************/
#define  FMC_KEY1                            ((uint32_t)0x45670123)            /*!< Flash program erase key1 */
#define  FMC_KEY2                            ((uint32_t)0xCDEF89AB)            /*!< Flash program erase key2 */

/******************  Bit definition for FMC_CSR register  *********************/
#define  FMC_CSR_BUSY                        ((uint32_t)0x00000001)            /*!< Busy */
#define  FMC_CSR_PGEF                        ((uint32_t)0x00000004)            /*!< Programming Error */
#define  FMC_CSR_WPEF                        ((uint32_t)0x00000010)            /*!< Write Protection Error */
#define  FMC_CSR_ENDF                        ((uint32_t)0x00000020)            /*!< End of operation */

/*******************  Bit definition for FMC_CMR register  ********************/
#define  FMC_CMR_PG                          ((uint32_t)0x00000001)            /*!< Programming */
#define  FMC_CMR_PE                          ((uint32_t)0x00000002)            /*!< Page Erase */
#define  FMC_CMR_ME                          ((uint32_t)0x00000004)            /*!< Mass Erase */
#define  FMC_CMR_OBPG                        ((uint32_t)0x00000010)            /*!< Option Byte Programming */
#define  FMC_CMR_OBER                        ((uint32_t)0x00000020)            /*!< Option Byte Erase */
#define  FMC_CMR_START                       ((uint32_t)0x00000040)            /*!< Start */
#define  FMC_CMR_LK                          ((uint32_t)0x00000080)            /*!< Lock */
#define  FMC_CMR_OBWE                        ((uint32_t)0x00000200)            /*!< Option Bytes Write Enable */
#define  FMC_CMR_ERIE                        ((uint32_t)0x00000400)            /*!< Error Interrupt Enable */
#define  FMC_CMR_ENDIE                       ((uint32_t)0x00001000)            /*!< End of operation interrupt enable */
#define  FMC_CMR_OPTR                        ((uint32_t)0x00002000)            /*!< Option Bytes Loader Launch */

/*******************  Bit definition for FMC_AR register  *********************/
#define  FMC_AR_AR                           ((uint32_t)0xFFFFFFFF)            /*!< Flash Address */

/******************  Bit definition for FMC_OPTR register  ********************/
#define  FMC_OPTR_OBER                       ((uint32_t)0x00000001)            /*!< Option Byte Error */
#define  FMC_OPTR_PLEVEL1                    ((uint32_t)0x00000002)            /*!< Read protection Level 1 */
#define  FMC_OPTR_PLEVEL2                    ((uint32_t)0x00000004)            /*!< Read protection Level 2 */

#define  FMC_OPTR_OB_USER                    ((uint32_t)0x00003700)            /*!< User Option Bytes */

/******************  Bit definition for FMC_WPR register  *********************/
#define  FMC_WPR_WRP                         ((uint32_t)0x0000FFFF)            /*!< Write Protect */

/******************  Bit definition for FMC_WSCR register  ********************/
#define  FMC_WSCR_WSEN                       ((uint32_t)0x00000001)            /*!< Wait state enable */
#define  FMC_WSCR_BPEN                       ((uint32_t)0x00000002)            /*!< Bit program enable */
/*----------------------------------------------------------------------------*/

/******************  Bit definition for OB_RDP register  **********************/
#define  OB_RDP_RDP                          ((uint32_t)0x000000FF)            /*!< Read protection option byte */
#define  OB_RDP_nRDP                         ((uint32_t)0x0000FF00)            /*!< Read protection complemented option byte */

/******************  Bit definition for OB_USER register  *********************/
#define  OB_USER_USER                        ((uint32_t)0x00FF0000)            /*!< User option byte */
#define  OB_USER_nUSER                       ((uint32_t)0xFF000000)            /*!< User complemented option byte */

/******************  Bit definition for OB_WRP0 register  *********************/
#define  OB_WRP0_WRP0                        ((uint32_t)0x000000FF)            /*!< Flash memory write protection option bytes */
#define  OB_WRP0_nWRP0                       ((uint32_t)0x0000FF00)            /*!< Flash memory write protection complemented option bytes */

/******************  Bit definition for OB_WRP1 register  *********************/
#define  OB_WRP1_WRP1                        ((uint32_t)0x00FF0000)            /*!< Flash memory write protection option bytes */
#define  OB_WRP1_nWRP1                       ((uint32_t)0xFF000000)            /*!< Flash memory write protection complemented option bytes */

/******************************************************************************/
/*                                                                            */
/*                       General Purpose IOs (GPIO)                           */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for GPIO_CTLR register  ******************/
#define  GPIO_CTLR_CTLR0                     ((uint32_t)0x00000003)            /*!< Pin 0 mode bits */
#define  GPIO_CTLR_CTLR0_0                   ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR0_1                   ((uint32_t)0x00000002)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR1                     ((uint32_t)0x0000000C)            /*!< Pin 1 mode bits */
#define  GPIO_CTLR_CTLR1_0                   ((uint32_t)0x00000004)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR1_1                   ((uint32_t)0x00000008)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR2                     ((uint32_t)0x00000030)            /*!< Pin 2 mode bits */
#define  GPIO_CTLR_CTLR2_0                   ((uint32_t)0x00000010)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR2_1                   ((uint32_t)0x00000020)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR3                     ((uint32_t)0x000000C0)            /*!< Pin 3 mode bits */
#define  GPIO_CTLR_CTLR3_0                   ((uint32_t)0x00000040)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR3_1                   ((uint32_t)0x00000080)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR4                     ((uint32_t)0x00000300)            /*!< Pin 4 mode bits */
#define  GPIO_CTLR_CTLR4_0                   ((uint32_t)0x00000100)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR4_1                   ((uint32_t)0x00000200)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR5                     ((uint32_t)0x00000C00)            /*!< Pin 5 mode bits */
#define  GPIO_CTLR_CTLR5_0                   ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR5_1                   ((uint32_t)0x00000800)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR6                     ((uint32_t)0x00003000)            /*!< Pin 6 mode bits */
#define  GPIO_CTLR_CTLR6_0                   ((uint32_t)0x00001000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR6_1                   ((uint32_t)0x00002000)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR7                     ((uint32_t)0x0000C000)            /*!< Pin 7 mode bits */
#define  GPIO_CTLR_CTLR7_0                   ((uint32_t)0x00004000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR7_1                   ((uint32_t)0x00008000)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR8                     ((uint32_t)0x00030000)            /*!< Pin 8 mode bits */
#define  GPIO_CTLR_CTLR8_0                   ((uint32_t)0x00010000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR8_1                   ((uint32_t)0x00020000)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR9                     ((uint32_t)0x000C0000)            /*!< Pin 9 mode bits */
#define  GPIO_CTLR_CTLR9_0                   ((uint32_t)0x00040000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR9_1                   ((uint32_t)0x00080000)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR10                    ((uint32_t)0x00300000)            /*!< Pin 10 mode bits */
#define  GPIO_CTLR_CTLR10_0                  ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR10_1                  ((uint32_t)0x00200000)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR11                    ((uint32_t)0x00C00000)            /*!< Pin 11 mode bits */
#define  GPIO_CTLR_CTLR11_0                  ((uint32_t)0x00400000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR11_1                  ((uint32_t)0x00800000)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR12                    ((uint32_t)0x03000000)            /*!< Pin 12 mode bits */
#define  GPIO_CTLR_CTLR12_0                  ((uint32_t)0x01000000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR12_1                  ((uint32_t)0x02000000)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR13                    ((uint32_t)0x0C000000)            /*!< Pin 13 mode bits */
#define  GPIO_CTLR_CTLR13_0                  ((uint32_t)0x04000000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR13_1                  ((uint32_t)0x08000000)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR14                    ((uint32_t)0x30000000)            /*!< Pin 14 mode bits */
#define  GPIO_CTLR_CTLR14_0                  ((uint32_t)0x10000000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR14_1                  ((uint32_t)0x20000000)            /*!< Bit 1 */

#define  GPIO_CTLR_CTLR15                    ((uint32_t)0xC0000000)            /*!< Pin 15 mode bits */
#define  GPIO_CTLR_CTLR15_0                  ((uint32_t)0x40000000)            /*!< Bit 0 */
#define  GPIO_CTLR_CTLR15_1                  ((uint32_t)0x80000000)            /*!< Bit 1 */

/******************  Bit definition for GPIO_OMODE register  ******************/
#define  GPIO_OMODE_OM0                      ((uint32_t)0x00000001)            /*!< Pin 0 OutPut mode bit */
#define  GPIO_OMODE_OM1                      ((uint32_t)0x00000002)            /*!< Pin 1 OutPut mode bit */
#define  GPIO_OMODE_OM2                      ((uint32_t)0x00000004)            /*!< Pin 2 OutPut mode bit */
#define  GPIO_OMODE_OM3                      ((uint32_t)0x00000008)            /*!< Pin 3 OutPut mode bit */
#define  GPIO_OMODE_OM4                      ((uint32_t)0x00000010)            /*!< Pin 4 OutPut mode bit */
#define  GPIO_OMODE_OM5                      ((uint32_t)0x00000020)            /*!< Pin 5 OutPut mode bit */
#define  GPIO_OMODE_OM6                      ((uint32_t)0x00000040)            /*!< Pin 6 OutPut mode bit */
#define  GPIO_OMODE_OM7                      ((uint32_t)0x00000080)            /*!< Pin 7 OutPut mode bit */
#define  GPIO_OMODE_OM8                      ((uint32_t)0x00000100)            /*!< Pin 8 OutPut mode bit */
#define  GPIO_OMODE_OM9                      ((uint32_t)0x00000200)            /*!< Pin 9 OutPut mode bit */
#define  GPIO_OMODE_OM10                     ((uint32_t)0x00000400)            /*!< Pin 10 OutPut mode bit */
#define  GPIO_OMODE_OM11                     ((uint32_t)0x00000800)            /*!< Pin 11 OutPut mode bit */
#define  GPIO_OMODE_OM12                     ((uint32_t)0x00001000)            /*!< Pin 12 OutPut mode bit */
#define  GPIO_OMODE_OM13                     ((uint32_t)0x00002000)            /*!< Pin 13 OutPut mode bit */
#define  GPIO_OMODE_OM14                     ((uint32_t)0x00004000)            /*!< Pin 14 OutPut mode bit */
#define  GPIO_OMODE_OM15                     ((uint32_t)0x00008000)            /*!< Pin 15 OutPut mode bit */

/****************  Bit definition for GPIO_OSPD register  *********************/
#define  GPIO_OSPD_OSPD0                     ((uint32_t)0x00000003)            /*!< Pin 0 Max Speed bits */
#define  GPIO_OSPD_OSPD0_0                   ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD0_1                   ((uint32_t)0x00000002)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD1                     ((uint32_t)0x0000000C)            /*!< Pin 1 Max Speed bits */
#define  GPIO_OSPD_OSPD1_0                   ((uint32_t)0x00000004)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD1_1                   ((uint32_t)0x00000008)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD2                     ((uint32_t)0x00000030)            /*!< Pin 2 Max Speed bits */
#define  GPIO_OSPD_OSPD2_0                   ((uint32_t)0x00000010)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD2_1                   ((uint32_t)0x00000020)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD3                     ((uint32_t)0x000000C0)            /*!< Pin 3 Max Speed bits */
#define  GPIO_OSPD_OSPD3_0                   ((uint32_t)0x00000040)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD3_1                   ((uint32_t)0x00000080)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD4                     ((uint32_t)0x00000300)            /*!< Pin 4 Max Speed bits */
#define  GPIO_OSPD_OSPD4_0                   ((uint32_t)0x00000100)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD4_1                   ((uint32_t)0x00000200)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD5                     ((uint32_t)0x00000C00)            /*!< Pin 5 Max Speed bits */
#define  GPIO_OSPD_OSPD5_0                   ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD5_1                   ((uint32_t)0x00000800)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD6                     ((uint32_t)0x00003000)            /*!< Pin 6 Max Speed bits */
#define  GPIO_OSPD_OSPD6_0                   ((uint32_t)0x00001000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD6_1                   ((uint32_t)0x00002000)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD7                     ((uint32_t)0x0000C000)            /*!< Pin 7 Max Speed bits */
#define  GPIO_OSPD_OSPD7_0                   ((uint32_t)0x00004000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD7_1                   ((uint32_t)0x00008000)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD8                     ((uint32_t)0x00030000)            /*!< Pin 8 Max Speed bits */
#define  GPIO_OSPD_OSPD8_0                   ((uint32_t)0x00010000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD8_1                   ((uint32_t)0x00020000)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD9                     ((uint32_t)0x000C0000)            /*!< Pin 9 Max Speed bits */
#define  GPIO_OSPD_OSPD9_0                   ((uint32_t)0x00040000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD9_1                   ((uint32_t)0x00080000)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD10                    ((uint32_t)0x00300000)            /*!< Pin 10 Max Speed bits */
#define  GPIO_OSPD_OSPD10_0                  ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD10_1                  ((uint32_t)0x00200000)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD11                    ((uint32_t)0x00C00000)            /*!< Pin 11 Max Speed bits */
#define  GPIO_OSPD_OSPD11_0                  ((uint32_t)0x00400000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD11_1                  ((uint32_t)0x00800000)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD12                    ((uint32_t)0x03000000)            /*!< Pin 12 Max Speed bits */
#define  GPIO_OSPD_OSPD12_0                  ((uint32_t)0x01000000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD12_1                  ((uint32_t)0x02000000)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD13                    ((uint32_t)0x0C000000)            /*!< Pin 13 Max Speed bits */
#define  GPIO_OSPD_OSPD13_0                  ((uint32_t)0x04000000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD13_1                  ((uint32_t)0x08000000)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD14                    ((uint32_t)0x30000000)            /*!< Pin 14 Max Speed bits */
#define  GPIO_OSPD_OSPD14_0                  ((uint32_t)0x10000000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD14_1                  ((uint32_t)0x20000000)            /*!< Bit 1 */

#define  GPIO_OSPD_OSPD15                    ((uint32_t)0xC0000000)            /*!< Pin 15 Max Speed bits */
#define  GPIO_OSPD_OSPD15_0                  ((uint32_t)0x40000000)            /*!< Bit 0 */
#define  GPIO_OSPD_OSPD15_1                  ((uint32_t)0x80000000)            /*!< Bit 1 */

/*******************  Bit definition for GPIO_PUPD register *******************/
#define  GPIO_PUPD_PUPD0                     ((uint32_t)0x00000003)            /*!< Pin 0 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD0_0                   ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD0_1                   ((uint32_t)0x00000002)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD1                     ((uint32_t)0x0000000C)            /*!< Pin 1 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD1_0                   ((uint32_t)0x00000004)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD1_1                   ((uint32_t)0x00000008)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD2                     ((uint32_t)0x00000030)            /*!< Pin 2 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD2_0                   ((uint32_t)0x00000010)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD2_1                   ((uint32_t)0x00000020)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD3                     ((uint32_t)0x000000C0)            /*!< Pin 3 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD3_0                   ((uint32_t)0x00000040)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD3_1                   ((uint32_t)0x00000080)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD4                     ((uint32_t)0x00000300)            /*!< Pin 4 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD4_0                   ((uint32_t)0x00000100)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD4_1                   ((uint32_t)0x00000200)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD5                     ((uint32_t)0x00000C00)            /*!< Pin 5 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD5_0                   ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD5_1                   ((uint32_t)0x00000800)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD6                     ((uint32_t)0x00003000)            /*!< Pin 6 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD6_0                   ((uint32_t)0x00001000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD6_1                   ((uint32_t)0x00002000)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD7                     ((uint32_t)0x0000C000)            /*!< Pin 7 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD7_0                   ((uint32_t)0x00004000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD7_1                   ((uint32_t)0x00008000)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD8                     ((uint32_t)0x00030000)            /*!< Pin 8 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD8_0                   ((uint32_t)0x00010000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD8_1                   ((uint32_t)0x00020000)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD9                     ((uint32_t)0x000C0000)            /*!< Pin 9 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD9_0                   ((uint32_t)0x00040000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD9_1                   ((uint32_t)0x00080000)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD10                    ((uint32_t)0x00300000)            /*!< Pin 10 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD10_0                  ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD10_1                  ((uint32_t)0x00200000)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD11                    ((uint32_t)0x00C00000)            /*!< Pin 11 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD11_0                  ((uint32_t)0x00400000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD11_1                  ((uint32_t)0x00800000)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD12                    ((uint32_t)0x03000000)            /*!< Pin 12 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD12_0                  ((uint32_t)0x01000000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD12_1                  ((uint32_t)0x02000000)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD13                    ((uint32_t)0x0C000000)            /*!< Pin 13 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD13_0                  ((uint32_t)0x04000000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD13_1                  ((uint32_t)0x08000000)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD14                    ((uint32_t)0x30000000)            /*!< Pin 14 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD14_0                  ((uint32_t)0x10000000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD14_1                  ((uint32_t)0x20000000)            /*!< Bit 1 */

#define  GPIO_PUPD_PUPD15                    ((uint32_t)0xC0000000)            /*!< Pin 15 Pull Up or Pull Down bits */
#define  GPIO_PUPD_PUPD15_0                  ((uint32_t)0x40000000)            /*!< Bit 0 */
#define  GPIO_PUPD_PUPD15_1                  ((uint32_t)0x80000000)            /*!< Bit 1 */

/*******************  Bit definition for GPIO_DIR register  *******************/
#define  GPIO_DIR0                           ((uint32_t)0x00000001)            /*!< Pin 0 input data bit */
#define  GPIO_DIR1                           ((uint32_t)0x00000002)            /*!< Pin 1 input data bit */
#define  GPIO_DIR2                           ((uint32_t)0x00000004)            /*!< Pin 2 input data bit */
#define  GPIO_DIR3                           ((uint32_t)0x00000008)            /*!< Pin 3 input data bit */
#define  GPIO_DIR4                           ((uint32_t)0x00000010)            /*!< Pin 4 input data bit */
#define  GPIO_DIR5                           ((uint32_t)0x00000020)            /*!< Pin 5 input data bit */
#define  GPIO_DIR6                           ((uint32_t)0x00000040)            /*!< Pin 6 input data bit */
#define  GPIO_DIR7                           ((uint32_t)0x00000080)            /*!< Pin 7 input data bit */
#define  GPIO_DIR8                           ((uint32_t)0x00000100)            /*!< Pin 8 input data bit */
#define  GPIO_DIR9                           ((uint32_t)0x00000200)            /*!< Pin 9 input data bit */
#define  GPIO_DIR10                          ((uint32_t)0x00000400)            /*!< Pin 10 input data bit */
#define  GPIO_DIR11                          ((uint32_t)0x00000800)            /*!< Pin 11 input data bit */
#define  GPIO_DIR12                          ((uint32_t)0x00001000)            /*!< Pin 12 input data bit */
#define  GPIO_DIR13                          ((uint32_t)0x00002000)            /*!< Pin 13 input data bit */
#define  GPIO_DIR14                          ((uint32_t)0x00004000)            /*!< Pin 14 input data bit */
#define  GPIO_DIR15                          ((uint32_t)0x00008000)            /*!< Pin 15 input data bit */

/******************  Bit definition for GPIO_DOR register  ********************/
#define  GPIO_DOR0                           ((uint32_t)0x00000001)            /*!< Pin 0 output data bit*/
#define  GPIO_DOR1                           ((uint32_t)0x00000002)            /*!< Pin 1 output data bit*/
#define  GPIO_DOR2                           ((uint32_t)0x00000004)            /*!< Pin 2 output data bit*/
#define  GPIO_DOR3                           ((uint32_t)0x00000008)            /*!< Pin 3 output data bit*/
#define  GPIO_DOR4                           ((uint32_t)0x00000010)            /*!< Pin 4 output data bit*/
#define  GPIO_DOR5                           ((uint32_t)0x00000020)            /*!< Pin 5 output data bit*/
#define  GPIO_DOR6                           ((uint32_t)0x00000040)            /*!< Pin 6 output data bit*/
#define  GPIO_DOR7                           ((uint32_t)0x00000080)            /*!< Pin 7 output data bit*/
#define  GPIO_DOR8                           ((uint32_t)0x00000100)            /*!< Pin 8 output data bit*/
#define  GPIO_DOR9                           ((uint32_t)0x00000200)            /*!< Pin 9 output data bit*/
#define  GPIO_DOR10                          ((uint32_t)0x00000400)            /*!< Pin 10 output data bit*/
#define  GPIO_DOR11                          ((uint32_t)0x00000800)            /*!< Pin 11 output data bit*/
#define  GPIO_DOR12                          ((uint32_t)0x00001000)            /*!< Pin 12 output data bit*/
#define  GPIO_DOR13                          ((uint32_t)0x00002000)            /*!< Pin 13 output data bit*/
#define  GPIO_DOR14                          ((uint32_t)0x00004000)            /*!< Pin 14 output data bit*/
#define  GPIO_DOR15                          ((uint32_t)0x00008000)            /*!< Pin 15 output data bit*/

/****************** Bit definition for GPIO_BOR register  *********************/
#define  GPIO_BOR_BOR0                       ((uint32_t)0x00000001)            /*!< Pin 0 Set bit */
#define  GPIO_BOR_BOR1                       ((uint32_t)0x00000002)            /*!< Pin 1 Set bit */
#define  GPIO_BOR_BOR2                       ((uint32_t)0x00000004)            /*!< Pin 2 Set bit */
#define  GPIO_BOR_BOR3                       ((uint32_t)0x00000008)            /*!< Pin 3 Set bit */
#define  GPIO_BOR_BOR4                       ((uint32_t)0x00000010)            /*!< Pin 4 Set bit */
#define  GPIO_BOR_BOR5                       ((uint32_t)0x00000020)            /*!< Pin 5 Set bit */
#define  GPIO_BOR_BOR6                       ((uint32_t)0x00000040)            /*!< Pin 6 Set bit */
#define  GPIO_BOR_BOR7                       ((uint32_t)0x00000080)            /*!< Pin 7 Set bit */
#define  GPIO_BOR_BOR8                       ((uint32_t)0x00000100)            /*!< Pin 8 Set bit */
#define  GPIO_BOR_BOR9                       ((uint32_t)0x00000200)            /*!< Pin 9 Set bit */
#define  GPIO_BOR_BOR10                      ((uint32_t)0x00000400)            /*!< Pin 10 Set bit */
#define  GPIO_BOR_BOR11                      ((uint32_t)0x00000800)            /*!< Pin 11 Set bit */
#define  GPIO_BOR_BOR12                      ((uint32_t)0x00001000)            /*!< Pin 12 Set bit */
#define  GPIO_BOR_BOR13                      ((uint32_t)0x00002000)            /*!< Pin 13 Set bit */
#define  GPIO_BOR_BOR14                      ((uint32_t)0x00004000)            /*!< Pin 14 Set bit */
#define  GPIO_BOR_BOR15                      ((uint32_t)0x00008000)            /*!< Pin 15 Set bit */
#define  GPIO_BOR_CR0                        ((uint32_t)0x00010000)            /*!< Pin 0 Reset bit */
#define  GPIO_BOR_CR1                        ((uint32_t)0x00020000)            /*!< Pin 1 Reset bit */
#define  GPIO_BOR_CR2                        ((uint32_t)0x00040000)            /*!< Pin 2 Reset bit */
#define  GPIO_BOR_CR3                        ((uint32_t)0x00080000)            /*!< Pin 3 Reset bit */
#define  GPIO_BOR_CR4                        ((uint32_t)0x00100000)            /*!< Pin 4 Reset bit */
#define  GPIO_BOR_CR5                        ((uint32_t)0x00200000)            /*!< Pin 5 Reset bit */
#define  GPIO_BOR_CR6                        ((uint32_t)0x00400000)            /*!< Pin 6 Reset bit */
#define  GPIO_BOR_CR7                        ((uint32_t)0x00800000)            /*!< Pin 7 Reset bit */
#define  GPIO_BOR_CR8                        ((uint32_t)0x01000000)            /*!< Pin 8 Reset bit */
#define  GPIO_BOR_CR9                        ((uint32_t)0x02000000)            /*!< Pin 9 Reset bit */
#define  GPIO_BOR_CR10                       ((uint32_t)0x04000000)            /*!< Pin 10 Reset bit */
#define  GPIO_BOR_CR11                       ((uint32_t)0x08000000)            /*!< Pin 11 Reset bit */
#define  GPIO_BOR_CR12                       ((uint32_t)0x10000000)            /*!< Pin 12 Reset bit */
#define  GPIO_BOR_CR13                       ((uint32_t)0x20000000)            /*!< Pin 13 Reset bit */
#define  GPIO_BOR_CR14                       ((uint32_t)0x40000000)            /*!< Pin 14 Reset bit */
#define  GPIO_BOR_CR15                       ((uint32_t)0x80000000)            /*!< Pin 15 Reset bit */

/****************** Bit definition for GPIO_LOCKR register  *******************/
#define  GPIO_LOCKR_LK0                      ((uint32_t)0x00000001)            /*!< Pin 0 Lock bit*/
#define  GPIO_LOCKR_LK1                      ((uint32_t)0x00000002)            /*!< Pin 1 Lock bit*/
#define  GPIO_LOCKR_LK2                      ((uint32_t)0x00000004)            /*!< Pin 2 Lock bit*/
#define  GPIO_LOCKR_LK3                      ((uint32_t)0x00000008)            /*!< Pin 3 Lock bit*/
#define  GPIO_LOCKR_LK4                      ((uint32_t)0x00000010)            /*!< Pin 4 Lock bit*/
#define  GPIO_LOCKR_LK5                      ((uint32_t)0x00000020)            /*!< Pin 5 Lock bit*/
#define  GPIO_LOCKR_LK6                      ((uint32_t)0x00000040)            /*!< Pin 6 Lock bit*/
#define  GPIO_LOCKR_LK7                      ((uint32_t)0x00000080)            /*!< Pin 7 Lock bit*/
#define  GPIO_LOCKR_LK8                      ((uint32_t)0x00000100)            /*!< Pin 8 Lock bit*/
#define  GPIO_LOCKR_LK9                      ((uint32_t)0x00000200)            /*!< Pin 9 Lock bit*/
#define  GPIO_LOCKR_LK10                     ((uint32_t)0x00000400)            /*!< Pin 10 Lock bit*/
#define  GPIO_LOCKR_LK11                     ((uint32_t)0x00000800)            /*!< Pin 11 Lock bit*/
#define  GPIO_LOCKR_LK12                     ((uint32_t)0x00001000)            /*!< Pin 12 Lock bit*/
#define  GPIO_LOCKR_LK13                     ((uint32_t)0x00002000)            /*!< Pin 13 Lock bit*/
#define  GPIO_LOCKR_LK14                     ((uint32_t)0x00004000)            /*!< Pin 14 Lock bit*/
#define  GPIO_LOCKR_LK15                     ((uint32_t)0x00008000)            /*!< Pin 15 Lock bit*/
#define  GPIO_LOCKR_LKK                      ((uint32_t)0x00010000)            /*!< Pin All Lock bit*/

/****************** Bit definition for GPIO_AFSL register  ********************/
#define  GPIO_AFSL_AFSL0                     ((uint32_t)0x0000000F)            /*!< Pin 0 Aaternate function selection bit*/
#define  GPIO_AFSL_AFSL1                     ((uint32_t)0x000000F0)            /*!< Pin 1 Aaternate function selection bit*/
#define  GPIO_AFSL_AFSL2                     ((uint32_t)0x00000F00)            /*!< Pin 2 Aaternate function selection bit*/
#define  GPIO_AFSL_AFSL3                     ((uint32_t)0x0000F000)            /*!< Pin 3 Aaternate function selection bit*/
#define  GPIO_AFSL_AFSL4                     ((uint32_t)0x000F0000)            /*!< Pin 4 Aaternate function selection bit*/
#define  GPIO_AFSL_AFSL5                     ((uint32_t)0x00F00000)            /*!< Pin 5 Aaternate function selection bit*/
#define  GPIO_AFSL_AFSL6                     ((uint32_t)0x0F000000)            /*!< Pin 6 Aaternate function selection bit*/
#define  GPIO_AFSL_AFSL7                     ((uint32_t)0xF0000000)            /*!< Pin 7 Aaternate function selection bit*/

/****************** Bit definition for GPIO_AFSH register  ********************/
#define  GPIO_AFSH_AFSH8                     ((uint32_t)0x0000000F)            /*!< Pin 8 Aaternate function selection bit*/
#define  GPIO_AFSH_AFSH9                     ((uint32_t)0x000000F0)            /*!< Pin 9 Aaternate function selection bit*/
#define  GPIO_AFSH_AFSH10                    ((uint32_t)0x00000F00)            /*!< Pin 10 Aaternate function selection bit*/
#define  GPIO_AFSH_AFSH11                    ((uint32_t)0x0000F000)            /*!< Pin 11 Aaternate function selection bit*/
#define  GPIO_AFSH_AFSH12                    ((uint32_t)0x000F0000)            /*!< Pin 12 Aaternate function selection bit*/
#define  GPIO_AFSH_AFSH13                    ((uint32_t)0x00F00000)            /*!< Pin 13 Aaternate function selection bit*/
#define  GPIO_AFSH_AFSH14                    ((uint32_t)0x0F000000)            /*!< Pin 14 Aaternate function selection bit*/
#define  GPIO_AFSH_AFSH15                    ((uint32_t)0xF0000000)            /*!< Pin 15 Aaternate function selection bit*/

/****************** Bit definition for GPIO_BCR register  *********************/
#define  GPIO_BCR_CR0                        ((uint32_t)0x00000001)            /*!< Pin 0 Clear bit*/
#define  GPIO_BCR_CR1                        ((uint32_t)0x00000002)            /*!< Pin 1 Clear bit*/
#define  GPIO_BCR_CR2                        ((uint32_t)0x00000004)            /*!< Pin 2 Clear bit*/
#define  GPIO_BCR_CR3                        ((uint32_t)0x00000008)            /*!< Pin 3 Clear bit*/
#define  GPIO_BCR_CR4                        ((uint32_t)0x00000010)            /*!< Pin 4 Clear bit*/
#define  GPIO_BCR_CR5                        ((uint32_t)0x00000020)            /*!< Pin 5 Clear bit*/
#define  GPIO_BCR_CR6                        ((uint32_t)0x00000040)            /*!< Pin 6 Clear bit*/
#define  GPIO_BCR_CR7                        ((uint32_t)0x00000080)            /*!< Pin 7 Clear bit*/
#define  GPIO_BCR_CR8                        ((uint32_t)0x00000100)            /*!< Pin 8 Clear bit*/
#define  GPIO_BCR_CR9                        ((uint32_t)0x00000200)            /*!< Pin 9 Clear bit*/
#define  GPIO_BCR_CR10                       ((uint32_t)0x00000400)            /*!< Pin 10 Clear bit*/
#define  GPIO_BCR_CR11                       ((uint32_t)0x00000800)            /*!< Pin 11 Clear bit*/
#define  GPIO_BCR_CR12                       ((uint32_t)0x00001000)            /*!< Pin 12 Clear bit*/
#define  GPIO_BCR_CR13                       ((uint32_t)0x00002000)            /*!< Pin 13 Clear bit*/
#define  GPIO_BCR_CR14                       ((uint32_t)0x00004000)            /*!< Pin 14 Clear bit*/
#define  GPIO_BCR_CR15                       ((uint32_t)0x00008000)            /*!< Pin 15 Clear bit*/

#ifdef GD32F170_190
/*******************  Bit definition for GPIO_TGR register *******************/
#define  GPIO_TGR_TG0                        ((uint32_t)0x00000001)            /*!< Pin 0 Toggle bit*/
#define  GPIO_TGR_TG1                        ((uint32_t)0x00000002)            /*!< Pin 1 Toggle bit*/
#define  GPIO_TGR_TG2                        ((uint32_t)0x00000004)            /*!< Pin 2 Toggle bit*/
#define  GPIO_TGR_TG3                        ((uint32_t)0x00000008)            /*!< Pin 3 Toggle bit*/
#define  GPIO_TGR_TG4                        ((uint32_t)0x00000010)            /*!< Pin 4 Toggle bit*/
#define  GPIO_TGR_TG5                        ((uint32_t)0x00000020)            /*!< Pin 5 Toggle bit*/
#define  GPIO_TGR_TG6                        ((uint32_t)0x00000040)            /*!< Pin 6 Toggle bit*/
#define  GPIO_TGR_TG7                        ((uint32_t)0x00000080)            /*!< Pin 7 Toggle bit*/
#define  GPIO_TGR_TG8                        ((uint32_t)0x00000100)            /*!< Pin 8 Toggle bit*/
#define  GPIO_TGR_TG9                        ((uint32_t)0x00000200)            /*!< Pin 9 Toggle bit*/
#define  GPIO_TGR_TG10                       ((uint32_t)0x00000400)            /*!< Pin 10 Toggle bit*/
#define  GPIO_TGR_TG11                       ((uint32_t)0x00000800)            /*!< Pin 11 Toggle bit*/
#define  GPIO_TGR_TG12                       ((uint32_t)0x00001000)            /*!< Pin 12 Toggle bit*/
#define  GPIO_TGR_TG13                       ((uint32_t)0x00002000)            /*!< Pin 13 Toggle bit*/
#define  GPIO_TGR_TG14                       ((uint32_t)0x00004000)            /*!< Pin 14 Toggle bit*/
#define  GPIO_TGR_TG15                       ((uint32_t)0x00008000)            /*!< Pin 15 Toggle bit*/
#endif /* GD32F170_190 */
/******************************************************************************/
/*                                                                            */
/*                   Inter-integrated Circuit Interface (I2C)                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CTLR1 register  ******************/
#define  I2C_CTLR1_I2CEN                     ((uint16_t)0x0001)                /*!< Peripheral Enable */
#define  I2C_CTLR1_SMBEN                     ((uint16_t)0x0002)                /*!< SMBus Mode */
#define  I2C_CTLR1_SMBSEL                    ((uint16_t)0x0008)                /*!< SMBus Type */
#define  I2C_CTLR1_ARPEN                     ((uint16_t)0x0010)                /*!< ARP Enable */
#define  I2C_CTLR1_PECEN                     ((uint16_t)0x0020)                /*!< PEC Enable */
#define  I2C_CTLR1_GCEN                      ((uint16_t)0x0040)                /*!< General Call Enable */
#define  I2C_CTLR1_DISSTRC                   ((uint16_t)0x0080)                /*!< Clock Stretching Disable (Slave mode) */
#define  I2C_CTLR1_GENSTA                    ((uint16_t)0x0100)                /*!< Start Generation */
#define  I2C_CTLR1_GENSTP                    ((uint16_t)0x0200)                /*!< Stop Generation */
#define  I2C_CTLR1_ACKEN                     ((uint16_t)0x0400)                /*!< Acknowledge Enable */
#define  I2C_CTLR1_POAP                      ((uint16_t)0x0800)                /*!< Acknowledge/PEC Position (for data reception) */
#define  I2C_CTLR1_PECTRANS                  ((uint16_t)0x1000)                /*!< Packet Error Checking */
#define  I2C_CTLR1_SALT                      ((uint16_t)0x2000)                /*!< SMBus Alert */
#define  I2C_CTLR1_SRESET                    ((uint16_t)0x8000)                /*!< Software Reset */

/*******************  Bit definition for I2C_CTLR2 register  ******************/
#define  I2C_CTLR2_I2CCLK                    ((uint16_t)0x003F)                /*!< I2CCLK[5:0] bits (Peripheral Clock Frequency) */
#define  I2C_CTLR2_I2CCLK_0                  ((uint16_t)0x0001)                /*!< Bit 0 */
#define  I2C_CTLR2_I2CCLK_1                  ((uint16_t)0x0002)                /*!< Bit 1 */
#define  I2C_CTLR2_I2CCLK_2                  ((uint16_t)0x0004)                /*!< Bit 2 */
#define  I2C_CTLR2_I2CCLK_3                  ((uint16_t)0x0008)                /*!< Bit 3 */
#define  I2C_CTLR2_I2CCLK_4                  ((uint16_t)0x0010)                /*!< Bit 4 */
#define  I2C_CTLR2_I2CCLK_5                  ((uint16_t)0x0020)                /*!< Bit 5 */

#define  I2C_CTLR2_EIE                       ((uint16_t)0x0100)                /*!< Error Interrupt Enable */
#define  I2C_CTLR2_EE                        ((uint16_t)0x0200)                /*!< Event Interrupt Enable */
#define  I2C_CTLR2_BIE                       ((uint16_t)0x0400)                /*!< Buffer Interrupt Enable */
#define  I2C_CTLR2_DMAON                     ((uint16_t)0x0800)                /*!< DMA Requests Enable */
#define  I2C_CTLR2_DMALST                    ((uint16_t)0x1000)                /*!< DMA Last Transfer */

/*******************  Bit definition for I2C_AR1 register  ********************/
#define  I2C_AR1_ADDRESS1_7                  ((uint16_t)0x00FE)                /*!< Interface Address */
#define  I2C_AR1_ADDRESS8_9                  ((uint16_t)0x0300)                /*!< Interface Address */

#define  I2C_AR1_ADDRESS0                    ((uint16_t)0x0001)                /*!< Bit 0 */
#define  I2C_AR1_ADDRESS1                    ((uint16_t)0x0002)                /*!< Bit 1 */
#define  I2C_AR1_ADDRESS2                    ((uint16_t)0x0004)                /*!< Bit 2 */
#define  I2C_AR1_ADDRESS3                    ((uint16_t)0x0008)                /*!< Bit 3 */
#define  I2C_AR1_ADDRESS4                    ((uint16_t)0x0010)                /*!< Bit 4 */
#define  I2C_AR1_ADDRESS5                    ((uint16_t)0x0020)                /*!< Bit 5 */
#define  I2C_AR1_ADDRESS6                    ((uint16_t)0x0040)                /*!< Bit 6 */
#define  I2C_AR1_ADDRESS7                    ((uint16_t)0x0080)                /*!< Bit 7 */
#define  I2C_AR1_ADDRESS8                    ((uint16_t)0x0100)                /*!< Bit 8 */
#define  I2C_AR1_ADDRESS9                    ((uint16_t)0x0200)                /*!< Bit 9 */

#define  I2C_AR1_ADDFORMAT                   ((uint16_t)0x8000)                /*!< Addressing Mode (Slave mode) */

/*******************  Bit definition for I2C_AR2 register  ********************/
#define  I2C_AR2_DUADEN                      ((uint8_t)0x01)                   /*!< Dual addressing mode enable */
#define  I2C_AR2_ADDRESS2                    ((uint8_t)0xFE)                   /*!< Interface address */

/********************  Bit definition for I2C_DTR register  *******************/
#define  I2C_DTR_TRB                         ((uint8_t)0xFF)                   /*!< 8-bit Data Register */

/*******************  Bit definition for I2C_STR1 register  *******************/
#define  I2C_STR1_SBSEND                     ((uint16_t)0x0001)                /*!< Start Bit (Master mode) */
#define  I2C_STR1_ADDSEND                    ((uint16_t)0x0002)                /*!< Address sent (master mode)/matched (slave mode) */
#define  I2C_STR1_BTC                        ((uint16_t)0x0004)                /*!< Byte Transfer Finished */
#define  I2C_STR1_ADD10SEND                  ((uint16_t)0x0008)                /*!< 10-bit header sent (Master mode) */
#define  I2C_STR1_STPDET                     ((uint16_t)0x0010)                /*!< Stop detection (Slave mode) */
#define  I2C_STR1_RBNE                       ((uint16_t)0x0040)                /*!< Data Register not Empty (receivers) */
#define  I2C_STR1_TBE                        ((uint16_t)0x0080)                /*!< Data Register Empty (transmitters) */
#define  I2C_STR1_BE                         ((uint16_t)0x0100)                /*!< Bus Error */
#define  I2C_STR1_LOSTARB                    ((uint16_t)0x0200)                /*!< Arbitration Lost (master mode) */
#define  I2C_STR1_AE                         ((uint16_t)0x0400)                /*!< Acknowledge Failure */
#define  I2C_STR1_RXORE                      ((uint16_t)0x0800)                /*!< Overrun/Underrun */
#define  I2C_STR1_PECE                       ((uint16_t)0x1000)                /*!< PEC Error in reception */
#define  I2C_STR1_SMBTO                      ((uint16_t)0x4000)                /*!< Timeout or Tlow Error */
#define  I2C_STR1_SMBALTS                    ((uint16_t)0x8000)                /*!< SMBus Alert */

/*******************  Bit definition for I2C_STR2 register  *******************/
#define  I2C_STR2_MASTER                     ((uint16_t)0x0001)                /*!< Master/Slave */
#define  I2C_STR2_I2CBSY                     ((uint16_t)0x0002)                /*!< Bus Busy */
#define  I2C_STR2_TRS                        ((uint16_t)0x0004)                /*!< Transmitter/Receiver */
#define  I2C_STR2_RXGC                       ((uint16_t)0x0010)                /*!< General Call Address (Slave mode) */
#define  I2C_STR2_DEFSMB                     ((uint16_t)0x0020)                /*!< SMBus Device Default Address (Slave mode) */
#define  I2C_STR2_HSTSMB                     ((uint16_t)0x0040)                /*!< SMBus Host Header (Slave mode) */
#define  I2C_STR2_DUMODF                     ((uint16_t)0x0080)                /*!< Dual Flag (Slave mode) */
#define  I2C_STR2_ECV                        ((uint16_t)0xFF00)                /*!< Packet Error Checking Register */

/*******************  Bit definition for I2C_CLKR register  *******************/
#define  I2C_CLKR_CLKC                       ((uint16_t)0x0FFF)                /*!< Clock Control Register in Fast/Standard mode (Master mode) */
#define  I2C_CLKR_DTCY                       ((uint16_t)0x4000)                /*!< Fast Mode Duty Cycle */
#define  I2C_CLKR_FAST                       ((uint16_t)0x8000)                /*!< I2C speed selection in master mode */

/******************  Bit definition for I2C_RTR register  *********************/
#define  I2C_RTR_RISETIME                    ((uint8_t)0x3F)                   /*!< Maximum Rise Time in Fast/Standard mode (Master mode) */

#ifdef GD32170_190
/******************  Bit definition for I2C_SAMCSR register  ******************/
#define  I2C_SAMCSR_SAME                     ((uint8_t)0x0001)                 /*!< SAM_V interface enable */
#define  I2C_SAMCSR_STOE                     ((uint8_t)0x0002)                 /*!< SAM_V interface timeout detect enable */
#define  I2C_SAMCSR_TFFIE                    ((uint8_t)0x0010)                 /*!< Txframe fall interrupt enable */
#define  I2C_SAMCSR_TFRIE                    ((uint8_t)0x0020)                 /*!< Txframe rise interrupt enable */
#define  I2C_SAMCSR_RFFIE                    ((uint8_t)0x0040)                 /*!< Rxframe fall interrupt enable */
#define  I2C_SAMCSR_RFRIE                    ((uint8_t)0x0080)                 /*!< Rxframe rise interrupt enable */
#define  I2C_SAMCSR_TXF                      ((uint8_t)0x0100)                 /*!< Level of txframe signal */
#define  I2C_SAMCSR_RXF                      ((uint8_t)0x0200)                 /*!< Level of rxframe signal */
#define  I2C_SAMCSR_TFF                      ((uint8_t)0x1000)                 /*!< Txframe fall flag, cleared by software write 0 */
#define  I2C_SAMCSR_TFR                      ((uint8_t)0x2000)                 /*!< Txframe rise flag, cleared by software write 0 */
#define  I2C_SAMCSR_RFF                      ((uint8_t)0x4000)                 /*!< Rxframe fall flag, cleared by software write 0 */
#define  I2C_SAMCSR_RFR                      ((uint8_t)0x8000)                 /*!< Rxframe rise flag, cleared by software write 0 */
#endif /*GD32170_190*/


#ifdef GD32F170_190
/******************************************************************************/
/*                                                                            */
/*             Programmable Current and Voltage Reference (IVREF)             */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for REF_CR register  ********************/
#define  IVREF_CTLR_CSDA                     ((uint32_t)0x0000003F)            /*!< Current step data bits */
#define  IVREF_CTLR_CSDA_0                   ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  IVREF_CTLR_CSDA_1                   ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  IVREF_CTLR_CSDA_2                   ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  IVREF_CTLR_CSDA_3                   ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  IVREF_CTLR_CSDA_4                   ((uint32_t)0x00000010)            /*!< Bit 4 */
#define  IVREF_CTLR_CSDA_5                   ((uint32_t)0x00000020)            /*!< Bit 5 */

#define  IVREF_CTLR_SCMO                     ((uint32_t)0x00000080)            /*!< Sink current mode bit */

#define  IVREF_CTLR_CPT                      ((uint32_t)0x00001F00)            /*!< Current precision trim bits */
#define  IVREF_CTLR_CPT_0                    ((uint32_t)0x00000100)            /*!< Bit 0 */
#define  IVREF_CTLR_CPT_1                    ((uint32_t)0x00000200)            /*!< Bit 1 */
#define  IVREF_CTLR_CPT_2                    ((uint32_t)0x00000400)            /*!< Bit 2 */
#define  IVREF_CTLR_CPT_3                    ((uint32_t)0x00000800)            /*!< Bit 3 */
#define  IVREF_CTLR_CPT_4                    ((uint32_t)0x00001000)            /*!< Bit 4 */

#define  IVREF_CTLR_MODSEL                   ((uint32_t)0x00004000)            /*!< Mode selection bit */
#define  IVREF_CTLR_CREN                     ((uint32_t)0x00008000)            /*!< Current Reference Enable bit */

#define  IVREF_CTLR_VPT                      ((uint32_t)0x1F000000)            /*!< Voltage precision trim bits */
#define  IVREF_CTLR_VPT_0                    ((uint32_t)0x01000000)            /*!< Bit 0 */
#define  IVREF_CTLR_VPT_1                    ((uint32_t)0x02000000)            /*!< Bit 1 */
#define  IVREF_CTLR_VPT_2                    ((uint32_t)0x04000000)            /*!< Bit 2 */
#define  IVREF_CTLR_VPT_3                    ((uint32_t)0x08000000)            /*!< Bit 3 */
#define  IVREF_CTLR_VPT_4                    ((uint32_t)0x10000000)            /*!< Bit 4 */

#define  IVREF_CTLR_DECAP                    ((uint32_t)0x40000000)            /*!< Connect or Disconnect external capacitor */
#define  IVREF_CTLR_VREN                     ((uint32_t)0x80000000)            /*!< Voltage Reference Enable bit */
#endif  /* GD32F170_190 */


/******************************************************************************/
/*                                                                            */
/*                        Independent WATCHDOG (IWDG)                         */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_CTLR register  ******************/
#define  IWDG_CTLR_CT                        ((uint16_t)0xFFFF)                /*!< Key value (write only, read 0000h) */

/*******************  Bit definition for IWDG_PSR register  *******************/
#define  IWDG_PSR_PS                         ((uint8_t)0x07)                   /*!< PS[2:0] (Prescaler divider) */
#define  IWDG_PSR_PS_0                       ((uint8_t)0x01)                   /*!< Bit 0 */
#define  IWDG_PSR_PS_1                       ((uint8_t)0x02)                   /*!< Bit 1 */
#define  IWDG_PSR_PS_2                       ((uint8_t)0x04)                   /*!< Bit 2 */

/*******************  Bit definition for IWDG_RLDR register  ******************/
#define  IWDG_RLDR_RLD                       ((uint16_t)0x0FFF)                /*!< Watchdog counter reload value */

/*******************  Bit definition for IWDG_STR register  *******************/
#define  IWDG_STR_PUD                        ((uint8_t)0x01)                   /*!< Watchdog prescaler value update */
#define  IWDG_STR_RUD                        ((uint8_t)0x02)                   /*!< Watchdog counter reload value update */
#define  IWDG_STR_WUD                        ((uint8_t)0x04)                   /*!< Watchdog counter window value update */

/*******************  Bit definition for IWDG_WND register  *******************/
#define  IWDG_WND_WND                        ((uint16_t)0x0FFF)                /*!< Watchdog counter window value */


#ifdef GD32F170_190
/******************************************************************************/
/*                                                                            */
/*                             LCD controller                                 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for LCD_CTLR register  ******************/
#define  LCD_CTLR_LCDON                      ((uint8_t)0x01)                   /*!< LCD controller start */
#define  LCD_CTLR_VSRC                       ((uint8_t)0x02)                   /*!< LCD Voltage source */

#define  LCD_CTLR_DUTY                       ((uint8_t)0x1C)                   /*!< Duty select */
#define  LCD_CTLR_DUTY0                      ((uint8_t)0x04)                   /*!< Bit 0 */
#define  LCD_CTLR_DUTY1                      ((uint8_t)0x08)                   /*!< Bit 1 */
#define  LCD_CTLR_DUTY2                      ((uint8_t)0x10)                   /*!< Bit 2 */

#define  LCD_CTLR_BIAS                       ((uint8_t)0x60)                   /*!< Bias select */
#define  LCD_CTLR_BIAS0                      ((uint8_t)0x20)                   /*!< Bit 0 */
#define  LCD_CTLR_BIAS1                      ((uint8_t)0x40)                   /*!< Bit 1 */

#define  LCD_CTLR_COMS                       ((uint8_t)0x80)                   /*!< Regular channel Start flag */

/********************  Bit definition for LCD_CFGR register  ******************/
#define  LCD_CFGR_HDON                       ((uint32_t)0x00000001)            /*!< High drive enable */
#define  LCD_CFGR_SOFIE                      ((uint32_t)0x00000002)            /*!< Start of frame interrupt enable */
#define  LCD_CFGR_UPDIE                      ((uint32_t)0x00000008)            /*!< LCD update done interrupt enable */

#define  LCD_CFGR_PULSE                      ((uint32_t)0x00000070)            /*!< Pulse ON duration */
#define  LCD_CFGR_PULSE0                     ((uint32_t)0x00000010)            /*!< Bit 0 */
#define  LCD_CFGR_PULSE1                     ((uint32_t)0x00000020)            /*!< Bit 1 */
#define  LCD_CFGR_PULSE2                     ((uint32_t)0x00000040)            /*!< Bit 2 */

#define  LCD_CFGR_DD                         ((uint32_t)0x00000380)            /*!< Dead time duration */
#define  LCD_CFGR_DD0                        ((uint32_t)0x00000080)            /*!< Bit 0 */
#define  LCD_CFGR_DD1                        ((uint32_t)0x00000100)            /*!< Bit 1 */
#define  LCD_CFGR_DD2                        ((uint32_t)0x00000200)            /*!< Bit 2 */

#define  LCD_CFGR_CONR                       ((uint32_t)0x00001C00)            /*!< Contrast ratio */
#define  LCD_CFGR_CONR0                      ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  LCD_CFGR_CONR1                      ((uint32_t)0x00000800)            /*!< Bit 1 */
#define  LCD_CFGR_CONR2                      ((uint32_t)0x00001000)            /*!< Bit 2 */

#define  LCD_CFGR_BLKDIV                     ((uint32_t)0x0000E000)            /*!< Blink frequency divider  */
#define  LCD_CFGR_BLKDIV0                    ((uint32_t)0x00002000)            /*!< Bit 0 */
#define  LCD_CFGR_BLKDIV1                    ((uint32_t)0x00004000)            /*!< Bit 1 */
#define  LCD_CFGR_BLKDIV2                    ((uint32_t)0x00008000)            /*!< Bit 2 */

#define  LCD_CFGR_BLKM                       ((uint32_t)0x00030000)            /*!< Blink mode  */
#define  LCD_CFGR_BLKM0                      ((uint32_t)0x00010000)            /*!< Bit 0 */
#define  LCD_CFGR_BLKM1                      ((uint32_t)0x00020000)            /*!< Bit 1 */

#define  LCD_CFGR_DIV                        ((uint32_t)0x003C0000)            /*!< LCD clock divider */
#define  LCD_CFGR_DIV0                       ((uint32_t)0x00040000)            /*!< Bit 0 */
#define  LCD_CFGR_DIV1                       ((uint32_t)0x00080000)            /*!< Bit 1 */
#define  LCD_CFGR_DIV2                       ((uint32_t)0x00100000)            /*!< Bit 2 */
#define  LCD_CFGR_DIV3                       ((uint32_t)0x00200000)            /*!< Bit 2 */

#define  LCD_CFGR_PRE                        ((uint32_t)0x03C00000)             /*!< LCD clock prescaler */
#define  LCD_CFGR_PRE0                       ((uint32_t)0x00400000)            /*!< Bit 0 */
#define  LCD_CFGR_PRE1                       ((uint32_t)0x00800000)            /*!< Bit 1 */
#define  LCD_CFGR_PRE2                       ((uint32_t)0x01000000)            /*!< Bit 2 */
#define  LCD_CFGR_PRE3                       ((uint32_t)0x02000000)            /*!< Bit 2 */

/********************  Bit definition for LCD_SFR register  *******************/
#define  LCD_SFR_ONF                         ((uint32_t)0x00000001)            /*!< LCD controller on flag */
#define  LCD_SFR_SOF                         ((uint32_t)0x00000002)            /*!< Start of frame flag */
#define  LCD_SFR_UPRF                        ((uint32_t)0x00000004)            /*!< LCD data update request flag */
#define  LCD_SFR_UPDF                        ((uint32_t)0x00000008)            /*!< Update LCD data Done flag */
#define  LCD_SFR_VRDYF                       ((uint32_t)0x00000010)            /*!< LCD voltage ready flag */
#define  LCD_SFR_SYNF                        ((uint32_t)0x00000020)            /*!< LCD FCR Register Synchronization Flag */

/********************  Bit definition for LCD_ICR register  *******************/
#define  LCD_ICR_SOFC                        ((uint32_t)0x00000002)            /*!< Start of frame flag clear */
#define  LCD_ICR_UPDC                        ((uint32_t)0x00000008)            /*!< LCD data update done clear bit */

/********************  Bit definition for LCD_DATA register  ******************/
#define  LCD_DATA                            ((uint32_t)0xFFFFFFFF)            /*!< Each bit corresponds to one segment to display */
#endif /* GD32F170_190 */


#ifdef GD32F170_190
/******************************************************************************/
/*                                                                            */
/*                    Operational amplifiers (OPAMP)                          */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for OPMAP_CTLR register  ****************/
#define  OPAMP_CTLR_OPA1PD                   ((uint32_t)0x00000001)            /*!< OPAMP1 power down */
#define  OPAMP_CTLR_T3OPA1                   ((uint32_t)0x00000002)            /*!< T3 enable for OPAMP1 */
#define  OPAMP_CTLR_S1OPA1                   ((uint32_t)0x00000004)            /*!< S1 enable for OPAMP1 */
#define  OPAMP_CTLR_S2OPA1                   ((uint32_t)0x00000008)            /*!< S2 enable for OPAMP1 */
#define  OPAMP_CTLR_S3OPA1                   ((uint32_t)0x00000010)            /*!< S3 enable for OPAMP1 */
#define  OPAMP_CTLR_OPA1CAL_L                ((uint32_t)0x00000020)            /*!< OPAMP1 offset calibration for P differentional pair */
#define  OPAMP_CTLR_OPA1CAL_H                ((uint32_t)0x00000040)            /*!< OPAMP1 offset calibration for N differentional pair */
#define  OPAMP_CTLR_OPA1LPM                  ((uint32_t)0x00000080)            /*!< OPAMP1 low power */
#define  OPAMP_CTLR_OPA2PD                   ((uint32_t)0x00000100)            /*!< OPAMP2 power down */
#define  OPAMP_CTLR_T3OPA2                   ((uint32_t)0x00000200)            /*!< T3 enable for OPAMP2 */
#define  OPAMP_CTLR_S1OPA2                   ((uint32_t)0x00000400)            /*!< S1 enable for OPAMP2 */
#define  OPAMP_CTLR_S2OPA2                   ((uint32_t)0x00000800)            /*!< S2 enable for OPAMP2 */
#define  OPAMP_CTLR_S3OPA2                   ((uint32_t)0x00001000)            /*!< S3 enable for OPAMP2 */
#define  OPAMP_CTLR_OPA2CAL_L                ((uint32_t)0x00002000)            /*!< OPAMP2 offset calibration for P differentional pair */
#define  OPAMP_CTLR_OPA2CAL_H                ((uint32_t)0x00004000)            /*!< OPAMP2 offset calibration for N differentional pair */
#define  OPAMP_CTLR_OPA2LPM                  ((uint32_t)0x00008000)            /*!< OPAMP2 low power */
#define  OPAMP_CTLR_OPA3PD                   ((uint32_t)0x00010000)            /*!< T3 enable for OPAMP3 */
#define  OPAMP_CTLR_T3OPA3                   ((uint32_t)0x00020000)            /*!< S1 enable for OPAMP3 */
#define  OPAMP_CTLR_S1OPA3                   ((uint32_t)0x00040000)            /*!< S2 enable for OPAMP3 */
#define  OPAMP_CTLR_S2OPA3                   ((uint32_t)0x00080000)            /*!< S3 enable for OPAMP3 */
#define  OPAMP_CTLR_S3OPA3                   ((uint32_t)0x00100000)            /*!< Switch 6 for OPAMP3 */
#define  OPAMP_CTLR_OPA3CAL_L                ((uint32_t)0x00200000)            /*!< OPAMP3 offset calibration for P differentional pair */
#define  OPAMP_CTLR_OPA3CAL_H                ((uint32_t)0x00400000)            /*!< OPAMP3 offset calibration for N differentional pair */
#define  OPAMP_CTLR_OPA3LPM                  ((uint32_t)0x00800000)            /*!< OPAMP3 low power */
#define  OPAMP_CTLR_S4OPA2                   ((uint32_t)0x08000000)            /*!< S4 enable for OPAMP3 */
#define  OPAMP_CTLR_OPA_RANGE                ((uint32_t)0x10000000)            /*!< OPAMP power range selection */
#define  OPAMP_CTLR_OPA1CALOUT               ((uint32_t)0x20000000)            /*!< OPAMP1 calibration output */
#define  OPAMP_CTLR_OPA2CALOUT               ((uint32_t)0x40000000)            /*!< OPAMP2 calibration output */
#define  OPAMP_CTLR_OPA3CALOUT               ((uint32_t)0x80000000)            /*!< OPAMP3 calibration output */

/********************  Bit definition for OPAMP_OTR register  *****************/
#define  OPAMP_OTR_OA1_TRIM_LOW              ((uint32_t)0x0000001F)            /*!< OPAMP1 normal mode 5-bit offset trim value for PMOS pairs */
#define  OPAMP_OTR_OA1_TRIM_LOW_0            ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  OPAMP_OTR_OA1_TRIM_LOW_1            ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  OPAMP_OTR_OA1_TRIM_LOW_2            ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  OPAMP_OTR_OA1_TRIM_LOW_3            ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  OPAMP_OTR_OA1_TRIM_LOW_4            ((uint32_t)0x00000010)            /*!< Bit 4 */

#define  OPAMP_OTR_OA1_TRIM_HIGH             ((uint32_t)0x000003E0)            /*!< OPAMP1 normal mode 5-bit offset trim value for NMOS pairs */
#define  OPAMP_OTR_OA1_TRIM_HIGH_0           ((uint32_t)0x00000020)            /*!< Bit 0 */
#define  OPAMP_OTR_OA1_TRIM_HIGH_1           ((uint32_t)0x00000040)            /*!< Bit 1 */
#define  OPAMP_OTR_OA1_TRIM_HIGH_2           ((uint32_t)0x00000080)            /*!< Bit 2 */
#define  OPAMP_OTR_OA1_TRIM_HIGH_3           ((uint32_t)0x00000100)            /*!< Bit 3 */
#define  OPAMP_OTR_OA1_TRIM_HIGH_4           ((uint32_t)0x00000200)            /*!< Bit 4 */

#define  OPAMP_OTR_OA2_TRIM_LOW              ((uint32_t)0x00007C00)            /*!< OPAMP2 normal mode 5-bit offset trim value for PMOS pairs */
#define  OPAMP_OTR_OA2_TRIM_LOW_0            ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  OPAMP_OTR_OA2_TRIM_LOW_1            ((uint32_t)0x00000800)            /*!< Bit 1 */
#define  OPAMP_OTR_OA2_TRIM_LOW_2            ((uint32_t)0x00001000)            /*!< Bit 2 */
#define  OPAMP_OTR_OA2_TRIM_LOW_3            ((uint32_t)0x00002000)            /*!< Bit 3 */
#define  OPAMP_OTR_OA2_TRIM_LOW_4            ((uint32_t)0x00004000)            /*!< Bit 4 */

#define  OPAMP_OTR_OA2_TRIM_HIGH             ((uint32_t)0x000F8000)            /*!< OPAMP2 normal mode 5-bit offset trim value for NMOS pairs */
#define  OPAMP_OTR_OA2_TRIM_HIGH_0           ((uint32_t)0x00008000)            /*!< Bit 0 */
#define  OPAMP_OTR_OA2_TRIM_HIGH_1           ((uint32_t)0x00010000)            /*!< Bit 1 */
#define  OPAMP_OTR_OA2_TRIM_HIGH_2           ((uint32_t)0x00020000)            /*!< Bit 2 */
#define  OPAMP_OTR_OA2_TRIM_HIGH_3           ((uint32_t)0x00040000)            /*!< Bit 3 */
#define  OPAMP_OTR_OA2_TRIM_HIGH_4           ((uint32_t)0x00080000)            /*!< Bit 4 */

#define  OPAMP_OTR_OA3_TRIM_LOW              ((uint32_t)0x01F00000)            /*!< OPAMP3 normal mode 5-bit offset trim value for PMOS pairs */
#define  OPAMP_OTR_OA3_TRIM_LOW_0            ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  OPAMP_OTR_OA3_TRIM_LOW_1            ((uint32_t)0x00200000)            /*!< Bit 1 */
#define  OPAMP_OTR_OA3_TRIM_LOW_2            ((uint32_t)0x00400000)            /*!< Bit 2 */
#define  OPAMP_OTR_OA3_TRIM_LOW_3            ((uint32_t)0x00800000)            /*!< Bit 3 */
#define  OPAMP_OTR_OA3_TRIM_LOW_4            ((uint32_t)0x01000000)            /*!< Bit 4 */

#define  OPAMP_OTR_OA3_TRIM_HIGH             ((uint32_t)0x3E000000)            /*!< OPAMP3 normal mode 5-bit offset trim value for NMOS pairs */
#define  OPAMP_OTR_OA3_TRIM_HIGH_0           ((uint32_t)0x02000000)            /*!< Bit 0 */
#define  OPAMP_OTR_OA3_TRIM_HIGH_1           ((uint32_t)0x04000000)            /*!< Bit 1 */
#define  OPAMP_OTR_OA3_TRIM_HIGH_2           ((uint32_t)0x08000000)            /*!< Bit 2 */
#define  OPAMP_OTR_OA3_TRIM_HIGH_3           ((uint32_t)0x10000000)            /*!< Bit 3 */
#define  OPAMP_OTR_OA3_TRIM_HIGH_4           ((uint32_t)0x20000000)            /*!< Bit 4 */

#define  OPAMP_OTR_OT_USER                   ((uint32_t)0x80000000)            /*!< Select user or factory trimming value */

/********************  Bit definition for OPAMP_LPOTR register  ***************/
#define  OPAMP_LPOTR_OA1_TRIM_LP_LOW         ((uint32_t)0x0000001F)            /*!< OPAMP1 low power mode 5-bit offset trim value for PMOS pairs */
#define  OPAMP_LPOTR_OA1_TRIM_LP_LOW_0       ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  OPAMP_LPOTR_OA1_TRIM_LP_LOW_1       ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  OPAMP_LPOTR_OA1_TRIM_LP_LOW_2       ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  OPAMP_LPOTR_OA1_TRIM_LP_LOW_3       ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  OPAMP_LPOTR_OA1_TRIM_LP_LOW_4       ((uint32_t)0x00000010)            /*!< Bit 4 */

#define  OPAMP_LPOTR_OA1_TRIM_LP_HIGH        ((uint32_t)0x000003E0)            /*!< OPAMP1 low power mode 5-bit offset trim value for NMOS pairs */
#define  OPAMP_LPOTR_OA1_TRIM_LP_HIGH_0      ((uint32_t)0x00000020)            /*!< Bit 0 */
#define  OPAMP_LPOTR_OA1_TRIM_LP_HIGH_1      ((uint32_t)0x00000040)            /*!< Bit 1 */
#define  OPAMP_LPOTR_OA1_TRIM_LP_HIGH_2      ((uint32_t)0x00000080)            /*!< Bit 2 */
#define  OPAMP_LPOTR_OA1_TRIM_LP_HIGH_3      ((uint32_t)0x00000100)            /*!< Bit 3 */
#define  OPAMP_LPOTR_OA1_TRIM_LP_HIGH_4      ((uint32_t)0x00000200)            /*!< Bit 4 */

#define  OPAMP_LPOTR_OA2_TRIM_LP_LOW         ((uint32_t)0x00007C00)            /*!< OPAMP2 low power mode 5-bit offset trim value for PMOS pairs */
#define  OPAMP_LPOTR_OA2_TRIM_LP_LOW_0       ((uint32_t)0x00000400)            /*!< Bit 0 */
#define  OPAMP_LPOTR_OA2_TRIM_LP_LOW_1       ((uint32_t)0x00000800)            /*!< Bit 1 */
#define  OPAMP_LPOTR_OA2_TRIM_LP_LOW_2       ((uint32_t)0x00001000)            /*!< Bit 2 */
#define  OPAMP_LPOTR_OA2_TRIM_LP_LOW_3       ((uint32_t)0x00002000)            /*!< Bit 3 */
#define  OPAMP_LPOTR_OA2_TRIM_LP_LOW_4       ((uint32_t)0x00004000)            /*!< Bit 4 */

#define  OPAMP_LPOTR_OA2_TRIM_LP_HIGH        ((uint32_t)0x000F8000)            /*!< OPAMP2 low power mode 5-bit offset trim value for NMOS pairs */
#define  OPAMP_LPOTR_OA2_TRIM_LP_HIGH_0      ((uint32_t)0x00008000)            /*!< Bit 0 */
#define  OPAMP_LPOTR_OA2_TRIM_LP_HIGH_1      ((uint32_t)0x00010000)            /*!< Bit 1 */
#define  OPAMP_LPOTR_OA2_TRIM_LP_HIGH_2      ((uint32_t)0x00020000)            /*!< Bit 2 */
#define  OPAMP_LPOTR_OA2_TRIM_LP_HIGH_3      ((uint32_t)0x00040000)            /*!< Bit 3 */
#define  OPAMP_LPOTR_OA2_TRIM_LP_HIGH_4      ((uint32_t)0x00080000)            /*!< Bit 4 */

#define  OPAMP_LPOTR_OA3_TRIM_LP_LOW         ((uint32_t)0x01F00000)            /*!< OPAMP3 low power mode 5-bit offset trim value for PMOS pairs */
#define  OPAMP_LPOTR_OA3_TRIM_LP_LOW_0       ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  OPAMP_LPOTR_OA3_TRIM_LP_LOW_1       ((uint32_t)0x00200000)            /*!< Bit 1 */
#define  OPAMP_LPOTR_OA3_TRIM_LP_LOW_2       ((uint32_t)0x00400000)            /*!< Bit 2 */
#define  OPAMP_LPOTR_OA3_TRIM_LP_LOW_3       ((uint32_t)0x00800000)            /*!< Bit 3 */
#define  OPAMP_LPOTR_OA3_TRIM_LP_LOW_4       ((uint32_t)0x01000000)            /*!< Bit 4 */

#define  OPAMP_LPOTR_OA3_TRIM_LP_HIGH        ((uint32_t)0x3E000000)            /*!< OPAMP3 low power mode 5-bit offset trim value for NMOS pairs */
#define  OPAMP_LPOTR_OA3_TRIM_LP_HIGH_0      ((uint32_t)0x02000000)            /*!< Bit 0 */
#define  OPAMP_LPOTR_OA3_TRIM_LP_HIGH_1      ((uint32_t)0x04000000)            /*!< Bit 1 */
#define  OPAMP_LPOTR_OA3_TRIM_LP_HIGH_2      ((uint32_t)0x08000000)            /*!< Bit 2 */
#define  OPAMP_LPOTR_OA3_TRIM_LP_HIGH_3      ((uint32_t)0x10000000)            /*!< Bit 3 */
#define  OPAMP_LPOTR_OA3_TRIM_LP_HIGH_4      ((uint32_t)0x20000000)            /*!< Bit 4 */
#endif  /* GD32F170_190 */


/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWR_CTLR register  ******************/
#define  PWR_CTLR_LDOLP                      ((uint16_t)0x0001)                /*!< LDO Low Power Mode */
#define  PWR_CTLR_SDBM                       ((uint16_t)0x0002)                /*!< Standby Mode */
#define  PWR_CTLR_WUFR                       ((uint16_t)0x0004)                /*!< Wakeup Flag Reset */
#define  PWR_CTLR_SBFR                       ((uint16_t)0x0008)                /*!< Standby Flag Reset */
#define  PWR_CTLR_LVDE                       ((uint16_t)0x0010)                /*!< Low Voltage Detector Enable */

#define  PWR_CTLR_LVDT                       ((uint16_t)0x00E0)                /*!< LVDT[2:0] bits (Low Voltage Detector Threshold) */
#define  PWR_CTLR_LVDT_0                     ((uint16_t)0x0020)                /*!< Bit 0 */
#define  PWR_CTLR_LVDT_1                     ((uint16_t)0x0040)                /*!< Bit 1 */
#define  PWR_CTLR_LVDT_2                     ((uint16_t)0x0080)                /*!< Bit 2 */

#ifdef GD32F130_150
#define  PWR_CTLR_LVDT_2V2                   ((uint16_t)0x0000)                /*!< LVDT is 2.2V */
#define  PWR_CTLR_LVDT_2V3                   ((uint16_t)0x0020)                /*!< LVDT is 2.3V */
#define  PWR_CTLR_LVDT_2V4                   ((uint16_t)0x0040)                /*!< LVDT is 2.4V */
#define  PWR_CTLR_LVDT_2V5                   ((uint16_t)0x0060)                /*!< LVDT is 2.5V */
#define  PWR_CTLR_LVDT_2V6                   ((uint16_t)0x0080)                /*!< LVDT is 2.6V */
#define  PWR_CTLR_LVDT_2V7                   ((uint16_t)0x00A0)                /*!< LVDT is 2.7V */
#define  PWR_CTLR_LVDT_2V8                   ((uint16_t)0x00C0)                /*!< LVDT is 2.8V */
#define  PWR_CTLR_LVDT_2V9                   ((uint16_t)0x00E0)                /*!< LVDT is 2.9V */
#endif  /* GD32F130_150 */

#ifdef GD32F170_190
#define  PWR_CTLR_LVDT_2V4                   ((uint16_t)0x0000)                /*!< LVDT is 2.4V */
#define  PWR_CTLR_LVDT_2V7                   ((uint16_t)0x0020)                /*!< LVDT is 2.7V */
#define  PWR_CTLR_LVDT_3V0                   ((uint16_t)0x0040)                /*!< LVDT is 3.0V */
#define  PWR_CTLR_LVDT_3V3                   ((uint16_t)0x0060)                /*!< LVDT is 3.3V */
#define  PWR_CTLR_LVDT_3V6                   ((uint16_t)0x0080)                /*!< LVDT is 3.6V */
#define  PWR_CTLR_LVDT_3V9                   ((uint16_t)0x00A0)                /*!< LVDT is 3.9V */
#define  PWR_CTLR_LVDT_4V2                   ((uint16_t)0x00C0)                /*!< LVDT is 4.2V */
#define  PWR_CTLR_LVDT_4V5                   ((uint16_t)0x00E0)                /*!< LVDT is 4.5V */
#endif  /* GD32F170_190 */

#define  PWR_CTLR_BKPWE                      ((uint16_t)0x0100)                /*!< Backup Domain write Enable */

/*******************  Bit definition for PWR_STR register  ********************/
#define  PWR_STR_WUF                         ((uint16_t)0x0001)                /*!< Wakeup Flag */
#define  PWR_STR_SBF                         ((uint16_t)0x0002)                /*!< Standby Flag */
#define  PWR_STR_LVDF                        ((uint16_t)0x0004)                /*!< Low Voltage Detector Status Flag */

#define  PWR_STR_WUPE1                       ((uint16_t)0x0100)                /*!< WUPE1 Pin Enable */
#define  PWR_STR_WUPE2                       ((uint16_t)0x0200)                /*!< WUPE2 Pin Enable */


/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/

/********************  Bit definition for RCC_GCCR register  ******************/
#define  RCC_GCCR_HSIEN                      ((uint32_t)0x00000001)            /*!< Internal High Speed clock enable */
#define  RCC_GCCR_HSISTB                     ((uint32_t)0x00000002)            /*!< Internal High Speed clock ready flag */
#define  RCC_GCCR_HSIADJ                     ((uint32_t)0x000000F8)            /*!< Internal High Speed clock trimming */
#define  RCC_GCCR_HSICALIB                   ((uint32_t)0x0000FF00)            /*!< Internal High Speed clock Calibration */
#define  RCC_GCCR_HSEEN                      ((uint32_t)0x00010000)            /*!< External High Speed clock enable */
#define  RCC_GCCR_HSESTB                     ((uint32_t)0x00020000)            /*!< External High Speed clock ready flag */
#define  RCC_GCCR_HSEBPS                     ((uint32_t)0x00040000)            /*!< External High Speed clock Bypass */
#define  RCC_GCCR_CKMEN                      ((uint32_t)0x00080000)            /*!< Clock Security System enable */
#define  RCC_GCCR_PLLEN                      ((uint32_t)0x01000000)            /*!< PLL enable */
#define  RCC_GCCR_PLLSTB                     ((uint32_t)0x02000000)            /*!< PLL clock ready flag */

/*******************  Bit definition for RCC_GCFGR register  ******************/
#define  RCC_GCFGR_SCS                       ((uint32_t)0x00000003)            /*!< SCS[1:0] bits (System clock Switch) */
#define  RCC_GCFGR_SCS_0                     ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  RCC_GCFGR_SCS_1                     ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  RCC_GCFGR_SCS_HSI                   ((uint32_t)0x00000000)            /*!< HSI selected as system clock */
#define  RCC_GCFGR_SCS_HSE                   ((uint32_t)0x00000001)            /*!< HSE selected as system clock */
#define  RCC_GCFGR_SCS_PLL                   ((uint32_t)0x00000002)            /*!< PLL selected as system clock */
#define  RCC_GCFGR_SCSS                      ((uint32_t)0x0000000C)            /*!< SCSS[1:0] bits (System Clock Switch Status) */
#define  RCC_GCFGR_SCSS_0                    ((uint32_t)0x00000004)            /*!< Bit 0 */
#define  RCC_GCFGR_SCSS_1                    ((uint32_t)0x00000008)            /*!< Bit 1 */
#define  RCC_GCFGR_SCSS_HSI                  ((uint32_t)0x00000000)            /*!< HSI oscillator used as system clock */
#define  RCC_GCFGR_SCSS_HSE                  ((uint32_t)0x00000004)            /*!< HSE oscillator used as system clock */
#define  RCC_GCFGR_SCSS_PLL                  ((uint32_t)0x00000008)            /*!< PLL used as system clock */
#define  RCC_GCFGR_AHBPS                     ((uint32_t)0x000000F0)            /*!< AHBPS[3:0] bits (AHB prescaler) */
#define  RCC_GCFGR_AHBPS_0                   ((uint32_t)0x00000010)            /*!< Bit 0 */
#define  RCC_GCFGR_AHBPS_1                   ((uint32_t)0x00000020)            /*!< Bit 1 */
#define  RCC_GCFGR_AHBPS_2                   ((uint32_t)0x00000040)            /*!< Bit 2 */
#define  RCC_GCFGR_AHBPS_3                   ((uint32_t)0x00000080)            /*!< Bit 3 */
#define  RCC_GCFGR_AHBPS_DIV1                ((uint32_t)0x00000000)            /*!< SYSCLK not divided */
#define  RCC_GCFGR_AHBPS_DIV2                ((uint32_t)0x00000080)            /*!< SYSCLK divided by 2 */
#define  RCC_GCFGR_AHBPS_DIV4                ((uint32_t)0x00000090)            /*!< SYSCLK divided by 4 */
#define  RCC_GCFGR_AHBPS_DIV8                ((uint32_t)0x000000A0)            /*!< SYSCLK divided by 8 */
#define  RCC_GCFGR_AHBPS_DIV16               ((uint32_t)0x000000B0)            /*!< SYSCLK divided by 16 */
#define  RCC_GCFGR_AHBPS_DIV64               ((uint32_t)0x000000C0)            /*!< SYSCLK divided by 64 */
#define  RCC_GCFGR_AHBPS_DIV128              ((uint32_t)0x000000D0)            /*!< SYSCLK divided by 128 */
#define  RCC_GCFGR_AHBPS_DIV256              ((uint32_t)0x000000E0)            /*!< SYSCLK divided by 256 */
#define  RCC_GCFGR_AHBPS_DIV512              ((uint32_t)0x000000F0)            /*!< SYSCLK divided by 512 */
#define  RCC_GCFGR_APB1PS                    ((uint32_t)0x00000700)            /*!< APB1PS[2:0] bits (APB1 prescaler) */
#define  RCC_GCFGR_APB1PS_0                  ((uint32_t)0x00000100)            /*!< Bit 0 */
#define  RCC_GCFGR_APB1PS_1                  ((uint32_t)0x00000200)            /*!< Bit 1 */
#define  RCC_GCFGR_APB1PS_2                  ((uint32_t)0x00000400)            /*!< Bit 2 */
#define  RCC_GCFGR_APB1PS_DIV1               ((uint32_t)0x00000000)            /*!< AHB not divided */
#define  RCC_GCFGR_APB1PS_DIV2               ((uint32_t)0x00000400)            /*!< AHB divided by 2 */
#define  RCC_GCFGR_APB1PS_DIV4               ((uint32_t)0x00000500)            /*!< AHB divided by 4 */
#define  RCC_GCFGR_APB1PS_DIV8               ((uint32_t)0x00000600)            /*!< AHB divided by 8 */
#define  RCC_GCFGR_APB1PS_DIV16              ((uint32_t)0x00000700)            /*!< AHB divided by 16 */
#define  RCC_GCFGR_APB2PS                    ((uint32_t)0x00003800)            /*!< APB2PS[2:0] bits (APB2 prescaler) */
#define  RCC_GCFGR_APB2PS_0                  ((uint32_t)0x00000800)            /*!< Bit 0 */
#define  RCC_GCFGR_APB2PS_1                  ((uint32_t)0x00001000)            /*!< Bit 1 */
#define  RCC_GCFGR_APB2PS_2                  ((uint32_t)0x00002000)            /*!< Bit 2 */
#define  RCC_GCFGR_APB2PS_DIV1               ((uint32_t)0x00000000)            /*!< AHB not divided */
#define  RCC_GCFGR_APB2PS_DIV2               ((uint32_t)0x00002000)            /*!< AHB divided by 2 */
#define  RCC_GCFGR_APB2PS_DIV4               ((uint32_t)0x00002800)            /*!< AHB divided by 4 */
#define  RCC_GCFGR_APB2PS_DIV8               ((uint32_t)0x00003000)            /*!< AHB divided by 8 */
#define  RCC_GCFGR_APB2PS_DIV16              ((uint32_t)0x00003800)            /*!< AHB divided by 16 */
#define  RCC_GCFGR_ADCPS                     ((uint32_t)0x0000C000)            /*!< ADCPS[1:0] bits (ADC prescaler) */
#define  RCC_GCFGR_ADCPS_0                   ((uint32_t)0x00004000)            /*!< Bit 0 */
#define  RCC_GCFGR_ADCPS_1                   ((uint32_t)0x00008000)            /*!< Bit 1 */
#define  RCC_GCFGR_ADCPS_DIV2                ((uint32_t)0x00000000)            /*!< APB2 divided by 2 */
#define  RCC_GCFGR_ADCPS_DIV4                ((uint32_t)0x00004000)            /*!< APB2 divided by 4 */
#define  RCC_GCFGR_ADCPS_DIV6                ((uint32_t)0x00008000)            /*!< APB2 divided by 6 */
#define  RCC_GCFGR_ADCPS_DIV8                ((uint32_t)0x0000C000)            /*!< APB2 divided by 8 */
#define  RCC_GCFGR_PLLSEL                    ((uint32_t)0x00010000)            /*!< PLLSEL bit for entry clock source */
#define  RCC_GCFGR_PLLSEL_HSI_DIV2           ((uint32_t)0x00000000)            /*!< HSI clock divided by 2 selected as PLL entry clock source */
#define  RCC_GCFGR_PLLSEL_HSEPREDIV          ((uint32_t)0x00010000)            /*!< HSEPREDIV clock selected as PLL entry clock source */
#define  RCC_GCFGR_PLLPREDV                  ((uint32_t)0x00020000)            /*!< PLLPREDV bit for PLL entry */
#define  RCC_GCFGR_PLLPREDV_PREDIV1          ((uint32_t)0x00000000)            /*!< PREDIV1 clock not divided for PLL entry */
#define  RCC_GCFGR_PLLPREDV_PREDIV1_DIV2     ((uint32_t)0x00020000)            /*!< PREDIV1 clock divided by 2 for PLL entry */
#define  RCC_GCFGR_PLLMF                     ((uint32_t)0x083C0000)            /*!< PLLMF[3:0] bits (PLL multiplication factor) */
#define  RCC_GCFGR_PLLMF_0                   ((uint32_t)0x00040000)            /*!< Bit 0 */
#define  RCC_GCFGR_PLLMF_1                   ((uint32_t)0x00080000)            /*!< Bit 1 */
#define  RCC_GCFGR_PLLMF_2                   ((uint32_t)0x00100000)            /*!< Bit 2 */
#define  RCC_GCFGR_PLLMF_3                   ((uint32_t)0x00200000)            /*!< Bit 3 */
#define  RCC_GCFGR_PLLMF_4                   ((uint32_t)0x08000000)            /*!< Bit 4 */
#define  RCC_GCFGR_PLLMF2                    ((uint32_t)0x00000000)            /*!< PLL input clock*2 */
#define  RCC_GCFGR_PLLMF3                    ((uint32_t)0x00040000)            /*!< PLL input clock*3 */
#define  RCC_GCFGR_PLLMF4                    ((uint32_t)0x00080000)            /*!< PLL input clock*4 */
#define  RCC_GCFGR_PLLMF5                    ((uint32_t)0x000C0000)            /*!< PLL input clock*5 */
#define  RCC_GCFGR_PLLMF6                    ((uint32_t)0x00100000)            /*!< PLL input clock*6 */
#define  RCC_GCFGR_PLLMF7                    ((uint32_t)0x00140000)            /*!< PLL input clock*7 */
#define  RCC_GCFGR_PLLMF8                    ((uint32_t)0x00180000)            /*!< PLL input clock*8 */
#define  RCC_GCFGR_PLLMF9                    ((uint32_t)0x001C0000)            /*!< PLL input clock*9 */
#define  RCC_GCFGR_PLLMF10                   ((uint32_t)0x00200000)            /*!< PLL input clock10 */
#define  RCC_GCFGR_PLLMF11                   ((uint32_t)0x00240000)            /*!< PLL input clock*11 */
#define  RCC_GCFGR_PLLMF12                   ((uint32_t)0x00280000)            /*!< PLL input clock*12 */
#define  RCC_GCFGR_PLLMF13                   ((uint32_t)0x002C0000)            /*!< PLL input clock*13 */
#define  RCC_GCFGR_PLLMF14                   ((uint32_t)0x00300000)            /*!< PLL input clock*14 */
#define  RCC_GCFGR_PLLMF15                   ((uint32_t)0x00340000)            /*!< PLL input clock*15 */
#define  RCC_GCFGR_PLLMF16                   ((uint32_t)0x00380000)            /*!< PLL input clock*16 */
#define  RCC_GCFGR_PLLMF17                   ((uint32_t)0x08000000)            /*!< PLL input clock*17 */
#define  RCC_GCFGR_PLLMF18                   ((uint32_t)0x08040000)            /*!< PLL input clock*18 */
#define  RCC_GCFGR_PLLMF19                   ((uint32_t)0x08080000)            /*!< PLL input clock*19 */
#define  RCC_GCFGR_PLLMF20                   ((uint32_t)0x080C0000)            /*!< PLL input clock*20 */
#define  RCC_GCFGR_PLLMF21                   ((uint32_t)0x08100000)            /*!< PLL input clock*21 */
#define  RCC_GCFGR_PLLMF22                   ((uint32_t)0x08140000)            /*!< PLL input clock*22 */
#define  RCC_GCFGR_PLLMF23                   ((uint32_t)0x08180000)            /*!< PLL input clock*23 */
#define  RCC_GCFGR_PLLMF24                   ((uint32_t)0x081C0000)            /*!< PLL input clock*24 */
#define  RCC_GCFGR_PLLMF25                   ((uint32_t)0x08200000)            /*!< PLL input clock*25 */
#define  RCC_GCFGR_PLLMF26                   ((uint32_t)0x08240000)            /*!< PLL input clock*26 */
#define  RCC_GCFGR_PLLMF27                   ((uint32_t)0x08280000)            /*!< PLL input clock*27 */
#define  RCC_GCFGR_PLLMF28                   ((uint32_t)0x082C0000)            /*!< PLL input clock*28 */
#define  RCC_GCFGR_PLLMF29                   ((uint32_t)0x08300000)            /*!< PLL input clock*29 */
#define  RCC_GCFGR_PLLMF30                   ((uint32_t)0x08340000)            /*!< PLL input clock*30 */
#define  RCC_GCFGR_PLLMF31                   ((uint32_t)0x08380000)            /*!< PLL input clock*31 */
#define  RCC_GCFGR_PLLMF32                   ((uint32_t)0x083C0000)            /*!< PLL input clock*32 */
#ifdef GD32F130_150                                                            
#define  RCC_GCFGR_USBPS                     ((uint32_t)0x00C00000)            /*!< USB Device prescaler */
#define  RCC_GCFGR_USBPS_Div1_5              ((uint32_t)0x00000000)            /*!< PLL divided by 1.5 */
#define  RCC_GCFGR_USBPS_Div1                ((uint32_t)0x00400000)            /*!< PLL not divided */
#define  RCC_GCFGR_USBPS_Div2_5              ((uint32_t)0x00800000)            /*!< PLL divided by 2.5 */
#define  RCC_GCFGR_USBPS_Div2                ((uint32_t)0x00C00000)            /*!< PLL divided by 2 */
#endif /* GD32F130_150 */                                                      
#define  RCC_GCFGR_CKOUTSRC                  ((uint32_t)0x07000000)            /*!< CKOUTSRC[2:0] bits (Microcontroller Clock Output) */
#define  RCC_GCFGR_CKOUTSRC_0                ((uint32_t)0x01000000)            /*!< Bit 0 */
#define  RCC_GCFGR_CKOUTSRC_1                ((uint32_t)0x02000000)            /*!< Bit 1 */
#define  RCC_GCFGR_CKOUTSRC_2                ((uint32_t)0x04000000)            /*!< Bit 2 */
#define  RCC_GCFGR_CKOUTSRC_NOCLOCK          ((uint32_t)0x00000000)            /*!< No clock */
#ifdef GD32F170_190                                                            
#define  RCC_GCFGR_CKOUTSRC_HSI28            ((uint32_t)0x01000000)            /*!< HSI28 clock selected as CKOUTSRC source */  
#else                                                                          
#define  RCC_GCFGR_CKOUTSRC_HSI14            ((uint32_t)0x01000000)            /*!< HSI14 clock selected as CKOUTSRC source */
#endif /* GD32F170_190 */                                                      
#define  RCC_GCFGR_CKOUTSRC_LSI              ((uint32_t)0x02000000)            /*!< LSI clock selected as CKOUTSRC source */
#define  RCC_GCFGR_CKOUTSRC_LSE              ((uint32_t)0x03000000)            /*!< LSE clock selected as CKOUTSRC source */
#define  RCC_GCFGR_CKOUTSRC_SYSCLK           ((uint32_t)0x04000000)            /*!< System clock selected as CKOUTSRC source */
#define  RCC_GCFGR_CKOUTSRC_HSI              ((uint32_t)0x05000000)            /*!< HSI clock selected as CKOUTSRC source */
#define  RCC_GCFGR_CKOUTSRC_HSE              ((uint32_t)0x06000000)            /*!< HSE clock selected as CKOUTSRC source  */
#define  RCC_GCFGR_CKOUTSRC_PLL_DIV1         ((uint32_t)0x87000000)            /*!< PLL is not divided to CK_OUT */
#define  RCC_GCFGR_CKOUTSRC_PLL_DIV2         ((uint32_t)0x07000000)            /*!< PLL clock divided by 2 selected as CKOUTSRC source */
#define  RCC_GCFGR_CKOUTDIV                  ((uint32_t)0x70000000)            /*!< CK_OUT is divided by 128 */
#define  RCC_GCFGR_CKOUTDIV_1                ((uint32_t)0x00000000)            /*!< CK_OUT is divided by 1 */
#define  RCC_GCFGR_CKOUTDIV_2                ((uint32_t)0x10000000)            /*!< CK_OUT is divided by 2 */
#define  RCC_GCFGR_CKOUTDIV_4                ((uint32_t)0x20000000)            /*!< CK_OUT is divided by 4 */
#define  RCC_GCFGR_CKOUTDIV_8                ((uint32_t)0x30000000)            /*!< CK_OUT is divided by 8 */
#define  RCC_GCFGR_CKOUTDIV_16               ((uint32_t)0x40000000)            /*!< CK_OUT is divided by 16 */
#define  RCC_GCFGR_CKOUTDIV_32               ((uint32_t)0x50000000)            /*!< CK_OUT is divided by 32 */
#define  RCC_GCFGR_CKOUTDIV_64               ((uint32_t)0x60000000)            /*!< CK_OUT is divided by 64 */
#define  RCC_GCFGR_CKOUTDIV_128              ((uint32_t)0x70000000)            /*!< CK_OUT is divided by 128 */
#define  RCC_GCFGR_PLLDV                     ((uint32_t)0x80000000)            /*!< PLL is not divided to CK_OUT */
#define  RCC_GCFGR_PLLDV_CK_PLL              ((uint32_t)0x80000000)            /*!<CK_PLL divided by 2 selected as CK_OUT */
#define  RCC_GCFGR_PLLDV_CK_PLL2             ((uint32_t)0x00000000)            /*!<CK_PLL selected as CK_OUT */
                                                                              
/*!<******************  Bit definition for RCC_GCIR register  *****************/
#define  RCC_GCIR_LSISTBF                    ((uint32_t)0x00000001)            /*!< LSI Ready Interrupt flag */
#define  RCC_GCIR_LSESTBF                    ((uint32_t)0x00000002)            /*!< LSE Ready Interrupt flag */
#define  RCC_GCIR_HSISTBF                    ((uint32_t)0x00000004)            /*!< HSI Ready Interrupt flag */
#define  RCC_GCIR_HSESTBF                    ((uint32_t)0x00000008)            /*!< HSE Ready Interrupt flag */
#define  RCC_GCIR_PLLSTBF                    ((uint32_t)0x00000010)            /*!< PLL Ready Interrupt flag */
#ifdef GD32F170_190                                                            
#define  RCC_GCIR_HSI28STBF                  ((uint32_t)0x00000020)            /*!< HSI28 Ready Interrupt flag */                                       
#else                                                                          
#define  RCC_GCIR_HSI14STBF                  ((uint32_t)0x00000020)            /*!< HSI14 Ready Interrupt flag */
#endif /* GD32F170_190 */                                                      
#define  RCC_GCIR_CKMF                       ((uint32_t)0x00000080)            /*!< Clock Security System Interrupt flag */
#define  RCC_GCIR_LSISTBIE                   ((uint32_t)0x00000100)            /*!< LSI Ready Interrupt Enable */
#define  RCC_GCIR_LSESTBIE                   ((uint32_t)0x00000200)            /*!< LSE Ready Interrupt Enable */
#define  RCC_GCIR_HSISTBIE                   ((uint32_t)0x00000400)            /*!< HSI Ready Interrupt Enable */
#define  RCC_GCIR_HSESTBIE                   ((uint32_t)0x00000800)            /*!< HSE Ready Interrupt Enable */
#define  RCC_GCIR_PLLSTBIE                   ((uint32_t)0x00001000)            /*!< PLL Ready Interrupt Enable */
#ifdef GD32F170_190                                                            
#define  RCC_GCIR_HSI28STBIE                 ((uint32_t)0x00002000)            /*!< HSI28 Ready Interrupt Enable */                                       
#else                                                                          
#define  RCC_GCIR_HSI14STBIE                 ((uint32_t)0x00002000)            /*!< HSI14 Ready Interrupt Enable */
#endif /* GD32F170_190 */                                                      
#define  RCC_GCIR_LSISTBR                    ((uint32_t)0x00010000)            /*!< LSI Ready Interrupt Clear */
#define  RCC_GCIR_LSESTBR                    ((uint32_t)0x00020000)            /*!< LSE Ready Interrupt Clear */
#define  RCC_GCIR_HSISTBR                    ((uint32_t)0x00040000)            /*!< HSI Ready Interrupt Clear */
#define  RCC_GCIR_HSESTBR                    ((uint32_t)0x00080000)            /*!< HSE Ready Interrupt Clear */
#define  RCC_GCIR_PLLSTBR                    ((uint32_t)0x00100000)            /*!< PLL Ready Interrupt Clear */
#ifdef GD32F170_190                                                            
#define  RCC_GCIR_HSI28STBR                  ((uint32_t)0x00200000)            /*!< HSI28 Ready Interrupt Clear */                                      
#else                                                                          
#define  RCC_GCIR_HSI14STBR                  ((uint32_t)0x00200000)            /*!< HSI14 Ready Interrupt Clear */
#endif /* GD32F170_190 */                                                      
#define  RCC_GCIR_CKMC                       ((uint32_t)0x00800000)            /*!< Clock Security System Interrupt Clear */

/*****************  Bit definition for RCC_APB2RCR register  ******************/
#define  RCC_APB2RCR_CFGCMPRST               ((uint32_t)0x00000001)            /*!< SYSCFG and CMP clock reset */
#define  RCC_APB2RCR_ADC1RST                 ((uint32_t)0x00000200)            /*!< ADC1 clock reset */
#define  RCC_APB2RCR_TIMER1RST               ((uint32_t)0x00000800)            /*!< TIMER1 clock reset */
#define  RCC_APB2RCR_SPI1RST                 ((uint32_t)0x00001000)            /*!< SPI1 clock reset */
#define  RCC_APB2RCR_USART1RST               ((uint32_t)0x00004000)            /*!< USART1 clock reset */
#define  RCC_APB2RCR_TIMER15RST              ((uint32_t)0x00010000)            /*!< TIMER15 clock reset */
#define  RCC_APB2RCR_TIMER16RST              ((uint32_t)0x00020000)            /*!< TIMER16 clock reset */
#define  RCC_APB2RCR_TIMER17RST              ((uint32_t)0x00040000)            /*!< TIMER17 clock reset */

/*****************  Bit definition for RCC_APB1RCR register  ******************/
#define  RCC_APB1RCR_TIMER2RST               ((uint32_t)0x00000001)            /*!< TIMER2 clock reset */
#define  RCC_APB1RCR_TIMER3RST               ((uint32_t)0x00000002)            /*!< TIMER3 clock reset */
#define  RCC_APB1RCR_TIMER6RST               ((uint32_t)0x00000010)            /*!< TIMER6 clock reset */
#define  RCC_APB1RCR_TIMER14RST              ((uint32_t)0x00000100)            /*!< TIMER14 clock reset */
#ifdef GD32F170_190                                                            
#define  RCC_APB1RCR_LCDRST                  ((uint32_t)0x00000200)            /*!< LCD clock reset */ 
#endif /* GD32F170_190 */                                                      
#define  RCC_APB1RCR_WWDGRST                 ((uint32_t)0x00000800)            /*!< Window Watchdog clock reset */
#define  RCC_APB1RCR_SPI2RST                 ((uint32_t)0x00004000)            /*!< SPI2 clock reset */
#define  RCC_APB1RCR_SPI3RST                 ((uint32_t)0x00008000)            /*!< SPI3 clock reset */
#define  RCC_APB1RCR_USART2RST               ((uint32_t)0x00020000)            /*!< USART 2 clock reset */
#define  RCC_APB1RCR_I2C1RST                 ((uint32_t)0x00200000)            /*!< I2C 1 clock reset */
#define  RCC_APB1RCR_I2C2RST                 ((uint32_t)0x00400000)            /*!< I2C 2 clock reset */
#ifdef GD32F130_150                                                            
#define  RCC_APB1RCR_USBRST                  ((uint32_t)0x00800000)            /*!< USB Device reset */
#endif /* GD32F130_150 */                                                      
#ifdef GD32F170_190                                                            
#define  RCC_APB1RCR_CAN1RST                 ((uint32_t)0x02000000)            /*!< CAN 1 clock reset */                                                    
#define  RCC_APB1RCR_CAN2RST                 ((uint32_t)0x04000000)            /*!< CAN 2 clock reset */ 
#endif /* GD32F170_190 */                                                      
#define  RCC_APB1RCR_PWRRST                  ((uint32_t)0x10000000)            /*!< PWR clock reset */
#define  RCC_APB1RCR_DACRST                  ((uint32_t)0x20000000)            /*!< DAC clock reset */
#define  RCC_APB1RCR_CECRST                  ((uint32_t)0x40000000)            /*!< CEC clock reset */
#ifdef GD32F170_190                                                            
#define  RCC_APB1RCR_OPAMPIVREFRST           ((uint32_t)0x80000000)            /*!< OPAMP and IVREF clock reset */ 
#endif /* GD32F170_190 */

/******************  Bit definition for RCC_AHBCCR register  ******************/
#define  RCC_AHBCCR_DMA1EN                   ((uint32_t)0x00000001)            /*!< DMA1 clock enable */
#define  RCC_AHBCCR_SRAMEN                   ((uint32_t)0x00000004)            /*!< SRAM interface clock enable */
#define  RCC_AHBCCR_FMCEN                    ((uint32_t)0x00000010)            /*!< FLITF clock enable */
#define  RCC_AHBCCR_CRCEN                    ((uint32_t)0x00000040)            /*!< CRC clock enable */
#define  RCC_AHBCCR_PAEN                     ((uint32_t)0x00020000)            /*!< GPIOA clock enable */
#define  RCC_AHBCCR_PBEN                     ((uint32_t)0x00040000)            /*!< GPIOB clock enable */
#define  RCC_AHBCCR_PCEN                     ((uint32_t)0x00080000)            /*!< GPIOC clock enable */
#define  RCC_AHBCCR_PDEN                     ((uint32_t)0x00100000)            /*!< GPIOD clock enable */
#define  RCC_AHBCCR_PFEN                     ((uint32_t)0x00400000)            /*!< GPIOF clock enable */
#define  RCC_AHBCCR_TSIEN                    ((uint32_t)0x01000000)            /*!< TS clock enable */

/*****************  Bit definition for RCC_APB2CCR register  ******************/
#define  RCC_APB2CCR_CFGCMPEN                ((uint32_t)0x00000001)            /*!< SYSCFG and comparator clock enable */ 
#define  RCC_APB2CCR_ADC1EN                  ((uint32_t)0x00000200)            /*!< ADC1 clock enable */
#define  RCC_APB2CCR_TIMER1EN                ((uint32_t)0x00000800)            /*!< TIMER1 clock enable */
#define  RCC_APB2CCR_SPI1EN                  ((uint32_t)0x00001000)            /*!< SPI1 clock enable */
#define  RCC_APB2CCR_USART1EN                ((uint32_t)0x00004000)            /*!< USART1 clock enable */
#define  RCC_APB2CCR_TIMER15EN               ((uint32_t)0x00010000)            /*!< TIMER15 clock enable */
#define  RCC_APB2CCR_TIMER16EN               ((uint32_t)0x00020000)            /*!< TIMER16 clock enable */
#define  RCC_APB2CCR_TIMER17EN               ((uint32_t)0x00040000)            /*!< TIMER17 clock enable */

/*****************  Bit definition for RCC_APB1CCR register  ******************/
#define  RCC_APB1CCR_TIMER2EN                ((uint32_t)0x00000001)            /*!< TIMER2 clock enable */
#define  RCC_APB1CCR_TIMER3EN                ((uint32_t)0x00000002)            /*!< TIMER3 clock enable */
#define  RCC_APB1CCR_TIMER6EN                ((uint32_t)0x00000010)            /*!< TIMER6 clock enable */
#define  RCC_APB1CCR_TIMER14EN               ((uint32_t)0x00000100)            /*!< TIMER14 clock enable */
#ifdef GD32F170_190                                                            
#define  RCC_APB1CCR_LCDREN                  ((uint32_t)0x00000200)            /*!< LCD clock enable */ 
#endif /* GD32F170_190 */                                                      
#define  RCC_APB1CCR_WWDGEN                  ((uint32_t)0x00000800)            /*!< Window Watchdog clock enable */
#define  RCC_APB1CCR_SPI2EN                  ((uint32_t)0x00004000)            /*!< SPI2 clock enable */
#define  RCC_APB1CCR_SPI3EN                  ((uint32_t)0x00008000)            /*!< SPI3 clock enable */
#define  RCC_APB1CCR_USART2EN                ((uint32_t)0x00020000)            /*!< USART2 clock enable */
#define  RCC_APB1CCR_I2C1EN                  ((uint32_t)0x00200000)            /*!< I2C1 clock enable */
#define  RCC_APB1CCR_I2C2EN                  ((uint32_t)0x00400000)            /*!< I2C2 clock enable */
#ifdef GD32F130_150                                                            
#define  RCC_APB1CCR_USBEN                   ((uint32_t)0x00800000)            /*!< USB Device clock enable */
#endif /* GD32F130_150 */                                                      
#ifdef GD32F170_190                                                            
#define  RCC_APB1CCR_CAN1EN                  ((uint32_t)0x02000000)            /*!< CAN 1 clock enable */                                                   
#define  RCC_APB1CCR_CAN2EN                  ((uint32_t)0x04000000)            /*!< CAN 2 clock enable */  
#endif /* GD32F170_190 */                                                      
#define  RCC_APB1CCR_PWREN                   ((uint32_t)0x10000000)            /*!< PWR clock enable */
#define  RCC_APB1CCR_DACEN                   ((uint32_t)0x20000000)            /*!< DAC clock enable */
#define  RCC_APB1CCR_CECEN                   ((uint32_t)0x40000000)            /*!< CEC clock enable */
#ifdef GD32F170_190                                                            
#define  RCC_APB1CCR_OPAMPIVREFEN            ((uint32_t)0x80000000)            /*!< OPAMP and IVREF clock enable */
#endif /* GD32F170_190 */

/*******************  Bit definition for RCC_BDCR register  *******************/
#define  RCC_BDCR_LSEEN                      ((uint32_t)0x00000001)            /*!< External Low Speed oscillator enable */
#define  RCC_BDCR_LSESTB                     ((uint32_t)0x00000002)            /*!< External Low Speed oscillator Ready */
#define  RCC_BDCR_LSEBPS                     ((uint32_t)0x00000004)            /*!< External Low Speed oscillator Bypass */
#define  RCC_BDCR_LSEDRI                     ((uint32_t)0x00000018)            /*!< LSEDRI[1:0] bits (LSE Osc. drive capability) */
#define  RCC_BDCR_LSEDRI_0                   ((uint32_t)0x00000008)            /*!< Bit 0 */
#define  RCC_BDCR_LSEDRI_1                   ((uint32_t)0x00000010)            /*!< Bit 1 */
#define  RCC_BDCR_RTCSEL                     ((uint32_t)0x00000300)            /*!< RTCSEL[1:0] bits (RTC clock source selection) */
#define  RCC_BDCR_RTCSEL_0                   ((uint32_t)0x00000100)            /*!< Bit 0 */
#define  RCC_BDCR_RTCSEL_1                   ((uint32_t)0x00000200)            /*!< Bit 1 */
#define  RCC_BDCR_RTCSEL_NOCLOCK             ((uint32_t)0x00000000)            /*!< No clock */
#define  RCC_BDCR_RTCSEL_LSE                 ((uint32_t)0x00000100)            /*!< LSE oscillator clock used as RTC clock */
#define  RCC_BDCR_RTCSEL_LSI                 ((uint32_t)0x00000200)            /*!< LSI oscillator clock used as RTC clock */
#define  RCC_BDCR_RTCSEL_HSE                 ((uint32_t)0x00000300)            /*!< HSE oscillator clock divided by 128 used as RTC clock */
#define  RCC_BDCR_RTCEN                      ((uint32_t)0x00008000)            /*!< RTC clock enable */
#define  RCC_BDCR_BKPRST                     ((uint32_t)0x00010000)            /*!< Backup domain software reset  */

/*******************  Bit definition for RCC_GCSR register  *******************/  
#define  RCC_GCSR_LSIEN                      ((uint32_t)0x00000001)            /*!< Internal Low Speed oscillator enable */
#define  RCC_GCSR_LSISTB                     ((uint32_t)0x00000002)            /*!< Internal Low Speed oscillator Ready */
#define  RCC_GCSR_V12RSTF                    ((uint32_t)0x00800000)            /*!< V1.8 power domain reset flag */
#define  RCC_GCSR_RSTFC                      ((uint32_t)0x01000000)            /*!< Remove reset flag */
#define  RCC_GCSR_OBLRSTF                    ((uint32_t)0x02000000)            /*!< OBL reset flag */
#define  RCC_GCSR_EPRSTF                     ((uint32_t)0x04000000)            /*!< PIN reset flag */
#define  RCC_GCSR_POPDRSTF                   ((uint32_t)0x08000000)            /*!< POR/PDR reset flag */
#define  RCC_GCSR_SWRSTF                     ((uint32_t)0x10000000)            /*!< Software Reset flag */
#define  RCC_GCSR_IWDGRSTF                   ((uint32_t)0x20000000)            /*!< Independent Watchdog reset flag */
#define  RCC_GCSR_WWDGRSTF                   ((uint32_t)0x40000000)            /*!< Window watchdog reset flag */
#define  RCC_GCSR_LPRSTF                     ((uint32_t)0x80000000)            /*!< Low-Power reset flag */

/*******************  Bit definition for RCC_AHBRCR register  *****************/
#define  RCC_AHBRCR_PARST                    ((uint32_t)0x00020000)            /*!< GPIOA clock reset */
#define  RCC_AHBRCR_PBRST                    ((uint32_t)0x00040000)            /*!< GPIOB clock reset */
#define  RCC_AHBRCR_PCRST                    ((uint32_t)0x00080000)            /*!< GPIOC clock reset */
#define  RCC_AHBRCR_PDRST                    ((uint32_t)0x00010000)            /*!< GPIOD clock reset */
#define  RCC_AHBRCR_PFRST                    ((uint32_t)0x00040000)            /*!< GPIOF clock reset */
#define  RCC_AHBRCR_TSIRST                   ((uint32_t)0x00100000)            /*!< TSI clock reset   */

/*******************  Bit definition for RCC_GCFGR2 register  *****************/
#define  RCC_GCFGR2_HSEPREDV1                ((uint32_t)0x0000000F)            /*!< PREDIV1[3:0] bits */
#define  RCC_GCFGR2_HSEPREDV1_0              ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  RCC_GCFGR2_HSEPREDV1_1              ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  RCC_GCFGR2_HSEPREDV1_2              ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  RCC_GCFGR2_HSEPREDV1_3              ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  RCC_GCFGR2_HSEPREDV1_DIV1           ((uint32_t)0x00000000)            /*!< HSEPREDV1 input clock not divided */
#define  RCC_GCFGR2_HSEPREDV1_DIV2           ((uint32_t)0x00000001)            /*!< HSEPREDV1 input clock divided by 2 */
#define  RCC_GCFGR2_HSEPREDV1_DIV3           ((uint32_t)0x00000002)            /*!< HSEPREDV1 input clock divided by 3 */
#define  RCC_GCFGR2_HSEPREDV1_DIV4           ((uint32_t)0x00000003)            /*!< HSEPREDV1 input clock divided by 4 */
#define  RCC_GCFGR2_HSEPREDV1_DIV5           ((uint32_t)0x00000004)            /*!< HSEPREDV1 input clock divided by 5 */
#define  RCC_GCFGR2_HSEPREDV1_DIV6           ((uint32_t)0x00000005)            /*!< HSEPREDV1 input clock divided by 6 */
#define  RCC_GCFGR2_HSEPREDV1_DIV7           ((uint32_t)0x00000006)            /*!< HSEPREDV1 input clock divided by 7 */
#define  RCC_GCFGR2_HSEPREDV1_DIV8           ((uint32_t)0x00000007)            /*!< HSEPREDV1 input clock divided by 8 */
#define  RCC_GCFGR2_HSEPREDV1_DIV9           ((uint32_t)0x00000008)            /*!< HSEPREDV1 input clock divided by 9 */
#define  RCC_GCFGR2_HSEPREDV1_DIV10          ((uint32_t)0x00000009)            /*!< HSEPREDV1 input clock divided by 10 */
#define  RCC_GCFGR2_HSEPREDV1_DIV11          ((uint32_t)0x0000000A)            /*!< HSEPREDV1 input clock divided by 11 */
#define  RCC_GCFGR2_HSEPREDV1_DIV12          ((uint32_t)0x0000000B)            /*!< HSEPREDV1 input clock divided by 12 */
#define  RCC_GCFGR2_HSEPREDV1_DIV13          ((uint32_t)0x0000000C)            /*!< HSEPREDV1 input clock divided by 13 */
#define  RCC_GCFGR2_HSEPREDV1_DIV14          ((uint32_t)0x0000000D)            /*!< HSEPREDV1 input clock divided by 14 */
#define  RCC_GCFGR2_HSEPREDV1_DIV15          ((uint32_t)0x0000000E)            /*!< HSEPREDV1 input clock divided by 15 */
#define  RCC_GCFGR2_HSEPREDV1_DIV16          ((uint32_t)0x0000000F)            /*!< HSEPREDV1 input clock divided by 16 */


/*******************  Bit definition for RCC_GCFGR3 register  *****************/
#define  RCC_GCFGR3_USART1SEL                ((uint32_t)0x00000003)            /*!< USART1SEL[1:0] bits */
#define  RCC_GCFGR3_USART1SEL_0              ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  RCC_GCFGR3_USART1SEL_1              ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  RCC_GCFGR3_USART1SEL_APB2           ((uint32_t)0x00000000)            /*!< APB2 clock used as USART1 clock */
#define  RCC_GCFGR3_USART1SEL_CK_SYS         ((uint32_t)0x00000001)            /*!< CK_SYS used as USART1 clock */
#define  RCC_GCFGR3_USART1SEL_LSE            ((uint32_t)0x00000002)            /*!< LSE used as USART1 clock */
#define  RCC_GCFGR3_USART1SEL_HSI            ((uint32_t)0x00000003)            /*!< HSI used as USART1 clock */
#define  RCC_GCFGR3_CECSEL                   ((uint32_t)0x00000040)            /*!< CECSEL bits */ 
#define  RCC_GCFGR3_CECSEL_HSI_DIV244        ((uint32_t)0x00000000)            /*!< HSI divided by 244 used as CECclock */
#define  RCC_GCFGR3_CECSEL_LSE               ((uint32_t)0x00000040)            /*!< LSE used as CEC clock */
#define  RCC_GCFGR3_ADCSEL                   ((uint32_t)0x00000100)            /*!< ADCSEL bits */
#ifdef GD32F170_190                                                            
#define  RCC_GCFGR3_ADCSEL_HSI28             ((uint32_t)0x00000000)            /*!< HSI28 used as ADC clock */                                                                                                                                                                                                                                                                                                                                          
#define RCC_GCFGR3_HSI28DIV                  ((uint32_t)0x00010000)            /*!< HSI28DIV bits */                                                                                                                                                                                                               
#define RCC_GCFGR3_HSI28DIV_DIV1             ((uint32_t)0x00010000)            /*!< HSI28 divided by 1 used as ADCclock */                                  
#define RCC_GCFGR3_HSI28DIV_DIV2             ((uint32_t)0x00000000)            /*!< HSI28 divided by 2 used as ADCclock */                                 
#else
#define  RCC_GCFGR3_ADCSEL_HSI14             ((uint32_t)0x00000000)            /*!< HSI14 used as ADC clock */
#endif  /* GD32F170_190 */
#define  RCC_GCFGR3_ADCSEL_APB2              ((uint32_t)0x00000100)            /*!< APB2 used as ADC clock */


#ifdef GD32F170_190
/*******************  Bit definition for RCC_GCCR2 register  ******************/                                                                      
#define  RCC_GCCR2_HSI28EN                   ((uint32_t)0x00000001)            /*!< Internal High Speed 28MHz clock enable */                               
#define  RCC_GCCR2_HSI28STB                  ((uint32_t)0x00000002)            /*!< Internal High Speed 28MHz clock ready flag */                           
#define  RCC_GCCR2_HSI28DIS                  ((uint32_t)0x00000004)            /*!< Internal High Speed 28MHz clock disable */                              
#define  RCC_GCCR2_HSI28ADJ                  ((uint32_t)0x000000F8)            /*!< Internal High Speed 28MHz clock trimming */                             
#define  RCC_GCCR2_HSI28CALIB                ((uint32_t)0x0000FF00)            /*!< Internal High Speed 28MHz clock Calibration */                          
                                                                                                                                                        
/*******************  Bit definition for RCC_GCFGR4 register  *****************/                                                                                                                                                                                           
#define  RCC_GCFGR4_CKOUT2SRC                ((uint32_t)0x00000007)            /*!< CKOUT2SRC[2:0] bits (Microcontroller Clock Output) */                   
#define  RCC_GCFGR4_CKOUT2SRC_0              ((uint32_t)0x00000001)            /*!< Bit 0 */                                                                
#define  RCC_GCFGR4_CKOUT2SRC_1              ((uint32_t)0x00000002)            /*!< Bit 1 */                                                                
#define  RCC_GCFGR4_CKOUT2SRC_2              ((uint32_t)0x00000004)            /*!< Bit 2 */                                                                
#define  RCC_GCFGR4_CKOUT2SRC_NOCLOCK        ((uint32_t)0x00000000)            /*!< No clock */                                                             
#define  RCC_GCFGR4_CKOUT2SRC_HSI28          ((uint32_t)0x00000001)            /*!< HSI28 clock selected as CKOUT2SRC source */                             
#define  RCC_GCFGR4_CKOUT2SRC_LSI            ((uint32_t)0x00000002)            /*!< LSI clock selected as CKOUT2SRC source */                               
#define  RCC_GCFGR4_CKOUT2SRC_LSE            ((uint32_t)0x00000003)            /*!< LSE clock selected as CKOUT2SRC source */                               
#define  RCC_GCFGR4_CKOUT2SRC_SYSCLK         ((uint32_t)0x00000004)            /*!< System clock selected as CKOUT2SRC source */                            
#define  RCC_GCFGR4_CKOUT2SRC_HSI            ((uint32_t)0x00000005)            /*!< HSI clock selected as CKOUT2SRC source */                               
#define  RCC_GCFGR4_CKOUT2SRC_HSE            ((uint32_t)0x00000006)            /*!< HSE clock selected as CKOUT2SRC source */                               
#define  RCC_GCFGR4_CKOUT2SRC_PLL            ((uint32_t)0x00000007)            /*!< CK_PLL or CK_PLL/2 clock selected as CKOUT2SRC source depend on PLLDV */                                                                                                                      
#define  RCC_GCFGR4_CKOUT2DIV                ((uint32_t)0x00003F00)            /*!< CKOUT2DIV[5:0] bits */                                                                                                                                                                                                          
#else
/*******************  Bit definition for RCC_GCCR2 register  ******************/
#define  RCC_GCCR2_HSI14EN                   ((uint32_t)0x00000001)            /*!< Internal High Speed 14MHz clock enable */
#define  RCC_GCCR2_HSI14STB                  ((uint32_t)0x00000002)            /*!< Internal High Speed 14MHz clock ready flag */
#define  RCC_GCCR2_HSI14DIS                  ((uint32_t)0x00000004)            /*!< Internal High Speed 14MHz clock disable */
#define  RCC_GCCR2_HSI14ADJ                  ((uint32_t)0x000000F8)            /*!< Internal High Speed 14MHz clock trimming */
#define  RCC_GCCR2_HSI14CALIB                ((uint32_t)0x0000FF00)            /*!< Internal High Speed 14MHz clock Calibration */
#endif  /* GD32F170_190 */

/*****************  Bit definition for RCC_ACCR register  *********************/
#define  RCC_ACCR_I2C3EN                     ((uint32_t)0x00000001)            /*!< I2C3 clock enable */

/*****************  Bit definition for RCC_ARCR register  *********************/
#define  RCC_ARCR_I2C3RST                    ((uint32_t)0x00000001)            /*!< I2C3 clock reset */

/*****************  Bit definition for RCC_DEEPSLEEP_VC register  *************/
#define  RCC_DEEPSLEEP_VC_CLEAR              ((uint32_t)0x00000007)            /*!< RCC_DEEPSLEEP_VC[2:0] bits */
#define  RCC_DEEPSLEEP_VC_0                  ((uint32_t)0x00000000)            /*!< Bit 0 bits */
#define  RCC_DEEPSLEEP_VC_1                  ((uint32_t)0x00000002)            /*!< Bit 1 bits */
#define  RCC_DEEPSLEEP_VC_2                  ((uint32_t)0x00000004)            /*!< Bit 2 bits */
#ifdef GD32F170_190
#define  RCC_DEEPSLEEP_VC1_8                 ((uint32_t)0x00000000)            /*!< The kernel voltage in Deep-sleep mode is 1.8V */                        
#define  RCC_DEEPSLEEP_VC1_6                 ((uint32_t)0x00000001)            /*!< The kernel voltage in Deep-sleep is 1.6V */                             
#define  RCC_DEEPSLEEP_VC1_4                 ((uint32_t)0x00000002)            /*!< The kernel voltage in Deep-sleep is 1.4V */                             
#define  RCC_DEEPSLEEP_VC1_2                 ((uint32_t)0x00000003)            /*!< The kernel voltage in Deep-sleep is 1.2V */                   
#else
#define  RCC_DEEPSLEEP_VC1_2                 ((uint32_t)0x00000000)            /*!< The kernel voltage in Deep-sleep mode is 1.2V */
#define  RCC_DEEPSLEEP_VC1_1                 ((uint32_t)0x00000001)            /*!< The kernel voltage in Deep-sleep is 1.1V */
#define  RCC_DEEPSLEEP_VC1_0                 ((uint32_t)0x00000002)            /*!< The kernel voltage in Deep-sleep is 1.0V */
#define  RCC_DEEPSLEEP_VC0_9                 ((uint32_t)0x00000003)            /*!< The kernel voltage in Deep-sleep is 0.9V */

/*****************  Bit definition for RCC_PDR_S register  ********************/
#define  RCC_PDR_S_CLEAR                     ((uint32_t)0x00000001)            /*!< RCC_PDR_S[0] bits */
#define  RCC_PDR_S2_6                        ((uint32_t)0x00000000)            /*!< The voltage of power down is 2.6V */
#define  RCC_PDR_S1_8                        ((uint32_t)0x00000001)            /*!< The voltage of power down is 1.8V */
#endif /* GD32F170_190 */
           

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RTC_TR register  *******************/
#define  RTC_TR_SU                           ((uint32_t)0x0000000F)            /*!< Second units in BCD code */
#define  RTC_TR_SU_0                         ((uint32_t)0x00000001)            /*!< Bit 0 bits */
#define  RTC_TR_SU_1                         ((uint32_t)0x00000002)            /*!< Bit 1 bits */
#define  RTC_TR_SU_2                         ((uint32_t)0x00000004)            /*!< Bit 2 bits */
#define  RTC_TR_SU_3                         ((uint32_t)0x00000008)            /*!< Bit 3 bits */
#define  RTC_TR_ST                           ((uint32_t)0x00000070)            /*!< Second tens in BCD code */
#define  RTC_TR_ST_0                         ((uint32_t)0x00000010)            /*!< Bit 0 bits */
#define  RTC_TR_ST_1                         ((uint32_t)0x00000020)            /*!< Bit 1 bits */
#define  RTC_TR_ST_2                         ((uint32_t)0x00000040)            /*!< Bit 2 bits */
#define  RTC_TR_MNU                          ((uint32_t)0x00000F00)            /*!< Minute units in BCD code */
#define  RTC_TR_MNU_0                        ((uint32_t)0x00000100)            /*!< Bit 0 bits */
#define  RTC_TR_MNU_1                        ((uint32_t)0x00000200)            /*!< Bit 1 bits */
#define  RTC_TR_MNU_2                        ((uint32_t)0x00000400)            /*!< Bit 2 bits */
#define  RTC_TR_MNU_3                        ((uint32_t)0x00000800)            /*!< Bit 3 bits */
#define  RTC_TR_MNT                          ((uint32_t)0x00007000)            /*!< Minute tens in BCD code */
#define  RTC_TR_MNT_0                        ((uint32_t)0x00001000)            /*!< Bit 0 bits */
#define  RTC_TR_MNT_1                        ((uint32_t)0x00002000)            /*!< Bit 1 bits */
#define  RTC_TR_MNT_2                        ((uint32_t)0x00004000)            /*!< Bit 2 bits */
#define  RTC_TR_HU                           ((uint32_t)0x000F0000)            /*!< Hour units in BCD code */
#define  RTC_TR_HU_0                         ((uint32_t)0x00010000)            /*!< Bit 0 bits */
#define  RTC_TR_HU_1                         ((uint32_t)0x00020000)            /*!< Bit 1 bits */
#define  RTC_TR_HU_2                         ((uint32_t)0x00040000)            /*!< Bit 2 bits */
#define  RTC_TR_HU_3                         ((uint32_t)0x00080000)            /*!< Bit 3 bits */
#define  RTC_TR_HT                           ((uint32_t)0x00300000)            /*!< Hour tens in BCD code */
#define  RTC_TR_HT_0                         ((uint32_t)0x00100000)            /*!< Bit 0 bits */
#define  RTC_TR_HT_1                         ((uint32_t)0x00200000)            /*!< Bit 1 bits */
#define  RTC_TR_PM                           ((uint32_t)0x00400000)            /*!< AM/PM notation */

/********************  Bits definition for RTC_DR register  *******************/
#define  RTC_DR_DU                           ((uint32_t)0x0000000F)            /*!< Date units in BCD code */
#define  RTC_DR_DU_0                         ((uint32_t)0x00000001)            /*!< Bit 0 bits */
#define  RTC_DR_DU_1                         ((uint32_t)0x00000002)            /*!< Bit 1 bits */
#define  RTC_DR_DU_2                         ((uint32_t)0x00000004)            /*!< Bit 2 bits */
#define  RTC_DR_DU_3                         ((uint32_t)0x00000008)            /*!< Bit 3 bits */
#define  RTC_DR_DT                           ((uint32_t)0x00000030)            /*!< Date tens in BCD code */
#define  RTC_DR_DT_0                         ((uint32_t)0x00000010)            /*!< Bit 0 bits */
#define  RTC_DR_DT_1                         ((uint32_t)0x00000020)            /*!< Bit 1 bits */
#define  RTC_DR_MU                           ((uint32_t)0x00000F00)            /*!< Month units in BCD code */
#define  RTC_DR_MU_0                         ((uint32_t)0x00000100)            /*!< Bit 0 bits */
#define  RTC_DR_MU_1                         ((uint32_t)0x00000200)            /*!< Bit 1 bits */
#define  RTC_DR_MU_2                         ((uint32_t)0x00000400)            /*!< Bit 2 bits */
#define  RTC_DR_MU_3                         ((uint32_t)0x00000800)            /*!< Bit 3 bits */
#define  RTC_DR_MT                           ((uint32_t)0x00001000)            /*!< Month tens in BCD code */
#define  RTC_DR_WDU                          ((uint32_t)0x0000E000)            /*!< Week day units */
#define  RTC_DR_WDU_0                        ((uint32_t)0x00002000)            /*!< Bit 0 bits */
#define  RTC_DR_WDU_1                        ((uint32_t)0x00004000)            /*!< Bit 1 bits */
#define  RTC_DR_WDU_2                        ((uint32_t)0x00008000)            /*!< Bit 2 bits */
#define  RTC_DR_YU                           ((uint32_t)0x000F0000)            /*!< Year units in BCD code */
#define  RTC_DR_YU_0                         ((uint32_t)0x00010000)            /*!< Bit 0 bits */
#define  RTC_DR_YU_1                         ((uint32_t)0x00020000)            /*!< Bit 1 bits */
#define  RTC_DR_YU_2                         ((uint32_t)0x00040000)            /*!< Bit 2 bits */
#define  RTC_DR_YU_3                         ((uint32_t)0x00080000)            /*!< Bit 3 bits */
#define  RTC_DR_YT                           ((uint32_t)0x00F00000)            /*!< Year tens in BCD code */
#define  RTC_DR_YT_0                         ((uint32_t)0x00100000)            /*!< Bit 0 bits */
#define  RTC_DR_YT_1                         ((uint32_t)0x00200000)            /*!< Bit 1 bits */
#define  RTC_DR_YT_2                         ((uint32_t)0x00400000)            /*!< Bit 2 bits */
#define  RTC_DR_YT_3                         ((uint32_t)0x00800000)            /*!< Bit 3 bits */

/********************  Bits definition for RTC_CTLR register  *****************/
#define  RTC_CTLR_TSEDGE                     ((uint32_t)0x00000008)            /*!< Valid event edge of time-stamp */
#define  RTC_CTLR_REFCKON                    ((uint32_t)0x00000010)            /*!< Reference clock detection function enable */
#define  RTC_CTLR_BYPSHAD                    ((uint32_t)0x00000020)            /*!< Shadow registers bypass control */
#define  RTC_CTLR_FMT                        ((uint32_t)0x00000040)            /*!< Display format of time */
#define  RTC_CTLR_AE                         ((uint32_t)0x00000100)            /*!< alarm function enable */
#define  RTC_CTLR_TSEN                       ((uint32_t)0x00000800)            /*!< time-stamp function enable */
#define  RTC_CTLR_AIE                        ((uint32_t)0x00001000)            /*!< RTC alarm interrupt enable */
#define  RTC_CTLR_TSIE                       ((uint32_t)0x00008000)            /*!< Time-stamp interrupt enable */
#define  RTC_CTLR_A1H                        ((uint32_t)0x00010000)            /*!< Add 1 hour(summer time change) */
#define  RTC_CTLR_S1H                        ((uint32_t)0x00020000)            /*!< Subtract 1 hour(winter time change) */
#define  RTC_CTLR_BKP                        ((uint32_t)0x00040000)            /*!< Backup */
#define  RTC_CTLR_COS                        ((uint32_t)0x00080000)            /*!< Calibration output selection */
#define  RTC_CTLR_OPOL                       ((uint32_t)0x00100000)            /*!< Output polarity */
#define  RTC_CTLR_OS                         ((uint32_t)0x00600000)            /*!< Output selection */
#define  RTC_CTLR_OS_0                       ((uint32_t)0x00200000)            /*!< Bit 0 bits */
#define  RTC_CTLR_OS_1                       ((uint32_t)0x00400000)            /*!< Bit 1 bits */
#define  RTC_CTLR_COEN                       ((uint32_t)0x00800000)            /*!< Calibration output enable */

/********************  Bits definition for RTC_STR register  ******************/
#define  RTC_STR_AWF                         ((uint32_t)0x00000001)            /*!< Alarm configuration can be write flag */
#define  RTC_STR_SHPF                        ((uint32_t)0x00000008)            /*!< Shift function operation pending flag */
#define  RTC_STR_INITS                       ((uint32_t)0x00000010)            /*!< Calendar initialization status flag */
#define  RTC_STR_RSF                         ((uint32_t)0x00000020)            /*!< Register synchronization flag */
#define  RTC_STR_INITF                       ((uint32_t)0x00000040)            /*!< Initialization state flag */
#define  RTC_STR_INIT                        ((uint32_t)0x00000080)            /*!< Enter initialization mode */
#define  RTC_STR_AF                          ((uint32_t)0x00000100)            /*!< Alarm occurs flag */
#define  RTC_STR_TSF                         ((uint32_t)0x00000800)            /*!< Time-stamp flag */
#define  RTC_STR_TSOVF                       ((uint32_t)0x00001000)            /*!< Time-stamp overflow flag */
#define  RTC_STR_TAMP1F                      ((uint32_t)0x00002000)            /*!< RTC_TAMP1 detected flag */
#define  RTC_STR_TAMP2F                      ((uint32_t)0x00004000)            /*!< RTC_TAMP2 detected flag */
#define  RTC_STR_RECALPF                     ((uint32_t)0x00010000)            /*!< Recalibration pending flag */

/********************  Bits definition for RTC_PSCR register  *****************/
#define  RTC_PSCR_PREDIV_S                   ((uint32_t)0x00007FFF)            /*!< Asynchronous prescaler factor */
#define  RTC_PSCR_PREDIV_A                   ((uint32_t)0x007F0000)            /*!< synchronous prescaler factor */

/********************  Bits definition for RTC_ALRMR register  ****************/
#define  RTC_ALRMR_SU                        ((uint32_t)0x0000000F)            /*!< Second units in BCD code */
#define  RTC_ALRMR_SU_0                      ((uint32_t)0x00000001)            /*!< Bit 0 bits */
#define  RTC_ALRMR_SU_1                      ((uint32_t)0x00000002)            /*!< Bit 1 bits */
#define  RTC_ALRMR_SU_2                      ((uint32_t)0x00000004)            /*!< Bit 2 bits */
#define  RTC_ALRMR_SU_3                      ((uint32_t)0x00000008)            /*!< Bit 3 bits */
#define  RTC_ALRMR_ST                        ((uint32_t)0x00000070)            /*!< Second tens in BCD code */
#define  RTC_ALRMR_ST_0                      ((uint32_t)0x00000010)            /*!< Bit 0 bits */
#define  RTC_ALRMR_ST_1                      ((uint32_t)0x00000020)            /*!< Bit 1 bits */
#define  RTC_ALRMR_ST_2                      ((uint32_t)0x00000040)            /*!< Bit 2 bits */
#define  RTC_ALRMR_MSK1                      ((uint32_t)0x00000080)            /*!< Alarm second mask bit */
#define  RTC_ALRMR_MNU                       ((uint32_t)0x00000F00)            /*!< Minutes units in BCD code */
#define  RTC_ALRMR_MNU_0                     ((uint32_t)0x00000100)            /*!< Bit 0 bits */
#define  RTC_ALRMR_MNU_1                     ((uint32_t)0x00000200)            /*!< Bit 1 bits */
#define  RTC_ALRMR_MNU_2                     ((uint32_t)0x00000400)            /*!< Bit 2 bits */
#define  RTC_ALRMR_MNU_3                     ((uint32_t)0x00000800)            /*!< Bit 3 bits */
#define  RTC_ALRMR_MNT                       ((uint32_t)0x00007000)            /*!< Minutes tens in BCD code */
#define  RTC_ALRMR_MNT_0                     ((uint32_t)0x00001000)            /*!< Bit 0 bits */
#define  RTC_ALRMR_MNT_1                     ((uint32_t)0x00002000)            /*!< Bit 1 bits */
#define  RTC_ALRMR_MNT_2                     ((uint32_t)0x00004000)            /*!< Bit 2 bits */
#define  RTC_ALRMR_MSK2                      ((uint32_t)0x00008000)            /*!< Alarm minutes mask bit */
#define  RTC_ALRMR_HU                        ((uint32_t)0x000F0000)            /*!< Hour units in BCD code */
#define  RTC_ALRMR_HU_0                      ((uint32_t)0x00010000)            /*!< Bit 0 bits */
#define  RTC_ALRMR_HU_1                      ((uint32_t)0x00020000)            /*!< Bit 1 bits */
#define  RTC_ALRMR_HU_2                      ((uint32_t)0x00040000)            /*!< Bit 2 bits */
#define  RTC_ALRMR_HU_3                      ((uint32_t)0x00080000)            /*!< Bit 3 bits */
#define  RTC_ALRMR_HT                        ((uint32_t)0x00300000)            /*!< Hour tens in BCD code */
#define  RTC_ALRMR_HT_0                      ((uint32_t)0x00100000)            /*!< Bit 0 bits */
#define  RTC_ALRMR_HT_1                      ((uint32_t)0x00200000)            /*!< Bit 1 bits */
#define  RTC_ALRMR_PM                        ((uint32_t)0x00400000)            /*!< AM/PM flag */
#define  RTC_ALRMR_MSK3                      ((uint32_t)0x00800000)            /*!< Alarm hour mask bit */
#define  RTC_ALRMR_DU                        ((uint32_t)0x0F000000)            /*!< Date units or week day in BCD code */
#define  RTC_ALRMR_DU_0                      ((uint32_t)0x01000000)            /*!< Bit 0 bits */
#define  RTC_ALRMR_DU_1                      ((uint32_t)0x02000000)            /*!< Bit 1 bits */
#define  RTC_ALRMR_DU_2                      ((uint32_t)0x04000000)            /*!< Bit 2 bits */
#define  RTC_ALRMR_DU_3                      ((uint32_t)0x08000000)            /*!< Bit 3 bits */
#define  RTC_ALRMR_DT                        ((uint32_t)0x30000000)            /*!< Date tens in BCD code */
#define  RTC_ALRMR_DT_0                      ((uint32_t)0x10000000)            /*!< Bit 0 bits */
#define  RTC_ALRMR_DT_1                      ((uint32_t)0x20000000)            /*!< Bit 0 bits */
#define  RTC_ALRMR_WDSEL                     ((uint32_t)0x40000000)            /*!< Week day selection */
#define  RTC_ALRMR_MSK4                      ((uint32_t)0x80000000)            /*!< Alarm date mask bit */

/********************  Bits definition for RTC_WPR register  ******************/
#define  RTC_WPR_KEY                         ((uint32_t)0x000000FF)            /*!< Key for write protection */

/********************  Bits definition for RTC_SSR register  ******************/
#define  RTC_SSR_SS                          ((uint32_t)0x0003FFFF)            /*!< Sub second value */

/********************  Bits definition for RTC_SHIFTCTLR register  ************/
#define  RTC_SHIFTCTLR_SFS                   ((uint32_t)0x00007FFF)            /*!< Subtract a fraction of a second */
#define  RTC_SHIFTCTLR_A1S                   ((uint32_t)0x80000000)            /*!< One second add */

/********************  Bits definition for RTC_TSTR register  *****************/
#define  RTC_TSTR_SU                         ((uint32_t)0x0000000F)            /*!< Second units in BCD code */
#define  RTC_TSTR_SU_0                       ((uint32_t)0x00000001)            /*!< Bit 0 bits */
#define  RTC_TSTR_SU_1                       ((uint32_t)0x00000002)            /*!< Bit 1 bits */
#define  RTC_TSTR_SU_2                       ((uint32_t)0x00000004)            /*!< Bit 2 bits */
#define  RTC_TSTR_SU_3                       ((uint32_t)0x00000008)            /*!< Bit 3 bits */
#define  RTC_TSTR_ST                         ((uint32_t)0x00000070)            /*!< Second tens in BCD code */
#define  RTC_TSTR_ST_0                       ((uint32_t)0x00000010)            /*!< Bit 0 bits */
#define  RTC_TSTR_ST_1                       ((uint32_t)0x00000020)            /*!< Bit 1 bits */
#define  RTC_TSTR_ST_2                       ((uint32_t)0x00000040)            /*!< Bit 2 bits */
#define  RTC_TSTR_MNU                        ((uint32_t)0x00000F00)            /*!< Minute units in BCD code */
#define  RTC_TSTR_MNU_0                      ((uint32_t)0x00000100)            /*!< Bit 0 bits */
#define  RTC_TSTR_MNU_1                      ((uint32_t)0x00000200)            /*!< Bit 1 bits */
#define  RTC_TSTR_MNU_2                      ((uint32_t)0x00000400)            /*!< Bit 2 bits */
#define  RTC_TSTR_MNU_3                      ((uint32_t)0x00000800)            /*!< Bit 3 bits */
#define  RTC_TSTR_MNT                        ((uint32_t)0x00007000)            /*!< Minute tens in BCD code */
#define  RTC_TSTR_MNT_0                      ((uint32_t)0x00001000)            /*!< Bit 0 bits */
#define  RTC_TSTR_MNT_1                      ((uint32_t)0x00002000)            /*!< Bit 1 bits */
#define  RTC_TSTR_MNT_2                      ((uint32_t)0x00004000)            /*!< Bit 2 bits */
#define  RTC_TSTR_HU                         ((uint32_t)0x000F0000)            /*!< Hour units in BCD code */
#define  RTC_TSTR_HU_0                       ((uint32_t)0x00010000)            /*!< Bit 0 bits */
#define  RTC_TSTR_HU_1                       ((uint32_t)0x00020000)            /*!< Bit 1 bits */
#define  RTC_TSTR_HU_2                       ((uint32_t)0x00040000)            /*!< Bit 2 bits */
#define  RTC_TSTR_HU_3                       ((uint32_t)0x00080000)            /*!< Bit 3 bits */
#define  RTC_TSTR_HT                         ((uint32_t)0x00300000)            /*!< Hour tens in BCD code */
#define  RTC_TSTR_HT_0                       ((uint32_t)0x00100000)            /*!< Bit 0 bits */
#define  RTC_TSTR_HT_1                       ((uint32_t)0x00200000)            /*!< Bit 1 bits */
#define  RTC_TSTR_PM                         ((uint32_t)0x00400000)            /*!< AM/PM notation */

/********************  Bits definition for RTC_TSDR register  *****************/
#define  RTC_TSDR_DU                         ((uint32_t)0x0000000F)            /*!< Date units in BCD code */
#define  RTC_TSDR_DU_0                       ((uint32_t)0x00000001)            /*!< Bit 0 bits */
#define  RTC_TSDR_DU_1                       ((uint32_t)0x00000002)            /*!< Bit 1 bits */
#define  RTC_TSDR_DU_2                       ((uint32_t)0x00000004)            /*!< Bit 2 bits */
#define  RTC_TSDR_DU_3                       ((uint32_t)0x00000008)            /*!< Bit 3 bits */
#define  RTC_TSDR_MU_3                       ((uint32_t)0x00000800)            /*!< Date tens in BCD code */
#define  RTC_TSDR_DT                         ((uint32_t)0x00000030)            /*!< Bit 0 bits */
#define  RTC_TSDR_DT_0                       ((uint32_t)0x00000010)            /*!< Bit 1 bits */
#define  RTC_TSDR_DT_1                       ((uint32_t)0x00000020)            /*!< Bit 2 bits */
#define  RTC_TSDR_MU                         ((uint32_t)0x00000F00)            /*!< Month units in BCD code */
#define  RTC_TSDR_MU_0                       ((uint32_t)0x00000100)            /*!< Bit 0 bits */
#define  RTC_TSDR_MU_1                       ((uint32_t)0x00000200)            /*!< Bit 1 bits */
#define  RTC_TSDR_MU_2                       ((uint32_t)0x00000400)            /*!< Bit 2 bits */
#define  RTC_TSDR_MT                         ((uint32_t)0x00001000)            /*!< Month tens in BCD code */
#define  RTC_TSDR_WDU                        ((uint32_t)0x0000E000)            /*!< Week day units */
#define  RTC_TSDR_WDU_0                      ((uint32_t)0x00002000)            /*!< Bit 0 bits */
#define  RTC_TSDR_WDU_1                      ((uint32_t)0x00004000)            /*!< Bit 1 bits */
#define  RTC_TSDR_WDU_2                      ((uint32_t)0x00008000)            /*!< Bit 2 bits */

/********************  Bits definition for RTC_TSSSR register  ****************/
#define  RTC_TSSSR_SS                        ((uint32_t)0x0003FFFF)            /*!< Bit 0 bits */

/********************  Bits definition for RTC_CCR register  ******************/
#define  RTC_CCR_CMSK                        ((uint32_t)0x000001FF)            /*!< Calibration mask number */
#define  RTC_CCR_CMSK_0                      ((uint32_t)0x00000001)            /*!< Bit 0 bits */
#define  RTC_CCR_CMSK_1                      ((uint32_t)0x00000002)            /*!< Bit 1 bits */
#define  RTC_CCR_CMSK_2                      ((uint32_t)0x00000004)            /*!< Bit 2 bits */
#define  RTC_CCR_CMSK_3                      ((uint32_t)0x00000008)            /*!< Bit 3 bits */
#define  RTC_CCR_CMSK_4                      ((uint32_t)0x00000010)            /*!< Bit 4 bits */
#define  RTC_CCR_CMSK_5                      ((uint32_t)0x00000020)            /*!< Bit 5 bits */
#define  RTC_CCR_CMSK_6                      ((uint32_t)0x00000040)            /*!< Bit 6 bits */
#define  RTC_CCR_CMSK_7                      ((uint32_t)0x00000080)            /*!< Bit 7 bits */
#define  RTC_CCR_CMSK_8                      ((uint32_t)0x00000100)            /*!< Bit 8 bits */
#define  RTC_CCR_CWND16                      ((uint32_t)0x00002000)            /*!< Calibration window select 16 seconds */
#define  RTC_CCR_CWND8                       ((uint32_t)0x00004000)            /*!< Calibration window select 8 seconds */
#define  RTC_CCR_CALP                        ((uint32_t)0x00008000)            /*!< Bit 0 bits */

/********************  Bits definition for RTC_TAFCR register  ****************/
#define  RTC_TAFCR_TAP1EN                    ((uint32_t)0x00000001)            /*!< Tamper 1 detection enable */
#define  RTC_TAFCR_TAP1TRIG                  ((uint32_t)0x00000002)            /*!< Tamper 1 event trigger edge for RTC_TAMP1 input */
#define  RTC_TAFCR_TAPIE                     ((uint32_t)0x00000004)            /*!< Tamper detection interrupt enable */
#define  RTC_TAFCR_TAP2EN                    ((uint32_t)0x00000008)            /*!< Tamper 2 detection enable */
#define  RTC_TAFCR_TAP2TRIG                  ((uint32_t)0x00000010)            /*!< Tamper 2 event trigger edge for RTC_TAMP2 input */
#define  RTC_TAFCR_TAPTS                     ((uint32_t)0x00000080)            /*!< Make tamper function used for timestamp function */
#define  RTC_TAFCR_FREQ                      ((uint32_t)0x00000700)            /*!< Sample frequency of tamper event detection */
#define  RTC_TAFCR_FREQ_0                    ((uint32_t)0x00000100)            /*!< Bit 0 bits */
#define  RTC_TAFCR_FREQ_1                    ((uint32_t)0x00000200)            /*!< Bit 1 bits */
#define  RTC_TAFCR_FREQ_2                    ((uint32_t)0x00000400)            /*!< Bit 2 bits */
#define  RTC_TAFCR_FLIT                      ((uint32_t)0x00001800)            /*!< RTC_TAMPx filter count setting */
#define  RTC_TAFCR_FLIT_0                    ((uint32_t)0x00000800)            /*!< Bit 0 bits */
#define  RTC_TAFCR_FLIT_1                    ((uint32_t)0x00001000)            /*!< Bit 1 bits */
#define  RTC_TAFCR_PRCH                      ((uint32_t)0x00006000)            /*!< Precharge duration time of RTC_TAMPx */
#define  RTC_TAFCR_PRCH_0                    ((uint32_t)0x00002000)            /*!< Bit 0 bits */
#define  RTC_TAFCR_PRCH_1                    ((uint32_t)0x00004000)            /*!< Bit 1 bits */
#define  RTC_TAFCR_DISPU                     ((uint32_t)0x00008000)            /*!< RTC_TAMPx pull up disable bit */
#define  RTC_TAFCR_PC13VALUE                 ((uint32_t)0x00040000)            /*!< Alarm output type control/PC13 output value */
#define  RTC_TAFCR_PC13MODE                  ((uint32_t)0x00080000)            /*!< PC13 mode */
#define  RTC_TAFCR_PC14VALUE                 ((uint32_t)0x00100000)            /*!< Alarm output type control/PC14 output value */
#define  RTC_TAFCR_PC14MODE                  ((uint32_t)0x00200000)            /*!< PC14 mode */
#define  RTC_TAFCR_PC15VALUE                 ((uint32_t)0x00400000)            /*!< Alarm output type control/PC15 output value */
#define  RTC_TAFCR_PC15MODE                  ((uint32_t)0x00800000)            /*!< PC15 mode */

/********************  Bits definition for RTC_ALARMSSR register  *************/
#define  RTC_ALARMSSR_SS                     ((uint32_t)0x00007FFF)            /*!< Alarm sub second value */
#define  RTC_ALARMSSR_MASKSS                 ((uint32_t)0x0F000000)            /*!< Mask control bit of SS */
#define  RTC_ALARMSSR_MASKSS_0               ((uint32_t)0x01000000)            /*!< Bit 0 bits */
#define  RTC_ALARMSSR_MASKSS_1               ((uint32_t)0x02000000)            /*!< Bit 1 bits */
#define  RTC_ALARMSSR_MASKSS_2               ((uint32_t)0x04000000)            /*!< Bit 2 bits */
#define  RTC_ALARMSSR_MASKSS_3               ((uint32_t)0x08000000)            /*!< Bit 3 bits */

/********************  Bits definition for RTC_BKP0R register  ****************/
#define  RTC_BKP0R                           ((uint32_t)0xFFFFFFFF)            /*!< Backup domain registers */

/********************  Bits definition for RTC_BKP1R register  ****************/
#define  RTC_BKP1R                           ((uint32_t)0xFFFFFFFF)            /*!< Backup domain registers */

/********************  Bits definition for RTC_BKP2R register  ****************/
#define  RTC_BKP2R                           ((uint32_t)0xFFFFFFFF)            /*!< Backup domain registers */

/********************  Bits definition for RTC_BKP3R register  ****************/
#define  RTC_BKP3R                           ((uint32_t)0xFFFFFFFF)            /*!< Backup domain registers */

/********************  Bits definition for RTC_BKP4R register  ****************/
#define  RTC_BKP4R                           ((uint32_t)0xFFFFFFFF)            /*!< Backup domain registers */


/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface                         */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for SPI_CTLR1 register  ******************/
#define  SPI_CTLR1_SCKPH                     ((uint16_t)0x0001)                /*!< Clock Phase */
#define  SPI_CTLR1_SCKPL                     ((uint16_t)0x0002)                /*!< Clock Polarity */
#define  SPI_CTLR1_MSTMODE                   ((uint16_t)0x0004)                /*!< Master Selection */

#define  SPI_CTLR1_PSC                       ((uint16_t)0x0038)                /*!< PSC[2:0] bits (Baud Rate Control) */
#define  SPI_CTLR1_PSC_0                     ((uint16_t)0x0008)                /*!< Bit 0 */
#define  SPI_CTLR1_PSC_1                     ((uint16_t)0x0010)                /*!< Bit 1 */
#define  SPI_CTLR1_PSC_2                     ((uint16_t)0x0020)                /*!< Bit 2 */

#define  SPI_CTLR1_SPIEN                     ((uint16_t)0x0040)                /*!< SPI Enable */
#define  SPI_CTLR1_LF                        ((uint16_t)0x0080)                /*!< Frame Format */
#define  SPI_CTLR1_SWNSS                     ((uint16_t)0x0100)                /*!< Internal slave select */
#define  SPI_CTLR1_SWNSSEN                   ((uint16_t)0x0200)                /*!< Software slave management */
#define  SPI_CTLR1_RO                        ((uint16_t)0x0400)                /*!< Receive only */
#define  SPI_CTLR1_FF16                      ((uint16_t)0x0800)                /*!< Data Frame Format */
#define  SPI_CTLR1_CRCNT                     ((uint16_t)0x1000)                /*!< Transmit CRC next */
#define  SPI_CTLR1_CRCEN                     ((uint16_t)0x2000)                /*!< Hardware CRC calculation enable */
#define  SPI_CTLR1_BDOE                      ((uint16_t)0x4000)                /*!< Output enable in bidirectional mode */
#define  SPI_CTLR1_BDM                       ((uint16_t)0x8000)                /*!< Bidirectional data mode enable */

/*******************  Bit definition for SPI_CTLR2 register  ******************/
#define  SPI_CTLR2_DMARE                     ((uint8_t)0x01)                   /*!< Rx Buffer DMA Enable */
#define  SPI_CTLR2_DMATE                     ((uint8_t)0x02)                   /*!< Tx Buffer DMA Enable */
#define  SPI_CTLR2_NSSDRV                    ((uint8_t)0x04)                   /*!< SS Output Enable */
#define  SPI_CTLR2_ERRIE                     ((uint8_t)0x20)                   /*!< Error Interrupt Enable */
#define  SPI_CTLR2_RBNEIE                    ((uint8_t)0x40)                   /*!< RX buffer Not Empty Interrupt Enable */
#define  SPI_CTLR2_TBEIE                     ((uint8_t)0x80)                   /*!< Tx buffer Empty Interrupt Enable */

/********************  Bit definition for SPI_STR register  *******************/
#define  SPI_STR_RBNE                        ((uint8_t)0x01)                   /*!< Receive buffer Not Empty */
#define  SPI_STR_TBE                         ((uint8_t)0x02)                   /*!< Transmit buffer Empty */
#define  SPI_STR_I2SCH                       ((uint8_t)0x04)                   /*!< Channel side */
#define  SPI_STR_TXURE                       ((uint8_t)0x08)                   /*!< Underrun flag */
#define  SPI_STR_CRCE                        ((uint8_t)0x10)                   /*!< CRC Error flag */
#define  SPI_STR_CONFE                       ((uint8_t)0x20)                   /*!< Mode fault */
#define  SPI_STR_RXORE                       ((uint8_t)0x40)                   /*!< Overrun flag */
#define  SPI_STR_TRANS                       ((uint8_t)0x80)                   /*!< Busy flag */

/********************  Bit definition for SPI_DTR register  *******************/
#define  SPI_DTR_DTR                         ((uint16_t)0xFFFF)                /*!< Data Register */

/*******************  Bit definition for SPI_CRR register  ********************/
#define  SPI_CPR_CPR                         ((uint16_t)0xFFFF)                /*!< CRC polynomial register */

/******************  Bit definition for SPI_RCR register  *********************/
#define  SPI_RCR_RCR                         ((uint16_t)0xFFFF)                /*!< Rx CRC Register */

/******************  Bit definition for SPI_TCR register  *********************/
#define  SPI_TCR_TCR                         ((uint16_t)0xFFFF)                /*!< Tx CRC Register */

/******************  Bit definition for SPI_I2SCTLR register  *****************/
#define  SPI_I2SCTLR_CHLEN                   ((uint16_t)0x0001)                /*!< Channel length (number of bits per audio channel) */

#define  SPI_I2SCTLR_DTLEN                   ((uint16_t)0x0006)                /*!< DTLEN[1:0] bits (Data length to be transferred) */
#define  SPI_I2SCTLR_DTLEN_0                 ((uint16_t)0x0002)                /*!< Bit 0 */
#define  SPI_I2SCTLR_DTLEN_1                 ((uint16_t)0x0004)                /*!< Bit 1 */

#define  SPI_I2SCTLR_CKPL                    ((uint16_t)0x0008)                /*!< steady state clock polarity */

#define  SPI_I2SCTLR_I2SSTD                  ((uint16_t)0x0030)                /*!< I2SSTD[1:0] bits (I2S standard selection) */
#define  SPI_I2SCTLR_I2SSTD_0                ((uint16_t)0x0010)                /*!< Bit 0 */
#define  SPI_I2SCTLR_I2SSTD_1                ((uint16_t)0x0020)                /*!< Bit 1 */

#define  SPI_I2SCTLR_PCMSM                   ((uint16_t)0x0080)                /*!< PCM frame synchronization */

#define  SPI_I2SCTLR_I2SOM                   ((uint16_t)0x0300)                /*!< I2SOM[1:0] bits (I2S configuration mode) */
#define  SPI_I2SCTLR_I2SOM_0                 ((uint16_t)0x0100)                /*!< Bit 0 */
#define  SPI_I2SCTLR_I2SOM_1                 ((uint16_t)0x0200)                /*!< Bit 1 */

#define  SPI_I2SCTLR_I2SEN                   ((uint16_t)0x0400)                /*!< I2S Enable */
#define  SPI_I2SCTLR_I2SSEL                  ((uint16_t)0x0800)                /*!< I2S mode selection */

/******************  Bit definition for SPI_I2SCKP register  ******************/
#define  SPI_I2SCKP_DIV                      ((uint16_t)0x00FF)                /*!< I2S Linear prescaler */
#define  SPI_I2SCKP_OF                       ((uint16_t)0x0100)                /*!< Odd factor for the prescaler */
#define  SPI_I2SCKP_MCKOE                    ((uint16_t)0x0200)                /*!< Master Clock Output Enable */

#ifdef GD32F170_190
/******************  Bit definition for SPI_QWCR register  ********************/
#define  SPI_QWCR_QMOD                       ((uint16_t)0x0001)                /*!< Quad wire mode Enable */
#define  SPI_QWCR_QRD                        ((uint16_t)0x0002)                /*!< Quad wire read select */
#define  SPI_QWCR_IO23_DRV                   ((uint16_t)0x0004)                /*!< Drive IO2 and IO3 Enable */
#endif /* GD32F170_190 */ 


/******************************************************************************/
/*                                                                            */
/*                       System Configuration (SYSCFG)                        */
/*                                                                            */
/******************************************************************************/
/*****************  Bit definition for SYSCFG_R1 register  ********************/
#define  SYSCFG_R1_BOOT_MODE                 ((uint32_t)0x00000003)            /*!< SYSCFG_Memory Remap Config */
#define  SYSCFG_R1_BOOT_MODE_0               ((uint32_t)0x00000001)            /*!< SYSCFG_Memory Remap Config Bit 0 */
#define  SYSCFG_R1_BOOT_MODE_1               ((uint32_t)0x00000002)            /*!< SYSCFG_Memory Remap Config Bit 1 */
#define  SYSCFG_R1_ADC_DMA_RMP               ((uint32_t)0x00000100)            /*!< ADC DMA remap */
#define  SYSCFG_R1_USART1_TX_DMA_RMP         ((uint32_t)0x00000200)            /*!< USART1 TX DMA remap */
#define  SYSCFG_R1_USART1_RX_DMA_RMP         ((uint32_t)0x00000400)            /*!< USART1 RX DMA remap */
#define  SYSCFG_R1_TIMER16_DMA_RMP           ((uint32_t)0x00000800)            /*!< Timer 16 DMA remap */
#define  SYSCFG_R1_TIMER17_DMA_RMP           ((uint32_t)0x00001000)            /*!< Timer 17 DMA remap */
#define  SYSCFG_R1_PB9_HCCE                  ((uint32_t)0x00080000)            /*!< PB9 pin high current capability enable */

#ifdef GD32F170_190
/*****************  Bit definition for SYSCFG_R2 register  ********************/
#define  SYSCFG_R2_LCD_DECA                  ((uint32_t)0x0000000E)            /*!< Decouping capacitance connection for LCD */
#define  SYSCFG_R2_LCD_DECA_0                ((uint32_t)0x00000002)            /*!< Decouping capacitance connection for LCD Bit 0 */
#define  SYSCFG_R2_LCD_DECA_1                ((uint32_t)0x00000004)            /*!< Decouping capacitance connection for LCD Bit 1 */
#define  SYSCFG_R2_LCD_DECA_2                ((uint32_t)0x00000008)            /*!< Decouping capacitance connection for LCD Bit 2 */
#endif /* GD32F170_190 */


/*****************  Bit definition for SYSCFG_EXTISS1 register  ***************/
#define  SYSCFG_EXTISS1_EXTI0_SS             ((uint16_t)0x000F)                /*!< EXTI 0 configuration */
#define  SYSCFG_EXTISS1_EXTI1_SS             ((uint16_t)0x00F0)                /*!< EXTI 1 configuration */
#define  SYSCFG_EXTISS1_EXTI2_SS             ((uint16_t)0x0F00)                /*!< EXTI 2 configuration */
#define  SYSCFG_EXTISS1_EXTI3_SS             ((uint16_t)0xF000)                /*!< EXTI 3 configuration */

#define  SYSCFG_EXTISS1_EXTI0_SS_PA          ((uint16_t)0x0000)                /*!< PA[0] pin */
#define  SYSCFG_EXTISS1_EXTI0_SS_PB          ((uint16_t)0x0001)                /*!< PB[0] pin */
#define  SYSCFG_EXTISS1_EXTI0_SS_PC          ((uint16_t)0x0002)                /*!< PC[0] pin */
#define  SYSCFG_EXTISS1_EXTI0_SS_PD          ((uint16_t)0x0003)                /*!< PD[0] pin */
#define  SYSCFG_EXTISS1_EXTI0_SS_PF          ((uint16_t)0x0005)                /*!< PF[0] pin */

#define  SYSCFG_EXTISS1_EXTI1_SS_PA          ((uint16_t)0x0000)                /*!< PA[1] pin */
#define  SYSCFG_EXTISS1_EXTI1_SS_PB          ((uint16_t)0x0010)                /*!< PB[1] pin */
#define  SYSCFG_EXTISS1_EXTI1_SS_PC          ((uint16_t)0x0020)                /*!< PC[1] pin */
#define  SYSCFG_EXTISS1_EXTI1_SS_PD          ((uint16_t)0x0030)                /*!< PD[1] pin */
#define  SYSCFG_EXTISS1_EXTI1_SS_PF          ((uint16_t)0x0050)                /*!< PF[1] pin */

#define  SYSCFG_EXTISS1_EXTI2_SS_PA          ((uint16_t)0x0000)                /*!< PA[2] pin */
#define  SYSCFG_EXTISS1_EXTI2_SS_PB          ((uint16_t)0x0100)                /*!< PB[2] pin */
#define  SYSCFG_EXTISS1_EXTI2_SS_PC          ((uint16_t)0x0200)                /*!< PC[2] pin */
#define  SYSCFG_EXTISS1_EXTI2_SS_PD          ((uint16_t)0x0300)                /*!< PD[2] pin */
#define  SYSCFG_EXTISS1_EXTI2_SS_PF          ((uint16_t)0x0500)                /*!< PF[2] pin */

#define  SYSCFG_EXTISS1_EXTI3_SS_PA          ((uint16_t)0x0000)                /*!< PA[3] pin */
#define  SYSCFG_EXTISS1_EXTI3_SS_PB          ((uint16_t)0x1000)                /*!< PB[3] pin */
#define  SYSCFG_EXTISS1_EXTI3_SS_PC          ((uint16_t)0x2000)                /*!< PC[3] pin */
#define  SYSCFG_EXTISS1_EXTI3_SS_PD          ((uint16_t)0x3000)                /*!< PD[3] pin */
#define  SYSCFG_EXTISS1_EXTI3_SS_PF          ((uint16_t)0x5000)                /*!< PF[3] pin */

/*****************  Bit definition for SYSCFG_EXTISS2 register  ***************/
#define  SYSCFG_EXTISS2_EXTI4_SS             ((uint16_t)0x000F)                /*!< EXTI 4 configuration */
#define  SYSCFG_EXTISS2_EXTI5_SS             ((uint16_t)0x00F0)                /*!< EXTI 5 configuration */
#define  SYSCFG_EXTISS2_EXTI6_SS             ((uint16_t)0x0F00)                /*!< EXTI 6 configuration */
#define  SYSCFG_EXTISS2_EXTI7_SS             ((uint16_t)0xF000)                /*!< EXTI 7 configuration */

#define  SYSCFG_EXTISS2_EXTI4_SS_PA          ((uint16_t)0x0000)                /*!< PA[4] pin */
#define  SYSCFG_EXTISS2_EXTI4_SS_PB          ((uint16_t)0x0001)                /*!< PB[4] pin */
#define  SYSCFG_EXTISS2_EXTI4_SS_PC          ((uint16_t)0x0002)                /*!< PC[4] pin */
#define  SYSCFG_EXTISS2_EXTI4_SS_PD          ((uint16_t)0x0003)                /*!< PD[4] pin */
#define  SYSCFG_EXTISS2_EXTI4_SS_PF          ((uint16_t)0x0005)                /*!< PF[4] pin */

#define  SYSCFG_EXTISS2_EXTI5_SS_PA          ((uint16_t)0x0000)                /*!< PA[5] pin */
#define  SYSCFG_EXTISS2_EXTI5_SS_PB          ((uint16_t)0x0010)                /*!< PB[5] pin */
#define  SYSCFG_EXTISS2_EXTI5_SS_PC          ((uint16_t)0x0020)                /*!< PC[5] pin */
#define  SYSCFG_EXTISS2_EXTI5_SS_PD          ((uint16_t)0x0030)                /*!< PD[5] pin */
#define  SYSCFG_EXTISS2_EXTI5_SS_PF          ((uint16_t)0x0050)                /*!< PF[5] pin */

#define  SYSCFG_EXTISS2_EXTI6_SS_PA          ((uint16_t)0x0000)                /*!< PA[6] pin */
#define  SYSCFG_EXTISS2_EXTI6_SS_PB          ((uint16_t)0x0100)                /*!< PB[6] pin */
#define  SYSCFG_EXTISS2_EXTI6_SS_PC          ((uint16_t)0x0200)                /*!< PC[6] pin */
#define  SYSCFG_EXTISS2_EXTI6_SS_PD          ((uint16_t)0x0300)                /*!< PD[6] pin */
#define  SYSCFG_EXTISS2_EXTI6_SS_PF          ((uint16_t)0x0500)                /*!< PF[6] pin */

#define  SYSCFG_EXTISS2_EXTI7_SS_PA          ((uint16_t)0x0000)                /*!< PA[7] pin */
#define  SYSCFG_EXTISS2_EXTI7_SS_PB          ((uint16_t)0x1000)                /*!< PB[7] pin */
#define  SYSCFG_EXTISS2_EXTI7_SS_PC          ((uint16_t)0x2000)                /*!< PC[7] pin */
#define  SYSCFG_EXTISS2_EXTI7_SS_PD          ((uint16_t)0x3000)                /*!< PD[7] pin */
#define  SYSCFG_EXTISS2_EXTI7_SS_PF          ((uint16_t)0x5000)                /*!< PF[7] pin */

/*****************  Bit definition for SYSCFG_EXTISS3 register  ***************/
#define  SYSCFG_EXTISS3_EXTI8_SS             ((uint16_t)0x000F)                /*!< EXTI 8 configuration */
#define  SYSCFG_EXTISS3_EXTI9_SS             ((uint16_t)0x00F0)                /*!< EXTI 9 configuration */
#define  SYSCFG_EXTISS3_EXTI10_SS            ((uint16_t)0x0F00)                /*!< EXTI 10 configuration */
#define  SYSCFG_EXTISS3_EXTI11_SS            ((uint16_t)0xF000)                /*!< EXTI 11 configuration */

#define  SYSCFG_EXTISS3_EXTI8_SS_PA          ((uint16_t)0x0000)                /*!< PA[8] pin */
#define  SYSCFG_EXTISS3_EXTI8_SS_PB          ((uint16_t)0x0001)                /*!< PB[8] pin */
#define  SYSCFG_EXTISS3_EXTI8_SS_PC          ((uint16_t)0x0002)                /*!< PC[8] pin */
#define  SYSCFG_EXTISS3_EXTI8_SS_PD          ((uint16_t)0x0003)                /*!< PD[8] pin */
#define  SYSCFG_EXTISS3_EXTI8_SS_PF          ((uint16_t)0x0005)                /*!< PF[8] pin */

#define  SYSCFG_EXTISS3_EXTI9_SS_PA          ((uint16_t)0x0000)                /*!< PA[9] pin */
#define  SYSCFG_EXTISS3_EXTI9_SS_PB          ((uint16_t)0x0010)                /*!< PB[9] pin */
#define  SYSCFG_EXTISS3_EXTI9_SS_PC          ((uint16_t)0x0020)                /*!< PC[9] pin */
#define  SYSCFG_EXTISS3_EXTI9_SS_PD          ((uint16_t)0x0030)                /*!< PD[9] pin */
#define  SYSCFG_EXTISS3_EXTI9_SS_PF          ((uint16_t)0x0050)                /*!< PF[9] pin */

#define  SYSCFG_EXTISS3_EXTI10_SS_PA         ((uint16_t)0x0000)                /*!< PA[10] pin */
#define  SYSCFG_EXTISS3_EXTI10_SS_PB         ((uint16_t)0x0100)                /*!< PB[10] pin */
#define  SYSCFG_EXTISS3_EXTI10_SS_PC         ((uint16_t)0x0200)                /*!< PC[10] pin */
#define  SYSCFG_EXTISS3_EXTI10_SS_PD         ((uint16_t)0x0300)                /*!< PD[10] pin */
#define  SYSCFG_EXTISS3_EXTI10_SS_PF         ((uint16_t)0x0500)                /*!< PF[10] pin */

#define  SYSCFG_EXTISS3_EXTI11_SS_PA         ((uint16_t)0x0000)                /*!< PA[11] pin */
#define  SYSCFG_EXTISS3_EXTI11_SS_PB         ((uint16_t)0x1000)                /*!< PB[11] pin */
#define  SYSCFG_EXTISS3_EXTI11_SS_PC         ((uint16_t)0x2000)                /*!< PC[11] pin */
#define  SYSCFG_EXTISS3_EXTI11_SS_PD         ((uint16_t)0x3000)                /*!< PD[11] pin */
#define  SYSCFG_EXTISS3_EXTI11_SS_PF         ((uint16_t)0x5000)                /*!< PF[11] pin */

/*****************  Bit definition for SYSCFG_EXTISS4 register  ***************/
#define  SYSCFG_EXTISS4_EXTI12_SS            ((uint16_t)0x000F)                /*!< EXTI 12 configuration */
#define  SYSCFG_EXTISS4_EXTI13_SS            ((uint16_t)0x00F0)                /*!< EXTI 13 configuration */
#define  SYSCFG_EXTISS4_EXTI14_SS            ((uint16_t)0x0F00)                /*!< EXTI 14 configuration */
#define  SYSCFG_EXTISS4_EXTI15_SS            ((uint16_t)0xF000)                /*!< EXTI 15 configuration */

#define  SYSCFG_EXTISS4_EXTI12_SS_PA         ((uint16_t)0x0000)                /*!< PA[12] pin */
#define  SYSCFG_EXTISS4_EXTI12_SS_PB         ((uint16_t)0x0001)                /*!< PB[12] pin */
#define  SYSCFG_EXTISS4_EXTI12_SS_PC         ((uint16_t)0x0002)                /*!< PC[12] pin */
#define  SYSCFG_EXTISS4_EXTI12_SS_PD         ((uint16_t)0x0003)                /*!< PD[12] pin */
#define  SYSCFG_EXTISS4_EXTI12_SS_PF         ((uint16_t)0x0005)                /*!< PF[12] pin */

#define  SYSCFG_EXTISS4_EXTI13_SS_PA         ((uint16_t)0x0000)                /*!< PA[13] pin */
#define  SYSCFG_EXTISS4_EXTI13_SS_PB         ((uint16_t)0x0010)                /*!< PB[13] pin */
#define  SYSCFG_EXTISS4_EXTI13_SS_PC         ((uint16_t)0x0020)                /*!< PC[13] pin */
#define  SYSCFG_EXTISS4_EXTI13_SS_PD         ((uint16_t)0x0030)                /*!< PD[13] pin */
#define  SYSCFG_EXTISS4_EXTI13_SS_PF         ((uint16_t)0x0050)                /*!< PF[13] pin */

#define  SYSCFG_EXTISS4_EXTI14_SS_PA         ((uint16_t)0x0000)                /*!< PA[14] pin */
#define  SYSCFG_EXTISS4_EXTI14_SS_PB         ((uint16_t)0x0100)                /*!< PB[14] pin */
#define  SYSCFG_EXTISS4_EXTI14_SS_PC         ((uint16_t)0x0200)                /*!< PC[14] pin */
#define  SYSCFG_EXTISS4_EXTI14_SS_PD         ((uint16_t)0x0300)                /*!< PD[14] pin */
#define  SYSCFG_EXTISS4_EXTI14_SS_PF         ((uint16_t)0x0500)                /*!< PF[14] pin */

#define  SYSCFG_EXTISS4_EXTI15_SS_PA         ((uint16_t)0x0000)                /*!< PA[15] pin */
#define  SYSCFG_EXTISS4_EXTI15_SS_PB         ((uint16_t)0x1000)                /*!< PB[15] pin */
#define  SYSCFG_EXTISS4_EXTI15_SS_PC         ((uint16_t)0x2000)                /*!< PC[15] pin */
#define  SYSCFG_EXTISS4_EXTI15_SS_PD         ((uint16_t)0x3000)                /*!< PD[15] pin */
#define  SYSCFG_EXTISS4_EXTI15_SS_PF         ((uint16_t)0x5000)                /*!< PF[15] pin */

/*****************  Bit definition for SYSCFG_R3 register  ********************/
#define  SYSCFG_R3_LOCKUP_LOCK               ((uint32_t)0x00000001)            /*!< Enables and locks the LOCKUP (Hardfault) output of CortexM0 with Break Input of TIMER1/15/16/17 */
#define  SYSCFG_R3_SRAM_PARITY_ERROR_LOCK    ((uint32_t)0x00000002)            /*!< Enables and locks the SRAM_PARITY error signal with Break Input of TIMER1/15/16/17 */
#define  SYSCFG_R3_LVD_LOCK                  ((uint32_t)0x00000004)            /*!< Enables and locks the LVD connection with Timer1 Break Input and also the LVD_EN and LVDSEL[2:0] bits of the Power Control Interface */
#define  SYSCFG_R3_SRAM_PCEF                 ((uint32_t)0x00000100)            /*!< SRAM Parity check error flag */


/******************************************************************************/
/*                                                                            */
/*                               Timers (TIMER)                               */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TIMER_CTLR1 register  ****************/
#define  TIMER_CTLR1_CNTE                    ((uint16_t)0x0001)                /*!< Counter enable */
#define  TIMER_CTLR1_UPDIS                   ((uint16_t)0x0002)                /*!< Update disable */
#define  TIMER_CTLR1_UPS                     ((uint16_t)0x0004)                /*!< Update request source */
#define  TIMER_CTLR1_SPM                     ((uint16_t)0x0008)                /*!< One pulse mode */
#define  TIMER_CTLR1_DIR                     ((uint16_t)0x0010)                /*!< Direction */

#define  TIMER_CTLR1_CAM                     ((uint16_t)0x0060)                /*!< CAM[1:0] bits (Center-aligned mode selection) */
#define  TIMER_CTLR1_CAM_0                   ((uint16_t)0x0020)                /*!< Bit 0 */
#define  TIMER_CTLR1_CAM_1                   ((uint16_t)0x0040)                /*!< Bit 1 */

#define  TIMER_CTLR1_ARSE                    ((uint16_t)0x0080)                /*!< Auto-reload preload enable */

#define  TIMER_CTLR1_CDIV                    ((uint16_t)0x0300)                /*!< CDIV[1:0] bits (clock division) */
#define  TIMER_CTLR1_CDIV_0                  ((uint16_t)0x0100)                /*!< Bit 0 */
#define  TIMER_CTLR1_CDIV_1                  ((uint16_t)0x0200)                /*!< Bit 1 */

/*******************  Bit definition for TIMER_CTLR2 register  ****************/
#define  TIMER_CTLR2_CCSE                    ((uint16_t)0x0001)                /*!< Capture/Compare Preloaded Control */
#define  TIMER_CTLR2_CCUC                    ((uint16_t)0x0004)                /*!< Capture/Compare Control Update Selection */
#define  TIMER_CTLR2_DMAS                    ((uint16_t)0x0008)                /*!< Capture/Compare DMA Selection */

#define  TIMER_CTLR2_MMC                     ((uint16_t)0x0070)                /*!< MMC[2:0] bits (Master Mode Selection) */
#define  TIMER_CTLR2_MMC_0                   ((uint16_t)0x0010)                /*!< Bit 0 */
#define  TIMER_CTLR2_MMC_1                   ((uint16_t)0x0020)                /*!< Bit 1 */
#define  TIMER_CTLR2_MMC_2                   ((uint16_t)0x0040)                /*!< Bit 2 */

#define  TIMER_CTLR2_TI1S                    ((uint16_t)0x0080)                /*!< TI1 Selection */
#define  TIMER_CTLR2_ISO1                    ((uint16_t)0x0100)                /*!< Output Idle state 1 (OC1 output) */
#define  TIMER_CTLR2_ISO1N                   ((uint16_t)0x0200)                /*!< Output Idle state 1 (OC1N output) */
#define  TIMER_CTLR2_ISO2                    ((uint16_t)0x0400)                /*!< Output Idle state 2 (OC2 output) */
#define  TIMER_CTLR2_ISO2N                   ((uint16_t)0x0800)                /*!< Output Idle state 2 (OC2N output) */
#define  TIMER_CTLR2_ISO3                    ((uint16_t)0x1000)                /*!< Output Idle state 3 (OC3 output) */
#define  TIMER_CTLR2_ISO3N                   ((uint16_t)0x2000)                /*!< Output Idle state 3 (OC3N output) */
#define  TIMER_CTLR2_ISO4                    ((uint16_t)0x4000)                /*!< Output Idle state 4 (OC4 output) */

/*******************  Bit definition for TIMER_SMC register  ******************/
#define  TIMER_SMC_SMC                       ((uint16_t)0x0007)                /*!< SMC[2:0] bits (Slave mode selection) */
#define  TIMER_SMC_SMC_0                     ((uint16_t)0x0001)                /*!< Bit 0 */
#define  TIMER_SMC_SMC_1                     ((uint16_t)0x0002)                /*!< Bit 1 */
#define  TIMER_SMC_SMC_2                     ((uint16_t)0x0004)                /*!< Bit 2 */
#define  TIMER_SMC_OCCS                      ((uint16_t)0x0008)                /*!< OCREF clear selection */

#define  TIMER_SMC_TRGS                      ((uint16_t)0x0070)                /*!< TRGS[2:0] bits (Trigger selection) */
#define  TIMER_SMC_TRGS_0                    ((uint16_t)0x0010)                /*!< Bit 0 */
#define  TIMER_SMC_TRGS_1                    ((uint16_t)0x0020)                /*!< Bit 1 */
#define  TIMER_SMC_TRGS_2                    ((uint16_t)0x0040)                /*!< Bit 2 */

#define  TIMER_SMC_MSM                       ((uint16_t)0x0080)                /*!< Master/slave mode */

#define  TIMER_SMC_ETFC                      ((uint16_t)0x0F00)                /*!< ETFC[3:0] bits (External trigger filter) */
#define  TIMER_SMC_ETFC_0                    ((uint16_t)0x0100)                /*!< Bit 0 */
#define  TIMER_SMC_ETFC_1                    ((uint16_t)0x0200)                /*!< Bit 1 */
#define  TIMER_SMC_ETFC_2                    ((uint16_t)0x0400)                /*!< Bit 2 */
#define  TIMER_SMC_ETFC_3                    ((uint16_t)0x0800)                /*!< Bit 3 */

#define  TIMER_SMC_ETPSC                     ((uint16_t)0x3000)                /*!< ETPSC[1:0] bits (External trigger prescaler) */
#define  TIMER_SMC_ETPSC_0                   ((uint16_t)0x1000)                /*!< Bit 0 */
#define  TIMER_SMC_ETPSC_1                   ((uint16_t)0x2000)                /*!< Bit 1 */

#define  TIMER_SMC_ECM2E                     ((uint16_t)0x4000)                /*!< External clock enable */
#define  TIMER_SMC_ETPL                      ((uint16_t)0x8000)                /*!< External trigger polarity */

/*******************  Bit definition for TIMER_DIE register  ******************/
#define  TIMER_DIE_UPIE                      ((uint16_t)0x0001)                /*!< Update interrupt enable */
#define  TIMER_DIE_CH1IE                     ((uint16_t)0x0002)                /*!< Capture/Compare 1 interrupt enable */
#define  TIMER_DIE_CH2IE                     ((uint16_t)0x0004)                /*!< Capture/Compare 2 interrupt enable */
#define  TIMER_DIE_CH3IE                     ((uint16_t)0x0008)                /*!< Capture/Compare 3 interrupt enable */
#define  TIMER_DIE_CH4IE                     ((uint16_t)0x0010)                /*!< Capture/Compare 4 interrupt enable */
#define  TIMER_DIE_CCUIE                     ((uint16_t)0x0020)                /*!< COM interrupt enable */
#define  TIMER_DIE_TRGIE                     ((uint16_t)0x0040)                /*!< Trigger interrupt enable */
#define  TIMER_DIE_BKIE                      ((uint16_t)0x0080)                /*!< Break interrupt enable */
#define  TIMER_DIE_UPDE                      ((uint16_t)0x0100)                /*!< Update DMA request enable */
#define  TIMER_DIE_CH1DE                     ((uint16_t)0x0200)                /*!< Capture/Compare 1 DMA request enable */
#define  TIMER_DIE_CH2DE                     ((uint16_t)0x0400)                /*!< Capture/Compare 2 DMA request enable */
#define  TIMER_DIE_CH3DE                     ((uint16_t)0x0800)                /*!< Capture/Compare 3 DMA request enable */
#define  TIMER_DIE_CH4DE                     ((uint16_t)0x1000)                /*!< Capture/Compare 4 DMA request enable */
#define  TIMER_DIE_CCUDE                     ((uint16_t)0x2000)                /*!< COM DMA request enable */
#define  TIMER_DIE_TRGDE                     ((uint16_t)0x4000)                /*!< Trigger DMA request enable */

/********************  Bit definition for TIMER_STR register  *****************/
#define  TIMER_STR_UPIF                      ((uint16_t)0x0001)                /*!< Update interrupt Flag */
#define  TIMER_STR_CH1IF                     ((uint16_t)0x0002)                /*!< Capture/Compare 1 interrupt Flag */
#define  TIMER_STR_CH2IF                     ((uint16_t)0x0004)                /*!< Capture/Compare 2 interrupt Flag */
#define  TIMER_STR_CH3IF                     ((uint16_t)0x0008)                /*!< Capture/Compare 3 interrupt Flag */
#define  TIMER_STR_CH4IF                     ((uint16_t)0x0010)                /*!< Capture/Compare 4 interrupt Flag */
#define  TIMER_STR_CCUIF                     ((uint16_t)0x0020)                /*!< COM interrupt Flag */
#define  TIMER_STR_TRGIF                     ((uint16_t)0x0040)                /*!< Trigger interrupt Flag */
#define  TIMER_STR_BKIF                      ((uint16_t)0x0080)                /*!< Break interrupt Flag */
#define  TIMER_STR_CH1OF                     ((uint16_t)0x0200)                /*!< Capture/Compare 1 Overcapture Flag */
#define  TIMER_STR_CH2OF                     ((uint16_t)0x0400)                /*!< Capture/Compare 2 Overcapture Flag */
#define  TIMER_STR_CH3OF                     ((uint16_t)0x0800)                /*!< Capture/Compare 3 Overcapture Flag */
#define  TIMER_STR_CH4OF                     ((uint16_t)0x1000)                /*!< Capture/Compare 4 Overcapture Flag */

/*******************  Bit definition for TIMER_EVG register  ******************/
#define  TIMER_EVG_UPG                       ((uint8_t)0x01)                   /*!< Update Generation */
#define  TIMER_EVG_CH1G                      ((uint8_t)0x02)                   /*!< Capture/Compare 1 Generation */
#define  TIMER_EVG_CH2G                      ((uint8_t)0x04)                   /*!< Capture/Compare 2 Generation */
#define  TIMER_EVG_CH3G                      ((uint8_t)0x08)                   /*!< Capture/Compare 3 Generation */
#define  TIMER_EVG_CH4G                      ((uint8_t)0x10)                   /*!< Capture/Compare 4 Generation */
#define  TIMER_EVG_CCUG                      ((uint8_t)0x20)                   /*!< Capture/Compare Control Update Generation */
#define  TIMER_EVG_TRGG                      ((uint8_t)0x40)                   /*!< Trigger Generation */
#define  TIMER_EVG_BKG                       ((uint8_t)0x80)                   /*!< Break Generation */

/******************  Bit definition for TIMER_CHCTLR1 register  ***************/
#define  TIMER_CHCTLR1_CH1M                  ((uint16_t)0x0003)                /*!< CH1M[1:0] bits (Capture/Compare 1 Selection) */
#define  TIMER_CHCTLR1_CH1M_0                ((uint16_t)0x0001)                /*!< Bit 0 */
#define  TIMER_CHCTLR1_CH1M_1                ((uint16_t)0x0002)                /*!< Bit 1 */

#define  TIMER_CHCTLR1_CH1OFE                ((uint16_t)0x0004)                /*!< Output Compare 1 Fast enable */
#define  TIMER_CHCTLR1_CH1OSE                ((uint16_t)0x0008)                /*!< Output Compare 1 Preload enable */

#define  TIMER_CHCTLR1_CH1OM                 ((uint16_t)0x0070)                /*!< CH1OM[2:0] bits (Output Compare 1 Mode) */
#define  TIMER_CHCTLR1_CH1OM_0               ((uint16_t)0x0010)                /*!< Bit 0 */
#define  TIMER_CHCTLR1_CH1OM_1               ((uint16_t)0x0020)                /*!< Bit 1 */
#define  TIMER_CHCTLR1_CH1OM_2               ((uint16_t)0x0040)                /*!< Bit 2 */

#define  TIMER_CHCTLR1_CH1OCE                ((uint16_t)0x0080)                /*!< Output Compare 1Clear Enable */

#define  TIMER_CHCTLR1_CH2M                  ((uint16_t)0x0300)                /*!< CH2M[1:0] bits (Capture/Compare 2 Selection) */
#define  TIMER_CHCTLR1_CH2M_0                ((uint16_t)0x0100)                /*!< Bit 0 */
#define  TIMER_CHCTLR1_CH2M_1                ((uint16_t)0x0200)                /*!< Bit 1 */

#define  TIMER_CHCTLR1_CH2OFE                ((uint16_t)0x0400)                /*!< Output Compare 2 Fast enable */
#define  TIMER_CHCTLR1_CH2OSE                ((uint16_t)0x0800)                /*!< Output Compare 2 Preload enable */

#define  TIMER_CHCTLR1_CH2OM                 ((uint16_t)0x7000)                /*!< CH2OM[2:0] bits (Output Compare 2 Mode) */
#define  TIMER_CHCTLR1_CH2OM_0               ((uint16_t)0x1000)                /*!< Bit 0 */
#define  TIMER_CHCTLR1_CH2OM_1               ((uint16_t)0x2000)                /*!< Bit 1 */
#define  TIMER_CHCTLR1_CH2OM_2               ((uint16_t)0x4000)                /*!< Bit 2 */

#define  TIMER_CHCTLR1_CH2OCE                ((uint16_t)0x8000)                /*!< Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIMER_CHCTLR1_CH1ICP                ((uint16_t)0x000C)                /*!< CH1ICP[1:0] bits (Input Capture 1 Prescaler) */
#define  TIMER_CHCTLR1_CH1ICP_0              ((uint16_t)0x0004)                /*!< Bit 0 */
#define  TIMER_CHCTLR1_CH1ICP_1              ((uint16_t)0x0008)                /*!< Bit 1 */

#define  TIMER_CHCTLR1_CH1ICF                ((uint16_t)0x00F0)                /*!< CH1ICF[3:0] bits (Input Capture 1 Filter) */
#define  TIMER_CHCTLR1_CH1ICF_0              ((uint16_t)0x0010)                /*!< Bit 0 */
#define  TIMER_CHCTLR1_CH1ICF_1              ((uint16_t)0x0020)                /*!< Bit 1 */
#define  TIMER_CHCTLR1_CH1ICF_2              ((uint16_t)0x0040)                /*!< Bit 2 */
#define  TIMER_CHCTLR1_CH1ICF_3              ((uint16_t)0x0080)                /*!< Bit 3 */

#define  TIMER_CHCTLR1_CH2ICP                ((uint16_t)0x0C00)                /*!< CH2ICP[1:0] bits (Input Capture 2 Prescaler) */
#define  TIMER_CHCTLR1_CH2ICP_0              ((uint16_t)0x0400)                /*!< Bit 0 */
#define  TIMER_CHCTLR1_CH2ICP_1              ((uint16_t)0x0800)                /*!< Bit 1 */

#define  TIMER_CHCTLR1_CH2ICF                ((uint16_t)0xF000)                /*!< CH2ICF[3:0] bits (Input Capture 2 Filter) */
#define  TIMER_CHCTLR1_CH2ICF_0              ((uint16_t)0x1000)                /*!< Bit 0 */
#define  TIMER_CHCTLR1_CH2ICF_1              ((uint16_t)0x2000)                /*!< Bit 1 */
#define  TIMER_CHCTLR1_CH2ICF_2              ((uint16_t)0x4000)                /*!< Bit 2 */
#define  TIMER_CHCTLR1_CH2ICF_3              ((uint16_t)0x8000)                /*!< Bit 3 */

/******************  Bit definition for TIMER_CHCTLR2 register  ***************/
#define  TIMER_CHCTLR2_CH3M                  ((uint16_t)0x0003)                /*!< CH3M[1:0] bits (Capture/Compare 3 Selection) */
#define  TIMER_CHCTLR2_CH3M_0                ((uint16_t)0x0001)                /*!< Bit 0 */
#define  TIMER_CHCTLR2_CH3M_1                ((uint16_t)0x0002)                /*!< Bit 1 */

#define  TIMER_CHCTLR2_CH3OFE                ((uint16_t)0x0004)                /*!< Output Compare 3 Fast enable */
#define  TIMER_CHCTLR2_CH3OSE                ((uint16_t)0x0008)                /*!< Output Compare 3 Preload enable */

#define  TIMER_CHCTLR2_CH3OM                 ((uint16_t)0x0070)                /*!< CH3OM[2:0] bits (Output Compare 3 Mode) */
#define  TIMER_CHCTLR2_CH3OM_0               ((uint16_t)0x0010)                /*!< Bit 0 */
#define  TIMER_CHCTLR2_CH3OM_1               ((uint16_t)0x0020)                /*!< Bit 1 */
#define  TIMER_CHCTLR2_CH3OM_2               ((uint16_t)0x0040)                /*!< Bit 2 */

#define  TIMER_CHCTLR2_CH3OCE                ((uint16_t)0x0080)                /*!< Output Compare 3 Clear Enable */

#define  TIMER_CHCTLR2_CH4M                  ((uint16_t)0x0300)                /*!< CH4M[1:0] bits (Capture/Compare 4 Selection) */
#define  TIMER_CHCTLR2_CH4M_0                ((uint16_t)0x0100)                /*!< Bit 0 */
#define  TIMER_CHCTLR2_CH4M_1                ((uint16_t)0x0200)                /*!< Bit 1 */

#define  TIMER_CHCTLR2_CH4OFE                ((uint16_t)0x0400)                /*!< Output Compare 4 Fast enable */
#define  TIMER_CHCTLR2_CH4OSE                ((uint16_t)0x0800)                /*!< Output Compare 4 Preload enable */

#define  TIMER_CHCTLR2_CH4OM                 ((uint16_t)0x7000)                /*!< CH4OM[2:0] bits (Output Compare 4 Mode) */
#define  TIMER_CHCTLR2_CH4OM_0               ((uint16_t)0x1000)                /*!< Bit 0 */
#define  TIMER_CHCTLR2_CH4OM_1               ((uint16_t)0x2000)                /*!< Bit 1 */
#define  TIMER_CHCTLR2_CH4OM_2               ((uint16_t)0x4000)                /*!< Bit 2 */

#define  TIMER_CHCTLR2_CH4OCE                ((uint16_t)0x8000)                /*!< Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define  TIMER_CHCTLR2_CH3ICP                ((uint16_t)0x000C)                /*!< CH3ICP[1:0] bits (Input Capture 3 Prescaler) */
#define  TIMER_CHCTLR2_CH3ICP_0              ((uint16_t)0x0004)                /*!< Bit 0 */
#define  TIMER_CHCTLR2_CH3ICP_1              ((uint16_t)0x0008)                /*!< Bit 1 */

#define  TIMER_CHCTLR2_CH3ICF                ((uint16_t)0x00F0)                /*!< CH3ICF[3:0] bits (Input Capture 3 Filter) */
#define  TIMER_CHCTLR2_CH3ICF_0              ((uint16_t)0x0010)                /*!< Bit 0 */
#define  TIMER_CHCTLR2_CH3ICF_1              ((uint16_t)0x0020)                /*!< Bit 1 */
#define  TIMER_CHCTLR2_CH3ICF_2              ((uint16_t)0x0040)                /*!< Bit 2 */
#define  TIMER_CHCTLR2_CH3ICF_3              ((uint16_t)0x0080)                /*!< Bit 3 */

#define  TIMER_CHCTLR2_CH4ICP                ((uint16_t)0x0C00)                /*!< CH4ICP[1:0] bits (Input Capture 4 Prescaler) */
#define  TIMER_CHCTLR2_CH4ICP_0              ((uint16_t)0x0400)                /*!< Bit 0 */
#define  TIMER_CHCTLR2_CH4ICP_1              ((uint16_t)0x0800)                /*!< Bit 1 */

#define  TIMER_CHCTLR2_CH4ICF                ((uint16_t)0xF000)                /*!< CH4ICF[3:0] bits (Input Capture 4 Filter) */
#define  TIMER_CHCTLR2_CH4ICF_0              ((uint16_t)0x1000)                /*!< Bit 0 */
#define  TIMER_CHCTLR2_CH4ICF_1              ((uint16_t)0x2000)                /*!< Bit 1 */
#define  TIMER_CHCTLR2_CH4ICF_2              ((uint16_t)0x4000)                /*!< Bit 2 */
#define  TIMER_CHCTLR2_CH4ICF_3              ((uint16_t)0x8000)                /*!< Bit 3 */

/*******************  Bit definition for TIMER_CHE register  ******************/
#define  TIMER_CHE_CH1E                      ((uint16_t)0x0001)                /*!< Capture/Compare 1 output enable */
#define  TIMER_CHE_CH1P                      ((uint16_t)0x0002)                /*!< Capture/Compare 1 output Polarity */
#define  TIMER_CHE_CH1NE                     ((uint16_t)0x0004)                /*!< Capture/Compare 1 Complementary output enable */
#define  TIMER_CHE_CH1NP                     ((uint16_t)0x0008)                /*!< Capture/Compare 1 Complementary output Polarity */
#define  TIMER_CHE_CH2E                      ((uint16_t)0x0010)                /*!< Capture/Compare 2 output enable */
#define  TIMER_CHE_CH2P                      ((uint16_t)0x0020)                /*!< Capture/Compare 2 output Polarity */
#define  TIMER_CHE_CH2NE                     ((uint16_t)0x0040)                /*!< Capture/Compare 2 Complementary output enable */
#define  TIMER_CHE_CH2NP                     ((uint16_t)0x0080)                /*!< Capture/Compare 2 Complementary output Polarity */
#define  TIMER_CHE_CH3E                      ((uint16_t)0x0100)                /*!< Capture/Compare 3 output enable */
#define  TIMER_CHE_CH3P                      ((uint16_t)0x0200)                /*!< Capture/Compare 3 output Polarity */
#define  TIMER_CHE_CH3NE                     ((uint16_t)0x0400)                /*!< Capture/Compare 3 Complementary output enable */
#define  TIMER_CHE_CH3NP                     ((uint16_t)0x0800)                /*!< Capture/Compare 3 Complementary output Polarity */
#define  TIMER_CHE_CH4E                      ((uint16_t)0x1000)                /*!< Capture/Compare 4 output enable */
#define  TIMER_CHE_CH4P                      ((uint16_t)0x2000)                /*!< Capture/Compare 4 output Polarity */
#define  TIMER_CHE_CH4NP                     ((uint16_t)0x8000)                /*!< Capture/Compare 4 Complementary output Polarity */

/*******************  Bit definition for TIMER_CNT register  ******************/
#define  TIMER_CNT_CNT                       ((uint16_t)0xFFFF)                /*!< Counter Value */

/*******************  Bit definition for TIMER_PSC register  ******************/
#define  TIMER_PSC_PSC                       ((uint16_t)0xFFFF)                /*!< Prescaler Value */

/*******************  Bit definition for TIMER_CARL register  *****************/
#define  TIMER_CARL_CARL                     ((uint16_t)0xFFFF)                /*!< actual auto-reload Value */

/*******************  Bit definition for TIMER_CREP register  *****************/
#define  TIMER_CREP_CREP                     ((uint8_t)0xFF)                   /*!< Repetition Counter Value */

/*******************  Bit definition for TIMER_CHCC1 register  ****************/
#define  TIMER_CHCC1_CHCC1                   ((uint16_t)0xFFFF)                /*!< Capture/Compare 1 Value */

/*******************  Bit definition for TIMER_CHCC2 register  ****************/
#define  TIMER_CHCC2_CHCC2                   ((uint16_t)0xFFFF)                /*!< Capture/Compare 2 Value */

/*******************  Bit definition for TIMER_CHCC3 register  ****************/
#define  TIMER_CHCC3_CHCC3                   ((uint16_t)0xFFFF)                /*!< Capture/Compare 3 Value */

/*******************  Bit definition for TIMER_CHCC4 register  ****************/
#define  TIMER_CHCC4_CHCC4                   ((uint16_t)0xFFFF)                /*!< Capture/Compare 4 Value */

/*******************  Bit definition for TIMER_BKDT register  *****************/
#define  TIMER_BKDT_DT                       ((uint16_t)0x00FF)                /*!< DT[0:7] bits (Dead-TIMERe Generator set-up) */
#define  TIMER_BKDT_DT_0                     ((uint16_t)0x0001)                /*!< Bit 0 */
#define  TIMER_BKDT_DT_1                     ((uint16_t)0x0002)                /*!< Bit 1 */
#define  TIMER_BKDT_DT_2                     ((uint16_t)0x0004)                /*!< Bit 2 */
#define  TIMER_BKDT_DT_3                     ((uint16_t)0x0008)                /*!< Bit 3 */
#define  TIMER_BKDT_DT_4                     ((uint16_t)0x0010)                /*!< Bit 4 */
#define  TIMER_BKDT_DT_5                     ((uint16_t)0x0020)                /*!< Bit 5 */
#define  TIMER_BKDT_DT_6                     ((uint16_t)0x0040)                /*!< Bit 6 */
#define  TIMER_BKDT_DT_7                     ((uint16_t)0x0080)                /*!< Bit 7 */

#define  TIMER_BKDT_LK                       ((uint16_t)0x0300)                /*!< LK[1:0] bits (Lock Configuration) */
#define  TIMER_BKDT_LK_0                     ((uint16_t)0x0100)                /*!< Bit 0 */
#define  TIMER_BKDT_LK_1                     ((uint16_t)0x0200)                /*!< Bit 1 */

#define  TIMER_BKDT_IOS                      ((uint16_t)0x0400)                /*!< Off-State Selection for Idle mode */
#define  TIMER_BKDT_ROS                      ((uint16_t)0x0800)                /*!< Off-State Selection for Run mode */
#define  TIMER_BKDT_BRKE                     ((uint16_t)0x1000)                /*!< Break enable */
#define  TIMER_BKDT_BRKP                     ((uint16_t)0x2000)                /*!< Break Polarity */
#define  TIMER_BKDT_OAE                      ((uint16_t)0x4000)                /*!< Automatic Output enable */
#define  TIMER_BKDT_POE                      ((uint16_t)0x8000)                /*!< Main Output enable */

/*******************  Bit definition for TIMER_DCTLR register  ****************/
#define  TIMER_DCTLR_DBAR                    ((uint16_t)0x001F)                /*!< DBAR[4:0] bits (DMA Base Address) */
#define  TIMER_DCTLR_DBAR_0                  ((uint16_t)0x0001)                /*!< Bit 0 */
#define  TIMER_DCTLR_DBAR_1                  ((uint16_t)0x0002)                /*!< Bit 1 */
#define  TIMER_DCTLR_DBAR_2                  ((uint16_t)0x0004)                /*!< Bit 2 */
#define  TIMER_DCTLR_DBAR_3                  ((uint16_t)0x0008)                /*!< Bit 3 */
#define  TIMER_DCTLR_DBAR_4                  ((uint16_t)0x0010)                /*!< Bit 4 */

#define  TIMER_DCTLR_DBLTH                   ((uint16_t)0x1F00)                /*!< DBLTH[4:0] bits (DMA Burst Length) */
#define  TIMER_DCTLR_DBLTH_0                 ((uint16_t)0x0100)                /*!< Bit 0 */
#define  TIMER_DCTLR_DBLTH_1                 ((uint16_t)0x0200)                /*!< Bit 1 */
#define  TIMER_DCTLR_DBLTH_2                 ((uint16_t)0x0400)                /*!< Bit 2 */
#define  TIMER_DCTLR_DBLTH_3                 ((uint16_t)0x0800)                /*!< Bit 3 */
#define  TIMER_DCTLR_DBLTH_4                 ((uint16_t)0x1000)                /*!< Bit 4 */

/*******************  Bit definition for TIMER_DTRSF register  ****************/
#define  TIMER_DTRSF_DTRSF                   ((uint16_t)0xFFFF)                /*!< DMA register for burst accesses */

/*******************  Bit definition for TIMER_RMP register  ******************/
#define  TIMER14_RMP_TI1_RMP                 ((uint16_t)0x0003)                /*!< TI1_RMP[1:0] bits (TIMER14 Input 4 remap) */
#define  TIMER14_RMP_TI1_RMP_0               ((uint16_t)0x0001)                /*!< Bit 0 */
#define  TIMER14_RMP_TI1_RMP_1               ((uint16_t)0x0002)                /*!< Bit 1 */

#ifdef GD32F170_190
/*******************  Bit definition for TIMER_CFGR register  *****************/
#define  TIMER_CFGR_OUTSEL                   ((uint16_t)0x0001)                /*!< Output value selection enable */
#define  TIMER_CFGR_CCSEL                    ((uint16_t)0x0002)                /*!< Write CC register selection enable */
#endif   /* GD32F170_190 */


/******************************************************************************/
/*                                                                            */
/*              Touch Sensing Interface(TSI)                                  */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for TSI_CTLR register  ********************/
#define  TSI_CTLR_TSIEN                      ((uint32_t)0x00000001)            /*!< TSI Enable */
#define  TSI_CTLR_TSIST                      ((uint32_t)0x00000002)            /*!< TSI start */
#define  TSI_CTLR_TM                         ((uint32_t)0x00000004)            /*!< Trigger mode selection */
#define  TSI_CTLR_ES                         ((uint32_t)0x00000008)            /*!< Edge selection */
#define  TSI_CTLR_PINMOD                     ((uint32_t)0x00000010)            /*!< Pin mode */
#define  TSI_CTLR_MCN                        ((uint32_t)0x000000E0)            /*!< MCN[2:0] bits (Max cycle number of a sequence) */
#define  TSI_CTLR_MCN_0                      ((uint32_t)0x00000020)            /*!< Bit 0 */
#define  TSI_CTLR_MCN_1                      ((uint32_t)0x00000040)            /*!< Bit 1 */
#define  TSI_CTLR_MCN_2                      ((uint32_t)0x00000800)            /*!< Bit 2 */
#define  TSI_CTLR_CTCDIV                     ((uint32_t)0x00007000)            /*!< CTCDIV[2:0] bits (CTCLK clock division factor) */
#define  TSI_CTLR_CTCDIV_0                   ((uint32_t)0x00001000)            /*!< Bit 0 */
#define  TSI_CTLR_CTCDIV_1                   ((uint32_t)0x00002000)            /*!< Bit 1 */
#define  TSI_CTLR_CTCDIV_2                   ((uint32_t)0x00004000)            /*!< Bit 2 */
#define  TSI_CTLR_ECDIV                      ((uint32_t)0x00008000)            /*!< ECCLK clock division factor */
#define  TSI_CTLR_ECEN                       ((uint32_t)0x00010000)            /*!< Extend Charge State Enable */
#define  TSI_CTLR_ECDT                       ((uint32_t)0x00FE0000)            /*!< ECDT[6:0] bits (Extend Charge State Maximum Duration Time) */
#define  TSI_CTLR_ECDT_0                     ((uint32_t)0x00020000)            /*!< Bit 0 */
#define  TSI_CTLR_ECDT_1                     ((uint32_t)0x00040000)            /*!< Bit 1 */
#define  TSI_CTLR_ECDT_2                     ((uint32_t)0x00080000)            /*!< Bit 2 */
#define  TSI_CTLR_ECDT_3                     ((uint32_t)0x00100000)            /*!< Bit 3 */
#define  TSI_CTLR_ECDT_4                     ((uint32_t)0x00200000)            /*!< Bit 4 */
#define  TSI_CTLR_ECDT_5                     ((uint32_t)0x00400000)            /*!< Bit 5 */
#define  TSI_CTLR_ECDT_6                     ((uint32_t)0x00800000)            /*!< Bit 6 */
#define  TSI_CTLR_CTDT                       ((uint32_t)0x0F000000)            /*!< CTDT[3:0] bits (Charge Transfer State Duration Time) */
#define  TSI_CTLR_CTDT_0                     ((uint32_t)0x01000000)            /*!< Bit 0 */
#define  TSI_CTLR_CTDT_1                     ((uint32_t)0x02000000)            /*!< Bit 1 */
#define  TSI_CTLR_CTDT_2                     ((uint32_t)0x04000000)            /*!< Bit 2 */
#define  TSI_CTLR_CTDT_3                     ((uint32_t)0x08000000)            /*!< Bit 3 */
#define  TSI_CTLR_CDT                        ((uint32_t)0xF0000000)            /*!< CDT[3:0] bits (Charge State Duration Time) */
#define  TSI_CTLR_CDT_0                      ((uint32_t)0x10000000)            /*!< Bit 0 */
#define  TSI_CTLR_CDT_1                      ((uint32_t)0x20000000)            /*!< Bit 1 */
#define  TSI_CTLR_CDT_2                      ((uint32_t)0x40000000)            /*!< Bit 2 */
#define  TSI_CTLR_CDT_3                      ((uint32_t)0x80000000)            /*!< Bit 3 */

/******************  Bit definition for TSI_IER register  *********************/
#define  TSI_IER_CRCFIE                      ((uint32_t)0x00000001)            /*!< Charge-transfer complete flag Interrupt Enable */
#define  TSI_IER_MNEIE                       ((uint32_t)0x00000002)            /*!< Max Cycle Number Error Interrupt Enable */
       

/******************  Bit definition for TSI_CEFR register  ********************/
#define  TSI_CEFR_CMNE                       ((uint32_t)0x00000001)            /*!< Clear max cycle number error */
#define  TSI_CEFR_CCTCF                      ((uint32_t)0x00000002)            /*!< Clear charge-transfer complete flag */

/******************  Bit definition for TSI_STR register  *********************/
#define  TSI_STR_CTCF                        ((uint32_t)0x00000001)            /*!< Charge-Transfer complete flag */
#define  TSI_STR_MNE                         ((uint32_t)0x00000002)            /*!< Max Cycle Number Error */

/******************  Bit definition for TSI_PHMR register  ********************/
#define  TSI_PHMR_G1P1                       ((uint32_t)0x00000001)            /*!< Pin G1P1 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G1P2                       ((uint32_t)0x00000002)            /*!< Pin G1P2 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G1P3                       ((uint32_t)0x00000004)            /*!< Pin G1P3 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G1P4                       ((uint32_t)0x00000008)            /*!< Pin G1P4 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G2P1                       ((uint32_t)0x00000010)            /*!< Pin G2P1 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G2P2                       ((uint32_t)0x00000020)            /*!< Pin G2P2 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G2P3                       ((uint32_t)0x00000040)            /*!< Pin G2P3 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G2P4                       ((uint32_t)0x00000080)            /*!< Pin G2P4 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G3P1                       ((uint32_t)0x00000100)            /*!< Pin G3P1 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G3P2                       ((uint32_t)0x00000200)            /*!< Pin G3P2 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G3P3                       ((uint32_t)0x00000400)            /*!< Pin G3P3 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G3P4                       ((uint32_t)0x00000800)            /*!< Pin G3P4 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G4P1                       ((uint32_t)0x00001000)            /*!< Pin G4P1 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G4P2                       ((uint32_t)0x00002000)            /*!< Pin G4P2 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G4P3                       ((uint32_t)0x00004000)            /*!< Pin G4P3 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G4P4                       ((uint32_t)0x00008000)            /*!< Pin G4P4 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G5P1                       ((uint32_t)0x00010000)            /*!< Pin G5P1 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G5P2                       ((uint32_t)0x00200000)            /*!< Pin G5P2 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G5P3                       ((uint32_t)0x00040000)            /*!< Pin G5P3 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G5P4                       ((uint32_t)0x00800000)            /*!< Pin G5P4 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G6P1                       ((uint32_t)0x00100000)            /*!< Pin G6P1 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G6P2                       ((uint32_t)0x00200000)            /*!< Pin G6P2 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G6P3                       ((uint32_t)0x00400000)            /*!< Pin G6P3 Schmitt trigger hysteresis mode enabled */
#define  TSI_PHMR_G6P4                       ((uint32_t)0x00800000)            /*!< Pin G6P4 Schmitt trigger hysteresis mode enabled */

/*******************  Bit definition for TSI_ASWR register  *******************/
#define  TSI_ASWR_G1P1                       ((uint32_t)0x00000001)            /*!< Analog switch of G1P1 is closed */
#define  TSI_ASWR_G1P2                       ((uint32_t)0x00000002)            /*!< Analog switch of G1P2 is closed */
#define  TSI_ASWR_G1P3                       ((uint32_t)0x00000004)            /*!< Analog switch of G1P3 is closed */
#define  TSI_ASWR_G1P4                       ((uint32_t)0x00000008)            /*!< Analog switch of G1P4 is closed */
#define  TSI_ASWR_G2P1                       ((uint32_t)0x00000010)            /*!< Analog switch of G2P1 is closed */
#define  TSI_ASWR_G2P2                       ((uint32_t)0x00000020)            /*!< Analog switch of G2P2 is closed */
#define  TSI_ASWR_G2P3                       ((uint32_t)0x00000040)            /*!< Analog switch of G2P3 is closed */
#define  TSI_ASWR_G2P4                       ((uint32_t)0x00000080)            /*!< Analog switch of G2P4 is closed */
#define  TSI_ASWR_G3P1                       ((uint32_t)0x00000100)            /*!< Analog switch of G3P1 is closed */
#define  TSI_ASWR_G3P2                       ((uint32_t)0x00000200)            /*!< Analog switch of G3P2 is closed */
#define  TSI_ASWR_G3P3                       ((uint32_t)0x00000400)            /*!< Analog switch of G3P3 is closed */
#define  TSI_ASWR_G3P4                       ((uint32_t)0x00000800)            /*!< Analog switch of G3P4 is closed */
#define  TSI_ASWR_G4P1                       ((uint32_t)0x00001000)            /*!< Analog switch of G4P1 is closed */
#define  TSI_ASWR_G4P2                       ((uint32_t)0x00002000)            /*!< Analog switch of G4P2 is closed */
#define  TSI_ASWR_G4P3                       ((uint32_t)0x00004000)            /*!< Analog switch of G4P3 is closed */
#define  TSI_ASWR_G4P4                       ((uint32_t)0x00008000)            /*!< Analog switch of G4P4 is closed */
#define  TSI_ASWR_G5P1                       ((uint32_t)0x00010000)            /*!< Analog switch of G5P1 is closed */
#define  TSI_ASWR_G5P2                       ((uint32_t)0x00200000)            /*!< Analog switch of G5P2 is closed */
#define  TSI_ASWR_G5P3                       ((uint32_t)0x00040000)            /*!< Analog switch of G5P3 is closed */
#define  TSI_ASWR_G5P4                       ((uint32_t)0x00800000)            /*!< Analog switch of G5P4 is closed */
#define  TSI_ASWR_G6P1                       ((uint32_t)0x00100000)            /*!< Analog switch of G6P1 is closed */
#define  TSI_ASWR_G6P2                       ((uint32_t)0x00200000)            /*!< Analog switch of G6P2 is closed */
#define  TSI_ASWR_G6P3                       ((uint32_t)0x00400000)            /*!< Analog switch of G6P3 is closed */
#define  TSI_ASWR_G6P4                       ((uint32_t)0x00800000)            /*!< Analog switch of G6P4 is closed */

/*******************  Bit definition for TSI_SPR register  ********************/
#define  TSI_SPR_G1P1                        ((uint32_t)0x00000001)            /*!< Pin G1P1 is a sample pin */
#define  TSI_SPR_G1P2                        ((uint32_t)0x00000002)            /*!< Pin G1P2 is a sample pin */
#define  TSI_SPR_G1P3                        ((uint32_t)0x00000004)            /*!< Pin G1P3 is a sample pin */
#define  TSI_SPR_G1P4                        ((uint32_t)0x00000008)            /*!< Pin G1P4 is a sample pin */
#define  TSI_SPR_G2P1                        ((uint32_t)0x00000010)            /*!< Pin G2P1 is a sample pin */
#define  TSI_SPR_G2P2                        ((uint32_t)0x00000020)            /*!< Pin G2P2 is a sample pin */
#define  TSI_SPR_G2P3                        ((uint32_t)0x00000040)            /*!< Pin G2P3 is a sample pin */
#define  TSI_SPR_G2P4                        ((uint32_t)0x00000080)            /*!< Pin G2P4 is a sample pin */
#define  TSI_SPR_G3P1                        ((uint32_t)0x00000100)            /*!< Pin G3P1 is a sample pin */
#define  TSI_SPR_G3P2                        ((uint32_t)0x00000200)            /*!< Pin G3P2 is a sample pin */
#define  TSI_SPR_G3P3                        ((uint32_t)0x00000400)            /*!< Pin G3P3 is a sample pin */
#define  TSI_SPR_G3P4                        ((uint32_t)0x00000800)            /*!< Pin G3P4 is a sample pin */
#define  TSI_SPR_G4P1                        ((uint32_t)0x00001000)            /*!< Pin G4P1 is a sample pin */
#define  TSI_SPR_G4P2                        ((uint32_t)0x00002000)            /*!< Pin G4P2 is a sample pin */
#define  TSI_SPR_G4P3                        ((uint32_t)0x00004000)            /*!< Pin G4P3 is a sample pin */
#define  TSI_SPR_G4P4                        ((uint32_t)0x00008000)            /*!< Pin G4P4 is a sample pin */
#define  TSI_SPR_G5P1                        ((uint32_t)0x00010000)            /*!< Pin G5P1 is a sample pin */
#define  TSI_SPR_G5P2                        ((uint32_t)0x00200000)            /*!< Pin G5P2 is a sample pin */
#define  TSI_SPR_G5P3                        ((uint32_t)0x00040000)            /*!< Pin G5P3 is a sample pin */
#define  TSI_SPR_G5P4                        ((uint32_t)0x00800000)            /*!< Pin G5P4 is a sample pin */
#define  TSI_SPR_G6P1                        ((uint32_t)0x00100000)            /*!< Pin G6P1 is a sample pin */
#define  TSI_SPR_G6P2                        ((uint32_t)0x00200000)            /*!< Pin G6P2 is a sample pin */
#define  TSI_SPR_G6P3                        ((uint32_t)0x00400000)            /*!< Pin G6P3 is a sample pin */
#define  TSI_SPR_G6P4                        ((uint32_t)0x00800000)            /*!< Pin G6P4 is a sample pin */

/*******************  Bit definition for TSI_CPR register  ********************/
#define  TSI_CPR_G1P1                        ((uint32_t)0x00000001)            /*!< Pin G1P1 is a channel pin */
#define  TSI_CPR_G1P2                        ((uint32_t)0x00000002)            /*!< Pin G1P2 is a channel pin */
#define  TSI_CPR_G1P3                        ((uint32_t)0x00000004)            /*!< Pin G1P3 is a channel pin */
#define  TSI_CPR_G1P4                        ((uint32_t)0x00000008)            /*!< Pin G1P4 is a channel pin */
#define  TSI_CPR_G2P1                        ((uint32_t)0x00000010)            /*!< Pin G2P1 is a channel pin */
#define  TSI_CPR_G2P2                        ((uint32_t)0x00000020)            /*!< Pin G2P2 is a channel pin */
#define  TSI_CPR_G2P3                        ((uint32_t)0x00000040)            /*!< Pin G2P3 is a channel pin */
#define  TSI_CPR_G2P4                        ((uint32_t)0x00000080)            /*!< Pin G2P4 is a channel pin */
#define  TSI_CPR_G3P1                        ((uint32_t)0x00000100)            /*!< Pin G3P1 is a channel pin */
#define  TSI_CPR_G3P2                        ((uint32_t)0x00000200)            /*!< Pin G3P2 is a channel pin */
#define  TSI_CPR_G3P3                        ((uint32_t)0x00000400)            /*!< Pin G3P3 is a channel pin */
#define  TSI_CPR_G3P4                        ((uint32_t)0x00000800)            /*!< Pin G3P4 is a channel pin */
#define  TSI_CPR_G4P1                        ((uint32_t)0x00001000)            /*!< Pin G4P1 is a channel pin */
#define  TSI_CPR_G4P2                        ((uint32_t)0x00002000)            /*!< Pin G4P2 is a channel pin */
#define  TSI_CPR_G4P3                        ((uint32_t)0x00004000)            /*!< Pin G4P3 is a channel pin */
#define  TSI_CPR_G4P4                        ((uint32_t)0x00008000)            /*!< Pin G4P4 is a channel pin */
#define  TSI_CPR_G5P1                        ((uint32_t)0x00010000)            /*!< Pin G5P1 is a channel pin */
#define  TSI_CPR_G5P2                        ((uint32_t)0x00200000)            /*!< Pin G5P2 is a channel pin */
#define  TSI_CPR_G5P3                        ((uint32_t)0x00040000)            /*!< Pin G5P3 is a channel pin */
#define  TSI_CPR_G5P4                        ((uint32_t)0x00800000)            /*!< Pin G5P4 is a channel pin */
#define  TSI_CPR_G6P1                        ((uint32_t)0x00100000)            /*!< Pin G6P1 is a channel pin */
#define  TSI_CPR_G6P2                        ((uint32_t)0x00200000)            /*!< Pin G6P2 is a channel pin */
#define  TSI_CPR_G6P3                        ((uint32_t)0x00400000)            /*!< Pin G6P3 is a channel pin */
#define  TSI_CPR_G6P4                        ((uint32_t)0x00800000)            /*!< Pin G6P4 is a channel pin */

/*******************  Bit definition for TSI_GCTLR register  ******************/
#define  TSI_GCTLR_GE1                       ((uint32_t)0x00000001)            /*!< Group 1 is enabled */
#define  TSI_GCTLR_GE2                       ((uint32_t)0x00000002)            /*!< Group 2 is enabled */
#define  TSI_GCTLR_GE3                       ((uint32_t)0x00000004)            /*!< Group 3 is enabled */
#define  TSI_GCTLR_GE4                       ((uint32_t)0x00000008)            /*!< Group 4 is enabled */
#define  TSI_GCTLR_GE5                       ((uint32_t)0x00000010)            /*!< Group 5 is enabled */
#define  TSI_GCTLR_GE6                       ((uint32_t)0x00000020)            /*!< Group 6 is enabled */
#define  TSI_GCTLR_GC1                       ((uint32_t)0x00010000)            /*!< Charge-transfer for group 1 is complete */
#define  TSI_GCTLR_GC2                       ((uint32_t)0x00020000)            /*!< Charge-transfer for group 2 is complete */
#define  TSI_GCTLR_GC3                       ((uint32_t)0x00040000)            /*!< Charge-transfer for group 3 is complete */
#define  TSI_GCTLR_GC4                       ((uint32_t)0x00080000)            /*!< Charge-transfer for group 4 is complete */
#define  TSI_GCTLR_GC5                       ((uint32_t)0x00100000)            /*!< Charge-transfer for group 5 is complete */
#define  TSI_GCTLR_GC6                       ((uint32_t)0x00200000)            /*!< Charge-transfer for group 6 is complete */

/*******************  Bit definition for TSI_GxCYCNR register  ****************/
#define  TSI_GxCYCNR_CYCN                    ((uint32_t)0x000003FF)            /*!< CYCN[13:0] bits (Cycle number) */
#define  TSI_GxCYCNR_CYCN_0                  ((uint32_t)0x00000001)            /*!< Bit 0 */
#define  TSI_GxCYCNR_CYCN_1                  ((uint32_t)0x00000002)            /*!< Bit 1 */
#define  TSI_GxCYCNR_CYCN_2                  ((uint32_t)0x00000004)            /*!< Bit 2 */
#define  TSI_GxCYCNR_CYCN_3                  ((uint32_t)0x00000008)            /*!< Bit 3 */
#define  TSI_GxCYCNR_CYCN_4                  ((uint32_t)0x00000010)            /*!< Bit 4 */
#define  TSI_GxCYCNR_CYCN_5                  ((uint32_t)0x00000020)            /*!< Bit 5 */
#define  TSI_GxCYCNR_CYCN_6                  ((uint32_t)0x00000040)            /*!< Bit 6 */
#define  TSI_GxCYCNR_CYCN_7                  ((uint32_t)0x00000080)            /*!< Bit 7 */
#define  TSI_GxCYCNR_CYCN_8                  ((uint32_t)0x00000100)            /*!< Bit 8 */
#define  TSI_GxCYCNR_CYCN_9                  ((uint32_t)0x00000200)            /*!< Bit 9 */
#define  TSI_GxCYCNR_CYCN_10                 ((uint32_t)0x00000400)            /*!< Bit 10 */
#define  TSI_GxCYCNR_CYCN_11                 ((uint32_t)0x00000800)            /*!< Bit 11 */
#define  TSI_GxCYCNR_CYCN_12                 ((uint32_t)0x00001000)            /*!< Bit 12 */
#define  TSI_GxCYCNR_CYCN_13                 ((uint32_t)0x00002000)            /*!< Bit 13 */


/******************************************************************************/
/*                                                                            */
/*      Universal Synchronous Asynchronous Receiver Transmitter (USART)       */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for USART_CTLR1 register  *****************/
#define  USART_CTLR1_UEN                     ((uint32_t)0x00000001)            /*!< USART Enable */
#define  USART_CTLR1_UESM                    ((uint32_t)0x00000002)            /*!< USART Enable in Deep-sleep Mode */
#define  USART_CTLR1_REN                     ((uint32_t)0x00000004)            /*!< Receiver Enable */
#define  USART_CTLR1_TEN                     ((uint32_t)0x00000008)            /*!< Transmitter Enable */
#define  USART_CTLR1_IDIE                    ((uint32_t)0x00000010)            /*!< IDLE Interrupt Enable */
#define  USART_CTLR1_RBNEIE                  ((uint32_t)0x00000020)            /*!< RBNE Interrupt Enable */
#define  USART_CTLR1_TCIE                    ((uint32_t)0x00000040)            /*!< Transmission Complete Interrupt Enable */
#define  USART_CTLR1_TBEIE                   ((uint32_t)0x00000080)            /*!< TBE Interrupt Enable */
#define  USART_CTLR1_PEIE                    ((uint32_t)0x00000100)            /*!< PE Interrupt Enable */
#define  USART_CTLR1_PM                      ((uint32_t)0x00000200)            /*!< Parity Mode */
#define  USART_CTLR1_PCEN                    ((uint32_t)0x00000400)            /*!< Parity Control Enable */
#define  USART_CTLR1_WM                      ((uint32_t)0x00000800)            /*!< Wakeup method in mute mode */
#define  USART_CTLR1_WL                      ((uint32_t)0x00001000)            /*!< Word length */
#define  USART_CTLR1_MEN                     ((uint32_t)0x00002000)            /*!< Mute Mode Enable */
#define  USART_CTLR1_AMIE                    ((uint32_t)0x00004000)            /*!< ADDR match interrupt enable */
#define  USART_CTLR1_OM                      ((uint32_t)0x00008000)            /*!< Oversampling by 8-bit or 16-bit mode */
#define  USART_CTLR1_DED                     ((uint32_t)0x001F0000)            /*!< DED[4:0] bits (Driver Enable Deassertion Time) */
#define  USART_CTLR1_DED_0                   ((uint32_t)0x00010000)            /*!< Bit 0 */
#define  USART_CTLR1_DED_1                   ((uint32_t)0x00020000)            /*!< Bit 1 */
#define  USART_CTLR1_DED_2                   ((uint32_t)0x00040000)            /*!< Bit 2 */
#define  USART_CTLR1_DED_3                   ((uint32_t)0x00080000)            /*!< Bit 3 */
#define  USART_CTLR1_DED_4                   ((uint32_t)0x00100000)            /*!< Bit 4 */
#define  USART_CTLR1_DEA                     ((uint32_t)0x03E00000)            /*!< DEA[4:0] bits (Driver Enable Assertion Time) */
#define  USART_CTLR1_DEA_0                   ((uint32_t)0x00200000)            /*!< Bit 0 */
#define  USART_CTLR1_DEA_1                   ((uint32_t)0x00400000)            /*!< Bit 1 */
#define  USART_CTLR1_DEA_2                   ((uint32_t)0x00800000)            /*!< Bit 2 */
#define  USART_CTLR1_DEA_3                   ((uint32_t)0x01000000)            /*!< Bit 3 */
#define  USART_CTLR1_DEA_4                   ((uint32_t)0x02000000)            /*!< Bit 4 */
#define  USART_CTLR1_RTIE                    ((uint32_t)0x04000000)            /*!< Receive Time Out interrupt enable */
#define  USART_CTLR1_EBIE                    ((uint32_t)0x08000000)            /*!< End of Block interrupt enable */

/******************  Bit definition for USART_CTLR2 register  *****************/
#define  USART_CTLR2_ADDM                    ((uint32_t)0x00000010)            /*!< 7-bit or 4-bit Address Detection */
#define  USART_CTLR2_LBDL                    ((uint32_t)0x00000020)            /*!< LIN Break Detection Length */
#define  USART_CTLR2_LBDIE                   ((uint32_t)0x00000040)            /*!< LIN Break Detection Interrupt Enable */
#define  USART_CTLR2_LBCP                    ((uint32_t)0x00000100)            /*!< Last Bit Clock pulse */
#define  USART_CTLR2_CPH                     ((uint32_t)0x00000200)            /*!< Clock Phase */
#define  USART_CTLR2_CPL                     ((uint32_t)0x00000400)            /*!< Clock Polarity */
#define  USART_CTLR2_CKEN                    ((uint32_t)0x00000800)            /*!< Clock Enable */
#define  USART_CTLR2_STB                     ((uint32_t)0x00003000)            /*!< STOP[1:0] bits (STOP bits) */
#define  USART_CTLR2_STB_0                   ((uint32_t)0x00001000)            /*!< Bit 0 */
#define  USART_CTLR2_STB_1                   ((uint32_t)0x00002000)            /*!< Bit 1 */
#define  USART_CTLR2_LMEN                    ((uint32_t)0x00004000)            /*!< LIN mode enable */
#define  USART_CTLR2_STRP                    ((uint32_t)0x00008000)            /*!< SWAP TX/RX pins */
#define  USART_CTLR2_RINV                    ((uint32_t)0x00010000)            /*!< RX pin active level inversion */
#define  USART_CTLR2_TINV                    ((uint32_t)0x00020000)            /*!< TX pin active level inversion */
#define  USART_CTLR2_DINV                    ((uint32_t)0x00040000)            /*!< Binary data inversion */
#define  USART_CTLR2_MSBF                    ((uint32_t)0x00080000)            /*!< Most Significant Bit First */
#define  USART_CTLR2_ABDEN                   ((uint32_t)0x00100000)            /*!< Auto Baud-Rate Enable*/
#define  USART_CTLR2_ABDM                    ((uint32_t)0x00600000)            /*!< ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
#define  USART_CTLR2_ABDM_0                  ((uint32_t)0x00200000)            /*!< Bit 0 */
#define  USART_CTLR2_ABDM_1                  ((uint32_t)0x00400000)            /*!< Bit 1 */
#define  USART_CTLR2_RTEN                    ((uint32_t)0x00800000)            /*!< Receiver Time-Out enable */
#define  USART_CTLR2_ADDR                    ((uint32_t)0xFF000000)            /*!< Address of the USART node */

/******************  Bit definition for USART_CTLR3 register  *****************/
#define  USART_CTLR3_ERIE                    ((uint32_t)0x00000001)            /*!< Error interrupt enable in multibuffer Communication */
#define  USART_CTLR3_IREN                    ((uint32_t)0x00000002)            /*!< IrDA mode Enable */
#define  USART_CTLR3_IRLP                    ((uint32_t)0x00000004)            /*!< IrDA Low-Power */
#define  USART_CTLR3_HDEN                    ((uint32_t)0x00000008)            /*!< Half-duplex enable */
#define  USART_CTLR3_NACK                    ((uint32_t)0x00000010)            /*!< SmartCard NACK enable */
#define  USART_CTLR3_SCEN                    ((uint32_t)0x00000020)            /*!< SmartCard mode enable */
#define  USART_CTLR3_DENR                    ((uint32_t)0x00000040)            /*!< DMA Enable Receiver */
#define  USART_CTLR3_DENT                    ((uint32_t)0x00000080)            /*!< DMA Enable Transmitter */
#define  USART_CTLR3_RTSEN                   ((uint32_t)0x00000100)            /*!< RTS Enable */
#define  USART_CTLR3_CTSEN                   ((uint32_t)0x00000200)            /*!< CTS Enable */
#define  USART_CTLR3_CTSIE                   ((uint32_t)0x00000400)            /*!< CTS Interrupt Enable */
#define  USART_CTLR3_OSBM                    ((uint32_t)0x00000800)            /*!< One sample bit mode */
#define  USART_CTLR3_OVRD                    ((uint32_t)0x00001000)            /*!< Overrun Disable */
#define  USART_CTLR3_DDRE                    ((uint32_t)0x00002000)            /*!< DMA Disable on Reception Error */
#define  USART_CTLR3_DEM                     ((uint32_t)0x00004000)            /*!< Driver Enable Mode */
#define  USART_CTLR3_DEP                     ((uint32_t)0x00008000)            /*!< Driver Enable Polarity Selection */
#define  USART_CTLR3_SCRTNUM                 ((uint32_t)0x000E0000)            /*!< SCRTNUM[2:0] bits (SmartCard Auto-Retry Count) */
#define  USART_CTLR3_SCRTNUM_0               ((uint32_t)0x00020000)            /*!< Bit 0 */
#define  USART_CTLR3_SCRTNUM_1               ((uint32_t)0x00040000)            /*!< Bit 1 */
#define  USART_CTLR3_SCRTNUM_2               ((uint32_t)0x00080000)            /*!< Bit 2 */
#define  USART_CTLR3_WUM                     ((uint32_t)0x00300000)            /*!< WUM[1:0] bits (Wakeup mode from Deep-sleep mode) */
#define  USART_CTLR3_WUM_0                   ((uint32_t)0x00100000)            /*!< Bit 0 */
#define  USART_CTLR3_WUM_1                   ((uint32_t)0x00200000)            /*!< Bit 1 */
#define  USART_CTLR3_WUIE                    ((uint32_t)0x00400000)            /*!< Wakeup from Deep-sleep mode interrupt enable */

/******************  Bit definition for USART_BRR register  *******************/
#define  USART_BRR_BRRF                      ((uint16_t)0x000F)                /*!< Fraction of USARTDIV */
#define  USART_BRR_BRRM                      ((uint16_t)0xFFF0)                /*!< Mantissa of USARTDIV */

/******************  Bit definition for TSI_PHMR register  ********************/
#define  USART_GTPR_PSC                      ((uint16_t)0x00FF)                /*!< PSC[7:0] bits (Prescaler value) */
#define  USART_GTPR_GT                       ((uint16_t)0xFF00)                /*!< GT[7:0] bits (Guard time value) */


/*******************  Bit definition for USART_RTR register  ******************/
#define  USART_RTR_RT                        ((uint32_t)0x00FFFFFF)            /*!< Receiver Time Out Value */
#define  USART_RTR_BL                        ((uint32_t)0xFF000000)            /*!< Block Length */

/*******************  Bit definition for USART_CMD register  ******************/
#define  USART_CMD_ABDCMD                    ((uint16_t)0x0001)                /*!< Auto-Baud Rate Request */
#define  USART_CMD_SBKCMD                    ((uint16_t)0x0002)                /*!< Send Break Request */
#define  USART_CMD_MMCMD                     ((uint16_t)0x0004)                /*!< Mute Mode Request */
#define  USART_CMD_RXFCMD                    ((uint16_t)0x0008)                /*!< Receive Data flush Request */
#define  USART_CMD_TXFCMD                    ((uint16_t)0x0010)                /*!< Transmit data flush Request */

/*******************  Bit definition for USART_STR register  ******************/
#define  USART_STR_PE                        ((uint32_t)0x00000001)            /*!< Parity Error */
#define  USART_STR_FE                        ((uint32_t)0x00000002)            /*!< Framing Error */
#define  USART_STR_NE                        ((uint32_t)0x00000004)            /*!< Noise detected Flag */
#define  USART_STR_ORE                       ((uint32_t)0x00000008)            /*!< OverRun Error */
#define  USART_STR_IDLEF                     ((uint32_t)0x00000010)            /*!< IDLEF line detected */
#define  USART_STR_RBNE                      ((uint32_t)0x00000020)            /*!< Read Data Register Not Empty */
#define  USART_STR_TC                        ((uint32_t)0x00000040)            /*!< Transmission Complete */
#define  USART_STR_TBE                       ((uint32_t)0x00000080)            /*!< Transmit Data Register Empty */
#define  USART_STR_LBDF                      ((uint32_t)0x00000100)            /*!< LIN Break Detection Flag */
#define  USART_STR_CTSF                      ((uint32_t)0x00000200)            /*!< CTS interrupt flag */
#define  USART_STR_CTS                       ((uint32_t)0x00000400)            /*!< CTS flag */
#define  USART_STR_RTF                       ((uint32_t)0x00000800)            /*!< Receiver Time Out */
#define  USART_STR_EBF                       ((uint32_t)0x00001000)            /*!< End Of Block Flag */
#define  USART_STR_ABDE                      ((uint32_t)0x00004000)            /*!< Auto-Baud Rate Error */
#define  USART_STR_ABDF                      ((uint32_t)0x00008000)            /*!< Auto-Baud Rate Flag */
#define  USART_STR_BSY                       ((uint32_t)0x00010000)            /*!< Busy Flag */
#define  USART_STR_AMF                       ((uint32_t)0x00020000)            /*!< Character Match Flag */
#define  USART_STR_SBF                       ((uint32_t)0x00040000)            /*!< Send Break Flag */
#define  USART_STR_RWU                       ((uint32_t)0x00080000)            /*!< Receive Wake Up from mute mode Flag */
#define  USART_STR_WUF                       ((uint32_t)0x00100000)            /*!< Wake Up from deep-sleep mode Flag */
#define  USART_STR_TEA                       ((uint32_t)0x00200000)            /*!< Transmit Enable Acknowledge Flag */
#define  USART_STR_REA                       ((uint32_t)0x00400000)            /*!< Receive Enable Acknowledge Flag */

/*******************  Bit definition for USART_SCR register  ******************/
#define  USART_SCR_PEC                       ((uint32_t)0x00000001)            /*!< Parity Error Clear Flag */
#define  USART_SCR_FEC                       ((uint32_t)0x00000002)            /*!< Framing Error Clear Flag */
#define  USART_SCR_NEC                       ((uint32_t)0x00000004)            /*!< Noise detected Clear Flag */
#define  USART_SCR_OREC                      ((uint32_t)0x00000008)            /*!< OverRun Error Clear Flag */
#define  USART_SCR_IDLEC                     ((uint32_t)0x00000010)            /*!< IDLE line detected Clear Flag */
#define  USART_SCR_TCC                       ((uint32_t)0x00000040)            /*!< Transmission Complete Clear Flag */
#define  USART_SCR_LBDC                      ((uint32_t)0x00000100)            /*!< LIN Break Detection Clear Flag */
#define  USART_SCR_CTSC                      ((uint32_t)0x00000200)            /*!< CTS Interrupt Clear Flag */
#define  USART_SCR_RTC                       ((uint32_t)0x00000800)            /*!< Receiver Time Out Clear Flag */
#define  USART_SCR_EBC                       ((uint32_t)0x00001000)            /*!< End Of Block Clear Flag */
#define  USART_SCR_AMC                       ((uint32_t)0x00020000)            /*!< Character Match Clear Flag */
#define  USART_SCR_WUC                       ((uint32_t)0x00100000)            /*!< Wake Up from deep-sleep mode Clear Flag */

/*******************  Bit definition for USART_RDR register  ******************/
#define  USART_RDR_RDTR                      ((uint16_t)0x01FF)                /*!< RDR[8:0] bits (Receive Data value) */

/*******************  Bit definition for USART_TDR register  ******************/
#define  USART_TDR_TDTR                      ((uint16_t)0x01FF)                /*!< TDR[8:0] bits (Transmit Data value) */


/******************************************************************************/
/*                                                                            */
/*                         Window WATCHDOG (WWDG)                             */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for WWDG_CTLR register  ******************/
#define  WWDG_CTLR_CNT                       ((uint8_t)0x7F)                   /*!< CNT[6:0] bits (7-Bit counter (MSB to LSB)) */
#define  WWDG_CTLR_CNT0                      ((uint8_t)0x01)                   /*!< Bit 0 */
#define  WWDG_CTLR_CNT1                      ((uint8_t)0x02)                   /*!< Bit 1 */
#define  WWDG_CTLR_CNT2                      ((uint8_t)0x04)                   /*!< Bit 2 */
#define  WWDG_CTLR_CNT3                      ((uint8_t)0x08)                   /*!< Bit 3 */
#define  WWDG_CTLR_CNT4                      ((uint8_t)0x10)                   /*!< Bit 4 */
#define  WWDG_CTLR_CNT5                      ((uint8_t)0x20)                   /*!< Bit 5 */
#define  WWDG_CTLR_CNT6                      ((uint8_t)0x40)                   /*!< Bit 6 */

#define  WWDG_CTLR_WDGEN                     ((uint8_t)0x80)                   /*!< Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define  WWDG_CFR_WIN                        ((uint16_t)0x007F)                /*!< WIN[6:0] bits (7-bit window value) */
#define  WWDG_CFR_WIN0                       ((uint16_t)0x0001)                /*!< Bit 0 */
#define  WWDG_CFR_WIN1                       ((uint16_t)0x0002)                /*!< Bit 1 */
#define  WWDG_CFR_WIN2                       ((uint16_t)0x0004)                /*!< Bit 2 */
#define  WWDG_CFR_WIN3                       ((uint16_t)0x0008)                /*!< Bit 3 */
#define  WWDG_CFR_WIN4                       ((uint16_t)0x0010)                /*!< Bit 4 */
#define  WWDG_CFR_WIN5                       ((uint16_t)0x0020)                /*!< Bit 5 */
#define  WWDG_CFR_WIN6                       ((uint16_t)0x0040)                /*!< Bit 6 */

#define  WWDG_CFR_PS                         ((uint16_t)0x0180)                /*!< PS[1:0] bits (Timer Base) */
#define  WWDG_CFR_PS0                        ((uint16_t)0x0080)                /*!< Bit 0 */
#define  WWDG_CFR_PS1                        ((uint16_t)0x0100)                /*!< Bit 1 */

#define  WWDG_CFR_EWI                        ((uint16_t)0x0200)                /*!< Early Wakeup Interrupt */

/*******************  Bit definition for WWDG_STR register  *******************/
#define  WWDG_STR_EWIF                       ((uint8_t)0x01)                   /*!< Early Wakeup Interrupt Flag */

/**
  * @}
  */

 /**
  * @}
  */ 

#ifdef USE_STDPERIPH_DRIVER
#include "gd32f1x0_conf.h"
#endif

/** @addtogroup Exported_macro
  * @{
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __GD32F1X0_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2016 GIGADEVICE *****END OF FILE****/
