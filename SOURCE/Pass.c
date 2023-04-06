#include"public.h"
#include"pass.h"



/*
FUNCTION:实现乘客功能
INPUT:界面跳转控制变量page，乘客代号identity
RETURN:无
*/
void Pass(int* page, int identity)
{
	int flag=0;
	int Tag;//用于标记乘客状态：1=正常，2=密切接触者，3=确诊
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Tag=Pass_Tag(identity);
	Draw_Pass(Tag,identity);
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if (MouseX > 492 && MouseX < 619 && MouseY> 80 && MouseY < 105)
		{
			if (mouse_press(492,80,619,105) == 2)//查看乘车记录未点击
			{
				MouseS = 1;
				if (flag== 0)//防止被重复标亮
				{
		            Pass_Lighten(1);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(492, 80, 619, 105) == 1)//查看乘车记录框点击
			{
				MouseS = 0;
				Pass_Lighten(1);
				*page=51;
				break;
			}
		}
		
		/*if (MouseX > 492 && MouseX < 619 && MouseY> 377 && MouseY < 397)
		{
			if (mouse_press(492,377,619,397) == 2)//查看乘车记录未点击
			{
				MouseS = 1;
				if (flag== 0)//防止被重复标亮
				{
		            Pass_Lighten(2);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(492, 377, 619, 397) == 1)//查看乘车记录框点击
			{
				MouseS = 0;
				Pass_Lighten(2);
				*page=51;
				break;
			}
		}*/
		
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
				//切换到乘客登录界面
			}
		}

        if (flag!= 0||MouseS!=0)
		{
			flag= 0; 
			MouseS = 0;
			Pass_Darken();
	    }
	}
}

/*
FUNCTION:绘制乘客功能界面
INPUT：乘客当前状态Tag
RETURN：无
*/
void Draw_Pass(int Tag,int identity)
{
    cleardevice();
	
	if(Tag==1)
	{
		//Pass_Name(identity);
	
	    ring(555, 263, 60, 50, GREEN, GREEN, 2);
	    map();
		//画地铁图
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, LIGHTGREEN);
		highlight(472, 0, 639, 479, LIGHTGREEN);
		//两个外框
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTRED);
		//查看乘车记录
		puthz(492,150,"您的出行状态是：",16,16,DARKGRAY);
		puthz(492,150+30,"正常通行",16,16,DARKGRAY);
		setcolor(GREEN);
		line(546, 270+20+40, 565, 270+20+40);
		line(546, 220+20+40, 546, 270+20+40);
		line(565, 220+20+40, 565, 270+20+40);//矩形
		line(520, 242+20+40, 532, 242+20+40);
		line(579, 242+20+40, 591, 242+20+40);//两边水平线
		line(532, 242+20+40, 546, 220+20+40);
		line(579, 242+20+40, 565, 220+20+40);//内侧斜线
		line(520, 242+20+40, 555.5, 190+20+40);
		line(591, 242+20+40, 555.5, 190+20+40);
		setfillstyle(1,GREEN);
		floodfill(555.5, 240+20+40, GREEN);
		circle(555+1,230+20+40,50);
		circle(555+1,230+20+40,60-2);
		floodfill(555+1,230+20+55+40,GREEN);
		//显示乘车状态
		/*cover(492, 395+2-20, 619, 415+2-20, WHITE);
		highlight(492, 395+2-20, 619, 415+2-20, LIGHTRED);
		puthz(492 + 10, 400-20, "查看停运日期", 16, 19, LIGHTRED);*/
		//查看停运日期
		draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
		//点击退出
	}
	
	else if(Tag==2)
	{
		//Pass_Name(identity);
	
		ring(555, 263, 60, 50, GREEN, GREEN, 2);
		map();
		//画地铁图
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, LIGHTGREEN);
		highlight(472, 0, 639, 479, LIGHTGREEN);
		//两个外框
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTRED);
		//查看乘车记录
		puthz(492,150,"您的出行状态是：",16,16,DARKGRAY);
		puthz(492,150+30,"禁止出行",16,16,RED);
		
		cover(547, 227, 547 + 15, 227 + 50, YELLOW);
		setcolor(YELLOW);
	    setfillstyle(1, YELLOW);
	    pieslice(547 + 7.5, 227+35 + 50, 0, 360, 10);
	    setcolor(YELLOW);
		
		//显示乘车状态
		/*cover(492, 395+2-20, 619, 415+2-20, WHITE);
		highlight(492, 395+2-20, 619, 415+2-20, LIGHTRED);
		puthz(492 + 10, 400-20, "查看停运日期", 16, 19, LIGHTRED);*/
		//查看停运日期
		draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
		//点击退出
	}
	
	else
	{
		//Pass_Name(identity);
	
		ring(555, 263, 60, 50, GREEN, GREEN, 2);
	    map();
		//画地铁图
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, LIGHTGREEN);
		highlight(472, 0, 639, 479, LIGHTGREEN);
		//两个外框
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTRED);
		//查看乘车记录
		puthz(492,150,"您的出行状态是：",16,16,DARKGRAY);
		puthz(492,150+30,"禁止出行",16,16,RED);
		
		cover(547, 227, 547 + 15, 227 + 50, RED);
		setcolor(RED);
	    setfillstyle(1, RED);
	    pieslice(547 + 7.5, 227 +35+ 50, 0, 360, 10);
	    setcolor(RED);
		
		//显示乘车状态
		/*cover(492, 395+2-20, 619, 415+2-20, WHITE);
		highlight(492, 395+2-20, 619, 415+2-20, LIGHTRED);
		puthz(492 + 10, 400-20, "查看停运日期", 16, 19, LIGHTRED);*/
		//查看停运日期
		draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
		//点击退出
	}
	
	
}

