#ifndef __MQ5_H_
#define __MQ5_H_

#include "STC8A.h"

/**********************
引脚别名定义
***********************/			
sbit Sensor_IN=P1^6; 	   //MQ-5传感器用

extern void Sensor_Scan(void);

extern uchar t;
#endif
