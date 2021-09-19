#include <string.h>
#include <stdio.h>
#include "main.h"
#include "HAL.h"

uint32_t sysTickTimer = 0;
uint32_t sysTimeSec = 0;

uint8_t sendFlag0 = 0;

void tskSched(void)
{
	static uint16_t tick = 0, msec = 0;

	sysTickTimer++;

	msec++;
	if(msec == 500)
	{
		LED_ON();
	}
	else if(msec == 900)
	{
		LED_OFF();
	}
	else if(msec >= 1000)
	{
		msec = 0;
		sysTimeSec++;
		sendFlag0 = 1;
	}
}

void can_msg_init(void)
{
	/* initialize transmit message */
	can_struct_para_init(CAN_TX_MESSAGE_STRUCT, &g_transmit_message);
	g_transmit_message.tx_sfid = 0x00;
	g_transmit_message.tx_efid = 0x00;
	g_transmit_message.tx_ft = CAN_FT_DATA;
	g_transmit_message.tx_ff = CAN_FF_EXTENDED;
	g_transmit_message.tx_dlen = 12;
	g_transmit_message.fd_flag = 1;
	g_transmit_message.fd_brs = 1;
	g_transmit_message.fd_esi = 0;

	/* initialize receive message */
	can_struct_para_init(CAN_RX_MESSAGE_STRUCT, &g_receive_message);
}


void can_transmit(void)
{
	uint32_t i;
	static uint8_t ch = 0;

	if(0 == sendFlag0)
	{
		return;
	}
	sendFlag0 = 0;

	if(0 == ch)
	{
		ch = 1;

		g_transmit_message.tx_efid = DEV_CAN1_ID;
		g_transmit_message.tx_data[0] = 0xaa;
		g_transmit_message.tx_data[1] = 0xbb;
		g_transmit_message.tx_data[2] = 0xcc;
		g_transmit_message.tx_data[3] = 0xdd;
		g_transmit_message.tx_data[4] = 0xee;
		g_transmit_message.tx_data[5] = 0xff;
		g_transmit_message.tx_data[6] = 0x00;
		g_transmit_message.tx_data[7] = 0x11;
		g_transmit_message.tx_data[8] = 0x22;
		g_transmit_message.tx_data[9] = 0x33;
		g_transmit_message.tx_data[10] = 0x44;
		g_transmit_message.tx_data[11] = 0x55;
		g_transmit_message.tx_dlen = 12;

		printf("can0 transmit %d bytes:", g_transmit_message.tx_dlen);
		for(i = 0; i < g_transmit_message.tx_dlen; i++)
		{
			printf("%02X ", g_transmit_message.tx_data[i]);
		}
		printf("\r\n");

		/* transmit message */
		can_message_transmit(CAN0, &g_transmit_message);
	}
	else if(1 == ch)
	{
		ch = 0;

		g_transmit_message.tx_efid = DEV_CAN0_ID;
		g_transmit_message.tx_data[0] = 0xaa;
		g_transmit_message.tx_data[1] = 0xbb;
		g_transmit_message.tx_data[2] = 0xcc;
		g_transmit_message.tx_data[3] = 0xdd;
		g_transmit_message.tx_data[4] = 0xee;
		g_transmit_message.tx_data[5] = 0xff;
		g_transmit_message.tx_data[6] = 0x00;
		g_transmit_message.tx_data[7] = 0x11;
		g_transmit_message.tx_data[8] = 0x22;
		g_transmit_message.tx_data[9] = 0x33;
		g_transmit_message.tx_data[10] = 0x44;
		g_transmit_message.tx_data[11] = 0x55;
		g_transmit_message.tx_data[12] = 0x11;
		g_transmit_message.tx_data[13] = 0x22;
		g_transmit_message.tx_data[14] = 0x33;
		g_transmit_message.tx_data[15] = 0x44;
		g_transmit_message.tx_dlen = 16;

		printf("can1 transmit %d bytes:", g_transmit_message.tx_dlen);
		for(i = 0; i < g_transmit_message.tx_dlen; i++)
		{
			printf("%02X ", g_transmit_message.tx_data[i]);
		}
		printf("\r\n");

		/* transmit message */
		can_message_transmit(CAN1, &g_transmit_message);
	}
}

void can_receive(void)
{
	uint32_t i;

	/* CAN0 receive data correctly, the received data is printed */
	if(SET == can0_receive_flag)
	{
		LED1_ON();
		can0_receive_flag = RESET;
		printf("can0 receive %d bytes:", g_receive_message.rx_dlen);
		for(i = 0; i < g_receive_message.rx_dlen; i++)
		{
			printf("%02X ", g_receive_message.rx_data[i]);
		}
		printf("\r\n");
		LED1_OFF();
	}

	/* CAN1 receive data correctly, the received data is printed */
	if(SET == can1_receive_flag)
	{
		LED2_ON();
		can1_receive_flag = RESET;
		printf("can1 receive %d bytes:", g_receive_message.rx_dlen);
		for(i = 0; i < g_receive_message.rx_dlen; i++)
		{
			printf("%02X ", g_receive_message.rx_data[i]);
		}
		printf("\r\n");
		LED2_OFF();
	}
}

int main(void)
{
	CLK_Config();
	GPIO_Config();
	USART_Config();
	NVIC_Config();
	TIM_Config();
	CAN_Config();
	WDG_Config();

	if (SysTick_Config(SystemCoreClock / 1000))
	{
		while(true);
	}

	can_msg_init();
	printf("FD communication test between CAN0 and CAN1\r\n");

	while(true)
	{
		can_transmit();
		can_receive();
		KickDog();
	}
}

//  delays number of tick Systicks (happens every 1 ms)
void Delay(uint32_t dlyTicks)
{
	uint32_t curTicks;

	curTicks = sysTickTimer;
	while ((sysTickTimer - curTicks) < dlyTicks)
	{
		__NOP();
	}
}

