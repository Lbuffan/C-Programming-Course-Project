#include"public.h"
#include"pass.h"



/*
FUNCTION:ʵ�ֳ˿͹���
INPUT:������ת���Ʊ���page���˿ʹ���identity
RETURN:��
*/
void Pass(int* page, int identity)
{
	int flag=0;
	int Tag;//���ڱ�ǳ˿�״̬��1=������2=���нӴ��ߣ�3=ȷ��
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Tag=Pass_Tag(identity);
	Draw_Pass(Tag,identity);
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if (MouseX > 492 && MouseX < 619 && MouseY> 80 && MouseY < 105)
		{
			if (mouse_press(492,80,619,105) == 2)//�鿴�˳���¼δ���
			{
				MouseS = 1;
				if (flag== 0)//��ֹ���ظ�����
				{
		            Pass_Lighten(1);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(492, 80, 619, 105) == 1)//�鿴�˳���¼����
			{
				MouseS = 0;
				Pass_Lighten(1);
				*page=51;
				break;
			}
		}
		
		/*if (MouseX > 492 && MouseX < 619 && MouseY> 377 && MouseY < 397)
		{
			if (mouse_press(492,377,619,397) == 2)//�鿴�˳���¼δ���
			{
				MouseS = 1;
				if (flag== 0)//��ֹ���ظ�����
				{
		            Pass_Lighten(2);
					flag= 1;
				}
				continue;
			}
			else if (mouse_press(492, 377, 619, 397) == 1)//�鿴�˳���¼����
			{
				MouseS = 0;
				Pass_Lighten(2);
				*page=51;
				break;
			}
		}*/
		
		if (MouseX > 525 && MouseX < 630 && MouseY> 450 && MouseY < 470)
		{
			if (mouse_press(525, 450, 630, 470) == 2)//����˳�δ���
			{
				MouseS=1;
				continue;
			}
			else if (mouse_press(525, 450, 630, 470) == 1)//����˳����
			{
				MouseS = 0;
				clrmous(MouseX, MouseY);
				*page =0;
				break;
				//�л����˿͵�¼����
			}
		}

        if (flag!= 0||MouseS!=0)
		{
			flag= 0; 
			MouseS = 0;
			Pass_Darken();
	    }
	}
}

