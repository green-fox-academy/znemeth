#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void freq_play()
{
	int n = 2000;

	for (int i = 1; i < 16; i++) {
		n = n / 1.14;
		for (int i = 0; i < 1; i++) {
			BSP_LED_On(LED1);
			HAL_Delay(n);
			BSP_LED_Off(LED1);
			HAL_Delay(n);
		}
	}

	for (int i = 16; i > 1; i--) {
			n = n / 1.14;
			for (int i = 0; i < 1; i++) {
				BSP_LED_On(LED1);
				HAL_Delay(n);
				BSP_LED_Off(LED1);
				HAL_Delay(n);
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
