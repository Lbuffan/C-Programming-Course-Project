#ifndef _check_h_
#define _check_h_

void Patient_Check(char* ID); //�鿴�˳���¼
int Draw_Patient_Check(); //��ͼ
int Patient_Identity_Get(char* ID,char* name); //��ȡ��Ϣ
int Record_Get(int n,struct Record* R);
int Patient_Record(struct Record *r); //�����Ϣ
int Draw_Subwaynumber(struct Record *r);
#endif