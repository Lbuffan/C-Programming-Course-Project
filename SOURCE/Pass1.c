#include"public.h"
#include"pass1.h"

void pass1(int* page,int identity)
{
	int tag = 0; //��ֹ�˳�����
	int i; //��ǵ�ǰ�����˳���¼
	int amount; //��¼�˳���¼����
	int flag=0; //��ǵ������
	/*int tag=0; //��ǳ˿�״̬��0Ϊ������1Ϊ�ܽӣ�2Ϊȷ��*/
	RECORD R[6]; //��¼�˿ͳ˳���¼�������ͷ
	Station a[18];
	
	clrmous(MouseX, MouseY);
	delay(100);
    save_bk_mou(MouseX, MouseY);
    cleardevice();
	
	amount=Pass_Record_Get(identity,R);
	i=0;
	Show_Record(&R[i]);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 81 && MouseX < 183 && MouseY> 358 && MouseY < 419)
		{
			if (mouse_press(81, 358, 183, 419) == 2)//�鿴��һ��δ���
			{
				MouseS = 1;
				if (flag==0)//��ֹ���ظ�����
				{
					clrmous(MouseX,MouseY);
					Pass1_Lighten(1);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(81, 358, 183, 419) == 1)//�鿴��һ������
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				Pass1_Lighten(1);
				if(i==0)
				{
					setfillstyle(1, WHITE);
		            bar(81.72, 358.75, 81.72 + 101, 358.75 + 60.5);
		            highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
		            puthz(102,380, "���޸���",16,16,RED);
		            delay(3000);
				}
				else
				{
					i--;
					Show_Record(&R[i]);
				}
				delay(100);
				continue;
			}
		}
		if (MouseX > 226 && MouseX < 413 && MouseY> 358 && MouseY < 419)
		{
			if (mouse_press(226, 358, 413, 419) == 2)   //��ʾ�켣δ���
			{
				MouseS = 1;
				if (flag==0)//��ֹ���ظ�����
				{
					clrmous(MouseX,MouseY);
					Pass1_Lighten(2);
					flag=1;
				}
				continue;
			}
			else if (mouse_press(226, 358, 413, 419) == 1)//��ʾ�켣���
			{
				tag = 1;
				MouseS = 0;
				clrmous(MouseX,MouseY);
				Pass1_Lighten(2);
				
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
						if (mouse_press(525, 450, 630, 470) == 2)//����˳�δ���
						{
							MouseS=1;
							continue;
						}
						else if (mouse_press(525, 450, 630, 470) == 1)//����˳����
						{
							MouseS=0;
							clrmous(MouseX, MouseY);
							cleardevice();
							//return; //������һ����
							//Patient_Check(ID);
							break;
						}
					}

					if (MouseS!=0)
					{
						MouseS = 0;
					}
				}
				Show_Record(&R[i]);
				continue;
			}
		}
		if (MouseX > 459 && MouseX < 561 && MouseY> 358 && MouseY < 419)
		{
			if (mouse_press(459, 358, 561, 419) == 2)//��һ��δ���
			{
				MouseS = 1;
				if (flag==0)//��ֹ���ظ�����
				{
					clrmous(MouseX,MouseY);
					Pass1_Lighten(3);
					flag=1;
				}
				continue;
			}
			else if (mouse_press(459, 358, 561, 419) == 1)//��һ�����
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				Pass1_Lighten(3);
				if(i==amount-1)
				{
					setfillstyle(1, WHITE);
		            bar(459.75, 358.75, 459.75 + 101, 358.75 + 60.5);
		            highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
		            puthz(480, 380, "���޸���", 16, 16, RED);
		            delay(3000);
				}
				else
				{
					i++;
					Show_Record(&R[i]);
				}
				delay(100);
			}
		}

		if (MouseX > 525 && MouseX < 630 && MouseY> 450 && MouseY < 470)
		{
			if (mouse_press(525, 450, 630, 470) == 2)//����˳�δ���
			{
				MouseS=1;
				continue;
			}
			else if (mouse_press(525, 450, 630, 470) == 1&&tag==0)//����˳����
			{
				MouseS = 0;
			    *page =5;//�л����˿͹��ܽ���
				/*printf("%d",*page);
				getchar();*/
				break;				
			}
			else  
			{
				delay(100);
				tag = 0;
			}
		}
		if (flag!=0)
		{
			MouseS = 0;
			clrmous(MouseX,MouseY);
			Pass1_Darken();
			flag=0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}

