#ifndef _ptpass_h_
#define _ptpass_h_

void Checksub(int* page);
int Checksub_Search(int* a);
struct Train* Checksub_Get(int* a);
int Checksub_Delete(TRAIN* phead);
int Draw_Checksub();
int Checksub_Show(struct Train* train);
int Checksub_Lighten(int flag);
int Checksub_Darken(int flag);
int Line_Search(int a,int b);

#endif