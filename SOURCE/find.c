#include "public.h"
#include "find.h"
#include "check.h"
#include "connect.h"
/*
FUNCTION:Find
DESCRIPTION:����ί����Ա�������нӴ���׷��
INPUT:�洢ȷ�ﻼ�߳˳���¼�Ľṹ��r
RETURN:��
*/
void Find(RECORD* r)
{
	int flag=0; //��ǵ������
	int all=0; //��¼һ���г˿�
	int func=0; //��¼һ���ж���ҳ
	int now=1; //��ǵ�ǰҳ��
	int i=0; //for��丨������
	int j=0;
	int k=0;
	char f[3]={"\0"}; //��ҳ��
	char n[3]={"\0"}; //��ǰҳ��
	int a[20]={0}; //�洢�ܽӳ˿ͳ˳���¼����
	RECORD C[20]; //�洢�ܽӳ˿���Ϣ�Ľṹ������
	char ID1[20]={"0"}; //�洢��ǰҳ������ʾ��4�γ˿����֤��
	char ID2[20]={"0"};
	char ID3[20]={"0"};
	char ID4[20]={"0"};
	
	//printf("%d,%d,%d,%d,%d",a[1],a[2],a[3],a[4],a[5]);getchar();
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Find(); //���ƽ���
	
	for(i=0;i<20;i++)
	{
		C[i].contact=0;
		C[i].number=0;
		//C[i].count=0;
		strcpy(C[i].ID,"0");
	}
	/*for(i=0;i<20;i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");
	getchar();*/
	j=0;
	k=0;
	all=Find_Search(r,a); //printf("%d\n",all);//��ȡ�ôγ˳���¼�����нӴ���
	/*for(i=0;i<10;i++)
	{
		printf("%d,",a[i]);
	}
	getchar();*/
	Find_Tag(a); //����й����нӴ��ĳ˳���¼
	Find_Get(a,C); //��ȡ���нӴ�����Ϣ
	delay(400);//printf("%d\n",C[0].contact);
	if(C[0].contact==0) //���û�л�ȡ�κ����нӴ�����Ϣ�����������ʾ���˳�
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"������Ϣ",24,24,RED);
		delay(3000);
		return;
	}
	//printf("%d,%d,%d,%d,%d",a[1],a[2],a[3],a[4],a[5]);getchar();
	//Draw_Find();
	func=(all-1)/4+1; //������ҳ��
	itoa(func,f,10); //��ʾҳ��
	setcolor(BLACK);
	outtextxy(328,434,f);
	outtextxy(305,434,"1");
	Find_Show(C,now,ID1,ID2,ID3,ID4); //��ʾ���нӴ�����Ϣ
	
	//getchar();
	while(1)
	{//getchar();
		newmouse(&MouseX,&MouseY,&press);//getchar();
		//printf("%d",10);
		/*if(MouseX>260&&MouseX<305&& MouseY>212&& MouseY<235&&strcmp(ID1,"0")!=0) //׷�ٿ�1
		{
			if(mouse_press(260,212,305,235)==2)               
			{
				MouseS=1;				
				if(flag==0)
				{
					clrmous(MouseX,MouseY); 
					Find_Lighten(1);
					flag=1;
				}
				continue;
			}
			else if(mouse_press(260,212,305,235)==1)        
			{
				MouseS=0;    
				Find_Lighten(1);
				puts(ID1);getchar();
				Patient_Check(ID1); //��ʾ��ǰ�˿͵ĳ˳���¼
				clrmous(MouseX,MouseY); //������ʾ���нӴ�����Ϣ
	            delay(100);
	            save_bk_mou(MouseX,MouseY);
	            cleardevice();
				Draw_Find();
				Find_Show(C,now,ID1,ID2,ID3,ID4);
				itoa(now,n,10);
				outtextxy(328,434,f);
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
		if(MouseX>260+240&&MouseX<305+240&& MouseY>212&& MouseY<235&&strcmp(ID2,"0")!=0) //׷�ٿ�2
		{
			if(mouse_press(260+240,212,305+240,235)==2)               
			{
				MouseS=1;				
				if(flag==0)
				{
					Find_Lighten(2);
					flag=2;
				}
				continue;
			}
			else if(mouse_press(260+240,212,305+240,235)==1)        
			{
				MouseS=0;    
				Find_Lighten(2);
				Patient_Check(ID2); //��ʾ��ǰ�˿͵ĳ˳���¼
				clrmous(MouseX,MouseY); //������ʾ���нӴ�����Ϣ
	            delay(100);
	            save_bk_mou(MouseX,MouseY);
	            cleardevice();
				Draw_Find();
				Find_Show(C,now,ID1,ID2,ID3,ID4);
				itoa(now,n,10);
				outtextxy(328,434,f);
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
		if(MouseX>260&&MouseX<305&& MouseY>212+160&& MouseY<235+160&&strcmp(ID3,"0")!=0) //׷�ٿ�3
		{
			if(mouse_press(260,212+160,305,235+160)==2)               
			{
				MouseS=1;				
				if(flag==0)
				{
					Find_Lighten(3);
					flag=3;
				}
				continue;
			}
			else if(mouse_press(260,212+160,305,235+160)==1)        
			{
				MouseS=0;    
				Find_Lighten(3);
				Patient_Check(ID3); //��ʾ��ǰ�˿͵ĳ˳���¼
				clrmous(MouseX,MouseY); //������ʾ���нӴ�����Ϣ
	            delay(100);
	            save_bk_mou(MouseX,MouseY);
	            cleardevice();
				Draw_Find();
				Find_Show(C,now,ID1,ID2,ID3,ID4);
				itoa(now,n,10);
				outtextxy(328,434,f);
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
		if(MouseX>260+240&&MouseX<305+240&& MouseY>212+160&& MouseY<235+160&&strcmp(ID4,"0")!=0) //׷�ٿ�4
		{
			if(mouse_press(260+240,212+160,305+240,235+160)==2)               
			{
				MouseS=1;				
				if(flag==0)
				{
					Find_Lighten(4);
					flag=4;
				}
				continue;
			}
			else if(mouse_press(260+240,212+160,305+240,235+160)==1)        
			{
				MouseS=0;    
				Find_Lighten(4);
				Patient_Check(ID4); //��ʾ��ǰ�˿͵ĳ˳���¼
				clrmous(MouseX,MouseY); //������ʾ���нӴ�����Ϣ
	            delay(100);
	            save_bk_mou(MouseX,MouseY);
	            cleardevice();
				Draw_Find();
				Find_Show(C,now,ID1,ID2,ID3,ID4);
				itoa(now,n,10);
				outtextxy(328,434,f);
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
		*/
		if(MouseX>220&&MouseX<260&& MouseY>437&& MouseY<457)//��һҳ��
		{
			if(mouse_press(220,437,260,457)==2)               
			{
				MouseS=1;				
				if(flag==0)
				{
					clrmous(MouseX,MouseY); 
					Find_Lighten(5);
					flag=5;
				}
				continue;
			}
			else if(mouse_press(220,437,260,457)==1)        
			{
				MouseS=0;    
				clrmous(MouseX,MouseY); 
				Find_Lighten(5);
				if(now==1) //�����ǰ�ڵ�һҳ
				{
					setfillstyle(1,WHITE);
					puthz(272,408,"���޸���",24,24,RED);
					delay(3000);
					bar(272,408,368,432);
				}
				else
				{
					strcpy(ID1,"0");
					strcpy(ID2,"0");
				    strcpy(ID3,"0");
					strcpy(ID4,"0");
					now--; //��ǰҳ-1
					itoa(now,n,10); //��õ�ǰҳ��
					Find_Cover(); //�ڸ���һҳ��
					Find_Show(C,now,ID1,ID2,ID3,ID4);
					if(strlen(n)==2) //��ʾ��ǰҳ��
					{
						outtextxy(290,434,n);
					}
					else
					{
						outtextxy(305,434,n);
					}
				}
				delay(100);
			}
			continue;
	    }
		if(MouseX>380&&MouseX<437&& MouseY>420&& MouseY<457)//��һҳ��
		{
			if(mouse_press(380,437,420,457)==2)               
			{
				MouseS=1;				
				if(flag==0)
				{
					clrmous(MouseX,MouseY); 
					Find_Lighten(6);
					flag=6;
				}
				continue;
			}
			else if(mouse_press(380,437,420,457)==1)        
			{
				MouseS=0;    
				clrmous(MouseX,MouseY); 
				Find_Lighten(6);
				if(now==func)
				{
					setfillstyle(1,WHITE);
					puthz(272,408,"���޸���",24,24,RED);
					delay(3000);
					bar(272,408,368,432);
				}
				else
				{
					strcpy(ID1,"0");
					strcpy(ID2,"0");
				    strcpy(ID3,"0");
					strcpy(ID4,"0");
					now++;
					itoa(now,n,10);
					Find_Cover();
					Find_Show(C,now,ID1,ID2,ID3,ID4);
					if(strlen(n)==2)
					{
						outtextxy(290,434,n);
					}
					else
					{
						outtextxy(305,434,n);
					}
				}
				delay(100);
			}
			continue;
	    }
		if(MouseX>480&&MouseX<585&& MouseY>437&& MouseY<457) //����˳�
		{
			if(mouse_press(480,437,585,457)==2)               
			{
				MouseS=1;				
				continue;
			}
			else if(mouse_press(480,437,585,457)==1)        
			{
				MouseS=0;    
				return;
			}
	    }
		if(flag!=0)
		{
			MouseS=0;
            if(flag==1)
			{
               clrmous(MouseX,MouseY); 
			   Find_Darken(1);
			}
			if(flag==2)
			{
               clrmous(MouseX,MouseY); 
			   Find_Darken(2);
			}
			if(flag==3)
			{
               clrmous(MouseX,MouseY); 
			   Find_Darken(3);
			}
			if(flag==4)
			{
               clrmous(MouseX,MouseY); 
			   Find_Darken(4);
			}
			if(flag==5)
			{
               clrmous(MouseX,MouseY); 
			   Find_Darken(5);
			}
			if(flag==6)
			{
               clrmous(MouseX,MouseY); 
			   Find_Darken(6);
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
FUNCTION:Draw_Find
DESCRIPTION:�������нӴ���׷�ٽ���
INPUT:��
RETURN:��
*/
int Draw_Find()
{
	cleardevice();
	cover(0, 0, 639, 479, WHITE);
	highlight(0, 0, 639, 479, GREEN);
	cover(118, 10, 118 + 405, 10 + 32, BLUE);
	highlight(118, 10, 118 + 405, 10 + 32, LIGHTGREEN);
	puthz(193, 14, "���������ܽӳ˿�׷��", 24, 24 + 2, WHITE);
	//search_choose_words_bk(242, 53, 9, LIGHTGRAY, LIGHTCYAN);
	//puthz(243,54,"����Ϊ�ܽӳ˿���Ϣ",16,17,RED);
	
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
	//draw_refresh(60,440, WHITE, RED, GREEN, GREEN);
	
	setcolor(GREEN);
	puthz(90,90,"�˿�����",16,16,BLUE);
	outtextxy(160,82,":");
	puthz(90,113,"�绰����",16,16,BLUE);
	outtextxy(160,105,":");
	puthz(90,136,"���֤��",16,16,BLUE);
	outtextxy(160,128,":");
	//puthz(90,174,"ͬ�˳���",16,16,BLUE);
	//outtextxy(160,166,":");
	puthz(90,197,"����",16,16,BLUE);
	outtextxy(130,189,":");
	puthz(90,174,"�Ա�",16,16,BLUE);
	outtextxy(130,166,":");
	puthz(235,193,"���",16,16,BLUE);
	outtextxy(275,185,":");
	//cover(260,212,305,235,BLUE);
	//highlight(260,212,305,235,CYAN);
	//puthz(266,217,"׷��",16,19,WHITE);
	
	setcolor(BLUE);
	puthz(90+240,90,"�˿�����",16,16,BLUE);
	outtextxy(160+240,82,":");
	puthz(90+240,113,"�绰����",16,16,BLUE);
	outtextxy(160+240,105,":");
	puthz(90+240,136,"���֤��",16,16,BLUE);
	outtextxy(160+240,128,":");
	//puthz(90+240,174,"ͬ�˳���",16,16,BLUE);
	//outtextxy(160+240,166,":");
	puthz(90+240,197,"����",16,16,BLUE);
	outtextxy(130+240,189,":");
	puthz(90+240,174,"�Ա�",16,16,BLUE);
	outtextxy(130+240,166,":");
	puthz(235+240,193,"���",16,16,BLUE);
	outtextxy(275+240,185,":");
	//cover(260+240,212,305+240,235,BLUE);
	//highlight(260+240,212,305+240,235,CYAN);
	//puthz(266+240,217,"׷��",16,19,WHITE);
	
	setcolor(BLUE);
	puthz(90,90+160,"�˿�����",16,16,BLUE);
	outtextxy(160,82+160,":");
	puthz(90,113+160,"�绰����",16,16,BLUE);
	outtextxy(160,105+160,":");
	puthz(90,136+160,"���֤��",16,16,BLUE);
	outtextxy(160,128+160,":");
	//puthz(90,174+160,"ͬ�˳���",16,16,BLUE);
	//outtextxy(160,166+160,":");
	puthz(90,197+160,"����",16,16,BLUE);
	outtextxy(130,189+160,":");
	puthz(90,174+160,"�Ա�",16,16,BLUE);
	outtextxy(130,166+160,":");
	puthz(235,193+160,"���",16,16,BLUE);
	outtextxy(275,185+160,":");
	//cover(260,212+160,305,235+160,BLUE);
	//highlight(260,212+160,305,235+160,CYAN);
	//puthz(266,217+160,"׷��",16,19,WHITE);
	
	setcolor(BLUE);
	puthz(90+240,90+160,"�˿�����",16,16,BLUE);
	outtextxy(160+240,82+160,":");
	puthz(90+240,113+160,"�绰����",16,16,BLUE);
	outtextxy(160+240,105+160,":");
	puthz(90+240,136+160,"���֤��",16,16,BLUE);
	outtextxy(160+240,128+160,":");
	//puthz(90+240,174+160,"ͬ�˳���",16,16,BLUE);
	//outtextxy(160+240,166+160,":");
	puthz(90+240,197+160,"����",16,16,BLUE);
	outtextxy(130+240,189+160,":");
	puthz(90+240,174+160,"�Ա�",16,16,BLUE);
	outtextxy(130+240,166+160,":");
	puthz(235+240,193+160,"���",16,16,BLUE);
	outtextxy(275+240,185+160,":");
	//cover(260+240,212+160,305+240,235+160,BLUE);
	//highlight(260+240,212+160,305+240,235+160,CYAN);
	//puthz(266+240,217+160,"׷��",16,19,WHITE);
}
/*
FUNCTION:Find_Cover
DESCRIPTION:�ڸ���һҳ����ʾ��ȷ�ﻼ����Ϣ
INPUT:��
RETURN:��
*/
int Find_Cover()
{
	setfillstyle(1,WHITE);
	bar(290,440,316,455); //�ڵ�ǰҳ��
	bar(167,90,215,106); //������
	bar(167,108,295,132); //�ڵ绰
	bar(90,154,305,174); //�����֤��
	bar(167,174,215,190); //��֢״����
	bar(138,192,158,216); //������
	bar(137,174,159,236); //���Ա�
	bar(290,188,310,210); //�����
	
	bar(167+240,90,215+240,106); //������
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
FUNCTION:Find_Lighten
DESCRIPTION:����
INPUT:flag
RETURN:NO
*/
int Find_Lighten(int flag)
{
	switch(flag)
	{
		/*case 1:
		    cover(260,212,305,235,LIGHTBLUE);
	        highlight(260,212,305,235,CYAN);
	        puthz(266,217,"׷��",16,19,WHITE);
			break;
		case 2:
		    cover(260+240,212,305+240,235,LIGHTBLUE);
	        highlight(260+240,212,305+240,235,CYAN);
	        puthz(266+240,217,"׷��",16,19,WHITE);
			break;
		case 3:
		    cover(260,212+160,305,235+160,LIGHTBLUE);
	        highlight(260,212+160,305,235+160,CYAN);
	        puthz(266,217+160,"׷��",16,19,WHITE);
			break;
		case 4:
		    cover(260+240,212+160,305+240,235+160,LIGHTBLUE);
	        highlight(260+240,212+160,305+240,235+160,CYAN);
	        puthz(266+240,217+160,"׷��",16,19,WHITE);
			break;*/
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
FUNCTION:Find_Darken
DESCRIPTION:�ָ�
INPUT:flag
RETURN:NO
*/
int Find_Darken(int flag)
{
	switch(flag)
	{
		/*case 1:
		    cover(260,212,305,235,BLUE);
	        highlight(260,212,305,235,CYAN);
	        puthz(266,217,"׷��",16,19,WHITE);
			break;
		case 2:
		    cover(260+240,212,305+240,235,BLUE);
	        highlight(260+240,212,305+240,235,CYAN);
	        puthz(266+240,217,"׷��",16,19,WHITE);
			break;
		case 3:
		    cover(260,212+160,305,235+160,BLUE);
	        highlight(260,212+160,305,235+160,CYAN);
	        puthz(266,217+160,"׷��",16,19,WHITE);
			break;
		case 4:
		    cover(260+240,212+160,305+240,235+160,BLUE);
	        highlight(260+240,212+160,305+240,235+160,CYAN);
	        puthz(266+240,217+160,"׷��",16,19,WHITE);
			break;*/
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
FUNCTION:Find_Search
DESCRIPTION:��ȡ���нӴ��߳˳���¼������Ϣ
INPUT:���߳˳���¼�ṹ��ָ��r���洢�ܽӽӴ��߳˳���¼���ŵ�����a
RETURN:amount
*/
int Find_Search(struct Record* r,int* a)
{
	FILE* fp;
	int amount=0;
	int i=0;
	RECORD* re; //��ʱ�洢�˳���¼
	
	if ((fp = fopen("C:\\TRY\\TEXT\\record.dat", "rb+")) == NULL) //���ļ�
	{
		printf("\nError on open record.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_SET);
	while(!feof(fp))
	{
		if((re=(RECORD*)malloc(sizeof(RECORD)))==NULL) //����ռ�             
	    {
		    printf("\nMemory not enough!");
            delay(3000);
			exit(1);
	    } 
		fscanf(fp,"%d",&re->contact); //��һ�γ˳���¼
		if(re->contact==-1)
		{
			break;
		}
		fgetc(fp);
		fscanf(fp,"%d",&re->number);
		fgetc(fp);
		fscanf(fp,"%s",re->name);
		fgetc(fp);
		fgets(re->telephone,12,fp);
		fgetc(fp);
		fgets(re->ID,19,fp);
		fgetc(fp);
		fgets(re->age,3,fp);
		fgetc(fp);
		fgets(re->sex,3,fp);
		fgetc(fp);
		fscanf(fp,"%d",&re->week);
		fgetc(fp);
		fscanf(fp,"%d",&re->subway_number[0]);
		fgetc(fp);
		fscanf(fp,"%d",&re->subway_number[1]);
		fgetc(fp);
		fscanf(fp,"%d",&re->subway_number[2]);
		fgetc(fp);
		fscanf(fp,"%d",&re->origin);
		fgetc(fp);
		fscanf(fp,"%d",&re->transfer);
		fgetc(fp);
		fscanf(fp,"%d",&re->terminal);
		if(r->contact==re->contact)
		{
			continue;
		}
		if(r->week==re->week)
		{
			if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //һ������
			{
				if((re->origin>=1&&re->origin<=6||re->terminal>=1&&re->terminal<=6)&&(re->origin>=7&&re->origin<=12||re->terminal>=7&&re->terminal<=12)&&(r->subway_number[0]==re->subway_number[0]||r->subway_number[1]==re->subway_number[1])) //һ������
				{
					amount++;
					a[i]=re->contact;
					i++;
				}
			}
			else if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)) //һ������
			{
				if((re->origin>=1&&re->origin<=6||re->terminal>=1&&re->terminal<=6)&&(re->origin>=13&&re->origin<=18||re->terminal>=13&&re->terminal<=18)&&(r->subway_number[0]==re->subway_number[0]||r->subway_number[2]==re->subway_number[2])) //һ������
				{
					amount++;
					a[i]=re->contact;
					i++;
				}
			}
			else if((r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)) //��������
			{
				if((re->origin>=7&&re->origin<=12||re->terminal>=7&&re->terminal<=12)&&(re->origin>=13&&re->origin<=18||re->terminal>=13&&re->terminal<=18)&&(r->subway_number[2]==re->subway_number[2]||r->subway_number[1]==re->subway_number[1])) //һ������
				{
					amount++;
					a[i]=re->contact;
					i++;
				}
			}
			else if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)) //һ����
			{
				if((r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->origin>=1&&r->origin<=6||r->terminal>=1&&r->terminal<=6)&&(r->subway_number[0]==re->subway_number[0])) //һ����
				{
					amount++;
					a[i]=re->contact;
					i++;
				}
			}
			else if((r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)) //������
			{
				if((r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)&&(r->origin>=7&&r->origin<=12||r->terminal>=7&&r->terminal<=12)&&(r->subway_number[1]==re->subway_number[1])) //������
				{
					amount++;
					a[i]=re->contact;
					i++;
				}
			}
			else if((r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)) //3����
			{
				if((r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)&&(r->origin>=13&&r->origin<=18||r->terminal>=13&&r->terminal<=18)&&(r->subway_number[2]==re->subway_number[2]))//3����
				{
					amount++;
					a[i]=re->contact;
					i++;
				}
			}
		}
		if(amount>=20)
		{
			break;
		}
        if(re!=NULL)
		{
			free(re);
			re=NULL;
	    }
	}	
	if(re!=NULL)
	{
		free(re);
		re=NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close record.dat!");
		delay(3000);
		exit(1);
	}
	/*printf("%d\n",i);
	getchar();*/
	return amount;
}
/*
FUNCTION:Find_Tag
DESCRIPTION:������нӴ��߳˳���¼,����a����state.dat
INPUT:�洢�ܽӽӴ��߳˳���¼���ŵ�����a
RETURN:��
*/
int Find_Tag(int* a) //��Ǳ��ܽӵĳ˳���¼
{
	long unsigned int b;
	long unsigned int l;
	long unsigned int i;
	int flag=0; //��¼�˿����
	FILE* fp;
	STATE* s=NULL;
	if ((fp=fopen("C:\\TRY\\TEXT\\state.dat","rb+"))==NULL)
	{
		printf("\nError on open file state.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);      // printf("%d,%ld",sizeof(STATE),ftell(fp)); getchar();                                     //�ļ�ָ�붨λ�����һλ
	//b=ftell(fp); printf("%d",b); 
	l=ftell(fp)/sizeof(STATE); // printf("%ld",l); getchar();
	for(i=0;i<l;i++)
	{
		if(*a==0)
		{
			break;
		}
		if((s=(STATE*)malloc(sizeof(STATE)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
		    exit(1);
		}
		fseek(fp,i*sizeof(STATE),SEEK_SET);                           
		fread(s,sizeof(STATE),1,fp);             
		if(*a==s->number) //���ļ��в�ѯ����Ӧ�˿�                                  
		{
	        a++;
			s->contact=1;
			fseek(fp,i*sizeof(STATE),SEEK_SET); //����Ϣд���ļ�                      
			fwrite(s,sizeof(STATE),1,fp);     				
		}
		if(s!=NULL)                                              //�ͷ��ڴ�
		{
			free(s);
			s=NULL;
		}
	}
	if(s!=NULL)                                              //�ͷ��ڴ�
	{
		free(s);
		s=NULL;
	}
	if(fclose(fp)!=0)
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
}
/*
FUNCTION:Find_Get
DESCRIPTION:��ȡ���нӴ��߳˳���¼��Ϣ
INPUT:�洢�ܽӽӴ��߳˳���¼���ŵ�����a���洢���нӴ��߳˳���¼��Ϣ�Ľṹ������C
RETURN:��
*/
int Find_Get(int* a,struct Record* C)
{
	int flag; //��¼��ǰ��ȡ���˶���Ϊ���нӴ���
	FILE* fp;
	RECORD* re; //��ʱ�洢�˳���¼
	flag=0;
	
	if ((fp = fopen("C:\\TRY\\TEXT\\record.dat", "rb+")) == NULL) //���ļ�
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
		if((re=(RECORD*)malloc(sizeof(RECORD)))==NULL) //����ռ�             
	    {
		    printf("\nMemory not enough!");
            delay(3000);
			exit(1);
	    } 
		fscanf(fp,"%d",&re->contact); //��һ�γ˳���¼
		if(re->contact==-1)
		{
			break;
		}
		fgetc(fp);
		fscanf(fp,"%d",&re->number);
		fgetc(fp);
		fscanf(fp,"%s",re->name);
		fgetc(fp);
		fgets(re->telephone,12,fp);
		fgetc(fp);
		fgets(re->ID,19,fp);
		fgetc(fp);
		fgets(re->age,3,fp);
		fgetc(fp);
		fgets(re->sex,3,fp);
		fgetc(fp);
		fscanf(fp,"%d",&re->week);
		fgetc(fp);
		fscanf(fp,"%d",&re->subway_number[0]);
		fgetc(fp);
		fscanf(fp,"%d",&re->subway_number[1]);
		fgetc(fp);
		fscanf(fp,"%d",&re->subway_number[2]);
		fgetc(fp);
		fscanf(fp,"%d",&re->origin);
		fgetc(fp);
		fscanf(fp,"%d",&re->transfer);
		fgetc(fp);
		fscanf(fp,"%d",&re->terminal);
		if(*a==re->contact) //�統ǰ�����ĳ˳���¼Ϊȷ�ﻼ�ߵ�
		{
			flag++;
			a++;
			C->contact=flag;	//���ɵ�flag���ܽӼ�¼
			C->number=re->number;
			//C->count=flag;
			strcpy(C->name,re->name);
			strcpy(C->telephone,re->telephone);
			strcpy(C->ID,re->ID);
			strcpy(C->sex,re->sex);
			strcpy(C->age,re->age);
			C->origin=re->origin;
			C->transfer=re->transfer;
			C->terminal=re->terminal;
			C->week=re->week;
			C->subway_number[0]=re->subway_number[0];
			C->subway_number[1]=re->subway_number[1];
			C->subway_number[2]=re->subway_number[2];
			C++;
		}
		if(re!=NULL)
		{
			free(re);
			re=NULL;
	    }
	}
	if(re!=NULL)
	{
		free(re);
		re=NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close p_record.dat!");
		delay(3000);
		exit(1);
	}
}
/*
FUNCTION:Find_Show
DESCRIPTION:��ʾ���нӴ��߳˳���¼��Ϣ
INPUT:�洢���нӴ��߳˳���¼�Ľṹ������C����ǰҳ��now,��ǰҳ���������֤��ID1��ID2��ID3��ID4
RETURN:��
*/
int Find_Show(struct Record* C,int now,char* ID1,char* ID2,char* ID3,char* ID4)
{
	int i;
	int j;
	j=0;
	for(i=0;i<20;i++)
	{
		if(C[i].contact>4*(now-1)&&C[i].contact<=4*now) //ȷ��˿�����ڵ�ǰҳ
		{
			j++; // ��¼��ǰ�˿�����λ��
			if(j==1)
			{
				strcpy(ID1,C[i].ID);
			}
			if(j==2)
			{
				strcpy(ID2,C[i].ID);
			}
			if(j==3)
			{
				strcpy(ID3,C[i].ID);
			}
			if(j==4)
			{
				strcpy(ID4,C[i].ID);
			}
			Find_Display(C[i],j); //�ڶ�Ӧλ����ʾ�ó˿���Ϣ
		}
		if(j>=4)
		{
			break;
		}
	}
}

/*
FUNCTION:Find_Display
DESCRIPTION:��ʾ���нӴ��߳˳���¼��Ϣ
INPUT:�洢���нӴ��߳˳���¼�Ľṹ��C����ǰ���нӴ��߳˳���¼��ʾλ��
RETURN:��
*/
int Find_Display(struct Record c,int i)
{
	char count[4];
	setcolor(BLACK);
	if(i==1)
	{
		itoa(c.contact,count,10);
		setcolor(BLACK);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
	    puthz(167,90,c.name,16,16,BLACK);
	    outtextxy(167,108,c.telephone);
	    outtextxy(90,150,c.ID);
		//outtextxy(167,170,c.train_number);
	    outtextxy(138,192,c.age);
	    puthz(137,174,c.sex,16,16,BLACK);
	    outtextxy(290,188,count);
	}
	if(i==2)
	{
		itoa(c.contact,count,10);
		setcolor(BLACK);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
	    puthz(167+240,90,c.name,16,16,BLACK);
	    outtextxy(167+240,108,c.telephone);
	    outtextxy(90+240,150,c.ID);
		//outtextxy(167+240,170,c.train_number);
	    outtextxy(138+240,192,c.age);
	    puthz(137+240,174,c.sex,16,16,BLACK);
	    outtextxy(290+240,188,count);
	}
	if(i==3)
	{
		itoa(c.contact,count,10);
		setcolor(BLACK);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
	    puthz(167,90+160,c.name,16,16,BLACK);
	    outtextxy(167,108+160,c.telephone);
	    outtextxy(90,150+160,c.ID);
		//outtextxy(167,170+160,c.train_number);
	    outtextxy(138,192+160,c.age);
	    puthz(137,174+160,c.sex,16,16,BLACK);
	    outtextxy(290,188+160,count);
	}
	if(i==4)
	{
		itoa(c.contact,count,10);
		setcolor(BLACK);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
	    settextjustify(LEFT_TEXT,TOP_TEXT);
	    puthz(167+240,90+160,c.name,16,16,BLACK);
	    outtextxy(167+240,108+160,c.telephone);
	    outtextxy(90+240,150+160,c.ID);
		//outtextxy(167+240,170+160,c.train_number);
	    outtextxy(138+240,192+160,c.age);
	    puthz(137+240,174+160,c.sex,16,16,BLACK);
	    outtextxy(290+240,188+160,count);
	}
}