/*
FUNCTION:��ȡ�˿͵ĳ˳���¼�����س˳���¼������
DESCRIPTION:��ȡ�˿ͳ˳���¼
INPUT:�˿ʹ���n,�洢�˿ͳ˳���¼�Ľṹ������
RETURN:��
*/
int Pass_Record_Get(int n,struct Record* R)
{
	int flag=0;
	FILE* fp;
	int i=0;
	int amount=0;
	RECORD* r; //��ʱ�洢�˳���¼
	
	if ((fp = fopen(".\\TEXT\\record.dat", "rb+")) == NULL) //���ļ�
	{
		printf("\nError on open record.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_SET);
	while(!feof(fp))
	{
		if((r=(RECORD*)malloc(sizeof(RECORD)))==NULL) //����ռ�             
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
		//printf("%d",r->origin);
		if(n==r->number) //������ǰ�˿͵ĳ˳���¼
		{
			flag==1; //����Ѿ��ҵ���ǰ�˿ͳ˳���¼
			R->contact=r->contact;
			R->number=r->number;
			strcpy(R->name,r->name);
			strcpy(R->telephone,r->telephone);
			strcpy(R->ID,r->ID);
			strcpy(R->age,r->age);
			strcpy(R->sex,r->sex);
			R->week=r->week;
			R->subway_number[0]=r->subway_number[0];
			R->subway_number[1]=r->subway_number[1];
			R->subway_number[2]=r->subway_number[2];
			R->origin=r->origin;//printf("%d",R->origin);getchar();
			R->transfer=r->transfer;
			R->terminal=r->terminal;
			amount++;
			R++;
			//printf("%d",R->origin);
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
}

/*
FUNCTION:Pass1_Lighten()
DESCRIPTION:����
INPUT:flag
RETURN:NO
*/
int Pass1_Lighten(int flag)
{
	switch(flag)
	{
		case 1:
			highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, YELLOW);
			cover(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, DARKGRAY);
			puthz(96, 377, "��һ��", 24, 24.5,BLUE);
			break;
		case 2:
			highlight(226, 358.75, 226 + 187, 358.75 + 60.5, YELLOW);
			cover(226, 358.75, 226 + 187, 358.75 + 60.5,DARKGRAY);
			puthz(247, 376.75, "�鿴�˳��켣", 24, 24.5, BLUE);
			break;
		case 3:
			highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, YELLOW);
			cover(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, DARKGRAY);
			puthz(475.88, 377, "��һ��", 24, 24.5, BLUE);
			break;
	}
}

/*
FUNCTION:Pass1_Darken
DESCRIPTION:�ָ�
INPUT:flag
RETURN:NO
*/
void Pass1_Darken()
{
	cover(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, WHITE);
	highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, YELLOW);
	puthz(96, 377, "��һ��", 24, 24.5, BLUE);
			
	cover(226, 358.75, 226 + 187, 358.75 + 60.5, WHITE);
	highlight(226, 358.75, 226 + 187, 358.75 + 60.5, YELLOW);
	puthz(247, 376.75, "�鿴�˳��켣", 24, 24.5, BLUE);
			
	cover(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, WHITE);
	highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, YELLOW);
	puthz(475.88, 377, "��һ��", 24, 24.5, BLUE);
	
}

