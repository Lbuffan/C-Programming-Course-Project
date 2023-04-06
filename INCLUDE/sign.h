#ifndef _sign_h_
#define _sign_h_

void Sign(int *page);	//实现标记患者功能
int Draw_Sign();	//绘制界面
int Sign_Lighten(int flag);		//点亮
int Sign_Darken(int flag);		//恢复
int Sign_ID_Judge(char *I);		//判断身份证格式
void Sign2(int* page,char* I,int pos2);	//保存界面
int Draw_Sign2(int pos2);		//绘制保存界面
int Sign_Check_Jundge(int n,int pos2, int* page);		//判断操作是否符合要求
int Sign_Check_Save(int n,int pos2);	 //保存确诊患者的标记或取消标记 

#endif