/*
 * stm32f446xx_systeck_driver.c
 *
 *  Created on: Oct 13, 2024
 *      Author: DELL
 */

#include"stm32f446xx_SysTick_driver.h"
void systickDelayMs(int delay)
{
	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD	= SYSTICK_LOAD_VAL;

	/*Clear systick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;
	for(int i=0; i<delay ; i++){

		/*Wait until the COUNTFLAG is set*/
		while((SysTick->CTRL &  CTRL_COUNTFLAG) == 0){}
	}
	SysTick->CTRL = 0;
}

void systick_1hz_interrupt(void)
{
	/*Reload with number of clocks persecond*/
	SysTick->LOAD  = ONE_SEC_LOAD - 1;
	/*Clear systick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC ;

	/*Enable systick interrupt*/
	SysTick->CTRL  |= CTRL_TICKINT;
}


