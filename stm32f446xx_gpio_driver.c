/*
 * GPIO.c
 *
 *  Created on: Oct 2, 2024
 *      Author: DELL
 */


#include"stm32f446xx_gpio_driver.h"

/*********************************************************************
 * @fn      		  - GPIO_Init
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none
*/

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	 uint32_t temp=0;
	 GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	//Pin Configuration
	switch (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode) {
	case GPIO_MODE_ANALOG: {
		pGPIOHandle->pGPIOx->MODER &= ~(0x3<< (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber))); // Clearing the position
		pGPIOHandle->pGPIOx->MODER |= (0x3<< (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
		break;
	}
	case GPIO_MODE_ALTFN: {
		pGPIOHandle->pGPIOx->MODER &= ~(0x3<< (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber))); // Clearing the position
		pGPIOHandle->pGPIOx->MODER |= (0x2<< (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
		break;
	}
	case GPIO_MODE_IN:
	{
		pGPIOHandle->pGPIOx->MODER &= ~(0x3<< (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber))); // Clearing the position
		pGPIOHandle->pGPIOx->MODER &= ~(0x1<< (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
		break;
	}
	case GPIO_MODE_OUT:
	{
		pGPIOHandle->pGPIOx->MODER &= ~(0x3<< (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber))); // Clearing the position
		pGPIOHandle->pGPIOx->MODER |= (0x1<< (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
		break;
	}
	case GPIO_MODE_IT_FT:
	{
		EXTI->FTSR|=(0x1<< ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
		EXTI->RTSR&=~(0x1<< ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));//Clearing Rising Intrupt line
		break;
	}
	case GPIO_MODE_IT_RT:
	{
		EXTI->RTSR|=(0x1<< ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
		EXTI->FTSR&=~(0x01<< ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));// Clearing the falling intrupt line
		break;
	}
	case GPIO_MODE_IT_RFT:
	{
		EXTI->RTSR|=(0x1<< ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
		EXTI->FTSR|=(0x1<< ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));// Clearing the falling intrupt line
	}
	default: {
		break;
	}

	}
	//2. configure the speed

	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
	(pGPIOHandle->pGPIOx->OSPEEDR) &= ~( 0x3 << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	//Pull Push Configuration
	temp=0;
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl<<(2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
	pGPIOHandle->pGPIOx->PUPDR|= ~(0x3<< (2 * (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
	pGPIOHandle->pGPIOx->PUPDR|=temp;

//	//Port output type
//	temp=0;
//	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType<<((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
//	pGPIOHandle->pGPIOx->OTYPER|= ~(0x1<< ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
//	pGPIOHandle->pGPIOx->OTYPER|=temp;
//
	//Alternative Functionality Mode
//	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode==GPIO_MODE_ALTFN)
//	{
		pGPIOHandle->pGPIOx->AFR[pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8]&=~(0xF<<(4*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber %8)));
		pGPIOHandle->pGPIOx->AFR[pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8]|=(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode)<<(4*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber %8));
//	}
	//2. configure the GPIO port selection in SYSCFG_EXTICR
	uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4 ;
	uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
	uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
	SYSCFG_PCLK_EN();
	SYSCFG->EXTICR[temp1] = portcode << ( temp2 * 4);

	//3 . enable the exti interrupt delivery using IMR
	EXTI->IMR |= 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
}
/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if (pGPIOx == GPIOA) {
			GPIOA_PCLK_EN();
		} else if (pGPIOx == GPIOB) {
			GPIOB_PCLK_EN();
		} else if (pGPIOx == GPIOC) {
			GPIOC_PCLK_EN();
		} else if (pGPIOx == GPIOD) {
			GPIOD_PCLK_EN();
		} else if (pGPIOx == GPIOE) {
			GPIOE_PCLK_EN();
		} else if (pGPIOx == GPIOF) {
			GPIOF_PCLK_EN();
		} else if (pGPIOx == GPIOG) {
			GPIOG_PCLK_EN();
		} else if (pGPIOx == GPIOH) {
			GPIOH_PCLK_EN();
		} else if (pGPIOx == GPIOI) {
			GPIOI_PCLK_EN();
		}
	}
	else
	{
		if (pGPIOx == GPIOA) {
			GPIOA_PCLK_DI();
		} else if (pGPIOx == GPIOB) {
			GPIOB_PCLK_DI();
		} else if (pGPIOx == GPIOC) {
			GPIOC_PCLK_DI();
		} else if (pGPIOx == GPIOD) {
			GPIOD_PCLK_DI();
		} else if (pGPIOx == GPIOE) {
			GPIOE_PCLK_DI();
		} else if (pGPIOx == GPIOF) {
			GPIOF_PCLK_DI();
		} else if (pGPIOx == GPIOG) {
			GPIOG_PCLK_DI();
		} else if (pGPIOx == GPIOH) {
			GPIOH_PCLK_DI();
		} else if (pGPIOx == GPIOI) {
			GPIOI_PCLK_DI();
		}
	}

}

/*********************************************************************
 * @fn      		  - GPIO_DeInit
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}else if (pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}else if (pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}else if (pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}else if (pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}else if (pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}else if (pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}else if (pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}else if (pGPIOx == GPIOI)
	{
		GPIOI_REG_RESET();
	}

}

/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t data=(uint8_t)(((pGPIOx->IDR)>>PinNumber)&0x01);
	return data;
}
/*********************************************************************
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t data=(uint16_t)(pGPIOx->IDR);
	return data;
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value==ENABLE)
	{
		 pGPIOx->ODR|=(1<<PinNumber);
	}else
	{
		 pGPIOx->ODR&=~(1<<PinNumber);
	}



}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR|=Value;
}
/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR^=(1<<PinNumber);
}
/*********************************************************************
 * @fn      		  - GPIO_IRQConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

	if(EnorDi == ENABLE)
	{
		if(IRQNumber <= 31)
		{
			//program ISER0 register
			*NVIC_ISER0 |= ( 1 << IRQNumber );

		}else if(IRQNumber > 31 && IRQNumber < 64 ) //32 to 63
		{
			//program ISER1 register
			*NVIC_ISER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ISER2 register //64 to 95
			*NVIC_ISER2 |= ( 1 << (IRQNumber % 64) );
		}
	}else
	{
		if(IRQNumber <= 31)
		{
			//program ICER0 register
			*NVIC_ICER0 |= ( 1 << IRQNumber );
		}else if(IRQNumber > 31 && IRQNumber < 64 )
		{
			//program ICER1 register
			*NVIC_ICER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ICER2 register
			*NVIC_ICER2 |= ( 1 << (IRQNumber % 64) );
		}
	}

}
/*********************************************************************
 * @fn      		  - GPIO_IRQPriorityConfig
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint32_t IRQPriority)
{
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section  = IRQNumber %4 ;

	uint8_t shift_amount = ( 8 * iprx_section) + ( 8 - NO_PR_BITS_IMPLEMENTED) ;

	*(  NVIC_PR_BASE_ADDR + iprx ) |=  ( IRQPriority << shift_amount );
}
/*********************************************************************
 * @fn      		  - GPIO_IRQHandling
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void GPIO_IRQHandling(uint8_t PinNumber)
{
	//clear the EXTI pr register corresponding to the pin number
	if(EXTI->PR & ( 1 << PinNumber))
	{
		//clear
		EXTI->PR |= ( 1 << PinNumber);
	}

}
