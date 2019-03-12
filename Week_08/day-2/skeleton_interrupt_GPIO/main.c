#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef user_button_handle;

void init_user_button()
{
	// Initialize the user push button
	__HAL_RCC_GPIOI_CLK_ENABLE()
	; // port I !!!

	user_button_handle.Pin = GPIO_PIN_11;   // port 11-re mukodik
	user_button_handle.Pull = GPIO_NOPULL;  // felhuzo ellenallas NINCS
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING; //rising edge, IT = interrupt

	//user_button_handle.Alternate = ; PWM-hez kell, de akkor a Mode-ot is modositani kell

	HAL_GPIO_Init(GPIOI, &user_button_handle); // struct peldany neve

	//Set the priority of the interrupt
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);

	// Enable the interrupt
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);  //csak a 10 es 15 kozotti pinre mukodik
}

int main()
{

	// main fuggveny

	HAL_Init();
	BSP_LED_Init(LED_GREEN);
	init_user_button();

	while (1) {
	}

	return 0;

}

void EXTI15_10_IRQHandler()    //startup .s fajlbol lehet kiolvasni
{
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin); // adott pin-re allitja a handlert!!!
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{		// ez a HAL_GPIO_EXTI_IRQHandler fuggvenyben van benne Callback neven

	if (GPIO_Pin == user_button_handle.Pin) { //pin akarmi lehet de legyen az adtt pin

		BSP_LED_Toggle(LED_GREEN);
	}

}
