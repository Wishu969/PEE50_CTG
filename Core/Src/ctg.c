#include <ctg.h>
#include <string.h>

/* @brief	uart print function with newline
 * @param	huart: pointer to the uart handle
 * @param	buffer: pointer to a char or string */
void ctg_print(UART_HandleTypeDef *huart, char * buffer)
{
	HAL_UART_Transmit(huart, (uint8_t *)buffer, strlen(buffer), 10);
	/* print newline */
	char newline[2] = "\r\n";
	HAL_UART_Transmit(huart, (uint8_t *)newline, 2, 10);
}

uint32_t sinewave16[16] =
{
		2048,
		2832,
		3496,
		3940,
		4095,
		3940,
		3496,
		2832, //half sine
		2048,
		1264,
		600,
		156,
		0,
		156,
		600,
		1264
};

/* sinewave in 32 slices for dac */
uint32_t sinewave32[32] =
{
		2048, 2448, 2832, 3186, 3496, 3751, 3940, 4057,
		4095, 4057, 3940, 3751, 3496, 3186, 2832, 2448,
		2048, 1648,	1264,  910,	 600,  345,  156,   39,
		   0,   39,  156,  345,  600,  910, 1264, 1648
};