/**
  **************************************************************************
  * File   : at32f4xx_comp.h
  * Version: V1.3.0
  * Date   : 2021-03-18
  * Brief  : at32f4xx COMP header file
  **************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32F4XX_COMP_H
#define __AT32F4XX_COMP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "at32f4xx.h"

/** @addtogroup AT32F4xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup COMP
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** 
  * @brief  COMP Init structure definition  
  */
  
typedef struct
{

  uint32_t COMP_INMInput;     /*!< Selects the inverting input of the comparator.
                                          This parameter can be a value of @ref COMP_INMInput */

  uint32_t COMP_Output;             /*!< Selects the output redirection of the comparator.
                                          This parameter can be a value of @ref COMP_Output */

  uint32_t COMP_OutPolarity;           /*!< Selects the output polarity of the comparator.
                                          This parameter can be a value of @ref COMP_OutputPolarity */

  uint32_t COMP_Hysteresis;         /*!< Selects the hysteresis voltage of the comparator.
                                          This parameter can be a value of @ref COMP_Hysteresis */

  uint32_t COMP_Mode;               /*!< Selects the operating mode of the comparator
                                         and allows to adjust the speed/consumption.
                                          This parameter can be a value of @ref COMP_Mode */

}COMP_InitType;

/* Exported constants --------------------------------------------------------*/
   
/** @defgroup COMP_Exported_Constants
  * @{
  */ 

/** @defgroup COMP_Selection
  * @{
  */

#define COMP1_Selection                    ((uint32_t)0x00000000) /*!< COMP1 Selection */
#ifndef AT32F421xx
#define COMP2_Selection                    ((uint32_t)0x00000010) /*!< COMP2 Selection */
#endif

#ifdef AT32F421xx
#define IS_COMP_ALL_PERIPH(PERIPH) (((PERIPH) == COMP1_Selection))
#else
#define IS_COMP_ALL_PERIPH(PERIPH) (((PERIPH) == COMP1_Selection) || \
                                    ((PERIPH) == COMP2_Selection))
#endif

/**
  * @}
  */ 

/** @defgroup COMP_NonInvertingInput
  * @{
  */
#ifdef AT32F421xx
#define COMP_INPInput_00               ((uint32_t)0x00000000) /*!< PA5 connected to comparator1 non-inverting input */
#define COMP_INPInput_01               ((uint32_t)0x00000080) /*!< PA1 connected to comparator1 non-inverting input */
#define COMP_INPInput_10               ((uint32_t)0x00000100) /*!< PA0 connected to comparator1 non-inverting input */
#define COMP_INPInput_11               ((uint32_t)0x00000180) /*!< VSSA connected to comparator1 non-inverting input */
#define IS_COMP_NONINVERTING_INPUT(INPUT) (((INPUT) == COMP_INPInput_00) || \
                                          ((INPUT) == COMP_INPInput_01) || \
                                          ((INPUT) == COMP_INPInput_10) || \
                                          ((INPUT) == COMP_INPInput_11))
#else
#define COMP_INPInput_00               ((uint32_t)0x00000000) /*!< PA5/PA7 connected to comparator1/2 non-inverting input */
#define COMP_INPInput_01               ((uint32_t)0x00000001) /*!< PA1/PA3 connected to comparator1/2 non-inverting input */
#define COMP_INPInput_10               ((uint32_t)0x00000002) /*!< PA0/PA2 connected to comparator1/2 non-inverting input */
#define IS_COMP_NONINVERTING_INPUT(INPUT) (((INPUT) == COMP_INPInput_00) || \
                                          ((INPUT) == COMP_INPInput_01) || \
                                          ((INPUT) == COMP_INPInput_10))
#endif


/** @defgroup COMP_InvertingInput
  * @{
  */

