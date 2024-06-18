#include <stdio.h>
#include<stdint.h>
#include<stm32f411xe.h>
#include <uart.h>
#include <adc.h>
#include <systick.h>
#include <tim.h>
#define GPIOAEN			(1U<<0)

int main(void)
{
	RCC->AHB1ENR|=(1U<<0);
	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);
	uart2_txrx_init();
	tim2_1hz_interrupt_init();
	while(1)
	{



	}
}
static void tim_callback(void)
{
	write_string(11,"Loading....");
	GPIOA->ODR^=(1U<<5);
}

void TIM2_IRQHandler(void)
{
	/*Clear update interrupt flag*/
	TIM2->SR&=~SR_UIF;/*Clear flag for interrupt next time*/
	/*Do something*/
	tim_callback();
}
