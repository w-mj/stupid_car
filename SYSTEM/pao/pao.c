#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "pao.h"
#include "delay/delay.h"


void pao_init(void) {
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	gpio.GPIO_Pin = GPIO_Pin_1;
	GPIO_Init(GPIOA, &gpio);
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}


void fire() {
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	delay_ms(1800);
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}
