#ifndef INC_CTG_H_
#define INC_CTG_H_

#include "stdint.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_uart.h"

void ctg_print(UART_HandleTypeDef *huart, char * buffer);

extern uint32_t sinewave16[16];

extern uint32_t sinewave32[32];

#endif /* INC_CTG_H_ */
