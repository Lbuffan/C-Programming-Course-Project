#include "public.h"
#include "patient.h"
#include "check.h"
/*
FUNCTION:Patient
DESCRIPTION:�鿴ȷ�ﻼ�߹���
INPUT:page
RETURN:NO
*/
void Patient(int* page)
{
	int flag=0; //��ǵ������
	int all=0; //��¼�ܳ˿���
	int func=0; //��¼һ������ҳ
	int now=1; //��¼��ǰҳ��
	int i;
	char f[3]={"\0"}; //��ҳ��
	char n[3]={"\0"}; //��ǰҳ��
	int a[10]={0}; //��¼ȷ��˿ʹ���
	char* ID[4]={"\0","\0","\0","\0"}; //�洢��ǰҳȷ֤�˿͵����֤��
	PATIENT P[10]; //ȷ��˿�
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	
	for(i=0;i<10;i++)
	{
		P[i].count=0;
	}
	Draw_Patient(); //���ƻ���
	Patient_Search(a); //��ȡȷ��˿ʹ���
	all=Patient_Get(a,P); //��ȡȷ��˿���Ϣ
	if(P[0].count==0) //���û�л�ȡ���κγ˳���¼�����������ʾ
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"������Ϣ",24,24,RED);
		delay(3000);
		*page=7; //������������������
		return;
	}
	
	Patient_Show(now,P,ID);	//��ʾȷ�ﻼ����Ϣ
	func=(all-1)/4+1;	//������ҳ��
	itoa(func,f,10);
	setcolor(GREEN);
	outtextxy(328,434,f);
	outtextxy(305,434,"1");
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>260&&MouseX<305&&MouseY>212&&MouseY<235&&strcmp(ID[0],"\0")!=0)	//�鿴
		{	
			if(mouse_press(260,212,305,235)==2)
			{
				MouseS=1;
				if(flag==0)
				{
					clrmous(MouseX,MouseY);
					Patient_Lighten(1);
					flag=1;
				}
				continue;
			}
			else if(mouse_press(260,212,305,235)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Patient_Lighten(1);
				Patient_Check(ID[0]); //��ѯ�˳���¼
				clrmous(MouseX,MouseY);
				delay(100);
				save_bk_mou(MouseX,MouseY);
				Draw_Patient();
				Patient_Show(now,P,ID);
				outtextxy(328,434,f);
				itoa(now,n,10);
				if(strlen(n)==2)
				{
					outtextxy(290,434,n);
				}
				else
				{
					outtextxy(305,434,n);
				}
				continue;
			}
		}
		if(MouseX>260+240&&MouseX<305+240&& MouseY>212&& MouseY<235&&strcmp(ID[1],"\0")!=0)//�����2
		{
			if(mouse_press(260+240,212,305+240,235)==2)               
			{
				MouseS=1;				
				if(flag==0)
				{
					clrmous(MouseX,MouseY);
					Patient_Lighten(2);
					flag=2;
				}
				continue;
			}
			else if(mouse_press(260+240,212,305+240,235)==1)        
			{
				MouseS=0;    
				clrmous(MouseX,MouseY);
				Patient_Lighten(2);
				Patient_Check(ID[1]);
				clrmous(MouseX,MouseY);
	            delay(100);
	            save_bk_mou(MouseX,MouseY);
				Draw_Patient(); //���»��ƽ���
				Patient_Show(now,P,ID); //��ʾһ��ȷ��˿���Ϣ
				outtextxy(328,434,f);
				itoa(now,n,10);
				if(strlen(n)==2) //��ʾ��ǰҳ��
				{
					outtextxy(290,434,n);
				}
				else
				{
					outtextxy(305,434,n);
				}
				continue;
			}
	    }
		if(MouseX>260&&MouseX<305&& MouseY>212+160&& MouseY<235+160&&strcmp(ID[2],"\0")!=0)//�����3
		{
			if(mouse_press(260,212+160,305,235+160)==2)               
			{
				MouseS=1;				
				if(flag==0)
				{
					clrmous(MouseX,MouseY);
					Patient_Lighten(3);
					flag=3;
				}
				continue;
			}
			else if(mouse_press(260,212+160,305,235+160)==1)        
			{
				MouseS=0;    
				clrmous(MouseX,MouseY);
				Patient_Lighten(3);
				Patient_Check(ID[2]);
				clrmous(MouseX,MouseY);
	            delay(100);
	            save_bk_mou(MouseX,MouseY);
				Draw_Patient(); //���»��ƽ���
				Patient_Show(now,P,ID); //��ʾһ��ȷ��˿���Ϣ
				outtextxy(328,434,f);
				itoa(now,n,10);
				if(strlen(n)==2) //��ʾ��ǰҳ��
				{
					outtextxy(290,434,n);
				}
				else
				{
					outtextxy(305,434,n);
				}
				continue;
			}
	    }
		if(MouseX>260+240&&MouseX<305+240&& MouseY>212+160&& MouseY<235+160&&strcmp(ID[3],"\0")!=0)//�����4
		{
			if(mouse_press(260+240,212+160,305+240,235+160)==2)               
			{
				MouseS=1;				
				if(flag==0)
				{
					clrmous(MouseX,MouseY);
					Patient_Lighten(4);
					flag=4;
				}
				continue;
			}
			else if(mouse_press(260+240,212+160,305+240,235+160)==1)        
			{
				MouseS=0;    
				clrmous(MouseX,MouseY);
				Patient_Lighten(4);
				Patient_Check(ID[3]);
				clrmous(MouseX,MouseY);
	            delay(100);
	            save_bk_mou(MouseX,MouseY);
				Draw_Patient(); //���»��ƽ���
				Patient_Show(now,P,ID); //��ʾһ��ȷ��˿���Ϣ
				outtextxy(328,434,f);
				itoa(now,n,10);
				if(strlen(n)==2) //��ʾ��ǰҳ��
				{
					outtextxy(290,434,n);
				}
				else
				{
					outtextxy(305,434,n);
				}
				continue;
			}
	    }
		if(MouseX>220&&MouseX<260&&MouseY>437&&MouseY<457) //��һҳ
		{
			if(mouse_press(220,437,260,457)==2)
			{
				MouseS=1;
				if(flag==0)
				{
					clrmous(MouseX,MouseY);
					Patient_Lighten(5);
					flag=5;
				}
				continue;
			}
			else if(mouse_press(220,437,260,457)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Patient_Lighten(5);
				if(now==1)
				{
					setfillstyle(1,WHITE);
					puthz(272,408,"���޸���",24,24,RED);
					delay(2000);
					bar(272,408,368,432);
				}
				else
				{
					for(i=0;i<4;i++)
					{
						ID[i]="\0";
					}
					now--;
					itoa(now,n,10);
					Patient_Cover();
					Patient_Show(now,P,ID);
					if(strlen(n)==2)
					{
						outtextxy(290,434,n);
					}
					else
					{
						outtextxy(305,434,n);
					}
				}
				delay(200);
			}
			continue;
		}
		if(MouseX>380&&MouseX<437&&MouseY>420&&MouseY<457) //��һҳ
		{
			if(mouse_press(380,437,420,457)==2)
			{
				MouseS=1;
				if(flag==0)
				{
					clrmous(MouseX,MouseY);
					Patient_Lighten(6);
					flag=6;
				}
				continue;
			}
			else if(mouse_press(380,437,420,457)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Patient_Lighten(6);
				if(now==func)
				{
					setfillstyle(1,WHITE);
					puthz(272,408,"���޸���",24,24,RED);
					delay(2000);
					bar(272,408,368,432);
				}
				else
				{
					for(i=0;i<4;i++) 
					{
						ID[i]="\0";
					}
					now++;
					itoa(now,n,10);
					Patient_Cover();
					Patient_Show(now,P,ID);
					if(strlen(n)==2)
					{
						outtextxy(290,434,n);
					}
					else
					{
						outtextxy(305,434,n);
					}
				}
				delay(200);
			}
			continue;
		}
		if(MouseX>480&&MouseX<585&&MouseY>437&&MouseY<457) //����˳�
		{
			if(mouse_press(480,437,585,457)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(480,437,585,457)==1)
			{
				MouseS=0;
				*page=7;
				break;
			}
		}
		if(MouseX>55&&MouseX<437&&MouseY>160&&MouseY<457) //��������
		{
			if(mouse_press(55,437,160,457)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(55,437,160,457)==1)
			{
				MouseS=0;
				delay(200);
				return;
			}
		}
		if(flag!=0)
		{
			MouseS=0;
			switch(flag)
			{
				case 1:
					clrmous(MouseX,MouseY);
					Patient_Darken(1);
					break;
				case 2:
					clrmous(MouseX,MouseY);
					Patient_Darken(2);
					break;
				case 3:
					clrmous(MouseX,MouseY);
					Patient_Darken(3);
					break;
				case 4:
					clrmous(MouseX,MouseY);
					Patient_Darken(4);
					break;
				case 5:
					clrmous(MouseX,MouseY);
					Patient_Darken(5);
					break;
				case 6:
					clrmous(MouseX,MouseY);
					Patient_Darken(6);
					break;
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
FUNCTION:Draw_Patient
DESCRIPTION:�����������Ų鿴ȷ�ﻼ����Ϣ����
INPUT:NO
RETURN:NO
*/
int Draw_Patient()
{
	cleardevice();
	setbkcolor(WHITE);
	highlight(0, 0, 639, 479, GREEN);
	cover(118, 10, 118 + 405, 10 + 32, BLUE);
	highlight(118, 10, 118 + 405, 10 + 32,LIGHTGREEN);
	puthz(220, 14, "�����鿴�˿���Ϣ", 24, 24 + 2, WHITE);
	setcolor(GREEN);
	setlinestyle(SOLID_LINE, 0, 3);
	rectangle(80,80,560,400);
	line(80,240,560,240);
	line(320,80,320,400);
	setcolor(BLUE);
    rectangle(260,437,380,457);
	rectangle(220,437,260,457);	//��һҳ
	rectangle(380,437,420,457);
	puthz(267,439,"��",16,16,RED);
	puthz(357,439,"ҳ",16,16,RED);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	setlinestyle(SOLID_LINE, 0, 1);
	line(317,454,323,440);
	line(385,440,385,454);
	line(385,440,415,447);
	line(385,454,415,447);
	line(255,440,255,454);
	line(255,440,225,447);
	line(255,454,225,447);
	draw_exit(485, 440, WHITE, RED, GREEN, CYAN);
	draw_refresh(60,440, WHITE, RED, GREEN, GREEN);
	
	setcolor(BLUE);
	puthz(90,90,"��������",16,16,BLUE);
	outtextxy(160,82,":");
	puthz(90,113,"�绰����",16,16,BLUE);
	outtextxy(160,105,":");
	puthz(90,136,"���֤��",16,16,BLUE);
	outtextxy(160,128,":");
	//puthz(90,174,"֢״����",16,16,BLUE);
	outtextxy(130,166,":");
	puthz(90,197,"����",16,16,BLUE);
	outtextxy(130,189,":");
	puthz(90,174,"�Ա�",16,16,BLUE);
	//outtextxy(130,212,":");
	puthz(235,193,"���",16,16,BLUE);
	outtextxy(275,185,":");
	cover(260,212,305,235,BLUE);
	highlight(260,212,305,235,CYAN);
	puthz(266,217,"�鿴",16,19,WHITE);
	
	setcolor(BLUE);
	puthz(90+240,90,"��������",16,16,BLUE);
	outtextxy(160+240,82,":");
	puthz(90+240,113,"�绰����",16,16,BLUE);
	outtextxy(160+240,105,":");
	puthz(90+240,136,"���֤��",16,16,BLUE);
	outtextxy(160+240,128,":");
	//puthz(90+240,174,"֢״����",16,16,BLUE);
	outtextxy(130+240,166,":");
	puthz(90+240,197,"����",16,16,BLUE);
	outtextxy(130+240,189,":");
	puthz(90+240,174,"�Ա�",16,16,BLUE);
	//outtextxy(130+240,212,":");
	puthz(235+240,193,"���",16,16,BLUE);
	outtextxy(275+240,185,":");
	cover(260+240,212,305+240,235,BLUE);
	highlight(260+240,212,305+240,235,CYAN);
	puthz(266+240,217,"�鿴",16,19,WHITE);
	
	setcolor(BLUE);
	puthz(90,90+160,"��������",16,16,BLUE);
	outtextxy(160,82+160,":");
	puthz(90,113+160,"�绰����",16,16,BLUE);
	outtextxy(160,105+160,":");
	puthz(90,136+160,"���֤��",16,16,BLUE);
	outtextxy(160,128+160,":");
	//puthz(90,174+160,"֢״����",16,16,BLUE);
	outtextxy(130,166+160,":");
	puthz(90,197+160,"����",16,16,BLUE);
	outtextxy(130,189+160,":");
	puthz(90,174+160,"�Ա�",16,16,BLUE);
	//outtextxy(130,212+160,":");
	puthz(235,193+160,"���",16,16,BLUE);
	outtextxy(275,185+160,":");
	cover(260,212+160,305,235+160,BLUE);
	highlight(260,212+160,305,235+160,CYAN);
	puthz(266,217+160,"�鿴",16,19,WHITE);
	
	setcolor(BLUE);
	puthz(90+240,90+160,"��������",16,16,BLUE);
	outtextxy(160+240,82+160,":");
	puthz(90+240,113+160,"�绰����",16,16,BLUE);
	outtextxy(160+240,105+160,":");
	puthz(90+240,136+160,"���֤��",16,16,BLUE);
	outtextxy(160+240,128+160,":");
	//puthz(90+240,174+160,"֢״����",16,16,BLUE);
	outtextxy(130+240,166+160,":");
	puthz(90+240,197+160,"����",16,16,BLUE);
	outtextxy(130+240,189+160,":");
	puthz(90+240,174+160,"�Ա�",16,16,BLUE);
	//outtextxy(130+240,212+160,":");
	puthz(235+240,193+160,"���",16,16,BLUE);
	outtextxy(275+240,185+160,":");
	cover(260+240,212+160,305+240,235+160,BLUE);
	highlight(260+240,212+160,305+240,235+160,CYAN);
	puthz(266+240,217+160,"�鿴",16,19,WHITE);
}
/*
FUNCTION:Patient_Cover
DESCRIPTION:�ڸ���һҳ����ʾ��ȷ�ﻼ����Ϣ
INPUT:��
RETURN:��
*/
int Patient_Cover()
{
	setfillstyle(1,WHITE);
	bar(290,440,316,455); //�ڵ�ǰҳ��

	bar(167,90,215,106); //������
	bar(167,108,295,132); //�ڵ绰
	bar(90,154,305,174); //�����֤��
	bar(167,174,215,190); //��֢״����
	bar(137,174,137+10,174+18); //������

	bar(137,174,159,236); //���Ա�

	bar(290,188,310,210); //�����
	
	bar(167+240,90,215+240+10,106); //������
	bar(167+240,108,295+240,132); //�ڵ绰
	bar(90+240,154,305+240,174); //�����֤��
	bar(167+240,174,215+240,190); //��֢״����
	bar(138+240,192,158+240,216); //������

	bar(137+240,174,159+240,236); //���Ա�

	bar(290+240,188,310+240,210); //�����
	
	bar(167,90+160,215,106+160); //������
	bar(167,108+160,295,132+160); //�ڵ绰
	bar(90,154+160,305,174+160); //�����֤��
	bar(167,174+160,215,190+160); //��֢״����
	bar(138,192+160,158,216+160); //������
	bar(137,174+160,159,236+160); //���Ա�
	bar(290,188+160,310,210+160); //�����
	
	bar(167+240,90+160,215+240,106+160); //������
	bar(167+240,108+160,295+240,132+160); //�ڵ绰
	bar(90+240,154+160,305+240,174+160); //�����֤��
	bar(167+240,174+160,215+240,190+160); //��֢״����
	bar(138+240,192+160,158+240,216+160); //������
	bar(137+240,174+160,159+240,236+160); //���Ա�
	bar(290+240,188+160,310+240,210+160); //�����
}
/*
FUNCTION:Patient_Lighten
DESCRIPTION:����
INPUT:flag
RETURN:NO
*/
int Patient_Lighten(int flag)
{
	switch(flag)
	{
		case 1:
		    cover(260,212,305,235,LIGHTBLUE);
	        highlight(260,212,305,235,CYAN);
	        puthz(266,217,"�鿴",16,19,WHITE);
			break;
		case 2:
		    cover(260+240,212,305+240,235,LIGHTBLUE);
	        highlight(260+240,212,305+240,235,CYAN);
	        puthz(266+240,217,"�鿴",16,19,WHITE);
			break;
		case 3:
		    cover(260,212+160,305,235+160,LIGHTBLUE);
	        highlight(260,212+160,305,235+160,CYAN);
	        puthz(266,217+160,"�鿴",16,19,WHITE);
			break;
		case 4:
		    cover(260+240,212+160,305+240,235+160,LIGHTBLUE);
	        highlight(260+240,212+160,305+240,235+160,CYAN);
	        puthz(266+240,217+160,"�鿴",16,19,WHITE);
			break;
		case 5: //��һҳ
		    setlinestyle(SOLID_LINE, 0, 3);
		    setfillstyle(1,LIGHTBLUE);
			bar(220,437,260,457);
			setcolor(WHITE);
			setlinestyle(SOLID_LINE, 0, 1);
			line(255,440,255,454);
	        line(255,440,225,447);
	        line(255,454,225,447);
			break;
		case 6: //��һҳ
		    setlinestyle(SOLID_LINE, 0, 3);
		    setfillstyle(1,LIGHTBLUE);
			bar(380,437,420,457);
			setcolor(WHITE);
			setlinestyle(SOLID_LINE, 0, 1);
			line(385,440,385,454);
	        line(385,440,415,447);
	        line(385,454,415,447);
			break;
	}
	
}
/*
FUNCTION:Patient_Darken
DESCRIPTION:�ָ�
INPUT:flag
RETURN:NO
*/
int Patient_Darken(int flag)
{
	switch(flag)
	{
		case 1:
		    cover(260,212,305,235,BLUE);
	        highlight(260,212,305,235,CYAN);
	        puthz(266,217,"�鿴",16,19,WHITE);
			break;
		case 2:
		    cover(260+240,212,305+240,235,BLUE);
	        highlight(260+240,212,305+240,235,CYAN);
	        puthz(266+240,217,"�鿴",16,19,WHITE);
			break;
		case 3:
		    cover(260,212+160,305,235+160,BLUE);
	        highlight(260,212+160,305,235+160,CYAN);
	        puthz(266,217+160,"�鿴",16,19,WHITE);
			break;
		case 4:
		    cover(260+240,212+160,305+240,235+160,BLUE);
	        highlight(260+240,212+160,305+240,235+160,CYAN);
	        puthz(266+240,217+160,"�鿴",16,19,WHITE);
			break;
		case 5:
		    setlinestyle(SOLID_LINE, 0, 3);
		    setfillstyle(1,WHITE);
			bar(220,437,260,457);
			setcolor(BLUE);
			rectangle(220,437,260,457);
			setlinestyle(SOLID_LINE, 0, 1);
			line(255,440,255,454);
	        line(255,440,225,447);
	        line(255,454,225,447);
			break;
		case 6:
		    setlinestyle(SOLID_LINE, 0, 3);
		    setfillstyle(1,WHITE);
			bar(380,437,420,457);
			setcolor(BLUE);
			rectangle(380,437,420,457);
			setlinestyle(SOLID_LINE, 0, 1);
			line(385,440,385,454);
	        line(385,440,415,447);
	        line(385,454,415,447);
			break;
	}
}
/*
FUNCTION:Patient_Search
DESCRIPTION:���һ�ȡȷ���ߴ���
INPUT:�洢ȷ�ﻼ�ߴ��ŵ�����a
RETURN:��
*/
int Patient_Search(int* a)
{
	int l;	//��¼�ļ�����
	int i;	
	FILE* fp;
	STATE* s;
	if((fp=fopen("C:\\TRY\\TEXT\\STATE.DAT","rb+"))==NULL)
	{
		printf("\nError on open file STATE.DAT");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);
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
		if(s->patient!=0)
		{
			*a=s->number;
			a++;
		}
		//printf("%d",a[0]);
		if(s!=NULL)		//�ͷ��ڴ�
		{
			free(s);
			s=NULL;
		}
	}
	if(fclose(fp)!=0)
	{
		printf("\nError on close STATE.DAT");
		delay(3000);
		exit(1);
	}
}
/*
FUNCTION:Patient_Get
DESCRIPTION:��ȡȷ�ﻼ�߸�����Ϣ
INPUT:�洢ȷ�ﻼ�ߴ��ŵ�����a���洢ȷ�ﻼ����Ϣ�Ľṹ������
RETURN:ȷ��������count
*/
int Patient_Get(int* a,struct Patient* P)
{
	FILE* fp;
	FILE* fp2;
	PASSENGER* p;
	STATE* s;
	int count=0;	//��¼��ǰȷ��˿����
	int l,i;
	if((fp=fopen("C:\\TRY\\TEXT\\pass.dat","rb+"))==NULL)
	{
		printf("\nError on open file pass.dat!");
		delay(3000);
		exit(1);
	}
	/*if((fp2=fopen("C:\\TRY\\TEXT\\STATE.DAT","rb+"))==NULL)
	{
		printf("\nError on open file STATE.DAT");
		delay(3000);
		exit(1);
	}*/
	while(!feof(fp))
	{
		if(count>=20)
		{
			break;
		}
		if((p=(PASSENGER*)malloc(sizeof(PASSENGER)))==NULL)
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
		if(p->number==*a)
		{
			count++;	//ȷ��������1
			P->number=*a;
			P->count=count;
			strcpy(P->name,p->name);
			strcpy(P->telephone,p->telephone);
			strcpy(P->ID,p->ID);
			strcpy(P->age,p->age);
			strcpy(P->sex,p->sex);
			/*fseek(fp,0,SEEK_END);
			l=ftell(fp)/sizeof(STATE);*/
			/*for(i=0;i<l;i++)
			{
				if((s=(STATE*)malloc(sizeof(STATE)))==NULL)
				{
					printf("\nMemory not enough!");
					delay(3000);
					exit(1);
				}
				fseek(fp,i*sizeof(STATE),SEEK_SET);
				fread(s,sizeof(STATE),1,fp);*/
			a++;
			P++;
		}
		if(p!= NULL) //�ͷ��ڴ�
		{
			free(p);
			p=NULL;
		}
	}
	if (fclose(fp)!=0) //�ر��ļ�
	{
		printf("\nError on close pass.dat!");
		delay(3000);
		exit(1);
	}
	return count; //����������
}
/*
FUNCTION:Patient_Show
DESCRIPTION:��ʾȷ�ﻼ����Ϣ
INPUT:��ǰҳ��now���洢ȷ�ﻼ����Ϣ�Ľṹ�����飬�洢��ǰҳ��ȷ�ﻼ�����֤�ŵ��ַ�������ID
RETURN:��
*/
int Patient_Show(int now,struct Patient* P,char** ID)
{
	int i=0;
	int j;
	char count[4];
	//printf("\nok766");
	//printf("\nnow=%d",now);
	for(j=0;j<20;j++)
	{
		//printf("\nok769");
		if(j+1>4*(now-1)&&j+1<=4*now) //ȷ��˿�����ڵ�ǰҳ
		{
			//printf("\nok772");
			if(P[j].count!=0)
			{
				//printf("\nok776");
			    ID[i]=P[j].ID; //���뵱ǰ��ȡ����ȷ��˿����֤��
			    i++; //��ǳ˿Ͷ�Ӧλ��
				if(i==1)
				{
					itoa(P[j].count,count,10);
					setcolor(GREEN);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
					settextjustify(LEFT_TEXT,TOP_TEXT);
					puthz(167,90,P[j].name,16,16,GREEN);
					//puts(P[j].telephone);
					outtextxy(167,108,P[j].telephone);
					outtextxy(90,150,P[j].ID);
					/*if(P[j].patient==1)
					{
						puthz(167,174,"��֢״",16,16,BLACK);
					}
					else if(P[j].patient==2);
					{
						puthz(167,174,"��֢״",16,16,BLACK);
					}	*/
					outtextxy(138,192,P[j].age);
					puthz(137,174,P[j].sex,16,16,GREEN);
					outtextxy(290,188,count);
				}
				if(i==2)
				{
					itoa(P[j].count,count,10);
					setcolor(GREEN);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
					settextjustify(LEFT_TEXT,TOP_TEXT);
					puthz(167+240,90,P[j].name,16,16,GREEN);
					//puts(P[j].telephone);
					outtextxy(167+240,108,P[j].telephone);
					outtextxy(90+240,150,P[j].ID);
					/*if(P[j].patient==1)
					{
						puthz(167+240,174,"��֢״",16,16,BLACK);
					}
					else 
					{
						puthz(167+240,174,"��֢״",16,16,BLACK);
					}*/
					outtextxy(138+240,192,P[j].age);
					puthz(137+240,174,P[j].sex,16,16,GREEN);
					outtextxy(290+240,188,count);
				}
				if(i==3)
				{
					itoa(P[j].count,count,10);
					setcolor(GREEN);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
					settextjustify(LEFT_TEXT,TOP_TEXT);
					puthz(167,90+160,P[j].name,16,16,GREEN);
					outtextxy(167,108+160,P[j].telephone);
					outtextxy(90,150+160,P[j].ID);
					//puts(P[j].telephone);
					/*if(P[j].patient==1)
					{
						puthz(167,174+160,"��֢״",16,16,GREEN);
					}
					else 
					{
						puthz(167,174+160,"��֢״",16,16,GREEN);
					}*/
					outtextxy(138,192+160,P[j].age);
					puthz(137,174+160,P[j].sex,16,16,GREEN);
					outtextxy(290,188+160,count);
				}
				if(i==4)
				{
					itoa(P[j].count,count,10);
					setcolor(GREEN);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
					settextjustify(LEFT_TEXT,TOP_TEXT);
					puthz(167+240,90+160,P[j].name,16,16,GREEN);
					outtextxy(167+240,108+160,P[j].telephone);
					outtextxy(90+240,150+160,P[j].ID);
					/*if(P[j].patient==1)
					{
						puthz(167+240,174+160,"��֢״",16,16,GREEN);
					}
					else 
					{
						puthz(167+240,174+160,"��֢״",16,16,GREEN);
					}*/
					outtextxy(138+240,192+160,P[j].age);
					puthz(137+240,174+160,P[j].sex,16,16,GREEN);
					outtextxy(290+240,188+160,count);
				}
			}
		}
		if(i>4)
		{
			break;
		}
	}
}