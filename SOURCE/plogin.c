#include"public.h"
#include"plogin.h"
/*
FUNCTION:Plogin
DESCRIPTION:ʵ�ֳ˿͵�¼����
INPUT:������ת���Ʊ���page���˿ʹ���identity
RETURN:��
*/
void Plogin(int* page,int* identity)
{
	int i;
	int pos1=0;                                             //�ж������1�������
	int pos2=0;                                             //�ж������2�������
	int flag=0;                                             //��ǵ������
	char account[15];
	char password[15];
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Plogin();                                          //���˿͵�¼����
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);                   //�����
		if(MouseX>95&&MouseX<545&&MouseY>205&& MouseY<230)  //�˺ſ�
		{
			if(mouse_press(95,205,545,230) == 2)    
			{
				MouseS=2;
				if(flag==0&&pos1==0)
				{
					Plogin_Lighten(95,205,545,230,1);
					flag=1;
				}
				continue;
			}

			else if(mouse_press(95,205,545,230)==1)      
			{
				Plogin_Lighten(95,205,545,230,1);
				MouseS = 0;
				account[0]='\0';                            
				setfillstyle(1,DARKGRAY);
		        bar(550,210,640,276);
				Input_Vis(account,95,205,16,LIGHTGRAY);  //�˺����� 
				if(strlen(account)!=0)
					pos1=1;
				else
					pos1=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>260&& MouseY<290) //�����
		{
			if(mouse_press(95,265,545,290)==2)      
			{
				MouseS=2;
				if(flag==0&&pos2==0)
				{
					Plogin_Lighten(95,265,545,290,2);
					flag=2;
				}
				continue;
			}

			else if(mouse_press(95,265,545,290)==1)
			{
				Plogin_Lighten(95,265,545,290,2);
				MouseS=0;
				password[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				Input_Invis(password,95,265,16,LIGHTGRAY);//��������
				if(strlen(password)!=0)
					pos2=1;
				else 
					pos2=0;
				continue;
			}
		}
		
		if(MouseX>260&&MouseX<380&&MouseY>310+12&& MouseY<345+12)//��¼��
		{
			if(mouse_press(260,310+12,380,345+12)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Plogin_Lighten(260,310+15,380,345+15,3);
					flag=3;
				}
				continue;
			}

			else if(mouse_press(260,310+12,380,345+12)==1)
			{
				Plogin_Lighten(260,310+12,380,345,3);
				MouseS=0;
				if(Jundge_Plogin(account,password,&i))//���е�¼�жϣ��������û����
				{
					*identity=i;
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
		            //printf("%d\n",*identity); getchar();
					delay(3000);
					*page=5;                                       //��ת���˿͹��ܽ���
					break;
				}
				else
				{
					setfillstyle(1,DARKGRAY);
		            bar(175,295+12,500,345+12);
		            puthz(265,320+12,"��¼ʧ�ܣ�",24,24,RED);
					delay(3000);
					return ;
				}
				continue;
			}
		}
		
		if(MouseX>290&&MouseX<350&&MouseY>380&& MouseY<405)//ע���
		{
			if(mouse_press(290,380,350,405)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Plogin_Lighten(290,380,350,405,4);
					flag=4;
				}
				continue;
			}

			else if(mouse_press(290,380,350,405)==1)
			{
				Plogin_Lighten(290,380,350,405,4);
				MouseS=0;
				*page=3;                                    //��ת��ע�����
				break;
			}
		}
		
        if(MouseX>100&&MouseX<169&&MouseY>380&& MouseY<405)//���ؿ�
		{
			if(mouse_press(100,380,169,405)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Plogin_Lighten(100,380,169,405,5);
					flag=5;
				}
				continue;
			}

			else if(mouse_press(100,380,169,405)==1)
			{
				Plogin_Lighten(100,380,169,405,5);
				MouseS=0;
				*page=0;                                   //��ת������¼����
				break;
			}
		}
		
		/*if(MouseX>480&&MouseX<570&&MouseY>380&& MouseY<405)//���޸������
		{
			if(mouse_press(480,380,570,405)==2)      
			{
				MouseS=1;
				if(flag==0)
				{
					Plogin_Lighten(480,380,570,405,6);
					flag=6;
				}
				continue;
			}

			else if(mouse_press(480,380,570,405)==1)
			{
				Plogin_Lighten(480,380,570,405,6);
				MouseS=0;
				*page=4;                                   //��ת���޸��������
				break;
			}
		}*/
	
		if(flag!=0)                                       //���ݵ���������Բ�������л�ԭ
		{
			MouseS=0;
			if(pos1==0)
			{
				Plogin_Darken(1);
			}
			if (pos2==0)
			{
				Plogin_Darken(2);
			}
			if (flag==3||flag ==4||flag ==5||flag==6)
			{
				Plogin_Darken(flag);
			}
			flag=0;
		}
		if(MouseS!=0)                                     //��ԭ���
		{                 
			MouseS=0;
		}
	}
}

