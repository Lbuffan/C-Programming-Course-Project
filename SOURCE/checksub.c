#include"public.h"
#include"Checksub.h"

/*
FUNCTION:Checksub
DESCRIPTION:铁路管理员查看涉疫车次
INPUT:界面跳转控制变量page
RETURN:无
*/
void Checksub(int* page)
{
	int flag=0; //标记点亮
	int a[10]={0}; //存储确诊乘客代号
	TRAIN* head; //链表表头
	TRAIN* t; //对链表进行操作
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	
	Draw_Checksub();
	
	Checksub_Search(a);
	
	head=Checksub_Get(a); //获取确诊乘客的乘车记录，存入链表
	t=head;
	
	if(t==NULL) //如果没有获取到任何乘车记录，给予相关提示
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"暂无信息",24,24,RED);
		delay(3000);
		*page=8;
		return;
	}
	else
	{
		Checksub_Show(t); //显示一次相关乘车记录
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>84&&MouseX<188&& MouseY>293+35&& MouseY<346+35)//上一条
		{
			if(mouse_press(84,293+35,188,346+35)==2)               
			{
				MouseS=1;                                   
				if(flag==0)                  
				{
		            Checksub_Lighten(4);
					flag=4;                               
				}
				continue;
			}
			else if(mouse_press(84,293+35,188,346+35)==1)        
			{
				MouseS=0;
				Checksub_Lighten(4);  
				if(t->front==NULL) //上一条为空，给予提示
				{
					setfillstyle(1,WHITE);
					bar(84, 293+35, 84 + 104, 293 + 53+35);
					puthz(101,347,"暂无更多",16,20,RED);
					delay(2000);
					cover(84, 293+35, 84 + 104, 293 + 53+35, LIGHTBLUE);
	                DOThighlight(84, 293+35, 84 + 104, 293 + 53+35, RED);
	                puthz(98, 308+35, "上一条", 24, 26, WHITE);
				}
				else //显示上一条乘车记录
				{
					t=t->front;
				    Checksub_Show(t);
				    delay(200);
				}
				continue;
			}
	    }
		if(MouseX>435.5&&MouseX<435.5+107&& MouseY>293+35&& MouseY<293+53+35)//下一条
		{
			if(mouse_press(432.5+3, 293+35, 432.5 + 107, 293 + 53+35)==2)               
			{
				MouseS=1;                                   
				if(flag==0)                  
				{
		            Checksub_Lighten(6);
					flag=6;                               
				}
				continue;
			}
			else if(mouse_press(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35)==1)        
			{
				MouseS=0;
				Checksub_Lighten(6);
				if(t->next==NULL) //下一条为空
				{
					setfillstyle(1,WHITE);
					bar(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35);
					puthz(432.5+20+15,347,"暂无更多",16,20,RED);
					delay(2000);
					cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTBLUE);
	                DOThighlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35, RED);
	                puthz(461-12+15, 308+35, "下一条", 24, 26, WHITE);
				}
				else //显示下一条乘车记录
				{
					t=t->next;
				    Checksub_Show(t);
				    delay(200);
				}
				continue;
			}
		}
		/*if (MouseX>255 && MouseX<359 && MouseY>293 + 35 && MouseY<346 + 35)//已确认
		{
			if(mouse_press(255,293+35,359,346+35)==2)               
			{
				MouseS=1;                                   
				if(flag==0)                  
				{
		            Checksub_Lighten(5);
					flag=5;                               
				}
				continue;
			}
			else if(mouse_press(255,293+35,359,346+35)==1)        
			{
				MouseS=0;
				Checksub_Lighten(5);  
				Checksub_Delete(head); //销毁链表
				cleardevice();
				*page=8; //返回铁路管理员主界面
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
			    *page =6;
				break;				
			}
		}
		
        if(flag!=0) //还原操作框
		{
			if(flag==4)
			{
				Checksub_Darken(4);
			}
			if(flag==5)
			{
				Checksub_Darken(5);
			}
			if(flag==6)
			{
				Checksub_Darken(6);
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
FUNCTION:
DESCRIPTION:获取确诊乘客代号
INPUT:用来存储确诊乘客代号的数组a
RETURN:无
*/
int Checksub_Search(int* a) //获取确诊者乘客代号
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
		if(s->patient!=0) //如果某位乘客被标记为确诊
		{
            *a=s->number; //将确诊乘客代号录入数组
            a++;
        }			
		if(s!=NULL)                                              //释放内存
		{
			free(s);
			s=NULL;
		}
	}
	if (fclose(fp) != 0) //关闭文件
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
}


