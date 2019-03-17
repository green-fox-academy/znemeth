#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

UART_HandleTypeDef UartHandle;

int main(void)
{
    HAL_Init();

    /* enable the clock of the used peripherial instance */
    __HAL_RCC_USART1_CLK_ENABLE();

    /* defining the UART configuration structure */
    UartHandle.Instance = USART1;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &UartHandle);

    char hello[] = "Principessa!!\r\n";
    char hello2[] = "Ci vediamo a Venezia!\r\n";
    char hello3[] = ";)\r\n";

    while (1) {

        HAL_Delay(1000);
        HAL_UART_Transmit(&UartHandle, (uint8_t*) hello, strlen(hello), 0xFFFF);
        HAL_Delay(500);
        HAL_UART_Transmit(&UartHandle, (uint8_t*) hello2, strlen(hello2), 0xFFFF);
        HAL_Delay(500);
        HAL_UART_Transmit(&UartHandle, (uint8_t*) hello3, strlen(hello3), 0xFFFF);
    }
}
