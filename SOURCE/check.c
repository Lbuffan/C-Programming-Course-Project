#include"public.h"
#include"check.h"

/*
FUNCTION:Patient_Check
DESCRIPTION:卫生部门查询乘客乘车记录
INPUT:乘客身份证号ID
RETURN:无
*/
void Patient_Check(char* ID)
{	
	int i; //标记当前所读乘车记录
	int identity; //记录乘客代号
	int amount; //记录乘车记录总数
	int flag=0; //标记点亮情况
	int tag=0; //标记乘客状态，0为正常，1为密接，2为确诊
	char name[7]; //记录当前乘客姓名
	RECORD R[6]; //记录乘客乘车记录的链表表头
	Station a[18];
	
	clrmous(MouseX, MouseY);
	delay(100);
    save_bk_mou(MouseX, MouseY);
    cleardevice();
	
	Draw_Patient_Check(); //绘制界面
	identity=Patient_Identity_Get(ID,name); //获取当前乘客的代号
	//printf("identity=%d\n",identity);getchar();
	amount=Record_Get(identity,R); //获取当前乘客的乘车记录
	//printf("origin=%d\n",R->origin);getchar();
	i=0;
	Patient_Record(&R[i]); //显示当前乘客的一次乘车记录
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 81 && MouseX < 183 && MouseY> 358 && MouseY < 419)
		{
			if (mouse_press(81, 358, 183, 419) == 2)//查看上一条未点击
			{
				MouseS = 1;
				if (flag==0)//防止被重复标亮
				{
					clrmous(MouseX,MouseY);
					Patient_Lighten2(1);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(81, 358, 183, 419) == 1)//查看上一条框点击
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				Patient_Lighten2(1);
				if(i==0)
				{
					setfillstyle(1, WHITE);
		            bar(81.72, 358.75, 81.72 + 101, 358.75 + 60.5);
		            highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
		            puthz(102,380, "暂无更多",16,16,RED);
		            delay(3000);
				}
				else
				{
					i--;
					Patient_Record(&R[i]);
				}
				delay(200);
				continue;
			}
		}
		if (MouseX > 226 && MouseX < 413 && MouseY> 358 && MouseY < 419)
		{
			if (mouse_press(226, 358, 413, 419) == 2)   //显示轨迹未点击
			{
				MouseS = 1;
				if (flag==0)//防止被重复标亮
				{
					clrmous(MouseX,MouseY);
					Patient_Lighten2(2);
					flag=2;
				}
				continue;
			}
			else if (mouse_press(226, 358, 413, 419) == 1)//显示轨迹点击
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				Patient_Lighten2(2);
				
	
				/*clrmous(MouseX,MouseY);
				delay(100);
				save_bk_mou(MouseX,MouseY);
				cleardevice();*/
				
				map();
				draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
				
				a[1].x=30;
				a[1].y=200;
				a[2].x=100;
				a[2].y=200;
				a[3].x=170;
				a[3].y=200;
				a[4].x=240;
				a[4].y=200;
				a[5].x=310;
				a[5].y=200;
				a[6].x=380;
				a[6].y=200;
				a[7].x=170;
				a[7].y=100;
				a[8].x=170;
				a[8].y=150;
				a[9].x=170;
				a[9].y=270;
				a[10].x=170;
				a[10].y=350;
				a[11].x=170;
				a[11].y=410;
				a[12].x=170;
				a[12].y=455;
				a[13].x=310;
				a[13].y=30;
				a[14].x=310;
				a[14].y=100;
				a[15].x=310;
				a[15].y=150;
				a[16].x=310;
				a[16].y=200;
				a[17].x=310;
				a[17].y=350;
				a[18].x=310;
				a[18].y=410;
				
				linebetweensta(a[R[i].origin].x,a[R[i].origin].y,a[R[i].transfer].x,a[R[i].transfer].y,RED);
				linebetweensta(a[R[i].transfer].x,a[R[i].transfer].y,a[R[i].terminal].x,a[R[i].terminal].y,RED);
				
				while (1)
				{
					newmouse(&MouseX,&MouseY,&press);
					
					if (MouseX >525&&MouseX<630&&MouseY>450&&MouseY<470)
					{
						if (mouse_press(525, 450, 630, 470) == 2)//点击退出未点击
						{
							MouseS=1;
							continue;
						}
						else if (mouse_press(525, 450, 630, 470) == 1)//点击退出点击
						{
							MouseS=0;
							clrmous(MouseX, MouseY);
							cleardevice();
							//return; //返回上一界面
							//Patient_Check(ID);
							break;
						}
					}

					if (MouseS!=0)
					{
						MouseS = 0;
					}
				}
				/*clrmous(MouseX, MouseY);
	            delay(100);
                save_bk_mou(MouseX, MouseY);
                cleardevice();*/
	            Draw_Patient_Check(); //重新显示当前乘车记录
				Patient_Record(&R[i]);
				continue;
			}
		}
		if (MouseX > 459 && MouseX < 561 && MouseY> 358 && MouseY < 419)
		{
			if (mouse_press(459, 358, 561, 419) == 2)//下一条未点击
			{
				MouseS = 1;
				if (flag==0)//防止被重复标亮
				{
					clrmous(MouseX,MouseY);
					Patient_Lighten2(3);
					flag=3;
				}
				continue;
			}
			else if (mouse_press(459, 358, 561, 419) == 1)//下一条点击
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				Patient_Lighten2(3);
				if(i==amount-1)
				{
					setfillstyle(1, WHITE);
		            bar(459.75, 358.75, 459.75 + 101, 358.75 + 60.5);
		            highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
		            puthz(480, 380, "暂无更多", 16, 16, RED);
		            delay(3000);
				}
				else
				{
					i++;
					Patient_Record(&R[i]);
				}
				delay(200);
			}
		}
		if (MouseX > 465 && MouseX < 570 && MouseY> 14 && MouseY < 34)
		{
			if (mouse_press(465, 14, 570, 34) == 2)//点击退出未点击
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(465, 14, 570, 34) == 1)//点击退出点击
			{
				MouseS=0;
				return; //返回上一界面
			}
		}
		if (flag!=0)
		{
			MouseS = 0;
			if (flag== 1)
			{
				clrmous(MouseX,MouseY);
				Patient_Darken2(1);
			}
			if (flag== 2)
			{
				clrmous(MouseX,MouseY);
				Patient_Darken2(2);
			}
			if (flag == 3)
			{
				clrmous(MouseX,MouseY);
				Patient_Darken2(3);
			}
			flag=0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}
