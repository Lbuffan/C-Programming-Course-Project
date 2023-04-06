#include"public.h"
#include"plogin.h"
/*
FUNCTION:Plogin
DESCRIPTION:实现乘客登录功能
INPUT:界面跳转控制变量page，乘客代号identity
RETURN:无
*/
void Plogin(int* page,int* identity)
{
	int i;
	int pos1=0;                                             //判断输入框1输入情况
	int pos2=0;                                             //判断输入框2输入情况
	int flag=0;                                             //标记点亮情况
	char account[15];
	char password[15];
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Plogin();                                          //画乘客登录界面
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);                   //画鼠标
		if(MouseX>95&&MouseX<545&&MouseY>205&& MouseY<230)  //账号框
		{
			if(mouse_press(95,205,545,230) == 2)    
			{
				MouseS=2;
				if(flag==0&&pos1==0)
				{
					Plogin_Lighten(95,205,545,230,1);
					flag=1;
				}
				continue;
			}

			else if(mouse_press(95,205,545,230)==1)      
			{
				Plogin_Lighten(95,205,545,230,1);
				MouseS = 0;
				account[0]='\0';                            
				setfillstyle(1,DARKGRAY);
		        bar(550,210,640,276);
				Input_Vis(account,95,205,16,LIGHTGRAY);  //账号输入 
				if(strlen(account)!=0)
					pos1=1;
				else
					pos1=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>260&& MouseY<290) //密码框
		{
			if(mouse_press(95,265,545,290)==2)      
			{
				MouseS=2;
				if(flag==0&&pos2==0)
				{
					Plogin_Lighten(95,265,545,290,2);
					flag=2;
				}
				continue;
			}

			else if(mouse_press(95,265,545,290)==1)
			{
				Plogin_Lighten(95,265,545,290,2);
				MouseS=0;
				password[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				Input_Invis(password,95,265,16,LIGHTGRAY);//密码输入
				if(strlen(password)!=0)
					pos2=1;
				else 
					pos2=0;
				continue;
			}
		}
		
		if(MouseX>260&&MouseX<380&&MouseY>310+12&& MouseY<345+12)//登录框
		{
			if(mouse_press(260,310+12,380,345+12)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Plogin_Lighten(260,310+15,380,345+15,3);
					flag=3;
				}
				continue;
			}

			else if(mouse_press(260,310+12,380,345+12)==1)
			{
				Plogin_Lighten(260,310+12,380,345,3);
				MouseS=0;
				if(Jundge_Plogin(account,password,&i))//进行登录判断，并返回用户身份
				{
					*identity=i;
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
		            //printf("%d\n",*identity); getchar();
					delay(3000);
					*page=5;                                       //跳转至乘客功能界面
					break;
				}
				else
				{
					setfillstyle(1,DARKGRAY);
		            bar(175,295+12,500,345+12);
		            puthz(265,320+12,"登录失败！",24,24,RED);
					delay(3000);
					return ;
				}
				continue;
			}
		}
		
		if(MouseX>290&&MouseX<350&&MouseY>380&& MouseY<405)//注册框
		{
			if(mouse_press(290,380,350,405)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Plogin_Lighten(290,380,350,405,4);
					flag=4;
				}
				continue;
			}

			else if(mouse_press(290,380,350,405)==1)
			{
				Plogin_Lighten(290,380,350,405,4);
				MouseS=0;
				*page=3;                                    //跳转至注册界面
				break;
			}
		}
		
        if(MouseX>100&&MouseX<169&&MouseY>380&& MouseY<405)//返回框
		{
			if(mouse_press(100,380,169,405)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Plogin_Lighten(100,380,169,405,5);
					flag=5;
				}
				continue;
			}

			else if(mouse_press(100,380,169,405)==1)
			{
				Plogin_Lighten(100,380,169,405,5);
				MouseS=0;
				*page=0;                                   //跳转至主登录界面
				break;
			}
		}
		
		/*if(MouseX>480&&MouseX<570&&MouseY>380&& MouseY<405)//忘修改密码框
		{
			if(mouse_press(480,380,570,405)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Plogin_Lighten(480,380,570,405,6);
					flag=6;
				}
				continue;
			}

			else if(mouse_press(480,380,570,405)==1)
			{
				Plogin_Lighten(480,380,570,405,6);
				MouseS=0;
				*page=4;                                   //跳转至修改密码界面
				break;
			}
		}*/
	
		if(flag!=0)                                       //根据点亮情况，对操作框进行还原
		{
			MouseS=0;
			if(pos1==0)
			{
				Plogin_Darken(1);
			}
			if (pos2==0)
			{
				Plogin_Darken(2);
			}
			if (flag==3||flag ==4||flag ==5||flag==6)
			{
				Plogin_Darken(flag);
			}
			flag=0;
		}
		if(MouseS!=0)                                     //还原鼠标
		{                 
			MouseS=0;
		}
	}
}

