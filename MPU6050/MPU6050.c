#include "MPU6050.h" 
#include "systick.h"
#include "iic.h"
//struct _sensor sensor;
//u8		 mpu6050_buffer[14];					//iic��ȡ�������� 
//*****************************************************************************************************
//��I2C�豸д��һ���ֽ�����
//*****************************************************************************************************
void Single_Write_Dev(u8 REG_Address,u8 REG_data)
{
    I2C_Start();                     //��ʼ�ź�
    I2C_Send_Byte(MPU6050_ADDRESS);  //�����豸��ַ+д�ź�
	  I2C_Wait_Ack(); 
    I2C_Send_Byte(REG_Address);      //�ڲ��Ĵ�����ַ��
	  I2C_Wait_Ack(); 
    I2C_Send_Byte(REG_data);         //�ڲ��Ĵ������ݣ�
	  I2C_Wait_Ack(); 
    I2C_Stop();                      //����ֹͣ�ź�
}
//*******************************************************************************************************
//��I2C�豸��ȡһ���ֽ�����
//*******************************************************************************************************
u8 Single_Read_Dev(u8 REG_Address)
{
	u8 REG_data;
	I2C_Start();                       //��ʼ�ź�
	I2C_Send_Byte(MPU6050_ADDRESS);    //�����豸��ַ+д�ź�
	I2C_Wait_Ack(); 
	I2C_Send_Byte(REG_Address);        //���ʹ洢��Ԫ��ַ����0��ʼ	
	I2C_Wait_Ack(); 
	I2C_Start();                       //��ʼ�ź�
	I2C_Send_Byte(MPU6050_ADDRESS+1);  //�����豸��ַ+���ź�
	I2C_Wait_Ack(); 
	REG_data=I2C_Read_Byte(0);         //�����Ĵ������� 1-����ӦӦ���ź�
	I2C_Stop();                        //ֹͣ�ź�
	return REG_data;
}

//********��ʼ��MPU6050**********
void Init_MUP6050()
{
  I2C_INIT();
	Single_Write_Dev(PWR_MGMT_1, 0x80);	//��λ
	delay_ms(500);
	Single_Write_Dev(PWR_MGMT_1, 0x01);	//����
	Single_Write_Dev(CONFIGL, 0x02);//��ͨ�˲�  0x01  5HZ   0x02 10hz
	Single_Write_Dev(SMPLRT_DIV, 0x04);//�����ǲ����ʣ�����ֵ��0x07(125Hz) 0X04 1/2	
	Single_Write_Dev(GYRO_CONFIG, 0x18);//�������Լ켰������Χ������ֵ��0x18(���Լ죬2000deg/s)  16.4LSB
	Single_Write_Dev(ACCEL_CONFIG, 0x08);//���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ�����ֵ��0x01(���Լ죬4G��5Hz)  8192LSB
		
}
//�ϳ�����
u16 GetData(u8 REG_Address)
{
	u16 H,L;
	H=Single_Read_Dev(REG_Address);
	L=Single_Read_Dev(REG_Address+1);
	return ((H<<8)+L);   //�ϳ�����
}

void data_div(u8 REG_Address, u8 *high , u8 *low)
{

	*high=Single_Read_Dev(REG_Address);
	*low=Single_Read_Dev(REG_Address+1);
	
}





