/**
  **************************************************************************
  * File   : at32f4xx_usart.h
  * Version: V1.3.0
  * Date   : 2021-03-18
  * Brief  : at32f4xx USART header file
  **************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32F4XX_USART_H
#define __AT32F4XX_USART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "at32f4xx.h"

/** @addtogroup at32f4xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup USART
  * @{
  */

/** @defgroup USART_Exported_Types
  * @{
  */

/**
  * @brief  USART Init Structure definition
  */

typedef struct
{
    uint32_t USART_BaudRate;                /*!< This member configures the USART communication baud rate.
                                                 The baud rate is computed using the following formula:
                                                  - IntegerDivider = ((PCLKx) / (16 * (USART_InitStruct->USART_BaudRate)))
                                                  - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 16) + 0.5 */

    uint16_t USART_WordLength;               /*!< Specifies the number of data bits transmitted or received in a frame.
                                                  This parameter can be a value of @ref USART_Word_Length */

    uint16_t USART_StopBits;                /*!< Specifies the number of stop bits transmitted.
                                                 This parameter can be a value of @ref USART_Stop_Bits */
                                             
    uint16_t USART_Parity;                  /*!< Specifies the parity mode.
                                                 This parameter can be a value of @ref USART_Parity
                                                 @note When parity is enabled, the computed parity is inserted
                                                       at the MSB position of the transmitted data (9th bit when
                                                       the word length is set to 9 data bits; 8th bit when the
                                                       word length is set to 8 data bits). */
                                            
    uint16_t USART_Mode;                    /*!< Specifies wether the Receive or Transmit mode is enabled or disabled.
                                                 This parameter can be a value of @ref USART_Mode */
                                            
    uint16_t USART_HardwareFlowControl;     /*!< Specifies wether the hardware flow control mode is enabled
                                                 or disabled.
                                                 This parameter can be a value of @ref USART_Hardware_Flow_Control */
} USART_InitType;

/**
  * @brief  USART Clock Init Structure definition
  */

typedef struct
{

    uint16_t USART_Clock;                   /*!< Specifies whether the USART clock is enabled or disabled.
                                                This parameter can be a value of @ref USART_Clock */
                                            
    uint16_t USART_CPOL;                    /*!< Specifies the steady state value of the serial clock.
                                                This parameter can be a value of @ref USART_Clock_Polarity */
                                            
    uint16_t USART_CPHA;                    /*!< Specifies the clock transition on which the bit capture is made.
                                                This parameter can be a value of @ref USART_Clock_Phase */
                                            
    uint16_t USART_LastBit;                 /*!< Specifies whether the clock pulse corresponding to the last transmitted
                                                data bit (MSB) has to be output on the SCLK pin in synchronous mode.
                                                This parameter can be a value of @ref USART_Last_Bit */
} USART_ClockInitType;

/**
  * @}
  */

/** @defgroup USART_Exported_Constants
  * @{
  */
#if defined (AT32F403xx) || defined (AT32F413xx) || defined (AT32F415xx)
  #define IS_USART_ALL_PERIPH(PERIPH)         (((PERIPH) == USART1) || \
                                               ((PERIPH) == USART2) || \
                                               ((PERIPH) == USART3) || \
                                               ((PERIPH) == UART4)  || \
                                               ((PERIPH) == UART5))
#elif defined (AT32F403Axx)|| defined (AT32F407xx)
  #define IS_USART_ALL_PERIPH(PERIPH)         (((PERIPH) == USART1) || \
                                               ((PERIPH) == USART2) || \
                                               ((PERIPH) == USART3) || \
                                               ((PERIPH) == UART4)  || \
                                               ((PERIPH) == UART5)  || \
                                               ((PERIPH) == USART6) || \
                                               ((PERIPH) == UART7)  || \
                                               ((PERIPH) == UART8))
#elif defined (AT32F421xx)
  #define IS_USART_ALL_PERIPH(PERIPH)         (((PERIPH) == USART1) || \
                                               ((PERIPH) == USART2))
#endif

#if !defined (AT32F421xx)
#define IS_USART_123_PERIPH(PERIPH)         (((PERIPH) == USART1) || \
                                             ((PERIPH) == USART2) || \
                                             ((PERIPH) == USART3))
#else
#define IS_USART_123_PERIPH(PERIPH)         (((PERIPH) == USART1) || \
                                             ((PERIPH) == USART2))
#endif

#if !defined (AT32F421xx)
#define IS_USART_1234_PERIPH(PERIPH)        (((PERIPH) == USART1) || \
                                             ((PERIPH) == USART2) || \
                                             ((PERIPH) == USART3) || \
                                             ((PERIPH) == UART4))