/*
FUNCTION:���Ƴ˿͹��ܽ���
INPUT���˿͵�ǰ״̬Tag
RETURN����
*/
void Draw_Pass(int Tag,int identity)
{
    cleardevice();
	
	if(Tag==1)
	{
		//Pass_Name(identity);
	
	    ring(555, 263, 60, 50, GREEN, GREEN, 2);
	    map();
		//������ͼ
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, LIGHTGREEN);
		highlight(472, 0, 639, 479, LIGHTGREEN);
		//�������
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTRED);
		//�鿴�˳���¼
		puthz(492,150,"���ĳ���״̬�ǣ�",16,16,DARKGRAY);
		puthz(492,150+30,"����ͨ��",16,16,DARKGRAY);
		setcolor(GREEN);
		line(546, 270+20+40, 565, 270+20+40);
		line(546, 220+20+40, 546, 270+20+40);
		line(565, 220+20+40, 565, 270+20+40);//����
		line(520, 242+20+40, 532, 242+20+40);
		line(579, 242+20+40, 591, 242+20+40);//����ˮƽ��
		line(532, 242+20+40, 546, 220+20+40);
		line(579, 242+20+40, 565, 220+20+40);//�ڲ�б��
		line(520, 242+20+40, 555.5, 190+20+40);
		line(591, 242+20+40, 555.5, 190+20+40);
		setfillstyle(1,GREEN);
		floodfill(555.5, 240+20+40, GREEN);
		circle(555+1,230+20+40,50);
		circle(555+1,230+20+40,60-2);
		floodfill(555+1,230+20+55+40,GREEN);
		//��ʾ�˳�״̬
		/*cover(492, 395+2-20, 619, 415+2-20, WHITE);
		highlight(492, 395+2-20, 619, 415+2-20, LIGHTRED);
		puthz(492 + 10, 400-20, "�鿴ͣ������", 16, 19, LIGHTRED);*/
		//�鿴ͣ������
		draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
		//����˳�
	}
	
	else if(Tag==2)
	{
		//Pass_Name(identity);
	
		ring(555, 263, 60, 50, GREEN, GREEN, 2);
		map();
		//������ͼ
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, LIGHTGREEN);
		highlight(472, 0, 639, 479, LIGHTGREEN);
		//�������
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTRED);
		//�鿴�˳���¼
		puthz(492,150,"���ĳ���״̬�ǣ�",16,16,DARKGRAY);
		puthz(492,150+30,"��ֹ����",16,16,RED);
		
		cover(547, 227, 547 + 15, 227 + 50, YELLOW);
		setcolor(YELLOW);
	    setfillstyle(1, YELLOW);
	    pieslice(547 + 7.5, 227+35 + 50, 0, 360, 10);
	    setcolor(YELLOW);
		
		//��ʾ�˳�״̬
		/*cover(492, 395+2-20, 619, 415+2-20, WHITE);
		highlight(492, 395+2-20, 619, 415+2-20, LIGHTRED);
		puthz(492 + 10, 400-20, "�鿴ͣ������", 16, 19, LIGHTRED);*/
		//�鿴ͣ������
		draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
		//����˳�
	}
	
	else
	{
		//Pass_Name(identity);
	
		ring(555, 263, 60, 50, GREEN, GREEN, 2);
	    map();
		//������ͼ
		highlight(483 - 2, 9 - 2, 627 + 2, 470 + 2, LIGHTGREEN);
		highlight(472, 0, 639, 479, LIGHTGREEN);
		//�������
		cover(492, 80, 619, 105, WHITE);
		highlight(492, 80, 619, 105, LIGHTRED);
		puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTRED);
		//�鿴�˳���¼
		puthz(492,150,"���ĳ���״̬�ǣ�",16,16,DARKGRAY);
		puthz(492,150+30,"��ֹ����",16,16,RED);
		
		cover(547, 227, 547 + 15, 227 + 50, RED);
		setcolor(RED);
	    setfillstyle(1, RED);
	    pieslice(547 + 7.5, 227 +35+ 50, 0, 360, 10);
	    setcolor(RED);
		
		//��ʾ�˳�״̬
		/*cover(492, 395+2-20, 619, 415+2-20, WHITE);
		highlight(492, 395+2-20, 619, 415+2-20, LIGHTRED);
		puthz(492 + 10, 400-20, "�鿴ͣ������", 16, 19, LIGHTRED);*/
		//�鿴ͣ������
		draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
		//����˳�
	}
	
	
}

/*
FUNCTION:��ʾ�˿�����
INPUT���˿ʹ���identity
RETURN����
*/

/*int Pass_Name(int identity)
{
	int flag=0;
	int n=0;
	FILE* fp;
	PASSENGER* p;//���ڴ���˿���Ϣ
	while(!feof(fp))
	{
		if((fp=fopen("C:\\TRY\\TEXT\\pass.dat","rb+"))==NULL)//������
		{
			printf("\nError on open pass.dat");
			delay(3000);
			exit(1);
		}
		
		//�������г˿���Ϣ
		
		fscanf(fp, "%d", &p->number);
		fgetc(fp);
		fscanf(fp, "%s", p->name);
		fgetc(fp);
		fgets(p->telephone, 12, fp);
		fgetc(fp);
		fgets(p->ID, 19, fp);
		fgetc(fp);
		fgets(p->age, 3, fp);
		fgetc(fp);
		fgets(p->sex, 3, fp);
		fgetc(fp);
		
		/*
		fscanf(fp,"%d",&p->number);    fgetc(fp);//ʹ�ļ�ָ�������
        fscanf(fp,"%s",p->name);       fgetc(fp);
		fgets(p->telephone,12,fp);     fgetc(fp);
		fgets(p->ID,19,fp);            fgetc(fp);
		fgets(p->age,3,fp);            fgetc(fp);
		fgets(p->sex,3,fp);            fgetc(fp);*/
		
		/*if(p->number==identity)
		{
			puthz(502,30,"���ã�",16,17,LIGHTBLUE);
			puthz(553,30,p->name,16,17,LIGHTBLUE);
			puthz(601,30,"!",16,17,LIGHTBLUE);
			if(p!=NULL)//�ͷ��ڴ�
			{
				free(p);
				p=NULL;
			}	
			break;
		}	
		
		if(p!=NULL)//�ͷ��ڴ�
		{
			free(p);
			p=NULL;
		}
	}
	
	if(p!=NULL)//�ͷ��ڴ�
	{
		free(p);
		p=NULL;
	}
	
	if(fclose(fp)!=0)//�ر��ļ�
	{
		printf("\n Error on close pass.dat1!");
		delay(3000);
		exit(1);
	}
	
	return 0;
	
}*/