/*
DESCRIPTION:���Ʋ鿴�˿ͳ˳���¼����
INPUT:��
RETURN:��
*/
void Draw_pass1()
{
	int i; //for��丨������	
	int a = 2;
	
	
	cleardevice();
    
	cover(1,1,639,479,LIGHTGRAY);
	puthz(242.38+60, 13.25, "�˳���¼", 24, 25.5, DARKGRAY);
	
	cover(419.5, 67.5, 419.5 + 139, 67.5 + 63, WHITE);
	highlight(419.5, 67.5, 419.5 + 139, 67.5 + 63, YELLOW);
	
	cover(79.5, 67.5, 79.5 + 139, 67.5 + 63,WHITE);
	highlight(79.5, 67.5, 79.5 + 139, 67.5 + 63, YELLOW);
	
	triangle(376.5, 89.66-8, 376.5, 89.66 + 34-8, 376.5 + 31, 89.66 + 17-8, WHITE);
	setfillstyle(1,WHITE);
	floodfill(380.5, 89.66 + 17-8, WHITE);
	cover(229.5, 100.5-8, 229.5 + 148, 100.5 + 10-8, WHITE);
	highlight(229.5, 100.5-8, 229.5 + 148, 100.5 + 10-8, WHITE);
	
	puthz(139+120+18+4, 190, "��", 24, 24, DARKGRAY);
	puthz(202+120+18, 190, "��", 24, 24, DARKGRAY);
	puthz(260+120+18, 190, "��", 24, 24, DARKGRAY);
	
	cover(200,235,440,330,WHITE);
	highlight(200,235,440,330,YELLOW);
	puthz(240,240,"��·",24,24,BLUE);
	puthz(320,240,"����ʱ��",24,24,BLUE); //������Ϣ
	
	cover(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, WHITE);
	highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, YELLOW);
	puthz(96, 377, "��һ��", 24, 24.5, BLUE);
	
	cover(226, 358.75, 226 + 187, 358.75 + 60.5, WHITE);
	highlight(226, 358.75, 226 + 187, 358.75 + 60.5, YELLOW);
	puthz(247, 376.75, "�鿴�˳��켣", 24, 24.5, BLUE);
	
	cover(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, WHITE);
	highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, YELLOW);
	puthz(475.88, 377, "��һ��", 24, 24.5, BLUE);
	
	draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
}	

