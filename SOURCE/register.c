#include"public.h"
#include"register.h"
/*
FUNCTION:Register
INPUT:界面跳转控制变量page
RETURN:无
*/
void Register(int* page)
{
	int pos1=0;                                             //判断输入框1输入情况
	int pos2=0;                                             //判断输入框2输入情况
	int pos3=0;                                             //判断输入框3输入情况
	int pos4=0;                                             //判断输入框4输入情况
	int pos5=0;
	int flag=0;                                             //标记输入框点亮情况，以防重复点亮
	int jun1=0;                                             //判断账号输入结果
	int jun2=0;                                             //判断密码输入结果
	int jun3=0;                                             //判断确认密码输入结果
	int jun4=0;                                             //判断身份证号输入结果
	int jun5=0;
	int identity;                                           //存储注册乘客的身份
	char A[15]={'\0'};                                      //账号，6-12位
	char I[20]={'\0'};                                      //身份证，18位
	char P[15]={'\0'};                                      //设置密码，6-12位
	char RP[15]={'\0'};                                     //确认密码，6-12位
	
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Register();                                        //画注册界面
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);                   //画鼠标
		if(MouseX>95&&MouseX<545&& MouseY>85&& MouseY<110)  //鼠标进入输入框1的范围
		{
			if(mouse_press(95,85,545,110)==2)               //未点击输入框1
			{
				MouseS=2;                                   //改鼠标为光标形态
				if(flag==0&&pos1==0)                  
				{
					Register_Lighten(95,85,545,110,1);      //点亮输入框1
					flag=1;                                 //标记输入框1已点亮
				}
				continue;
			}

			else if(mouse_press(95,85,545,110)==1)         //点击输入框1
			{
				MouseS =0;
				Register_Lighten(95,85,545,110,1);
				A[0]='\0';                                  //清空之前的输入
				setfillstyle(1,DARKGRAY);
		        bar(550,90,640,106);
				Input_Vis(A,95,85,12,LIGHTGRAY);            //可视输入
				jun1=R_Account_Jundge(A);                   //判断账号是否符合要求
				if(strlen(A)!= 0)                           //判断是否完成输入
					pos1=1;                                 //完成输入则进行标记
				else
					pos1=0;
				continue;
			}
		}
		if(MouseX>95&& MouseX<545&& MouseY>145&& MouseY< 170)
		{
			if(mouse_press(95,145,545,170)==2)     
			{
				MouseS=2;
				if(flag==0&&pos2==0)
				{
					Register_Lighten(95,145,545,170,2);
					flag=2;
				}
				continue;
			}

			else if(mouse_press(95,145,545,170)==1)     
			{
				Register_Lighten(95,145,545,170,2);
				MouseS=0;
				P[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,150,640,166);
				Input_Invis(P,95,145,16,LIGHTGRAY);
				jun2=R_Password_Jundge(P);//判断密码长度是否符合要求
				if(strlen(P)!=0)
					pos2=1;
				else
					pos2=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>205&& MouseY<230)
		{
			if(mouse_press(95,205,545,230) == 2)    
			{
				MouseS=2;
				if(flag==0&&pos3==0)
				{
					Register_Lighten(95,205,545,230,3);
					flag=3;
				}
				continue;
			}

			else if(mouse_press(95,205,545,230)==1)      
			{
				Register_Lighten(95,205,545,230,3);
				MouseS = 0;
				RP[0] ='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,210,640,226);
				Input_Invis(RP,95,205,16,LIGHTGRAY);//不可视输入
				jun3=R_Password_Same(P,RP);//判断两次输入的密码是否一致
				if(strlen(RP)!=0)
					pos3=1;
				else
					pos3=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>260&& MouseY<290)
		{
			if(mouse_press(95,265,545,290)==2)      
			{
				MouseS=2;
				if(flag==0&&pos4==0)
				{
					Register_Lighten(95,265,545,290,4);
					flag=4;
				}
				continue;
			}

			else if(mouse_press(95,265,545,290)==1)
			{
				Register_Lighten(95,265,545,290,4);
				MouseS=0;
				I[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				Input_Vis(I,95,265,18,LIGHTGRAY);
				jun4=R_ID_Jundge(I);//判断身份证是否有效
				if(strlen(I)!=0)
					pos4=1;
				else 
					pos4=0;
				continue;
			}
		}
		
		if(MouseX>143&&MouseX<237&&MouseY>370&& MouseY<400)
		{
			if(mouse_press(143,370,237,400)==2)                
			{
				if(flag==0)
				{
					MouseS=1;
					Register_Lighten(143,370,237,400,5);
					flag=5;
				}
				continue;
			}

			else if(mouse_press(143,370,237,400)==1)
			{
				MouseS=0;                        //重置鼠标
				A[0]='\0';
				I[0]='\0';
				P[0]='\0';
				RP[0]='\0';
				flag=0;                          //重置数据
				pos1=0;
				pos2=0;
				pos3=0;
				pos4=0;
				return;
			}
		}

		if(MouseX >273&& MouseX<367&& MouseY>370&& MouseY<400)
		{
			if(mouse_press(273,370,367,400)==2)					
			{
				if (flag==0)
				{
					MouseS=1;
					Register_Lighten(273,370,367,400,6);
					flag=6;
				}
				continue;
			}

			else if(mouse_press(273,370,367,400)==1)
			{
				MouseS=0;
				if (Register_Com(jun1,jun2,jun3,jun4,A,I,P))//注册判断
				{
		            *page=1;                                         //跳转至乘客登录界面
					break;
				}
				else
				{
					return;
				}
			}
		}

		if (MouseX>403&&MouseX<497&&MouseY>370&&MouseY<400)
		{
			if (mouse_press(403, 370, 497, 400)==2)				
			{
				if (flag==0)
				{
					MouseS=1;
					Register_Lighten(403,370,497,400,7);
					flag=7;
				}
				continue;
			}

			else if(mouse_press(403, 370, 497, 400) == 1)
			{
				MouseS=0;
				*page=1;                            //跳转至乘客登录界面
				break; 
			}
		}

		if(flag!=0)                                 //根据点亮情况，对输入框进行还原
		{
			MouseS=0;
			if(pos1==0)
			{
				Register_Darken(1);
			}
			if (pos2==0)
			{
				Register_Darken(2);
			}
			if (pos3==0)
			{
				Register_Darken(3);
			}
			if (pos4==0)
			{
				Register_Darken(4);
			}
			if (pos5==0)
			{
				Register_Darken(5);
			}
			if (flag==5||flag ==6||flag ==7)
			{
				Register_Darken(flag);
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
FUNCTION:Draw_Register
DESCRIPTION:绘制登录界面
INPUT:无
RETURN:无
*/
int Draw_Register()
{
    cleardevice();
	setbkcolor(DARKGRAY);                        //设置背景颜色
	
	puthz(255,25,"用户注册",32,32,WHITE);
	puthz(254,24,"用户注册",32,32,RED);
	puthz(175,320,"勿将身份信息透露给他人",24,24,BROWN);
	puthz(95,60,"请输入账号",16,16,CYAN);        //画输入提示
	puthz(95,120,"请输入密码",16,16,CYAN);
    puthz(95,180,"请确认密码",16,16,CYAN);
    puthz(95,240,"请输入身份证号码",16,16,CYAN);
	
	
	setviewport(0,0,640,480,1);                  //画小人和身份证
	setfillstyle(1,YELLOW);
	setcolor(YELLOW);
	circle(50,95,30);
	floodfill(50,95,YELLOW);

    setfillstyle(1,BLUE);
	setcolor(BLUE);
	circle(50,275,30);
	floodfill(50,275,BLUE);
	
	setfillstyle(1,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	circle(50,85,10);
	floodfill(50,85,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	line(50,95,34,115);
	line(34,115,66,115);
	line(66,115,50,95);
	floodfill(50,105,LIGHTGRAY);
	
	setfillstyle(1, WHITE);
	setcolor(WHITE);
	rectangle(30,265,70,285);
	floodfill(35,275, WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(45,268,55,271);
	bar(45,273,65,276);
	bar(45,278,65,281);
	
	setfillstyle(1,WHITE);                     
	bar(95,85,545,110);                          //画输入框
    bar(95,145,545,170);
	bar(95,205,545,230);
	bar(95,265,545,290);

	setfillstyle(1,GREEN);
	bar(143, 370, 237, 400);
	puthz(161,373,"重置",24,34,WHITE);           //画操作框
    setfillstyle(1,RED);
	bar(273, 370, 367, 400);
	puthz(291,373,"完成",24,34,WHITE);
    setfillstyle(1,BLUE);
	bar(403, 370, 497, 400);
	puthz(421,373,"返回",24,34,WHITE);
	
	
}


/*
FUNCTION:Register_Lighten
DESCRIPTION:乘客注册界面按钮点亮
INPUT:点亮控制变量flag
RETURN:无
*/
int Register_Lighten(int x1,int y1,int x2,int y2,int flag)
{
	clrmous(MouseX,MouseY);
	delay(10);

	if(flag==5)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,CYAN);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(161,373,"重置",24,34,LIGHTCYAN);
	}
	else if(flag== 6)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,RED);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(291,373,"完成",24,34,LIGHTRED);
	}
	else if(flag==7)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,BLUE);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(421,373,"返回",24,34,LIGHTBLUE);
	}
	else                                            //点亮输入框
	{
		setcolor(MAGENTA);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,LIGHTGRAY);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
	}
}

/*
FUNCTION:Register_Darken
DESCRIPTION:乘客注册界面按钮恢复
INPUT:恢复控制变量pos
RETURN:无
*/
int Register_Darken(int pos)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, WHITE);
	switch (pos)
	{
	case 1:                                          //还原输入框
		bar(95,85,545,110);
		break;
	case 2:
		bar(95,145,545,170);
		break;
	case 3:
		bar(95,205,545,230);
		break;
	case 4:
		bar(95,265,545,290);
		break;
	case 5:
		setfillstyle(1,GREEN);
		bar(143,370,237,400);
		puthz(161,373,"重置",24,34,WHITE);
		break;
	case 6:
		setfillstyle(1,RED);
		bar(273,370,367,400);
		puthz(291,373,"完成",24,34,WHITE);
		break;
	case 7:
		setfillstyle(1,BLUE);
		bar(403,370,497,400);
		puthz(421,373,"返回",24,34,WHITE);
		break;
	case 8:
	    bar(175, 325, 545, 350);
		break;
	}
}

