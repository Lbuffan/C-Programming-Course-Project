#ifndef _data_h_
#define _data_h_

typedef struct Passenger { //乘客信息
	int number; //乘客代号
	char name[10]; //乘客姓名
	char ID[20]; //乘客身份证号
	char telephone[15]; //乘客电话号码
	char sex[5]; //乘客性别
	char age[5]; //乘客年龄
}PASSENGER;

typedef struct State{ //乘客涉疫情况
	int number; //乘客代号
	int patient; //确诊情况，0为未确诊，1为无症状，2为有症状
	int contact; //密接情况，0为正常，1为密切接触者
	int deal; //密接处理情况，0为未处理，1为已处理
	int find; //密接联络情况，0为未联络，1为已联络
}STATE;
 
typedef struct Administrator{ //管理员信息
	char unit; //管理员所属单位，1为检测机构，2为卫健委，3为铁路
	char account[9]; //管理员账号 
	char password[9]; //管理员密码 
}ADMINISTRATOR;            

typedef struct User{ //用户信息
    int number; //用户乘客代号
    char ID[20]; //用户身份证号
	char account[15]; //用户账号
	char password[15]; //用户密码
}USER;

typedef struct Record{ //乘车记录
	
	int contact; //乘车记录代号
	int number; //乘客代号
	char name[10]; //姓名
	char telephone[13];
	char ID[20];
	char age[3];
	char sex[4];
	int origin; //起始站代号
	int transfer; //中转站代号
	int terminal; //终点站代号
	int week; //第几天
	int subway_number[3]; //车次
}RECORD; 

typedef struct Train{ //列车信息
	int origin; //列车起始站 
	int transfer;
	int terminal; //列车终点站
	int line;
	int time;
	int week;
	struct Train* front; //指向上一个节点的指针
	struct Train* next; //指向下一个节点的结构指针
}TRAIN;

typedef struct Patient{ //确诊乘客信息
    int patient; //乘客确诊类型，1为无症状，2为有症状
	int number; //乘客代号
	int count; //确诊乘客中的序号
	char name[10]; //乘客姓名
	char ID[20]; //乘客身份证号
	char telephone[15]; //乘客电话号码
	char sex[5]; //乘客性别
	char age[5];//乘客年龄
	struct Patient* front; //指向上一个节点的指针           
	struct Patient* next; //指向下一个节点的指针
}PATIENT;

typedef struct station{
	int x;
	int y;
    } Station;
#endif   