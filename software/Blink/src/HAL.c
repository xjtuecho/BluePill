#include "HAL.h"

void RCU_Config(void)
{
	rcu_periph_clock_sleep_enable(RCU_FMC_SLP);
	rcu_periph_clock_sleep_enable(RCU_SRAM_SLP);

	rcu_periph_clock_enable(RCU_AF);
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOB);
	rcu_periph_clock_enable(RCU_GPIOC);
	rcu_periph_clock_enable(RCU_USART0);
}

void NVIC_Config(void)
{
	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
	nvic_irq_enable(USART0_IRQn, 3, 1);
}

void GPIO_Config(void)
{
	// PA9  = TXD USART0
	// PA10 = RXD USART0
	gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_10MHZ, GPIO_PIN_9);
	gpio_init(GPIOA, GPIO_MODE_IPU, GPIO_OSPEED_10MHZ, GPIO_PIN_10);

	// PC13 = LED2
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_13);

}
