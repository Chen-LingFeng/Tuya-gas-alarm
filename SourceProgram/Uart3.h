#ifndef __Uart3_H
#define __Uart3_H 
#include "STC8A.h"				       //��Ƭ��ͷ�ļ���������Ƭ�������⹦�ܼĴ����Ķ��壩	
	
extern uchar Uart3_Receive_i;		       //���崮�п�3�������ݱ���
extern bit Uart3_Receive_Flag;		     //���崮�п�3����������ɱ�־λ

extern void Uart3_Init(void);					      //���п�3ʹ�ö�ʱ��T2��Ϊ�����ʷ�������ʼ������
extern void Uart3_SendData(uchar dat);			//���п�3�������ݺ���
extern void Uart3_SendString(uchar *s);		  //���п�3�����ַ�������

#endif