#define COMP_INMInput_1_4VREFINT          ((uint32_t)0x00000000) /*!< 1/4 VREFINT connected to comparator inverting input */
#define COMP_INMInput_1_2VREFINT          ((uint32_t)0x00000010) /*!< 1/2 VREFINT connected to comparator inverting input */
#define COMP_INMInput_3_4VREFINT          ((uint32_t)0x00000020) /*!< 3/4 VREFINT connected to comparator inverting input */
#define COMP_INMInput_VREFINT             ((uint32_t)0x00000030) /*!< VREFINT connected to comparator inverting input */
#define COMP_INMInput_IN1                 ((uint32_t)0x00000040) /*!< I/O (PA4 for COMP1 and PA3 for COMP2) connected to comparator inverting input */
#define COMP_INMInput_IN2                 ((uint32_t)0x00000050) /*!< I/O (PA5 for COMP1 and PA7 for COMP2) connected to comparator inverting input */
#define COMP_INMInput_IN3                 ((uint32_t)0x00000060) /*!< I/O (PA0 for COMP1 and PA2 for COMP2) connected to comparator inverting input */
#ifdef AT32F421xx
#define COMP_INMInput_IN4                 ((uint32_t)0x00000070) /*!< I/O (PA2 for COMP1) connected to comparator inverting input */
#define IS_COMP_INVERTING_INPUT(INPUT) (((INPUT) == COMP_INMInput_1_4VREFINT) || \
                                        ((INPUT) == COMP_INMInput_1_2VREFINT) || \
                                        ((INPUT) == COMP_INMInput_3_4VREFINT) || \
                                        ((INPUT) == COMP_INMInput_VREFINT)    || \
                                        ((INPUT) == COMP_INMInput_IN1)        || \
                                        ((INPUT) == COMP_INMInput_IN2)        || \
                                        ((INPUT) == COMP_INMInput_IN3)        || \
                                        ((INPUT) == COMP_INMInput_IN4))
#else
#define IS_COMP_INVERTING_INPUT(INPUT) (((INPUT) == COMP_INMInput_1_4VREFINT) || \
                                        ((INPUT) == COMP_INMInput_1_2VREFINT) || \
                                        ((INPUT) == COMP_INMInput_3_4VREFINT) || \
                                        ((INPUT) == COMP_INMInput_VREFINT)    || \
                                        ((INPUT) == COMP_INMInput_IN1)        || \
                                        ((INPUT) == COMP_INMInput_IN2)        || \
                                        ((INPUT) == COMP_INMInput_IN3))
#endif


/**
  * @}
  */ 
  
/** @defgroup COMP_Output
  * @{
  */

#define COMP_Output_None                  ((uint32_t)0x00000000)   /*!< COMP output isn't connected to other peripherals */
#ifdef AT32F421xx
#define COMP_Output_TMR1BKIN              ((uint32_t)0x00000400)   /*!< COMP output connected to TIM1 Break Input (BKIN) */
#define COMP_Output_TMR1IC1               ((uint32_t)0x00000800)   /*!< COMP output connected to TIM1 Input Capture 1 */
#define COMP_Output_TMR1OCREFCLR          ((uint32_t)0x00000C00)   /*!< COMP output connected to TIM1 OCREF Clear */
#define COMP_Output_TMR3IC1               ((uint32_t)0x00001800)   /*!< COMP output connected to TIM3 Input Capture 1 */
#define COMP_Output_TMR3OCREFCLR          ((uint32_t)0x00001C00)   /*!< COMP output connected to TIM3 OCREF Clear */
#else
#define COMP_Output_TMR1BKIN              ((uint32_t)0x00000100)   /*!< COMP output connected to TIM1 Break Input (BKIN) */
#define COMP_Output_TMR1IC1               ((uint32_t)0x00000200)   /*!< COMP output connected to TIM1 Input Capture 1 */
#define COMP_Output_TMR1OCREFCLR          ((uint32_t)0x00000300)   /*!< COMP output connected to TIM1 OCREF Clear */
#define COMP_Output_TMR2IC4               ((uint32_t)0x00000400)   /*!< COMP output connected to TIM2 Input Capture 4 */
#define COMP_Output_TMR2OCREFCLR          ((uint32_t)0x00000500)   /*!< COMP output connected to TIM2 OCREF Clear */
#define COMP_Output_TMR3IC1               ((uint32_t)0x00000600)   /*!< COMP output connected to TIM3 Input Capture 1 */
#define COMP_Output_TMR3OCREFCLR          ((uint32_t)0x00000700)   /*!< COMP output connected to TIM3 OCREF Clear */
#endif

