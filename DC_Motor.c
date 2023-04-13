
#include "DC_Motor.h"
#include "Pwm.h"
#include <util/delay.h>


void DcMotorR_Init(void)
{
	/* !Comment: Initialize the DC Motor direction selection Pins */
	Dio_ChannelDirectionSet(DC_MOTOR_R_DIR_REG, DC_MOTOR_R_IN1_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(DC_MOTOR_R_DIR_REG, DC_MOTOR_R_IN2_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(DC_MOTOR_R_EN_DIR_REG, DC_MOTOR_R_EN_PIN, DIO_OUTPUT);
	/* !Comment: Initialize PWM module */
	Pwm_Init(&gStrPwm_Configuration[PWM_CHANNEL_1]);
}
void DcMotorR_Control(DcMotor_RotationDirType Dir, DcMotor_SpeedType Speed)
{
	switch(Dir)
	{
		case DC_MOTOR_TURN_CW:
		Dio_ChannelWrite(DC_MOTOR_R_OUT_REG, DC_MOTOR_R_IN1_PIN, DIO_HIGH);
		Dio_ChannelWrite(DC_MOTOR_R_OUT_REG, DC_MOTOR_R_IN2_PIN, DIO_LOW);
		break;
		case DC_MOTOR_TURN_CCW:
		Dio_ChannelWrite(DC_MOTOR_R_OUT_REG, DC_MOTOR_R_IN1_PIN, DIO_LOW);
		Dio_ChannelWrite(DC_MOTOR_R_OUT_REG, DC_MOTOR_R_IN2_PIN, DIO_HIGH);
		break;
		default:
		break;
	}
	switch(Speed)
	{
		case DC_MOTOR_SPEED_LOW:
		Pwm_SetDutyCycle(PWM_CHANNEL_1, 20U);
		break;
		case DC_MOTOR_SPEED_MID:
		Pwm_SetDutyCycle(PWM_CHANNEL_1, 50U);
		break;
		case DC_MOTOR_SPEED_HIGH:
		Pwm_SetDutyCycle(PWM_CHANNEL_1, 90U);
		break;
		default:
		break;
	}
}

void DcMotorL_Init(void)
{
	/* !Comment: Initialize the DC Motor direction selection Pins */
	Dio_ChannelDirectionSet(DC_MOTOR_L_DIR_REG, DC_MOTOR_L_IN1_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(DC_MOTOR_L_DIR_REG, DC_MOTOR_L_IN2_PIN, DIO_OUTPUT);
	Dio_ChannelDirectionSet(DC_MOTOR_L_EN_DIR_REG, DC_MOTOR_L_EN_PIN, DIO_OUTPUT);
	/* !Comment: Initialize PWM module */
	Pwm_Init(&gStrPwm_Configuration[PWM_CHANNEL_1]);
}
void DcMotorL_Control(DcMotor_RotationDirType Dir, DcMotor_SpeedType Speed)
{
	switch(Dir)
	{
		case DC_MOTOR_TURN_CW:
		Dio_ChannelWrite(DC_MOTOR_L_OUT_REG, DC_MOTOR_L_IN1_PIN, DIO_HIGH);
		Dio_ChannelWrite(DC_MOTOR_L_OUT_REG, DC_MOTOR_L_IN2_PIN, DIO_LOW);
		break;
		case DC_MOTOR_TURN_CCW:
		Dio_ChannelWrite(DC_MOTOR_L_OUT_REG, DC_MOTOR_L_IN1_PIN, DIO_LOW);
		Dio_ChannelWrite(DC_MOTOR_L_OUT_REG, DC_MOTOR_L_IN2_PIN, DIO_HIGH);
		break;
		default:
		break;
	}
	switch(Speed)
	{
		case DC_MOTOR_SPEED_LOW:
		Pwm_SetDutyCycle(PWM_CHANNEL_1, 20U);
		break;
		case DC_MOTOR_SPEED_MID:
		Pwm_SetDutyCycle(PWM_CHANNEL_1, 50U);
		break;
		case DC_MOTOR_SPEED_HIGH:
		Pwm_SetDutyCycle(PWM_CHANNEL_1, 90U);
		break;
		default:
		break;
	}
}

void Forward(void)
{
	DcMotorR_Control(DC_MOTOR_TURN_CW, DC_MOTOR_SPEED_MID);
	DcMotorL_Control(DC_MOTOR_TURN_CW, DC_MOTOR_SPEED_MID);
	
	LCD_StringDisplay("Moving Forward");
	_delay_ms(500);
	LCD_Clear();
}
void Backward(void)
{
	DcMotorR_Control(DC_MOTOR_TURN_CCW, DC_MOTOR_SPEED_MID);
	DcMotorL_Control(DC_MOTOR_TURN_CCW, DC_MOTOR_SPEED_MID);
	
	LCD_StringDisplay("Moving Backward");
	_delay_ms(500);
	LCD_Clear();
}
void Left(void)
{
	DcMotorR_Control(DC_MOTOR_TURN_CW, DC_MOTOR_SPEED_MID);
	DcMotorL_Control(DC_MOTOR_TURN_CCW, DC_MOTOR_SPEED_MID);
	
	LCD_StringDisplay("Turning Left");
	_delay_ms(500);
	LCD_Clear();
}
void Right(void)
{
	DcMotorR_Control(DC_MOTOR_TURN_CCW, DC_MOTOR_SPEED_MID);
	DcMotorL_Control(DC_MOTOR_TURN_CW, DC_MOTOR_SPEED_MID);
	
	LCD_StringDisplay("Turning Right");
	_delay_ms(500);
	LCD_Clear();
}

void Stop(void)
{
	Dio_ChannelWrite(DC_MOTOR_L_OUT_REG, DC_MOTOR_L_IN1_PIN, DIO_LOW);
	Dio_ChannelWrite(DC_MOTOR_L_OUT_REG, DC_MOTOR_L_IN2_PIN, DIO_LOW);
	Pwm_SetDutyCycle(PWM_CHANNEL_1, 0);
	
	LCD_StringDisplay("Stopping");
	_delay_ms(500);
	LCD_Clear();
}
void DcMotors_Speed_Control(DcMotor_SpeedType Speed){
	
	Pwm_SetDutyCycle(PWM_CHANNEL_1, Speed);
	
}
