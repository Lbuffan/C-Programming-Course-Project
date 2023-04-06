#include "public.h"
#include "weisheng.h"
/*
FUNCTION:Weisheng
DESCRIPTION:实现卫生部门选择功能
INPUT:界面跳转控制变量page
RETURN:无
*/
void Weisheng(int* page)
{
	int flag = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	save_bk_mou(MouseX, MouseY);
	Draw_Weisheng();
	


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
					Weisheng_Lighten(1);
					flag = 1;
				}
				continue;
			}

			else if (mouse_press(210, 80, 430, 160) == 1)
			{
				MouseS = 0;
				clrmous(MouseX, MouseY);
				*page =71;//跳转至标记患者
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
					Weisheng_Lighten(2);
					flag = 2;
				}
				continue;
			}

			else if (mouse_press(210, 200, 430, 280) == 1)
			{
				MouseS = 0;
				*page = 72;//跳转至查看患者
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
					Weisheng_Lighten(3);
					flag = 3;
				}
				continue;
			}

			else if (mouse_press(210,320,430,400) == 1)
			{
				MouseS = 0;
				*page = 73;//跳转至查看密接
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
				*page=0;
				break;
			}
		}


		if (flag != 0)
		{
			Weisheng_Darken(flag);
			flag = 0;
		}


		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*
FUNCTION:WEISHENG
DESCEIPTION:绘制卫生部门界面
INPUT:NO
RETURN:NO
*/
int Draw_Weisheng()
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
	puthz(260,104,"标记患者",32,32,DARKGRAY);
	puthz(260,224, "查看患者", 32, 32,DARKGRAY);
	puthz(260,344, "查看密接", 32, 32,DARKGRAY);
	draw_exit(497, 420, LIGHTGREEN, WHITE, BLUE, GREEN);
	return 0;
}
/*
FUNCTION:Weisheng_Lighten
DESCRIPTION:登录选择界面按钮点亮
INPUT:点亮控制变量flag
RETURN:无
*/
int Weisheng_Lighten(int flag)
{
	switch(flag)
	{
		case 1:
		{
		    puthz(260,104,"标记患者",32,32,WHITE);
			break;
		}
		case 2:
		{
			puthz(260,224,"查看患者",32,32,WHITE);
			break;
		}
		case 3:
		{
			puthz(260,344,"查看密接",32,32,WHITE);
			break;
		}
	}
}
/*
FUNCTION:Weisheng_Darken
DESCRIPTION:登录选择界面按钮恢复
INPUT:恢复控制变量flag
RETURN:无
*/
int Weisheng_Darken(int flag)
{
	switch (flag)
	{
	  
	  case 1:
	  {
		puthz(260, 104, "标记患者", 32, 32, DARKGRAY);
		break;
	  }
	  
	  case 2:
	  {
		puthz(260, 224, "查看患者", 32, 32, DARKGRAY);
		break;
	  }
	  
	  case 3:
	  {
		puthz(260, 344, "查看密接", 32, 32, DARKGRAY);
		break;
	  }

	}
}

