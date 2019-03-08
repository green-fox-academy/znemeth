#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

UART_HandleTypeDef UartHandle;
GPIO_InitTypeDef LEDS;

#define UART_PUTCHAR int __io_putchar(int ch)

int main(void)
{
	HAL_Init();

	/* enable GPIO clock */
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	/* configure GPIO for UART transmit line */
	GPIOTxConfig.Pin = GPIO_PIN_9;
	GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIOTxConfig.Speed = GPIO_SPEED_FAST;
	GPIOTxConfig.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIOTxConfig);

	/* configure GPIO for UART receive line */
	GPIORxConfig.Pin = GPIO_PIN_7;
	GPIORxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIORxConfig.Speed = GPIO_SPEED_FAST;
	GPIORxConfig.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOB, &GPIORxConfig);

	LEDS.Pin = GPIO_PIN_9 | GPIO_PIN_10; /* setting up 2 pins at once with | operator */
	LEDS.Mode = GPIO_MODE_OUTPUT_PP; /* configure as output, in push-pull mode */
	LEDS.Pull = GPIO_NOPULL; /* we don't need internal pull-up or -down resistor */
	LEDS.Speed = GPIO_SPEED_HIGH; /* we need a high-speed output */

	HAL_GPIO_Init(GPIOF, &LEDS); /* initialize the pin on GPIOF port */

	/* enable the clock of the used peripherial instance */
	__HAL_RCC_USART1_CLK_ENABLE()
	;

	BSP_LED_Init(LED_GREEN);
	/* defining the UART configuration structure */
	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &UartHandle);

	while (1) {

		uint8_t one_char;
		uint8_t oneline[100];
		uint8_t flag = 0;
		while (HAL_UART_Receive(&UartHandle, (uint8_t*) &one_char,
				sizeof(one_char), 0xFFFF) != HAL_ERROR) {
			if (one_char != '\n') {
				oneline[flag] = one_char;
				flag++;
			} else {
				oneline[flag] = '\0';
				if (!strcmp(oneline, "on")) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
				} else if (!strcmp(oneline, "off")) {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
				} else {
					HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
					for (int i = 0; i < 3; i++) {
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
						HAL_Delay(250);
						HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
						HAL_Delay(250);
					}
				}
				flag = 0;
			}
		}
	}
}

UART_PUTCHAR
{
	HAL_UART_Transmit(&UartHandle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
