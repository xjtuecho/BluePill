#include "HAL.h"
#include <ctype.h>
#include <stdio.h>


/* config CAN baud rate to 500K Hz (range from 1Hz to 1MHz)*/
#define DEV_CAN_BAUD_RATE    500000
#define DEV_CANFD_BAUD_RATE    2000000

can_trasnmit_message_struct g_transmit_message;
can_receive_message_struct g_receive_message;
FlagStatus can0_receive_flag;
FlagStatus can1_receive_flag;

void CLK_Config(void)
{
	rcu_periph_clock_sleep_enable(RCU_FMC_SLP);
	rcu_periph_clock_sleep_enable(RCU_SRAM_SLP);

	rcu_periph_clock_enable(RCU_AF);
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOB);
	rcu_periph_clock_enable(RCU_GPIOC);
	rcu_periph_clock_enable(RCU_SPI0);
	rcu_periph_clock_enable(RCU_PMU);
	rcu_periph_clock_enable(RCU_CAN0);
	rcu_periph_clock_enable(RCU_CAN1);
	rcu_periph_clock_enable(RCU_USART0);
	rcu_periph_clock_enable(RCU_TIMER0);
}

void NVIC_Config(void)
{
	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);

	nvic_irq_enable(USART0_IRQn, 3, 1);

	/* configure CAN0 NVIC */
	nvic_irq_enable(CAN0_RX0_IRQn, 0, 0);

	/* configure CAN1 NVIC */
	nvic_irq_enable(CAN1_RX0_IRQn, 1, 0);
}

void GPIO_Config(void)
{
	// PA4 = NCS
	gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_10MHZ, GPIO_PIN_4);

	// PA5 = SCK
	// PA6 = MISO
	// PA7 = MOSI
	gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_5);
	gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
	gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);

	// PA8  = KEY
	gpio_init(GPIOA, GPIO_MODE_IPU, GPIO_OSPEED_2MHZ, GPIO_PIN_8);

	// PA9  = TXD USART0
	// PA10 = RXD USART0
	gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_10MHZ, GPIO_PIN_9);
	gpio_init(GPIOA, GPIO_MODE_IPU, GPIO_OSPEED_10MHZ, GPIO_PIN_10);

	// PB0  = LED3
	// PB1  = LED4
	// PB5  = LED1
	// PB11 = LED2
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_0);
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_1);
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_5);
	gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_11);

	// PB8 = CAN0_RX
	// PB9 = CAN0_TX
	gpio_init(GPIOB, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
	gpio_init(GPIOB, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);
	gpio_pin_remap_config(GPIO_CAN0_PARTIAL_REMAP, ENABLE);

	// PB12 = CAN1_RX
	// PB13 = CAN1_TX
	gpio_init(GPIOB, GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, GPIO_PIN_12);
	gpio_init(GPIOB, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);

	// PC13 = LED3
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_13);
}

// 40e3/128 = 312.5Hz 1000/312.5=3.2s
void WDG_Config(void)
{
	fwdgt_write_enable();
	fwdgt_config(1000, FWDGT_PSC_DIV128);
	fwdgt_counter_reload();
	fwdgt_enable();
}

void USART_Config(void)
{
	usart_deinit(USART0);
	usart_baudrate_set(USART0, 115200);
	usart_parity_config(USART0, USART_PM_NONE);
	usart_word_length_set(USART0, USART_WL_8BIT);
	usart_stop_bit_set(USART0, USART_STB_1BIT);
	usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
	usart_receive_config(USART0, USART_RECEIVE_ENABLE);
	usart_interrupt_enable(USART0, USART_INT_RBNE);
	usart_enable(USART0);
}

void USART_SendByte(uint16_t c)
{
	while(0 == (USART_STAT0(USART0) & USART_STAT0_TBE));
	USART_DATA(USART0) = USART_DATA_DATA & c;
	while(0 == (USART_STAT0(USART0) & USART_STAT0_TC));
}

void uart_putchar(uint8_t c)
{
	USART_SendByte(c);
}

/* retarget the C library printf function to the usart */
int fputc(int ch, FILE *f)
{
	USART_SendByte(ch);
	return ch;
}

void SPI_Config(void)
{
	spi_parameter_struct SPI_InitStruct;

	// 全双工SPI
	SPI_InitStruct.device_mode = SPI_MASTER;
	SPI_InitStruct.trans_mode = SPI_TRANSMODE_FULLDUPLEX;
	SPI_InitStruct.frame_size = SPI_FRAMESIZE_8BIT;
	SPI_InitStruct.nss = SPI_NSS_SOFT;
	SPI_InitStruct.endian = SPI_ENDIAN_MSB;
	SPI_InitStruct.clock_polarity_phase = SPI_CK_PL_HIGH_PH_2EDGE;
	SPI_InitStruct.prescale = SPI_PSC_8;
	spi_init(SPI0, &SPI_InitStruct);

	spi_enable(SPI0);
}


