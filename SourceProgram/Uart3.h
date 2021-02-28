#ifndef __Uart3_H
#define __Uart3_H 
#include "STC8A.h"				       //单片机头文件（包含单片机的特殊功能寄存器的定义）	
	
extern uchar Uart3_Receive_i;		       //定义串行口3接收数据变量
extern bit Uart3_Receive_Flag;		     //定义串行口3接收数据完成标志位

extern void Uart3_Init(void);					      //串行口3使用定时器T2作为波特率发生器初始化函数
extern void Uart3_SendData(uchar dat);			//串行口3发送数据函数
extern void Uart3_SendString(uchar *s);		  //串行口3发送字符串函数

#endif

