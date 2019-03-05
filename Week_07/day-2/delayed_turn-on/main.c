/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void)
{
	HAL_Init();

	BSP_LED_Init(LED1);

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);



	int count = 0;
	while (1) {
		if (BSP_PB_GetState(BUTTON_KEY) && count < 5) {
			count++;
			HAL_Delay(300);
		} else if (BSP_PB_GetState(BUTTON_KEY) && count >= 5) {
			while (1) {
				BSP_LED_On(LED1);
			}
		}
	}
}
