#include "public.h"
#include "alogin.h"
#include "input.h"
/*
FUNCTION:Alogin
DESCRIPTION:管理员登录
INPUT:page,ad,AD
RETURN:no
*/
void Alogin(int *page,int ad,ADMINISTRATOR *AD)
{
	int pos1=0;				//判断输入框1的输入情况
	int pos2=0;
	int flag=0;
	int jun1=-1;
	int jun2=0;
	char c;				//选择不同的管理员登录端
	char A[10]={'\0'};				//账号，6-12位
	char P[10]={'\0'};				//设置密码，6-12位
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	switch(ad)				//通过不同ad值绘制不同登陆界面
	{
		case 1:
			Draw_Alogin1();
			c='1';
			break;
		case 2:
			Draw_Alogin2();
			c='2';
			break;			
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>95&&MouseX<545&&MouseY>205&&MouseY<230)
		{
			if(mouse_press(95,205,545,230)==2)
			{
				MouseS=2;
				if(flag==0&&pos1==0)
				{
					Alogin_Lighten(95,205,545,230,1);
					flag=1;
				}
				continue;
			}
			else if(mouse_press(95,205,545,230)==1)
			{
				Alogin_Lighten(95,205,545,230,1);
				MouseS=0;
				A[0]='\0';
				setfillstyle(1,DARKGRAY);
				bar(550,210,640,226);
				Input_Vis(A,95,205,10,LIGHTGRAY);
				if(strlen(A)!=0)
				{
					pos1=1;
				}
				else{
					pos1=0;
				}
				continue;
			}
		}
		if(MouseX>95&&MouseX<545&&MouseY>260&& MouseY<290)
		{
			if(mouse_press(95,265,545,290)==2)
			{
				MouseS=2;
				if(flag==0&&pos2==0)
				{
					Alogin_Lighten(95,265,545,290,2);
					flag=2;
				}
				continue;
			}

			else if(mouse_press(95,265,545,290)==1)
			{
				Alogin_Lighten(95,265,545,290,2);
				MouseS=0;
				P[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				Input_Invis(P,95,265,10,LIGHTGRAY);
				if(strlen(P)!=0)
					pos2=1;
				else 
					pos2=0;
				continue;
			}
		}
		
		if(MouseX>260&&MouseX<380&&MouseY>310&& MouseY<345)
		{
			if(mouse_press(260,310,380,345)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Alogin_Lighten(260,310,380,345,3);
					flag=3;
				}
				continue;
			}

			else if(mouse_press(260,310,380,345)==1)
			{
				Alogin_Lighten(260,310,380,345,3);
				MouseS=0;
				if(Alogin_Com(AD,A,P,c))
				{
				    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, WHITE);
		            puthz(274,220,"正在登录",24,24,RED);
					stablack(282,270,3);
					stablack(282,270,3);
					delay(500);
					stablack(320,270,3);
					delay(500);
					stablack(358,270,3);
					delay(500);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, WHITE);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, WHITE);
		            puthz(274,230,"登录成功",24,24,RED);
		            delay(3000);
					switch(ad)
	                {
		                case 1:
		                    *page=6;
			                break;
		                case 2:
		                    *page=7;
			                break;
					}
				    break;
	            }
				else
				{
					setfillstyle(1,DARKGRAY);
		            bar(175,295+12,500,345+12);
		            puthz(265,320+12,"登录失败！",24,24,RED);
					delay(3000);
				}
				continue;
			}
		}
		
		if(MouseX>480&&MouseX<538&&MouseY>380&& MouseY<405)
		{
			if(mouse_press(480,380,538,405)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Alogin_Lighten(480,380,538,405,4);
					flag=4;
				}
				continue;
			}

			else if(mouse_press(480,380,538,405)==1)
			{
				Alogin_Lighten(480,380,538,405,4);
				MouseS=0;
				*page=0;
				break;
			}
		}
	
		if(flag!=0)                                 //根据点亮情况，对输入框进行还原
		{
			MouseS=0;
			if(pos1==0)
			{
				Alogin_Darken(1);
			}
			if (pos2==0)
			{
				Alogin_Darken(2);
			}
			if (flag==3||flag ==4)
			{
				Alogin_Darken(flag);
			}
			flag=0;
		}
		if(MouseS!=0)                               //还原鼠标
		{                 
			MouseS=0;
		}
	}
	
}
/*
FUNCTION:Draw_Alogin1
DESCRIPTION:绘制地铁部门登陆界面
INPUT:NO
RETURN:NO
*/
int Draw_Alogin1()
{
	cleardevice();
	setbkcolor(DARKGRAY);

	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(LIGHTGRAY);
	circle(320,130,50);
	setfillstyle(SOLID_FILL, WHITE);
	setcolor(WHITE);
	floodfill(315,135,LIGHTGRAY);
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	bar(320-30,130-30,320+30,130+30);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	bar(320-25,130-25,320+25,130);
	setfillstyle(1,WHITE);
	pieslice(320-18,130+20,0,360,5);
	pieslice(320+18,130+20,0,360,5);
	
	setfillstyle(1,GREEN);
	bar(0,0,640,60);
	puthz(165,15,"地铁部门管理系统",32,40,LIGHTGRAY);
	
	puthz(95,180,"账号",16,16,CYAN);
	puthz(95,240,"密码",16,16,CYAN);
	
	setfillstyle(1,WHITE);
	bar(95,205,545,230);
	bar(95,265,545,290);
	
	setfillstyle(1,RED);
	bar(260,310+12,380,345+12);
	puthz(290,315+12,"登录",24,34,WHITE);
	
	setfillstyle(1,WHITE);
	setlinestyle(0,0,3);
	setcolor(LIGHTBLUE);
	
	bar(480,380,538,405);
	puthz(492,385,"返回",16,18,LIGHTBLUE);
	rectangle(480,380,538,405);
}
/*
FUNCTION:Draw_Alogin2
DESCRIPTION:绘制卫生部门登陆界面
INPUT:NO
RETURN:NO
*/
int Draw_Alogin2()
{
	cleardevice();
	setbkcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(GREEN);
	setfillstyle(1,GREEN);
	pieslice(320,130,0,360,50);
	line(320,130,370,130);
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	bar(310,100,330,160);
	bar(290,120,350,140);
	setfillstyle(1,GREEN);
	bar(0,0,640,60);
	puthz(165,15,"卫生部门管理系统",32,40, LIGHTGRAY);
	setfillstyle(1,LIGHTBLUE);
	setcolor(LIGHTGREEN);
	
	puthz(95,180,"账号",16,16,CYAN);        
	puthz(95,240,"密码",16,16,CYAN);

	setfillstyle(1,WHITE);                     
    bar(95,205,545,230);
	bar(95,265,545,290);

	setfillstyle(SOLID_FILL, RED);
	bar(260,310+12,380,345+12);
	puthz(290,315+12,"登录",24,34,WHITE);
	
    setlinestyle(SOLID_LINE,0,1);
	setfillstyle(SOLID_FILL,WHITE);
	setlinestyle(SOLID_LINE,0,2);
	setcolor(LIGHTBLUE);


	bar(480,380,538,405);
	puthz(492,385,"返回",16,18,LIGHTBLUE);
	rectangle(480,380,538,405);
	
}
/*
FUNCTION:Alogin_Lighten
DESCRIPTION:按钮点亮
INPUT:坐标及点亮控制变量flag
RETURN:NO
*/
int Alogin_Lighten(int x1,int y1,int x2,int y2,int flag)
{
	clrmous(MouseX,MouseY);
	delay(10);

	if(flag==3)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(SOLID_FILL,LIGHTRED);
	    bar(260,310+12,380,345+12);
	    puthz(290,315+12,"登录",24,34,WHITE);//登录框
	}

	else if(flag==4)
	{
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(480,380,538,405);
	    puthz(492,385,"返回",16,18,CYAN);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(CYAN);
	    rectangle(480,380,538,405);
	}
	else 
	{
		setcolor(MAGENTA);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,LIGHTGRAY);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
	}
}

