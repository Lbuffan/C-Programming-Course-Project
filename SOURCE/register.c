#include"public.h"
#include"register.h"
/*
FUNCTION:Register
INPUT:������ת���Ʊ���page
RETURN:��
*/
void Register(int* page)
{
	int pos1=0;                                             //�ж������1�������
	int pos2=0;                                             //�ж������2�������
	int pos3=0;                                             //�ж������3�������
	int pos4=0;                                             //�ж������4�������
	int pos5=0;
	int flag=0;                                             //�����������������Է��ظ�����
	int jun1=0;                                             //�ж��˺�������
	int jun2=0;                                             //�ж�����������
	int jun3=0;                                             //�ж�ȷ������������
	int jun4=0;                                             //�ж����֤��������
	int jun5=0;
	int identity;                                           //�洢ע��˿͵����
	char A[15]={'\0'};                                      //�˺ţ�6-12λ
	char I[20]={'\0'};                                      //���֤��18λ
	char P[15]={'\0'};                                      //�������룬6-12λ
	char RP[15]={'\0'};                                     //ȷ�����룬6-12λ
	
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	Draw_Register();                                        //��ע�����
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);                   //�����
		if(MouseX>95&&MouseX<545&& MouseY>85&& MouseY<110)  //�����������1�ķ�Χ
		{
			if(mouse_press(95,85,545,110)==2)               //δ��������1
			{
				MouseS=2;                                   //�����Ϊ�����̬
				if(flag==0&&pos1==0)                  
				{
					Register_Lighten(95,85,545,110,1);      //���������1
					flag=1;                                 //��������1�ѵ���
				}
				continue;
			}

			else if(mouse_press(95,85,545,110)==1)         //��������1
			{
				MouseS =0;
				Register_Lighten(95,85,545,110,1);
				A[0]='\0';                                  //���֮ǰ������
				setfillstyle(1,DARKGRAY);
		        bar(550,90,640,106);
				Input_Vis(A,95,85,12,LIGHTGRAY);            //��������
				jun1=R_Account_Jundge(A);                   //�ж��˺��Ƿ����Ҫ��
				if(strlen(A)!= 0)                           //�ж��Ƿ��������
					pos1=1;                                 //�����������б��
				else
					pos1=0;
				continue;
			}
		}
		if(MouseX>95&& MouseX<545&& MouseY>145&& MouseY< 170)
		{
			if(mouse_press(95,145,545,170)==2)     
			{
				MouseS=2;
				if(flag==0&&pos2==0)
				{
					Register_Lighten(95,145,545,170,2);
					flag=2;
				}
				continue;
			}

			else if(mouse_press(95,145,545,170)==1)     
			{
				Register_Lighten(95,145,545,170,2);
				MouseS=0;
				P[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,150,640,166);
				Input_Invis(P,95,145,16,LIGHTGRAY);
				jun2=R_Password_Jundge(P);//�ж����볤���Ƿ����Ҫ��
				if(strlen(P)!=0)
					pos2=1;
				else
					pos2=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>205&& MouseY<230)
		{
			if(mouse_press(95,205,545,230) == 2)    
			{
				MouseS=2;
				if(flag==0&&pos3==0)
				{
					Register_Lighten(95,205,545,230,3);
					flag=3;
				}
				continue;
			}

			else if(mouse_press(95,205,545,230)==1)      
			{
				Register_Lighten(95,205,545,230,3);
				MouseS = 0;
				RP[0] ='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,210,640,226);
				Input_Invis(RP,95,205,16,LIGHTGRAY);//����������
				jun3=R_Password_Same(P,RP);//�ж���������������Ƿ�һ��
				if(strlen(RP)!=0)
					pos3=1;
				else
					pos3=0;
				continue;
			}
		}

		if(MouseX>95&&MouseX<545&&MouseY>260&& MouseY<290)
		{
			if(mouse_press(95,265,545,290)==2)      
			{
				MouseS=2;
				if(flag==0&&pos4==0)
				{
					Register_Lighten(95,265,545,290,4);
					flag=4;
				}
				continue;
			}

			else if(mouse_press(95,265,545,290)==1)
			{
				Register_Lighten(95,265,545,290,4);
				MouseS=0;
				I[0]='\0';
				setfillstyle(1,DARKGRAY);
		        bar(550,270,640,286);
				Input_Vis(I,95,265,18,LIGHTGRAY);
				jun4=R_ID_Jundge(I);//�ж����֤�Ƿ���Ч
				if(strlen(I)!=0)
					pos4=1;
				else 
					pos4=0;
				continue;
			}
		}
		
		if(MouseX>143&&MouseX<237&&MouseY>370&& MouseY<400)
		{
			if(mouse_press(143,370,237,400)==2)                
			{
				if(flag==0)
				{
					MouseS=1;
					Register_Lighten(143,370,237,400,5);
					flag=5;
				}
				continue;
			}

			else if(mouse_press(143,370,237,400)==1)
			{
				MouseS=0;                        //�������
				A[0]='\0';
				I[0]='\0';
				P[0]='\0';
				RP[0]='\0';
				flag=0;                          //��������
				pos1=0;
				pos2=0;
				pos3=0;
				pos4=0;
				return;
			}
		}

		if(MouseX >273&& MouseX<367&& MouseY>370&& MouseY<400)
		{
			if(mouse_press(273,370,367,400)==2)					
			{
				if (flag==0)
				{
					MouseS=1;
					Register_Lighten(273,370,367,400,6);
					flag=6;
				}
				continue;
			}

			else if(mouse_press(273,370,367,400)==1)
			{
				MouseS=0;
				if (Register_Com(jun1,jun2,jun3,jun4,A,I,P))//ע���ж�
				{
		            *page=1;                                         //��ת���˿͵�¼����
					break;
				}
				else
				{
					return;
				}
			}
		}

		if (MouseX>403&&MouseX<497&&MouseY>370&&MouseY<400)
		{
			if (mouse_press(403, 370, 497, 400)==2)				
			{
				if (flag==0)
				{
					MouseS=1;
					Register_Lighten(403,370,497,400,7);
					flag=7;
				}
				continue;
			}

			else if(mouse_press(403, 370, 497, 400) == 1)
			{
				MouseS=0;
				*page=1;                            //��ת���˿͵�¼����
				break; 
			}
		}

		if(flag!=0)                                 //���ݵ�����������������л�ԭ
		{
			MouseS=0;
			if(pos1==0)
			{
				Register_Darken(1);
			}
			if (pos2==0)
			{
				Register_Darken(2);
			}
			if (pos3==0)
			{
				Register_Darken(3);
			}
			if (pos4==0)
			{
				Register_Darken(4);
			}
			if (pos5==0)
			{
				Register_Darken(5);
			}
			if (flag==5||flag ==6||flag ==7)
			{
				Register_Darken(flag);
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
FUNCTION:Draw_Register
DESCRIPTION:���Ƶ�¼����
INPUT:��
RETURN:��
*/
int Draw_Register()
{
    cleardevice();
	setbkcolor(DARKGRAY);                        //���ñ�����ɫ
	
	puthz(255,25,"�û�ע��",32,32,WHITE);
	puthz(254,24,"�û�ע��",32,32,RED);
	puthz(175,320,"�������Ϣ͸¶������",24,24,BROWN);
	puthz(95,60,"�������˺�",16,16,CYAN);        //��������ʾ
	puthz(95,120,"����������",16,16,CYAN);
    puthz(95,180,"��ȷ������",16,16,CYAN);
    puthz(95,240,"���������֤����",16,16,CYAN);
	
	
	setviewport(0,0,640,480,1);                  //��С�˺����֤
	setfillstyle(1,YELLOW);
	setcolor(YELLOW);
	circle(50,95,30);
	floodfill(50,95,YELLOW);

    setfillstyle(1,BLUE);
	setcolor(BLUE);
	circle(50,275,30);
	floodfill(50,275,BLUE);
	
	setfillstyle(1,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	circle(50,85,10);
	floodfill(50,85,LIGHTGRAY);
	setcolor(LIGHTGRAY);
	line(50,95,34,115);
	line(34,115,66,115);
	line(66,115,50,95);
	floodfill(50,105,LIGHTGRAY);
	
	setfillstyle(1, WHITE);
	setcolor(WHITE);
	rectangle(30,265,70,285);
	floodfill(35,275, WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(45,268,55,271);
	bar(45,273,65,276);
	bar(45,278,65,281);
	
	setfillstyle(1,WHITE);                     
	bar(95,85,545,110);                          //�������
    bar(95,145,545,170);
	bar(95,205,545,230);
	bar(95,265,545,290);

	setfillstyle(1,GREEN);
	bar(143, 370, 237, 400);
	puthz(161,373,"����",24,34,WHITE);           //��������
    setfillstyle(1,RED);
	bar(273, 370, 367, 400);
	puthz(291,373,"���",24,34,WHITE);
    setfillstyle(1,BLUE);
	bar(403, 370, 497, 400);
	puthz(421,373,"����",24,34,WHITE);
	
	
}


/*
FUNCTION:Register_Lighten
DESCRIPTION:�˿�ע����水ť����
INPUT:�������Ʊ���flag
RETURN:��
*/
int Register_Lighten(int x1,int y1,int x2,int y2,int flag)
{
	clrmous(MouseX,MouseY);
	delay(10);

	if(flag==5)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,CYAN);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(161,373,"����",24,34,LIGHTCYAN);
	}
	else if(flag== 6)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,RED);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(291,373,"���",24,34,LIGHTRED);
	}
	else if(flag==7)
	{
		setcolor(WHITE);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,BLUE);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
		puthz(421,373,"����",24,34,LIGHTBLUE);
	}
	else                                            //���������
	{
		setcolor(MAGENTA);
	    setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	    setfillstyle(1,LIGHTGRAY);
	    bar(x1,y1,x2,y2);
	    rectangle(x1,y1,x2,y2);	
	}
}

