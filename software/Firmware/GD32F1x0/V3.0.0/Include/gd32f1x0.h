/*!
    \file  gd32f1x0.h
    \brief general definitions for gd32f1x0
*/

/*
    Copyright (C) 2016 GigaDevice

    2014-12-26, V1.0.0, firmware for GD32F1x0(x=3,5)
    2016-01-15, V2.0.0, firmware for GD32F1x0(x=3,5,7,9)
    2016-04-30, V3.0.0, firmware update for GD32F1x0(x=3,5,7,9)
*/

#ifndef GD32F1X0_H
#define GD32F1X0_H

#ifdef cplusplus
 extern "C" {
#endif 

/* define GD32F1x0 */
#if !defined (GD32F1x0)
  #define GD32F1x0
#endif /* define GD32F1x0 */
#if !defined (GD32F1x0)
 #error "Please select the target GD32F1x0 device used in your application (in gd32f1x0.h file)"
#endif /* undefine GD32F1x0 tip */

/* define GD32F1x0 device category */
#if!defined (GD32F170_190)&&!defined (GD32F130_150)
 #error "Please select GD32F1x0 device category( GD32F130_150 or GD32F170_190 )"
#endif /* undefine GD32F170_190 or GD32F130_150 tip */
#if defined (GD32F170_190)&& defined (GD32F130_150)
 #error "Please select one GD32F1x0 device category( GD32F130_150 or GD32F170_190 )"
#endif /* define GD32F170_190 and GD32F130_150 tip */

/* define value of high speed crystal oscillator (HXTAL) in Hz */
#if !defined  (HXTAL_VALUE)
#define HXTAL_VALUE    ((uint32_t)8000000)
#endif /* high speed crystal oscillator value */

/* define startup timeout value of high speed crystal oscillator (HXTAL) */
#if !defined  (HXTAL_STARTUP_TIMEOUT)
#define HXTAL_STARTUP_TIMEOUT   ((uint16_t)0x0800)
#endif /* high speed crystal oscillator startup timeout */

/* define value of internal 8MHz RC oscillator (IRC8M) in Hz */
#if !defined  (IRC8M_VALUE) 
#define IRC8M_VALUE  ((uint32_t)8000000)
#endif /* internal 8MHz RC oscillator value */

/* define startup timeout value of internal 8MHz RC oscillator (IRC8M) */
#if !defined  (IRC8M_STARTUP_TIMEOUT)
#define IRC8M_STARTUP_TIMEOUT   ((uint16_t)0x0500)
#endif /* internal 8MHz RC oscillator startup timeout */

/* define value of internal RC oscillator for ADC in Hz */
#ifdef GD32F170_190
#if !defined  (IRC28M_VALUE)
#define IRC28M_VALUE ((uint32_t)28000000)
#endif /* IRC28M for GD32F170_190 */
#else 
#if !defined  (IRC14M_VALUE) 
#define IRC14M_VALUE ((uint32_t)14000000)
#endif /* IRC14M for GD32F130_150 */
#endif /* GD32F170_190 */

/* define value of internal 40KHz RC oscillator(IRC40K) in Hz */
#if !defined  (IRC40K_VALUE) 
#define IRC40K_VALUE  ((uint32_t)40000)
#endif /* internal 40KHz RC oscillator value */

/* define value of low speed crystal oscillator (LXTAL)in Hz */
#if !defined  (LXTAL_VALUE) 
#define LXTAL_VALUE  ((uint32_t)32768)
#endif /* low speed crystal oscillator value */

/* GD32F1x0 firmware library version number V3.0 */
#define __GD32F1x0_STDPERIPH_VERSION_MAIN   (0x03) /*!< [31:24] main version     */
#define __GD32F1x0_STDPERIPH_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version     */
#define __GD32F1x0_STDPERIPH_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version     */
#define __GD32F1x0_STDPERIPH_VERSION_RC     (0x00) /*!< [7:0]  release candidate */ 
#define __GD32F1x0_STDPERIPH_VERSION        ((__GD32F1x0_STDPERIPH_VERSION_MAIN << 24)\
                                            |(__GD32F1x0_STDPERIPH_VERSION_SUB1 << 16)\
                                            |(__GD32F1x0_STDPERIPH_VERSION_SUB2 << 8)\
                                            |(__GD32F1x0_STDPERIPH_VERSION_RC))