/*
FUNCTION:R_Account_Jundge
DESCRIPTION:判断账号是否符合要求
INPUT:输入的账号A
RETURN:判断结果
*/
int R_Account_Jundge(char* A)                  //判断账号是否符合要求
{
	int flag=0;                                //标记账号长度是否符合要求
	int l;
	int i;
	FILE* fp;
	USER*u=NULL;
	if(strlen(A)>=6)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,90,640,106);
		puthz(550,90,"通过",16,16,RED);
		flag=1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,90,640,106);
		puthz(550,90,"账号过短",16,16,RED);
		flag=0;
	}
	if(flag==1)
	{
		if((fp=fopen(".\\TEXT\\UserData.dat","rb+"))==NULL)//打开存储用户信息的文件
	    {
		    printf("\nError on open file UserData.dat!");
		    delay(3000);
		    exit(1);
	    }
	    fseek(fp,0,SEEK_END);                                    //文件指针定位至起点
	    l=ftell(fp)/sizeof(USER);                                //计算用户总数
	    for(i=0;i<l;i++)                                         //遍历读取到的所有用户
	    {
		    if((u=(USER*)malloc(sizeof(USER)))==NULL)
		    {
			    printf("Memory not enough!");
			    delay(3000);
			    exit(1);
		    }
		    fseek(fp,i*sizeof(USER),SEEK_SET);
		    fread(u,sizeof(USER),1,fp);
		    if(strcmp(u->account,A)==0)                          //如果当前账号在文件中已经存在
		    {
			    setfillstyle(1,DARKGRAY);
		        bar(550,90,640,106);
		        puthz(550,90,"账号已注册",16,16,RED);
			    if(u != NULL)
			    {
				    free(u);
				    u = NULL;
			    }
			    if(fclose(fp) != 0)
			    {
				    printf("\nError on close UserData.dat!");
				    delay(3000);
				    exit(1);
			    }
			    if(u!= NULL)
		        {
			        free(u);
			        u = NULL;
		        }
			    return 0;                                        //账号不符合要求
		    }
	    }
		//能够离开循环，说明账号尚未注册
		setfillstyle(1,DARKGRAY);
		bar(550,90,640,106);
		puthz(550,90,"通过",16,16,RED);
		if(u!= NULL)
		{
			free(u);
			u = NULL;
		}
		if(fclose(fp) != 0)
		{
			printf("\nError on close UserData.dat!");
			delay(3000);
			exit(1);
		}
		if(u != NULL)
		{
			free(u);
			u = NULL;
		}
		return 1;                                                 //账号符合要求
    }
}