/*
FUNCTION:Alogin_Darken
DESCRIPTION:管理员登录界面按钮恢复
INPUT:点亮控制变量pos
RETURN:无
*/
int Alogin_Darken(int pos)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	switch (pos)
	{
	case 1:
		bar(95,205,545,230);
		break;
	case 2:
		bar(95,265,545,290);
		break;
	case 3:
		setfillstyle(SOLID_FILL, RED);
	    bar(260,310+12,380,345+12);
	    puthz(290,315+12,"登录",24,34,WHITE);
		break;
	case 4:
	    setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(480,380,538,405);
	    puthz(492,385,"返回",16,18,LIGHTBLUE);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(480,380,538,405);
	}
}

/*
FUNCTION:Alogin_Com
DESCRIPTION:完成管理员登录
INPUT:账号密码判断结果jun1,jun2
RETURN:判断结果
*/
int Alogin_Com(struct Administrator* A,char* account,char* password,char unit)
{
	int i;
	for(i=0;i<15;i++)
	{
		if(A->unit==unit&&strcmp(A->account,account)==0)
		{
			if(strcmp(A->password,password)==0)
			{
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
		        puthz(550,270,"密码正确",16,16,RED);
		        return 1;
			}
			else
			{
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
		        puthz(550,270,"密码错误",16,16,RED);
		        return 0;
			}
		}
		A++;
	}
	setfillstyle(1,DARKGRAY);
	bar(550,210,640,226);
	puthz(550,210,"账号错误",16,16,RED);
	return 0;
}