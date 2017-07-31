#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "usmart.h"	  
#include "mpu6500.h"

int main(void)
{
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	uart_init(115200);
	LED_Init();
	LCD_Init();
	KEY_Init(); 	
	IIC_Init();
	InitMPU6050();
	
	//void LCD_ShowString( x, y, width, height, size, *p)
	LCD_ShowString(30,190,150,16,16,"   ACCEL_XOUT_H Is:");
	LCD_ShowString(30,210,150,16,16,"   ACCEL_YOUT_H Is:");
	LCD_ShowString(30,230,150,16,16,"   ACCEL_ZOUT_H Is:");
	LCD_ShowString(30,250,150,16,16,"    GYRO_XOUT_H Is:");
	LCD_ShowString(30,270,150,16,16,"    GYRO_YOUT_H Is:");
	LCD_ShowString(30,290,150,16,16,"    GYRO_ZOUT_H Is:");
	while(1)
	{
		//void LCD_ShowxNum(x, y, num, len, size, mode)
		LCD_ShowxNum(200, 190, GetData(ACCEL_XOUT_H), 5, 16, 16);
		LCD_ShowxNum(200, 210, GetData(ACCEL_YOUT_H), 5, 16, 16);
		LCD_ShowxNum(200, 230, GetData(ACCEL_ZOUT_H), 5, 16, 16);
		LCD_ShowxNum(200, 250, GetData(GYRO_XOUT_H), 5, 16, 16);
		LCD_ShowxNum(200, 270, GetData(GYRO_YOUT_H), 5, 16, 16);
		LCD_ShowxNum(200, 290, GetData(GYRO_ZOUT_H), 5, 16, 16);
		delay_ms(250);
	}
}

