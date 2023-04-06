#ifndef _plogin_h_
#define _plogin_h_

void Plogin(int* page,int* identity);
int Draw_Plogin();
int Plogin_Lighten(int x1,int y1,int x2,int y2,int flag);
int Plogin_Darken(int pos);
int Jundge_Plogin(char* account, char* password,int* id);
#endif