#include <ctg.h>
#include <string.h>
#include <stdlib.h>

/* initialise queue  */
struct queue* create_queue(int length)
{
	struct queue* temp = (struct queue*)malloc(sizeof(struct queue*));

	temp->head = NULL;
	temp->tail = NULL;

	/* initialise queue first */
	for(int i = 0; i < length; i++)
	{
		node *n = (node*)malloc(sizeof(node));
		n->sample = 0.0;
		n->next = NULL;

		if(temp->head == NULL)
		{
			temp->head = n;
			temp->tail = temp->head;
		}
		else
		{
			n->next = temp->head;
			temp->head = n;
		}
	}

	/* initialize variables at the end or malloc will override these values */
	temp->sum = 0.0;
	temp->avg = 1.0;
	temp->length = length;

	return temp;
}

/* shift samples in queue and calculate sum of queue */
void shift_queue(struct queue * q, float sample)
{
	node *n = (node*)malloc(sizeof(node));
	n->sample = sample;
	n->next = NULL;

	q->tail->next = n;
	q->tail = n;
	//q->sum += sample;

	node *temp = q->head;
	//q->sum -= temp->sample;
	q->head = q->head->next;
	free(temp);
}

/* calculate average of queue */
void get_average(struct queue * q, float * avg)
{
	*avg = q->sum / q->length;
}

/* @brief	uart print function with newline
 * @param	huart: pointer to the uart handle
 * @param	buffer: pointer to a char or string */
void ctg_print(UART_HandleTypeDef *huart, char * buffer)
{
	HAL_UART_Transmit(huart, (uint8_t *)buffer, strlen(buffer), 10);
	//HAL_UART_Transmit_IT(huart, (uint8_t *)buffer, strlen(buffer));
	/* print newline */
	char newline[2] = "\r\n";
	HAL_UART_Transmit(huart, (uint8_t *)newline, 2, 10);
	//HAL_UART_Transmit_IT(huart, (uint8_t *)buffer, strlen(buffer));
}

void ctg_read_adc(ADC_HandleTypeDef *hadc, float *voltage)
{
	  /* (re)start ADC sampling */
	  HAL_ADC_Start(hadc);

	  /* poll 1ms for conversion */
	  HAL_ADC_PollForConversion(hadc, 1);

	  /* read ADC value */
	  uint32_t sample = HAL_ADC_GetValue(hadc);

	  /* convert to voltage */
	  *voltage = ((float)sample * (float)3.3);
	  /* divide voltage by 4096  */
	  *voltage = *voltage / 4096;
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