#ifdef AT32F421xx
#define IS_COMP_OUTPUT(OUTPUT) (((OUTPUT) == COMP_Output_None)         || \
                                ((OUTPUT) == COMP_Output_TMR1BKIN)     || \
                                ((OUTPUT) == COMP_Output_TMR1IC1)      || \
                                ((OUTPUT) == COMP_Output_TMR1OCREFCLR) || \
                                ((OUTPUT) == COMP_Output_TMR3IC1)      || \
                                ((OUTPUT) == COMP_Output_TMR3OCREFCLR))
#else
#define IS_COMP_OUTPUT(OUTPUT) (((OUTPUT) == COMP_Output_None)         || \
                                ((OUTPUT) == COMP_Output_TMR1BKIN)     || \
                                ((OUTPUT) == COMP_Output_TMR1IC1)      || \
                                ((OUTPUT) == COMP_Output_TMR1OCREFCLR) || \
                                ((OUTPUT) == COMP_Output_TMR2IC4)      || \
                                ((OUTPUT) == COMP_Output_TMR2OCREFCLR) || \
                                ((OUTPUT) == COMP_Output_TMR3IC1)      || \
                                ((OUTPUT) == COMP_Output_TMR3OCREFCLR))
#endif
/**
  * @}
  */ 

/** @defgroup COMP_OutputPolarity
  * @{
  */
#define COMP_OutPolarity_NonInverted          ((uint32_t)0x00000000)  /*!< COMP output on GPIO isn't inverted */
#define COMP_OutPolarity_Inverted             COMP_CTRLSTS_COMP1POL       /*!< COMP output on GPIO is inverted */

#define IS_COMP_OUTPUT_POL(POL) (((POL) == COMP_OutPolarity_NonInverted)  || \
                                 ((POL) == COMP_OutPolarity_Inverted))

/**
  * @}
  */ 

/** @defgroup COMP_Hysteresis
  * @{
  */
/* Please refer to the electrical characteristics in the device datasheet for
   the hysteresis level */
#define COMP_Hysteresis_No                         ((uint32_t)0x00000000)   /*!< No hysteresis */
#define COMP_Hysteresis_Low                        COMP_CTRLSTS_COMP1HYST_0 /*!< Hysteresis level low */
#define COMP_Hysteresis_Medium                     COMP_CTRLSTS_COMP1HYST_1 /*!< Hysteresis level medium */
#define COMP_Hysteresis_High                       COMP_CTRLSTS_COMP1HYST   /*!< Hysteresis level high */

#define IS_COMP_HYSTERESIS(HYSTERESIS)    (((HYSTERESIS) == COMP_Hysteresis_No) || \
                                           ((HYSTERESIS) == COMP_Hysteresis_Low) || \
                                           ((HYSTERESIS) == COMP_Hysteresis_Medium) || \
                                           ((HYSTERESIS) == COMP_Hysteresis_High))
/**
  * @}
  */

/** @defgroup COMP_Mode
  * @{
  */
/* Please refer to the electrical characteristics in the device datasheet for
   the power consumption values */
#define COMP_Mode_Fast                     ((uint32_t)0x00000000)  /*!< High Speed */
#ifdef AT32F421xx
#define COMP_Mode_Medium                   COMP_CTRLSTS_COMP1MDE_0 /*!< Low power mode */
#define COMP_Mode_Slow                     COMP_CTRLSTS_COMP1MDE_1 /*!< Low power mode */
#define COMP_Mode_Very_Slow                COMP_CTRLSTS_COMP1MDE /*!< Low power mode */
#define IS_COMP_MODE(MODE)    (((MODE) == COMP_Mode_Fast)      || \
                               ((MODE) == COMP_Mode_Medium)    || \
                               ((MODE) == COMP_Mode_Slow)      || \
                               ((MODE) == COMP_Mode_Very_Slow))
#else
#define COMP_Mode_Slow                     COMP_CTRLSTS_COMP1MDE /*!< Low power mode */
#define IS_COMP_MODE(MODE)    (((MODE) == COMP_Mode_Fast)    || \
                               ((MODE) == COMP_Mode_Slow))
#endif

/**
  * @}
  */
  
/** @defgroup COMP_SCAL_BRG
  * @{
  */
/* Please refer to the electrical characteristics in the device datasheet for
   the SCAL and BRG */