#else
#define IS_USART_1234_PERIPH(PERIPH)        (((PERIPH) == USART1) || \
                                             ((PERIPH) == USART2))
#endif
/** @defgroup USART_Word_Length
  * @{
  */

#define USART_WordLength_8b                 ((uint16_t)0x0000)
#define USART_WordLength_9b                 ((uint16_t)0x1000)

#define IS_USART_WORD_LENGTH(LENGTH)        (((LENGTH) == USART_WordLength_8b) || \
                                             ((LENGTH) == USART_WordLength_9b))
/**
  * @}
  */

/** @defgroup USART_Stop_Bits
  * @{
  */
                                            
#define USART_StopBits_1                    ((uint16_t)0x0000)
#define USART_StopBits_0_5                  ((uint16_t)0x1000)
#define USART_StopBits_2                    ((uint16_t)0x2000)
#define USART_StopBits_1_5                  ((uint16_t)0x3000)
#define IS_USART_STOPBITS(STOPBITS)         (((STOPBITS) == USART_StopBits_1) || \
                                             ((STOPBITS) == USART_StopBits_0_5) || \
                                             ((STOPBITS) == USART_StopBits_2) || \
                                             ((STOPBITS) == USART_StopBits_1_5))
/**
  * @}
  */

/** @defgroup USART_Parity
  * @{
  */

#define USART_Parity_No                     ((uint16_t)0x0000)
#define USART_Parity_Even                   ((uint16_t)0x0400)
#define USART_Parity_Odd                    ((uint16_t)0x0600)
#define IS_USART_PARITY(PARITY)             (((PARITY) == USART_Parity_No) || \
                                             ((PARITY) == USART_Parity_Even) || \
                                             ((PARITY) == USART_Parity_Odd))
/**
  * @}
  */

/** @defgroup USART_Mode
  * @{
  */

#define USART_Mode_Rx                       ((uint16_t)0x0004)
#define USART_Mode_Tx                       ((uint16_t)0x0008)
#define IS_USART_MODE(MODE)                 ((((MODE) & (uint16_t)0xFFF3) == 0x00) && ((MODE) != (uint16_t)0x00))
/**
  * @}
  */

/** @defgroup USART_Hardware_Flow_Control
  * @{
  */
#define USART_HardwareFlowControl_None      ((uint16_t)0x0000)
#define USART_HardwareFlowControl_RTS       ((uint16_t)0x0100)
#define USART_HardwareFlowControl_CTS       ((uint16_t)0x0200)
#define USART_HardwareFlowControl_RTS_CTS   ((uint16_t)0x0300)
#define IS_USART_HARDWARE_FLOW_CONTROL(CONTROL)\
                                            (((CONTROL) == USART_HardwareFlowControl_None) || \
                                             ((CONTROL) == USART_HardwareFlowControl_RTS) || \
                                             ((CONTROL) == USART_HardwareFlowControl_CTS) || \
                                             ((CONTROL) == USART_HardwareFlowControl_RTS_CTS))
/**
  * @}
  */

/** @defgroup USART_Clock
  * @{
  */
#define USART_Clock_Disable                 ((uint16_t)0x0000)
#define USART_Clock_Enable                  ((uint16_t)0x0800)
#define IS_USART_CLOCK(CLOCK)               (((CLOCK) == USART_Clock_Disable) || \
                                             ((CLOCK) == USART_Clock_Enable))
/**
  * @}
  */

/** @defgroup USART_Clock_Polarity
  * @{
  */

#define USART_CPOL_Low                      ((uint16_t)0x0000)
#define USART_CPOL_High                     ((uint16_t)0x0400)
#define IS_USART_CPOL(CPOL)                 (((CPOL) == USART_CPOL_Low) || ((CPOL) == USART_CPOL_High))

/**
  * @}
  */

/** @defgroup USART_Clock_Phase
  * @{
  */

#define USART_CPHA_1Edge                    ((uint16_t)0x0000)
#define USART_CPHA_2Edge                    ((uint16_t)0x0200)
#define IS_USART_CPHA(CPHA)                 (((CPHA) == USART_CPHA_1Edge) || ((CPHA) == USART_CPHA_2Edge))

/**
  * @}
  */

/** @defgroup USART_Last_Bit
  * @{
  */

#define USART_LastBit_Disable               ((uint16_t)0x0000)
#define USART_LastBit_Enable                ((uint16_t)0x0100)
#define IS_USART_LASTBIT(LASTBIT)           (((LASTBIT) == USART_LastBit_Disable) || \
                                             ((LASTBIT) == USART_LastBit_Enable))