/*
FUNCTION:R_Password_Jundge
DESCRIPTION:判断密码是否符合要求
INPUT:输入的密码P
RETURN:判断结果
*/
int R_Password_Jundge(char* P)                                    //判断密码长度是否符合要求
{
	if(strlen(P)>=6)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,150,640,166);
		puthz(550,150,"通过",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,150,640,166);
		puthz(550,150,"密码过短",16,16,RED);
		return 0;
	}
}	

/*
FUNCTION:R_Password_Same
DESCRIPTION:判断两次输入的密码是否一致
INPUT:两次输入的密码P,RP
RETURN:判断结果
*/
int R_Password_Same(char* P,char* RP)                             //判断两次输入的密码是否一致
{
	if(strcmp(P,RP)==0)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,226);
		puthz(550,210,"密码一致",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,226);
		puthz(550,210,"密码不一致",16,16,RED);
		return 0;
	}
}

/*
FUNCTION:R_ID_Jundge
DESCRIPTION:判断身份证是否有效
INPUT:输入的身份证号I
RETURN:判断结果
*/
int R_ID_Jundge(char *I)               //判断输入的身份证号是否存在于系统中
{
	int flag=0;
	int i=0;
	int id=0;
	FILE* fp;
	PASSENGER* p=NULL;
	
	if((fp = fopen(".\\TEXT\\pass.dat","rb+"))==NULL)     //打开存储用户信息的文件
	{
		printf("\nError on close pass.dat!");
		delay(3000);
		exit(1);
	}
	while(!feof(fp))
	{
		if((p=(PASSENGER*)malloc(sizeof(PASSENGER)))==NULL)     //分配空间
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fscanf(fp,"%d",&p->number); 
		if(p->number==-1)
		{
			break;
		}
		fgetc(fp);
		fscanf(fp,"%s",p->name);
		fgetc(fp);
		fgets(p->telephone,12,fp);
		fgetc(fp);
		fgets(p->ID,19,fp);
		fgetc(fp);
		fgetc(fp);
		fgets(p->age,3,fp);
		fgetc(fp);
		fgets(p->sex,3,fp);
		fgetc(fp);
		if(strcmp(p->ID,I)==0)
		{
			id=p->number;
			flag=1;
			if(p!= NULL)                                      //释放内存
		    {
			    free(p);
			    p= NULL;
		    }
			break;
		}
		if(p!= NULL)                                      //释放内存
		{
			free(p);
			p = NULL;
		}
	}	
	if(flag==1)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,270,640,286);
		puthz(550,270,"身份证有效",16,16,RED);
		return id;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,270,640,286);
		puthz(550,270,"身份证无效",16,16,RED);
		return 0;
	}
}

