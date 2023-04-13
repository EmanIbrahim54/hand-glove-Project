#include "DC_Motor.h"
#include "Pwm.h"
#include "USART.h"
#include <util/delay.h>


int main(void)
{
	uint8 ReceivedData;

	DcMotorR_Init();
	DcMotorL_Init();
	LCD_Init();
	UART_INIT();


	while (1)
	{
		ReceivedData = UART_Rx();

		if(ReceivedData == 'l')
		{
			Left();
		}
		else if(ReceivedData == 'r')
		{
			Right();
		}
		else if(ReceivedData == 'f')
		{
			Forward();
		}
		else if(ReceivedData == 'b')
		{
			Backward();
		}
		else if(ReceivedData == 's')
		{
			Stop();
		}
		else if(ReceivedData =='L')
		{
			DcMotors_Speed_Control(40);
		}
		else if(ReceivedData =='H')
		{
			DcMotors_Speed_Control(95);
		}


	}
}