#include"public.h"
#include"Login.h"




/*
FUNCTION:Login
DESCRIPTION:实现登录选择功能
INPUT:界面跳转控制变量page,管理员所属部门ad
RETURN:无
*/
void Login(int* page, int* ad)
{
	int flag = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	save_bk_mou(MouseX, MouseY);
	Draw_Login();
	


	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);


		if (MouseX > 210 && MouseX < 430 && MouseY>80 && MouseY < 160)//鼠标
		{

			if (mouse_press(210, 80, 430, 160) == 2)
			{
				MouseS = 1;
				if (flag == 0);
				{
					Login_Light(1);
					flag = 1;
				}
				continue;
			}

			else if (mouse_press(210, 80, 430, 160) == 1)
			{
				MouseS = 0;
				clrmous(MouseX, MouseY);
				*page = 1;//跳转至乘客
				break;
			}
		}


		if (MouseX > 210 && MouseX < 430 && MouseY>200 && MouseY < 280)
		{

			if (mouse_press(210, 200, 430, 280) == 2)
			{
				MouseS = 1;
				if (flag == 0);
				{
					Login_Light(2);
					flag = 2;
				}
				continue;
			}

			else if (mouse_press(210, 200, 430, 280) == 1)
			{
				MouseS = 0;
				*ad = 1;
				*page = 2;//跳转至地铁
				break;
			}
		}


		if (MouseX > 210 && MouseX < 430 && MouseY>320 && MouseY < 400)//鼠标
		{

			if (mouse_press(210,320,430,400) == 2)
			{
				MouseS = 1;
				if (flag == 0);
				{
					Login_Light(3);
					flag = 3;
				}
				continue;
			}

			else if (mouse_press(210,320,430,400) == 1)
			{
				MouseS = 0;
				*ad = 2;
				*page = 2;//跳转至卫生
				break;
			}
		}


		if (MouseX > 492 && MouseX < 597 && MouseY>417 && MouseY < 437)//鼠标
		{

			if (mouse_press(492, 417, 597, 437) == 2)
			{
				MouseS = 1;
				continue;
			}

			else if (mouse_press(492, 417, 597, 437) == 1)
			{
				MouseS = 0;
				bye();
				delay(3000);
				exit(1);
				break;
			}
		}


		if (flag != 0)
		{
			Login_Darken(flag);
			flag = 0;
		}


		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}




/*
FUNCTION:Draw_Login
DESCRIPTION:绘制登录选择界面
INPUT:无
RETURN:无
*/
int Draw_Login()
{
	cleardevice();
	setbkcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(WHITE);
	rectangle(210,80,430,160);
	rectangle(210,200,430,280);
	rectangle(210,320,430,400);
	setfillstyle(1,GREEN);
	floodfill(300,100,WHITE);
	floodfill(300,240,WHITE);
	floodfill(300,380,WHITE);
	puthz(285,104,"乘客",32,32,DARKGRAY);
	puthz(260, 224, "地铁部门", 32, 32,DARKGRAY);
	puthz(260, 344, "卫生部门", 32, 32,DARKGRAY);
	draw_exit(497, 420, LIGHTGREEN, WHITE, BLUE, GREEN);
	return 0;
}




/*
FUNCTION:Login_Lighten
DESCRIPTION:登录选择界面按钮点亮
INPUT:点亮控制变量flag
RETURN:无
*/
int Login_Light(int flag)
{
	switch(flag)
	{
		case 1:
		{
		    puthz(285,104,"乘客",32,32,WHITE);
			break;
		}
		case 2:
		{
			puthz(260,224,"地铁部门",32,32,WHITE);
			break;
		}
		case 3:
		{
			puthz(260,344,"卫生部门",32,32,WHITE);
			break;
		}
	}
}




/*
FUNCTION:Login_Darken
DESCRIPTION:登录选择界面按钮恢复
INPUT:恢复控制变量flag
RETURN:无
*/
int Login_Darken(int flag)
{
	switch (flag)
	{
	  
	  case 1:
	  {
		puthz(285, 104, "乘客", 32, 32, DARKGRAY);
		break;
	  }
	  
	  case 2:
	  {
		puthz(260, 224, "地铁部门", 32, 32, DARKGRAY);
		break;
	  }
	  
	  case 3:
	  {
		puthz(260, 344, "卫生部门", 32, 32, DARKGRAY);
		break;
	  }

	}
}
