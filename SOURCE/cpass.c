#include "public.h"
#include "cpass.h"
#include "patient.h"
#include "check.h"
/*
FUNCTION:cpass
DESCRIPTION:�������Ų鿴�����˿�
INPUT:������ת���Ʊ���page
RETURN:��
*/
void Cpass(int *page)
{
	int a[20]; //�洢�˿ʹ���
	int pos1=0;
	int pos2=0;
	int pos3=0;
	int flag=0; //��ǵ������
	int i;
	char dates[4]={"\0"};
	char lines[3]={"\0"};
	char nums[3]={"\0"};
	int line=0;
	int num=0;
	int date=0;
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	
	Draw_Cpass();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX>390&&MouseX<475&&MouseY>100&&MouseY<150)	//�������ڿ�
		{	
			if(mouse_press(390,100,475,150)==2)
			{
				MouseS=1;
				if(flag==0)
				{
					/*clrmous(MouseX,MouseY);
					Cpass_Lighten(2);
					flag=2;*/
				}
				continue;
			}
			else if(mouse_press(390,100,475,150)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Cpass_Lighten(2);
				dates[0]='\0';
				date=0;
				Input_Vis(dates,390+5,100+15,2,DARKGRAY);
				if(strlen(dates)!=0)
				{
					pos1=1;
				}
				else
				{
					pos1=0;
				}
				date=atoi(dates)-15;
				continue;
			}
		}
		if(MouseX>240&&MouseX<295&&MouseY>180&&MouseY<230)	//����·��
		{	
			if(mouse_press(240,180,295,230)==2)
			{
				MouseS=1;
				if(flag==0)
				{
					/*clrmous(MouseX,MouseY);
					Cpass_Lighten(3);
					flag=3;*/
				}
				continue;
			}
			else if(mouse_press(240,180,295,230)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Cpass_Lighten(3);
				lines[0]='\0';
				line=0;
				Input_Vis(lines,240,180+15,1,DARKGRAY);
				if(strlen(lines)!=0)
				{
					pos2=1;
				}
				else
				{
					pos2=0;
				}
				line=atoi(lines);
				continue;
			}
		}
		if(MouseX>240&&MouseX<295&&MouseY>260&&MouseY<310)	//���복��
		{	
			if(mouse_press(240,260,295,310)==2)
			{
				MouseS=1;
				if(flag==0)
				{
					/*clrmous(MouseX,MouseY);
					Cpass_Lighten(4);
					flag=4;*/
				}
				continue;
			}
			else if(mouse_press(240,260,295,310)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Cpass_Lighten(4);
				nums[0]='\0';
				num=0;
				Input_Vis(nums,240,260+15,2,DARKGRAY);
				if(strlen(nums)!=0)
				{
					pos3=1;
				}
				else
				{
					pos3=0;
				}
				num=atoi(nums);
				continue;
			}
		}
		if(MouseX>226&&MouseX<226+187&&MouseY>358.75&&MouseY<358.75+60.5)	//��ѯ
		{	
			if(mouse_press(226, 358.75, 226 + 187, 358.75 + 60.5)==2)
			{
				MouseS=1;
				if(flag==0)
				{
					clrmous(MouseX,MouseY);
					Cpass_Lighten(1);
					flag=1;
				}
				continue;
			}
			else if(mouse_press(226, 358.75, 226 + 187, 358.75 + 60.5)==1)
			{
				MouseS=0;
				clrmous(MouseX,MouseY);
				Cpass_Lighten(4);
				if(pos1==1&&pos2==1&&pos3==1&&line>=1&&line<=3&&date>=1&&date<=7&&num>=1&&num<=51)
				{
					setfillstyle(1,GREEN);
		            bar(175,295+12,500,344+12);
		            puthz(265,320+12,"���ڲ�ѯ",24,24,LIGHTGRAY);
					delay(1000);
					Cpass_Search(a,date,line,num);//printf("%d,%d,%d,%d,%d",&a[0],&a[1],&a[2],&a[3],&a[4]);getchar();
					/*for(i=0;i<20;i++)
					{
						printf("%d,",a[i]);
					}
					getchar();*/
					Passcheck(a,&page);
					break;
				}
				else
				{
					setfillstyle(1,GREEN);
		            bar(175,295+12,500,344+12);
		            puthz(265,320+12,"��ѯʧ��",24,24,LIGHTGRAY);
					delay(1000);
					Draw_Cpass();
					continue;
				}
			}
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
				*page=6;
				break;
			}
		}
		if(flag!=0)
		{
			MouseS=0;
			clrmous(MouseX,MouseY);
			Cpass_Darken();
			flag=0;
		}
		if(MouseS!=0)
		{
			MouseS=0;
		}
	}
	
}
/*
FUNCTION:Draw_Cpass
DESCRIPTION:��ͼ
INPUT:��
RETURN:��
*/
int Draw_Cpass()
{
	
	cleardevice();
    
	cover(1,1,639,479,WHITE);
	
	highlight(40,20,600,80,GREEN);
	puthz(50,25,"֧�ֲ�ѯǰ���յĳ���",24,24,BLUE);
	puthz(50,50,"ÿ����Ӫʱ��Ϊ������ʮһ�㣬ÿ����ʮ���ӷ���",24,24,BLUE);
	cover(226, 358.75, 226 + 187, 358.75 + 60.5, LIGHTGRAY);
	highlight(226, 358.75, 226 + 187, 358.75 + 60.5, YELLOW);
	puthz(247, 376.75, "�鿴�����˿�", 24, 24.5, BLUE);
	
	draw_exit(525, 450, LIGHTGRAY,BROWN,DARKGRAY,GREEN);
	puthz(220,100,"��",48,48,DARKGRAY);
	puthz(340,100,"��",48,48,DARKGRAY);
	puthz(480,100,"��",48,48,DARKGRAY);
	puthz(300,180,"����",48,48,DARKGRAY);
	puthz(300,260,"����",48,48,DARKGRAY);
	settextjustify(0, 2);
	settextstyle(3, 0, 6);
	outtextxy(80,90,"2022");
	outtextxy(300,90,"4");
	setcolor(LIGHTGRAY);
	cover(390,100,475,150,LIGHTGRAY);
	highlight(390,100,475,150,GREEN);
	cover(240,180,295,230,LIGHTGRAY);
	highlight(240,180,295,230,GREEN);
	cover(240,260,295,310,LIGHTGRAY);
	highlight(240,260,295,310,GREEN);
	
}
/*
FUNCTION:Cpass_Lighten()
DESCRIPTION:����
INPUT:flag
RETURN:NO
*/
int Cpass_Lighten(int flag)
{
	switch(flag)
	{
		case 1:
			highlight(226, 358.75, 226 + 187, 358.75 + 60.5, YELLOW);
			cover(226, 358.75, 226 + 187, 358.75 + 60.5,DARKGRAY);
			puthz(247, 376.75, "�鿴�����˿�", 24, 24.5, BLUE);
			break;
		case 2:
			cover(390,100,475,150,DARKGRAY);
			highlight(390,100,475,150,GREEN);
			break;
		case 3:
			cover(240,180,295,230,DARKGRAY);
			highlight(240,180,295,230,GREEN);
			break;
		case 4:
			cover(240,260,295,310,DARKGRAY);
			highlight(240,260,295,310,GREEN);
			break;
	}
}