void TIM_Config(void)
{
	timer_parameter_struct timer_initpara;

	timer_deinit(TIMER0);

	timer_initpara.prescaler = 72 - 1;		// 72M / 72 = 1M
	timer_initpara.alignedmode = TIMER_COUNTER_EDGE;
	timer_initpara.counterdirection = TIMER_COUNTER_UP;
	timer_initpara.period = 65535;
	timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
	timer_initpara.repetitioncounter = 0;
	timer_init(TIMER0, &timer_initpara);
	timer_enable(TIMER0);
}

void CAN_Config(void)
{
	can_parameter_struct can_parameter;
	can_fdframe_struct can_fd_parameter;
	can_fd_tdc_struct can_fd_tdc_parameter;

	can_struct_para_init(CAN_INIT_STRUCT, &can_parameter);
	/* initialize CAN register */
	can_deinit(CAN0);
	can_deinit(CAN1);

	/* initialize CAN parameters */
	can_parameter.time_triggered = DISABLE;
	can_parameter.auto_bus_off_recovery = DISABLE;
	can_parameter.auto_wake_up = DISABLE;
	can_parameter.auto_retrans = ENABLE;
	can_parameter.rec_fifo_overwrite = ENABLE;
	can_parameter.trans_fifo_order = ENABLE;
	can_parameter.working_mode = CAN_NORMAL_MODE;
	// 36e3/12/(4+1+1) = 500k
	can_parameter.resync_jump_width = CAN_BT_SJW_1TQ;
	can_parameter.time_segment_1 = CAN_BT_BS1_4TQ;
	can_parameter.time_segment_2 = CAN_BT_BS2_1TQ;
	can_parameter.prescaler = 12;
	/* initialize CAN */
	can_init(CAN0, &can_parameter);
	can_init(CAN1, &can_parameter);

	// 常规CAN的波特率计算函数，把BS1和BS2寄存器的位数都浪费掉了
//	can_frequency_set(CAN0, DEV_CAN_BAUD_RATE);
//	can_frequency_set(CAN1, DEV_CAN_BAUD_RATE);

	can_struct_para_init(CAN_FD_FRAME_STRUCT, &can_fd_parameter);
	can_fd_parameter.fd_frame = ENABLE;
	can_fd_parameter.excp_event_detect = ENABLE;
	can_fd_parameter.delay_compensation = ENABLE;
	can_fd_tdc_parameter.tdc_filter = 0x04;
	can_fd_tdc_parameter.tdc_mode = CAN_TDCMOD_CALC_AND_OFFSET;
	can_fd_tdc_parameter.tdc_offset = 0x04;
	can_fd_parameter.p_delay_compensation = &can_fd_tdc_parameter;
	can_fd_parameter.iso_bosch = CAN_FDMOD_ISO;
	can_fd_parameter.esi_mode = CAN_ESIMOD_HARDWARE;
	// 36e3/2/(1+6+2) = 2M
	can_fd_parameter.data_resync_jump_width = CAN_BT_SJW_1TQ;
	can_fd_parameter.data_time_segment_1 = CAN_BT_BS1_6TQ;
	can_fd_parameter.data_time_segment_2 = CAN_BT_BS2_2TQ;
	can_fd_parameter.data_prescaler = 2;
	can_fd_init(CAN0, &can_fd_parameter);
	can_fd_init(CAN1, &can_fd_parameter);

	// 计算FD的这个函数，问题不是很大，可以用，偶尔也会报错
//	can_fd_frequency_set(CAN0, DEV_CANFD_BAUD_RATE);
//	can_fd_frequency_set(CAN1, DEV_CANFD_BAUD_RATE);

	/* initialize filter */
	can1_filter_start_bank(14);
	can_filter_mask_mode_init(DEV_CAN0_ID, DEV_CAN0_MASK, CAN_EXTENDED_FIFO0, 0);
	can_filter_mask_mode_init(DEV_CAN1_ID, DEV_CAN1_MASK, CAN_EXTENDED_FIFO0, 15);

	/* enable can receive FIFO0 not empty interrupt */
	can_interrupt_enable(CAN0, CAN_INTEN_RFNEIE0);
	can_interrupt_enable(CAN1, CAN_INTEN_RFNEIE0);
}