/*
FUNCTION:Draw_Plogin
DESCRIPTION:���Ƴ˿͵�¼����
INPUT:��
RETURN:��
*/
int Draw_Plogin()
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
	puthz(165,15,"�˿��г̹���ϵͳ",32,40, LIGHTGRAY);
	setfillstyle(1,LIGHTBLUE);

	puthz(95,180,"�������˺�",16,16,CYAN);        //��������ʾ
	puthz(95,240,"����������",16,16,CYAN);

	setfillstyle(1,WHITE);                     
    bar(95,205,545,230);
	bar(95,265,545,290);

	setfillstyle(SOLID_FILL, RED);
	bar(260,310+12,380,345+12);
	puthz(290,315+12,"��¼",24,34,WHITE);//��¼��

	setlinestyle(SOLID_LINE,0,1);
	setfillstyle(SOLID_FILL,WHITE);
	bar(290,380,350,405);
	puthz(302,385,"ע��",16,24,LIGHTBLUE);
	setlinestyle(SOLID_LINE,0,2);
	setcolor(LIGHTBLUE);
	rectangle(290,380,350,405);//ע���

	bar(100,380,169,405);
	puthz(114,385,"����",16,24,LIGHTBLUE);//���ؿ�
	rectangle(100,380,169,405);

/*	bar(480,380,570,405);
	puthz(492,385,"�޸�����",16,18,LIGHTBLUE);//�޸������
	rectangle(480,380,570,405);*/
}

/*
FUNCTION:Plogin_Lighten
DESCRIPTION:�˿͵�¼���水ť����
INPUT:�������Ʊ���flag
RETURN:��
*/
int Plogin_Lighten(int x1,int y1,int x2,int y2,int flag)//���������
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
	    bar(290,380,350,405);
	    puthz(302,385,"ע��",16,24,CYAN);
	    setlinestyle(SOLID_LINE,0,2);
	    setcolor(CYAN);
	    rectangle(290,380,350,405);//ע���
	}
	else if(flag==5)
	{
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(100,380,169,405);
	    puthz(114,385,"����",16,24,CYAN);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(CYAN);
	    rectangle(100,380,169,405);//���ؿ�
	}
	/*else if(flag==6)
	{
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(480,380,570,405);
	    puthz(492,385,"�޸�����",16,18,CYAN);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(CYAN);//�޸������
	    rectangle(480,380,570,405);
	}*/
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
FUNCTION:Plogin_Darken
DESCRIPTION:�˿͵�¼���水ť�ָ�
INPUT:�ָ����Ʊ���pos
RETURN:��
*/
int Plogin_Darken(int pos)                            
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
	    puthz(290,315+12,"��¼",24,34,WHITE);//��¼��
		break;
	case 4:
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
	    bar(290,380,350,405);
	    puthz(302,385,"ע��",16,24,LIGHTBLUE);
	    setlinestyle(SOLID_LINE,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(290,380,350,405);//ע���
		break;
	case 5:
		setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(100,380,169,405);
	    puthz(114,385,"����",16,24,LIGHTBLUE);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(LIGHTBLUE);
	    rectangle(100,380,169,405);//���ؿ�
		break;
	/*case 6:
	    setlinestyle(SOLID_LINE,0,1);
	    setfillstyle(SOLID_FILL,WHITE);
		bar(480,380,570,405);
	    puthz(492,385,"�޸�����",16,18,LIGHTBLUE);
		setlinestyle(SOLID_LINE,0,2);
	    setcolor(LIGHTBLUE);//�޸������
	    rectangle(480,380,570,405);*/
	}
}

int Jundge_Plogin(char* account, char* password,int *id)	
{
	int l;                                                                     
	int i;
	int identity;
	FILE* fp;
	USER* u;                                                     //�ݴ��û���Ϣ�Ľṹ��
	if((fp=fopen(".\\TEXT\\UserData.dat","rb+"))==NULL)    //�򿪴洢�û���Ϣ���ļ�
	{
		printf("\nError on open file UserData.dat!");
		delay(3000);
		exit(1);
	}
	fseek(fp,0,SEEK_END);                                 //���ļ�ָ�붨λ�����
	l=ftell(fp)/sizeof(USER);                             //���ڴ�µ����ṹ���ڴ棬������ļ��ж�ȡ�������û���
	for(i=0;i<l;i++)                                      //�������ļ��ж����������û�
	{
		if ((u=(USER*)malloc(sizeof(USER)))==NULL)        //����
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fseek(fp,i*sizeof(USER),SEEK_SET);                //�ļ�ָ�붨λ����i���û����ڵ�λ��
		fread(u, sizeof(USER),1,fp);                      //���ļ��н���i���û�����Ϣ����u
		if(strcmp(account,u->account)==0)                 //����뵱ǰ�����û����û���ƥ��
		{
			if(strcmp(password,u->password)!=0)           //����뵱ǰ�����û������벻ƥ��
			{
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				puthz(550,270,"�������",16,16,RED);      
				break;                                    //��������
			}
			else if(strcmp(password,u->password)==0)      //����뵱ǰ�����û�������ƥ��
			{
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				puthz(550,270,"������ȷ",16,16,RED);
				*id=u->number;
				if (u!=NULL)                              //�ͷ��ڴ�
				{
					free(u);
					u=NULL;
				}
				if (fclose(fp)!= 0)                       //�ر��ļ�
				{
					printf("\nError on close UserData.dat!");
					delay(3000);
					exit(1);
				}
				return 1;                          //��־��¼�ɹ������ظ��û���ݣ��Ա�����ĳ˿Ͳ���
			}
		}
	}
	if (i==l)                                             //�������ļ��ж�δ�ҵ����û���Ϣ
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,276);
		puthz(550,210,"�˺�δע��", 16, 16, RED);       
	}

	if (u!= NULL)                                         //�ͷ��ڴ�
	{
		free(u);
		u=NULL;
	}

	if (fclose(fp) != 0)                                  //�ر��ļ�
	{
		printf("\nError on close UserData.dat!");
		delay(3000);
		exit(1);
	}
	return 0;                                             //����0����־��¼ʧ��
}