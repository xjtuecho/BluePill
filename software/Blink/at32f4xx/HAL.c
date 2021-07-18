#include "HAL.h"

void RCU_Config(void)
{
#if defined(AT32F421xx)
	RCC->AHBEN  |= RCC_AHBPERIPH_GPIOA | RCC_AHBPERIPH_GPIOC;
	RCC->APB2EN |= RCC_APB2PERIPH_USART1;
#else
	RCC->APB2EN |= (RCC_APB2PERIPH_GPIOA | RCC_APB2PERIPH_GPIOC | RCC_APB2PERIPH_USART1);
#endif
}

void NVIC_Config(void)
{
	NVIC_InitType NVIC_InitStructure;

	/* Configure the NVIC Preemption Priority Bits */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

	/* Enable the USART1 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void GPIO_Config(void)
{
	GPIO_InitType GPIO_InitStructure;

	// PA9  = TXD
	// PA10 = RXD
	// PC13 = LED2
#if defined(AT32F421xx)

	GPIO_InitStructure.GPIO_Pins = GPIO_Pins_9 | GPIO_Pins_10;
	GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OutType = GPIO_OutType_PP;
	GPIO_InitStructure.GPIO_Pull = GPIO_Pull_PU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_PinAFConfig(GPIOA, GPIO_PinsSource9,  GPIO_AF_1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinsSource10, GPIO_AF_1);

	GPIO_InitStructure.GPIO_Pins = GPIO_Pins_13;
	GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OutType = GPIO_OutType_PP;
	GPIO_InitStructure.GPIO_Pull = GPIO_Pull_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

#else

	GPIO_InitStructure.GPIO_Pins = GPIO_Pins_9 | GPIO_Pins_10;
	GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pins = GPIO_Pins_13;
	GPIO_InitStructure.GPIO_MaxSpeed = GPIO_MaxSpeed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

#endif
}
