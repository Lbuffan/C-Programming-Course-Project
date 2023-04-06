#include"public.h"
#include"graph.h"
void cover(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color)//画有颜色的矩形框*
{
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	bar(lefttop_x, lefttop_y, rightbottom_x, rightbottom_y);
}


void highlight(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color)//画眼颜色矩形边框
{
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(color);
	rectangle(lefttop_x, lefttop_y, rightbottom_x, rightbottom_y);
}
//画填充了黑色的圆圈
void stablack(int x, int y, int r)
{
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	pieslice(x, y, 0, 360, r);
	setcolor(BLACK);
	line(x, y, x + r, y);
}
//画站点之间的连线
void linebetweensta(int x1, int y1, int x2, int y2, int color)
{
	setcolor(color);
	setlinestyle(0, 0, 3);
	line(x1 + 1, y1, x2 + 1, y2);
	setlinestyle(0, 0, 3);
	line(x1 - 1, y1, x2 - 1, y2);
}
//画一个宽度为r的方框
void frame(int x1, int y1, int x2, int y2, int r, int color, int bk)
{
	cover(x1, y1, x2, y2, color);
	cover(x1 + r, y1 + r, x2 - r, y2 - r, bk);
}

//画一个三角形(未填充颜色)
void triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
	setcolor(color);
	line(x1, y1, x2, y2);
	line(x1, y1, x3, y3);
	line(x2, y2, x3, y3);
}
//画一个圆环
void ring(int x, int y, int r2, int r1, int color, int bk, int style)
{
	int i;
	int w = 2;
	if (style == 2)
	{
		setcolor(bk);
		setfillstyle(1, color);
		pieslice(x, y, 0, 360, r2);
		setcolor(color);
		line(x, y, x + r2-2, y);
		setfillstyle(1, bk);
		pieslice(x, y, 0, 360, r1);
		setcolor(bk);
		line(x, y, x + r1-2, y);
		setfillstyle(1, color);
		if((color != GREEN)&&(r1 > 45))
		{
			setcolor(color);
			for(i = r2-w;i<=(r2+w);i++)
			{
				setcolor(color);
				setlinestyle(0,0,3);
				circle(x , y, i);
			}
		}
	}
	if (style == 1)
	{
		setfillstyle(1, bk);
		setcolor(color);
		circle(x, y, r2);
		floodfill(x, y, color);
		circle(x, y, r1);
		floodfill(x, y, bk);
	}

}
//画一个退出系统的标志
void draw_exit(int x, int y, int bk, int hzcolor, int fmcolor, int tr)
{
	int a;
	int b;
	int m, n;
	highlight(x - 5, y - 3, x + 100, y + 17, fmcolor);
	puthz(x, y, "点击退出", 16, 18, hzcolor);
	a = 18 * 4 + x + 2;
	b = y;
	frame(a, b, a + 12, b + 16, 4, fmcolor, bk);
	cover(a + 6, b + 6, a + 15, b + 10, tr);
	m = a + 15;
	n = b + 8;
	triangle(m, b, m, b + 16, m + 7, n, tr);
}
//画一重新载入的标志
void draw_refresh(int x, int y, int bk, int hzcolor, int fmcolor, int tr)
{
	int a, b, r;
	highlight(x - 5, y - 3, x + 100, y + 17, fmcolor);
	puthz(x, y, "重新载入", 16, 18, hzcolor);
	a = 18 * 4 + x + 2;
	b = y + 1;
	r=8;
	ring(a + r, b + r, r, r - 2, tr, bk, 2);
	cover(a + r, b + r - 2, a + 2 * r, b + r + 5, bk);
	triangle(a + 1.3 * r, b + 0.3 * r, a + 2.1 * r, b + 0.3 * r, a + 1.7 * r, b + r, tr);
    
}
void map()
{
	cleardevice();
	setbkcolor(LIGHTGRAY);
	
	linebetweensta(30, 200, 100, 200, YELLOW);//涓�鍙风嚎
	linebetweensta(100, 200, 170, 200, YELLOW);
	linebetweensta(170,200,240,200,YELLOW);
	linebetweensta(240, 200, 310, 200, YELLOW);
	linebetweensta(310, 200, 380, 200, YELLOW);
	
	linebetweensta(310, 30, 310, 100, YELLOW);//浜屽彿绾?
	linebetweensta(310, 100, 310, 180, YELLOW);
	linebetweensta(310, 150, 310, 270, YELLOW);
	linebetweensta(310,200,310,270,YELLOW);
	linebetweensta(310,270,310,350,YELLOW);
	linebetweensta(310, 350, 310, 410, YELLOW);
	
	linebetweensta(170,100,170,180,YELLOW);//涓夊彿绾?
	linebetweensta(170,150,170,270,YELLOW);
	linebetweensta(170, 200, 170, 270, YELLOW);
	linebetweensta(170, 270, 170, 350, YELLOW);
	linebetweensta(170, 350, 170, 410, YELLOW);
	linebetweensta(170, 410, 170, 455, YELLOW);

	ring(30, 200, 5, 10, GREEN, YELLOW, 1);//涓�鍙风嚎
	ring(100, 200, 5, 10, GREEN, YELLOW, 1);
	ring(170, 200, 5, 10, GREEN, YELLOW, 1);
	ring(240, 200, 5, 10, GREEN, YELLOW, 1);
	ring(310, 200, 5, 10, GREEN, YELLOW, 1);
	ring(380, 200, 5, 10, GREEN, YELLOW, 1);



	ring(310, 30, 5, 10, GREEN, YELLOW, 1);//浜屽彿绾?
	ring(310, 100, 5, 10, GREEN, YELLOW, 1);
	ring(310, 150, 5, 10, GREEN, YELLOW, 1);
	ring(310, 200, 5, 10, GREEN, YELLOW, 1);
	ring(310, 270, 5, 10, GREEN, YELLOW, 1);
	ring(310, 350, 5, 10, GREEN, YELLOW, 1);
	ring(310, 410, 5, 10, GREEN, YELLOW, 1);

	ring(170, 100, 5, 10, GREEN, YELLOW, 1);//涓夊彿绾?
	ring(170, 150, 5, 10, GREEN, YELLOW, 1);
	ring(170, 200, 5, 10, GREEN, YELLOW, 1);
	ring(170, 270, 5, 10, GREEN, YELLOW, 1);
	ring(170, 350, 5, 10, GREEN, YELLOW, 1);
	ring(170, 410, 5, 10, GREEN, YELLOW, 1);
	ring(170, 455, 5, 10, GREEN, YELLOW, 1);
	
	puthz(15,215,"泾河",16,16,DARKGRAY);
	puthz(70,215,"五环大道",16,16,DARKGRAY);
	puthz(180,210,"宗关",16,16,DARKGRAY);
	puthz(220,215,"崇仁路",16,16,DARKGRAY);
	puthz(320,210,"循礼门",16,16,DARKGRAY);
	puthz(390,210,"汉口北",16,16,DARKGRAY);
	
	puthz(325,23,"天河机场",16,16,DARKGRAY);
	puthz(325,93,"巨龙大道",16,16,DARKGRAY);
	puthz(325,143,"金谭路",16,16,DARKGRAY);
	puthz(325,263,"江汉路",16,16,DARKGRAY);
	puthz(325,343,"光谷广场",16,16,DARKGRAY);
	puthz(325,403,"佛祖岭",16,16,DARKGRAY);
	
	puthz(108,93,"罗家庄",16,16,DARKGRAY);
	puthz(108,143,"云飞路",16,16,DARKGRAY);
	puthz(108,263,"龙阳村",16,16,DARKGRAY);
	puthz(108,343,"陶家岭",16,16,DARKGRAY);
	puthz(108,403,"三角湖",16,16,DARKGRAY);
	puthz(92,448,"沌阳大道",16,16,DARKGRAY);
	
	puthz(310-20, 410+40,"三号线",16,16,BLUE);
	puthz(400,180, "一号线", 16, 16, BLUE);
	puthz(170-30,100-30,"二号线",16,16,BLUE);

}

//行高25选项输入框
//输出坐标为(x-2,y-1,x-2 + n * 25 + 4,y+24)的矩形区域
void search_choose_enter_24bk(int x, int y, int n, int b, int h)
{
	int length, x2, y2, x1, y1;
	length = n * 25 + 4;
	x1 = x - 2;
	y1 = y - 1;
	x2 = x1 + length;
	y2 = y + 24;
	cover(x1, y1, x2, y2, b);
	highlight(x1, y1, x2+1, y2+1, h);
}

//行高20选项文字框
//输出坐标为(x-2,y-2,x-2 + n * 17 + 4,y+18)的矩形区域
void search_choose_words_bk(int x, int y, int n, int h, int b)
{
	int length, x2, y2, x1, y1;
	length = n * 17 + 4;
	x1 = x - 2;
	y1 = y - 2;
	x2 = x1 + length;
	y2 = y + 18;
	cover(x1, y1, x2, y2, b);
	highlight(x1, y1, x2, y2, h);
}

void DOThighlight(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color)
{
	setcolor(color);
	setlinestyle(1, 0, 3);
	rectangle(lefttop_x, lefttop_y, rightbottom_x, rightbottom_y);
}