/* configuration of the Cortex-M3 processor and core peripherals */
#define __MPU_PRESENT             1        /*!< GD32F1x0 do not provide MPU                              */
#define __NVIC_PRIO_BITS          4        /*!< GD32F1x0 uses 4 bits for the priority levels             */
#define __Vendor_SysTickConfig    0        /*!< set to 1 if different sysTick config is used             */

/* define interrupt number */
typedef enum IRQn
{
    /* Cortex-M3 processor exceptions numbers */
    NonMaskableInt_IRQn          = -14,    /*!< 2 non maskable interrupt                                 */
    MemoryManagement_IRQn        = -12,    /*!< 4 Cortex-M3 memory management interrupt                  */
    BusFault_IRQn                = -11,    /*!< 5 Cortex-M3 bus fault interrupt                          */
    UsageFault_IRQn              = -10,    /*!< 6 Cortex-M3 usage fault interrupt                        */
    SVCall_IRQn                  = -5,     /*!< 11 Cortex-M3 SV call interrupt                           */
    DebugMonitor_IRQn            = -4,     /*!< 12 Cortex-M3 debug monitor interrupt                     */
    PendSV_IRQn                  = -2,     /*!< 14 Cortex-M3 pend SV interrupt                           */
    SysTick_IRQn                 = -1,     /*!< 15 Cortex-M3 system tick interrupt                       */
    /* interruput numbers */
    WWDGT_IRQn                   = 0,      /*!< window watchDog timer interrupt                          */
    LVD_IRQn                     = 1,      /*!< LVD through EXTI line detect interrupt                   */
    RTC_IRQn                     = 2,      /*!< RTC through EXTI line interrupt                          */
    FMC_IRQn                     = 3,      /*!< FMC interrupt                                            */
    RCU_IRQn                     = 4,      /*!< RCU interrupt                                            */
    EXTI0_1_IRQn                 = 5,      /*!< EXTI line 0 and 1 interrupts                             */
    EXTI2_3_IRQn                 = 6,      /*!< EXTI line 2 and 3 interrupts                             */
    EXTI4_15_IRQn                = 7,      /*!< EXTI line 4 to 15 interrupts                             */
    TSI_IRQn                     = 8,      /*!< TSI Interrupt                                            */
    DMA_Channel0_IRQn            = 9,      /*!< DMA channel 0 interrupt                                  */
    DMA_Channel1_2_IRQn          = 10,     /*!< DMA channel 1 and channel 2 interrupts                   */
    DMA_Channel3_4_IRQn          = 11,     /*!< DMA channel 3 and channel 4 interrupts                   */
    ADC_CMP_IRQn                 = 12,     /*!< ADC, CMP0 and CMP1 interrupts                            */
    TIMER0_BRK_UP_TRG_COM_IRQn   = 13,     /*!< TIMER0 break, update, trigger and commutation interrupts */
    TIMER0_CC_IRQn               = 14,     /*!< TIMER0 capture compare interrupt                         */
    TIMER1_IRQn                  = 15,     /*!< TIMER1 interrupt                                         */
    TIMER2_IRQn                  = 16,     /*!< TIMER2 interrupt                                         */
    TIMER5_DAC_IRQn              = 17,     /*!< TIMER5 and DAC interrupts                                */
    TIMER13_IRQn                 = 19,     /*!< TIMER13 interrupt                                        */
    TIMER14_IRQn                 = 20,     /*!< TIMER14 interrupt                                        */
    TIMER15_IRQn                 = 21,     /*!< TIMER15 interrupt                                        */
    TIMER16_IRQn                 = 22,     /*!< TIMER16 interrupt                                        */
    I2C0_EV_IRQn                 = 23,     /*!< I2C0 event interrupt                                     */
    I2C1_EV_IRQn                 = 24,     /*!< I2C1 event interrupt                                     */
    SPI0_IRQn                    = 25,     /*!< SPI0 interrupt                                           */
    SPI1_IRQn                    = 26,     /*!< SPI1 interrupt                                           */
    USART0_IRQn                  = 27,     /*!< USART0 interrupt                                         */
    USART1_IRQn                  = 28,     /*!< USART1 interrupt                                         */
    CEC_IRQn                     = 30,     /*!< CEC interrupt                                            */
    I2C0_ER_IRQn                 = 32,     /*!< I2C0 error interrupt                                     */
    I2C1_ER_IRQn                 = 34,     /*!< I2C1 error interrupt                                     */
    I2C2_EV_IRQn                 = 35,     /*!< I2C2 event interrupt                                     */
    I2C2_ER_IRQn                 = 36,     /*!< I2C2 error interrupt                                     */
    USBD_LP_IRQn                 = 37,     /*!< USBD_LP interrupt                                        */
    USBD_HP_IRQn                 = 38,     /*!< USBD_HP interrupt                                        */
    USBDWakeUp_IRQChannel        = 42,     /*!< USBD_WKUP interrupt                                      */
    CAN0_TX_IRQn                 = 43,     /*!< CAN0 TX interrupt                                        */
    CAN0_RX0_IRQn                = 44,     /*!< CAN0 RX0 interrupt                                       */
    CAN0_RX1_IRQn                = 45,     /*!< CAN0 RX1 interrupt                                       */
    CAN0_SCE_IRQn                = 46,     /*!< CAN0 SCE interrupt                                       */
    SLCD_IRQn                    = 47,     /*!< SLCD interrupt                                           */
    DMA_Channel5_6_IRQn          = 48,     /*!< DMA1 channel 5 and channel 6 interrupts                  */
    SPI2_IRQn                    = 51,     /*!< SPI2 global interrupt                                    */ 
    CAN1_TX_IRQn                 = 70,     /*!< CAN1 TX interrupt                                        */
    CAN1_RX0_IRQn                = 71,     /*!< CAN1 RX0 interrupt                                       */
    CAN1_RX1_IRQn                = 72,     /*!< CAN1 RX1 interrupt                                       */
    CAN1_SCE_IRQn                = 73,     /*!< CAN1 SCE interrupt                                       */ 
} IRQn_Type;

