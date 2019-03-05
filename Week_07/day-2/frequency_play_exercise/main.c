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

void freq_play()
{
	int n = 2000;
	for (int j = 1; j < 100; j++) {
		for (int i = 0; i < 3; i++) {
			BSP_LED_On(LED1);
			HAL_Delay(n / j);
			BSP_LED_Off(LED1);
			HAL_Delay(n / j);
		}
	}
}

int main(void)
{
	HAL_Init();

	BSP_LED_Init(LED1);

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	//  Flash the user LED with gradually increasing frequency.
	//	Start from 0.5 Hz and constantly make it 1 Hz, then 2 Hz finally 4 Hz,
	//	then it should constantly decrease the frequency from 4 Hz back to 0.5 Hz.
	//	(increase/decrease the frequency, when 3 period - on and off - comes to an end.

	while (1) {
		if (BSP_PB_GetState(BUTTON_KEY)) {
			while (1) {
				freq_play();
			}
		}
	}
}