/**
  * @}
  */

/** @defgroup USART_Interrupt_definition
  * @{
  */

#define USART_INT_PERR                      ((uint16_t)0x0028)
#define USART_INT_TDE                       ((uint16_t)0x0727)
#define USART_INT_TRAC                      ((uint16_t)0x0626)
#define USART_INT_RDNE                      ((uint16_t)0x0525)
#define USART_INT_IDLEF                     ((uint16_t)0x0424)
#define USART_INT_LBDF                      ((uint16_t)0x0846)
#define USART_INT_CTSF                      ((uint16_t)0x096A)
#define USART_INT_ERR                       ((uint16_t)0x0060)
#define USART_INT_ORERR                     ((uint16_t)0x0360)
#define USART_INT_NERR                      ((uint16_t)0x0260)
#define USART_INT_FERR                      ((uint16_t)0x0160)
#define IS_USART_CONFIG_INT(INT)            (((INT) == USART_INT_PERR)  || ((INT) == USART_INT_TDE) || \
                                             ((INT) == USART_INT_TRAC)  || ((INT) == USART_INT_RDNE) || \
                                             ((INT) == USART_INT_IDLEF) || ((INT) == USART_INT_LBDF) || \
                                             ((INT) == USART_INT_CTSF)  || ((INT) == USART_INT_ERR))
#define IS_USART_GET_INT(INT)               (((INT) == USART_INT_PERR)  || ((INT) == USART_INT_TDE) || \
                                             ((INT) == USART_INT_TRAC)  || ((INT) == USART_INT_RDNE) || \
                                             ((INT) == USART_INT_IDLEF) || ((INT) == USART_INT_LBDF) || \
                                             ((INT) == USART_INT_CTSF)  || ((INT) == USART_INT_ORERR) || \
                                             ((INT) == USART_INT_NERR)  || ((INT) == USART_INT_FERR))
#define IS_USART_CLEAR_INT(INT)             (((INT) == USART_INT_TRAC)  || ((INT) == USART_INT_RDNE) || \
                                             ((INT) == USART_INT_LBDF)  || ((INT) == USART_INT_CTSF))
/**
  * @}
  */

/** @defgroup USART_DMA_Requests
  * @{
  */

#define USART_DMAReq_Tx                     ((uint16_t)0x0080)
#define USART_DMAReq_Rx                     ((uint16_t)0x0040)
#define IS_USART_DMAREQ(DMAREQ)             ((((DMAREQ) & (uint16_t)0xFF3F) == 0x00) && ((DMAREQ) != (uint16_t)0x00))

/**
  * @}
  */

/** @defgroup USART_WakeUp_methods
  * @{
  */

#define USART_WakeUp_IdleLine               ((uint16_t)0x0000)
#define USART_WakeUp_AddressMark            ((uint16_t)0x0800)
#define IS_USART_WAKEUP(WAKEUP)             (((WAKEUP) == USART_WakeUp_IdleLine) || \
                                             ((WAKEUP) == USART_WakeUp_AddressMark))
/**
  * @}
  */

/** @defgroup USART_LIN_Break_Detection_Length
  * @{
  */

#define USART_LINBreakDetectLength_10b      ((uint16_t)0x0000)
#define USART_LINBreakDetectLength_11b      ((uint16_t)0x0020)
#define IS_USART_LIN_BREAK_DETECT_LENGTH(LENGTH) \
                                            (((LENGTH) == USART_LINBreakDetectLength_10b) || \
                                             ((LENGTH) == USART_LINBreakDetectLength_11b))
/**
  * @}
  */

/** @defgroup USART_IrDA_Low_Power
  * @{
  */

#define USART_IrDAMode_LowPower             ((uint16_t)0x0004)
#define USART_IrDAMode_Normal               ((uint16_t)0x0000)
#define IS_USART_IRDA_MODE(MODE)            (((MODE) == USART_IrDAMode_LowPower) || \
                                             ((MODE) == USART_IrDAMode_Normal))
/**
  * @}
  */

/** @defgroup USART_Flags
  * @{
  */