/* includes */
#include "core_cm3.h"
#include "system_gd32f1x0.h"
#include <stdint.h>

/* enum definitions */
typedef enum {DISABLE = 0, ENABLE = !DISABLE} EventStatus, ControlStatus;
//typedef enum {FALSE = 0, TRUE = !FALSE} bool;
typedef enum {RESET = 0, SET = !RESET} FlagStatus;
typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrStatus;

/* bit operations */
#define REG32(addr)                  (*(volatile uint32_t *)(addr))
#define REG16(addr)                  (*(volatile uint16_t *)(addr))
#define BIT(x)                       ((uint32_t)((uint32_t)0x01<<(x)))
#define BITS(start, end)             ((0xFFFFFFFFUL << (start)) & (0xFFFFFFFFUL >> (31 - (end)))) 
#define GET_BITS(regval, start, end) (((regval) & BITS(start,end)) >> (start))

/* main flash and SRAM memory map */
#define FLASH_BASE            ((uint32_t)0x08000000)        /*!< main FLASH base address          */
#define SRAM_BASE             ((uint32_t)0x20000000)        /*!< SRAM base address                */
/* SRAM and peripheral base bit-band region */
#define SRAM_BB_BASE          ((uint32_t)0x22000000)        /*!< SRAM bit-band base address       */
#define PERIPH_BB_BASE        ((uint32_t)0x42000000)        /*!< peripheral bit-band base address */
/* peripheral memory map */
#define APB1_BUS_BASE         ((uint32_t)0x40000000)        /*!< apb1 base address                */
#define APB2_BUS_BASE         ((uint32_t)0x40010000)        /*!< apb2 base address                */
#define AHB1_BUS_BASE         ((uint32_t)0x40020000)        /*!< ahb1 base address                */
#define AHB2_BUS_BASE         ((uint32_t)0x48000000)        /*!< ahb2 base address                */
/* advanced peripheral bus 1 memory map */
#define TIMER_BASE            (APB1_BUS_BASE + 0x00000000)  /*!< TIMER base address               */
#define SLCD_BASE             (APB1_BUS_BASE + 0x00002400)  /*!< SLCD base address                */
#define RTC_BASE              (APB1_BUS_BASE + 0x00002800)  /*!< RTC base address                 */
#define WWDGT_BASE            (APB1_BUS_BASE + 0x00002C00)  /*!< WWDGT base address               */
#define FWDGT_BASE            (APB1_BUS_BASE + 0x00003000)  /*!< FWDGT base address               */
#define USART_BASE            (APB1_BUS_BASE + 0x00004400)  /*!< USART base address               */
#define SPI_BASE              (APB1_BUS_BASE + 0x00003800)  /*!< SPI base address                 */
#define I2C_BASE              (APB1_BUS_BASE + 0x00005400)  /*!< I2C base address                 */
#define USBD_BASE             (APB1_BUS_BASE + 0x00005C00)  /*!< USBD base address                */
#define USBD_RAM_BASE         (APB1_BUS_BASE + 0x00006000)  /*!< USBD RAM base address            */
#define CAN_BASE              (APB1_BUS_BASE + 0x00006400)  /*!< CAN base address                 */
#define PMU_BASE              (APB1_BUS_BASE + 0x00007000)  /*!< PMU base address                 */
#define DAC_BASE              (APB1_BUS_BASE + 0x00007400)  /*!< DAC base address                 */
#define CEC_BASE              (APB1_BUS_BASE + 0x00007800)  /*!< CEC base address                 */
#define OPA_BASE              (APB1_BUS_BASE + 0x00007C5C)  /*!< OPA base address                 */
#define IVREF_BASE            (APB1_BUS_BASE + 0x00007C00)  /*!< IVREF base address               */
/* advanced peripheral bus 2 memory map */
#define SYSCFG_BASE           (APB2_BUS_BASE + 0x00000000)  /*!< SYSCFG base address              */
#define CMP_BASE              (APB2_BUS_BASE + 0x0000001C)  /*!< CMP base address                 */
#define EXTI_BASE             (APB2_BUS_BASE + 0x00000400)  /*!< EXTI base address                */
#define ADC_BASE              (APB2_BUS_BASE + 0x00002400)  /*!< ADC base address                 */
/* advanced high performance bus 1 memory map */
#define DMA_BASE              (AHB1_BUS_BASE + 0x00000000)  /*!< DMA base address                 */
#define DMA_CHANNEL_BASE      (DMA_BASE + 0x00000008)       /*!< DMA channel base address         */
#define RCU_BASE              (AHB1_BUS_BASE + 0x00001000)  /*!< RCU base address                 */
#define FMC_BASE              (AHB1_BUS_BASE + 0x00002000)  /*!< FMC base address                 */
#define CRC_BASE              (AHB1_BUS_BASE + 0x00003000)  /*!< CRC base address                 */
#define TSI_BASE              (AHB1_BUS_BASE + 0x00004000)  /*!< TSI base address                 */
/* advanced high performance bus 2 memory map */
#define GPIO_BASE             (AHB2_BUS_BASE + 0x00000000)  /*!< TSI base address                 */
/* option byte and debug memory map */
#define OB_BASE               ((uint32_t)0x1FFFF800)        /*!< OB base address                  */
#define DBG_BASE              ((uint32_t)0xE0042000)        /*!< DBG base address                 */

/* define marco USE_STDPERIPH_DRIVER */
#if !defined  USE_STDPERIPH_DRIVER
#define USE_STDPERIPH_DRIVER
#endif 
#ifdef USE_STDPERIPH_DRIVER
#include "gd32f1x0_libopt.h"
#endif /* USE_STDPERIPH_DRIVER */

#ifdef cplusplus
}
#endif
#endif 




