#include "gps.h" 
#include "sys.h" 	   
#include "stdio.h"	 
#include "stdarg.h"	 
#include "string.h"	 
#include "math.h"
	   


//��buf����õ���cx���������ڵ�λ��
//����ֵ:0~0XFE,����������λ�õ�ƫ��.
//       0XFF,�������ڵ�cx������			

u8 NMEA_Comma_Pos(u8 *buf,u8 cx)
{	 		    
	u8 *p=buf;
	while(cx)
	{		 
		if(*buf=='*'||*buf<' '||*buf>'z')return 0XFF;//����'*'���߷Ƿ��ַ�,�򲻴��ڵ�cx������
		if(*buf==',')cx--;
		buf++;
	}
	return buf-p;	 
}
//m^n����
//����ֵ:m^n�η�.
u32 NMEA_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}
//strת��Ϊ����,��','����'*'����
//buf:���ִ洢��
//dx:С����λ��,���ظ����ú���
//����ֵ:ת�������ֵ
int NMEA_Str2num(u8 *buf,u8*dx)
{
	u8 *p=buf;
	u32 ires=0,fres=0;
	u8 ilen=0,flen=0,i;
	u8 mask=0;
	int res;
	while(1) //�õ�������С���ĳ���
	{
		if(*p=='-'){mask|=0X02;p++;}//�Ǹ���
		if(*p==','||(*p=='*'))break;//����������
		if(*p=='.'){mask|=0X01;p++;}//����С������
		else if(*p>'9'||(*p<'0'))	//�зǷ��ַ�
		{	
			ilen=0;
			flen=0;
			break;
		}	
		if(mask&0X01)flen++;
		else ilen++;
		p++;
	}
	if(mask&0X02)buf++;	//ȥ������
	for(i=0;i<ilen;i++)	//�õ�������������
	{  
		ires+=NMEA_Pow(10,ilen-1-i)*(buf[i]-'0');
	}
	if(flen>5)flen=5;	//���ȡ5λС��
	*dx=flen;	 		//С����λ��
	for(i=0;i<flen;i++)	//�õ�С����������
	{  
		fres+=NMEA_Pow(10,flen-1-i)*(buf[ilen+1+i]-'0');
	} 
	res=ires*NMEA_Pow(10,flen)+fres;
	if(mask&0X02)res=-res;		   
	return res;
}	  							 
//����GPGSV��Ϣ
//gpsx:nmea��Ϣ�ṹ��
//buf:���յ���GPS���ݻ������׵�ַ



//����GNRMC��Ϣ
//gpsx:nmea��Ϣ�ṹ��
//buf:���յ���GPS���ݻ������׵�ַ
void NMEA_GNRMC_Analysis(u8 *gpsx,u8 *buf)
{
	u8 *p1,dx;		 
	u8 posx;     
	u32 temp;	  
	u8 d=0;
	u8 m=0;
	u32 s=0;
	p1=(u8*)strstr((const char *)buf,"$GNRMC");//"$GNRMC",������&��GNRMC�ֿ������,��ֻ�ж�GPRMC.
//	posx=NMEA_Comma_Pos(p1,1);								//�õ�UTCʱ��
//	if(posx!=0XFF)
//	{
//		temp=NMEA_Str2num(p1+posx,&dx)/NMEA_Pow(10,dx);	 	//�õ�UTCʱ��,ȥ��ms
//		gpsx->utc.hour=temp/10000;
//		gpsx->utc.min=(temp/100)%100;
//		gpsx->utc.sec=temp%100;	 	 
//	}	
	posx=NMEA_Comma_Pos(p1,3);								//�õ�γ��
	if(posx!=0XFF)
	{	
		temp=NMEA_Str2num(p1+posx,&dx);	
		d=temp/NMEA_Pow(10,dx+2);
		m=temp%NMEA_Pow(10,dx+2)/NMEA_Pow(10,dx);
		s=temp%NMEA_Pow(10,dx);
		gpsx[2]=d;
		gpsx[3]=m;
		gpsx[4]=s>>16;
		gpsx[5]=s>>8;
		gpsx[6]=s;
		gpsx[7]=dx;


	}
			 
 	posx=NMEA_Comma_Pos(p1,5);								//�õ�����
	if(posx!=0XFF)
	{												  
		temp=NMEA_Str2num(p1+posx,&dx);		 	
		d=temp/NMEA_Pow(10,dx+2);
		m=temp%NMEA_Pow(10,dx+2)/NMEA_Pow(10,dx);
		s=temp%NMEA_Pow(10,dx);
		
		gpsx[8]=d;
		gpsx[9]=m;
		gpsx[10]=s>>16;
		gpsx[11]=s>>8;
		gpsx[12]=s;
		gpsx[13]=dx;

	}
	 
//	posx=NMEA_Comma_Pos(p1,9);								//�õ�UTC����
//	if(posx!=0XFF)
//	{
//		temp=NMEA_Str2num(p1+posx,&dx);		 				//�õ�UTC����
//		gpsx->utc.date=temp/10000;
//		gpsx->utc.month=(temp/100)%100;
//		gpsx->utc.year=2000+temp%100;	 	 
//	} 
}

