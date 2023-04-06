#ifndef _ALOGIN_H_
#define _ALOGIN_H_

void Alogin(int *page,int ad,ADMINISTRATOR *AD);
int Draw_Alogin1();
int Draw_Alogin2();
int Alogin_Lighten(int x1,int y1,int x2,int y2,int flag);
int Alogin_Darken(int pos);
int Alogin_Com(struct Administrator* A,char* account,char* password,char unit);

#endif