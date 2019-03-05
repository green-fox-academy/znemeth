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

//    Make the green user LED flashing with 2 Hz, but the flashing should not begin until
//    the user button is not pressed. Once it is pushed, the LED should be blinking forever.


    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
    while (1) {
            if (BSP_PB_GetState(BUTTON_KEY)) {
            	while (1) {
            	BSP_LED_On(LED1);
            			HAL_Delay(500);
              	        BSP_LED_Off(LED1);
               	        HAL_Delay(500);
            	    	}
            	}
            }
}
