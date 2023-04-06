#ifndef _check_h_
#define _check_h_

void Patient_Check(char* ID); //查看乘车记录
int Draw_Patient_Check(); //绘图
int Patient_Identity_Get(char* ID,char* name); //获取信息
int Record_Get(int n,struct Record* R);
int Patient_Record(struct Record *r); //输出信息
int Draw_Subwaynumber(struct Record *r);
#endif