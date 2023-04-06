#include"public.h"
#include"sign.h"
/*
FUNCTION:Sign
DESCRIPTION:ʵ�ֱ����ȡ����ǹ���
INPUT:page
OUTPUT:NO
*/
void Sign(int *page)
{
	int flag=0;		//�������
	int pos1=0;		//���֤�������
	int pos2=0;		//���ȷ�ﻼ��
	int pos3=0;		//ȡ�����߱��
	int jun=0; //�ж����֤��ʽ
	char I[25]; //�洢��������֤��
	int n; //��¼�˿ʹ���
	int patient; //��¼�˿�ȷ�����
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	
	Draw_Sign();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>220&&MouseX<595&&MouseY>188&&MouseY<213);		//�����֤
		{
			if(mouse_press(220,188,595,213)==2)
			{
				MouseS=2;
				if(pos1==0&&flag==0)
				{
					clrmous(MouseX,MouseY);
					Sign_Lighten(1);		//����
					flag=1;
				}
				continue;
			}
			if(mouse_press(220,188,595,213)==1)
			{
				MouseS=0;
				I[0]='\0';
				setfillstyle(1,WHITE);
				bar(530,217,600,235);
				Input_Vis(I,220,188,18,LIGHTGRAY);		//���ӻ�����
				jun=Sign_ID_Judge(I);
				if(strlen(I)!=0)		//�ж��Ƿ��������
				{
					pos1=1;			//���
				}
				else
				{
					pos1=0;
				}
				continue;
			}
				
		}
		if(MouseX>290&&MouseX<290+105&&MouseY>289&&MouseY<308)		//���ȷ�ﻼ��
		{
			if (mouse_press(290,289,290+105,308)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(290,289,290+105,308)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Sign_Lighten(2);
				Sign_Darken(3);
				pos2=1;
				pos3=0;
				delay(200);
			}
		}
		if(MouseX>(388+90)&&MouseX<(388+90+105)&&MouseY>289&&MouseY<308)		//ȡ�����ȷ�ﻼ��
		{
			if (mouse_press(388+90,289,388+90+105,308)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(388+90,289,388+90+105,308)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Sign_Lighten(3);
				Sign_Darken(2);
				pos2=0;
				pos3=1;
				delay(200);
			}
		}
		if(MouseX>172.5&&MouseX<(182.5+294-4)&&MouseY>386.5&&MouseY<386.5+37)		//�ύ����
		{
			if (mouse_press(172.5,386.5,182.5+294-4,386.5+37)==2)
			{
				MouseS=1;
				if(flag==0)
				{
					clrmous(MouseX,MouseY);
					Sign_Lighten(4);
					flag=4;
				}
				continue;
			}
			else if(mouse_press(172.5,386.5,182.5+294-4,386.5+37)==1)
			{
				MouseS=0;
				Sign_Lighten(4);
				 if(pos1==1&&(pos2==1||pos3==1)&&jun==1) //�������д���ݲ��Ҹ�ʽ��ȷ
                {
					setlinestyle(SOLID_LINE,0,NORM_WIDTH); //������ʾ
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, DARKGRAY);
		            puthz(274,220,"�����ύ",24,24,RED);
					stablack(282,270,3);
					stablack(282,270,3);
					delay(500);
					stablack(320,270,3);
					delay(500);
					stablack(358,270,3);
					delay(500);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, DARKGRAY);
		            puthz(274,230,"�ύ�ɹ�",24,24,RED);
		            delay(1000);
					MouseS=0;
			    	Sign2(page,I,pos2); //���뻼�����֤�ţ�ȷ�����������Ա��������
					break;
				}
				else
				{
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, DARKGRAY);
		            puthz(274,220,"�����ύ",24,24,RED);
					stablack(282,270,3);
					stablack(282,270,3);
					delay(500);
					stablack(320,270,3);
					delay(500);
					stablack(358,270,3);
					delay(500);
					setlinestyle(SOLID_LINE,0,NORM_WIDTH);
                    setfillstyle(SOLID_FILL, DARKGRAY);
                    bar(200,180,440,300);
                    rectangle(200,180,440,300);
                    setfillstyle(SOLID_FILL, DARKGRAY);
		            puthz(274,230,"�ύʧ��",24,24,RED);
		            delay(1000);
					return;
				}
				continue;
			}
		}
		if(MouseX>474+5&&MouseX<579+5&&MouseY>362+75&&MouseY<382+75) //����
		{
			if(mouse_press(474+5,362+75,579+5,382+75)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(474+5,362+75,579+5,382+75)==1)
			{
				MouseS=0;
				cleardevice();
				flag=0;
				pos1=0;
				pos2=0;
				pos3=0;
				I[0]='\0';
				Draw_Sign();
				delay(100);
				continue;
			}
		}
		if(MouseX>55&&MouseX<160&&MouseY>437&&MouseY<457) //�˳�
		{
			if(mouse_press(55,437,160,457)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(55,437,160,457)==1)
			{
				MouseS=0;
				*page=7; //�����������Ž���
				break;
			}
		}
		if(flag!=0)		//��ԭҳ��
		{
			if(flag==1&&pos1==0)
			{
				clrmous(MouseX,MouseY);
				Sign_Darken(1);
			}
			if(flag==4)
			{
				clrmous(MouseX,MouseY);
				Sign_Darken(4);
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
FUNCTION:Draw_Sign
DESCRIPTION:���Ʊ�ǻ��߽���
INPUT:no
RETURN:no
*/
int Draw_Sign()
{
	cleardevice();
	setbkcolor(WHITE);
	cover(118, 10, 118 + 405, 10 + 32,LIGHTGRAY);
	highlight(118, 10, 118 + 405, 10 + 32,GREEN);
	cover(171,116,164+284,120+24,LIGHTGRAY);
	highlight(171,116,164+284,120+24,RED);
	puthz(170,14,"��ӭ�����������ű��ϵͳ",24,24,GREEN);
	puthz(175, 120, "�����������Ϣ�������¹�ȷ������Ϣ", 16, 16, RED);
	puthz(71, 194.75, "���Ի������֤��", 16, 16, RED);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);   
	setfillstyle(1,DARKGRAY);
	bar(220,188,595,213);		//���֤�������
	highlight(220,188,595,213,GREEN);
	puthz(71,290,"��ѡ���������",16,16,RED);
	cover(290,289,290+105,308,GREEN);
	highlight(287,286,290+108,311,RED);
	cover(388+90,289,388+90+105,308,GREEN);	
	highlight(388+90-3,289-3,388+90+105+3,308+3,RED);		//������ť
	puthz(291,290, "���ȷ�ﻼ��", 16, 17, RED);
	puthz(388+91,290, "ȡ�����߱��", 16, 17, RED);
	cover(172.5, 386.5, 182.5 + 294-4, 386.5 + 37, GREEN);	
	highlight(172.5, 386.5, 182.5 + 294-4, 386.5 + 37, RED);		//�ύ���水ť
	puthz(260, 389, "�ύ����", 32, 32 + 2, WHITE);
	draw_exit(60, 440, WHITE, RED, BLUE, CYAN);
	draw_refresh(279+200+5, 440, WHITE, GREEN, CYAN, LIGHTGREEN);
}
/*
FUNCTION:Sign_Lighten
DESCRIPTION:������ť
INPUT:flag
RETURN:NO
*/
int Sign_Lighten(int flag)
{
	clrmous(MouseY,MouseY);
	delay(10);
	switch(flag)
	{
		case 1: //���֤�������
			setlinestyle(SOLID_LINE,0,THICK_WIDTH);
			highlight(220,188,595,213,GREEN);
			setfillstyle(1,LIGHTGRAY);
			bar(220,188,595,213);	
			break;
		case 2: //���ȷ�ﻼ��
			cover(290,289,290+105,308,LIGHTGRAY);
			highlight(287,286,290+108,311,RED);
			puthz(291,290, "���ȷ�ﻼ��", 16, 17, RED);
			break;
		case 3: //ȡ�����߱��
			cover(388+90,289,388+90+105,308,LIGHTGRAY);	
			highlight(388+90-3,289-3,388+90+105+3,308+3,RED);
			puthz(388+91,290, "ȡ�����߱��", 16, 17, RED);
			break;
		case 4: //�ύ���水ť
			cover(172.5, 386.5, 182.5 + 294-4, 386.5 + 37, LIGHTGRAY);		
			puthz(260, 389, "�ύ����", 32, 32 + 2,GREEN);
		/*case 5: //����
		    cover(99,308+30,203,361+30, LIGHTBLUE);
	        highlight(99,308+30,203,361+30, RED);
	        puthz(110+15, 310+13+30, "����", 24, 26, WHITE);
			break;
		case 6: //����
		    cover(432,308+30,536,361+30, LIGHTBLUE);
	        highlight(432,308+30,536,361+30, RED);
	        puthz(461, 310+13+30, "����", 24, 26, WHITE);
			break;*/
	}
}
/*
FUNCTION:Sign_Darken
DESCRIPTION:��ť�ָ�
INPUT:flag
RETURN:NO
*/
int Sign_Darken(int flag)
{
	clrmous(MouseY,MouseY);
	delay(10);
	switch(flag)
	{
		case 1: //���֤�������
			setlinestyle(SOLID_LINE,0,THICK_WIDTH);
			highlight(220,188,595,213,GREEN);
			setfillstyle(1,DARKGRAY);
			bar(220,188,595,213);	
			break;
		case 2: //���ȷ�ﻼ��
			cover(290,289,290+105,308,GREEN);
			highlight(287,286,290+108,311,RED);
			puthz(291,290, "���ȷ�ﻼ��", 16, 17, RED);
			break;
		case 3: //ȡ�����߱��
			cover(388+90,289,388+90+105,308,GREEN);	
			highlight(388+90-3,289-3,388+90+105+3,308+3,RED);
			puthz(388+91,290, "ȡ�����߱��", 16, 17, RED);
			break;
		case 4: //�ύ���水ť
			cover(172.5, 386.5, 182.5 + 294-4, 386.5 + 37, GREEN);		
			puthz(260, 389, "�ύ����", 32, 32 + 2,WHITE);
		/*case 5: //����
		    cover(99,308+30,203,361+30, WHITE);
	        highlight(99,308+30,203,361+30, RED);
	        puthz(110+15, 310+13+30, "����", 24, 26, LIGHTBLUE);
			break;
		case 6: //����
		    cover(432,308+30,536,361+30, WHITE);
	        highlight(432,308+30,536,361+30, RED);
	        puthz(461, 310+13+30, "����", 24, 26, LIGHTBLUE);
			break;*/
	}
}
/*
FUNCTION:Sign_ID_Judge()
DESCRIPTION:�ж����֤��ʽ
INPUT:if
RETURN:1or0
*/
int Sign_ID_Judge(char *I)
{
	int i;
	int flag1=0;//�жϳ���
	int flag2=0;//�ж�����
	int flag3=0;//�ж����һλ
	int len=0;
	len=strlen(I);
	if(len==18)
	{
		flag1=1;
	}
	if(flag1==1)
	{
		for(i=0;i<17;i++)
		{
			if(I[i]>='0'&&I[i]<='9')
			{
				flag2=1;
			}
			else
			{
				flag2=0;
				break;
			}
		}
	}
	if(flag2==1)
	{
		if((I[17]>='0'&&I[17]<='9')||I[17]=='X')
		{
			flag3=1;
		}
	}
	if(flag1=1&&flag2==1&&flag3==1)
	{
		setfillstyle(1,WHITE);
		bar(530,217,600,235);
		puthz(530,218,"��ʽ��ȷ",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,WHITE);
		bar(530,217,600,235);
		puthz(530,218,"��ʽ����",16,16,RED);
		return 0;
	}
}
/*
FUNCTION:Sign2
DESCRIPTION:�������
INPUT:������ת���Ʊ���page���������֤��I������Ա������ʽpos2
RETURN:��
*/
void Sign2(int* page,char* I,int pos2)//�������
{
	int flag=0; //��ǵ������
	int n=0; //��¼�˿ʹ���
	int jun; //�жϲ����Ƿ���Ϲ淶
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Sign2(pos2); //����ѡ��Ĳ������ͻ��ƽ���
	
	Sign_Search(&n,pos2,I); //��ϵͳ�в�ѯ��س˿͵���Ϣ
	jun=Sign_Check_Jundge(n,pos2,page); //�жϲ����Ƿ���Ϲ淶
	//printf("%d",n);
	if(n==0) //δ��ϵͳ�в�ѯ����س˿͵���Ϣ
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"������Ϣ",24,24,RED);
		delay(3000);
		*page=71;
		return;
	}
	if(jun==1) //�ó˿��Ѿ������ȴѡ���˱�ǻ��߲���
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"�Ѿ����",24,24,RED);
		delay(3000);
		*page=71;
		return;
	}
	else if(jun==2) //�ó˿���δ�����ȴѡ����ȡ����ǲ���
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"��δ���",24,24,RED);
		delay(3000);
		*page=71;
		return;
	}
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		MouseS=0;
		if(MouseX>99&&MouseX<203&& MouseY>308+30&& MouseY<361+30) //���ؿ�
		{
			if(mouse_press(99,308+30,203,361+30)==2)               
			{
				MouseS=1;                                   
				if(flag==0)                  
				{
		            //Sign_Lighten(5);
					flag=5;                               
				}
				continue;
			}
			else if(mouse_press(99,308+30,203,361+30)==1)        
			{
				MouseS=0;
				//Sign_Lighten(5);     
				cleardevice();
				*page=71; //���ر��������
				break;
			}
	    }
		if(MouseX>432&&MouseX<536&& MouseY>308+30&& MouseY<361+30)//�����
		{
			if(mouse_press(432,308+30,536,361+30)==2)               
			{
				MouseS=1;                                   
				if(flag==0)                  
				{
		            //Sign_Lighten(6);
					flag=6;                               
				}
				continue;
			}
			else if(mouse_press(432,308+30,536,361+30)==1)        
			{
				setlinestyle(SOLID_LINE,0,NORM_WIDTH); //��ʾ����ɹ�
                setfillstyle(SOLID_FILL, WHITE);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                setfillstyle(SOLID_FILL, WHITE);
		        puthz(274,220,"���ڱ���",24,24,RED);
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
		        puthz(274,230,"����ɹ�",24,24,RED);
		        delay(1500);
				Sign_Check_Save(n,pos2);
				*page=71; //���ر�ǻ���������
				break;
			}
	    }
        if(flag!=0)
		{
			if(flag==5)
			{
				//Sign_Darken(5);
			}
			if(flag==6)
			{
				//Sign_Darken(6);
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
FUNCTION:Draw_Sign2
DESCRIPTION:���Ʊ������
INPUT:pos2
RETURN:��
*/
int Draw_Sign2(int pos2)
{
	int hzcolor = LIGHTBLUE;
	
	cleardevice();
	setbkcolor(DARKGRAY);
	cover(35, 69+20, 35 + 573, 305 + 83+30, LIGHTGRAY);
	highlight(35, 69+20, 35 + 573, 305 + 83+30, RED);
	setfillstyle(1,GREEN);
	bar(150,23,504,63);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(RED);
	rectangle(150,23,504,63);
	if(pos2==1) //���ݲ������͸��費ͬ�Ĳ�����ʾ
	{
		puthz(219,32,"����ȷ�ﻼ��",24,32,WHITE);
	}
	else
	{
		puthz(219,32,"��ȡ�����߱��",24,32,WHITE);
	}
	puthz(91, 89+30, "��������", 16, 17, hzcolor);
	puthz(91, 129+30, "�����Ա�", 16, 17, hzcolor);
	puthz(91, 169+30, "���֤��", 16, 17, hzcolor);
	puthz(91, 209+30, "��ϵ��ʽ", 16, 17, hzcolor);

	setcolor(RED);
	setlinestyle(1, 0, 3);
	line(200, 135, 470, 135);//����
	line(200, 175, 470, 175);//�Ա�
	line(200, 215, 470, 215);//���֤��
	line(200, 255, 470, 255);//��ϵ��ʽ
	
	cover(99,308+30,203,361+30, WHITE);
	highlight(99,308+30,203,361+30, RED);
	puthz(110+15, 310+13+30, "����", 24, 26, hzcolor);
	cover(432.5, 293.13+15+30, 432.5 + 104, 293 + 53+15+30, WHITE);
	highlight(432.5, 293.13+15+30, 432.5 + 104, 293 + 53+15+30, RED);
	puthz(461, 310+13+30, "����", 24, 26, hzcolor);
}
/*
FUNCTION:Sign_Search
DESCRIPTION:��ϵͳ�в���¼��Ļ�����Ϣ
INPUT:n������ID����I���Ƿ���pos2
RETURN:NO
*/
int Sign_Search(int *n,int pos2,char* I)
{
	PASSENGER* p;
	FILE *fp;
	if((fp=fopen("C:\\TRY\\TEXT\\pass.dat","rb+"))==NULL)//�򿪴洢�û���Ϣ���ļ�
	{
		printf("\nError on open file pass.dat!");
		delay(3000);
		exit(1);
	}
	while(!feof(fp))
	{
		if((p=(PASSENGER*)malloc(sizeof(PASSENGER)))==NULL)	//����ռ�
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
		
		if(strcmp(p->ID,I)==0)
		{
			*n=p->number;	//��¼�˿ʹ���
			puthz(200,118,p->name,16,24,WHITE); //����Ļ����ʾ�˿���Ϣ
	        puthz(200,158,p->sex,16,24,WHITE);
			settextstyle(1,0,1);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			setcolor(WHITE);
			outtextxy(200,233,p->telephone);
			outtextxy(200,193,p->ID);
			if(p!=NULL)
			{
				free(p);
				p=NULL;
			}
			break;
		}
		if(p!=NULL)
		{
			free(p);
			p=NULL;
		}
	}
	if(fclose(fp)!=0)
	{
		printf("\nError on close pass.dat!");
		delay(3000);
		exit(1);
	}
}
/*
FUNCTION:Sign_Check_Jundge
DESCRIPTION:�жϹ���Ա�����Ƿ���Ϲ淶
INPUT:�˿ʹ���n������Ա������ʽpos2��������ת���Ʊ���page
RETURN:flag
*/
int Sign_Check_Jundge(int n,int pos2, int* page)
{
	int flag=0;
	int l;
	int i;
	FILE *fp;
	STATE *S=NULL;
	if((fp=fopen("C:\\TRY\\TEXT\\state.dat","rb+"))==NULL)
	{
		printf("\nError on open file state.dat!");
		delay(3000);
		exit(1);
	}	
	fseek(fp,0,SEEK_END);	//�����ļ���С
	l=ftell(fp)/sizeof(STATE);
	for(i=0;i<l;i++)
	{
		if((S=(STATE*)malloc(sizeof(STATE)))==NULL)
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp,i*sizeof(STATE),SEEK_SET);
		fread(S,sizeof(STATE),1,fp);
		if(n==S->number)
		{
			if(pos2==1&&S->patient!=0)	//ѡ�������ѱ��
			{
				flag=1;
			}
			if(pos2==0&&S->patient==0)	//ѡ��ȡ����δ���
			{
				flag=2;
			}
		}
		if(S!=NULL)                                              //�ͷ��ڴ�
		{
			free(S);
			S=NULL;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
	return flag; //���ز����ж�
}
/*
FUNCTION:Sign_Check_Save
DESCRIPTION:��ϵͳ�б���ĳ˿͵�ȷ�����
INPUT:�˿ʹ���n������Ա������ʽpos2
RETURN:��
*/
int Sign_Check_Save(int n,int pos2) //���ȷ�ﻼ�ߵı�ǻ�ȡ����� 
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
	fseek(fp,0,SEEK_END);                                            //�ļ�ָ�붨λ�����һλ
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
		if(n==s->number) //���ļ��в�ѯ����Ӧ�˿�                                  
		{
			if(pos2==1) //���ȷ��˿�
			{			    			    
				    s->patient=1;
			}
			else //ȡ���˿ͱ��
			{
				s->patient=0;
			}
			fseek(fp,i*sizeof(STATE),SEEK_SET); //����Ϣд���ļ�                      
			fwrite(s,sizeof(STATE),1,fp);                             
			if(s!=NULL)                                              //�ͷ��ڴ�
			{
				free(s);
				s=NULL;
			}
			break;
		}
		if(s!=NULL)                                              //�ͷ��ڴ�
		{
			free(s);
			s=NULL;
		}
	}
	if (fclose(fp) != 0)
	{
		printf("\nError on close state.dat!");
		delay(3000);
		exit(1);
	}
}