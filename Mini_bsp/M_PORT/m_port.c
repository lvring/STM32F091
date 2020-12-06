#include "m_port.h"
#include "m_scheduler.h"

/**
  ******************************************************************************
  * @file    port
  * @author  JQ ->>https://github.com/lvring
  * @brief   ��Ҫʵ�ֵĺ���
  * @version V1.0 2019/4/15 
	* @History V1.0 ����
  ******************************************************************************
  */


void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* Infinite loop */
    printf("assert failed at %s:%d \n", file, line);
    while (1) {
    }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */


void _putchar(char character)
{
	//Com_Send(COM_1,(uint8_t *)&character,1);
	HAL_UART_Transmit(&UartHandle[USART_DEBUG].UartHalHandle,(uint8_t *)&character,1,0xFFFFFFFF);
}


void SysTick_Handler(void)
{
	SchedulerSysTickIntHandler();
}


