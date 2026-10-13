
// PDGL version 1.0.2

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX_X 240
#define MAX_Y 180

int rnd,akt,tm,nm_cl,ic,ns_y,ns_x;
int i,j,k;
char world[MAX_Y][MAX_X+1],a,tw[MAX_Y][MAX_X+1];

void a_ge_map()
{
	for (i = 0; i < MAX_Y; i++) {
		for (j = 0; j < MAX_X; j++) {
			rnd = rand() % 3 + 1;
			if (rnd == 1) world[i][j] = '#';
			else world[i][j] = ' ';
		}
		world[i][MAX_X] = '\0';
	}
}

void b_ge_map()
{
	int gm_akt = 1,x = 1,y = 1;
	int xm,ym;
	for (i = 0; i < MAX_Y; i++) {
		for (j = 0; j < MAX_X; j++) {
			world[i][j] = ' ';
		}
		world[i][MAX_X] = '\0';
	}
	do
	{
		for (i = 0; i < MAX_Y; i++) {
			for (j = 0; j < MAX_X; j++) {
				tw[i][j] = world[i][j];
			}
			tw[i][MAX_X] = '\0';
		}
		if ((x < 0) || (y < 0) || (x > MAX_X-1) || (y > MAX_Y-1)) x = 1,y = 1;
		if (y < 30) ns_y = 1;
		if ((y > 29) && (y < 60)) ns_y = 2;
		if ((y > 59) && (y < 90)) ns_y = 3;
		if ((y > 89) && (y < 120)) ns_y = 4;
		if ((y > 119) && (y < 150)) ns_y = 5;
		if (y > 149) ns_y = 6;
		if (x < 120) ns_x = 1;
		if (x > 119) ns_x = 2;
		if (ns_y == 1) ym = 30;
		if (ns_y == 2) ym = 60;
		if (ns_y == 3) ym = 90;
		if (ns_y == 4) ym = 120;
		if (ns_y == 5) ym = 150;
		if (ns_y == 6) ym = 180;
		if (ns_x == 1) xm = 120;
		if (ns_x == 2) xm = 240;
		tw[y][x] = '>';
		for (i = ym-30; i < ym; i++) {
			printf("\n%.*s",120,tw[i] + xm-120);
		}
		printf("\nPress 'g' to save");
		printf("\nX: %d,Y: %d",x,y);
		a = getch();
		printf("\033[H\033[2J\033[3J");
		if (a == 'w') y--;
		if (a == 's') y++;
		if (a == 'a') x--;
		if (a == 'd') x++;
		if (a == 'z') world[y][x] = '#';
		if (a == 'x') world[y][x] = ' ';
		if (a == 'g') gm_akt = 0;
	}
	while (gm_akt == 1);
}

void process()
{
	int tj,ti;
	for (i = 0; i < MAX_Y; i++) {
		for (j = 0; j < MAX_X; j++) {
			tw[i][j] = world[i][j];
		}
		tw[i][MAX_X] = '\0';
	}
	for (i = 0; i < MAX_Y; i++) {
		for (j = 0; j < MAX_X; j++) {
			if ((tw[i][j] == ' ') || (tw[i][j] == '#')) {
				nm_cl = 0,ti = i,tj = j;
				j++;
				if (j > MAX_X-1) j = 0;
				if (j < 0) j = MAX_X-1;
				if (i > MAX_Y-1) i = 0;
				if (i < 0) i = MAX_Y-1;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				j--;
				if (j > MAX_X-1) j = 0;
				if (j < 0) j = MAX_X-1;
				if (i > MAX_Y-1) i = 0;
				if (i < 0) i = MAX_Y-1;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i++;
				if (j > MAX_X-1) j = 0;
				if (j < 0) j = MAX_X-1;
				if (i > MAX_Y-1) i = 0;
				if (i < 0) i = MAX_Y-1;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i--;
				if (j > MAX_X-1) j = 0;
				if (j < 0) j = MAX_X-1;
				if (i > MAX_Y-1) i = 0;
				if (i < 0) i = MAX_Y-1;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i++,j++;
				if (j > MAX_X-1) j = 0;
				if (j < 0) j = MAX_X-1;
				if (i > MAX_Y-1) i = 0;
				if (i < 0) i = MAX_Y-1;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i--,j--;
				if (j > MAX_X-1) j = 0;
				if (j < 0) j = MAX_X-1;
				if (i > MAX_Y-1) i = 0;
				if (i < 0) i = MAX_Y-1;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i++,j--;
				if (j > MAX_X-1) j = 0;
				if (j < 0) j = MAX_X-1;
				if (i > MAX_Y-1) i = 0;
				if (i < 0) i = MAX_Y-1;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i--,j++;
				if (j > MAX_X-1) j = 0;
				if (j < 0) j = MAX_X-1;
				if (i > MAX_Y-1) i = 0;
				if (i < 0) i = MAX_Y-1;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				if (nm_cl < 2) world[i][j] = ' ';
				if (nm_cl > 3) world[i][j] = ' ';
				if (nm_cl == 3) world[i][j] = '#';
			}
		}
		world[i][MAX_X] = '\0';
	}
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nPublic Domain Game of Life (PDGL)");
	printf("\nVersion 1.0.2\n");
	srand(time(NULL));
	printf("\nR?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') ic = 1;
	else ic = 2;
	akt = 1,tm = 0,ns_y = 1,ns_x = 1;
	if (ic == 1)
		a_ge_map();
	if (ic == 2)
		b_ge_map();
	do
	{
		int ym,xm;
		tm++;
		if (ns_y < 1) ns_y = 1;
		if (ns_y > 6) ns_y = 6;
		if (ns_x < 1) ns_x = 1;
		if (ns_x > 2) ns_x = 2;
		process();
		if (ns_y == 1) ym = 30;
		if (ns_y == 2) ym = 60;
		if (ns_y == 3) ym = 90;
		if (ns_y == 4) ym = 120;
		if (ns_y == 5) ym = 150;
		if (ns_y == 6) ym = 180;
		if (ns_x == 1) xm = 120;
		if (ns_x == 2) xm = 240;
		for (i = ym-30; i < ym; i++) {
			printf("\n%.*s",120,tw[i] + xm-120);
		}
		printf("\nMove: %d, area_y: %d, area_x: %d",tm,ns_y,ns_x);
		a = getch();
		printf("\033[H\033[2J\033[3J");
		if (a == 'w') ns_y--;
		if (a == 's') ns_y++;
		if (a == 'a') ns_x--;
		if (a == 'd') ns_x++;
		if (a == 'x') akt = 0;
	}
	while (akt == 1);
	printf("\nOk");
	return 0;
}
