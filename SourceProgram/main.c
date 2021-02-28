#include "STC8A.h"     //STC8A单片机头文件（包含单片机的特殊功能寄存器的定义）
#include "Delay.h"     //延时函数头文件
#include "Uart3.h"     //串口三头文件
#include "wifi.h"      //wifi模块头文件
#include "Key.h"       //按键头文件
#include "MQ-5.h"      //燃气检测模块头文件
/************************函数声明*************************************/
void STC8A_IOinit(void);			//STC8A单片机引脚初始化函数

/************************变量定义*************************************/

/****************************************************************************************************
/*函数：void STC8A_IOinit(void)
/*功能：STC8A单片机引脚初始化函数
/*说明：统一将单片机所有引脚初始化为准双向口工作模式
/*修改日期：2021-02-22
/*作者：华南理工大学广州学院电工电子创新实验室——陈凌峰  
/****************************************************************************************************/
void STC8A_IOinit(void)
{
	P0M1 = 0;	P0M0 = 0;	//设置为准双向口
	P1M1 = 0;	P1M0 = 0;	//设置为准双向口
	P2M1 = 0;	P2M0 = 0;	//设置为准双向口
	P3M1 = 0;	P3M0 = 0;	//设置为准双向口
	P4M1 = 0;	P4M0 = 0;	//设置为准双向口
	P5M1 = 0;	P5M0 = 0;	//设置为准双向口
	P6M1 = 0;	P6M0 = 0;	//设置为准双向口
	P7M1 = 0;	P7M0 = 0;	//设置为准双向口 
//	P0 = 0XFF;	P1 = 0XFF;	P2 = 0XFF; 
//	P3 = 0XFF;	P4 = 0XFF;	P5 = 0XFF; 
//	P6 = 0XFF;	P7 = 0XFF;
}

/****************************************************************************************************
/*函数：void main()
/*功能：
/*说明：主函数
/*修改日期：2021-02-22
/*作者：华南理工大学广州学院电工电子创新实验室——陈凌峰  
/****************************************************************************************************/
void main()
{
	STC8A_IOinit();			      //STC8A单片机引脚初始化函数
	Uart3_Init();							//串行口3使用定时器T2作为波特率发生器初始化函数
	wifi_protocol_init();    	//wifi协议初始化函数
	while(1)
	{
		wifi_uart_service();    //wifi串口数据处理服务
		Scan_Key();             //按键接P4.0，切换smart模式（快闪）和AP模式（慢闪）
		Sensor_Scan();          //传感器检测。当检测到燃气时，蜂鸣器发出声音
		mcu_dp_bool_update(DPID_IS_AS_DETECTED,~P44);
		switch(mcu_get_wifi_work_state())					//配网指示
		{
			case SMART_CONFIG_STATE:
				P32=0;Delay_ms(100); 			//快闪：200ms闪烁一次
			P32=1;Delay_ms(100);				//Smart配置状态LED快闪，led闪烁请用户完成
			break;
			case AP_STATE:
				P32=0;Delay_ms(500);      //慢闪：1000ms闪烁一次
			P32=1;Delay_ms(500);				//AP配置状态LED慢闪，led闪烁请用户完成
			break;
			case WIFI_NOT_CONNECTED:
				P32=1;										//WIFI配完成，正在连接路由器，LED常暗
			break;
			case WIFI_CONNECTED:
				P32=0;										//路由器连接成功，LED常亮
			break;
			case WIFI_CONN_CLOUD:
				P32=0;										//wifi已连上云端，LED常亮
			default:break;
		}
	}
}

