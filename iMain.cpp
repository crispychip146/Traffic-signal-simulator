#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#pragma comment(lib, "winmm.lib")
int moux, mouy;
/*char car_up[16][32]={"Cars\\car 1\\up.bmp","Cars\\car 2\\up.bmp","Cars\\car 3\\up.bmp","Cars\\car 4\\up.bmp"};
char car_down[16][32]={"Cars\\car 1\\down.bmp","Cars\\car 2\\down.bmp","Cars\\car 3\\down.bmp","Cars\\car 4\\down.bmp"};
char car_right[16][32]={"Cars\\car 1\\right.bmp","Cars\\car 2\\right.bmp","Cars\\car 3\\right.bmp","Cars\\car 4\\right.bmp"};
char car_left[16][32]={"Cars\\car 1\\left.bmp","Cars\\car 2\\left.bmp","Cars\\car 3\\left.bmp","Cars\\car 4\\left.bmp"};
*/
int carcoordinateX;
int carcoordinateY;
int carindex;
int n1 = 1;
int gamestate = -1;
int laneroad4x[8] = {345, 400, 450, 500, -50, -50, 900, 900};
int laneroad4y[8] = {-50, -50, 750, 750, 375, 430, 320, 275};
int laneroad4z[8] = {0, 0, 2, 2, 3, 3, 1, 1}; // 0:up 1:left  2:down  3:right
int laneroad6x[12] = {315, 365, 410, 900, 900, 900, 545, 495, 450, -50, -50, -50};
int laneroad6y[12] = {-50, -50, -50, 235, 280, 335, 750, 750, 750, 475, 425, 380};
int laneroad6z[12] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3};
/*int lane1x = 345, lane1y = 5, lane1z = 0;
int lane2x = 400, lane2y = 5, lane2z = 0;
int lane3x = 450, lane3y = 750, lane3z = 2;
int lane4x = 500, lane4y = 750, lane4z = 2;
int lane11x = 5, lane11y = 375, lane11z = 3;
int lane12x = 5, lane12y = 430, lane12z = 3;
int lane21x = 900, lane21y = 320, lane21z = 1;
int lane22x = 900, lane22y = 275, lane22z = 1;*/
char car_1[16][32] = {"Cars\\car 1\\up.bmp", "Cars\\car 1\\left.bmp", "Cars\\car 1\\down.bmp", "Cars\\car 1\\right.bmp"};
char car_2[16][32] = {"Cars\\car 2\\up.bmp", "Cars\\car 2\\left.bmp", "Cars\\car 2\\down.bmp", "Cars\\car 2\\right.bmp"};
char car_3[16][32] = {"Cars\\car 3\\up.bmp", "Cars\\car 3\\left.bmp", "Cars\\car 3\\down.bmp", "Cars\\car 3\\right.bmp"};
char car_4[16][32] = {"Cars\\car 4\\up.bmp", "Cars\\car 4\\left.bmp", "Cars\\car 4\\down.bmp", "Cars\\car 4\\right.bmp"};
char car_round_1[16][32] = {"Cars\\car 1\\left1.bmp", "Cars\\car 1\\right1.bmp", "Cars\\car 1\\left2.bmp", "Cars\\car 1\\right2.bmp"};
char car_round_2[16][32] = {"Cars\\car 2\\left1.bmp", "Cars\\car 2\\right1.bmp", "Cars\\car 2\\left2.bmp", "Cars\\car 2\\right2.bmp"};
char car_round_3[16][32] = {"Cars\\car 3\\left1.bmp", "Cars\\car 3\\right1.bmp", "Cars\\car 3\\left2.bmp", "Cars\\car 3\\right2.bmp"};
char car_round_4[16][32] = {"Cars\\car 4\\left1.bmp", "Cars\\car 4\\right1.bmp", "Cars\\car 4\\left2.bmp", "Cars\\car 4\\right2.bmp"};
char menu[120][100] = {"menu1\\100001.jpg", "menu1\\100002.jpg", "menu1\\100003.jpg", "menu1\\100004.jpg", "menu1\\100005.jpg", "menu1\\100006.jpg", "menu1\\100007.jpg", "menu1\\100008.jpg", "menu1\\100009.jpg", "menu1\\100010.jpg", "menu1\\100011.jpg", "menu1\\100012.jpg", "menu1\\100013.jpg", "menu1\\100014.jpg", "menu1\\100015.jpg", "menu1\\100016.jpg", "menu1\\100017.jpg", "menu1\\100018.jpg", "menu1\\100019.jpg", "menu1\\100020.jpg", "menu1\\100021.jpg", "menu1\\100022.jpg", "menu1\\100023.jpg", "menu1\\100024.jpg", "menu1\\100025.jpg", "menu1\\100026.jpg", "menu1\\100027.jpg", "menu1\\100028.jpg", "menu1\\100029.jpg", "menu1\\100030.jpg", "menu1\\100031.jpg", "menu1\\100032.jpg", "menu1\\100033.jpg", "menu1\\100034.jpg", "menu1\\100035.jpg", "menu1\\100036.jpg", "menu1\\100037.jpg", "menu1\\100038.jpg", "menu1\\100039.jpg", "menu1\\100040.jpg", "menu1\\100041.jpg", "menu1\\100042.jpg", "menu1\\100043.jpg", "menu1\\100044.jpg", "menu1\\100045.jpg", "menu1\\100046.jpg", "menu1\\100047.jpg", "menu1\\100048.jpg", "menu1\\100049.jpg", "menu1\\100050.jpg", "menu1\\100051.jpg", "menu1\\100052.jpg", "menu1\\100053.jpg", "menu1\\100054.jpg", "menu1\\100055.jpg", "menu1\\100056.jpg", "menu1\\100057.jpg", "menu1\\100058.jpg", "menu1\\100059.jpg", "menu1\\100060.jpg", "menu1\\100061.jpg", "menu1\\100062.jpg", "menu1\\100063.jpg", "menu1\\100064.jpg", "menu1\\100065.jpg", "menu1\\100066.jpg", "menu1\\100067.jpg", "menu1\\100068.jpg", "menu1\\100069.jpg", "menu1\\100070.jpg", "menu1\\100071.jpg", "menu1\\100072.jpg", "menu1\\100073.jpg", "menu1\\100074.jpg", "menu1\\100075.jpg", "menu1\\100076.jpg", "menu1\\100077.jpg", "menu1\\100078.jpg", "menu1\\100079.jpg", "menu1\\100080.jpg", "menu1\\100081.jpg", "menu1\\100082.jpg", "menu1\\100083.jpg", "menu1\\100084.jpg", "menu1\\100085.jpg", "menu1\\100086.jpg", "menu1\\100087.jpg", "menu1\\100088.jpg", "menu1\\100089.jpg", "menu1\\100090.jpg", "menu1\\100091.jpg", "menu1\\100092.jpg", "menu1\\100093.jpg", "menu1\\100094.jpg", "menu1\\100095.jpg", "menu1\\100096.jpg", "menu1\\100097.jpg", "menu1\\100098.jpg", "menu1\\100099.jpg", "menu1\\100100.jpg", "menu1\\100101.jpg", "menu1\\100102.jpg", "menu1\\100103.jpg", "menu1\\100104.jpg", "menu1\\100105.jpg", "menu1\\100106.jpg", "menu1\\100107.jpg", "menu1\\100108.jpg", "menu1\\100109.jpg", "menu1\\100110.jpg", "menu1\\100111.jpg", "menu1\\100112.jpg", "menu1\\100113.jpg", "menu1\\100114.jpg", "menu1\\100115.jpg", "menu1\\100116.jpg", "menu1\\100117.jpg", "menu1\\100118.jpg", "menu1\\100119.jpg", "menu1\\100120.jpg"};
int roundx[4] = {390, 950, 460, -50};
int roundy[4] = {-50, 325, 750, 380};
int roundz[4] = {0, 1, 2, 3}; // 0:up 1:left  2:down  3:right// 0:left1  1:right1   2:left2  3:right2
int flag[4] = {0, 0, 0, 0};
int mouse_x, mouse_y;
bool music = true;
int idx = 0;
int r, g, b;
int color_r[5] = {0, 255, 255, 255};
int color_g[5] = {255, 0, 0, 0};
int color_b[5] = {0};
int n[12];
int i = 0;
bool x[8] = {false};
void change()
{
	if (idx < 118 && gamestate == -1)
		idx++;
	else if (idx == 118)
	{
		gamestate = 0;
		idx = 0;
	}
}
void menu1()
{
	iShowBMP(0, 0, menu[idx]);
}
void random()
{
	for (int i = 0; i < 12; i++)
	{
		n[i] = rand() % 4 + 1;
	}
}
void timerFunction()
{
	if (color_r[i] == 0 && color_g[i] == 255)
	{
		int n = i + 1;
		if (i + 1 == 4)
			n = 0;
		color_r[n] = 0;
		color_g[n] = 255;
		color_r[i] = 255;
		color_g[i] = 0;
	}
	i++;
	if (i == 4)
	{
		i = 0;
	}
}
void carlane1move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary <= 160)
		(*cary) += 2;
	if (*cary >= 160 && *cary <= 175)
	{
		if (x[0] == true)
			*cary += 2;
	}
	if (*cary >= 175 && *cary < 260)
		*cary += 2;
	if (*cary >= 260)
	{
		*caridx = 1;
		*carx -= 2;
	}
}
void carlane2move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary <= 160)
		(*cary) += 2;
	if (*cary >= 160 && *cary <= 175)
	{
		if (x[0] == true)
			*cary += 2;
	}
	if (*cary <= 750 && *cary >= 175)
	{
		*cary += 2;
	}
}
void carlane3move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary >= 505)
		(*cary) -= 2;
	if (*cary >= 490 && *cary <= 505)
	{
		if (x[2] == true)
			*cary -= 2;
	}
	if (*cary > -55 && *cary <= 490)
	{
		*cary -= 2;
	}
}
void carlane4move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary >= 505)
		(*cary) -= 2;
	if (*cary >= 490 && *cary <= 505)
	{
		if (x[2] == true)
			*cary -= 2;
	}
	if (*cary <= 490 && *cary > 420)
		*cary -= 2;
	if (*cary <= 420)
	{
		*caridx = 3;
		*carx += 2;
	}
}
void carlane11move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx <= 240)
		*carx += 2;
	if (*carx >= 240 && *carx <= 265)
	{
		if (x[3] == true)
			*carx += 2;
	}
	if (*carx > 265 && *carx < 900)
	{
		*carx += 2;
	}
}
void carlane12move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx <= 240)
		*carx += 2;
	if (*carx >= 240 && *carx <= 265)
	{
		if (x[3] == true)
			*carx += 2;
	}
	if (*carx >= 265 && *carx < 350)
	{
		*carx += 2;
	}
	if (*carx >= 350)
	{
		*caridx = 0;
		*cary += 2;
	}
}
void carlane21move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx >= 575)
		*carx -= 2;
	if (*carx >= 570 && *carx <= 575)
	{
		if (x[1] == true)
		{
			*carx -= 2;
		}
	}
	if (*carx <= 570 && *carx > -55)
	{
		*carx -= 2;
	}
}
void carlane22move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx >= 575)
		*carx -= 2;
	if (*carx >= 570 && *carx <= 575)
	{
		if (x[1] == true)
		{
			*carx -= 2;
		}
	}
	if (*carx <= 570 && *carx > 500)
	{
		*carx -= 2;
	}
	if (*carx <= 500 && cary > 0)
	{
		*caridx = 2;
		*cary -= 2;
	}
}
void carlane6_1move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary <= 235)
	{
		*cary += 3;
	}
	if (*cary > 235)
	{
		*caridx = 1;
		*carx -= 3;
	}
}
void carlane6_2move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary <= 140)
		*cary += 3;
	if (*cary >= 140 && *cary <= 155)
	{
		if (x[1] == true)
			*cary += 3;
	}
	if (*cary >= 155 && *cary <= 755)
		*cary += 3;
}
void carlane6_3move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary <= 140)
		*cary += 3;
	if (*cary >= 140 && *cary <= 155)
	{
		if (x[1] == true)
			*cary += 3;
	}
	if (*cary >= 155 && *cary <= 375)
		*cary += 3;
	if (*cary > 375)
	{
		*caridx = 3;
		*carx += 3;
	}
}
void carlane6_4move(int *carx, int *cary, int *caridx, int n)
{
	n = 4;
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx >= 545)
	{
		*carx -= 3;
	}
	if (*carx < 545)
	{
		*cary -= 3;
		*caridx = 2;
	}
}
void carlane6_5move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx >= 620)
		*carx -= 3;
	if (*carx <= 620 && *carx >= 605)
	{
		if (x[2] == true)
			*carx -= 3;
	}
	if (*carx <= 605)
		*carx -= 3;
}
void carlane6_6move(int *carx, int *cary, int *caridx, int n)
{
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx >= 620)
		*carx -= 3;
	if (*carx <= 620 && *carx >= 605)
	{
		if (x[2] == true)
			*carx -= 3;
	}
	if (*carx <= 605 && *carx >= 405)
	{
		*carx -= 3;
	}
	if (*carx < 405)
	{
		*caridx = 0;
		*cary += 3;
	}
}
void carlane6_7move(int *carx, int *cary, int *caridx, int n)
{
	n = 1;
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary >= 470)
	{
		*cary -= 3;
	}
	if (*cary <= 470)
	{
		*caridx = 3;
		*carx += 3;
	}
}
void carlane6_8move(int *carx, int *cary, int *caridx, int n)
{
	n = 2;
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary >= 525)
	{
		*cary -= 3;
	}
	if (*cary <= 525 && *cary >= 510)
	{
		if (x[3] == true)
			*cary -= 3;
	}
	if (*cary <= 510 && *cary >= -55)
		*cary -= 3;
}
void carlane6_9move(int *carx, int *cary, int *caridx, int n)
{
	n = 3;
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*cary >= 525)
		*cary -= 3;
	if (*cary <= 525 && *cary >= 510)
	{
		if (x[3] == true)
			*cary -= 3;
	}
	if (*cary <= 520 && *cary >= 340)
		*cary -= 3;
	if (*cary <= 340)
	{
		*caridx = 1;
		*carx -= 3;
	}
}
void carlane6_10move(int *carx, int *cary, int *caridx, int n)
{
	n = 4;
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx <= 305)
	{
		*carx += 3;
	}
	if (*carx >= 305)
	{
		*caridx = 0;
		*cary += 3;
	}
}
void carlane6_11move(int *carx, int *cary, int *caridx, int n)
{
	n = 1;
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx <= 200)
		*carx += 3;
	if (*carx >= 200 && *carx <= 215)
	{
		if (x[0] == true)
			*carx += 3;
	}
	if (*carx >= 215 && *carx <= 900)
		*carx += 3;
}
void carlane6_12move(int *carx, int *cary, int *caridx, int n)
{
	n = 2;
	if (n == 1)
		iShowBMP2(*carx, *cary, car_1[*caridx], 0);
	else if (n == 2)
		iShowBMP2(*carx, *cary, car_2[*caridx], 0);
	else if (n == 3)
		iShowBMP2(*carx, *cary, car_3[*caridx], 0);
	else if (n == 4)
		iShowBMP2(*carx, *cary, car_4[*caridx], 0);
	if (*carx <= 200)
		*carx += 3;
	if (*carx >= 200 && *carx <= 215)
	{
		if (x[0] == true)
			*carx += 3;
	}
	if (*carx >= 215 && *carx <= 445)
		*carx += 3;
	if (*carx >= 445)
	{
		*cary -= 3;
		*caridx = 2;
	}
}
void carlaneround_1(int *carx, int *cary, int *caridx, int *n)
{
	if (*cary <= 120)
	{
		iShowBMP2(*carx, *cary, car_1[0], 0);
		*cary += 2;
	}
	if ((*carx <= 410 && *carx >= 190) && (*cary >= 120 && *cary <= 310))
	{
		iShowBMP2(*carx, *cary, car_round_1[0], 0);
		*carx -= 2;
		*cary += 2;
	}
	if (*n == 0)
	{
		if (*cary >= 310 && *carx <= 210)
		{
			iShowBMP2(*carx, *cary, car_1[1], 0);
			*carx -= 3;
		}
	}
	if ((*n == 1) || (*n == 2))
	{
		if (*cary >= 310 && *cary <= 375)
		{
			iShowBMP2(*carx, *cary, car_1[0], 0);
			*cary += 2;
		}
		if ((*carx >= 180 && *carx <= 390) && (*cary >= 375 && *cary <= 590))
		{
			iShowBMP2(*carx, *cary, car_round_1[1], 0);
			*carx += 2;
			*cary += 2;
		}
		if (*cary >= 565)
		{
			iShowBMP2(*carx, *cary, car_1[0], 0);
			*cary += 2;
		}
	}
}
void carlaneround_2(int *carx, int *cary, int *caridx, int *n)
{
	if (*carx >= 660)
	{
		iShowBMP2(*carx, *cary, car_2[1], 0);
		*carx -= 3;
	}
	if ((*carx <= 660 && *carx >= 460) && (*cary <= 325 && *cary >= 130))
	{
		iShowBMP2(*carx, *cary, car_round_2[3], 0);
		*carx -= 2;
		*cary -= 2;
	}
	if (*n == 0)
	{
		if (*cary <= 130 && *carx <= 470)
		{
			iShowBMP2(*carx, *cary, car_2[2], 0);
			*cary -= 2;
		}
	}
	if (*n == 1)
	{
		if (*carx <= 465 && *carx >= 410)
		{
			iShowBMP2(*carx, *cary, car_2[1], 0);
			*carx -= 2;
		}
		if ((*carx <= 410 && *carx >= 190) && (*cary >= 120 && *cary <= 310))
		{
			iShowBMP2(*carx, *cary, car_round_2[0], 0);
			*carx -= 2;
			*cary += 2;
		}
		if (*cary >= 310 && *carx <= 240)
		{
			iShowBMP2(*carx, *cary, car_2[1], 0);
			*carx -= 3;
		}
	}
}
void carlaneround_3(int *carx, int *cary, int *caridx, int *n)
{
	if (*cary >= 560)
	{
		iShowBMP2(*carx, *cary, car_3[2], 0);
		*cary -= 2;
	}
	if ((*cary >= 390 && *cary <= 560) && (*carx >= 460 && *carx <= 680))
	{
		iShowBMP2(*carx, *cary, car_round_3[2], 0);
		*carx += 2;
		*cary -= 2;
	}
	if (*n == 0)
	{
		if (*cary <= 390 && *carx <= 900)
		{
			iShowBMP2(*carx, *cary, car_3[3], 0);
			*carx += 3;
		}
	}
	if (*n == 1)
	{
		if (*cary <= 390 && *cary >= 300)
		{
			iShowBMP2(*carx, *cary, car_3[2], 0);
			*cary -= 2;
		}
		if ((*carx <= 660 && *carx >= 460) && (*cary <= 300 && *cary >= 130))
		{
			iShowBMP2(*carx, *cary, car_round_3[3], 0);
			*carx -= 2;
			*cary -= 2;
		}
		if (*cary <= 130)
		{
			iShowBMP2(*carx, *cary, car_3[2], 0);
			*cary -= 2;
		}
	}
}
void carlaneround_4(int *carx, int *cary, int *caridx, int *n)
{
	if (*carx <= 180)
	{
		iShowBMP2(*carx, *cary, car_4[3], 0);
		*carx += 3;
	}
	if ((*carx >= 180 && *carx <= 390) && (*cary >= 380 && *cary <= 590))
	{
		iShowBMP2(*carx, *cary, car_round_4[1], 0);
		*carx += 2;
		*cary += 2;
	}
	if (*n == 0)
	{
		if (*cary >= 590 && *carx >= 390)
		{
			iShowBMP2(*carx, *cary, car_4[0], 0);
			*cary += 2;
		}
	}
	if (*n == 1)
	{
		if (*carx >= 390 && *carx <= 460)
		{
			iShowBMP2(*carx, *cary, car_4[3], 0);
			*carx += 2;
		}
		if ((*cary >= 390 && *cary <= 580) && (*carx >= 460 && *carx <= 680))
		{
			iShowBMP2(*carx, *cary, car_round_4[2], 0);
			*carx += 2;
			*cary -= 2;
		}
		if (*cary <= 390 && *carx <= 900)
		{
			iShowBMP2(*carx, *cary, car_4[3], 0);
			*carx += 2;
		}
	}
}
void iDraw()
{
	iClear();
	if (gamestate == -1)
	{
		menu1();
	}
	else if (gamestate == 0)
	{
		iShowBMP(0, 0, "menu1\\100118.jpg");
	}
	else if (gamestate == 1)
	{
		iShowBMP(0, 0, "Pictures\\start.jpg");
	}
	else if (gamestate == 2)
	{
		iShowBMP(0, 0, "Pictures\\4&6 lane.jpg");
	}
	else if (gamestate == 4)
	{
		iShowBMP(0, 0, "Pictures\\4 lane road.bmp");
		r = color_r[0];
		g = color_g[0];
		b = color_b[0];
		if (color_r[0] == 0 && color_g[0] == 255)
			x[0] = true;
		else
			x[0] = false;
		iSetColor(r, g, b);
		iFilledCircle(315, 240, 20, 1000);
		r = color_r[3];
		g = color_g[3];
		b = color_b[3];
		if (color_r[3] == 0 && color_g[3] == 255)
			x[3] = true;
		else
			x[3] = false;
		iSetColor(r, g, b);
		iFilledCircle(315, 500, 20, 1000);
		r = color_r[1];
		g = color_g[1];
		b = color_b[1];
		if (color_r[1] == 0 && color_g[1] == 255)
			x[1] = true;
		else
			x[1] = false;
		iSetColor(r, g, b);
		iFilledCircle(580, 240, 20, 1000);
		r = color_r[2];
		g = color_g[2];
		b = color_b[2];
		if (color_r[2] == 0 && color_g[2] == 255)
			x[2] = true;
		else
			x[2] = false;
		iSetColor(r, g, b);
		iFilledCircle(580, 500, 20, 1000);
		if ((mouse_x >= 3 && mouse_x <= 80) && (mouse_y >= 535 && mouse_y <= 600))
		{
			gamestate = 3;
		}
		carlane1move(&laneroad4x[0], &laneroad4y[0], &laneroad4z[0], n[0]);
		carlane2move(&laneroad4x[1], &laneroad4y[1], &laneroad4z[1], n[1]);
		carlane3move(&laneroad4x[2], &laneroad4y[2], &laneroad4z[2], n[2]);
		carlane4move(&laneroad4x[3], &laneroad4y[3], &laneroad4z[3], n[3]);
		carlane11move(&laneroad4x[4], &laneroad4y[4], &laneroad4z[4], n[4]);
		carlane12move(&laneroad4x[5], &laneroad4y[5], &laneroad4z[5], n[5]);
		carlane21move(&laneroad4x[6], &laneroad4y[6], &laneroad4z[6], n[6]);
		carlane22move(&laneroad4x[7], &laneroad4y[7], &laneroad4z[7], n[7]);
		if (laneroad4x[0] <= 0)
		{
			laneroad4x[0] = 345;
			laneroad4y[0] = -50;
			laneroad4z[0] = 0;
			x[0] = false;
			carlane1move(&laneroad4x[0], &laneroad4y[0], &laneroad4z[0], n[0]);
		}
		if (laneroad4y[1] >= 750)
		{
			laneroad4x[1] = 400;
			laneroad4y[1] = -50;
			laneroad4z[1] = 0;
			x[1] = false;
			carlane2move(&laneroad4x[1], &laneroad4y[1], &laneroad4z[1], n[1]);
		}
		if (laneroad4y[2] <= -55)
		{
			laneroad4x[2] = 450;
			laneroad4y[2] = 750;
			laneroad4z[2] = 2;
			x[2] = false;
			carlane3move(&laneroad4x[2], &laneroad4y[2], &laneroad4z[2], n[2]);
		}
		if (laneroad4x[3] >= 900)
		{
			laneroad4x[3] = 500;
			laneroad4y[3] = 750;
			laneroad4z[3] = 2;
			x[3] = false;
			carlane4move(&laneroad4x[3], &laneroad4y[3], &laneroad4z[3], n[3]);
		}
		if (laneroad4x[4] >= 900)
		{
			laneroad4x[4] = -50;
			laneroad4y[4] = 375;
			laneroad4z[4] = 3;
			x[4] = false;
			carlane11move(&laneroad4x[4], &laneroad4y[4], &laneroad4z[4], n[4]);
		}
		if (laneroad4y[5] >= 750)
		{
			laneroad4x[5] = -50;
			laneroad4y[5] = 430;
			laneroad4z[5] = 3;
			x[5] = false;
			carlane12move(&laneroad4x[5], &laneroad4y[5], &laneroad4z[5], n[5]);
		}
		if (laneroad4x[6] <= -55)
		{
			laneroad4x[6] = 900;
			laneroad4y[6] = 320;
			laneroad4z[6] = 1;
			x[6] = false;
			carlane21move(&laneroad4x[6], &laneroad4y[6], &laneroad4z[6], n[6]);
		}
		if (laneroad4y[7] <= 0)
		{
			laneroad4x[7] = 900;
			laneroad4y[7] = 275;
			laneroad4z[7] = 1;
			x[7] = false;
			carlane22move(&laneroad4x[7], &laneroad4y[7], &laneroad4z[7], n[7]);
		}
	}
	else if (gamestate == 5)
	{
		iShowBMP(0, 0, "Pictures\\6 lane road.bmp");
		r = color_r[0];
		g = color_g[0];
		b = color_b[0];
		if (color_r[0] == 0 && color_g[0] == 255)
			x[0] = true;
		else
			x[0] = false;
		iSetColor(r, g, b);
		iFilledCircle(320, 445, 20, 1000); // lane 11
		r = color_r[0];
		g = color_g[0];
		b = color_b[0];
		if (color_r[0] == 0 && color_g[0] == 255)
			x[0] = true;
		else
			x[0] = false;
		iSetColor(r, g, b);
		iFilledCircle(320, 400, 20, 1000); // lane 12
		r = color_r[1];
		g = color_g[1];
		b = color_b[1];
		if (color_r[1] == 0 && color_g[1] == 255)
			x[1] = true;
		else
			x[1] = false;
		iSetColor(r, g, b);
		iFilledCircle(380, 250, 20, 1000); // lane 2
		r = color_r[1];
		g = color_g[1];
		b = color_b[1];
		if (color_r[1] == 0 && color_g[1] == 255)
			x[1] = true;
		else
			x[1] = false;
		iSetColor(r, g, b);
		iFilledCircle(425, 250, 20, 1000); // lane 3
		r = color_r[2];
		g = color_g[2];
		b = color_b[2];
		if (color_r[2] == 0 && color_g[2] == 255)
			x[2] = true;
		else
			x[2] = false;
		iSetColor(r, g, b);
		iFilledCircle(580, 355, 20, 1000); // lane 6
		r = color_r[2];
		g = color_g[2];
		b = color_b[2];
		if (color_r[2] == 0 && color_g[2] == 255)
			x[2] = true;
		else
			x[2] = false;
		iSetColor(r, g, b);
		iFilledCircle(580, 310, 20, 1000); // lane 5
		r = color_r[3];
		g = color_g[3];
		b = color_b[3];
		if (color_r[3] == 0 && color_g[3] == 255)
			x[3] = true;
		else
			x[3] = false;
		iSetColor(r, g, b);
		iFilledCircle(475, 507, 20, 1000); // lane 8
		r = color_r[3];
		g = color_g[3];
		b = color_b[3];
		if (color_r[3] == 0 && color_g[3] == 255)
			x[3] = true;
		else
			x[3] = false;
		iSetColor(r, g, b);
		iFilledCircle(520, 507, 20, 1000); // lane 9
		carlane6_1move(&laneroad6x[0], &laneroad6y[0], &laneroad6z[0], n[0]);
		carlane6_2move(&laneroad6x[1], &laneroad6y[1], &laneroad6z[1], n[1]);
		carlane6_3move(&laneroad6x[2], &laneroad6y[2], &laneroad6z[2], n[2]);
		carlane6_4move(&laneroad6x[3], &laneroad6y[3], &laneroad6z[3], n[3]);
		carlane6_5move(&laneroad6x[4], &laneroad6y[4], &laneroad6z[4], n[4]);
		carlane6_6move(&laneroad6x[5], &laneroad6y[5], &laneroad6z[5], n[5]);
		carlane6_7move(&laneroad6x[6], &laneroad6y[6], &laneroad6z[6], n[6]);
		carlane6_8move(&laneroad6x[7], &laneroad6y[7], &laneroad6z[7], n[7]);
		carlane6_9move(&laneroad6x[8], &laneroad6y[8], &laneroad6z[8], n[7]);
		carlane6_10move(&laneroad6x[9], &laneroad6y[9], &laneroad6z[9], n[7]);
		carlane6_11move(&laneroad6x[10], &laneroad6y[10], &laneroad6z[10], n[7]);
		carlane6_12move(&laneroad6x[11], &laneroad6y[11], &laneroad6z[11], n[7]);
		if (laneroad6x[0] <= 0)
		{
			laneroad6x[0] = 315;
			laneroad6y[0] = -50;
			laneroad6z[0] = 0;
			carlane6_1move(&laneroad6x[0], &laneroad6y[0], &laneroad6z[0], n[0]);
		}
		if (laneroad6y[1] >= 750)
		{
			laneroad6x[1] = 365;
			laneroad6y[1] = -50;
			laneroad6z[1] = 0;
			x[1] = false;
			carlane6_2move(&laneroad6x[1], &laneroad6y[1], &laneroad6z[1], n[1]);
		}
		if (laneroad6x[2] >= 900)
		{
			laneroad6x[2] = 410;
			laneroad6y[2] = -50;
			laneroad6z[2] = 0;
			x[1] = false;
			carlane6_3move(&laneroad6x[2], &laneroad6y[2], &laneroad6z[2], n[2]);
		}
		if (laneroad6y[3] <= 0)
		{
			laneroad6x[3] = 900;
			laneroad6y[3] = 235;
			laneroad6z[3] = 1;
			carlane6_4move(&laneroad6x[3], &laneroad6y[3], &laneroad6z[3], n[3]);
		}
		if (laneroad6x[4] <= -55)
		{
			laneroad6x[4] = 900;
			laneroad6y[4] = 280;
			laneroad6z[4] = 1;
			x[2] = false;
			carlane6_5move(&laneroad6x[4], &laneroad6y[4], &laneroad6z[4], n[4]);
		}
		if (laneroad6y[5] >= 748)
		{
			laneroad6x[5] = 900;
			laneroad6y[5] = 335;
			laneroad6z[5] = 1;
			x[2] = false;
			carlane6_6move(&laneroad6x[5], &laneroad6y[5], &laneroad6z[5], n[5]);
		}
		if (laneroad6x[6] >= 900)
		{
			laneroad6x[6] = 545;
			laneroad6y[6] = 750;
			laneroad6z[6] = 2;
			carlane6_7move(&laneroad6x[6], &laneroad6y[6], &laneroad6z[6], n[6]);
		}
		if (laneroad6y[7] <= 0)
		{
			laneroad6x[7] = 495;
			laneroad6y[7] = 750;
			laneroad6z[7] = 2;
			x[3] = false;
			carlane6_8move(&laneroad6x[7], &laneroad6y[7], &laneroad6z[7], n[7]);
		}
		if (laneroad6x[8] <= -55)
		{
			laneroad6x[8] = 450;
			laneroad6y[8] = 750;
			laneroad6z[8] = 2;
			x[3] = false;
			carlane6_9move(&laneroad6x[8], &laneroad6y[8], &laneroad6z[8], n[7]);
		}
		if (laneroad6y[9] >= 750)
		{
			laneroad6x[9] = -50;
			laneroad6y[9] = 475;
			laneroad6z[9] = 3;
			carlane6_10move(&laneroad6x[9], &laneroad6y[9], &laneroad6z[9], n[7]);
		}
		if (laneroad6x[10] >= 750)
		{
			laneroad6x[10] = -50;
			laneroad6y[10] = 425;
			laneroad6z[10] = 3;
			x[0] = false;
			carlane6_11move(&laneroad6x[10], &laneroad6y[10], &laneroad6z[10], n[7]);
		}
		if (laneroad6y[11] <= -55)
		{
			laneroad6x[11] = -50;
			laneroad6y[11] = 380;
			laneroad6z[11] = 3;
			x[0] = false;
			carlane6_12move(&laneroad6x[11], &laneroad6y[11], &laneroad6z[11], n[7]);
		}
	}
	else if (gamestate == 6)
	{
		iShowBMP(0, 0, "Pictures\\round_about.bmp");
		carlaneround_1(&roundx[0], &roundy[0], &roundz[0], &flag[0]);
		carlaneround_2(&roundx[1], &roundy[1], &roundz[1], &flag[1]);
		carlaneround_3(&roundx[2], &roundy[2], &roundz[2], &flag[2]);
		carlaneround_4(&roundx[3], &roundy[3], &roundz[3], &flag[3]);
		if (roundx[0] <= 0 || roundy[0] >= 750)
		{
			roundx[0] = 390;
			roundy[0] = -50;
			if (flag[0] == 0)
				flag[0] = 1;
			else
				flag[0] = 0;
			carlaneround_1(&roundx[0], &roundy[0], &roundz[0], &flag[0]);
		}
		if (roundy[1] <= 0 || roundx[1] <= 0)
		{
			roundx[1] = 900;
			roundy[1] = 325;
			if (flag[1] == 0)
				flag[1] = 1;
			else
				flag[1] = 0;
			carlaneround_2(&roundx[1], &roundy[1], &roundz[1], &flag[1]);
		}
		if (roundx[2] >= 900 || roundy[2] <= 0)
		{
			roundx[2] = 460;
			roundy[2] = 750;
			if (flag[2] == 0)
				flag[2] = 1;
			else
				flag[2] = 0;
			carlaneround_3(&roundx[2], &roundy[2], &roundz[0], &flag[2]);
		}
		if (roundy[3] >= 750 || roundx[3] >= 900)
		{
			roundx[3] = -50;
			roundy[3] = 380;
			if (flag[3] == 0)
				flag[3] = 1;
			else
				flag[3] = 0;
			carlaneround_4(&roundx[3], &roundy[3], &roundz[0], &flag[3]);
		}
	}
	else if (gamestate == 9)
	{
		iShowBMP(0, 0, "Pictures\\instruction.jpg");
		if ((mouse_x >= 0 && mouse_x <= 90) && (mouse_y >= 661 && mouse_y <= 750))
		{
			gamestate = 0;
		}
	}
	else if (gamestate == 8)
	{
		iShowBMP(0, 0, "Pictures\\credit.jpg");
		if ((mouse_x >= 0 && mouse_x <= 60) && (mouse_y >= 660 && mouse_y <= 720))
		{
			gamestate = 0;
		}
	}
	else if (gamestate == 3)
	{
		if (music)
		{
			iShowBMP(0, 0, "Pictures\\1.jpg");
		}
		else
		{
			iShowBMP(0, 0, "Pictures\\2.jpg");
		}
	}
}
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
}
void iMouse(int button, int state, int mx, int my)
{
	mouse_x = mx;
	mouse_y = my;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gamestate == 0)
		{
			if ((mouse_x >= 10 && mouse_x <= 340) && (mouse_y >= 495 && mouse_y <= 544))
			{
				gamestate = 1;
			}
			if ((mouse_x >= 5 && mouse_x <= 520) && (mouse_y >= 380 && mouse_y <= 430))
			{
				gamestate = 3;
			}
			if ((mouse_x >= 15 && mouse_x <= 365) && (mouse_y >= 270 && mouse_y <= 325))
			{
				gamestate = 8;
			}
			if ((mouse_x >= 15 && mouse_x <= 665) && (mouse_y >= 165 && mouse_y <= 220))
			{
				gamestate = 9;
			}
		}
		else if (gamestate == 1)
		{
			if ((mouse_x >= 20 && mouse_x <= 350) && (mouse_y >= 405 && mouse_y <= 445))
			{
				gamestate = 2;
			}
			if ((mouse_x >= 0 && mouse_x <= 60) && (mouse_y >= 660 && mouse_y <= 720))
			{
				gamestate = 0;
			}
			if ((mouse_x >= 0 && mouse_x <= 555) && (mouse_y >= 290 && mouse_y <= 340))
			{
				gamestate = 6;
			}
		}
		else if (gamestate == 2)
		{
			if ((mouse_x >= 0 && mouse_x <= 200) && (mouse_y >= 660 && mouse_y <= 750))
			{
				gamestate = 1;
			}
			if ((mouse_x >= 36 && mouse_x <= 320) && (mouse_y >= 385 && mouse_y <= 430))
			{
				gamestate = 4;
				//music = false;
			}
			if ((mouse_x >= 20 && mouse_x <= 300) && (mouse_y >= 290 && mouse_y <= 340))
			{
				gamestate = 5;
			}
		}
		else if (gamestate == 4)
		{
			if ((mouse_x >= 0 && mouse_x <= 80) && (mouse_y >= 680 && mouse_y <= 750))
			{
				gamestate = 2;
			}
		}
		else if (gamestate == 5)
		{
			if ((mouse_x >= 0 && mouse_x <= 80) && (mouse_y >= 680 && mouse_y <= 750))
			{
				gamestate = 2;
			}
		}
		else if (gamestate == 6)
		{
			if ((mouse_x >= 0 && mouse_x <= 80) && (mouse_y >= 680 && mouse_y <= 750))
			{
				gamestate = 1;
			}
		}
		else if (gamestate == 3)
		{
			if ((mouse_x >= 345 && mouse_x <= 540) && (mouse_y >= 265 && mouse_y <= 425))
			{
				if (music)
				{
					n1 = 0;
					music = false;
					PlaySound(0, 0, 0);
				}
				else
				{
					music = true;
					PlaySound("Pictures\\Carefree(chosic.com).wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			if ((mouse_x >= 0 && mouse_x <= 125) && (mouse_y >= 630 && mouse_y <= 750))
			{
				gamestate = 0;
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		// x -= 10;
		// y -= 10;
	}
}
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
	// place your codes for other keys here
}
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	// place your codes for other keys here
}
int main()
{
	random();
	iSetTimer(3500, timerFunction);
	if (gamestate == -1)
		iSetTimer(30, change);
	if (music)
	{
		PlaySound("Pictures\\Carefree(chosic.com).wav", NULL, SND_LOOP | SND_ASYNC);
	}
	srand(time(NULL));
	iInitialize(900, 750, "CITY FLOW");
	return 0;
}