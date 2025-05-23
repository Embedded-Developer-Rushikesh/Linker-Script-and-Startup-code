/*
 * gpio_intrupt.c
 *
 *  Created on: Oct 5, 2024
 *      Author: DELL
 */

#include"stm32f446xx.h"
#include<stdio.h>
void delay(void)
 {
	for(uint32_t i = 0 ; i < 500000 ; i ++);
}
int main()
{
	//LED PA5
	GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	//GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GpioLed);


	//Button PC13
	GPIO_Handle_t GpioButton;
	GpioButton.pGPIOx = GPIOC;
	GpioButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PD;
	GPIO_Init(&GpioButton);


	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10,NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10,ENABLE);
	while(1){
		GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, DISABLE);
		delay();
	}
}
void EXTI15_10_IRQHandler(void)
{
   /// delay(); //200ms . wait till button de-bouncing gets over
	GPIO_IRQHandling(GPIO_PIN_NO_13); //clear the pending event from exti line
	GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, ENABLE);
	printf("Button is Pressed by user\n");
	delay();
}
