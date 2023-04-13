#include "USART.h"

void UART_INIT(void)
{
	/*Set pin Directions*/
	/*pin_0 input*/
	Clear_Bit(DDRD, 0);
	/*pin_1 output*/
	Set_Bit(DDRD, 1);

	/* Transmitter/ Receiver Enable */
	UCSRB = 0x18;

	/*Parity Bit Selection*/
	/*Data Size Selection*/
	/*Stop Bit Selection*/
	UCSRC = (PARITY_MODE << 4) | (DATA_SIZE << 1) | (STOP_BIT << 3) | (1 << 7);

	/*Baud Rate Selection*/
	UBRRL = BAUD_RATE;


}
void UART_Tx(Uint8 chr)
{
	UDR = chr;
	while(Get_Bit(UCSRA, 5) == 0);
}
void UART_Tx_String(Uint8* str)
{

}
Uint8 UART_Rx(void)
{
	Uint8 received_data = 0;
	while(Get_Bit(UCSRA, 7) == 0);
	received_data = UDR;
	return received_data;
}