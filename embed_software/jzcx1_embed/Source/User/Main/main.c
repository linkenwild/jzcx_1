/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
**  电子气味嵌入式软件
**	整体系统代码
**  版本：Rev1.0 
**  日期：2015-12-25
**	淘宝：http://shop36995246.taobao.com/   
**  技术QQ:1482755485
**  Copyright(c)@今朝创新	xuhaiyang88@163.com
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
 
//头文件调用
#include "usually.h"
#include "usart.h"  
#include "rc522.h"
#include "led.h"
#include "fans.h"
#include "ultrasonic.h"
#include "timer.h"
#include "ble.h"
#include "user_sys_config.h"




/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
** 函数名称: main
** 功能描述: 主函数入口
** 参数描述：这个程序演示了串口收发程序 ，接收是采用中断方式
				你可以输入键盘上的任意值 电脑超级终端将以十进制输出你输入的数值 
				比如：1对应十进制是49；2对应于50；a对应于97；这个你懂！！！
** 作  　者: Dream
** 日　  期: 2011年6月20日
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
int main(void)
{
	SystemInit();					//系统时钟配置
	Init_NVIC();					//中断向量表注册函数
	
	Init_Usart();					//串口引脚配置
	Init_Rc522();					//初始化RFID
	Init_TIMER();				//定时器初始化
	Init_Ble();					//初始化蓝牙模块
	Init_Fans();				//初始化风扇
	Init_Ultrasonic();  //初始化超声波
	Init_LED();						//各个外设引脚配置
	
	Usart_Configuration(115200);	//串口配置 设置波特率为115200
	   
	while(1)													
	{  
		LED1=~LED1;	   				
		Delay_Ms(200);				 //LED1闪烁，系统正在运行
	}
}


/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
End:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D:-D
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