#define USART_FLAG_CTSF                     ((uint16_t)0x0200)
#define USART_FLAG_LBDF                     ((uint16_t)0x0100)
#define USART_FLAG_TDE                      ((uint16_t)0x0080)
#define USART_FLAG_TRAC                     ((uint16_t)0x0040)
#define USART_FLAG_RDNE                     ((uint16_t)0x0020)
#define USART_FLAG_IDLEF                    ((uint16_t)0x0010)
#define USART_FLAG_ORERR                    ((uint16_t)0x0008)
#define USART_FLAG_NERR                     ((uint16_t)0x0004)
#define USART_FLAG_FERR                     ((uint16_t)0x0002)
#define USART_FLAG_PERR                     ((uint16_t)0x0001)
#define IS_USART_FLAG(FLAG)                 (((FLAG) == USART_FLAG_PERR) || ((FLAG) == USART_FLAG_TDE) || \
                                             ((FLAG) == USART_FLAG_TRAC) || ((FLAG) == USART_FLAG_RDNE) || \
                                             ((FLAG) == USART_FLAG_IDLEF)|| ((FLAG) == USART_FLAG_LBDF) || \
                                             ((FLAG) == USART_FLAG_CTSF) || ((FLAG) == USART_FLAG_ORERR) || \
                                             ((FLAG) == USART_FLAG_NERR) || ((FLAG) == USART_FLAG_FERR))

#define IS_USART_CLEAR_FLAG(FLAG)           ((((FLAG) & (uint16_t)0xFC9F) == 0x00) && ((FLAG) != (uint16_t)0x00))
#define IS_USART_PERIPH_FLAG(PERIPH, USART_FLAG)    ((((*(uint32_t*)&(PERIPH)) != UART4_BASE) &&\
                                                     ((*(uint32_t*)&(PERIPH)) != UART5_BASE) &&\
                                                     ((*(uint32_t*)&(PERIPH)) != UART7_BASE) &&\
                                                     ((*(uint32_t*)&(PERIPH)) != UART8_BASE)) \
                                                     || ((USART_FLAG) != USART_FLAG_CTSF))
#define IS_USART_ADDRESS(ADDRESS)           ((ADDRESS) <= 0xF)
#define IS_USART_DATA(DATA)                 ((DATA) <= 0x1FF)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup USART_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup USART_Exported_Functions
  * @{
  */
void USART_SendBreak(USART_Type* USARTx);
void USART_SetGuardTime(USART_Type* USARTx, uint8_t USART_GuardTime);
void USART_SetPrescaler(USART_Type* USARTx, uint8_t USART_Prescaler);
void USART_SmartCardCmd(USART_Type* USARTx, FunctionalState NewState);
void USART_SmartCardNACKCmd(USART_Type* USARTx, FunctionalState NewState);
void USART_HalfDuplexCmd(USART_Type* USARTx, FunctionalState NewState);
void USART_IrDAConfig(USART_Type* USARTx, uint16_t USART_IrDAMode);
void USART_IrDACmd(USART_Type* USARTx, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_Type* USARTx, uint16_t USART_FLAG);
void USART_Reset(USART_Type* USARTx);
void USART_Init(USART_Type* USARTx, USART_InitType* USART_InitStruct);
void USART_StructInit(USART_InitType* USART_InitStruct);
void USART_ClockInit(USART_Type* USARTx, USART_ClockInitType* USART_ClockInitStruct);
void USART_ReceiverWakeUpCmd(USART_Type* USARTx, FunctionalState NewState);
void USART_LINBreakDetectLengthConfig(USART_Type* USARTx, uint16_t USART_LINBreakDetectLength);
void USART_LINCmd(USART_Type* USARTx, FunctionalState NewState);
void USART_SendData(USART_Type* USARTx, uint16_t Data);
uint16_t USART_ReceiveData(USART_Type* USARTx);
void USART_ClearFlag(USART_Type* USARTx, uint16_t USART_FLAG);
ITStatus USART_GetITStatus(USART_Type* USARTx, uint16_t USART_INT);
void USART_ClearITPendingBit(USART_Type* USARTx, uint16_t USART_INT);
#if defined (AT32F421xx)
void USART_SWAP(USART_Type* USARTx, FunctionalState NewState);
#endif
void USART_ClockStructInit(USART_ClockInitType* USART_ClockInitStruct);
void USART_Cmd(USART_Type* USARTx, FunctionalState NewState);
void USART_INTConfig(USART_Type* USARTx, uint16_t USART_INT, FunctionalState NewState);
void USART_DMACmd(USART_Type* USARTx, uint16_t USART_DMAReq, FunctionalState NewState);
void USART_SetAddress(USART_Type* USARTx, uint8_t USART_Address);
void USART_WakeUpConfig(USART_Type* USARTx, uint16_t USART_WakeUp);

#ifdef __cplusplus
}
#endif

#endif /* __AT32F4XX_USART_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */


