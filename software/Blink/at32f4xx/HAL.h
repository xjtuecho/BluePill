#ifndef _HAL_H_
#define _HAL_H_

#include "at32f4xx.h"

#define LED_ON()	GPIO_ResetBits(GPIOC, GPIO_Pins_13)
#define LED_OFF()	GPIO_SetBits(GPIOC, GPIO_Pins_13)

extern void RCU_Config(void);
extern void NVIC_Config(void);
extern void GPIO_Config(void);

#endif

