#include "MPU6050.h" 
#include "systick.h"
#include "iic.h"
//struct _sensor sensor;
//u8		 mpu6050_buffer[14];					//iic读取后存放数据 
//*****************************************************************************************************
//向I2C设备写入一个字节数据
//*****************************************************************************************************
void Single_Write_Dev(u8 REG_Address,u8 REG_data)
{
    I2C_Start();                     //起始信号
    I2C_Send_Byte(MPU6050_ADDRESS);  //发送设备地址+写信号
	  I2C_Wait_Ack(); 
    I2C_Send_Byte(REG_Address);      //内部寄存器地址，
	  I2C_Wait_Ack(); 
    I2C_Send_Byte(REG_data);         //内部寄存器数据，
	  I2C_Wait_Ack(); 
    I2C_Stop();                      //发送停止信号
}
//*******************************************************************************************************
//从I2C设备读取一个字节数据
//*******************************************************************************************************
u8 Single_Read_Dev(u8 REG_Address)
{
	u8 REG_data;
	I2C_Start();                       //起始信号
	I2C_Send_Byte(MPU6050_ADDRESS);    //发送设备地址+写信号
	I2C_Wait_Ack(); 
	I2C_Send_Byte(REG_Address);        //发送存储单元地址，从0开始	
	I2C_Wait_Ack(); 
	I2C_Start();                       //起始信号
	I2C_Send_Byte(MPU6050_ADDRESS+1);  //发送设备地址+读信号
	I2C_Wait_Ack(); 
	REG_data=I2C_Read_Byte(0);         //读出寄存器数据 1-不响应应答信号
	I2C_Stop();                        //停止信号
	return REG_data;
}

//********初始化MPU6050**********
void Init_MUP6050()
{
  I2C_INIT();
	Single_Write_Dev(PWR_MGMT_1, 0x80);	//复位
	delay_ms(500);
	Single_Write_Dev(PWR_MGMT_1, 0x01);	//唤醒
	Single_Write_Dev(CONFIGL, 0x02);//低通滤波  0x01  5HZ   0x02 10hz
	Single_Write_Dev(SMPLRT_DIV, 0x04);//陀螺仪采样率，典型值：0x07(125Hz) 0X04 1/2	
	Single_Write_Dev(GYRO_CONFIG, 0x18);//陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)  16.4LSB
	Single_Write_Dev(ACCEL_CONFIG, 0x08);//加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，4G，5Hz)  8192LSB
		
}
//合成数据
u16 GetData(u8 REG_Address)
{
	u16 H,L;
	H=Single_Read_Dev(REG_Address);
	L=Single_Read_Dev(REG_Address+1);
	return ((H<<8)+L);   //合成数据
}

void data_div(u8 REG_Address, u8 *high , u8 *low)
{

	*high=Single_Read_Dev(REG_Address);
	*low=Single_Read_Dev(REG_Address+1);
	
}