/*
FUNCTION:Checksub_Get
DESCRIPTION:获取涉疫车次信息
INPUT:存储确诊患者代号的数组a
RETURN:存储涉疫车次信息的链表表头
*/
struct Train* Checksub_Get(int* a)
{
	int flag=0;
	FILE* fp;
	int i=0;
	RECORD* r; //临时存储乘车记录
	TRAIN* phead=NULL; //建立链表
    TRAIN* pnew;
    TRAIN* pend; 
	
	if ((fp = fopen(".\\TEXT\\record.dat", "rb+")) == NULL) //打开文件
	{
		printf("\nError on open record.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_SET);
	while(!feof(fp))
	{
		if(*a==0)
		{
			break;
		}
		if((r=(RECORD*)malloc(sizeof(RECORD)))==NULL) //分配空间             
	    {
		    printf("\nMemory not enough!");
            delay(3000);
			exit(1);
	    } 
		fscanf(fp,"%d",&r->contact);   fgetc(fp);
		if(r->contact==-1)
		{
			break;
		}
		fscanf(fp,"%d",&r->number);              fgetc(fp);
		fscanf(fp,"%s",r->name);                 fgetc(fp);
		fgets(r->telephone,12,fp);               fgetc(fp);
		fgets(r->ID,19,fp);                      fgetc(fp);
		fgets(r->age,3,fp);                      fgetc(fp);
		fgets(r->sex,3,fp);                      fgetc(fp);
		fscanf(fp,"%d",&r->week);                fgetc(fp);
		fscanf(fp,"%d",&r->subway_number[0]);    fgetc(fp);
		fscanf(fp,"%d",&r->subway_number[1]);    fgetc(fp);
		fscanf(fp,"%d",&r->subway_number[2]);    fgetc(fp);
		fscanf(fp,"%d",&r->origin);              fgetc(fp);
		fscanf(fp,"%d",&r->transfer);            fgetc(fp);
		fscanf(fp,"%d",&r->terminal);            
		
		if(*a==r->number) //如当前读到的乘车记录为确诊患者的
		{
			flag=1;
			if((pnew=(TRAIN*)malloc(sizeof(TRAIN)))==NULL) //分配空间                   
	        {
		        printf("\nMemory not enough!");
                delay(3000);
			    exit(1);
	        }  //存储涉疫列车信息
			
			    pnew->week=r->week;
		
			    pnew->line=Line_Search(r->origin,r->transfer);
			    
			    if(pnew->line==1)
				{
					pnew->time=r->subway_number[0];
				}
				
				else if(pnew->line==2)
				{
					pnew->time=r->subway_number[1];
				}
				
				else
				{
					pnew->time=r->subway_number[2];
				}
			
			    pnew->front=NULL;
			    pnew->next=NULL;
	        if(phead==NULL) //存入链表
		    {
			    phead=pnew;
	        }
	        else
	        {
	    	    pend->next=pnew;
	    	    pnew->front=pend;
	        }
	        pend=pnew;
		}
		if(flag==1&&r->number!=*a)
		{
			a++;
			flag=0;
			if(*a==r->number) //如当前读到的乘车记录为确诊患者的
		    {
			    flag=1;
			    if((pnew=(TRAIN*)malloc(sizeof(TRAIN)))==NULL) //分配空间                   
	            {
		            printf("\nMemory not enough!");
                    delay(3000);
			        exit(1);
	            }  //存储涉疫列车信息
			
			    pnew->week=r->week;
		
			    pnew->line=Line_Search(r->origin,r->transfer);
			    
			    if(pnew->line==1)
				{
					pnew->time=r->subway_number[0];
				}
				
				else if(pnew->line==2)
				{
					pnew->time=r->subway_number[1];
				}
				
				else
				{
					pnew->time=r->subway_number[2];
				}
	
			    pnew->front=NULL;
			    pnew->next=NULL;
	            if(phead==NULL) //存入链表
		        {
			        phead=pnew;
	            }
	            else
	            {
	    	        pend->next=pnew;
	    	        pnew->front=pend;
	            }
	            pend=pnew;
		    }
		}
        if(r!=NULL)
		{
			free(r);
			r=NULL;
	    }
	}
	pend->next=NULL;
	if (fclose(fp) != 0)
	{
		printf("\nError on close record.dat!");
		delay(3000);
		exit(1);
	}
    return phead;
}


/*
FUNCTION:Checksub_Delete
DESCRIPTION:销毁存储涉疫车次信息的链表
INPUT:存储涉疫车次信息的链表表头
RETURN:无
*/
int Checksub_Delete(TRAIN* phead)
{
	TRAIN* pcur,*pnext;
	pcur=phead;
	for(pnext=pcur->next;pcur!=NULL;pcur=pnext,pnext=pnext->next)
	{
		free(pcur);
	}
}
/*
FUNCTION:Draw_Checksub
DESCRIPTION:绘制铁路管理员查看涉疫车次界面
INPUT:无
RETURN:无
*/
int Draw_Checksub()
{
	int offset=12;
	cleardevice();
	setbkcolor(DARKGRAY);
	cover(35, 69+20, 35 + 573, 305 + 83+30, LIGHTGRAY);
	
	setcolor(LIGHTMAGENTA);
	setlinestyle(1, 0, 3);
	rectangle(35, 69+20, 35 + 573, 305 + 83+30);
	
	//可以修改底框 填充色 文字色 
	setfillstyle(1,BLUE);
	bar(130,23,524,63);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(LIGHTCYAN);
	rectangle(130,23,524,63);
	puthz(140,30,"欢迎进入查看涉疫列车模式",24,32,WHITE);
	
	//search_choose_words_bk(90, 100+15 + 3, 4, LIGHTRED, WHITE);
	//puthz(91, 100+15 + 4.75, "涉疫车次", 16, 17, BLACK);
	
	search_choose_words_bk(90, 140 + 15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 140 +15 + 4.75, "涉疫日期", 16, 17, BLACK);
	
	search_choose_words_bk(90, 180 +15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 180 + 15 + 4.75, "涉疫线路", 16, 17, BLACK);
	
	search_choose_words_bk(90, 220 + 15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 220 + 15 + 4.75, "发车时间", 16, 17, BLACK);
	
	//search_choose_words_bk(90, 260 + 15 + 3, 4, LIGHTRED, WHITE);
	//puthz(91, 260 + 15 + 4.75, "终止站点", 16, 17, BLACK);

	setcolor(LIGHTMAGENTA);
	setlinestyle(1, 0, 3);
	line(200, 135, 470, 135);
	line(200, 175, 470, 175);
	line(200, 215, 470, 215);
	line(200, 255, 470, 255);
	line(200, 295, 470, 295);
	
	cover(84, 293+35, 84 + 104, 293 + 53+35, WHITE);
	DOThighlight(84, 293+35, 84 + 104, 293 + 53+35, LIGHTMAGENTA);
	puthz(110-offset, 308+35, "上一条", 24, 26, LIGHTBLUE);
	//cover(255+12, 293+35, 252 + 107+12, 293 + 53+35, WHITE);
	//DOThighlight(255+12, 293+35, 252 + 107+12, 293 + 53+35, LIGHTMAGENTA);
	//puthz(282 - offset+12, 308+35, "已确认", 24, 26, LIGHTBLUE);
	cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,WHITE);
	DOThighlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTMAGENTA);
	puthz(461 - offset+15, 308+35, "下一条", 24, 26, LIGHTBLUE);
	
