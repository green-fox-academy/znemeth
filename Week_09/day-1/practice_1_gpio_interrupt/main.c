#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

typedef enum
{
	ON, OFF
} led_status_t;

volatile led_status_t STATUS = ON;

GPIO_InitTypeDef user_button_handle;
TIM_HandleTypeDef timer_led;

void init_timer_led()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	HAL_TIM_Base_DeInit(&timer_led);
	timer_led.Instance = TIM2;
	timer_led.Init.Prescaler = 54000 - 1;
	timer_led.Init.Period = 1000 - 1;
	timer_led.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_led.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&timer_led);
	HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void init_user_button()
{
	// Initialize the user push button
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	user_button_handle.Pin = GPIO_PIN_11;   // blue button
	user_button_handle.Pull = GPIO_NOPULL;  // felhuzo ellenallas NINCS
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING; //rising edge, IT = interrupt

	HAL_GPIO_Init(GPIOI, &user_button_handle); // struct peldany neve

	//Set the priority of the interrupt
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);

	// Enable the interrupt
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

int main()
{

	HAL_Init();
	BSP_LED_Init(LED_GREEN);
	init_user_button();
	init_timer_led();
	HAL_TIM_Base_Start_IT(&timer_led);

	BSP_LED_On(LED_GREEN);

	while (1) {

	}

	return 0;

}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if (GPIO_Pin == user_button_handle.Pin) {

		BSP_LED_Toggle(LED_GREEN);

	}

}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&timer_led);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		//BSP_LED_On(LED_GREEN);
	}
}
