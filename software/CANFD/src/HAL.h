#ifndef _HAL_H_
#define _HAL_H_

#include <stdint.h>
#include <stdbool.h>
#include "gd32e10x.h"

#define KickDog()			fwdgt_counter_reload()

#define SPI_CS_HIGH()	gpio_bit_set(GPIOA, GPIO_PIN_4)
#define SPI_CS_LOW()	gpio_bit_reset(GPIOA, GPIO_PIN_4)

#define KEY()			gpio_input_bit_get(GPIOA, GPIO_PIN_8)

#define LED_ON()		gpio_bit_reset(GPIOC, GPIO_PIN_13)
#define LED_OFF()		gpio_bit_set(GPIOC, GPIO_PIN_13)

#define LED1_ON()		gpio_bit_set(GPIOB, GPIO_PIN_5)
#define LED1_OFF()		gpio_bit_reset(GPIOB, GPIO_PIN_5)

#define LED2_ON()		gpio_bit_set(GPIOB, GPIO_PIN_11)
#define LED2_OFF()		gpio_bit_reset(GPIOB, GPIO_PIN_11)

#define LED3_ON()		gpio_bit_set(GPIOB, GPIO_PIN_0)
#define LED3_OFF()		gpio_bit_reset(GPIOB, GPIO_PIN_0)

#define LED4_ON()		gpio_bit_set(GPIOB, GPIO_PIN_1)
#define LED4_OFF()		gpio_bit_reset(GPIOB, GPIO_PIN_1)

extern void CLK_Config(void);
extern void NVIC_Config(void);
extern void GPIO_Config(void);
extern void WDG_Config(void);
extern void SPI_Config(void);
extern uint16_t SPI_SwapByte(uint8_t byte);
extern void USART_Config(void);
extern void USART_SendByte(uint16_t c);
extern void uart_putchar(uint8_t c);
extern void TIM_Config(void);
extern void CAN_Config(void);

#define DEV_CAN0_ID          0xaabb
#define DEV_CAN0_MASK        0x0000
#define DEV_CAN1_ID          0xccdd
#define DEV_CAN1_MASK        0x0000

extern can_trasnmit_message_struct g_transmit_message;
extern can_receive_message_struct g_receive_message;
extern FlagStatus can0_receive_flag;
extern FlagStatus can1_receive_flag;

#endif

