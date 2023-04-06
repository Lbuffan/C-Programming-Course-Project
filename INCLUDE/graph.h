#ifndef _graph_H_
#define _graph_H_
void cover(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color);//画有颜色的矩形框
void highlight(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color);//画眼颜色矩形边框
void stablack(int x, int y, int r);//画黑色圆圈
void linebetweensta(int x1, int y1, int x2, int y2, int color);//站点间连线
void frame(int x1, int y1, int x2, int y2, int r, int color, int bk);//画一个宽度为r的方框
void triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color);//画一个三角形
void ring(int x, int y, int r2, int r1, int color, int bk, int style);//画一个圆圈
void draw_exit(int x, int y, int bk, int hzcolor, int fmcolor, int tr);//画退出系统
void draw_refresh(int x, int y, int bk, int hzcolor, int fmcolor, int tr);//画重新载入
#endif