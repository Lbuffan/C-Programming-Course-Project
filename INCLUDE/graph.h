#ifndef _graph_H_
#define _graph_H_
void cover(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color);//������ɫ�ľ��ο�
void highlight(int lefttop_x, int lefttop_y, int rightbottom_x, int rightbottom_y, int color);//������ɫ���α߿�
void stablack(int x, int y, int r);//����ɫԲȦ
void linebetweensta(int x1, int y1, int x2, int y2, int color);//վ�������
void frame(int x1, int y1, int x2, int y2, int r, int color, int bk);//��һ�����Ϊr�ķ���
void triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color);//��һ��������
void ring(int x, int y, int r2, int r1, int color, int bk, int style);//��һ��ԲȦ
void draw_exit(int x, int y, int bk, int hzcolor, int fmcolor, int tr);//���˳�ϵͳ
void draw_refresh(int x, int y, int bk, int hzcolor, int fmcolor, int tr);//����������
#endif