#ifndef INC_CTG_H_
#define INC_CTG_H_

#include "stdint.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_uart.h"
#include "stm32l4xx_hal_adc.h"

void ctg_print(UART_HandleTypeDef *huart, char * buffer);

void ctg_read_adc(ADC_HandleTypeDef *hadc, float *voltage);

extern uint32_t sinewave16[16];

extern uint32_t sinewave32[32];

#endif /* INC_CTG_H_ */
