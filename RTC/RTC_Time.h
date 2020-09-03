/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               RTC_Time.h
** Descriptions:            None
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-10-30
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

#ifndef _RTC_TIME_H_
#define _RTC_TIME_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

extern int UDP_year;
extern int UDP_mon;
extern int UDP_mday;
extern int UDP_hour;
extern int UDP_min;
extern int UDP_sec;

extern int RTC_year;
extern int RTC_mon;
extern int RTC_mday;
extern int RTC_hour;
extern int RTC_min;
extern int RTC_sec;

/* Private function prototypes -----------------------------------------------*/
void RTC_Init(u8 RTC_temp);
void Time_get(void);
void Time_Regulate(void);

/* Private variables ---------------------------------------------------------*/
extern FunctionalState TimeDisplay;

#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
