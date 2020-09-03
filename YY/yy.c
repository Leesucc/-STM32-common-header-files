#include "YY.h"

u8 yy[20]={0xAA,0x08,0x0b,0x01,0x2F,0x30,0x30,0x30,0x30,0x31,0x2A,0X4D,0x50,0x33,0xD1};
u8 bf=0;

void ZYAW()
{
	yy[9]=0x31;
	yy[14]=0xD8;
	for(bf=0;bf<15;bf++)
	{
		USART_SendData(UART5,yy[bf]);
		while(USART_GetFlagStatus(UART5,USART_FLAG_TXE)==RESET);
	}
}

void QFHD()
{
	yy[9]=0x32;
	yy[14]=0xD9;
	for(bf=0;bf<15;bf++)
	{
		USART_SendData(UART5,yy[bf]);
		while(USART_GetFlagStatus(UART5,USART_FLAG_TXE)==RESET);
	}
}

void ZZAW()
{
	yy[9]=0x33;
	yy[14]=0xDA;
	for(bf=0;bf<15;bf++)
	{
		USART_SendData(UART5,yy[bf]);
		while(USART_GetFlagStatus(UART5,USART_FLAG_TXE)==RESET);
	}
}

void YZ()
{
	yy[9]=0x34;
	yy[14]=0xDB;
	for(bf=0;bf<15;bf++)
	{
		USART_SendData(UART5,yy[bf]);
		while(USART_GetFlagStatus(UART5,USART_FLAG_TXE)==RESET);
	}
}

void YZAW()
{
	yy[9]=0x35;
	yy[14]=0xDC;
	for(bf=0;bf<15;bf++)
	{
		USART_SendData(UART5,yy[bf]);
		while(USART_GetFlagStatus(UART5,USART_FLAG_TXE)==RESET);
	}
}

void ZZ()
{
	yy[9]=0x36;
	yy[14]=0xDD;
	for(bf=0;bf<15;bf++)
	{
		USART_SendData(UART5,yy[bf]);
		while(USART_GetFlagStatus(UART5,USART_FLAG_TXE)==RESET);
	}
}

void QFZAW()
{
	yy[9]=0x37;
	yy[14]=0xDE;
	for(bf=0;bf<15;bf++)
	{
		USART_SendData(UART5,yy[bf]);
		while(USART_GetFlagStatus(UART5,USART_FLAG_TXE)==RESET);
	}
}


 
