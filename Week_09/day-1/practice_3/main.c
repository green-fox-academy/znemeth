#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

typedef enum
{
	ON, OFF
} status_t;

volatile status_t status = ON;

GPIO_InitTypeDef user_button_handle;
TIM_HandleTypeDef timer_led;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_timer_led()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	HAL_TIM_Base_DeInit(&timer_led);
	timer_led.Instance = TIM2;
	timer_led.Init.Prescaler = 54000 - 1;
	timer_led.Init.Period = 125 - 1;
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
	SystemClock_Config();
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
		if (status == ON) {
			BSP_LED_Off(LED_GREEN);
			status = OFF;
		} else if (status == OFF) {
			BSP_LED_On(LED_GREEN);
			status = ON;
		}

	}

}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&timer_led);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		/*	if (status == ON) {
		 BSP_LED_On(LED_GREEN);
		 } else if (status == OFF) {
		 BSP_LED_Off(LED_GREEN);
		 }*/
	}
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

static void Error_Handler(void)
{
}
