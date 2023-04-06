#include "public.h"
#include "alogin.h"
#include "input.h"
/*
FUNCTION:Alogin
DESCRIPTION:����Ա��¼
INPUT:page,ad,AD
RETURN:no
*/
void Alogin(int *page,int ad,ADMINISTRATOR *AD)
{
	int pos1=0;				//�ж������1���������
	int pos2=0;
	int flag=0;
	int jun1=-1;
	int jun2=0;
	char c;				//ѡ��ͬ�Ĺ���Ա��¼��
	char A[10]={'\0'};				//�˺ţ�6-12λ
	char P[10]={'\0'};				//�������룬6-12λ
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	switch(ad)				//ͨ����ͬadֵ���Ʋ�ͬ��½����
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
		            puthz(274,220,"���ڵ�¼",24,24,RED);
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
		            puthz(274,230,"��¼�ɹ�",24,24,RED);
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
		            puthz(265,320+12,"��¼ʧ�ܣ�",24,24,RED);
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
	
		if(flag!=0)                                 //���ݵ�����������������л�ԭ
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
		if(MouseS!=0)                               //��ԭ���
		{                 
			MouseS=0;
		}
	}
	
}
/*
FUNCTION:Draw_Alogin1
DESCRIPTION:���Ƶ������ŵ�½����
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
	puthz(165,15,"�������Ź���ϵͳ",32,40,LIGHTGRAY);
	
	puthz(95,180,"�˺�",16,16,CYAN);
	puthz(95,240,"����",16,16,CYAN);
	
	setfillstyle(1,WHITE);
	bar(95,205,545,230);
	bar(95,265,545,290);
	
	setfillstyle(1,RED);
	bar(260,310+12,380,345+12);
	puthz(290,315+12,"��¼",24,34,WHITE);
	
	setfillstyle(1,WHITE);
	setlinestyle(0,0,3);
	setcolor(LIGHTBLUE);
	
	bar(480,380,538,405);
	puthz(492,385,"����",16,18,LIGHTBLUE);
	rectangle(480,380,538,405);
}
/*
FUNCTION:Draw_Alogin2
DESCRIPTION:�����������ŵ�½����
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
	puthz(165,15,"�������Ź���ϵͳ",32,40, LIGHTGRAY);
	setfillstyle(1,LIGHTBLUE);
	setcolor(LIGHTGREEN);
	
	puthz(95,180,"�˺�",16,16,CYAN);        
	puthz(95,240,"����",16,16,CYAN);

	setfillstyle(1,WHITE);                     
    bar(95,205,545,230);
	bar(95,265,545,290);

	setfillstyle(SOLID_FILL, RED);
	bar(260,310+12,380,345+12);
	puthz(290,315+12,"��¼",24,34,WHITE);
	
    setlinestyle(SOLID_LINE,0,1);
	setfillstyle(SOLID_FILL,WHITE);
	setlinestyle(SOLID_LINE,0,2);
	setcolor(LIGHTBLUE);


	bar(480,380,538,405);
	puthz(492,385,"����",16,18,LIGHTBLUE);
	rectangle(480,380,538,405);
	
}
/*
FUNCTION:Alogin_Lighten
DESCRIPTION:��ť����
INPUT:���꼰�������Ʊ���flag
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
	    puthz(290,315+12,"��¼",24,34,WHITE);//��¼��
	}

	else if(flag==4)
	{
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(480,380,538,405);
	    puthz(492,385,"����",16,18,CYAN);
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
DESCRIPTION:����Ա��¼���水ť�ָ�
INPUT:�������Ʊ���pos
RETURN:��
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
	    puthz(290,315+12,"��¼",24,34,WHITE);
		break;
	case 4:
	    setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(480,380,538,405);
	    puthz(492,385,"����",16,18,LIGHTBLUE);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(480,380,538,405);
	}
}

/*
FUNCTION:Alogin_Com
DESCRIPTION:��ɹ���Ա��¼
INPUT:�˺������жϽ��jun1,jun2
RETURN:�жϽ��
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
		        puthz(550,270,"������ȷ",16,16,RED);
		        return 1;
			}
			else
			{
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
		        puthz(550,270,"�������",16,16,RED);
		        return 0;
			}
		}
		A++;
	}
	setfillstyle(1,DARKGRAY);
	bar(550,210,640,226);
	puthz(550,210,"�˺Ŵ���",16,16,RED);
	return 0;
}