#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef RGB_LED_handle;
GPIO_InitTypeDef blue_button_handle;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_user_button()
{

	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	blue_button_handle.Pin = GPIO_PIN_11;
	blue_button_handle.Pull = GPIO_NOPULL;
	blue_button_handle.Speed = GPIO_SPEED_FAST;
	blue_button_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &blue_button_handle);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_RGB_LED()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	RGB_LED_handle.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
	RGB_LED_handle.Mode = GPIO_MODE_OUTPUT_PP;
	RGB_LED_handle.Pull = GPIO_NOPULL;
	RGB_LED_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &RGB_LED_handle);

}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_user_button();
	init_RGB_LED();
	while (1) {


	}

	return 0;

}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(blue_button_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == blue_button_handle.Pin) {

		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_8);
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	}

}

static void Error_Handler(void)
{
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

