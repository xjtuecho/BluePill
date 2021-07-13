/**
  **************************************************************************
  * File   : at32f4xx_gpio_ex.c
  * Version: V1.3.0
  * Date   : 2021-03-18
  * Brief  : at32f4xx GPIO extended source file
  **************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "at32f4xx_gpio_ex.h"
#include "at32f4xx_rcc.h"

/** @addtogroup at32f4xx_StdPeriph_Driver
  * @{
  */

/** @defgroup GPIO
  * @brief GPIO driver modules
  * @{
  */

#if defined (AT32F421xx)

/** @defgroup GPIO_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Private_Defines
  * @{
  */

/* ------------ RCC registers bit address in the alias region ----------------*/
#define AFIO_OFFSET                 (AFIO_BASE - PERIPH_BASE)

/* --- EVENTCR Register -----*/

/* Alias word address of EVOE bit */
#define EVCR_OFFSET                 (AFIO_OFFSET + 0x00)
#define EVOE_BitNumber              ((uint8_t)0x07)
#define EVCR_EVOE_BB                (PERIPH_BB_BASE + (EVCR_OFFSET * 32) + (EVOE_BitNumber * 4))


/* ---  MAPR Register ---*/
/* Alias word address of MII_RMII_SEL bit */
#define MAP_OFFSET                 (AFIO_OFFSET + 0x04)
#define MII_RMII_SEL_BitNumber      ((u8)0x17)
#define MAPR_MII_RMII_SEL_BB        (PERIPH_BB_BASE + (MAP_OFFSET * 32) + (MII_RMII_SEL_BitNumber * 4))


#define EVCR_PORTPINCONFIG_MASK     ((uint16_t)0xFF80)
#define LSB_MASK                    ((uint16_t)0xFFFF)
#define DBGAFR_POSITION_MASK        ((uint32_t)0x000F0000)
#define DBGAFR_SWJCONF_MASK          ((uint32_t)0xF0FFFFFF)
#define DBGAFR_LOCATION_MASK        ((uint32_t)0x00200000)
#define DBGAFR_NUMBITS_MASK         ((uint32_t)0x00100000)
/**
  * @}
  */

/** @defgroup GPIO_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Private_Functions
  * @{
  */

/**
  * @brief  Deinitializes the GPIOx peripheral registers to their default reset values.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_Reset(GPIO_Type* GPIOx)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  if (GPIOx == GPIOA)
  {
    RCC_AHBPeriphResetCmd(RCC_AHBPERIPH_GPIOA, ENABLE);
    RCC_AHBPeriphResetCmd(RCC_AHBPERIPH_GPIOA, DISABLE);
  }
  else if (GPIOx == GPIOB)
  {
    RCC_AHBPeriphResetCmd(RCC_AHBPERIPH_GPIOB, ENABLE);
    RCC_AHBPeriphResetCmd(RCC_AHBPERIPH_GPIOB, DISABLE);
  }
  else if (GPIOx == GPIOC)
  {
    RCC_AHBPeriphResetCmd(RCC_AHBPERIPH_GPIOC, ENABLE);
    RCC_AHBPeriphResetCmd(RCC_AHBPERIPH_GPIOC, DISABLE);
  }
  else if (GPIOx == GPIOF)
  {
    RCC_AHBPeriphResetCmd(RCC_AHBPERIPH_GPIOF, ENABLE);
    RCC_AHBPeriphResetCmd(RCC_AHBPERIPH_GPIOF, DISABLE);
  }
}

/**
  * @brief  Initializes the GPIOx peripheral according to the specified
  *         parameters in the GPIO_InitStruct.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_InitStruct: pointer to a GPIO_InitType structure that
  *         contains the configuration information for the specified GPIO peripheral.
  * @retval None
  */