/*
FUNCTION:Register_Darken
DESCRIPTION:�˿�ע����水ť�ָ�
INPUT:�ָ����Ʊ���pos
RETURN:��
*/
int Register_Darken(int pos)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1, WHITE);
	switch (pos)
	{
	case 1:                                          //��ԭ�����
		bar(95,85,545,110);
		break;
	case 2:
		bar(95,145,545,170);
		break;
	case 3:
		bar(95,205,545,230);
		break;
	case 4:
		bar(95,265,545,290);
		break;
	case 5:
		setfillstyle(1,GREEN);
		bar(143,370,237,400);
		puthz(161,373,"����",24,34,WHITE);
		break;
	case 6:
		setfillstyle(1,RED);
		bar(273,370,367,400);
		puthz(291,373,"���",24,34,WHITE);
		break;
	case 7:
		setfillstyle(1,BLUE);
		bar(403,370,497,400);
		puthz(421,373,"����",24,34,WHITE);
		break;
	case 8:
	    bar(175, 325, 545, 350);
		break;
	}
}

/*
FUNCTION:R_Account_Jundge
DESCRIPTION:�ж��˺��Ƿ����Ҫ��
INPUT:������˺�A
RETURN:�жϽ��
*/
int R_Account_Jundge(char* A)                  //�ж��˺��Ƿ����Ҫ��
{
	int flag=0;                                //����˺ų����Ƿ����Ҫ��
	int l;
	int i;
	FILE* fp;
	USER*u=NULL;
	if(strlen(A)>=6)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,90,640,106);
		puthz(550,90,"ͨ��",16,16,RED);
		flag=1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,90,640,106);
		puthz(550,90,"�˺Ź���",16,16,RED);
		flag=0;
	}
	if(flag==1)
	{
		if((fp=fopen(".\\TEXT\\UserData.dat","rb+"))==NULL)//�򿪴洢�û���Ϣ���ļ�
	    {
		    printf("\nError on open file UserData.dat!");
		    delay(3000);
		    exit(1);
	    }
	    fseek(fp,0,SEEK_END);                                    //�ļ�ָ�붨λ�����
	    l=ftell(fp)/sizeof(USER);                                //�����û�����
	    for(i=0;i<l;i++)                                         //������ȡ���������û�
	    {
		    if((u=(USER*)malloc(sizeof(USER)))==NULL)
		    {
			    printf("Memory not enough!");
			    delay(3000);
			    exit(1);
		    }
		    fseek(fp,i*sizeof(USER),SEEK_SET);
		    fread(u,sizeof(USER),1,fp);
		    if(strcmp(u->account,A)==0)                          //�����ǰ�˺����ļ����Ѿ�����
		    {
			    setfillstyle(1,DARKGRAY);
		        bar(550,90,640,106);
		        puthz(550,90,"�˺���ע��",16,16,RED);
			    if(u != NULL)
			    {
				    free(u);
				    u = NULL;
			    }
			    if(fclose(fp) != 0)
			    {
				    printf("\nError on close UserData.dat!");
				    delay(3000);
				    exit(1);
			    }
			    if(u!= NULL)
		        {
			        free(u);
			        u = NULL;
		        }
			    return 0;                                        //�˺Ų�����Ҫ��
		    }
	    }
		//�ܹ��뿪ѭ����˵���˺���δע��
		setfillstyle(1,DARKGRAY);
		bar(550,90,640,106);
		puthz(550,90,"ͨ��",16,16,RED);
		if(u!= NULL)
		{
			free(u);
			u = NULL;
		}
		if(fclose(fp) != 0)
		{
			printf("\nError on close UserData.dat!");
			delay(3000);
			exit(1);
		}
		if(u != NULL)
		{
			free(u);
			u = NULL;
		}
		return 1;                                                 //�˺ŷ���Ҫ��
    }
}

