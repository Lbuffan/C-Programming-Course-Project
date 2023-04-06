#ifndef _patient_h_
#define _patient_h_

void Patient(int* page);	//实现查看患者功能
int Draw_Patient();		//绘制查看患者界面
int Patient_Cover();	//遮盖
int Patient_Lighten(int flag);		//点亮
int Patient_Darken(int flag);		//恢复
int Patient_Search(int* a);		//查找确诊者代号
int Patient_Get(int* a,struct Patient* p);		//获取确诊信息
int Patient_Show(int now,struct Patient* P,char** ID);		//显示确诊者信息
#endif