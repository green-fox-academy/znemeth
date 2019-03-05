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

//    Toggle the green user LED with the blue user button switch,
//    so the LED should be turned on to a push, and then off to another push, and so on.


    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
    while (1) {
            if (BSP_PB_GetState(BUTTON_KEY)) {
            			BSP_LED_Toggle(LED1);
            	    }
            }
}