void GPIO_Init(GPIO_Type* GPIOx, GPIO_InitType* GPIO_InitStruct)
{
  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_MDE(GPIO_InitStruct->GPIO_Mode));
  assert_param(IS_GPIO_PINS(GPIO_InitStruct->GPIO_Pins));
  assert_param(IS_GPIO_PUPD(GPIO_InitStruct->GPIO_Pull));
  assert_param(IS_GPIO_OTYPE(GPIO_InitStruct->GPIO_OutType));
  assert_param(IS_GPIO_MAXSPEED(GPIO_InitStruct->GPIO_MaxSpeed));
	
  if(!IS_GPIO_MDE(GPIO_InitStruct->GPIO_Mode))
  {
    GPIO_InitStruct->GPIO_Mode = GPIO_Mode_IN;
  }
  if(!IS_GPIO_PUPD(GPIO_InitStruct->GPIO_Pull))
  {
    GPIO_InitStruct->GPIO_Pull = GPIO_Pull_NOPULL;
  }
  if(!IS_GPIO_OTYPE(GPIO_InitStruct->GPIO_OutType))
  {
    GPIO_InitStruct->GPIO_OutType = GPIO_OutType_PP;
  }
  if(!IS_GPIO_MAXSPEED(GPIO_InitStruct->GPIO_MaxSpeed))
  {
    GPIO_InitStruct->GPIO_MaxSpeed = GPIO_MaxSpeed_2MHz;
  }

  /*-------------------------- Configure the port pins -----------------------*/
  /*-- GPIO Mode Configuration --*/
  for (pinpos = 0x00; pinpos < 0x10; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;

    /* Get the port pins position */
    currentpin = (GPIO_InitStruct->GPIO_Pins) & pos;

    if (currentpin == pos)
    {
      if ((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF))
      {
        /* Check Speed mode parameters */
        assert_param(IS_GPIO_MAXSPEED(GPIO_InitStruct->GPIO_MaxSpeed));

        /* Speed mode configuration */
        GPIOx->ODRVR &= ~(GPIO_ODRVR_ODRV0 << (pinpos * 2));
        GPIOx->ODRVR |= ((uint32_t)(GPIO_InitStruct->GPIO_MaxSpeed) << (pinpos * 2));

        /* Output mode configuration */
        GPIOx->OTYPER &= ~((GPIO_OTYPER_OT_0) << ((uint16_t)pinpos));
        GPIOx->OTYPER |= (uint16_t)(((uint16_t)GPIO_InitStruct->GPIO_OutType) << ((uint16_t)pinpos));
      }

      GPIOx->MODER  &= ~(GPIO_MODER_MODER0 << (pinpos * 2));

      GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << (pinpos * 2));

      /* Pull-up Pull down resistor configuration */
      GPIOx->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)pinpos * 2));
      GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->GPIO_Pull) << (pinpos * 2));
    }
  }
}

/**
  * @brief  Fills each GPIO_InitStruct member with its default value.
  * @param  GPIO_InitStruct : pointer to a GPIO_InitType structure which will
  *         be initialized.
  * @retval None
  */
void GPIO_StructInit(GPIO_InitType* GPIO_InitStruct)
{
  GPIO_InitStruct->GPIO_Pins  = GPIO_Pins_All;
  GPIO_InitStruct->GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStruct->GPIO_MaxSpeed = GPIO_MaxSpeed_2MHz;
  GPIO_InitStruct->GPIO_OutType = GPIO_OutType_PP;
  GPIO_InitStruct->GPIO_Pull = GPIO_Pull_NOPULL;
}

/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */
uint8_t GPIO_ReadInputDataBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
  uint8_t bitstatus = 0x00;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PINS(GPIO_Pin));

  if ((GPIOx->IPTDT & GPIO_Pin) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint8_t)Bit_RESET;
  }

  return bitstatus;
}

/**
  * @brief  Reads the specified GPIO input data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO input data port value.
  */
uint16_t GPIO_ReadInputData(GPIO_Type* GPIOx)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  return ((uint16_t)GPIOx->IPTDT);
}

/**
  * @brief  Reads the specified output data port bit.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The output port pin value.
  */
uint8_t GPIO_ReadOutputDataBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
  uint8_t bitstatus = 0x00;
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PINS(GPIO_Pin));

  if ((GPIOx->OPTDT & GPIO_Pin) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint8_t)Bit_RESET;
  }

  return bitstatus;
}

/**
  * @brief  Reads the specified GPIO output data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO output data port value.
  */
uint16_t GPIO_ReadOutputData(GPIO_Type* GPIOx)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  return ((uint16_t)GPIOx->OPTDT);
}

/**
  * @brief  Sets the selected data port bits.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_SetBits(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PINS(GPIO_Pin));

  GPIOx->BSRE = GPIO_Pin;
}

/**
  * @brief  Clears the selected data port bits.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_ResetBits(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PINS(GPIO_Pin));

  GPIOx->BRE = GPIO_Pin;
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *   This parameter can be one of the BitState enum values:
  *     @arg Bit_RESET: to clear the port pin
  *     @arg Bit_SET: to set the port pin
  * @retval None
  */
void GPIO_WriteBit(GPIO_Type* GPIOx, uint16_t GPIO_Pin, BitState BitVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PINS(GPIO_Pin));
  assert_param(IS_GPIO_BIT_STATE(BitVal));

  if (BitVal != Bit_RESET)
  {
    GPIOx->BSRE = GPIO_Pin;
  }
  else
  {
    GPIOx->BRE = GPIO_Pin;
  }
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */
void GPIO_Write(GPIO_Type* GPIOx, uint16_t PortVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  GPIOx->OPTDT = PortVal;
}

/**
  * @brief  Locks GPIO Pins configuration registers.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_PinsLockConfig(GPIO_Type* GPIOx, uint16_t GPIO_Pin)
{
  uint32_t tmp = 0x00010000;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PINS(GPIO_Pin));

  tmp |= GPIO_Pin;
  /* Set LCKK bit */
  GPIOx->LOCK = tmp;
  /* Reset LCKK bit */
  GPIOx->LOCK =  GPIO_Pin;
  /* Set LCKK bit */
  GPIOx->LOCK = tmp;
  /* Read LCKK bit*/
  tmp = GPIOx->LOCK;
  /* Read LCKK bit*/
  tmp = GPIOx->LOCK;
}

