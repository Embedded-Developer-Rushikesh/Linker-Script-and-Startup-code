#include<stdint.h>

#define SRAM_START 0x20000000
#define SRAM_SIZE (128*1024)

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _sidata;
extern uint32_t _estack;
extern int main(void);
void Reset_Handler();
void NMI_handler() __attribute__((weak,alias("Default_handler")));
void Hardfault_handler() __attribute__((weak,alias("Default_handler")));
void MemManage_Handler() __attribute__((weak,alias("Default_handler")));
void BusFault_Handler() __attribute__((weak,alias("Default_handler")));
void UsageFault_Handler() __attribute__((weak,alias("Default_handler")));
void SVC_Handler() __attribute__((weak,alias("Default_handler")));
void DebugMon_Handler() __attribute__((alias("Default_handler")));
void PendSV_Handler() __attribute__((weak,alias("Default_handler")));
void SysTick_Handler() __attribute__((weak,alias("Default_handler")));
void WWDG_IRQHandler() __attribute__((weak,alias("Default_handler")));             			/* Window Watchdog interrupt                                          */
void PVD_IRQHandler() __attribute__((alias("Default_handler")));               			/* PVD through EXTI line detection interrupt                          */
void TAMP_STAMP_IRQHandler() __attribute__((alias("Default_handler")));        			/* Tamper and TimeStamp interrupts through the EXTI line              */
void RTC_WKUP_IRQHandler() __attribute__((alias("Default_handler")));          			/* RTC Wakeup interrupt through the EXTI line                         */
void FLASH_IRQHandler() __attribute__((alias("Default_handler")));             			/* Flash global interrupt                                             */
void RCC_IRQHandler() __attribute__((alias("Default_handler")));               			/* RCC global interrupt                                               */
void EXTI0_IRQHandler() __attribute__((alias("Default_handler")));             			/* EXTI Line0 interrupt                                               */
void EXTI1_IRQHandler() __attribute__((alias("Default_handler")));             			/* EXTI Line1 interrupt                                               */
void EXTI2_IRQHandler() __attribute__((alias("Default_handler")));             			/* EXTI Line2 interrupt                                               */
void EXTI3_IRQHandler() __attribute__((alias("Default_handler")));             			/* EXTI Line3 interrupt                                               */
void EXTI4_IRQHandler() __attribute__((alias("Default_handler")));             			/* EXTI Line4 interrupt                                               */
void DMA1_Stream0_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA1 Stream0 global interrupt                                      */
void DMA1_Stream1_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA1 Stream1 global interrupt                                      */
void DMA1_Stream2_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA1 Stream2 global interrupt                                      */
void DMA1_Stream3_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA1 Stream3 global interrupt                                      */
void DMA1_Stream4_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA1 Stream4 global interrupt                                      */
void DMA1_Stream5_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA1 Stream5 global interrupt                                      */
void DMA1_Stream6_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA1 Stream6 global interrupt                                      */
void ADC_IRQHandler() __attribute__((alias("Default_handler")));               			/* ADC1 global interrupt                                              */
void CAN1_TX_IRQHandler() __attribute__((alias("Default_handler")));          			/* CAN1 TX interrupts                                                 */
void CAN1_RX0_IRQHandler() __attribute__((alias("Default_handler")));          			/* CAN1 RX0 interrupts                                                */
void CAN1_RX1_IRQHandler() __attribute__((alias("Default_handler")));          			/* CAN1 RX1 interrupts                                                */
void CAN1_SCE_IRQHandler() __attribute__((alias("Default_handler")));          			/* CAN1 SCE interrupt                                                 */
void EXTI9_5_IRQHandler() __attribute__((alias("Default_handler")));          			/* EXTI Line[9:5] interrupts                                          */
void TIM1_BRK_TIM9_IRQHandler() __attribute__((alias("Default_handler")));    			/* TIM1 Break interrupt and TIM9 global interrupt                     */
void TIM1_UP_TIM10_IRQHandler() __attribute__((alias("Default_handler")));     			/* TIM1 Update interrupt and TIM10 global interrupt                   */
void TIM1_TRG_COM_TIM11_IRQHandler() __attribute__((alias("Default_handler")));			/* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
void TIM1_CC_IRQHandler() __attribute__((alias("Default_handler")));           			/* TIM1 Capture Compare interrupt                                     */
void TIM2_IRQHandler() __attribute__((alias("Default_handler")));             			/* TIM2 global interrupt                                              */
void TIM3_IRQHandler() __attribute__((alias("Default_handler")));              			/* TIM3 global interrupt                                              */
void TIM4_IRQHandler() __attribute__((alias("Default_handler")));              			/* TIM4 global interrupt                                              */
void I2C1_EV_IRQHandler() __attribute__((alias("Default_handler")));           			/* I2C1 event interrupt                                               */
void I2C1_ER_IRQHandler() __attribute__((alias("Default_handler")));           			/* I2C1 error interrupt                                               */
void I2C2_EV_IRQHandler() __attribute__((alias("Default_handler")));           			/* I2C2 event interrupt                                               */
void I2C2_ER_IRQHandler() __attribute__((alias("Default_handler")));           			/* I2C2 error interrupt                                               */
void SPI1_IRQHandler() __attribute__((alias("Default_handler")));              			/* SPI1 global interrupt                                              */
void SPI2_IRQHandler() __attribute__((alias("Default_handler")));             			/* SPI2 global interrupt                                              */
void USART1_IRQHandler() __attribute__((alias("Default_handler")));            			/* USART1 global interrupt                                            */
void USART2_IRQHandler() __attribute__((alias("Default_handler")));            			/* USART2 global interrupt                                            */
void USART3_IRQHandler() __attribute__((alias("Default_handler")));            			/* USART3 global interrupt                                            */
void EXTI15_10_IRQHandler() __attribute__((weak,alias("Default_handler")));         			/* EXTI Line[15:10] interrupts                                        */
void RTC_Alarm_IRQHandler() __attribute__((alias("Default_handler")));         			/* RTC Alarms (A and B) through EXTI line interrupt                   */
void OTG_FS_WKUP_IRQHandler() __attribute__((alias("Default_handler")));       			/* USB On-The-Go FS Wakeup through EXTI line interrupt                */
void TIM8_BRK_TIM12_IRQHandler() __attribute__((alias("Default_handler")));    			/* TIM8 Break interrupt and TIM12 global interrupt                    */
void TIM8_UP_TIM13_IRQHandler() __attribute__((alias("Default_handler")));     			/* TIM8 Update interrupt and TIM13 global interrupt                   */
void TIM8_TRG_COM_TIM14_IRQHandler() __attribute__((alias("Default_handler")));			/* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt */
void TIM8_CC_IRQHandler() __attribute__((alias("Default_handler")));           			/* TIM8 Capture Compare interrupt                                     */
void DMA1_Stream7_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA1 Stream7 global interrupt                                      */
void FMC_IRQHandler() __attribute__((alias("Default_handler")));               			/* FMC global interrupt                                               */
void SDIO_IRQHandler() __attribute__((alias("Default_handler")));              			/* SDIO global interrupt                                              */
void TIM5_IRQHandler() __attribute__((alias("Default_handler")));              			/* TIM5 global interrupt                                              */
void SPI3_IRQHandler() __attribute__((alias("Default_handler")));              			/* SPI3 global interrupt                                              */
void UART4_IRQHandler() __attribute__((alias("Default_handler")));             			/* UART4 global interrupt                                             */
void UART5_IRQHandler() __attribute__((alias("Default_handler")));             			/* UART5 global interrupt                                             */
void TIM6_DAC_IRQHandler() __attribute__((alias("Default_handler")));          			/* TIM6 global interrupt, DAC1 and DAC2 underrun error interrupt      */
void TIM7_IRQHandler() __attribute__((alias("Default_handler")));              			/* TIM7 global interrupt                                              */
void DMA2_Stream0_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA2 Stream0 global interrupt                                      */
void DMA2_Stream1_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA2 Stream1 global interrupt                                      */
void DMA2_Stream2_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA2 Stream2 global interrupt                                      */
void DMA2_Stream3_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA2 Stream3 global interrupt                                      */
void DMA2_Stream4_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA2 Stream4 global interrupt                                      */                                                          
void CAN2_TX_IRQHandler() __attribute__((alias("Default_handler")));          			/* CAN2 TX interrupts                                                 */
void CAN2_RX0_IRQHandler() __attribute__((alias("Default_handler")));          			/* CAN2 RX0 interrupts                                                */
void CAN2_RX1_IRQHandler() __attribute__((alias("Default_handler")));          			/* CAN2 RX1 interrupts                                                */
void CAN2_SCE_IRQHandler() __attribute__((alias("Default_handler")));          			/* CAN2 SCE interrupt                                                 */
void OTG_FS_IRQHandler() __attribute__((alias("Default_handler")));            			/* USB On The Go FS global interrupt                                  */
void DMA2_Stream5_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA2 Stream5 global interrupt                                      */
void DMA2_Stream6_IRQHandler() __attribute__((alias("Default_handler")));      			/* DMA2 Stream6 global interrupt                                      */
void DMA2_Stream7_IRQHandler() __attribute__((alias("Default_handler")));     			/* DMA2 Stream7 global interrupt                                      */
void USART6_IRQHandler() __attribute__((alias("Default_handler")));           			/* USART6 global interrupt                                            */
void I2C3_EV_IRQHandler() __attribute__((alias("Default_handler")));           			/* I2C3 event interrupt                                               */
void I2C3_ER_IRQHandler() __attribute__((alias("Default_handler")));          			/* I2C3 error interrupt                                               */
void OTG_HS_EP1_OUT_IRQHandler() __attribute__((alias("Default_handler")));    			/* USB On The Go HS End Point 1 Out                                   */
void OTG_HS_EP1_IN_IRQHandler() __attribute__((alias("Default_handler")));     			/* USB On The Go HS End Point 1 In                                    */
void OTG_HS_WKUP_IRQHandler() __attribute__((alias("Default_handler")));       			/* USB On The Go HS Wakeup                                            */
void OTG_HS_IRQHandler() __attribute__((alias("Default_handler")));           			/* USB On The Go HS global interrupt                                  */
void DCMI_IRQHandler() __attribute__((alias("Default_handler")));              			/* DCMI global interrupt                                              */                                                         
void SPI4_IRQHandler() __attribute__((alias("Default_handler")));              			/* SPI 4 global interrupt                                             */                                                         
void SAI1_IRQHandler() __attribute__((alias("Default_handler")));              			/* SAI1 global interrupt                                              */
void SAI2_IRQHandler() __attribute__((alias("Default_handler")));              			/* SAI2 global interrupt                                              */
void QuadSPI_IRQHandler() __attribute__((alias("Default_handler")));           			/* QuadSPI global interrupt                                           */
void HDMI_CEC_IRQHandler() __attribute__((alias("Default_handler")));          			/* HDMI-CEC global interrupt                                          */
void SPDIF_Rx_IRQHandler() __attribute__((alias("Default_handler")));          			/* SPDIF-Rx global interrupt                                          */
void FMPI2C1_IRQHandler() __attribute__((alias("Default_handler")));           			/* FMPI2C1 event interrupt */
uint32_t vectors[] __attribute__((section(".isr_vector")))={
	(uint32_t) &_estack,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_handler,
	(uint32_t)&Hardfault_handler,
	(uint32_t)&	MemManage_Handler,
	(uint32_t)&BusFault_Handler,
	(uint32_t)&UsageFault_Handler,
		0,
		0,
		0,
		0,
	(uint32_t)&SVC_Handler,
	(uint32_t)&DebugMon_Handler,
		0,
	(uint32_t)&PendSV_Handler,
	(uint32_t)&SysTick_Handler,
	(uint32_t)&	WWDG_IRQHandler,             			/* Window Watchdog interrupt                                          */
	(uint32_t)&PVD_IRQHandler,               			/* PVD through EXTI line detection interrupt                          */
	(uint32_t)&TAMP_STAMP_IRQHandler,        			/* Tamper and TimeStamp interrupts through the EXTI line              */
	(uint32_t)&RTC_WKUP_IRQHandler,          			/* RTC Wakeup interrupt through the EXTI line                         */
	(uint32_t)&FLASH_IRQHandler,             			/* Flash global interrupt                                             */
	(uint32_t)&RCC_IRQHandler,               			/* RCC global interrupt                                               */
	(uint32_t)&EXTI0_IRQHandler,             			/* EXTI Line0 interrupt                                               */
	(uint32_t)&EXTI1_IRQHandler,             			/* EXTI Line1 interrupt                                               */
	(uint32_t)&EXTI2_IRQHandler,             			/* EXTI Line2 interrupt                                               */
	(uint32_t)&EXTI3_IRQHandler,             			/* EXTI Line3 interrupt                                               */
	(uint32_t)&EXTI4_IRQHandler,             			/* EXTI Line4 interrupt*/
	(uint32_t)&DMA1_Stream0_IRQHandler,      			/* DMA1 Stream0 global interrupt                                      */
	(uint32_t)&DMA1_Stream1_IRQHandler,      			/* DMA1 Stream1 global interrupt                                      */
	(uint32_t)&DMA1_Stream2_IRQHandler,      			/* DMA1 Stream2 global interrupt                                      */
	(uint32_t)&DMA1_Stream3_IRQHandler,      			/* DMA1 Stream3 global interrupt                                      */
	(uint32_t)&DMA1_Stream4_IRQHandler,      			/* DMA1 Stream4 global interrupt                                      */
	(uint32_t)&DMA1_Stream5_IRQHandler,      			/* DMA1 Stream5 global interrupt                                      */
	(uint32_t)&DMA1_Stream6_IRQHandler,      			/* DMA1 Stream6 global interrupt                                      */
	(uint32_t)&ADC_IRQHandler,               			/* ADC1 global interrupt                                              */
	(uint32_t)&CAN1_TX_IRQHandler,           			/* CAN1 TX interrupts                                                 */
	(uint32_t)&CAN1_RX0_IRQHandler,          			/* CAN1 RX0 interrupts                                                */
	(uint32_t)&CAN1_RX1_IRQHandler,          			/* CAN1 RX1 interrupts                                                */
	(uint32_t)&CAN1_SCE_IRQHandler,          			/* CAN1 SCE interrupt                                                 */
	(uint32_t)&EXTI9_5_IRQHandler,          			/* EXTI Line[9:5] interrupts                                          */
	(uint32_t)&TIM1_BRK_TIM9_IRQHandler,    			/* TIM1 Break interrupt and TIM9 global interrupt                     */
	(uint32_t)&TIM1_UP_TIM10_IRQHandler,     			/* TIM1 Update interrupt and TIM10 global interrupt                   */
	(uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler,			/* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
	(uint32_t)&TIM1_CC_IRQHandler,           			/* TIM1 Capture Compare interrupt                                     */
	(uint32_t)&	TIM2_IRQHandler,             			/* TIM2 global interrupt                                              */
	(uint32_t)&TIM3_IRQHandler,              			/* TIM3 global interrupt                                              */
	(uint32_t)&TIM4_IRQHandler,              			/* TIM4 global interrupt                                              */
	(uint32_t)&I2C1_EV_IRQHandler,           			/* I2C1 event interrupt                                               */
	(uint32_t)&I2C1_ER_IRQHandler,           			/* I2C1 error interrupt                                               */
	(uint32_t)&I2C2_EV_IRQHandler,           			/* I2C2 event interrupt                                               */
	(uint32_t)&I2C2_ER_IRQHandler,           			/* I2C2 error interrupt                                               */
	(uint32_t)&SPI1_IRQHandler,              			/* SPI1 global interrupt                                              */
	(uint32_t)&SPI2_IRQHandler,              			/* SPI2 global interrupt                                              */
	(uint32_t)&USART1_IRQHandler,            			/* USART1 global interrupt                                            */
	(uint32_t)&USART2_IRQHandler,            			/* USART2 global interrupt                                            */
	(uint32_t)&USART3_IRQHandler,            			/* USART3 global interrupt                                            */
	(uint32_t)&	EXTI15_10_IRQHandler,         			/* EXTI Line[15:10] interrupts                                        */
	(uint32_t)&RTC_Alarm_IRQHandler,         			/* RTC Alarms (A and B) through EXTI line interrupt                   */
	(uint32_t)&OTG_FS_WKUP_IRQHandler,       			/* USB On-The-Go FS Wakeup through EXTI line interrupt                */
	(uint32_t)&TIM8_BRK_TIM12_IRQHandler,    			/* TIM8 Break interrupt and TIM12 global interrupt                    */
	(uint32_t)&TIM8_UP_TIM13_IRQHandler,     			/* TIM8 Update interrupt and TIM13 global interrupt                   */
	(uint32_t)&	TIM8_TRG_COM_TIM14_IRQHandler,			/* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt */
	(uint32_t)&TIM8_CC_IRQHandler,           			/* TIM8 Capture Compare interrupt                                     */
	(uint32_t)&DMA1_Stream7_IRQHandler,      			/* DMA1 Stream7 global interrupt                                      */
	(uint32_t)&FMC_IRQHandler,               			/* FMC global interrupt                                               */
	(uint32_t)&	SDIO_IRQHandler,              			/* SDIO global interrupt                                              */
  	(uint32_t)&	TIM5_IRQHandler,              			/* TIM5 global interrupt                                              */
	(uint32_t)&SPI3_IRQHandler,              			/* SPI3 global interrupt                                              */
	(uint32_t)&UART4_IRQHandler,             			/* UART4 global interrupt                                             */
	(uint32_t)&UART5_IRQHandler,             			/* UART5 global interrupt                                             */
	(uint32_t)&TIM6_DAC_IRQHandler,          			/* TIM6 global interrupt, DAC1 and DAC2 underrun error interrupt      */
	(uint32_t)&TIM7_IRQHandler,              			/* TIM7 global interrupt                                              */
	(uint32_t)&DMA2_Stream0_IRQHandler,      			/* DMA2 Stream0 global interrupt                                      */
	(uint32_t)&DMA2_Stream1_IRQHandler,      			/* DMA2 Stream1 global interrupt                                      */
	(uint32_t)&DMA2_Stream2_IRQHandler,      			/* DMA2 Stream2 global interrupt                                      */
	(uint32_t)&DMA2_Stream3_IRQHandler,      			/* DMA2 Stream3 global interrupt                                      */
	(uint32_t)&DMA2_Stream4_IRQHandler,      			/* DMA2 Stream4 global interrupt                                      */
		0,                            			/* Reserved                                                           */
		0,                            			/* Reserved                                                           */
	(uint32_t)&	CAN2_TX_IRQHandler,           			/* CAN2 TX interrupts                                                 */
	(uint32_t)&CAN2_RX0_IRQHandler,          			/* CAN2 RX0 interrupts                                                */
	(uint32_t)&CAN2_RX1_IRQHandler,          			/* CAN2 RX1 interrupts                                                */
	(uint32_t)&	CAN2_SCE_IRQHandler,          			/* CAN2 SCE interrupt                                                 */
	(uint32_t)&OTG_FS_IRQHandler,            			/* USB On The Go FS global interrupt                                  */
	(uint32_t)&	DMA2_Stream5_IRQHandler,      			/* DMA2 Stream5 global interrupt                                      */
	(uint32_t)&DMA2_Stream6_IRQHandler,      			/* DMA2 Stream6 global interrupt                                      */
	(uint32_t)&	DMA2_Stream7_IRQHandler,      			/* DMA2 Stream7 global interrupt                                      */
	(uint32_t)&USART6_IRQHandler,            			/* USART6 global interrupt                                            */
	(uint32_t)&I2C3_EV_IRQHandler,           			/* I2C3 event interrupt                                               */
	(uint32_t)&I2C3_ER_IRQHandler,          			/* I2C3 error interrupt                                               */
	(uint32_t)&OTG_HS_EP1_OUT_IRQHandler,    			/* USB On The Go HS End Point 1 Out                                   */
	(uint32_t)&OTG_HS_EP1_IN_IRQHandler,     			/* USB On The Go HS End Point 1 In                                    */
	(uint32_t)&OTG_HS_WKUP_IRQHandler,       			/* USB On The Go HS Wakeup                                            */
	(uint32_t)&OTG_HS_IRQHandler,            			/* USB On The Go HS global interrupt                                  */
	(uint32_t)&	DCMI_IRQHandler,              			/* DCMI global interrupt                                              */
		0,                            			/* Reserved                                                           */
		0,                            			/* Reserved                                                           */
		0,                            			/* Reserved                                                           */
		0,                            			/* Reserved                                                           */
		0,                            			/* Reserved                                                           */
	(uint32_t)&SPI4_IRQHandler,              			/* SPI 4 global interrupt                                             */
		0,                            			/* Reserved                                                           */
		0,                           			/* Reserved                                                           */
  	(uint32_t)&SAI1_IRQHandler,              			/* SAI1 global interrupt                                              */
		0,                            			/* Reserved                                                           */
		0,                            			/* Reserved                                                           */
		0,                            			/* Reserved                                                           */
  	(uint32_t)&SAI2_IRQHandler,              			/* SAI2 global interrupt                                              */
  	(uint32_t)&QuadSPI_IRQHandler,           			/* QuadSPI global interrupt                                           */
  	(uint32_t)&HDMI_CEC_IRQHandler,          			/* HDMI-CEC global interrupt                                          */
  	(uint32_t)&SPDIF_Rx_IRQHandler,          			/* SPDIF-Rx global interrupt                                          */
  	(uint32_t)&FMPI2C1_IRQHandler,           			/* FMPI2C1 event interrupt */
};
void Default_handler()
{
	while(1)
	{
		
	}
}
void Reset_Handler()
{
    /* Copy the data segment initializers from flash to SRAM*/
    uint32_t *sdata = (uint32_t *) &_sdata;  /* Start of the .data section in SRAM*/
    uint32_t *edata = (uint32_t *) &_edata;  /* End of the .data section in SRAM*/
    uint32_t *sidata = (uint32_t *) &_sidata; /* Start of the .data section in flash*/

    /* Copy initialized data from flash to SRAM*/
    while (sdata < edata) {
        *sdata++ = *sidata++;  /* Copy value from flash to SRAM*/
    }
    uint32_t *sbss = (uint32_t *) &_sbss;  
    uint32_t *ebss = (uint32_t *) &_ebss;

    while (sbss < ebss) {
        *sbss++ = 0;  
    }

    /*main function*/
    main();
}