/*
FUNCTION:Draw_Plogin
DESCRIPTION:绘制乘客登录界面
INPUT:无
RETURN:无
*/
int Draw_Plogin()
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
	puthz(165,15,"乘客行程管理系统",32,40, LIGHTGRAY);
	setfillstyle(1,LIGHTBLUE);

	puthz(95,180,"请输入账号",16,16,CYAN);        //画输入提示
	puthz(95,240,"请输入密码",16,16,CYAN);

	setfillstyle(1,WHITE);                     
    bar(95,205,545,230);
	bar(95,265,545,290);

	setfillstyle(SOLID_FILL, RED);
	bar(260,310+12,380,345+12);
	puthz(290,315+12,"登录",24,34,WHITE);//登录框

	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(SOLID_FILL,WHITE);
	bar(290,380,350,405);
	puthz(302,385,"注册",16,24,LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,2);
	setcolor(LIGHTBLUE);
	rectangle(290,380,350,405);//注册框

	bar(100,380,169,405);
	puthz(114,385,"返回",16,24,LIGHTBLUE);//返回框
	rectangle(100,380,169,405);

/*	bar(480,380,570,405);
	puthz(492,385,"修改密码",16,18,LIGHTBLUE);//修改密码框
	rectangle(480,380,570,405);*/
}

/*
FUNCTION:Plogin_Lighten
DESCRIPTION:乘客登录界面按钮点亮
INPUT:点亮控制变量flag
RETURN:无
*/
int Plogin_Lighten(int x1,int y1,int x2,int y2,int flag)//操作框点亮
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
	    bar(290,380,350,405);
	    puthz(302,385,"注册",16,24,CYAN);
	    setlinestyle(SOLID_LINE,0,2);
	    setcolor(CYAN);
	    rectangle(290,380,350,405);//注册框
	}
	else if(flag==5)
	{
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(100,380,169,405);
	    puthz(114,385,"返回",16,24,CYAN);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(CYAN);
	    rectangle(100,380,169,405);//返回框
	}
	/*else if(flag==6)
	{
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(480,380,570,405);
	    puthz(492,385,"修改密码",16,18,CYAN);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(CYAN);//修改密码框
	    rectangle(480,380,570,405);
	}*/
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
FUNCTION:Plogin_Darken
DESCRIPTION:乘客登录界面按钮恢复
INPUT:恢复控制变量pos
RETURN:无
*/
int Plogin_Darken(int pos)                            
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
	    puthz(290,315+12,"登录",24,34,WHITE);//登录框
		break;
	case 4:
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
	    bar(290,380,350,405);
	    puthz(302,385,"注册",16,24,LIGHTBLUE);
	    setlinestyle(SOLID_LINE,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(290,380,350,405);//注册框
		break;
	case 5:
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(100,380,169,405);
	    puthz(114,385,"返回",16,24,LIGHTBLUE);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(100,380,169,405);//返回框
		break;
	/*case 6:
	    setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(480,380,570,405);
	    puthz(492,385,"修改密码",16,18,LIGHTBLUE);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(LIGHTBLUE);//修改密码框
	    rectangle(480,380,570,405);*/
	}
}

int Jundge_Plogin(char* account, char* password,int *id)	
{
	int l;                                                                     
	int i;
	int identity;
	FILE* fp;
	USER* u;                                                     //暂存用户信息的结构体
	if((fp=fopen(".\\TEXT\\UserData.dat","rb+"))==NULL)    //打开存储用户信息的文件
	{
		printf("\nError on open file UserData.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);                                 //将文件指针定位至起点
	l=ftell(fp)/sizeof(USER);                             //总内存÷单个结构体内存，计算从文件中读取到的总用户数
	for(i=0;i<l;i++)                                      //遍历从文件中读到的所有用户
	{
		if ((u=(USER*)malloc(sizeof(USER)))==NULL)        //分配
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp,i*sizeof(USER),SEEK_SET);                //文件指针定位到第i个用户所在的位置
		fread(u, sizeof(USER),1,fp);                      //从文件中将第i个用户的信息读入u
		if(strcmp(account,u->account)==0)                 //如果与当前所读用户的用户名匹配
		{
			if(strcmp(password,u->password)!=0)           //如果与当前所读用户的密码不匹配
			{
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				puthz(550,270,"密码错误",16,16,RED);      
				break;                                    //跳出遍历
			}
			else if(strcmp(password,u->password)==0)      //如果与当前所读用户的密码匹配
			{
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				puthz(550,270,"密码正确",16,16,RED);
				*id=u->number;
				if (u!=NULL)                              //释放内存
				{
					free(u);
					u=NULL;
				}
				if (fclose(fp)!= 0)                       //关闭文件
				{
					printf("\nError on close UserData.dat!");
					delay(3000);
					exit(1);
				}
				return 1;                          //标志登录成功，返回该用户身份，以便后续的乘客操作
			}
		}
	}
	if (i==l)                                             //在整个文件中都未找到该用户信息
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,276);
		puthz(550,210,"账号未注册", 16, 16, RED);       
	}

	if (u!= NULL)                                         //释放内存
	{
		free(u);
		u=NULL;
	}

	if (fclose(fp) != 0)                                  //关闭文件
	{
		printf("\nError on close UserData.dat!");
		delay(3000);
		exit(1);
	}
	return 0;                                             //返回0，标志登录失败
}