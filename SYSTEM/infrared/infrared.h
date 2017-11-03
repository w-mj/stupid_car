#ifndef _INFRARED_H_
#define _INFRARED_H_

#define L_OUT GPIO_Pin_13
#define L_IN GPIO_Pin_12
#define R_IN GPIO_Pin_11
#define R_OUT GPIO_Pin_10
///////////////////////////////////////////////////////////////////
#define DAPAO_LEFT GPIO_Pin_8
#define DAPAO_RIGHT GPIO_Pin_9
#define DAPAO_PIN (DAPAO_LEFT|DAPAO_RIGHT)
///////////////////////////////////////////////////////////////////

#define INFRARED_PIN  (L_OUT | L_IN | R_IN | R_OUT)

#define ON_BLACK 1
#define ON_WHITE 0

#define DETECT (0 | PBin(L_OUT) << 4 | PBin(L_IN) << 3 | PBin(R_IN) << 2 | PBin(R_OUT))

void infrared_init(void);

#endif
