/*#include "exti\exti.h"
#include "delay\delay.h"
#include "motor\motor.h"
#include "pao\pao.h"

void exti_init() {
	//GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource8);
	
	EXTI_InitStructure.EXTI_Line=EXTI_Line8;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure); 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);		 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure); 		
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line8) == SET)
	{
   	EXTI_ClearITPendingBit(EXTI_Line8);
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0 && GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0)
		{
			stop();
			delay_ms(2000);
			
			while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0 && GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0) {
				ultraBackward();
				delay_ms(5);
				stop();
				delay_ms(30);
			}
			if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 1) { //8 right
				while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) == 1) {
					right_forward();
					delay_ms(5);
					right_stop();
					delay_ms(30);
				}
			} else if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9) == 1){ //9 left
				while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 1) {
					left_forward();
					delay_ms(10);
					left_stop();
					delay_ms(20);
				}
			}
			fire();
			
		}
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0 && GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0);
		ultraForward();
	}
	if(EXTI_GetITStatus(EXTI_Line9) == SET)
	{
   	EXTI_ClearITPendingBit(EXTI_Line9);
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0 && GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0)
		{
			stop();
			delay_ms(2000);
			
			while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0 && GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0) {
				ultraBackward();
				delay_ms(5);
				stop();
				delay_ms(30);
			}
			if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 1) { //8 right
				while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8) == 1) {
					right_forward();
					delay_ms(5);
					right_stop();
					delay_ms(30);
				}
			} else if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9) == 1){ //9 left
				while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 1) {
					left_forward();
					delay_ms(10);
					left_stop();
					delay_ms(20);
				}
			}
			fire();
			
		}
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0 && GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0);
		ultraForward();
	}
	
}
*/