/*
FUNCTION:Cpass_Darken
DESCRIPTION:�ָ�
INPUT:flag
RETURN:NO
*/
void Cpass_Darken()
{
			
	cover(226, 358.75, 226 + 187, 358.75 + 60.5, LIGHTGRAY);
	highlight(226, 358.75, 226 + 187, 358.75 + 60.5, YELLOW);
	puthz(247, 376.75, "�鿴�����˿�", 24, 24.5, BLUE);
	
	/*cover(390,100,475,150,LIGHTGRAY);
	highlight(390,100,475,150,GREEN);
	
	cover(240,180,295,230,LIGHTGRAY);
	highlight(240,180,295,230,GREEN);
	
	cover(240,260,295,310,LIGHTGRAY);
	highlight(240,260,295,310,GREEN);*/
}
/*
FUNCTION:Cpass_Search
DESCRIPTION:���ҹ����˿ʹ���
INPUT:�����˿ʹ�������a������week,��·line������num
RETURN:����amount
*/
int Cpass_Search(int* a,int week,int line,int num)
{
	int flag=0;
	FILE* fp;
	int i=0;
	int amount=0;
	//char tool[30]; //��������Ҫ���ַ���
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
			
				if(week==r->week)
				{
					if(CLine_Search(r->origin,r->transfer)==line||CLine_Search(r->terminal,r->transfer))
					{
						if(line==1)
						{
							if(r->subway_number[0]==num)
							{
								a[i]=r->number;amount++;
								i++;
							}
						}
						else if(line==2)
						{
							if(r->subway_number[1]==num)
							{
								a[i]=r->number;amount++;
								i++;
							}
						}
						else if(line==3)
						{
							if(r->subway_number[2]==num)
							{
								a[i]=r->number;amount++;
								i++;
							}
						}
					}
				}
			if(i>=19)
			{
				break;
			}
			if(r!=NULL)
			{
				free(r);
				r=NULL;
			}
		}
	
	if (fclose(fp) != 0)
	{
		printf("\nError on close record.dat!");
		delay(3000);
		exit(1);
	}
	//printf("%d\n",amount);getchar();
	//return amount;
}



int CLine_Search(int a,int b)
{
	if(a>0&&a<7&&b>0&&b<7)
	{
		return 1;
	}
	

    if((a==2||(a>6&&a<13))&&(b==2||(a>6&&a<13)))
	{
		return 2;
	}
	

    else 
	{
		return 3;
	}
}
/*
FUNCTION:Passcheck
DESCRIPTION:�鿴ȷ�ﻼ�߹���
INPUT:�˿ʹ�������a��page
RETURN:NO
*/
void Passcheck(int* a,int* page)
{
	int flag=0; //��ǵ������
	int all=0; //��¼�ܳ˿���
	int func=0; //��¼һ������ҳ
	int now=1; //��¼��ǰҳ��
	int i;
	char f[3]={"\0"}; //��ҳ��
	char n[3]={"\0"}; //��ǰҳ��
	//int a[10]={0}; //��¼ȷ��˿ʹ���
	char* ID[4]={"\0","\0","\0","\0"}; //�洢��ǰҳȷ֤�˿͵����֤��
	PATIENT P[20];
	
	clrmous(MouseX,MouseY);
	delay(100);
	save_bk_mou(MouseX,MouseY);
	
	for(i=0;i<20;i++)
	{
		P[i].count=0;
	}
	Draw_Patient(); //���ƻ���
	all=Patient_Get(a,P); //��ȡȷ��˿���Ϣ
	//printf("amount=%d",all);
	if(P[0].count==0) //���û�л�ȡ���κγ˳���¼�����������ʾ
	{
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
        setfillstyle(SOLID_FILL, WHITE);
        bar(200,180,440,300);
        rectangle(200,180,440,300);
        setfillstyle(SOLID_FILL, WHITE);
		puthz(274,230,"������Ϣ",24,24,RED);
		delay(3000);
		*page=62; //������������������
		Draw_Cpass();
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
				*page=6;
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