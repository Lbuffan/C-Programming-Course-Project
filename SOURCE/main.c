#include"public.h"
#include"login.h"
#include"plogin.h"
#include"alogin.h"
#include"register.h"
/*
FUNCTION:main
DESCRIPTION:ʵ��ҳ����ת
INPUT:no
RETURN:no
*/
void main()
{
	int page=6;//ҳ����ת����
	int ad=0; //�жϹ���Ա��ݣ�1Ϊ�������ţ�2Ϊ��������
	int identity=0; //��¼��¼�˿͵����	 
	int gd=VGA;
	int gm=VGAHI;
	ADMINISTRATOR AD[2];
	Scan_A(AD); //�������Ա��Ϣ
	//printf("hi\n");
	initgraph(&gd,&gm,"C:\\BORLANDC\\BGI");
	cleardevice();
	//welcome();//��ӭҳ�� 
	//Build_State();
	//delay(1000);  
	mouseinit();//����ʼ�� 
	while(1)//ҳ����ת
	{
		switch (page)
		{
			case 0://��¼����
				Login(&page,&ad);
				break;
			case 1://�˿͵�¼����
				Plogin(&page,&identity);
				break;
			case 2://����Ա��¼
				Alogin(&page,ad,AD);  
				break;
			case 3:  //ע�����
			    Register(&page);  
				break;
			case 5: //�˿͵�¼����
			    Pass(&page,identity);      
				break;
			case 51: //�˿Ͳ鿴�켣
				pass1(&page,identity);
				break;
			case 6://��·���Ž���
			    railway(&page);
				break;
			case 61: //�鿴�����г�
			    Checksub(&page);
				break;
			case 62: //���ҹ����˿�
				Cpass(&page);
				break;
			case 7://�������Ž���
				Weisheng(&page);
				break;
			case 71://��ǻ��߽���
				Sign(&page);
				break;
			case 72://�鿴����
				Patient(&page);
				break;
			case 73: //�鿴�ܽ�
				Connect(&page);
				break;
		}
		
	}
	
}

