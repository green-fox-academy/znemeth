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

/*    while (1) {
        BSP_LED_On(LED1);
        HAL_Delay(150);
        BSP_LED_Off(LED1);
        HAL_Delay(250);
    }
*/
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
    while (1) {
            if (BSP_PB_GetState(BUTTON_KEY)) {
                /* If button is pressed do something */
                BSP_LED_On(LED1);
            }
        }


}