/*
FUNCTION:R_Password_Jundge
DESCRIPTION:�ж������Ƿ����Ҫ��
INPUT:���������P
RETURN:�жϽ��
*/
int R_Password_Jundge(char* P)                                    //�ж����볤���Ƿ����Ҫ��
{
	if(strlen(P)>=6)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,150,640,166);
		puthz(550,150,"ͨ��",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,150,640,166);
		puthz(550,150,"�������",16,16,RED);
		return 0;
	}
}	

/*
FUNCTION:R_Password_Same
DESCRIPTION:�ж���������������Ƿ�һ��
INPUT:�������������P,RP
RETURN:�жϽ��
*/
int R_Password_Same(char* P,char* RP)                             //�ж���������������Ƿ�һ��
{
	if(strcmp(P,RP)==0)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,226);
		puthz(550,210,"����һ��",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,210,640,226);
		puthz(550,210,"���벻һ��",16,16,RED);
		return 0;
	}
}

/*
FUNCTION:R_ID_Jundge
DESCRIPTION:�ж����֤�Ƿ���Ч
INPUT:��������֤��I
RETURN:�жϽ��
*/
int R_ID_Jundge(char *I)               //�ж���������֤���Ƿ������ϵͳ��
{
	int flag=0;
	int i=0;
	int id=0;
	FILE* fp;
	PASSENGER* p=NULL;
	
	if((fp = fopen(".\\TEXT\\pass.dat","rb+"))==NULL)     //�򿪴洢�û���Ϣ���ļ�
	{
		printf("\nError on close pass.dat!");
		delay(3000);
		exit(1);
	}
	while(!feof(fp))
	{
		if((p=(PASSENGER*)malloc(sizeof(PASSENGER)))==NULL)     //����ռ�
		{
			printf("\nMemory not enough!");
			delay(3000);
			exit(1);
		}
		fscanf(fp,"%d",&p->number); 
		if(p->number==-1)
		{
			break;
		}
		fgetc(fp);
		fscanf(fp,"%s",p->name);
		fgetc(fp);
		fgets(p->telephone,12,fp);
		fgetc(fp);
		fgets(p->ID,19,fp);
		fgetc(fp);
		fgetc(fp);
		fgets(p->age,3,fp);
		fgetc(fp);
		fgets(p->sex,3,fp);
		fgetc(fp);
		if(strcmp(p->ID,I)==0)
		{
			id=p->number;
			flag=1;
			if(p!= NULL)                                      //�ͷ��ڴ�
		    {
			    free(p);
			    p= NULL;
		    }
			break;
		}
		if(p!= NULL)                                      //�ͷ��ڴ�
		{
			free(p);
			p = NULL;
		}
	}	
	if(flag==1)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,270,640,286);
		puthz(550,270,"���֤��Ч",16,16,RED);
		return id;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,270,640,286);
		puthz(550,270,"���֤��Ч",16,16,RED);
		return 0;
	}
}