	draw_exit(525, 450, LIGHTGRAY,BROWN,GREEN,GREEN);
}



/*
FUNCTION:Checksub_Show
DESCRIPTION:显示涉疫车次信息
INPUT:存储涉疫车次信息的链表表头
RETURN:无
*/
int Checksub_Show(struct Train* train) //显示一次乘车记录信息
{
	char number[10];
	
	setfillstyle(1,LIGHTGRAY); //遮盖之前显示的信息
	bar(200,113,470,133);
	bar(200,153,470,173);
    bar(200,193,470,213);
    bar(200,233,470,253);	
	bar(200,273,470,293);
	
	//Sta_Search(train->origin,origin); //获取起点站名
	//Sta_Search(train->transfer,transfer); //获取中转站名
	//Sta_Search(train->terminal,terminal); //获取终点站名
	
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	setcolor(WHITE);
	
	
	
	puthz(250+20,157+3,"年",16,28,WHITE);
	puthz(295+30,157+3,"月",16,28,WHITE);
	puthz(340+30+10,157+3,"日",16,28,WHITE);
	
	switch(train->week)
	{
		case 7:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(200,153,"2022");
			outtextxy(200+103,153,"4");
			outtextxy(200+103+40,153,"22");
			break;
		case 6:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(200,153,"2022");
			outtextxy(200+103,153,"4");
			outtextxy(200+103+40,153,"21");
			break;
		case 5:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(200,153,"2022");
			outtextxy(200+103,153,"4");
			outtextxy(200+103+40,153,"20");
			break;
		case 4:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(200,153,"2022");
			outtextxy(200+103,153,"4");
			outtextxy(200+103+40,153,"19");
			break;
		case 3:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(200,153,"2022");
			outtextxy(200+103,153,"4");
			outtextxy(200+103+40,153,"18");
			break;
		case 2:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(200,153,"2022");
			outtextxy(200+103,153,"4");
			outtextxy(200+103+40,153,"17");
			break;
		case 1:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(200,153,"2022");
			outtextxy(200+103,153,"4");
			outtextxy(200+103+40,153,"16");
			break;
	}
	
	switch(train->time)
		{
			case 1:
				strcpy(number,"6:00");
				break;
			case 2:
				strcpy(number,"6:20");
				break;
			case 3:
				strcpy(number,"6:40");
				break;
			case 4:
				strcpy(number,"7:00");
				break;
			case 5:
				strcpy(number,"7:20");
				break;
			case 6:
				strcpy(number,"7:40");
				break;
			case 7:
				strcpy(number,"8:00");
				break;
			case 8:
				strcpy(number,"8:20");
				break;
			case 9:
				strcpy(number,"8:40");
				break;
			case 10:
				strcpy(number,"9:00");
				break;
			case 11:
				strcpy(number,"9:20");
				break;
			case 12:
				strcpy(number,"9:40");
				break;
			case 13:
				strcpy(number,"10:00");
				break;
			case 14:
				strcpy(number,"10:20");
				break;
			case 15:
				strcpy(number,"10:40");
				break;
			case 16:
				strcpy(number,"11:00");
				break;
			case 17:
				strcpy(number,"11:20");
				break;
			case 18:
				strcpy(number,"11:40");
				break;
			case 19:
				strcpy(number,"12:00");
				break;
			case 20:
				strcpy(number,"12:20");
				break;
			case 21:
				strcpy(number,"12:40");
				break;
			case 22:
				strcpy(number,"13:00");
				break;
			case 23:
				strcpy(number,"13:20");
				break;
			case 24:
				strcpy(number,"13:40");
				break;
			case 25:
				strcpy(number,"14:00");
				break;
			case 26:
				strcpy(number,"14:20");
				break;
			case 27:
				strcpy(number,"14:40");
				break;
			case 28:
				strcpy(number,"15:00");
				break;
			case 29:
				strcpy(number,"15:20");
				break;
			case 30:
				strcpy(number,"15:40");
				break;
			case 31:
				strcpy(number,"16:00");
				break;
			case 32:
				strcpy(number,"16:20");
				break;
			case 33:
				strcpy(number,"16:40");
				break;
			case 34:
				strcpy(number,"17:00");
				break;
			case 35:
				strcpy(number,"17:20");
				break;
			case 36:
				strcpy(number,"17:40");
				break;
			case 37:
				strcpy(number,"18:00");
				break;
			case 38:
				strcpy(number,"18:20");
				break;
			case 39:
				strcpy(number,"18:40");
				break;
			case 40:
				strcpy(number,"19:00");
				break;
			case 41:
				strcpy(number,"19:20");
				break;
			case 42:
				strcpy(number,"19:40");
				break;
			case 43:
				strcpy(number,"20:00");
				break;
			case 44:
				strcpy(number,"20:20");
				break;
			case 45:
				strcpy(number,"20:40");
				break;
			case 46:
				strcpy(number,"21:00");
				break;
			case 47:
				strcpy(number,"21:20");
				break;
			case 48:
				strcpy(number,"21:40");
				break;
			case 49:
				strcpy(number,"22:00");
				break;
			case 50:
				strcpy(number,"22:20");
				break;
			case 51:
				strcpy(number,"22:40");
				break;
				
		}
	if(train->line==1)
	{
		outtextxy(200,190,"1");
	}
	else if(train->line==2)
	{
		outtextxy(200,190,"2");
	}
	else
	{
		outtextxy(200,190,"3");
	}
	
	outtextxy(200,238-10,number);
	//puthz(200,278,terminal,16,28,WHITE);
}


