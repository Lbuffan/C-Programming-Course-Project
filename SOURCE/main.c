#include"public.h"
#include"login.h"
#include"plogin.h"
#include"alogin.h"
#include"register.h"
/*
FUNCTION:main
DESCRIPTION:实现页面跳转
INPUT:no
RETURN:no
*/
void main()
{
	int page=6;//页面跳转变量
	int ad=0; //判断管理员身份，1为地铁部门，2为卫生部门
	int identity=0; //记录登录乘客的身份	 
	int gd=VGA;
	int gm=VGAHI;
	ADMINISTRATOR AD[2];
	Scan_A(AD); //读入管理员信息
	//printf("hi\n");
	initgraph(&gd,&gm,"C:\\BORLANDC\\BGI");
	cleardevice();
	//welcome();//欢迎页面 
	//Build_State();
	//delay(1000);  
	mouseinit();//鼠标初始化 
	while(1)//页面跳转
	{
		switch (page)
		{
			case 0://登录界面
				Login(&page,&ad);
				break;
			case 1://乘客登录界面
				Plogin(&page,&identity);
				break;
			case 2://管理员登录
				Alogin(&page,ad,AD);  
				break;
			case 3:  //注册界面
			    Register(&page);  
				break;
			case 5: //乘客登录界面
			    Pass(&page,identity);      
				break;
			case 51: //乘客查看轨迹
				pass1(&page,identity);
				break;
			case 6://铁路部门界面
			    railway(&page);
				break;
			case 61: //查看涉疫列车
			    Checksub(&page);
				break;
			case 62: //查找关联乘客
				Cpass(&page);
				break;
			case 7://卫生部门界面
				Weisheng(&page);
				break;
			case 71://标记患者界面
				Sign(&page);
				break;
			case 72://查看患者
				Patient(&page);
				break;
			case 73: //查看密接
				Connect(&page);
				break;
		}
		
	}
	
}

