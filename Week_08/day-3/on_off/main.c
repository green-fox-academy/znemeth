#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef user_button_handle;

volatile int counter = 0;

volatile uint32_t previous_ms = 0;

void init_user_button()
{
	// Initialize the user push button
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_4;   // port 4-re mukodik
	user_button_handle.Pull = GPIO_NOPULL;  // felhuzo ellenallas NINCS
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING; //rising edge, IT = interrupt

	HAL_GPIO_Init(GPIOB, &user_button_handle); // struct peldany neve

	//Set the priority of the interrupt
	HAL_NVIC_SetPriority(EXTI4_IRQn, 4, 0);

	// Enable the interrupt
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

int main()
{

	HAL_Init();
	BSP_LED_Init(LED_GREEN);
	init_user_button();

	while (1) {
		if (counter % 10 == 0) {
			BSP_LED_Off(LED_GREEN);
		} else if (counter % 5 == 0) {
			BSP_LED_On(LED_GREEN);
		}
	}

	return 0;

}

void EXTI4_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if (GPIO_Pin == user_button_handle.Pin) {


		uint32_t actual_ms = HAL_GetTick();
		uint32_t time_diff = actual_ms - previous_ms;

		if (time_diff > 300) {
			counter++;
		}
		previous_ms = actual_ms;

	}

}