/*
FUNCTION:Checksub_Lighten
DESCRIPTION:铁路管理员查看涉疫列车功能界面按钮点亮
INPUT:点亮控制变量flag
RETURN:无
*/
int Checksub_Lighten(int flag)
{
	int x = 472;//***********坐标
	int y = 120;
	int h = 41;
	int w = 165;
	int a = 5;
	int b = 2;
	int offset = 12;
	int offset1=15;
	clrmous(MouseX,MouseY);
	delay(10);
	
	switch(flag)
	{
		case 1:
		    cover(x, y, x + w, y + h, LIGHTGRAY);//******查看涉疫列车跳转框
	        highlight(x, y, x + w, y + h, YELLOW);
	        puthz(x + a, y + b+5, "查看涉疫列车", 24, 26, LIGHTBLUE);
			break;
		case 2:
	        cover(x, y + h+25, x + w, y + h + h+25, LIGHTGRAY);//******调整运行时刻跳转框
	        highlight(x, y + h+25, x + w, y + h + h+25, YELLOW);
	        puthz(x + a, y + b+h+5+25, "调整运行时刻", 24, 26, LIGHTBLUE);
			break;
		case 3:
		    cover(x, y + 2 * h+50, x + w, y + h + 2 * h+50, LIGHTGRAY);//******查看关联乘客
	        highlight(x, y + 2 * h+50, x + w, y + h + 2 * h+50, YELLOW);
	        puthz(x + a, y + b+2 * h+5+50, "查看关联乘客", 24, 26, LIGHTBLUE);
		    break;
		case 4:
		    cover(84, 293+35, 84 + 104, 293 + 53+35, LIGHTBLUE);
	        DOThighlight(84, 293+35, 84 + 104, 293 + 53+35, RED);
	        puthz(110-offset, 308+35, "上一条", 24, 26, WHITE);
			break;
		/*case 5:
		    cover(255+12, 293+35, 252 + 107+12, 293 + 53+35, LIGHTBLUE);
	        DOThighlight(255+12, 293+35, 252 + 107+12, 293 + 53+35, RED);
	        puthz(282 - offset+12, 308+35, "已确认", 24, 26, WHITE);
			break;*/
		case 6:
		    cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTBLUE);
	        DOThighlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35, RED);
	        puthz(461 - offset+15, 308+35, "下一条", 24, 26, WHITE);
			break;
		case 7:
		    cover(183, 390, 183 + 295, 390 + 37, BROWN);
	        highlight(183, 390, 183 + 295, 390 + 37, CYAN);
	        puthz(255 + 10, 392, "查询车次", 32, 32, WHITE);
			break;
		case 8:
		    search_choose_enter_24bk(69 + 250+3, 155, 4, LIGHTGRAY, LIGHTCYAN);//********列车车次输入框
			break;
		case 9:
		    search_choose_enter_24bk(256 - 80, 256, 4, LIGHTGRAY, LIGHTCYAN);//********年输入框
			break;
		case 10:
		    search_choose_enter_24bk(272 + 20+offset1+15, 256, 2, LIGHTGRAY, LIGHTCYAN);//********月输入框
			break;
		case 11:
		    search_choose_enter_24bk(350 + 24 + offset1+30, 256, 2, LIGHTGRAY, LIGHTCYAN);//********日输入框
			break;
		case 12:
		    cover(90,360,200,410,LIGHTGRAY);//*******上一站
	        DOThighlight(90,360,200,410,GREEN);
	        puthz(108,375, "上一站", 24, 24,LIGHTRED);
			break;
		case 13:
		    cover(440,360,550,410, LIGHTGRAY);//*******下一站
	        DOThighlight(440,360,550,410, GREEN);
	        puthz(458,375, "下一站", 24, 24, LIGHTRED);
		    break;
		case 14:
		    cover(265, 360,375,410, LIGHTGRAY);//*******确认
	        DOThighlight(265, 360,375,410, GREEN);
	        puthz(296,375,"确认",24,24,LIGHTRED);
			break;
		case 15:
		    ring(395, 218, 13, 11, GREEN, WHITE, 2);
			stablack(295,218,11);
			break;
		case 16:
		    ring(295, 218, 13, 11, GREEN, WHITE, 2);
			stablack(395,218,11);
			break;
		case 17:
		    search_choose_enter_24bk(69 + 230+3, 195, 4, LIGHTGRAY, LIGHTCYAN);//********列车车次输入框
			break;
	}
}	