/**
  * @brief  Enables or disables to enhance slew rate of GPIO Pins.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @param  NewState: new state of the slew rate.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void GPIO_PinsEnhanceSlewRate(GPIO_Type* GPIOx, uint16_t GPIO_Pin, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PINS(GPIO_Pin));
  if( ENABLE == NewState ){
      GPIOx->SRCTR |= GPIO_Pin;
  }else{
      GPIOx->SRCTR &= ~GPIO_Pin;
  }
}

/**
  * @brief  Enables or disables GPIO Pins huge driven.
  * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @param  NewState: new state of the slew rate.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void GPIO_PinsHugeDriven(GPIO_Type* GPIOx, uint16_t GPIO_Pin, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PINS(GPIO_Pin));
  if( ENABLE == NewState ){
      GPIOx->HDRV |= GPIO_Pin;
  }else{
      GPIOx->HDRV &= ~GPIO_Pin;
  }
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A or B) to select the GPIO peripheral.
  * @param  GPIO_PinSource: specifies the pin for the Alternate function.
  *          This parameter can be GPIO_PinSourcex where x can be (0..15).
  * @param  GPIO_AF: selects the pin to used as Alternate function.
  *          This parameter can be one of the following value:
  *            @arg GPIO_AF_0: EVENTOUT, TIM15, SPI1, TIM17, MCO, SWDAT, SWCLK, TIM14,
  *                            USART1, IR_OUT, SPI2 
  *            @arg GPIO_AF_1: USART2, TMR3, USART1, USART2, EVENTOUT, I2C1, I2C2, TMR15, IR_OUT 
  *            @arg GPIO_AF_2: TMR2, TMR1, EVENTOUT, TMR16, TMR17
  *            @arg GPIO_AF_3: USART2, I2C1, TMR15, EVENTOUT 
  *            @arg GPIO_AF_4: I2C2, TMR14, USART2, I2C1
  *            @arg GPIO_AF_5: TMR1, TMR15, TMR16, TMR17, I2C2, MCO
  *            @arg GPIO_AF_6: EVENTOUT, SPI2
  *            @arg GPIO_AF_7: COMP1 OUT, COMP2 OUT, I2C2, SPI2
  * @note   The pin should already been configured in Alternate Function mode(AF)
  *         using GPIO_InitStruct->GPIO_Mode = GPIO_Mode_AF
  * @note   Refer to the Alternate function mapping table in the device datasheet 
  *         for the detailed mapping of the system and peripherals'alternate 
  *         function I/O pins.
  * @retval None
  */
void GPIO_PinAFConfig(GPIO_Type* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF)
{
  uint32_t temp = 0x00;
  uint32_t temp_2 = 0x00;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PINS_SOURCE(GPIO_PinSource));
  assert_param(IS_GPIO_AF(GPIO_AF));

  temp = ((uint32_t)(GPIO_AF) << ((uint32_t)((uint32_t)GPIO_PinSource & (uint32_t)0x07) * 4));
  GPIOx->AFR[GPIO_PinSource >> 0x03] &= ~((uint32_t)0xF << ((uint32_t)((uint32_t)GPIO_PinSource & (uint32_t)0x07) * 4));
  temp_2 = GPIOx->AFR[GPIO_PinSource >> 0x03] | temp;
  GPIOx->AFR[GPIO_PinSource >> 0x03] = temp_2;
}

#if defined (AT32F421PF4P7) || defined (AT32F421PF8P7)
/**
  * @brief  Unused GPIO pin Init.
  * @note   The pin should been configured in analog mode(AN), This function just
  *         only be called by AT32F421PFxP7 packages.
  * @retval None
  */
void GPIO_F421PFxP7_LowPower(void)
{
  GPIO_InitType GPIO_InitStructure;
  RCC_AHBPeriphClockCmd(RCC_AHBPERIPH_GPIOA | RCC_AHBPERIPH_GPIOB | RCC_AHBPERIPH_GPIOC | \
                        RCC_AHBPERIPH_GPIOF, ENABLE);

  GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructure.GPIO_Pull = GPIO_Pull_NOPULL;

  GPIO_InitStructure.GPIO_Pins = GPIO_Pins_11 | GPIO_Pins_12;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pins = GPIO_Pins_0 | GPIO_Pins_2 | GPIO_Pins_3 | GPIO_Pins_4 | GPIO_Pins_5 | \
                                 GPIO_Pins_6 | GPIO_Pins_7 | GPIO_Pins_8 | GPIO_Pins_9 | GPIO_Pins_10| \
                                 GPIO_Pins_11| GPIO_Pins_12| GPIO_Pins_13| GPIO_Pins_15;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pins = GPIO_Pins_13| GPIO_Pins_14| GPIO_Pins_15;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pins = GPIO_Pins_0 | GPIO_Pins_1 | GPIO_Pins_6 | GPIO_Pins_7;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
}
#endif /* AT32F421PF4P7 || AT32F421PF8P7 */

/**
  * @}
  */

#endif /* AT32F421xx */

/**
  * @}
  */

/**
  * @}
  */