int R_Code_Jundge(char* str,char* VC)
{
	if(strcmp(str,VC)==0)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,330,640,286+60);
		puthz(550,330,"正确",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,330,640,286+60);
		puthz(550,330,"错误",16,16,RED);
		return 0;
	}
}
/*
FUNCTION:R_Input_Data
DESCRIPTION:将新注册的用户信息写入文件
INPUT:输入的账号A，身份证号I，密码P，乘客代号identity
RETURN:判断结果
*/
void R_Input_Data(char* A,char* I,char* P,int jun4)           //将新注册的用户信息写入文件
{
	FILE* fp;
	USER* u;
	if((fp=fopen(".\\TEXT\\UserData.dat", "rb+" )) == NULL) //打开存储用户信息的文件
	{
		printf("\nError on open file UserData.dat!");
		delay(3000);
		exit(1);
	}
	if((u=(USER*)malloc(sizeof(USER)))==NULL)                      //分配空间
	{
		printf("\nMemory not enough!");
		delay(3000);
		exit(1);
	}
	u->number=jun4;                                            //将用户输入的信息临时存储在u中
	strcpy(u->ID,I);
	strcpy(u->account,A);
	strcpy(u->password,P);
	fseek(fp,0,SEEK_END);                                          //文件指针移动至文件最后
	fwrite(u,sizeof(USER),1,fp);                                   //把新用户信息写入文件最后
	if (u != NULL)                                                 //释放u
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp)!=0)                                             //关闭文件
	{
		printf("\nError on close UserData.dat!");
		delay(3000);
		exit(1);
	}
}

/*
FUNCTION:Register_Com
DESCRIPTION:完成注册
INPUT:判断结果jun1,jun2,jun3,jun4,输入的账号A，身份证号I，密码P，乘客代号identity
RETURN:判断结果
*/
int Register_Com(int jun1,int jun2,int jun3,int jun4,char* A,char* I,char* P)
{
	if(jun1==1&&jun2==1&&jun3==1&&jun4!=0)                         //用户输入的内容均符合要求
	{
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,220,"正在注册",24,24,RED);
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
		puthz(274,230,"注册成功",24,24,RED);
		delay(3000);
		R_Input_Data(A,I,P,jun4);                              //将新用户的信息写入文件
	    return 1;
	}
	else
	{
		setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,220,"正在注册",24,24,RED);
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
		puthz(274,230,"注册失败",24,24,RED);
		delay(3000);
		return 0;
	}
}
