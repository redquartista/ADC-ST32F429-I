/*
 * delay.h
 *
 *  Created on: 17 Apr 2019
 *      Author: Hrudaynath
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "stm32f4xx_it.h"




extern uint32_t SystemCoreClock;
volatile u32 timer = 0;
volatile u32 msTimer = 0;
volatile u32 msCount = 1000;



void SysTick_Handler(void)
{
/*  TimingDelay_Decrement(); */
//	Micros++;
//	Millis %= Micros;
	if(timer != 0)
	{
		timer--;
		if(--msCount == 0)
		{
			if(msTimer !=0)
			{
				msTimer--;
				msCount = 1000;
			}
		}
	}

	else;
}

void sysTickIntConfig()
{
	SystemCoreClockUpdate();
	if (SysTick_Config (SystemCoreClock / 1000000)) //1us per interrupt
	while (1);


//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);    //4 bits for preemp priority 0 bit for sub priority
//	NVIC_SetPriority(SysTick_IRQn, 0);//i want to make sure systick has highest priority amount all other interrupts
//
//	Micros = 0;
}

void delay_us(u32 us)
{
	timer = us;
	while(timer!=0 );

}

void delay_ms(u32 ms)
{
	timer = SystemCoreClock;
	msTimer = ms;
	while(msTimer !=0);
	timer = 0;
	//	u32 curTime = Millis;
//	while((nTime-(Millis-curTime)) > 0);
}




#endif /* DELAY_H_ */
