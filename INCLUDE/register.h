#ifndef _register_h_
#define _register_h_

void Register(int* page); //实现注册界面功能
int Draw_Register(); //绘制注册界面
int Register_Lighten(int x1,int y1,int x2,int y2,int flag); //实现注册界面操作框点亮
int Register_Darken(int pos); //实现注册界面操作框恢复
int R_Account_Jundge(char* A); //注册输入账号判断
int R_Password_Jundge(char* P); //注册输入密码判断
int R_Password_Same(char* P,char* RP); //注册确认密码判断
int R_ID_Jundge(char* I); //注册身份证号判断
void R_Input_Data(char* A,char* I,char* P,int jun4); //注册信息写入文件
int Register_Com(int jun1,int jun2,int jun3,int jun4,char* A,char* I,char* P); //完成注册

#endif