/*
FUNCTION:Checksub_Darken
DESCRIPTION:铁路管理员功能界面按钮恢复
INPUT:恢复控制变量flag
RETURN:无
*/
int Checksub_Darken(int flag)
{
	int x = 472;//***********坐标
	int y = 120;
	int h = 41;
	int w = 165;
	int a = 5;
	int b = 2;
	int offset = 12;
	int offset1=15;
	clrmous(MouseX,MouseY);
	delay(10);
	
	switch(flag)
	{
		case 1:
		    cover(x, y, x + w, y + h, BLUE);//******查看涉疫列车跳转框
	        highlight(x, y, x + w, y + h, YELLOW);
	        puthz(x + a, y + b+5, "查看涉疫列车", 24, 26, WHITE);
		    break;
		case 2:
		    cover(x, y + h+25, x + w, y + h + h+25, BLUE);//******调整运行时刻跳转框
	        highlight(x, y + h+25, x + w, y + h + h+25, YELLOW);
	        puthz(x + a, y + b+h+5+25, "调整运行时刻", 24, 26, WHITE);
			break;
		case 3:
		    cover(x, y + 2 * h+50, x + w, y + h + 2 * h+50, BLUE);//******添查看关联乘客跳转框
	        highlight(x, y + 2 * h+50, x + w, y + h + 2 * h+50, YELLOW);
	        puthz(x + a, y + b+2 * h+5+50, "查看关联乘客", 24, 26, WHITE);
			break;
		case 4:
		    cover(84, 293+35, 84 + 104, 293 + 53+35, WHITE);
	        DOThighlight(84, 293+35, 84 + 104, 293 + 53+35, LIGHTMAGENTA);
	        puthz(110-offset, 308+35, "上一条", 24, 26, LIGHTBLUE);
			break;
		/*case 5:
		    cover(255+12, 293+35, 252 + 107+12, 293 + 53+35, WHITE);
	        DOThighlight(255+12, 293+35, 252 + 107+12, 293 + 53+35, LIGHTMAGENTA);
	        puthz(282 - offset+12, 308+35, "已确认", 24, 26, LIGHTBLUE);
			break;*/
		case 6:
		    cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,WHITE);
	        DOThighlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35, LIGHTMAGENTA);
	        puthz(461 - offset+15, 308+35, "下一条", 24, 26, LIGHTBLUE);
			break;
		case 7:
            cover(183, 390, 183 + 295, 390 + 37, YELLOW);
	        highlight(183, 390, 183 + 295, 390 + 37, CYAN);
	        puthz(255 + 10, 392, "查询车次", 32, 32, RED);		
			break;
		case 8:
		    search_choose_enter_24bk(69 + 250+3, 155, 4, DARKGRAY, LIGHTCYAN);//********列车车次输入框
			break;
		case 9:
	        search_choose_enter_24bk(256 - 80, 256, 4, DARKGRAY, LIGHTCYAN);//********年输入框
			break;
		case 10:
		    search_choose_enter_24bk(272 + 20+offset1+15, 256, 2, DARKGRAY, LIGHTCYAN);//********月输入框
			break;
		case 11:
		    search_choose_enter_24bk(350 + 24 + offset1+30, 256, 2, DARKGRAY, LIGHTCYAN);//********日输入框
			break;
		case 12:
		    cover(90,360,200,410,WHITE);//*******上一站
	        DOThighlight(90,360,200,410,GREEN);
	        puthz(108,375, "上一站", 24, 24, RED);
			break;
		case 13:
		    cover(440,360,550,410, WHITE);//*******下一站
	        DOThighlight(440,360,550,410, GREEN);
	        puthz(458,375, "下一站", 24, 24, RED);
		    break;
		case 14:
		    cover(265, 360,375,410, WHITE);//*******确认
	        DOThighlight(265, 360,375,410, GREEN);
	        puthz(296,375,"确认",24,24,RED);
			break;
		case 17:
		    search_choose_enter_24bk(69 + 230+3, 195, 4, DARKGRAY, LIGHTCYAN);//********列车车次输入框
			break;
	}
}	

int Line_Search(int a,int b)
{
	if(a>0&&a<7&&b>0&&b<7)
	{
		return 1;
	}
	

    else if((a==2||(a>6&&a<13))&&(b==2||(a>6&&a<13)))
	{
		return 2;
	}
	

    else 
	{
		return 3;
	}
}