#include"public.h"
#include"railway.h"


void railway(int* page)
{
	int flag=0;
	
	cleardevice();
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	/*printf("\n%d",*page);
	getchar();*/
	Draw_railway();
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if (MouseX > 492 && MouseX < 619 && MouseY> 120 && MouseY < 145)
		{
			if (mouse_press(492,120,619,145) == 2)//查看涉疫列车未点击
			{
				MouseS = 1;
				if (flag== 0)//防止被重复标亮
				{
		            railway_Lighten(1);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(492, 120, 619, 145) == 1)//查看涉疫列车点击
			{
				MouseS = 0;
				railway_Lighten(1);
				*page=61;
				break;
			}
		}
		if (MouseX > 492 && MouseX < 619 && MouseY> 140+60 && MouseY < 165+60)
		{
			if (mouse_press(492, 140+60, 619, 165+60) == 2)//查看关联乘客未点击
			{
				MouseS = 1;
				if (flag== 0)//防止被重复标亮
				{
		            railway_Lighten(2);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(492, 140+60, 619, 165+60) == 1)//查看关联乘客点击
			{
				MouseS = 0;
				railway_Lighten(2);
				*page=62;
				break;
			}
		}
		
		
		if (MouseX > 525 && MouseX < 630 && MouseY> 450 && MouseY < 470)
		{
			if (mouse_press(525, 450, 630, 470) == 2)//点击退出未点击
			{
				MouseS=1;
				continue;
			}
			else if (mouse_press(525, 450, 630, 470) == 1)//点击退出点击
			{
				MouseS = 0;
				clrmous(MouseX, MouseY);
				*page =0;
				break;
				//切换到登录界面
			}
		}

        if (flag!= 0||MouseS!=0)
		{
			flag= 0; 
			MouseS = 0;
			railway_Darken();
	    }
	}
}

int Draw_railway()
{
	cleardevice();
	
	map();
	
	highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, LIGHTGREEN);
	highlight(472, 0, 639, 479, LIGHTGREEN);
	
	draw_date(474, 90, YELLOW, DARKGRAY);
	
	cover(492, 120, 619, 145, WHITE);
	highlight(492, 120, 619, 145, LIGHTRED);
	puthz(492 + 10, 126, "查看涉疫列车", 16, 19, LIGHTRED);
	//查看涉疫列车
   
	cover(492, 140+60, 619, 165+60, WHITE);
	highlight(492, 140+60, 619, 165+60, LIGHTRED);
	puthz(492 + 10, 146+60, "查看关联乘客", 16, 19, LIGHTRED);
	
	draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
	//退出
}


void draw_date(int x, int y, int linecolor,int wordcolor)//画当天的日期
{
	int a, b;
	char Y[5];
	char M[3];
	char D[3];
	struct tm* ptr;
	time_t lt;
	setcolor(linecolor);
	a = 2 + x;
	b = y - 40;
	lt = time(NULL);
	ptr = localtime(&lt);
	sprintf(Y, "%d", ptr->tm_year + 1900);
	sprintf(M, "%d", ptr->tm_mon + 1);
	sprintf(D, "%d", ptr->tm_mday);
	//乘车日期
	setcolor(linecolor);
	setlinestyle(1, 0, 3);
	//line(400, 26.5, 400 + 270, 26.5);
	puthz(a+13, b-15, "今天是：", 16, 17, wordcolor);
	//年填在(a+68,b,a+68+64,b+16)
	settextstyle(1, 0, 1);
	settextjustify(LEFT_TEXT, 0);
	outtextxy(a+15 , b+18, Y);
	puthz(a  + 64, b+5, "年", 16, 17, wordcolor);
	settextstyle(1, 0, 1);
	settextjustify(LEFT_TEXT, 0);
	outtextxy(a  + 64 + 23, b + 18, M);
	//月填在(a+68 + 64+17,b,a+68 + 64+17+28,b+16)
	puthz(a  + 64 + 17 + 17, b +5, "月", 16, 17, wordcolor);
	//日填在(a  + 64 + 17 + 28+17,b,a  + 64 + 17 + 28+17+28,b+16)
	settextstyle(1, 0, 1);
	settextjustify(LEFT_TEXT, 0);
	if(strlen(D)==2)
	{
	    outtextxy(a  + 64 + 17 + 28 + 6, b + 18, D);
	}
	else 
	{
		outtextxy(a  + 64 + 17 + 28 + 12, b + 18, D);
	}
	puthz(a  + 64 + 17 + 28 + 26, b+5 , "日", 16, 19, wordcolor);
}

/*
FUNCTION:地铁管理员界面按钮点亮
INPUT：点亮控制变量flag
RETURN:无
*/
int railway_Lighten(int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	switch(flag)
	{
		case 1:
		setfillstyle(1, WHITE);
		setcolor(CYAN);
		bar(492, 120, 619, 145);
		cover(492, 120, 619, 145, WHITE);
	    highlight(492, 120, 619, 145, LIGHTMAGENTA);
		puthz(492 + 10, 126, "查看涉疫列车", 16, 19, LIGHTMAGENTA);
		break;
	    
	    case 2:
		setfillstyle(1, WHITE);
		setcolor(CYAN);
		bar(492, 140+60, 619, 165+60);
	    cover(492, 140+60, 619, 165+60, WHITE);
	    highlight(492, 140+60, 619, 165+60, LIGHTMAGENTA);
		puthz(492 + 10, 146+60, "查看关联乘客", 16, 19, LIGHTMAGENTA);
		break;
	    
		/*case 3:
		setfillstyle(1, WHITE);
		setcolor(CYAN);
		bar(492, 160+120, 619, 185+120);
	    cover(492, 160+120, 619, 185+120, WHITE);
	    highlight(492, 160+120, 619, 185+120, LIGHTMAGENTA);
		puthz(492 + 10, 166+120, "调整运行时刻", 16, 19, LIGHTMAGENTA);
		break;*/
	}
}

int railway_Darken()
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, WHITE);
	
	cover(492, 120, 619, 145, WHITE);
	highlight(492, 120, 619, 145, LIGHTRED);
	puthz(492 + 10, 126, "查看涉疫列车", 16, 19, LIGHTRED);
	
	cover(492, 140+60, 619, 165+60, WHITE);
	highlight(492, 140+60, 619, 165+60, LIGHTRED);
	puthz(492 + 10, 146+60, "查看关联乘客", 16, 19, LIGHTRED);
	
	/*cover(492, 160+120, 619, 185+120, WHITE);
	highlight(492, 160+120, 619, 185+120, LIGHTRED);
	puthz(492 + 10, 166+120, "调整运行时刻", 16, 19, LIGHTRED);*/
}