#define COMP_SCAL_BRG_00            ((uint32_t)0x00000000)
#define COMP_SCAL_BRG_10            COMP_CTRLSTS_COMP1SCALEN
#define COMP_SCAL_BRG_11            (COMP_CTRLSTS_COMP1SCALEN | COMP_CTRLSTS_COMP1BRGEN)

#define IS_COMP_SCAL_BRG(MODE)    (((SCAL_BRG) == COMP_SCAL_BRG_00)    || \
                                   ((SCAL_BRG) == COMP_SCAL_BRG_10)    || \
                                   ((SCAL_BRG) == COMP_SCAL_BRG_11))
/**
  * @}
  */
  
/** @defgroup COMP_OutputLevel
  * @{
  */ 
/* When output polarity is not inverted, comparator output is high when
   the non-inverting input is at a higher voltage than the inverting input */
#define COMP_OutputState_High                   COMP_CTRLSTS_COMP1OUT
/* When output polarity is not inverted, comparator output is low when
   the non-inverting input is at a lower voltage than the inverting input*/
#define COMP_OutputState_Low                    ((uint32_t)0x00000000)

/**
  * @}
  */ 

#ifdef AT32F421xx
/** @defgroup COMP_High_Pulse_Filter
  * @{
  */        
  
#define IS_COMP_HighPulseCnt(HighPulse)          ((HighPulse) <= 0x3F)
/**
  * @}
  */
  
/** @defgroup COMP_Low_Pulse_Filter
  * @{
  */        
  
#define IS_COMP_LowPulseCnt(LowPulse)            ((LowPulse) <= 0x3F)
/**
  * @}
  */

/** @defgroup COMP_Blanking
  * @{
  */
/* Please refer to the electrical characteristics in the device datasheet for
   the blanking source */
#define COMP_Blanking_None                       ((uint32_t)0x00000000)
#define COMP_Blanking_TMR1OC4                    ((uint32_t)0x00040000)
#define COMP_Blanking_TMR3OC3                    ((uint32_t)0x000C0000)
#define COMP_Blanking_TMR15OC2                   ((uint32_t)0x00100000)
#define COMP_Blanking_TMR15OC1                   ((uint32_t)0x00180000)

#define IS_COMP_BLANKING(Blanking)    (((Blanking) == COMP_Blanking_None)       || \
                                       ((Blanking) == COMP_Blanking_TMR1OC4)    || \
                                       ((Blanking) == COMP_Blanking_TMR3OC3)    || \
                                       ((Blanking) == COMP_Blanking_TMR15OC2)   || \
                                       ((Blanking) == COMP_Blanking_TMR15OC1))
/**
  * @}
  */
#endif

/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/*  Function used to set the COMP configuration to the default reset state ****/
void COMP_Reset(void);

/* Initialization and Configuration functions *********************************/
void COMP_Init(uint32_t COMP_Selection, COMP_InitType* COMP_InitStruct);
void COMP_SelectINPInput(uint32_t COMP_Selection, uint32_t COMP_INPInput);
void COMP_StructInit(COMP_InitType* COMP_InitStruct);
void COMP_Cmd(uint32_t COMP_Selection, FunctionalState NewState);
void COMP_SwitchCmd(FunctionalState NewState);
uint32_t COMP_GetOutputState(uint32_t COMP_Selection);

#ifdef AT32F415
/* Window mode control function ***********************************************/
void COMP_WindowCmd(FunctionalState NewState);
#endif

/* COMP configuration locking function ****************************************/
void COMP_LockConfig(uint32_t COMP_Selection);

#ifdef AT32F421xx
/* COMP configuration glitch filter ****************************************/
void COMP_FilterConfig(uint16_t COMP_HighPulseCnt, uint16_t COMP_LowPulseCnt, FunctionalState NewState);

/* COMP configuration blanking source ****************************************/
void COMP_BlankingConfig(uint32_t Blank_Selection);

/* COMP configuration SCAL BRG ****************************************/
void COMP_SCAL_BRGConfig(uint32_t SCAL_BRG);
#endif

#ifdef __cplusplus
}
#endif

#endif /*__AT32F4XX_COMP_H */

/**
  * @}
  */ 

/**
  * @}
  */