int R_Code_Jundge(char* str,char* VC)
{
	if(strcmp(str,VC)==0)
	{
		setfillstyle(1,DARKGRAY);
		bar(550,330,640,286+60);
		puthz(550,330,"��ȷ",16,16,RED);
		return 1;
	}
	else
	{
		setfillstyle(1,DARKGRAY);
		bar(550,330,640,286+60);
		puthz(550,330,"����",16,16,RED);
		return 0;
	}
}
/*
FUNCTION:R_Input_Data
DESCRIPTION:����ע����û���Ϣд���ļ�
INPUT:������˺�A�����֤��I������P���˿ʹ���identity
RETURN:�жϽ��
*/
void R_Input_Data(char* A,char* I,char* P,int jun4)           //����ע����û���Ϣд���ļ�
{
	FILE* fp;
	USER* u;
	if((fp=fopen(".\\TEXT\\UserData.dat", "rb+" )) == NULL) //�򿪴洢�û���Ϣ���ļ�
	{
		printf("\nError on open file UserData.dat!");
		delay(3000);
		exit(1);
	}
	if((u=(USER*)malloc(sizeof(USER)))==NULL)                      //����ռ�
	{
		printf("\nMemory not enough!");
		delay(3000);
		exit(1);
	}
	u->number=jun4;                                            //���û��������Ϣ��ʱ�洢��u��
	strcpy(u->ID,I);
	strcpy(u->account,A);
	strcpy(u->password,P);
	fseek(fp,0,SEEK_END);                                          //�ļ�ָ���ƶ����ļ����
	fwrite(u,sizeof(USER),1,fp);                                   //�����û���Ϣд���ļ����
	if (u != NULL)                                                 //�ͷ�u
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp)!=0)                                             //�ر��ļ�
	{
		printf("\nError on close UserData.dat!");
		delay(3000);
		exit(1);
	}
}

/*
FUNCTION:Register_Com
DESCRIPTION:���ע��
INPUT:�жϽ��jun1,jun2,jun3,jun4,������˺�A�����֤��I������P���˿ʹ���identity
RETURN:�жϽ��
*/
int Register_Com(int jun1,int jun2,int jun3,int jun4,char* A,char* I,char* P)
{
	if(jun1==1&&jun2==1&&jun3==1&&jun4!=0)                         //�û���������ݾ�����Ҫ��
	{
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,220,"����ע��",24,24,RED);
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
		puthz(274,230,"ע��ɹ�",24,24,RED);
		delay(3000);
		R_Input_Data(A,I,P,jun4);                              //�����û�����Ϣд���ļ�
	    return 1;
	}
	else
	{
		setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,220,"����ע��",24,24,RED);
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
		puthz(274,230,"ע��ʧ��",24,24,RED);
		delay(3000);
		return 0;
	}
}
