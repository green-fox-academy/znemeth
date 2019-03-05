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

//  Your program should start in a state waiting for 5 button press (press means:
//  press and release), and when it reaches 5, then turn on the user LED,
//	and put your program into a state in which the program is not reacting to
// 	any further button pushes at all, so the LED should be lit once, and forever.

	while (1) {
		if (BSP_PB_GetState(BUTTON_KEY)) {
			HAL_Delay(300);
			if (BSP_PB_GetState(BUTTON_KEY)) {
				HAL_Delay(300);
				if (BSP_PB_GetState(BUTTON_KEY)) {
					HAL_Delay(300);
					if (BSP_PB_GetState(BUTTON_KEY)) {
						HAL_Delay(300);
						if (BSP_PB_GetState(BUTTON_KEY)) {
							while (1) {
								BSP_LED_On(LED1);
							}
						}
					}
				}
			}
		}
	}
}