/*
FUNCTION:显示乘客姓名
INPUT：乘客代号identity
RETURN：无
*/

/*int Pass_Name(int identity)
{
	int flag=0;
	int n=0;
	FILE* fp;
	PASSENGER* p;//用于储存乘客信息
	while(!feof(fp))
	{
		if((fp=fopen("C:\\TRY\\TEXT\\pass.dat","rb+"))==NULL)//打开数据
		{
			printf("\nError on open pass.dat");
			delay(3000);
			exit(1);
		}
		
		//遍历所有乘客信息
		
		fscanf(fp, "%d", &p->number);
		fgetc(fp);
		fscanf(fp, "%s", p->name);
		fgetc(fp);
		fgets(p->telephone, 12, fp);
		fgetc(fp);
		fgets(p->ID, 19, fp);
		fgetc(fp);
		fgets(p->age, 3, fp);
		fgetc(fp);
		fgets(p->sex, 3, fp);
		fgetc(fp);
		
		/*
		fscanf(fp,"%d",&p->number);    fgetc(fp);//使文件指针向后移
        fscanf(fp,"%s",p->name);       fgetc(fp);
		fgets(p->telephone,12,fp);     fgetc(fp);
		fgets(p->ID,19,fp);            fgetc(fp);
		fgets(p->age,3,fp);            fgetc(fp);
		fgets(p->sex,3,fp);            fgetc(fp);*/
		
		/*if(p->number==identity)
		{
			puthz(502,30,"您好，",16,17,LIGHTBLUE);
			puthz(553,30,p->name,16,17,LIGHTBLUE);
			puthz(601,30,"!",16,17,LIGHTBLUE);
			if(p!=NULL)//释放内存
			{
				free(p);
				p=NULL;
			}	
			break;
		}	
		
		if(p!=NULL)//释放内存
		{
			free(p);
			p=NULL;
		}
	}
	
	if(p!=NULL)//释放内存
	{
		free(p);
		p=NULL;
	}
	
	if(fclose(fp)!=0)//关闭文件
	{
		printf("\n Error on close pass.dat1!");
		delay(3000);
		exit(1);
	}
	
	return 0;
	
}*/





/*
FUNCTION:Pass_Tag
INPUT:乘客代号identity
RETURN：乘客状态flag
*/

int Pass_Tag(int identity)
{
	int l;
	int i;
	int flag=0;//记录乘客状态
	FILE* fp;
	STATE* s=NULL;
	
	if((fp=fopen(".\\TEXT\\STATE.dat","rb+"))==NULL)
	{
		printf("\n Error on open file STATE.dat!");
		delay(3000);
		exit(1);
	}
	
	fseek(fp,0,SEEK_END);//文件指针定位到最后一位
	l=ftell(fp)/sizeof(STATE);//计算总数据条数
	for(i=0;i<l;i++)
	{
		if((s=(STATE*)malloc(sizeof(STATE)))==NULL)
		{
			printf("\n Memory is not enough!");
			delay(3000);
			exit(1);
		}
		
		fseek(fp,i*sizeof(STATE),SEEK_SET);
		fread(s,sizeof(STATE),1,fp);
		
		if(identity==s->number)
		{
			if(s->patient!=0)//乘客被标记为确诊患者
			{
				flag=3;
			}
		    else if(s->contact==1)//乘客被标记为密切接触者
			{
				flag=2;
			}
			else//乘客被标记为健康状态
			{
				flag=1;
			}
			
			if(s!=NULL)
			{
				free(s);
				s=NULL;
			}
			break;
		}
		
		if(s!=NULL)
		{
			free(s);
			s=NULL;
		}
	}
	
	if(fclose(fp)!=0)
	{
		printf("\n Error on close STATE.dat!");
		delay(3000);
		exit(1);
	}
	
	return flag;
}





/*
FUNCTION:乘客界面按钮恢复
INPUT：无
RETURN：无
*/
int Pass_Darken()
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, WHITE);
	cover(492, 80, 619, 105, WHITE);
	highlight(492, 80, 619, 105, LIGHTRED);
	puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTRED);
	//查看乘车记录
	/*cover(492, 395+2-20, 619, 415+2-20, WHITE);
	highlight(492, 395+2-20, 619, 415+2-20, LIGHTRED);
	puthz(492 + 10, 400-20, "查看停运日期", 16, 19, LIGHTRED);*/
	//查看停运日期
}




/*
FUNCTION:乘客界面按钮点亮
INPUT：点亮控制变量flag
RETURN:无
*/
int Pass_Lighten(int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	switch(flag)
	{
		case 1:
		setfillstyle(1, WHITE);
		setcolor(CYAN);
		bar(492, 80, 619, 105);
		cover(492, 80, 619, 105, WHITE);
	    highlight(492, 80, 619, 105, LIGHTMAGENTA);
	    puthz(492 + 10, 86, "查看乘车记录", 16, 19, LIGHTMAGENTA);
		break;
	    //查看乘车记录
	    /*case 2:
		setfillstyle(1, WHITE);
		setcolor(CYAN);
		bar(492, 395+2-20, 619, 415+2-20);
	    cover(492, 395+2-20, 619, 415+2-20, WHITE);
	    highlight(492, 395+2-20, 619, 415+2-20, LIGHTMAGENTA);
	    puthz(492 + 10, 400-20, "查看停运日期", 16, 19, LIGHTMAGENTA);
		break;*/
	    //查看停运日期
	}
}