#include"public.h"
#include"welcome.h"
/*function:welcome
input:no
return:no
*/
void welcome()
{
	setbkcolor(LIGHTGRAY);

	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(LIGHTGRAY);
	circle(320,200,50);
	setcolor(WHITE);
	floodfill(315,205,LIGHTGRAY);
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	bar(320-30,200-30,320+30,200+30);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	bar(320-25,200-25,320+25,200);
	setfillstyle(1,WHITE);
	pieslice(320-18,200+20,0,360,5);
	pieslice(320+18,200+20,0,360,5);
	puthz(170,300,"公共交通乘客行程系统",32,32,GREEN);
	puthz(268,360,"欢迎使用",24,24,WHITE);
	 

	setcolor(WHITE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
	outtextxy(250,60,"WELCOME");
	outtextxy(255,30,"SUBWAY");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	outtextxy(320,410," AIA 2108 LYF and XZX");
	delay(3000);
}
/*function:bye
input：no
output:no
*/
void bye()
{
	cleardevice();
	
	setbkcolor(LIGHTGRAY);

	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	setcolor(LIGHTGRAY);
	circle(320,200,50);
	setfillstyle(SOLID_FILL, WHITE);
	setcolor(WHITE);
	floodfill(315,205,LIGHTGRAY);
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	bar(320-30,200-30,320+30,200+30);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	bar(320-25,200-25,320+25,200);
	setfillstyle(1,WHITE);
	pieslice(320-18,200+20,0,360,5);
	pieslice(320+18,200+20,0,360,5);
	puthz(170,300,"公共交通乘客行程系统",32,32,GREEN);
	puthz(268,360,"感谢使用",24,24,WHITE);
	puthz(279,410,"再见！",32,32,GREEN);
	 

	setcolor(WHITE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
	outtextxy(280,60,"BYE");
	outtextxy(255,30,"SUBWAY");
	delay(1500);
}



