;**************************************************************************
;* File   : startup_at32f421pf4p7.s
;* Version: V1.3.0
;* Date   : 2021-03-18
;* Brief  : at32f4xx startup file for IAR Systems
;**************************************************************************
;

; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler                   ; Reset Handler
        DCD     NMI_Handler                     ; NMI Handler
        DCD     HardFault_Handler               ; Hard Fault Handler
        DCD     MemManage_Handler               ; MPU Fault Handler
        DCD     BusFault_Handler                ; Bus Fault Handler
        DCD     UsageFault_Handler              ; Usage Fault Handler
        DCD     0                               ; Reserved
        DCD     0                               ; Reserved
        DCD     0                               ; Reserved
        DCD     0                               ; Reserved
        DCD     SVC_Handler                     ; SVCall Handler
        DCD     DebugMon_Handler                ; Debug Monitor Handler
        DCD     0                               ; Reserved
        DCD     PendSV_Handler                  ; PendSV Handler
        DCD     SysTick_Handler                 ; SysTick Handler

        ; External Interrupts
        DCD     WWDG_IRQHandler                 ; Window Watchdog
        DCD     PVD_IRQHandler                  ; PVD through EXTI Line detect
        DCD     ERTC_IRQHandler                 ; ERTC
        DCD     FLASH_IRQHandler                ; Flash
        DCD     RCC_IRQHandler                  ; RCC
        DCD     EXTI1_0_IRQHandler              ; EXTI Line [1:0]
        DCD     EXTI3_2_IRQHandler              ; EXTI Line [3:2]
        DCD     EXTI15_4_IRQHandler             ; EXTI Line [15:4]
        DCD     0                               ; Reserved
        DCD     DMA1_Channel1_IRQHandler        ; DMA1 Channel 1
        DCD     DMA1_Channel3_2_IRQHandler      ; DMA1 Channel [3:2]
        DCD     DMA1_Channel7_4_IRQHandler      ; DMA1 Channel [7:4]
        DCD     ADC_COMP_IRQHandler             ; ADC & COMP
        DCD     TMR1_BRK_UP_TRG_COM_IRQHandler  ; TMR1 Break Update Trigger Commutation
        DCD     TMR1_CC_IRQHandler              ; TMR1 Capture Compare
        DCD     0                               ; Reserved
        DCD     TMR3_GLOBAL_IRQHandler          ; TMR3
        DCD     TMR6_GLOBAL_IRQHandler          ; TMR6
        DCD     0                               ; Reserved
        DCD     TMR14_GLOBAL_IRQHandler         ; TMR14
        DCD     TMR15_GLOBAL_IRQHandler         ; TMR15
        DCD     TMR16_GLOBAL_IRQHandler         ; TMR16
        DCD     TMR17_GLOBAL_IRQHandler         ; TMR17
        DCD     I2C1_EV_IRQHandler              ; I2C1 Event
        DCD     I2C2_EV_IRQHandler              ; I2C2 Event
        DCD     SPI1_IRQHandler                 ; SPI1
        DCD     0                               ; Reserved
        DCD     USART1_IRQHandler               ; USART1
        DCD     USART2_IRQHandler               ; USART2
        DCD     0                               ; Reserved
        DCD     0                               ; Reserved
        DCD     0                               ; Reserved
        DCD     I2C1_ER_IRQHandler              ; I2C1 Error
        DCD     0                               ; Reserved
        DCD     I2C2_ER_IRQHandler              ; I2C2 Error
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B MemManage_Handler

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B BusFault_Handler

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B UsageFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B DebugMon_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B SysTick_Handler

        PUBWEAK WWDG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
WWDG_IRQHandler
        B WWDG_IRQHandler

        PUBWEAK PVD_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PVD_IRQHandler
        B PVD_IRQHandler

        PUBWEAK ERTC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ERTC_IRQHandler
        B ERTC_IRQHandler

        PUBWEAK FLASH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FLASH_IRQHandler
        B FLASH_IRQHandler

        PUBWEAK RCC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RCC_IRQHandler
        B RCC_IRQHandler

        PUBWEAK EXTI1_0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI1_0_IRQHandler
        B EXTI1_0_IRQHandler

        PUBWEAK EXTI3_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI3_2_IRQHandler
        B EXTI3_2_IRQHandler

        PUBWEAK EXTI15_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI15_4_IRQHandler
        B EXTI15_4_IRQHandler

        PUBWEAK DMA1_Channel1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel1_IRQHandler
        B DMA1_Channel1_IRQHandler

        PUBWEAK DMA1_Channel3_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel3_2_IRQHandler
        B DMA1_Channel3_2_IRQHandler

        PUBWEAK DMA1_Channel7_4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_Channel7_4_IRQHandler
        B DMA1_Channel7_4_IRQHandler

        PUBWEAK ADC_COMP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC_COMP_IRQHandler
        B ADC_COMP_IRQHandler

        PUBWEAK TMR1_BRK_UP_TRG_COM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TMR1_BRK_UP_TRG_COM_IRQHandler
        B TMR1_BRK_UP_TRG_COM_IRQHandler

        PUBWEAK TMR1_CC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TMR1_CC_IRQHandler
        B TMR1_CC_IRQHandler

        PUBWEAK TMR3_GLOBAL_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TMR3_GLOBAL_IRQHandler
        B TMR3_GLOBAL_IRQHandler

        PUBWEAK TMR6_GLOBAL_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TMR6_GLOBAL_IRQHandler
        B TMR6_GLOBAL_IRQHandler

        PUBWEAK TMR14_GLOBAL_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TMR14_GLOBAL_IRQHandler
        B TMR14_GLOBAL_IRQHandler

        PUBWEAK TMR15_GLOBAL_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TMR15_GLOBAL_IRQHandler
        B TMR15_GLOBAL_IRQHandler

        PUBWEAK TMR16_GLOBAL_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TMR16_GLOBAL_IRQHandler
        B TMR16_GLOBAL_IRQHandler

        PUBWEAK TMR17_GLOBAL_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TMR17_GLOBAL_IRQHandler
        B TMR17_GLOBAL_IRQHandler

        PUBWEAK I2C1_EV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_EV_IRQHandler
        B I2C1_EV_IRQHandler

        PUBWEAK I2C2_EV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_EV_IRQHandler
        B I2C2_EV_IRQHandler

        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_IRQHandler
        B SPI1_IRQHandler

        PUBWEAK USART1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USART1_IRQHandler
        B USART1_IRQHandler

        PUBWEAK USART2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USART2_IRQHandler
        B USART2_IRQHandler

        PUBWEAK I2C1_ER_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_ER_IRQHandler
        B I2C1_ER_IRQHandler

        PUBWEAK I2C2_ER_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_ER_IRQHandler
        B I2C2_ER_IRQHandler
		
        END
