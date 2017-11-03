#include "infrared.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "adc/adc.h"

// 从右至左依次为10， 11， 12， 13
//加上8 9
void infrared_init(void) {
	GPIO_InitTypeDef gpio_init;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);	
	gpio_init.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_init.GPIO_Pin = INFRARED_PIN|DAPAO_PIN;
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_init);
}
