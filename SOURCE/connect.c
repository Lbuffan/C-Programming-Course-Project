#include "public.h"
#include "connect.h"
/*
FUNCTION:Connect
DESCRIPTION:追踪密接乘客
INPUT:PAGE
RETURN:NO
*/
void Connect(int* page)
{
	int flag=0; //标记点亮
	int a[10]={0}; //存储确诊乘客代号
	int j=0;
	int k=0;
	int i=0; //当前乘车记录
	int amount=0; //记录总数
	RECORD r[35]; //存储乘车记录

	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	cleardevice();

	Draw_Connect();
	Patient_Search(a); //获取确诊乘客代号
	//printf("%d\n%d",a[0],a[1]);
	while(a[j]!=0)
	{
		amount=amount+Connect_Get(a[j],&r[k]); //获取相关乘车记录
		j++;k=k+3;
	}
	j=0;
	if(r==NULL) //如果没有获取到相关乘车记录，给予相关提示
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"暂无信息",24,24,RED);
		delay(1500);
		*page=7; //返回上一界面
		return;
	}
	else
	{
		Connect_Show(r[j]); //显示一次相关乘车记录
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
		            clrmous(MouseX,MouseY);
					Connect_Lighten(1);
					flag=1;
				}
				continue;
			}
			else if(mouse_press(84,293+35,188,346+35)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Connect_Lighten(1);
				if(i==0) //上一条为空，给予提示
				{
					setfillstyle(1,WHITE);
					bar(84, 293+35, 84 + 104, 293 + 53+35);
					puthz(101,347,"暂无更多",16,20,RED);
					delay(1000);
					cover(84, 293+35, 84 + 104, 293 + 53+35, LIGHTBLUE);
	                highlight(84, 293+35, 84 + 104, 293 + 53+35, RED);
	                puthz(98, 308+35, "上一条", 24, 26, WHITE);
				}
				else //显示上一条乘车记录
				{
					j--;
					i--;
				    Connect_Show(r[j]);
				    delay(100);
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
		            clrmous(MouseX,MouseY);
					Connect_Lighten(2);
					flag=2;
				}
				continue;
			}
			else if(mouse_press(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Connect_Lighten(2);
				if(i==amount-1) //下一条为空
				{
					setfillstyle(1,WHITE);
					bar(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35);
					puthz(432.5+20+15,347,"暂无更多",16,20,RED);
					delay(2000);
					cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTBLUE);
	                highlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35, RED);
	                puthz(461-12+15, 308+35, "下一条", 24, 26, WHITE);
				}
				else //显示下一条乘车记录
				{
					j++;
					i++;
				    Connect_Show(r[j]);
				    delay(100);
				}
				continue;
			}
		}
		if(MouseX>255&&MouseX<359&& MouseY>293+35&& MouseY<346+35)//密接追踪
		{
			if(mouse_press(255,293+35,359,346+35)==2)
			{
				MouseS=1;
				if(flag==0)
				{
		            clrmous(MouseX,MouseY);
					Connect_Lighten(3);
					flag=3;
				}
				continue;
			}
			else if(mouse_press(255,293+35,359,346+35)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Connect_Lighten(3);
				/*page=731;
				break;*/
				Find(&r[j]); //进行密接追踪
				clrmous(MouseX,MouseY);
	            delay(100);
	            save_bk_mou(MouseX,MouseY);
	            cleardevice();
	            Draw_Connect();
				Connect_Show(r[j]);
				continue;
			}
	    }
		if(MouseX>55+450&&MouseX<160+450&&MouseY>437&&MouseY<457)//退出
		{
			if(mouse_press(55+450,437,160+450,457)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(55+450,437,160+450,457)==1)
			{
				MouseS=0;
				//Ad2_Connect_Delete(head);
				*page=7;
				break;
			}
		}
        if(flag!=0) //还原操作框
		{
			if(flag==1)
			{
				clrmous(MouseX,MouseY);
				Connect_Darken(1);
			}
			if(flag==2)
			{
				clrmous(MouseX,MouseY);
				Connect_Darken(2);
			}
			if(flag==3)
			{
				clrmous(MouseX,MouseY);
				Connect_Darken(3);
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
FUNCTION:Draw_Connect
DESCRIPTION:绘制卫生部门查看确诊患者关联车次界面
INPUT:无
RETURN:无
*/
int Draw_Connect()
{
	int d=12;
	cleardevice();
	setbkcolor(DARKGRAY);
	cover(35, 69+20, 35 + 573, 305 + 83+30, LIGHTGRAY);
	highlight(35, 69+20, 35 + 573, 305 + 83+30, LIGHTGREEN);//background
	//可以修改底框 填充色 文字色
	setfillstyle(1,BLUE);
	bar(130,23,524,63);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(LIGHTGREEN);
	rectangle(130,23,524,63);
	cover(130,23,524,63,GREEN);
	puthz(140,30,"请选择确诊患者的乘车记录",24,32,WHITE);
	//search_choose_words_bk(90, 100+15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 100+15 + 4.75, "确诊乘客", 16, 17, BLACK);
	//search_choose_words_bk(90, 140 + 15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 140 +15 + 4.75, "关联车次", 16, 17, BLACK);
	//search_choose_words_bk(90, 180 +15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 180 + 15 + 4.75, "乘车日期", 16, 17, BLACK);
	//search_choose_words_bk(90, 220 + 15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 220 + 15 + 4.75, "上车站点", 16, 17, BLACK);
	//search_choose_words_bk(90, 260 + 15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 260 + 15 + 4.75, "下车站点", 16, 17, BLACK);

	//*************需要填写24号字
	setcolor(LIGHTGREEN);
	setlinestyle(1, 0, 3);
	line(200, 135, 470, 135);//姓名
	line(200, 175, 470, 175);//车次
	line(200, 215, 470, 215);//车厢
	line(200, 255, 470, 255);//上车站点
	line(200, 295, 470, 295);//下车站点

	cover(84, 293+35, 84 + 104, 293 + 53+35, WHITE);
	highlight(84, 293+35, 84 + 104, 293 + 53+35, LIGHTGREEN);
	puthz(110-d, 308+35, "上一条", 24, 26, LIGHTBLUE);
	cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,WHITE);
	highlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTGREEN);
	puthz(461 - d+15, 308+35, "下一条", 24, 26, LIGHTBLUE);
	cover(255, 293+35,385, 293 + 53+35, WHITE);
	highlight(255, 293+35,385, 293 + 53+35, LIGHTGREEN);
	puthz(270, 308+35, "密接追踪", 24, 26, LIGHTBLUE);
	draw_exit(60+450, 440, GREEN,WHITE, BLUE, CYAN);
}
/*
FUNCTION:Connect_Lighten()
DESCRIPTION:点亮
INPUT:flag
RETURN:NO
*/
int Connect_Lighten(int flag)
{
	switch(flag)
	{
		case 1:
			cover(84, 293+35, 84 + 104, 293 + 53+35, LIGHTBLUE);
			highlight(84, 293+35, 84 + 104, 293 + 53+35, LIGHTGREEN);
			puthz(110-12, 308+35, "上一条", 24, 26, WHITE);
			break;
		case 2:
			cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTBLUE);
			highlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTGREEN);
			puthz(461 - 12+15, 308+35, "下一条", 24, 26, WHITE);
			break;
		case 3:
			cover(255, 293+35,385, 293 + 53+35,LIGHTBLUE);
			highlight(255, 293+35,385, 293 + 53+35, LIGHTGREEN);
			puthz(270, 308+35, "密接追踪", 24, 26, WHITE);
			break;
	}
}
/*
FUNCTION:Connect_Darken()
DESCRIPTION:恢复
INPUT:flag
RETURN:NO
*/
int Connect_Darken(int flag)
{
	switch(flag)
	{
		case 1:
			cover(84, 293+35, 84 + 104, 293 + 53+35, WHITE);
			highlight(84, 293+35, 84 + 104, 293 + 53+35, LIGHTGREEN);
			puthz(110-12, 308+35, "上一条", 24, 26, LIGHTBLUE);
			break;
		case 2:
			cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,WHITE);
			highlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTGREEN);
			puthz(461 - 12+15, 308+35, "下一条", 24, 26, LIGHTBLUE);
			break;
		case 3:
			cover(255, 293+35,385, 293 + 53+35, WHITE);
			highlight(255, 293+35,385, 293 + 53+35, LIGHTGREEN);
			puthz(270, 308+35, "密接追踪", 24, 26, LIGHTBLUE);
			break;
	}
}
/*
FUNCTION:Connect_Get
DESCRIPTION:获取确诊患者信息
INPUT:乘客代号a，存储乘客乘车记录的结构体数组
RETURN:amount
*/
int Connect_Get(int n,struct Record* R)
{
	int flag=0;
	FILE* fp;
	int i=0;
	int amount=0;
	char tool[30]; //读掉不需要的字符串
	RECORD* r=NULL; //临时存储乘车记录

	if ((fp = fopen("C:\\TRY\\TEXT\\record.dat", "rb+")) == NULL) //打开文件
	{
		printf("\nError on open record.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_SET);
	while(!feof(fp))
	{
		if((r=(RECORD*)malloc(sizeof(RECORD)))==NULL) //分配空间
	    {
		    printf("\nMemory not enough!");
            delay(3000);
			exit(1);
	    }
		fscanf(fp,"%d",&r->contact); //读一次乘车记录
		if(r->contact==-1)
		{
			break;
		}
		fgetc(fp);
		fscanf(fp,"%d",&r->number);
		fgetc(fp);
		fscanf(fp,"%s",r->name);
		fgetc(fp);
		fgets(r->telephone,12,fp);
		fgetc(fp);
		fgets(r->ID,19,fp);
		fgetc(fp);
		fgets(r->age,3,fp);
		fgetc(fp);
		fgets(r->sex,3,fp);
		fgetc(fp);
		fscanf(fp,"%d",&r->week);
		fgetc(fp);
		fscanf(fp,"%d",&r->subway_number[0]);
		fgetc(fp);
		fscanf(fp,"%d",&r->subway_number[1]);
		fgetc(fp);
		fscanf(fp,"%d",&r->subway_number[2]);
		fgetc(fp);
		fscanf(fp,"%d",&r->origin);
		fgetc(fp);
		fscanf(fp,"%d",&r->transfer);
		fgetc(fp);
		fscanf(fp,"%d",&r->terminal);
		//printf("%d",r->number);getchar();
		//printf("%d",n);
		if(n==r->number) //读到当前乘客的乘车记录
		{
			flag==1; //标记已经找到当前乘客乘车记录
			R->contact=r->contact;
			R->number=r->number;
			strcpy(R->name,r->name);
			strcpy(R->telephone,r->telephone);
			strcpy(R->ID,r->ID);
			strcpy(R->age,r->age);
			strcpy(R->sex,r->sex);
			R->origin=r->origin;
			R->transfer=r->transfer;
			R->terminal=r->terminal;
			R->week=r->week;
			R->subway_number[1]=r->subway_number[1];
			R->subway_number[2]=r->subway_number[2];
			R->subway_number[0]=r->subway_number[0];
			//printf("%d",R->subway_number[0]);
			amount++;
			R++;
		}
        if(r!=NULL)
		{
			free(r);
			r=NULL;
	    }
		if(n!=r->number&&flag==1)
		{
			break;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close record.dat!");
		delay(3000);
		exit(1);
	}
	return amount;
	//printf("\n\n\n\n\n\n\nhh");
	//puts(R->name);
}
/*
FUNCTION:Connect_Show
DESCRIPTION:显示确诊患者的关联车次
INPUT:存储确诊患者乘车记录的结构体r
RETURN:无
*/
int Connect_Show(struct Record r)
{
	char origin[5];
	char terminal[5];
	setfillstyle(1,LIGHTGRAY); //遮盖之前显示的信息
	bar(200,113,470,133);
	bar(200,150,470,173);
    bar(200,184,470,213);
    bar(200,233,470,253);
	bar(200,273,470,293);
	switch(r.origin)
	{
		case 1:
			puthz(200,238, "泾河", 16,28, WHITE);
			break;
		case 2:
			puthz(200,238, "五环大道", 16,28, WHITE);
			break;
		case 3:
			puthz(200,238, "宗关", 16,28, WHITE);
			break;
		case 4:
			puthz(200,238, "崇仁路", 16,28, WHITE);
			break;
		case 5:
			puthz(200,238, "循礼门", 16,28, WHITE);
			break;
		case 6:
			puthz(200,238, "汉口北", 16,28, WHITE);
			break;
		case 7:
			puthz(200,238, "罗家庄", 16,28, WHITE);
			break;
		case 8:
			puthz(200,238, "云飞路", 16,28, WHITE);
			break;
		case 9:
			puthz(200,238, "龙阳村", 16,28, WHITE);
			break;
		case 10:
			puthz(200,238, "陶家岭", 16,28, WHITE);
			break;
		case 11:
			puthz(200,238, "三角湖", 16,28, WHITE);
			break;
		case 12:
			puthz(200,238, "沌阳大道", 16,28, WHITE);
			break;
		case 13:
			puthz(200,238, "天河机场", 16,28, WHITE);
			break;
		case 14:
			puthz(200,238, "巨龙大道", 16,28, WHITE);
			break;
		case 15:
			puthz(200,238, "金谭路", 16,28, WHITE);
			break;
		case 16:
			puthz(200,238, "江汉路", 16,28, WHITE);
			break;
		case 17:
			puthz(200,238, "光谷广场", 16,28, WHITE);
			break;
		case 18:
			puthz(200,238, "佛祖岭", 16,28, WHITE);
			break;
	}
	switch(r.terminal)
	{
		case 1:
			puthz(200,278, "泾河", 16,28, WHITE);
			break;
		case 2:
			puthz(200,278, "五环大道", 16,28, WHITE);
			break;
		case 3:
			puthz(200,278, "宗关", 16,28, WHITE);
			break;
		case 4:
			puthz(200,278, "崇仁路", 16,28, WHITE);
			break;
		case 5:
			puthz(200,278, "循礼门", 16,28, WHITE);
			break;
		case 6:
			puthz(200,278, "汉口北", 16,28, WHITE);
			break;
		case 7:
			puthz(200,278, "罗家庄", 16,28, WHITE);
			break;
		case 8:
			puthz(200,278, "云飞路", 16,28, WHITE);
			break;
		case 9:
			puthz(200,278, "龙阳村", 16,28, WHITE);
			break;
		case 10:
			puthz(200,278, "陶家岭", 16,28, WHITE);
			break;
		case 11:
			puthz(200,278, "三角湖", 16,28, WHITE);
			break;
		case 12:
			puthz(200,278, "沌阳大道", 16,28, WHITE);
			break;
		case 13:
			puthz(200,278, "天河机场", 16,28, WHITE);
			break;
		case 14:
			puthz(200,278, "巨龙大道", 16,28, WHITE);
			break;
		case 15:
			puthz(200,278, "金谭路", 16,28, WHITE);
			break;
		case 16:
			puthz(200,278, "江汉路", 16,28, WHITE);
			break;
		case 17:
			puthz(200,278, "光谷广场", 16,28, WHITE);
			break;
		case 18:
			puthz(200,278, "佛祖岭", 16,28, WHITE);
			break;
	}

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	setcolor(WHITE);
	puthz(200,117,r.name,16,17,WHITE);
	//outtextxy(200,153,r.train_number); //显示车次
	//outtextxy(250,153,r.carriage);
	//puthz(268,157,"车",16,16,WHITE);
	//outtextxy(295,153,r.sit);
	//puthz(330,157,"座",16,16,WHITE);
	if((r.origin>=1&&r.origin<=6||r.terminal>=1&&r.terminal<=6)&&(r.origin>=7&&r.origin<=12||r.terminal>=7&&r.terminal<=12)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"1");
		outtextxy(250,145,"2");
	}
	else if((r.origin>=1&&r.origin<=6||r.terminal>=1&&r.terminal<=6)&&(r.origin>=13&&r.origin<=18||r.terminal>=13&&r.terminal<=18)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"1");
		outtextxy(250,145,"3");
	}
	else if((r.origin>=13&&r.origin<=18||r.terminal>=13&&r.terminal<=18)&&(r.origin>=7&&r.origin<=12||r.terminal>=7&&r.terminal<=12)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"2");
		outtextxy(250,145,"3");
	}
	else if((r.origin>=1&&r.origin<=6||r.terminal>=1&&r.terminal<=6)&&(r.origin>=1&&r.origin<=6||r.terminal>=1&&r.terminal<=6)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"1");
	}
	else if((r.origin>=7&&r.origin<=12||r.terminal>=7&&r.terminal<=12)&&(r.origin>=7&&r.origin<=12||r.terminal>=7&&r.terminal<=12)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"2");
	}
	else if((r.origin>=13&&r.origin<=18||r.terminal>=13&&r.terminal<=18)&&(r.origin>=13&&r.origin<=18||r.terminal>=13&&r.terminal<=18)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"3");
	}
	/*outtextxy(200,193,"2022"); *///显示年月日
	puthz(257,197,"年",16,28,WHITE);
	//outtextxy(275,193,r.month);
	puthz(295,197,"月",16,28,WHITE);
	//outtextxy(315,193,r.day);
	puthz(342,197,"日",16,28,WHITE);
	switch(r.week)
	{
		case 7:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(WHITE);
			outtextxy(200,184,"2022");
			outtextxy(275,184,"4");
			outtextxy(315,184,"22");
			break;
		case 6:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(WHITE);
			outtextxy(200,184,"2022");
			outtextxy(275,184,"4");
			outtextxy(315,184,"21");
			break;
		case 5:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(WHITE);
			outtextxy(200,184,"2022");
			outtextxy(275,184,"4");
			outtextxy(315,184,"20");
			break;
		case 4:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(WHITE);
			outtextxy(200,184,"2022");
			outtextxy(275,184,"4");
			outtextxy(315,184,"19");
			break;
		case 3:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(WHITE);
			outtextxy(200,184,"2022");
			outtextxy(275,184,"4");
			outtextxy(315,184,"18");
			break;
		case 2:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(WHITE);
			outtextxy(200,184,"2022");
			outtextxy(275,184,"4");
			outtextxy(315,184,"17");
			break;
		case 1:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(WHITE);
			outtextxy(200,184,"2022");
			outtextxy(275,184,"4");
			outtextxy(315,184,"16");
			break;
	}
	//puthz(200,238,origin,16,28,WHITE);
	//puthz(200,278,terminal,16,28,WHITE);
}