/*
FUNCTION:Pass_Tag
INPUT:�˿ʹ���identity
RETURN���˿�״̬flag
*/

int Pass_Tag(int identity)
{
	int l;
	int i;
	int flag=0;//��¼�˿�״̬
	FILE* fp;
	STATE* s=NULL;
	
	if((fp=fopen(".\\TEXT\\STATE.dat","rb+"))==NULL)
	{
		printf("\n Error on open file STATE.dat!");
		delay(3000);
		exit(1);
	}
	
	fseek(fp,0,SEEK_END);//�ļ�ָ�붨λ�����һλ
	l=ftell(fp)/sizeof(STATE);//��������������
	for(i=0;i<l;i++)
	{
		if((s=(STATE*)malloc(sizeof(STATE)))==NULL)
		{
			printf("\n Memory is not enough!");
			delay(3000);
			exit(1);
		}
		
		fseek(fp,i*sizeof(STATE),SEEK_SET);
		fread(s,sizeof(STATE),1,fp);
		
		if(identity==s->number)
		{
			if(s->patient!=0)//�˿ͱ����Ϊȷ�ﻼ��
			{
				flag=3;
			}
		    else if(s->contact==1)//�˿ͱ����Ϊ���нӴ���
			{
				flag=2;
			}
			else//�˿ͱ����Ϊ����״̬
			{
				flag=1;
			}
			
			if(s!=NULL)
			{
				free(s);
				s=NULL;
			}
			break;
		}
		
		if(s!=NULL)
		{
			free(s);
			s=NULL;
		}
	}
	
	if(fclose(fp)!=0)
	{
		printf("\n Error on close STATE.dat!");
		delay(3000);
		exit(1);
	}
	
	return flag;
}





/*
FUNCTION:�˿ͽ��水ť�ָ�
INPUT����
RETURN����
*/
int Pass_Darken()
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, WHITE);
	cover(492, 80, 619, 105, WHITE);
	highlight(492, 80, 619, 105, LIGHTRED);
	puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTRED);
	//�鿴�˳���¼
	/*cover(492, 395+2-20, 619, 415+2-20, WHITE);
	highlight(492, 395+2-20, 619, 415+2-20, LIGHTRED);
	puthz(492 + 10, 400-20, "�鿴ͣ������", 16, 19, LIGHTRED);*/
	//�鿴ͣ������
}




/*
FUNCTION:�˿ͽ��水ť����
INPUT���������Ʊ���flag
RETURN:��
*/
int Pass_Lighten(int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	switch(flag)
	{
		case 1:
		setfillstyle(1, WHITE);
		setcolor(CYAN);
		bar(492, 80, 619, 105);
		cover(492, 80, 619, 105, WHITE);
	    highlight(492, 80, 619, 105, LIGHTMAGENTA);
	    puthz(492 + 10, 86, "�鿴�˳���¼", 16, 19, LIGHTMAGENTA);
		break;
	    //�鿴�˳���¼
	    /*case 2:
		setfillstyle(1, WHITE);
		setcolor(CYAN);
		bar(492, 395+2-20, 619, 415+2-20);
	    cover(492, 395+2-20, 619, 415+2-20, WHITE);
	    highlight(492, 395+2-20, 619, 415+2-20, LIGHTMAGENTA);
	    puthz(492 + 10, 400-20, "�鿴ͣ������", 16, 19, LIGHTMAGENTA);
		break;*/
	    //�鿴ͣ������
	}
}