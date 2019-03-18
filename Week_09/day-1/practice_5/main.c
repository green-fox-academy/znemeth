#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

typedef enum
{
	FAST, SLOW
} status_t;

volatile status_t status = FAST;
volatile uint8_t counter = 0;

GPIO_InitTypeDef user_button_handle;
TIM_HandleTypeDef timer_led1;
//TIM_HandleTypeDef timer_led2;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_timer_led1()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	HAL_TIM_Base_DeInit(&timer_led1);
	timer_led1.Instance = TIM2;
	timer_led1.Init.Prescaler = 54000 - 1;
	timer_led1.Init.Period = 125 - 1;
	timer_led1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_led1.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&timer_led1);
	HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}
/*
 void init_timer_led2()
 {
 __HAL_RCC_TIM3_CLK_ENABLE()
 ;
 HAL_TIM_Base_DeInit(&timer_led2);
 timer_led2.Instance = TIM3;
 timer_led2.Init.Prescaler = 54000 - 1;
 timer_led2.Init.Period = 1000 - 1;
 timer_led2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
 timer_led2.Init.CounterMode = TIM_COUNTERMODE_UP;
 HAL_TIM_Base_Init(&timer_led2);
 HAL_NVIC_SetPriority(TIM3_IRQn, 3, 0);
 HAL_NVIC_EnableIRQ(TIM3_IRQn);
 }
 */
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
	init_timer_led1();
	//init_timer_led2();
	HAL_TIM_Base_Start_IT(&timer_led1);

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

		if (status == FAST) {
			//HAL_TIM_Base_Stop_IT(&timer_led1);
			status = SLOW;
			//HAL_TIM_Base_Start_IT(&timer_led1);

		} else if (status == SLOW) {
			//HAL_TIM_Base_Stop_IT(&timer_led1);
			status = FAST;
			//HAL_TIM_Base_Start_IT(&timer_led1);

		}

	}

}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&timer_led1);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		if (status == FAST && counter == 8) {
			BSP_LED_Toggle(LED_GREEN);
			counter = 0;
		} else if (status == FAST) {
			counter++;

		}
		if (status == SLOW) {
			BSP_LED_Toggle(LED_GREEN);
		}
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
