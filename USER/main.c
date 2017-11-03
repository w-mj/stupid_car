#include "stm32f10x.h"
#include "delay\delay.h"
#include "usart\usart.h"
#include "adc\adc.h"
#include "camera\camera.h"
#include "stervo\stervo.h"
#include "infrared\infrared.h"
#include "motor\motor.h"
//#include "exti\exti.h"
#include "sys\sys.h"
#include "pao\pao.h"

#define angleLimit(x) ((x) < 75? 75 : ( (x) > 105? 105 : (x)))
#define speedLimit(x) ((x) < 0.4 ? 0.4: ((x) > 1 ? 1 : (x)))

extern u8 ADV[128];



int main()
{	
	u8 lo, li, ro, ri,left,right, check = 0;
	SystemInit();
	delay_init();
	//exti_init();
	uart_init(9600);
	motor_init();
	infrared_init();
	pao_init();
	
	ultraForward();
	
	while(1) {
		lo = GPIO_ReadInputDataBit(GPIOB, L_OUT);
		li = GPIO_ReadInputDataBit(GPIOB, L_IN);
		ro = GPIO_ReadInputDataBit(GPIOB, R_OUT);
		ri = GPIO_ReadInputDataBit(GPIOB, R_IN);
		



		right = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);//r
		left = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9);//l
		
		
if(!(left&&right)){
			check = 0;
			stop();
			delay_ms(500);
	    li = GPIO_ReadInputDataBit(GPIOB, L_IN);
		  ri = GPIO_ReadInputDataBit(GPIOB, R_IN);
      do {
					
		      if(li){
						ultraTurnLeft();
					  delay_ms(2);
					  stop();
					  delay_ms(2);}
					else if(ri){
						ultraTurnRight();
					  delay_ms(2);
					  stop();
					  delay_ms(2);
					} 
					li = GPIO_ReadInputDataBit(GPIOB, L_IN);
		      ri = GPIO_ReadInputDataBit(GPIOB, R_IN);				
				}while((li||ri));
			fire();
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8) == 0 && GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0);
		ultraForward();
		}




		
		if ((li || lo) && (ri || ro))  // ×óÓÒÍ¬Ê±ºÚ
			continue;
		
		if (! (li || lo || ri || ro))  // È«°×
			continue; 
//////////////////////////////////////////////////////////////////////
//    dpl = GPIO_ReadInputDataBit(GPIOB, DAPAO_LEFT);
//		dpr = GPIO_ReadInputDataBit(GPIOB, DAPAO_RIGHT);
//		if(!(dpl&&dpr))
//		{
//			 delay_ms(500);
//			 stop();
//			 delay_ms(1800);
//		}
//////////////////////////////////////////////////////////////////////			
		if (lo) {
			ultraTurnLeft();
			delay_ms(20);
		} else if (ro) {
			ultraTurnRight();
			delay_ms(20);
		} else if (li) {
			ultraTurnLeft();
			delay_ms(10);
		} else if (ri) {
			ultraTurnRight();
			delay_ms(10);
		} 
		
		ultraForward();
		delay_ms(25);
	}	
}
