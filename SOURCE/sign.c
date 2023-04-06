#include"public.h"
#include"sign.h"
/*
FUNCTION:Sign
DESCRIPTION:实现标记与取消标记功能
INPUT:page
OUTPUT:NO
*/
void Sign(int *page)
{
	int flag=0;		//点亮情况
	int pos1=0;		//身份证输入情况
	int pos2=0;		//标记确诊患者
	int pos3=0;		//取消患者标记
	int jun=0; //判断身份证格式
	char I[25]; //存储输入的身份证号
	int n; //记录乘客代号
	int patient; //记录乘客确诊情况
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	
	Draw_Sign();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>220&&MouseX<595&&MouseY>188&&MouseY<213);		//输身份证
		{
			if(mouse_press(220,188,595,213)==2)
			{
				MouseS=2;
				if(pos1==0&&flag==0)
				{
					clrmous(MouseX,MouseY);
					Sign_Lighten(1);		//点亮
					flag=1;
				}
				continue;
			}
			if(mouse_press(220,188,595,213)==1)
			{
				MouseS=0;
				I[0]='\0';
				setfillstyle(1,WHITE);
				bar(530,217,600,235);
				Input_Vis(I,220,188,18,LIGHTGRAY);		//可视化输入
				jun=Sign_ID_Judge(I);
				if(strlen(I)!=0)		//判断是否完成输入
				{
					pos1=1;			//标记
				}
				else
				{
					pos1=0;
				}
				continue;
			}
				
		}
		if(MouseX>290&&MouseX<290+105&&MouseY>289&&MouseY<308)		//标记确诊患者
		{
			if (mouse_press(290,289,290+105,308)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(290,289,290+105,308)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Sign_Lighten(2);
				Sign_Darken(3);
				pos2=1;
				pos3=0;
				delay(200);
			}
		}
		if(MouseX>(388+90)&&MouseX<(388+90+105)&&MouseY>289&&MouseY<308)		//取消标记确诊患者
		{
			if (mouse_press(388+90,289,388+90+105,308)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(388+90,289,388+90+105,308)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Sign_Lighten(3);
				Sign_Darken(2);
				pos2=0;
				pos3=1;
				delay(200);
			}
		}
		if(MouseX>172.5&&MouseX<(182.5+294-4)&&MouseY>386.5&&MouseY<386.5+37)		//提交报告
		{
			if (mouse_press(172.5,386.5,182.5+294-4,386.5+37)==2)
			{
				MouseS=1;
				if(flag==0)
				{
					clrmous(MouseX,MouseY);
					Sign_Lighten(4);
					flag=4;
				}
				continue;
			}
			else if(mouse_press(172.5,386.5,182.5+294-4,386.5+37)==1)
			{
				MouseS=0;
				Sign_Lighten(4);
				 if(pos1==1&&(pos2==1||pos3==1)&&jun==1) //完成了填写内容并且格式正确
                {
					setlinestyle(SOLID_LINE,0,NORM_WIDTH); //进行提示
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, DARKGRAY);
		            puthz(274,220,"正在提交",24,24,RED);
					stablack(282,270,3);
					stablack(282,270,3);
					delay(500);
					stablack(320,270,3);
					delay(500);
					stablack(358,270,3);
					delay(500);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, DARKGRAY);
		            puthz(274,230,"提交成功",24,24,RED);
		            delay(1000);
					MouseS=0;
			    	Sign2(page,I,pos2); //传入患者身份证号，确诊类型与管理员操作类型
					break;
				}
				else
				{
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, DARKGRAY);
		            puthz(274,220,"正在提交",24,24,RED);
					stablack(282,270,3);
					stablack(282,270,3);
					delay(500);
					stablack(320,270,3);
					delay(500);
					stablack(358,270,3);
					delay(500);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, DARKGRAY);
		            puthz(274,230,"提交失败",24,24,RED);
		            delay(1000);
					return;
				}
				continue;
			}
		}
		if(MouseX>474+5&&MouseX<579+5&&MouseY>362+75&&MouseY<382+75) //重置
		{
			if(mouse_press(474+5,362+75,579+5,382+75)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(474+5,362+75,579+5,382+75)==1)
			{
				MouseS=0;
				cleardevice();
				flag=0;
				pos1=0;
				pos2=0;
				pos3=0;
				I[0]='\0';
				Draw_Sign();
				delay(100);
				continue;
			}
		}
		if(MouseX>55&&MouseX<160&&MouseY>437&&MouseY<457) //退出
		{
			if(mouse_press(55,437,160,457)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(55,437,160,457)==1)
			{
				MouseS=0;
				*page=7; //返回卫生部门界面
				break;
			}
		}
		if(flag!=0)		//还原页面
		{
			if(flag==1&&pos1==0)
			{
				clrmous(MouseX,MouseY);
				Sign_Darken(1);
			}
			if(flag==4)
			{
				clrmous(MouseX,MouseY);
				Sign_Darken(4);
			}
			flag=0;
		}
		if(MouseS!=0)
		{
			MouseS=0;
		}
	}
}
/*
FUNCTION:Draw_Sign
DESCRIPTION:绘制标记患者界面
INPUT:no
RETURN:no
*/
int Draw_Sign()
{
	cleardevice();
	setbkcolor(WHITE);
	cover(118, 10, 118 + 405, 10 + 32,LIGHTGRAY);
	highlight(118, 10, 118 + 405, 10 + 32,GREEN);
	cover(171,116,164+284,120+24,LIGHTGRAY);
	highlight(171,116,164+284,120+24,RED);
	puthz(170,14,"欢迎进入卫生部门标记系统",24,24,GREEN);
	puthz(175, 120, "请完成以下信息，调整新冠确诊者信息", 16, 16, RED);
	puthz(71, 194.75, "阳性患者身份证号", 16, 16, RED);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);   
	setfillstyle(1,DARKGRAY);
	bar(220,188,595,213);		//身份证号输入框
	highlight(220,188,595,213,GREEN);
	puthz(71,290,"请选择操作类型",16,16,RED);
	cover(290,289,290+105,308,GREEN);
	highlight(287,286,290+108,311,RED);
	cover(388+90,289,388+90+105,308,GREEN);	
	highlight(388+90-3,289-3,388+90+105+3,308+3,RED);		//两个按钮
	puthz(291,290, "标记确诊患者", 16, 17, RED);
	puthz(388+91,290, "取消患者标记", 16, 17, RED);
	cover(172.5, 386.5, 182.5 + 294-4, 386.5 + 37, GREEN);	
	highlight(172.5, 386.5, 182.5 + 294-4, 386.5 + 37, RED);		//提交报告按钮
	puthz(260, 389, "提交报告", 32, 32 + 2, WHITE);
	draw_exit(60, 440, WHITE, RED, BLUE, CYAN);
	draw_refresh(279+200+5, 440, WHITE, GREEN, CYAN, LIGHTGREEN);
}
/*
FUNCTION:Sign_Lighten
DESCRIPTION:点亮按钮
INPUT:flag
RETURN:NO
*/
int Sign_Lighten(int flag)
{
	clrmous(MouseY,MouseY);
	delay(10);
	switch(flag)
	{
		case 1: //身份证号输入框
			setlinestyle(SOLID_LINE,0,THICK_WIDTH);
			highlight(220,188,595,213,GREEN);
			setfillstyle(1,LIGHTGRAY);
			bar(220,188,595,213);	
			break;
		case 2: //标记确诊患者
			cover(290,289,290+105,308,LIGHTGRAY);
			highlight(287,286,290+108,311,RED);
			puthz(291,290, "标记确诊患者", 16, 17, RED);
			break;
		case 3: //取消患者标记
			cover(388+90,289,388+90+105,308,LIGHTGRAY);	
			highlight(388+90-3,289-3,388+90+105+3,308+3,RED);
			puthz(388+91,290, "取消患者标记", 16, 17, RED);
			break;
		case 4: //提交报告按钮
			cover(172.5, 386.5, 182.5 + 294-4, 386.5 + 37, LIGHTGRAY);		
			puthz(260, 389, "提交报告", 32, 32 + 2,GREEN);
		/*case 5: //返回
		    cover(99,308+30,203,361+30, LIGHTBLUE);
	        highlight(99,308+30,203,361+30, RED);
	        puthz(110+15, 310+13+30, "返回", 24, 26, WHITE);
			break;
		case 6: //保存
		    cover(432,308+30,536,361+30, LIGHTBLUE);
	        highlight(432,308+30,536,361+30, RED);
	        puthz(461, 310+13+30, "保存", 24, 26, WHITE);
			break;*/
	}
}
/*
FUNCTION:Sign_Darken
DESCRIPTION:按钮恢复
INPUT:flag
RETURN:NO
*/
int Sign_Darken(int flag)
{
	clrmous(MouseY,MouseY);
	delay(10);
	switch(flag)
	{
		case 1: //身份证号输入框
			setlinestyle(SOLID_LINE,0,THICK_WIDTH);
			highlight(220,188,595,213,GREEN);
			setfillstyle(1,DARKGRAY);
			bar(220,188,595,213);	
			break;
		case 2: //标记确诊患者
			cover(290,289,290+105,308,GREEN);
			highlight(287,286,290+108,311,RED);
			puthz(291,290, "标记确诊患者", 16, 17, RED);
			break;
		case 3: //取消患者标记
			cover(388+90,289,388+90+105,308,GREEN);	
			highlight(388+90-3,289-3,388+90+105+3,308+3,RED);
			puthz(388+91,290, "取消患者标记", 16, 17, RED);
			break;
		case 4: //提交报告按钮
			cover(172.5, 386.5, 182.5 + 294-4, 386.5 + 37, GREEN);		
			puthz(260, 389, "提交报告", 32, 32 + 2,WHITE);
		/*case 5: //返回
		    cover(99,308+30,203,361+30, WHITE);
	        highlight(99,308+30,203,361+30, RED);
	        puthz(110+15, 310+13+30, "返回", 24, 26, LIGHTBLUE);
			break;
		case 6: //保存
		    cover(432,308+30,536,361+30, WHITE);
	        highlight(432,308+30,536,361+30, RED);
	        puthz(461, 310+13+30, "保存", 24, 26, LIGHTBLUE);
			break;*/
	}
}
/*
FUNCTION:Sign_ID_Judge()
DESCRIPTION:判断身份证格式
INPUT:if
RETURN:1or0
*/
int Sign_ID_Judge(char *I)
{
	int i;
	int flag1=0;//判断长度
	int flag2=0;//判断数字
	int flag3=0;//判断最后一位
	int len=0;
	len=strlen(I);
	if(len==18)
	{
		flag1=1;
	}
	if(flag1==1)
	{
		for(i=0;i<17;i++)
		{
			if(I[i]>='0'&&I[i]<='9')
			{
				flag2=1;
			}
			else
			{
				flag2=0;
				break;
			}
		}
	}
	if(flag2==1)
	{
		if((I[17]>='0'&&I[17]<='9')||I[17]=='X')
		{
			flag3=1;
		}
	}
	if(flag1=1&&flag2==1&&flag3==1)
	{
		setfillstyle(1,WHITE);
		bar(530,217,600,235);
		puthz(530,218,"格式正确",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,WHITE);
		bar(530,217,600,235);
		puthz(530,218,"格式错误",16,16,RED);
		return 0;
	}
}
/*
FUNCTION:Sign2
DESCRIPTION:保存界面
INPUT:界面跳转控制变量page，患者身份证号I，管理员操作方式pos2
RETURN:无
*/
void Sign2(int* page,char* I,int pos2)//保存界面
{
	int flag=0; //标记点亮情况
	int n=0; //记录乘客代号
	int jun; //判断操作是否符合规范
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Sign2(pos2); //根据选择的操作类型绘制界面
	
	Sign_Search(&n,pos2,I); //在系统中查询相关乘客的信息
	jun=Sign_Check_Jundge(n,pos2,page); //判断操作是否符合规范
	//printf("%d",n);
	if(n==0) //未在系统中查询到相关乘客的信息
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"暂无信息",24,24,RED);
		delay(3000);
		*page=71;
		return;
	}
	if(jun==1) //该乘客已经被标记却选择了标记患者操作
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"已经标记",24,24,RED);
		delay(3000);
		*page=71;
		return;
	}
	else if(jun==2) //该乘客尚未被标记却选择了取消标记操作
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"尚未标记",24,24,RED);
		delay(3000);
		*page=71;
		return;
	}
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		MouseS=0;
		if(MouseX>99&&MouseX<203&& MouseY>308+30&& MouseY<361+30) //返回框
		{
			if(mouse_press(99,308+30,203,361+30)==2)               
			{
				MouseS=1;                                   
				if(flag==0)                  
				{
		            //Sign_Lighten(5);
					flag=5;                               
				}
				continue;
			}
			else if(mouse_press(99,308+30,203,361+30)==1)        
			{
				MouseS=0;
				//Sign_Lighten(5);     
				cleardevice();
				*page=71; //返回标记主界面
				break;
			}
	    }
		if(MouseX>432&&MouseX<536&& MouseY>308+30&& MouseY<361+30)//保存框
		{
			if(mouse_press(432,308+30,536,361+30)==2)               
			{
				MouseS=1;                                   
				if(flag==0)                  
				{
		            //Sign_Lighten(6);
					flag=6;                               
				}
				continue;
			}
			else if(mouse_press(432,308+30,536,361+30)==1)        
			{
				setlinestyle(SOLID_LINE,0,NORM_WIDTH); //提示保存成功
                setfillstyle(SOLID_FILL, WHITE);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                setfillstyle(SOLID_FILL, WHITE);
		        puthz(274,220,"正在保存",24,24,RED);
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
		        puthz(274,230,"保存成功",24,24,RED);
		        delay(1500);
				Sign_Check_Save(n,pos2);
				*page=71; //返回标记患者主界面
				break;
			}
	    }
        if(flag!=0)
		{
			if(flag==5)
			{
				//Sign_Darken(5);
			}
			if(flag==6)
			{
				//Sign_Darken(6);
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
FUNCTION:Draw_Sign2
DESCRIPTION:绘制保存界面
INPUT:pos2
RETURN:无
*/
int Draw_Sign2(int pos2)
{
	int hzcolor = LIGHTBLUE;
	
	cleardevice();
	setbkcolor(DARKGRAY);
	cover(35, 69+20, 35 + 573, 305 + 83+30, LIGHTGRAY);
	highlight(35, 69+20, 35 + 573, 305 + 83+30, RED);
	setfillstyle(1,GREEN);
	bar(150,23,504,63);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(RED);
	rectangle(150,23,504,63);
	if(pos2==1) //根据操作类型给予不同的操作提示
	{
		puthz(219,32,"请标记确诊患者",24,32,WHITE);
	}
	else
	{
		puthz(219,32,"请取消患者标记",24,32,WHITE);
	}
	puthz(91, 89+30, "患者姓名", 16, 17, hzcolor);
	puthz(91, 129+30, "患者性别", 16, 17, hzcolor);
	puthz(91, 169+30, "身份证号", 16, 17, hzcolor);
	puthz(91, 209+30, "联系方式", 16, 17, hzcolor);

	setcolor(RED);
	setlinestyle(1, 0, 3);
	line(200, 135, 470, 135);//姓名
	line(200, 175, 470, 175);//性别
	line(200, 215, 470, 215);//身份证号
	line(200, 255, 470, 255);//联系方式
	
	cover(99,308+30,203,361+30, WHITE);
	highlight(99,308+30,203,361+30, RED);
	puthz(110+15, 310+13+30, "返回", 24, 26, hzcolor);
	cover(432.5, 293.13+15+30, 432.5 + 104, 293 + 53+15+30, WHITE);
	highlight(432.5, 293.13+15+30, 432.5 + 104, 293 + 53+15+30, RED);
	puthz(461, 310+13+30, "保存", 24, 26, hzcolor);
}
/*
FUNCTION:Sign_Search
DESCRIPTION:在系统中查找录入的患者信息
INPUT:n，患者ID号码I，是否标记pos2
RETURN:NO
*/
int Sign_Search(int *n,int pos2,char* I)
{
	PASSENGER* p;
	FILE *fp;
	if((fp=fopen("C:\\TRY\\TEXT\\pass.dat","rb+"))==NULL)//打开存储用户信息的文件
	{
		printf("\nError on open file pass.dat!");
		delay(3000);
		exit(1);
	}
	while(!feof(fp))
	{
		if((p=(PASSENGER*)malloc(sizeof(PASSENGER)))==NULL)	//分配空间
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fscanf(fp,"%d",&p->number);
		fgetc(fp);
		if(p->number==-1)
		{
			break;
		}
		fscanf(fp,"%s",p->name);
		fgetc(fp);
		fgets(p->telephone,12,fp);
		fgetc(fp);
		fgets(p->ID,19,fp);
		fgetc(fp);
		fgets(p->age,3,fp);
		fgetc(fp);
		fgets(p->sex,3,fp);
		fgetc(fp);
		
		if(strcmp(p->ID,I)==0)
		{
			*n=p->number;	//记录乘客代号
			puthz(200,118,p->name,16,24,WHITE); //在屏幕上显示乘客信息
	        puthz(200,158,p->sex,16,24,WHITE);
			settextstyle(1,0,1);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			setcolor(WHITE);
			outtextxy(200,233,p->telephone);
			outtextxy(200,193,p->ID);
			if(p!=NULL)
			{
				free(p);
				p=NULL;
			}
			break;
		}
		if(p!=NULL)
		{
			free(p);
			p=NULL;
		}
	}
	if(fclose(fp)!=0)
	{
		printf("\nError on close pass.dat!");
		delay(3000);
		exit(1);
	}
}
/*
FUNCTION:Sign_Check_Jundge
DESCRIPTION:判断管理员操作是否符合规范
INPUT:乘客代号n，管理员操作方式pos2，界面跳转控制变量page
RETURN:flag
*/
int Sign_Check_Jundge(int n,int pos2, int* page)
{
	int flag=0;
	int l;
	int i;
	FILE *fp;
	STATE *S=NULL;
	if((fp=fopen("C:\\TRY\\TEXT\\state.dat","rb+"))==NULL)
	{
		printf("\nError on open file state.dat!");
		delay(3000);
		exit(1);
	}	
	fseek(fp,0,SEEK_END);	//计算文件大小
	l=ftell(fp)/sizeof(STATE);
	for(i=0;i<l;i++)
	{
		if((S=(STATE*)malloc(sizeof(STATE)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp,i*sizeof(STATE),SEEK_SET);
		fread(S,sizeof(STATE),1,fp);
		if(n==S->number)
		{
			if(pos2==1&&S->patient!=0)	//选择标记且已标记
			{
				flag=1;
			}
			if(pos2==0&&S->patient==0)	//选择取消且未标记
			{
				flag=2;
			}
		}
		if(S!=NULL)                                              //释放内存
		{
			free(S);
			S=NULL;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
	return flag; //返回操作判断
}
/*
FUNCTION:Sign_Check_Save
DESCRIPTION:在系统中保存的乘客的确诊情况
INPUT:乘客代号n，管理员操作方式pos2
RETURN:无
*/
int Sign_Check_Save(int n,int pos2) //完成确诊患者的标记或取消标记 
{
	int l;
	int i;
	FILE* fp;
	STATE* s=NULL;
	if ((fp=fopen("C:\\TRY\\TEXT\\state.dat","rb+"))==NULL)
	{
		printf("\nError on open file state.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);                                            //文件指针定位到最后一位
	l=ftell(fp)/sizeof(STATE);                                      
	for(i=0;i<l;i++)
	{
		if((s=(STATE*)malloc(sizeof(STATE)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
		    exit(1);
		}
		fseek(fp,i*sizeof(STATE),SEEK_SET);                           
		fread(s,sizeof(STATE),1,fp);                                 
		if(n==s->number) //在文件中查询到对应乘客                                  
		{
			if(pos2==1) //标记确诊乘客
			{			    			    
				    s->patient=1;
			}
			else //取消乘客标记
			{
				s->patient=0;
			}
			fseek(fp,i*sizeof(STATE),SEEK_SET); //将信息写入文件                      
			fwrite(s,sizeof(STATE),1,fp);                             
			if(s!=NULL)                                              //释放内存
			{
				free(s);
				s=NULL;
			}
			break;
		}
		if(s!=NULL)                                              //释放内存
		{
			free(s);
			s=NULL;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
}