#include "public.h"
#include "connect.h"
/*
FUNCTION:Connect
DESCRIPTION:׷���ܽӳ˿�
INPUT:PAGE
RETURN:NO
*/
void Connect(int* page)
{
	int flag=0; //��ǵ���
	int a[10]={0}; //�洢ȷ��˿ʹ���
	int j=0;
	int k=0;
	int i=0; //��ǰ�˳���¼
	int amount=0; //��¼����
	RECORD r[35]; //�洢�˳���¼

	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	cleardevice();

	Draw_Connect();
	Patient_Search(a); //��ȡȷ��˿ʹ���
	//printf("%d\n%d",a[0],a[1]);
	while(a[j]!=0)
	{
		amount=amount+Connect_Get(a[j],&r[k]); //��ȡ��س˳���¼
		j++;k=k+3;
	}
	j=0;
	if(r==NULL) //���û�л�ȡ����س˳���¼�����������ʾ
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"������Ϣ",24,24,RED);
		delay(1500);
		*page=7; //������һ����
		return;
	}
	else
	{
		Connect_Show(r[j]); //��ʾһ����س˳���¼
	}


	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>84&&MouseX<188&& MouseY>293+35&& MouseY<346+35)//��һ��
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
				if(i==0) //��һ��Ϊ�գ�������ʾ
				{
					setfillstyle(1,WHITE);
					bar(84, 293+35, 84 + 104, 293 + 53+35);
					puthz(101,347,"���޸���",16,20,RED);
					delay(1000);
					cover(84, 293+35, 84 + 104, 293 + 53+35, LIGHTBLUE);
	                highlight(84, 293+35, 84 + 104, 293 + 53+35, RED);
	                puthz(98, 308+35, "��һ��", 24, 26, WHITE);
				}
				else //��ʾ��һ���˳���¼
				{
					j--;
					i--;
				    Connect_Show(r[j]);
				    delay(100);
				}
				continue;
			}
	    }
		if(MouseX>435.5&&MouseX<435.5+107&& MouseY>293+35&& MouseY<293+53+35)//��һ��
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
				if(i==amount-1) //��һ��Ϊ��
				{
					setfillstyle(1,WHITE);
					bar(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35);
					puthz(432.5+20+15,347,"���޸���",16,20,RED);
					delay(2000);
					cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTBLUE);
	                highlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35, RED);
	                puthz(461-12+15, 308+35, "��һ��", 24, 26, WHITE);
				}
				else //��ʾ��һ���˳���¼
				{
					j++;
					i++;
				    Connect_Show(r[j]);
				    delay(100);
				}
				continue;
			}
		}
		if(MouseX>255&&MouseX<359&& MouseY>293+35&& MouseY<346+35)//�ܽ�׷��
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
				Find(&r[j]); //�����ܽ�׷��
				clrmous(MouseX,MouseY);
	            delay(100);
	            save_bk_mou(MouseX,MouseY);
	            cleardevice();
	            Draw_Connect();
				Connect_Show(r[j]);
				continue;
			}
	    }
		if(MouseX>55+450&&MouseX<160+450&&MouseY>437&&MouseY<457)//�˳�
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
        if(flag!=0) //��ԭ������
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
		if(MouseS!=0)                               //��ԭ���
		{
			MouseS=0;
		}
	}
}
/*
FUNCTION:Draw_Connect
DESCRIPTION:�����������Ų鿴ȷ�ﻼ�߹������ν���
INPUT:��
RETURN:��
*/
int Draw_Connect()
{
	int d=12;
	cleardevice();
	setbkcolor(DARKGRAY);
	cover(35, 69+20, 35 + 573, 305 + 83+30, LIGHTGRAY);
	highlight(35, 69+20, 35 + 573, 305 + 83+30, LIGHTGREEN);//background
	//�����޸ĵ׿� ���ɫ ����ɫ
	setfillstyle(1,BLUE);
	bar(130,23,524,63);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(LIGHTGREEN);
	rectangle(130,23,524,63);
	cover(130,23,524,63,GREEN);
	puthz(140,30,"��ѡ��ȷ�ﻼ�ߵĳ˳���¼",24,32,WHITE);
	//search_choose_words_bk(90, 100+15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 100+15 + 4.75, "ȷ��˿�", 16, 17, BLACK);
	//search_choose_words_bk(90, 140 + 15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 140 +15 + 4.75, "��������", 16, 17, BLACK);
	//search_choose_words_bk(90, 180 +15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 180 + 15 + 4.75, "�˳�����", 16, 17, BLACK);
	//search_choose_words_bk(90, 220 + 15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 220 + 15 + 4.75, "�ϳ�վ��", 16, 17, BLACK);
	//search_choose_words_bk(90, 260 + 15 + 3, 4, LIGHTRED, WHITE);
	puthz(91, 260 + 15 + 4.75, "�³�վ��", 16, 17, BLACK);

	//*************��Ҫ��д24����
	setcolor(LIGHTGREEN);
	setlinestyle(1, 0, 3);
	line(200, 135, 470, 135);//����
	line(200, 175, 470, 175);//����
	line(200, 215, 470, 215);//����
	line(200, 255, 470, 255);//�ϳ�վ��
	line(200, 295, 470, 295);//�³�վ��

	cover(84, 293+35, 84 + 104, 293 + 53+35, WHITE);
	highlight(84, 293+35, 84 + 104, 293 + 53+35, LIGHTGREEN);
	puthz(110-d, 308+35, "��һ��", 24, 26, LIGHTBLUE);
	cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,WHITE);
	highlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTGREEN);
	puthz(461 - d+15, 308+35, "��һ��", 24, 26, LIGHTBLUE);
	cover(255, 293+35,385, 293 + 53+35, WHITE);
	highlight(255, 293+35,385, 293 + 53+35, LIGHTGREEN);
	puthz(270, 308+35, "�ܽ�׷��", 24, 26, LIGHTBLUE);
	draw_exit(60+450, 440, GREEN,WHITE, BLUE, CYAN);
}
/*
FUNCTION:Connect_Lighten()
DESCRIPTION:����
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
			puthz(110-12, 308+35, "��һ��", 24, 26, WHITE);
			break;
		case 2:
			cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTBLUE);
			highlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTGREEN);
			puthz(461 - 12+15, 308+35, "��һ��", 24, 26, WHITE);
			break;
		case 3:
			cover(255, 293+35,385, 293 + 53+35,LIGHTBLUE);
			highlight(255, 293+35,385, 293 + 53+35, LIGHTGREEN);
			puthz(270, 308+35, "�ܽ�׷��", 24, 26, WHITE);
			break;
	}
}
/*
FUNCTION:Connect_Darken()
DESCRIPTION:�ָ�
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
			puthz(110-12, 308+35, "��һ��", 24, 26, LIGHTBLUE);
			break;
		case 2:
			cover(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,WHITE);
			highlight(432.5+3+15, 293+35, 432.5 + 107+15, 293 + 53+35,LIGHTGREEN);
			puthz(461 - 12+15, 308+35, "��һ��", 24, 26, LIGHTBLUE);
			break;
		case 3:
			cover(255, 293+35,385, 293 + 53+35, WHITE);
			highlight(255, 293+35,385, 293 + 53+35, LIGHTGREEN);
			puthz(270, 308+35, "�ܽ�׷��", 24, 26, LIGHTBLUE);
			break;
	}
}
/*
FUNCTION:Connect_Get
DESCRIPTION:��ȡȷ�ﻼ����Ϣ
INPUT:�˿ʹ���a���洢�˿ͳ˳���¼�Ľṹ������
RETURN:amount
*/
int Connect_Get(int n,struct Record* R)
{
	int flag=0;
	FILE* fp;
	int i=0;
	int amount=0;
	char tool[30]; //��������Ҫ���ַ���
	RECORD* r=NULL; //��ʱ�洢�˳���¼

	if ((fp = fopen("C:\\TRY\\TEXT\\record.dat", "rb+")) == NULL) //���ļ�
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
		fscanf(fp,"%d",&r->contact); //��һ�γ˳���¼
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
DESCRIPTION:��ʾȷ�ﻼ�ߵĹ�������
INPUT:�洢ȷ�ﻼ�߳˳���¼�Ľṹ��r
RETURN:��
*/
int Connect_Show(struct Record r)
{
	char origin[5];
	char terminal[5];
	setfillstyle(1,LIGHTGRAY); //�ڸ�֮ǰ��ʾ����Ϣ
	bar(200,113,470,133);
	bar(200,150,470,173);
    bar(200,184,470,213);
    bar(200,233,470,253);
	bar(200,273,470,293);
	switch(r.origin)
	{
		case 1:
			puthz(200,238, "����", 16,28, WHITE);
			break;
		case 2:
			puthz(200,238, "�廷���", 16,28, WHITE);
			break;
		case 3:
			puthz(200,238, "�ڹ�", 16,28, WHITE);
			break;
		case 4:
			puthz(200,238, "����·", 16,28, WHITE);
			break;
		case 5:
			puthz(200,238, "ѭ����", 16,28, WHITE);
			break;
		case 6:
			puthz(200,238, "���ڱ�", 16,28, WHITE);
			break;
		case 7:
			puthz(200,238, "�޼�ׯ", 16,28, WHITE);
			break;
		case 8:
			puthz(200,238, "�Ʒ�·", 16,28, WHITE);
			break;
		case 9:
			puthz(200,238, "������", 16,28, WHITE);
			break;
		case 10:
			puthz(200,238, "�ռ���", 16,28, WHITE);
			break;
		case 11:
			puthz(200,238, "���Ǻ�", 16,28, WHITE);
			break;
		case 12:
			puthz(200,238, "�������", 16,28, WHITE);
			break;
		case 13:
			puthz(200,238, "��ӻ���", 16,28, WHITE);
			break;
		case 14:
			puthz(200,238, "�������", 16,28, WHITE);
			break;
		case 15:
			puthz(200,238, "��̷·", 16,28, WHITE);
			break;
		case 16:
			puthz(200,238, "����·", 16,28, WHITE);
			break;
		case 17:
			puthz(200,238, "��ȹ㳡", 16,28, WHITE);
			break;
		case 18:
			puthz(200,238, "������", 16,28, WHITE);
			break;
	}
	switch(r.terminal)
	{
		case 1:
			puthz(200,278, "����", 16,28, WHITE);
			break;
		case 2:
			puthz(200,278, "�廷���", 16,28, WHITE);
			break;
		case 3:
			puthz(200,278, "�ڹ�", 16,28, WHITE);
			break;
		case 4:
			puthz(200,278, "����·", 16,28, WHITE);
			break;
		case 5:
			puthz(200,278, "ѭ����", 16,28, WHITE);
			break;
		case 6:
			puthz(200,278, "���ڱ�", 16,28, WHITE);
			break;
		case 7:
			puthz(200,278, "�޼�ׯ", 16,28, WHITE);
			break;
		case 8:
			puthz(200,278, "�Ʒ�·", 16,28, WHITE);
			break;
		case 9:
			puthz(200,278, "������", 16,28, WHITE);
			break;
		case 10:
			puthz(200,278, "�ռ���", 16,28, WHITE);
			break;
		case 11:
			puthz(200,278, "���Ǻ�", 16,28, WHITE);
			break;
		case 12:
			puthz(200,278, "�������", 16,28, WHITE);
			break;
		case 13:
			puthz(200,278, "��ӻ���", 16,28, WHITE);
			break;
		case 14:
			puthz(200,278, "�������", 16,28, WHITE);
			break;
		case 15:
			puthz(200,278, "��̷·", 16,28, WHITE);
			break;
		case 16:
			puthz(200,278, "����·", 16,28, WHITE);
			break;
		case 17:
			puthz(200,278, "��ȹ㳡", 16,28, WHITE);
			break;
		case 18:
			puthz(200,278, "������", 16,28, WHITE);
			break;
	}

	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	setcolor(WHITE);
	puthz(200,117,r.name,16,17,WHITE);
	//outtextxy(200,153,r.train_number); //��ʾ����
	//outtextxy(250,153,r.carriage);
	//puthz(268,157,"��",16,16,WHITE);
	//outtextxy(295,153,r.sit);
	//puthz(330,157,"��",16,16,WHITE);
	if((r.origin>=1&&r.origin<=6||r.terminal>=1&&r.terminal<=6)&&(r.origin>=7&&r.origin<=12||r.terminal>=7&&r.terminal<=12)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"1");
		outtextxy(250,145,"2");
	}
	else if((r.origin>=1&&r.origin<=6||r.terminal>=1&&r.terminal<=6)&&(r.origin>=13&&r.origin<=18||r.terminal>=13&&r.terminal<=18)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"1");
		outtextxy(250,145,"3");
	}
	else if((r.origin>=13&&r.origin<=18||r.terminal>=13&&r.terminal<=18)&&(r.origin>=7&&r.origin<=12||r.terminal>=7&&r.terminal<=12)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"2");
		outtextxy(250,145,"3");
	}
	else if((r.origin>=1&&r.origin<=6||r.terminal>=1&&r.terminal<=6)&&(r.origin>=1&&r.origin<=6||r.terminal>=1&&r.terminal<=6)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"1");
	}
	else if((r.origin>=7&&r.origin<=12||r.terminal>=7&&r.terminal<=12)&&(r.origin>=7&&r.origin<=12||r.terminal>=7&&r.terminal<=12)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"2");
	}
	else if((r.origin>=13&&r.origin<=18||r.terminal>=13&&r.terminal<=18)&&(r.origin>=13&&r.origin<=18||r.terminal>=13&&r.terminal<=18)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(200,145,"3");
	}
	/*outtextxy(200,193,"2022"); *///��ʾ������
	puthz(257,197,"��",16,28,WHITE);
	//outtextxy(275,193,r.month);
	puthz(295,197,"��",16,28,WHITE);
	//outtextxy(315,193,r.day);
	puthz(342,197,"��",16,28,WHITE);
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

