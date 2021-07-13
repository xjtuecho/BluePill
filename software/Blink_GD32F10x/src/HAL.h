#ifndef _HAL_H_
#define _HAL_H_

#include "gd32f10x.h"

#define LED_ON()	gpio_bit_reset(GPIOC, GPIO_PIN_13)
#define LED_OFF()	gpio_bit_set(GPIOC, GPIO_PIN_13)

extern void RCU_Config(void);
extern void NVIC_Config(void);
extern void GPIO_Config(void);

#endif