/*
FUNCTION:Draw_Patient_Check
DESCRIPTION:绘制卫生部门查询乘客乘车记录界面
INPUT:无
RETURN:无
*/
int Draw_Patient_Check()
{
	int i; //for语句辅助参数	
	int mainhzcolor = GREEN;
	int fillcolor = LIGHTGRAY;
	int buttoncolor = BLUE;
	int textstyle = 3;
	
	cleardevice();
    cover(0, 0, 639, 479, WHITE);
	//setbkcolor(DARKGRAY);
	puthz(305, 14, "乘车记录", 24, 25.5, mainhzcolor);
	cover(229.5, 100.5, 229.5 + 148, 100.5 + 10, fillcolor);
	highlight(229.5, 100.5, 229.5 + 148, 100.5 + 10, BLACK);
	draw_exit(470, 17, WHITE, BLUE, GREEN, LIGHTGREEN);
	setcolor(LIGHTGRAY);
	line(376.5,89.66,376.5,89.66+34);
	line(376.5,89.66,376.5+31,89.66+17);
	line(376.5, 89.66 + 34, 376.5 + 31, 89.66 + 17);
	floodfill((376.5*3+31)/3,(89.66*3+51)/3,LIGHTGRAY);
	setcolor(BLACK);
	line(376.5, 89.66, 376.5, 89.66 + 34);
	line(376.5, 89.66 + 34, 376.5 + 31, 89.66 + 17);
	line(376.5, 89.66, 376.5 + 31, 89.66 + 17);
	cover(79.5, 67.5, 79.5 + 139, 67.5 + 63, fillcolor);
	highlight(79.5, 67.5, 79.5 + 139, 67.5 + 63, GREEN);
	cover(419.5, 67.5, 419.5 + 139, 67.5 + 63, fillcolor);
	highlight(419.5, 67.5, 419.5 + 139, 67.5 + 63, GREEN);	//起点及终点
	setcolor(mainhzcolor);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
	puthz(96, 377, "上一条", 24, 24.5, buttoncolor);
	highlight(226, 358.75, 226 + 187, 358.75 + 60.5, BLACK);
	puthz(247, 376.75, "查看乘车轨迹", 24, 24.5, buttoncolor);
	highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
	puthz(475.88, 377, "下一条", 24, 24.5, buttoncolor);
	cover(200,235,440,330,LIGHTGRAY);
	highlight(200,235,440,330,GREEN);
	puthz(240,240,"线路",24,24,BLUE);
	puthz(320,240,"发车时间",24,24,BLUE); //车次信息
	//puthz(100, 88, "泾河", 24, 24, WHITE);
	//puthz(100, 88, "五环大道", 24, 24, WHITE);
	//puthz(100, 88, "崇仁路", 24, 24, WHITE);
	puthz(139+120+18+4, 190, "年", 24, 24, GREEN);
	puthz(202+120+18, 190, "月", 24, 24, GREEN);
	puthz(260+120+18, 190, "日", 24, 24, GREEN);
	/*settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	outtextxy(139+60+18,184,"2022");
	outtextxy(202+100+18,184,"4");
	outtextxy(260+84+18,184,"18");
	setcolor(WHITE);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	outtextxy(240+20,270,"1");
	outtextxy(240+20,300,"2");
	outtextxy(320+20,270,"6:20");
	outtextxy(321+20,300,"20:20");
	puthz(220, 14, "蓝一番", 24, 25.5, RED);*/
}
/*
FUNCTION:Patient_Lighten2()
DESCRIPTION:点亮
INPUT:flag
RETURN:NO
*/
int Patient_Lighten2(int flag)
{
	switch(flag)
	{
		case 1:
			highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
			cover(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, LIGHTGRAY);
			puthz(96, 377, "上一条", 24, 24.5,BLUE);
			break;
		case 2:
			highlight(226, 358.75, 226 + 187, 358.75 + 60.5, BLACK);
			cover(226, 358.75, 226 + 187, 358.75 + 60.5, LIGHTGRAY);
			puthz(247, 376.75, "查看乘车轨迹", 24, 24.5, BLUE);
			break;
		case 3:
			highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
			cover(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, LIGHTGRAY);
			puthz(475.88, 377, "下一条", 24, 24.5, BLUE);
			break;
	}
}
/*
FUNCTION:Patient_Darken2
DESCRIPTION:恢复
INPUT:flag
RETURN:NO
*/
int Patient_Darken2(int flag)
{
	switch(flag)
	{
		case 1:
			highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
			cover(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, WHITE);
			puthz(96, 377, "上一条", 24, 24.5,BLUE);
			break;
		case 2:
			highlight(226, 358.75, 226 + 187, 358.75 + 60.5, BLACK);
			cover(226, 358.75, 226 + 187, 358.75 + 60.5, WHITE);
			puthz(247, 376.75, "查看乘车轨迹", 24, 24.5, BLUE);
			break;
		case 3:
			highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
			cover(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, WHITE);
			puthz(475.88, 377, "下一条", 24, 24.5, BLUE);
			break;
	}
}
/*
FUNCTION:Patient_Identity_Get
DESCRIPTION:卫生部门获取乘客信息
INPUT:乘客身份证号ID，乘客姓名name
RETURN:乘客代号flag
*/
int Patient_Identity_Get(char* ID,char* name)
{
	int flag; //记录当前乘车代号
	PASSENGER* p;
	FILE* fp;
	if((fp=fopen("C:\\TRY\\TEXT\\pass.dat", "rb+" )) == NULL) //打开存储用户信息的文件
	{
		printf("\nError on open file pass.dat!");
		delay(3000);
		exit(1);
	}
	flag=0; 
	while(!feof(fp))
	{
		if((p=(PASSENGER*)malloc(sizeof(PASSENGER)))==NULL)     //分配空间
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
		
		if(strcmp(p->ID,ID)==0) //读到的乘客身份证号匹配
		{
			flag=p->number;
			strcpy(name,p->name);
			if(p!= NULL)                                    
		    {
			    free(p);
			    p = NULL;
		    }
			break;
		}
		if(p!= NULL)                                   
		{
			free(p);
			p=NULL;
		}
	}
	if (fclose(fp)!=0)                                         
	{
		printf("\nError on close pass.dat!");
		delay(3000);
		exit(1);
	}
	return flag; //返回当前乘客代号
}
/*
FUNCTION:Record_Get
DESCRIPTION:获取乘客乘车记录
INPUT:乘客代号n,存储乘客乘车记录的结构体数组
RETURN:无
*/
int Record_Get(int n,struct Record* R)
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
FUNCTION:Patient_Record
DESCRIPTION:显示乘客乘车记录信息
INPUT:存储乘客乘车记录的结构体r
RETURN:无
*/
int Patient_Record(struct Record *r)
{
	/*cover(79.5, 67.5, 79.5 + 139, 67.5 + 63, LIGHTGRAY); //遮盖之前显示的信息
	highlight(79.5, 67.5, 79.5 + 139, 67.5 + 63, GREEN);
	cover(419.5, 67.5, 419.5 + 139, 67.5 + 63, LIGHTGRAY);
	highlight(419.5, 67.5, 419.5 + 139, 67.5 + 63, GREEN);
	cover(200,235,440,330,LIGHTGRAY);
	highlight(200,235,440,330,GREEN);
	puthz(240,240,"线路",24,24,BLUE);
	puthz(320,240,"发车时间",24,24,BLUE); //车次信息*/
	Draw_Patient_Check();
	//puts(r->name);
	//printf("%d\n",r->number);
	//printf("%d\n",r->origin);
	//printf("%d\n",r->subway_number[0]);
	switch(r->origin)
	{
		case 1:
			puthz(100, 88, "泾河", 24, 24, WHITE);
			break;
		case 2:
			puthz(100, 88, "五环大道", 24, 24, WHITE);
			break;
		case 3:
			puthz(100, 88, "宗关", 24, 24, WHITE);
			break;
		case 4:
			puthz(100, 88, "崇仁路", 24, 24, WHITE);
			break;
		case 5:
			puthz(100, 88, "循礼门", 24, 24, WHITE);
			break;
		case 6:
			puthz(100, 88, "汉口北", 24, 24, WHITE);
			break;
		case 7:
			puthz(100, 88, "罗家庄", 24, 24, WHITE);
			break;
		case 8:
			puthz(100, 88, "云飞路", 24, 24, WHITE);
			break;
		case 9:
			puthz(100, 88, "龙阳村", 24, 24, WHITE);
			break;
		case 10:
			puthz(100, 88, "陶家岭", 24, 24, WHITE);
			break;
		case 11:
			puthz(100, 88, "三角湖", 24, 24, WHITE);
			break;
		case 12:
			puthz(100, 88, "沌阳大道", 24, 24, WHITE);
			break;
		case 13:
			puthz(100, 88, "天河机场", 24, 24, WHITE);
			break;
		case 14:
			puthz(100, 88, "巨龙大道", 24, 24, WHITE);
			break;
		case 15:
			puthz(100, 88, "金谭路", 24, 24, WHITE);
			break;
		case 16:
			puthz(100, 88, "江汉路", 24, 24, WHITE);
			break;
		case 17:
			puthz(100, 88, "光谷广场", 24, 24, WHITE);
			break;
		case 18:
			puthz(100, 88, "佛祖岭", 24, 24, WHITE);
			break;
	}
	switch(r->terminal)
	{
		case 1:
			puthz(440, 88, "泾河", 24, 24, WHITE);
			break;
		case 2:
			puthz(440, 88, "五环大道", 24, 24, WHITE);
			break;
		case 3:
			puthz(440, 88, "宗关", 24, 24, WHITE);
			break;
		case 4:
			puthz(440, 88, "崇仁路", 24, 24, WHITE);
			break;
		case 5:
			puthz(440, 88, "循礼门", 24, 24, WHITE);
			break;
		case 6:
			puthz(440, 88, "汉口北", 24, 24, WHITE);
			break;
		case 7:
			puthz(440, 88, "罗家庄", 24, 24, WHITE);
			break;
		case 8:
			puthz(440, 88, "云飞路", 24, 24, WHITE);
			break;
		case 9:
			puthz(440, 88, "龙阳村", 24, 24, WHITE);
			break;
		case 10:
			puthz(440, 88, "陶家岭", 24, 24, WHITE);
			break;
		case 11:
			puthz(440, 88, "三角湖", 24, 24, WHITE);
			break;
		case 12:
			puthz(440, 88, "沌阳大道", 24, 24, WHITE);
			break;
		case 13:
			puthz(440, 88, "天河机场", 24, 24, WHITE);
			break;
		case 14:
			puthz(440, 88, "巨龙大道", 24, 24, WHITE);
			break;
		case 15:
			puthz(440, 88, "金谭路", 24, 24, WHITE);
			break;
		case 16:
			puthz(440, 88, "江汉路", 24, 24, WHITE);
			break;
		case 17:
			puthz(440, 88, "光谷广场", 24, 24, WHITE);
			break;
		case 18:
			puthz(440, 88, "佛祖岭", 24, 24, WHITE);
			break;
	}
	Draw_Subwaynumber(r);
	puthz(220, 14, r->name, 24, 25.5, RED);
	switch(r->week)
	{
		case 7:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(RED);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"22");
			break;
		case 6:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(RED);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"21");
			break;
		case 5:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(RED);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"20");
			break;
		case 4:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(RED);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"19");
			break;
		case 3:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(RED);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"18");
			break;
		case 2:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(RED);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"17");
			break;
		case 1:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(RED);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"16");
			break;
	}
	return 0;
}
/*
FUNCTION:Draw_Subwaynumber()
DESCRIPTION:画车次及时间
INPUT:r
OUTPUT:NO
*/
int Draw_Subwaynumber(struct Record *r)
{
	int i=0;
	char number[3][10]={"\0","\0","\0"};
	for(i=0;i<3;i++)
	{
		switch(r->subway_number[i])
		{
			case 1:
				strcpy(number[i],"6:00");
				break;
			case 2:
				strcpy(number[i],"6:20");
				break;
			case 3:
				strcpy(number[i],"6:40");
				break;
			case 4:
				strcpy(number[i],"7:00");
				break;
			case 5:
				strcpy(number[i],"7:20");
				break;
			case 6:
				strcpy(number[i],"7:40");
				break;
			case 7:
				strcpy(number[i],"8:00");
				break;
			case 8:
				strcpy(number[i],"8:20");
				break;
			case 9:
				strcpy(number[i],"8:40");
				break;
			case 10:
				strcpy(number[i],"9:00");
				break;
			case 11:
				strcpy(number[i],"9:20");
				break;
			case 12:
				strcpy(number[i],"9:40");
				break;
			case 13:
				strcpy(number[i],"10:00");
				break;
			case 14:
				strcpy(number[i],"10:20");
				break;
			case 15:
				strcpy(number[i],"10:40");
				break;
			case 16:
				strcpy(number[i],"11:00");
				break;
			case 17:
				strcpy(number[i],"11:20");
				break;
			case 18:
				strcpy(number[i],"11:40");
				break;
			case 19:
				strcpy(number[i],"12:00");
				break;
			case 20:
				strcpy(number[i],"12:20");
				break;
			case 21:
				strcpy(number[i],"12:40");
				break;
			case 22:
				strcpy(number[i],"13:00");
				break;
			case 23:
				strcpy(number[i],"13:20");
				break;
			case 24:
				strcpy(number[i],"13:40");
				break;
			case 25:
				strcpy(number[i],"14:00");
				break;
			case 26:
				strcpy(number[i],"14:20");
				break;
			case 27:
				strcpy(number[i],"14:40");
				break;
			case 28:
				strcpy(number[i],"15:00");
				break;
			case 29:
				strcpy(number[i],"15:20");
				break;
			case 30:
				strcpy(number[i],"15:40");
				break;
			case 31:
				strcpy(number[i],"16:00");
				break;
			case 32:
				strcpy(number[i],"16:20");
				break;
			case 33:
				strcpy(number[i],"16:40");
				break;
			case 34:
				strcpy(number[i],"17:00");
				break;
			case 35:
				strcpy(number[i],"17:20");
				break;
			case 36:
				strcpy(number[i],"17:40");
				break;
			case 37:
				strcpy(number[i],"18:00");
				break;
			case 38:
				strcpy(number[i],"18:20");
				break;
			case 39:
				strcpy(number[i],"18:40");
				break;
			case 40:
				strcpy(number[i],"19:00");
				break;
			case 41:
				strcpy(number[i],"19:20");
				break;
			case 42:
				strcpy(number[i],"19:40");
				break;
			case 43:
				strcpy(number[i],"20:00");
				break;
			case 44:
				strcpy(number[i],"20:20");
				break;
			case 45:
				strcpy(number[i],"20:40");
				break;
			case 46:
				strcpy(number[i],"21:00");
				break;
			case 47:
				strcpy(number[i],"21:20");
				break;
			case 48:
				strcpy(number[i],"21:40");
				break;
			case 49:
				strcpy(number[i],"22:00");
				break;
			case 50:
				strcpy(number[i],"22:20");
				break;
			case 51:
				strcpy(number[i],"22:40");
				break;
				
		}
	}
	
	if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"1");
		outtextxy(240+20,300,"2");
		outtextxy(320+20,270,number[0]);
		outtextxy(321+20,300,number[1]);
	}
	else if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"1");
		outtextxy(240+20,300,"3");
		outtextxy(320+20,270,number[0]);
		outtextxy(321+20,300,number[2]);
	}
	else if((r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"2");
		outtextxy(240+20,300,"3");
		outtextxy(320+20,270,number[1]);
		outtextxy(321+20,300,number[2]);
	}
	else if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"1");
		outtextxy(320+20,270,number[0]);
	}
	else if((r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"2");
		outtextxy(320+20,270,number[1]);
	}
	else if((r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)) //一二号线
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"3");
		outtextxy(320+20,270,number[2]);
	}
}

