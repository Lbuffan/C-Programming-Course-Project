#ifndef _pass_h_
#define _pass_h_
void pass1(int* page,int identity);
int Pass_Record_Get(int n,struct Record* R);
int Pass1_Lighten(int flag);
void Pass1_Darken();
void Draw_pass1();
int Draw_Subnum(struct Record *r);
int Show_Record(struct Record *r);
int Show_Pass(RECORD *r,int *page,int identity);
#endif