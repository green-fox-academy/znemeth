#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

TIM_HandleTypeDef timer_handle;
static void SystemClock_Config(void);

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	HAL_TIM_Base_DeInit(&timer_handle); //elozo base deinicializalasa
	__HAL_TIM_SET_COUNTER(&timer_handle, 0);
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 54000 - 1; /* 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms */
	timer_handle.Init.Period = 12000 - 1; /* 6000 x 0.5 ms = 6 second period */
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configure the timer */
	HAL_TIM_Base_Init(&timer_handle);

}

int main()
{
	HAL_Init();
	SystemClock_Config();

	BSP_LED_Init(LED_GREEN);

	init_timer();

	/* starting the timer */
	HAL_TIM_Base_Start_IT(&timer_handle);

	while (1) {

	}

	return 0;

}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {

		//printf("ENTRY point of the timer callback (in every 6 seconds)\n\n");
		int start_timestamp = __HAL_TIM_GET_COUNTER(htim);

		for (int i = 0; i < 48826291; i++);    // a for ciklus itt veget er. az a cel h ne csinaljon semmit se.
		/* 48826291 execution of this loop takes exactly 3000 ms */
		int end_timestamp = __HAL_TIM_GET_COUNTER(htim);

		int time_diff = (end_timestamp - start_timestamp) / 2;

		//printf("EXIT point of the timer callback (after %d ms)\n\n", time_diff);
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