/*
FUNCTION:Draw_Subnum()
DESCRIPTION:�����μ�ʱ��
INPUT:r
OUTPUT:NO
*/
int Draw_Subnum(struct Record *r)
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

	if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //һ������
	{
		setcolor(DARKGRAY);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"1");
		outtextxy(240+20,300,"2");
		outtextxy(320+20,270,number[0]);
		outtextxy(321+20,300,number[1]);
	}
	else if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)) //һ������
	{
		setcolor(DARKGRAY);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"1");
		outtextxy(240+20,300,"3");
		outtextxy(320+20,270,number[0]);
		outtextxy(321+20,300,number[2]);
	}
	else if((r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //һ������
	{
		setcolor(DARKGRAY);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"2");
		outtextxy(240+20,300,"3");
		outtextxy(320+20,270,number[1]);
		outtextxy(321+20,300,number[2]);
	}
	else if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)) //һ������
	{
		setcolor(DARKGRAY);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"1");
		outtextxy(320+20,270,number[0]);
	}
	else if((r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //һ������
	{
		setcolor(DARKGRAY);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"2");
		outtextxy(320+20,270,number[1]);
	}
	else if((r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)) //һ������
	{
		setcolor(DARKGRAY);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"3");
		outtextxy(320+20,270,number[2]);
	}
}
/*
FUNCTION:Show_Record
DESCRIPTION:��ʾ�˿ͳ˳���¼��Ϣ
INPUT:�洢�˿ͳ˳���¼�Ľṹ��r
RETURN:��
*/
int Show_Record(struct Record *r)
{
	
	Draw_pass1();

	switch(r->origin)
	{
		case 1:
			puthz(100, 88, "����", 24, 24, DARKGRAY);
			break;
		case 2:
			puthz(100, 88, "�廷���", 24, 24, DARKGRAY);
			break;
		case 3:
			puthz(100, 88, "�ڹ�", 24, 24, DARKGRAY);
			break;
		case 4:
			puthz(100, 88, "����·", 24, 24, DARKGRAY);
			break;
		case 5:
			puthz(100, 88, "ѭ����", 24, 24, DARKGRAY);
			break;
		case 6:
			puthz(100, 88, "���ڱ�", 24, 24, DARKGRAY);
			break;
		case 7:
			puthz(100, 88, "�޼�ׯ", 24, 24, DARKGRAY);
			break;
		case 8:
			puthz(100, 88, "�Ʒ�·", 24, 24, DARKGRAY);
			break;
		case 9:
			puthz(100, 88, "������", 24, 24, DARKGRAY);
			break;
		case 10:
			puthz(100, 88, "�ռ���", 24, 24, DARKGRAY);
			break;
		case 11:
			puthz(100, 88, "���Ǻ�", 24, 24, DARKGRAY);
			break;
		case 12:
			puthz(100, 88, "�������", 24, 24, DARKGRAY);
			break;
		case 13:
			puthz(100, 88, "��ӻ���", 24, 24, DARKGRAY);
			break;
		case 14:
			puthz(100, 88, "�������", 24, 24, DARKGRAY);
			break;
		case 15:
			puthz(100, 88, "��̷·", 24, 24, DARKGRAY);
			break;
		case 16:
			puthz(100, 88, "����·", 24, 24, DARKGRAY);
			break;
		case 17:
			puthz(100, 88, "��ȹ㳡", 24, 24, DARKGRAY);
			break;
		case 18:
			puthz(100, 88, "������", 24, 24, DARKGRAY);
			break;
	}
	switch(r->terminal)
	{
		case 1:
			puthz(440, 88, "����", 24, 24, DARKGRAY);
			break;
		case 2:
			puthz(440, 88, "�廷���", 24, 24, DARKGRAY);
			break;
		case 3:
			puthz(440, 88, "�ڹ�", 24, 24, DARKGRAY);
			break;
		case 4:
			puthz(440, 88, "����·", 24, 24, DARKGRAY);
			break;
		case 5:
			puthz(440, 88, "ѭ����", 24, 24, DARKGRAY);
			break;
		case 6:
			puthz(440, 88, "���ڱ�", 24, 24, DARKGRAY);
			break;
		case 7:
			puthz(440, 88, "�޼�ׯ", 24, 24, DARKGRAY);
			break;
		case 8:
			puthz(440, 88, "�Ʒ�·", 24, 24, DARKGRAY);
			break;
		case 9:
			puthz(440, 88, "������", 24, 24, DARKGRAY);
			break;
		case 10:
			puthz(440, 88, "�ռ���", 24, 24, DARKGRAY);
			break;
		case 11:
			puthz(440, 88, "���Ǻ�", 24, 24, DARKGRAY);
			break;
		case 12:
			puthz(440, 88, "�������", 24, 24, DARKGRAY);
			break;
		case 13:
			puthz(440, 88, "��ӻ���", 24, 24, DARKGRAY);
			break;
		case 14:
			puthz(440, 88, "�������", 24, 24, DARKGRAY);
			break;
		case 15:
			puthz(440, 88, "��̷·", 24, 24, DARKGRAY);
			break;
		case 16:
			puthz(440, 88, "����·", 24, 24, DARKGRAY);
			break;
		case 17:
			puthz(440, 88, "��ȹ㳡", 24, 24, DARKGRAY);
			break;
		case 18:
			puthz(440, 88, "������", 24, 24, DARKGRAY);
			break;
	}
	
	Draw_Subnum(r);
	switch(r->week)
	{
		case 7:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"22");
			break;
		case 6:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"21");
			break;
		case 5:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"20");
			break;
		case 4:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"19");
			break;
		case 3:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"18");
			break;
		case 2:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"17");
			break;
		case 1:
			settextjustify(0, 2);
			settextstyle(3, 0, 3);
			setcolor(DARKGRAY);
			outtextxy(139+60+18,184,"2022");
			outtextxy(202+100+18,184,"4");
			outtextxy(260+84+18,184,"16");
			break;
	}
	
	puthz(220, 14, r->name, 24, 25.5, DARKGRAY);
	
	
	return 0;
}
