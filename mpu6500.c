#include "mpu6500.h"
#include "24cxx.h"

void InitMPU6050(void)
{
	AT24CXX_WriteOneByte(PWR_MGMT_1, 0x00);
	AT24CXX_WriteOneByte(SMPLRT_DIV, 0x07);
	AT24CXX_WriteOneByte(CONFIG, 0x06);
	AT24CXX_WriteOneByte(GYRO_CONFIG, 0x18);
	AT24CXX_WriteOneByte(ACCEL_CONFIG, 0x01);
}

int GetData(uint8_t REG_Address)
{
	uint8_t H,L;
	H=AT24CXX_ReadOneByte(REG_Address);
	L=AT24CXX_ReadOneByte(REG_Address+1);
	return (H<<8)+L;
}

