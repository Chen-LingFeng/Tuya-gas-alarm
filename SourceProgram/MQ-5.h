#ifndef __MQ5_H_
#define __MQ5_H_

#include "STC8A.h"

/**********************
���ű�������
***********************/			
sbit Sensor_IN=P1^6; 	   //MQ-5��������

extern void Sensor_Scan(void);

extern uchar t;
#endif
