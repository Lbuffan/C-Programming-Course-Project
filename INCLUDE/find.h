#ifndef _ptpass_h_
#define _ptpass_h_

void Find(struct Record* r);
int Draw_Find();
int Find_Lighten(int flag);
int Patient_Darken(int flag);
int Find_Search(struct Record* r,int* a);
int Find_Tag(int* a);
int Find_Get(int* a,struct Record* C);
int Find_Show(struct Record* C,int now,char* ID1,char* ID2,char* ID3,char* ID4);
int Find_Display(struct Record c,int i);
#endif