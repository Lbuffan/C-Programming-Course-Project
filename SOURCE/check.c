#include"public.h"
#include"check.h"

/*
FUNCTION:Patient_Check
DESCRIPTION:�������Ų�ѯ�˿ͳ˳���¼
INPUT:�˿����֤��ID
RETURN:��
*/
void Patient_Check(char* ID)
{	
	int i; //��ǵ�ǰ�����˳���¼
	int identity; //��¼�˿ʹ���
	int amount; //��¼�˳���¼����
	int flag=0; //��ǵ������
	int tag=0; //��ǳ˿�״̬��0Ϊ������1Ϊ�ܽӣ�2Ϊȷ��
	char name[7]; //��¼��ǰ�˿�����
	RECORD R[6]; //��¼�˿ͳ˳���¼�������ͷ
	Station a[18];
	
	clrmous(MouseX, MouseY);
	delay(100);
    save_bk_mou(MouseX, MouseY);
    cleardevice();
	
	Draw_Patient_Check(); //���ƽ���
	identity=Patient_Identity_Get(ID,name); //��ȡ��ǰ�˿͵Ĵ���
	//printf("identity=%d\n",identity);getchar();
	amount=Record_Get(identity,R); //��ȡ��ǰ�˿͵ĳ˳���¼
	//printf("origin=%d\n",R->origin);getchar();
	i=0;
	Patient_Record(&R[i]); //��ʾ��ǰ�˿͵�һ�γ˳���¼
	
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
					Patient_Lighten2(1);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(81, 358, 183, 419) == 1)//�鿴��һ������
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				Patient_Lighten2(1);
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
					Patient_Record(&R[i]);
				}
				delay(200);
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
					Patient_Lighten2(2);
					flag=2;
				}
				continue;
			}
			else if (mouse_press(226, 358, 413, 419) == 1)//��ʾ�켣���
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
				/*clrmous(MouseX, MouseY);
	            delay(100);
                save_bk_mou(MouseX, MouseY);
                cleardevice();*/
	            Draw_Patient_Check(); //������ʾ��ǰ�˳���¼
				Patient_Record(&R[i]);
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
					Patient_Lighten2(3);
					flag=3;
				}
				continue;
			}
			else if (mouse_press(459, 358, 561, 419) == 1)//��һ�����
			{
				MouseS = 0;
				clrmous(MouseX,MouseY);
				Patient_Lighten2(3);
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
					Patient_Record(&R[i]);
				}
				delay(200);
			}
		}
		if (MouseX > 465 && MouseX < 570 && MouseY> 14 && MouseY < 34)
		{
			if (mouse_press(465, 14, 570, 34) == 2)//����˳�δ���
			{
				MouseS = 1;
				continue;
			}
			else if (mouse_press(465, 14, 570, 34) == 1)//����˳����
			{
				MouseS=0;
				return; //������һ����
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
DESCRIPTION:�����������Ų�ѯ�˿ͳ˳���¼����
INPUT:��
RETURN:��
*/
int Draw_Patient_Check()
{
	int i; //for��丨������	
	int mainhzcolor = GREEN;
	int fillcolor = LIGHTGRAY;
	int buttoncolor = BLUE;
	int textstyle = 3;
	
	cleardevice();
    cover(0, 0, 639, 479, WHITE);
	//setbkcolor(DARKGRAY);
	puthz(305, 14, "�˳���¼", 24, 25.5, mainhzcolor);
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
	highlight(419.5, 67.5, 419.5 + 139, 67.5 + 63, GREEN);	//��㼰�յ�
	setcolor(mainhzcolor);
	settextjustify(0, 2);
	settextstyle(textstyle, 0, 3);
	highlight(81.72, 358.75, 81.72 + 101, 358.75 + 60.5, BLACK);
	puthz(96, 377, "��һ��", 24, 24.5, buttoncolor);
	highlight(226, 358.75, 226 + 187, 358.75 + 60.5, BLACK);
	puthz(247, 376.75, "�鿴�˳��켣", 24, 24.5, buttoncolor);
	highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
	puthz(475.88, 377, "��һ��", 24, 24.5, buttoncolor);
	cover(200,235,440,330,LIGHTGRAY);
	highlight(200,235,440,330,GREEN);
	puthz(240,240,"��·",24,24,BLUE);
	puthz(320,240,"����ʱ��",24,24,BLUE); //������Ϣ
	//puthz(100, 88, "����", 24, 24, WHITE);
	//puthz(100, 88, "�廷���", 24, 24, WHITE);
	//puthz(100, 88, "����·", 24, 24, WHITE);
	puthz(139+120+18+4, 190, "��", 24, 24, GREEN);
	puthz(202+120+18, 190, "��", 24, 24, GREEN);
	puthz(260+120+18, 190, "��", 24, 24, GREEN);
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
	puthz(220, 14, "��һ��", 24, 25.5, RED);*/
}
/*
FUNCTION:Patient_Lighten2()
DESCRIPTION:����
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
			puthz(96, 377, "��һ��", 24, 24.5,BLUE);
			break;
		case 2:
			highlight(226, 358.75, 226 + 187, 358.75 + 60.5, BLACK);
			cover(226, 358.75, 226 + 187, 358.75 + 60.5, LIGHTGRAY);
			puthz(247, 376.75, "�鿴�˳��켣", 24, 24.5, BLUE);
			break;
		case 3:
			highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
			cover(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, LIGHTGRAY);
			puthz(475.88, 377, "��һ��", 24, 24.5, BLUE);
			break;
	}
}
/*
FUNCTION:Patient_Darken2
DESCRIPTION:�ָ�
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
			puthz(96, 377, "��һ��", 24, 24.5,BLUE);
			break;
		case 2:
			highlight(226, 358.75, 226 + 187, 358.75 + 60.5, BLACK);
			cover(226, 358.75, 226 + 187, 358.75 + 60.5, WHITE);
			puthz(247, 376.75, "�鿴�˳��켣", 24, 24.5, BLUE);
			break;
		case 3:
			highlight(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, BLACK);
			cover(459.75, 358.75, 459.75 + 101, 358.75 + 60.5, WHITE);
			puthz(475.88, 377, "��һ��", 24, 24.5, BLUE);
			break;
	}
}
/*
FUNCTION:Patient_Identity_Get
DESCRIPTION:�������Ż�ȡ�˿���Ϣ
INPUT:�˿����֤��ID���˿�����name
RETURN:�˿ʹ���flag
*/
int Patient_Identity_Get(char* ID,char* name)
{
	int flag; //��¼��ǰ�˳�����
	PASSENGER* p;
	FILE* fp;
	if((fp=fopen("C:\\TRY\\TEXT\\pass.dat", "rb+" )) == NULL) //�򿪴洢�û���Ϣ���ļ�
	{
		printf("\nError on open file pass.dat!");
		delay(3000);
		exit(1);
	}
	flag=0; 
	while(!feof(fp))
	{
		if((p=(PASSENGER*)malloc(sizeof(PASSENGER)))==NULL)     //����ռ�
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
		
		if(strcmp(p->ID,ID)==0) //�����ĳ˿����֤��ƥ��
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
	return flag; //���ص�ǰ�˿ʹ���
}
/*
FUNCTION:Record_Get
DESCRIPTION:��ȡ�˿ͳ˳���¼
INPUT:�˿ʹ���n,�洢�˿ͳ˳���¼�Ľṹ������
RETURN:��
*/
int Record_Get(int n,struct Record* R)
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
DESCRIPTION:��ʾ�˿ͳ˳���¼��Ϣ
INPUT:�洢�˿ͳ˳���¼�Ľṹ��r
RETURN:��
*/
int Patient_Record(struct Record *r)
{
	/*cover(79.5, 67.5, 79.5 + 139, 67.5 + 63, LIGHTGRAY); //�ڸ�֮ǰ��ʾ����Ϣ
	highlight(79.5, 67.5, 79.5 + 139, 67.5 + 63, GREEN);
	cover(419.5, 67.5, 419.5 + 139, 67.5 + 63, LIGHTGRAY);
	highlight(419.5, 67.5, 419.5 + 139, 67.5 + 63, GREEN);
	cover(200,235,440,330,LIGHTGRAY);
	highlight(200,235,440,330,GREEN);
	puthz(240,240,"��·",24,24,BLUE);
	puthz(320,240,"����ʱ��",24,24,BLUE); //������Ϣ*/
	Draw_Patient_Check();
	//puts(r->name);
	//printf("%d\n",r->number);
	//printf("%d\n",r->origin);
	//printf("%d\n",r->subway_number[0]);
	switch(r->origin)
	{
		case 1:
			puthz(100, 88, "����", 24, 24, WHITE);
			break;
		case 2:
			puthz(100, 88, "�廷���", 24, 24, WHITE);
			break;
		case 3:
			puthz(100, 88, "�ڹ�", 24, 24, WHITE);
			break;
		case 4:
			puthz(100, 88, "����·", 24, 24, WHITE);
			break;
		case 5:
			puthz(100, 88, "ѭ����", 24, 24, WHITE);
			break;
		case 6:
			puthz(100, 88, "���ڱ�", 24, 24, WHITE);
			break;
		case 7:
			puthz(100, 88, "�޼�ׯ", 24, 24, WHITE);
			break;
		case 8:
			puthz(100, 88, "�Ʒ�·", 24, 24, WHITE);
			break;
		case 9:
			puthz(100, 88, "������", 24, 24, WHITE);
			break;
		case 10:
			puthz(100, 88, "�ռ���", 24, 24, WHITE);
			break;
		case 11:
			puthz(100, 88, "���Ǻ�", 24, 24, WHITE);
			break;
		case 12:
			puthz(100, 88, "�������", 24, 24, WHITE);
			break;
		case 13:
			puthz(100, 88, "��ӻ���", 24, 24, WHITE);
			break;
		case 14:
			puthz(100, 88, "�������", 24, 24, WHITE);
			break;
		case 15:
			puthz(100, 88, "��̷·", 24, 24, WHITE);
			break;
		case 16:
			puthz(100, 88, "����·", 24, 24, WHITE);
			break;
		case 17:
			puthz(100, 88, "��ȹ㳡", 24, 24, WHITE);
			break;
		case 18:
			puthz(100, 88, "������", 24, 24, WHITE);
			break;
	}
	switch(r->terminal)
	{
		case 1:
			puthz(440, 88, "����", 24, 24, WHITE);
			break;
		case 2:
			puthz(440, 88, "�廷���", 24, 24, WHITE);
			break;
		case 3:
			puthz(440, 88, "�ڹ�", 24, 24, WHITE);
			break;
		case 4:
			puthz(440, 88, "����·", 24, 24, WHITE);
			break;
		case 5:
			puthz(440, 88, "ѭ����", 24, 24, WHITE);
			break;
		case 6:
			puthz(440, 88, "���ڱ�", 24, 24, WHITE);
			break;
		case 7:
			puthz(440, 88, "�޼�ׯ", 24, 24, WHITE);
			break;
		case 8:
			puthz(440, 88, "�Ʒ�·", 24, 24, WHITE);
			break;
		case 9:
			puthz(440, 88, "������", 24, 24, WHITE);
			break;
		case 10:
			puthz(440, 88, "�ռ���", 24, 24, WHITE);
			break;
		case 11:
			puthz(440, 88, "���Ǻ�", 24, 24, WHITE);
			break;
		case 12:
			puthz(440, 88, "�������", 24, 24, WHITE);
			break;
		case 13:
			puthz(440, 88, "��ӻ���", 24, 24, WHITE);
			break;
		case 14:
			puthz(440, 88, "�������", 24, 24, WHITE);
			break;
		case 15:
			puthz(440, 88, "��̷·", 24, 24, WHITE);
			break;
		case 16:
			puthz(440, 88, "����·", 24, 24, WHITE);
			break;
		case 17:
			puthz(440, 88, "��ȹ㳡", 24, 24, WHITE);
			break;
		case 18:
			puthz(440, 88, "������", 24, 24, WHITE);
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
DESCRIPTION:�����μ�ʱ��
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
	
	if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"1");
		outtextxy(240+20,300,"2");
		outtextxy(320+20,270,number[0]);
		outtextxy(321+20,300,number[1]);
	}
	else if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"1");
		outtextxy(240+20,300,"3");
		outtextxy(320+20,270,number[0]);
		outtextxy(321+20,300,number[2]);
	}
	else if((r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"2");
		outtextxy(240+20,300,"3");
		outtextxy(320+20,270,number[1]);
		outtextxy(321+20,300,number[2]);
	}
	else if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"1");
		outtextxy(320+20,270,number[0]);
	}
	else if((r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"2");
		outtextxy(320+20,270,number[1]);
	}
	else if((r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)) //һ������
	{
		setcolor(WHITE);
		settextjustify(0, 2);
		settextstyle(3, 0, 3);
		outtextxy(240+20,270,"3");
		outtextxy(320+20,270,number[2]);
	}
}

