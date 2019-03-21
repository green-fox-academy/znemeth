#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef GB_LED_handle;
GPIO_InitTypeDef R_LED_handle;
GPIO_InitTypeDef blue_button_handle; // GREEN
GPIO_InitTypeDef ext1_button_handle;
GPIO_InitTypeDef ext2_button_handle;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_ext1_button()
{
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;

	ext1_button_handle.Pin = GPIO_PIN_2;
	ext1_button_handle.Pull = GPIO_NOPULL;
	ext1_button_handle.Speed = GPIO_SPEED_FAST;
	ext1_button_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &ext1_button_handle);

	HAL_NVIC_SetPriority(EXTI2_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(EXTI2_IRQn);
}

void init_ext2_button()
{
	__HAL_RCC_GPIOG_CLK_ENABLE()
	;

	ext2_button_handle.Pin = GPIO_PIN_7;
	ext2_button_handle.Pull = GPIO_NOPULL;
	ext2_button_handle.Speed = GPIO_SPEED_FAST;
	ext2_button_handle.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOG, &ext2_button_handle);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

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

void init_GB_LED()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	GB_LED_handle.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	GB_LED_handle.Mode = GPIO_MODE_OUTPUT_PP;
	GB_LED_handle.Pull = GPIO_NOPULL;
	GB_LED_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &GB_LED_handle);

}

void init_R_LED()
{
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;
	R_LED_handle.Pin = GPIO_PIN_0;
	R_LED_handle.Mode = GPIO_MODE_OUTPUT_PP;
	R_LED_handle.Pull = GPIO_NOPULL;
	R_LED_handle.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOI, &R_LED_handle);

}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_user_button();
	init_GB_LED();
	init_R_LED();
	init_ext1_button();
	init_ext2_button();

	while (1) {

	}

	return 0;

}

void EXTI2_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(ext1_button_handle.Pin);
}

void EXTI9_5_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(ext2_button_handle.Pin);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(blue_button_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == blue_button_handle.Pin) {
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_8); // GREEN
	} else if (GPIO_Pin == ext1_button_handle.Pin) {
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	} else if (GPIO_Pin == ext2_button_handle.Pin) {
		HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_0);
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

