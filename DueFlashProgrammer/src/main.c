#include <stdio.h>
#include <stdlib.h>

#include <asf.h>

static void configure_console_uart(void)
{
	/*https://startingelectronics.org/software/atmel/asf-arm-tutorial/stdio-uart/*/
	
	const usart_serial_options_t console_usart_serial_options =
	{	.baudrate     = CONF_UART_BAUDRATE,
		.charlength   = CONF_UART_CHAR_LENGTH,
		.paritytype   = CONF_UART_PARITY,
		.stopbits     = CONF_UART_STOP_BITS
	};
	
	//sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &console_usart_serial_options);
}


int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	
	sysclk_init();
	board_init();

	/* Insert application code here, after the board has been initialized. */
	
	/*	Initialize STDIO to USART	*/
	configure_console_uart();
	
	//Initialize GPIO needed by NFC
	
	while(1)
	{
		printf("\r\nHello World!\r\n");
	}
	
}
