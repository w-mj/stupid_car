#ifndef _motor_H
#define _motor_H
#include "stm32f10x.h"
 
void motor_init(void);
void motor_forward(void);
void stop(void);

void set_left_speed(float);
void set_right_speed(float);

void ultraTurnLeft(void);
void ultraTurnRight(void);
void ultraForward(void);
void ultraBackward(void);

void right_stop(void);
void left_stop(void);
void left_forward(void);
void right_forward(void);

#endif 
