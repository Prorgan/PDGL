
// PDGL version 1.1.0

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define MAX_X 480
#define MAX_Y 480

int rnd,akt,tm,nm_cl,ic,ns_y,ns_x,nt;
int i,j,k,l;
char world[MAX_Y][MAX_X+1],a,tw[MAX_Y][MAX_X+1];
char lc,dc;

void a_ge_map()
{
	int rnd_a;
	printf("\n1/");
	scanf("%d",&rnd_a);
	if (rnd_a < 1) rnd_a = 1;
	for (i = 0; i < MAX_Y; i++) {
		for (j = 0; j < MAX_X; j++) {
			rnd = rand() % rnd_a + 1;
			if (rnd == 1) world[i][j] = 2;
			else world[i][j] = 1;
		}
		world[i][MAX_X] = '\0';
	}
}

void b_ge_map()
{
	for (i = 0; i < MAX_Y; i++) {
		for (j = 0; j < MAX_X; j++) {
			world[i][j] = 1;
		}
		world[i][MAX_X] = '\0';
	}
}

void editor()
{
	int gm_akt = 1,x = 1,y = 1;
	int xm,ym;
	do
	{
		for (i = 0; i < MAX_Y; i++) {
			for (j = 0; j < MAX_X; j++) {
				if (world[i][j] == 1) tw[i][j] = dc;
				if (world[i][j] == 2) tw[i][j] = lc;
			}
			tw[i][MAX_X] = '\0';
		}
		if (x > MAX_X-1) x = 0;
		if (x < 0) x = MAX_X-1;
		if (y > MAX_Y-1) y = 0;
		if (y < 0) y = MAX_Y-1;
		int ay = 30,ax = 120;
		if (y < 30) ns_y = 1;
		for (k = 0; k < ((MAX_Y / 30) - 2); k++) {
			if ((y > ay-1) && (y < ay+30)) ns_y = k+2;
			ay += 30;
		}
		if (y > MAX_Y-31) ns_y = MAX_Y/30;
		if (x < 120) ns_x = 1;
		for (k = 0; k < ((MAX_X / 120) - 2); k++) {
			if ((x > ax-1) && (x < ax+120)) ns_x = k+2;
			ax += 120;
		}
		if (x > MAX_X-121) ns_x = MAX_X/120;
		ay = 30,ax = 120;
		for (k = 0; k < (MAX_Y / 30); k++) {
			if (ns_y == k+1) ym = ay;
			ay += 30;
		}
		for (k = 0; k < (MAX_X / 120); k++) {
			if (ns_x == k+1) xm = ax;
			ax += 120;
		}
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
		if (a == 'z') world[y][x] = 2;
		if (a == 'x') world[y][x] = 1;
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
			if ((tw[i][j] == 1) || (tw[i][j] == 2)) {
				nm_cl = 0,ti = i,tj = j;
				for (k = 0; k < 8; k++) {
					if (k == 0) j++;
					if (k == 1) j--;
					if (k == 2) i++;
					if (k == 3) i--;
					if (k == 4) i++,j++;
					if (k == 5) i--,j--;
					if (k == 6) i++,j--;
					if (k == 7) i--,j++;
					if (j > MAX_X-1) j = 0;
					if (j < 0) j = MAX_X-1;
					if (i > MAX_Y-1) i = 0;
					if (i < 0) i = MAX_Y-1;
					if (tw[i][j] == 2) nm_cl++;
					i = ti,j = tj;
				}
				if (nm_cl < 2) world[i][j] = 1;
				if (nm_cl > 3) world[i][j] = 1;
				if (nm_cl == 3) world[i][j] = 2;
			}
		}
		world[i][MAX_X] = '\0';
	}
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nPublic Domain Game of Life (PDGL)");
	printf("\nVersion 1.1.0\n");
	srand(time(NULL));
	printf("\nR?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') ic = 1;
	else ic = 2;
	akt = 1,tm = 1,ns_y = 1,ns_x = 1,nt = 1;
	printf("\nDC:");
	scanf(" %c",&dc);
	printf("\nLC:");
	scanf(" %c",&lc);
	if (dc == '%') dc = ' ';
	if (lc == '%') lc = '#';
	if (ic == 1)
		a_ge_map();
	if (ic == 2)
		b_ge_map();
	editor();
	do
	{
		int ym,xm;
		if (ns_y < 1) ns_y = MAX_Y/30;
		if (ns_y > MAX_Y/30) ns_y = 1;
		if (ns_x < 1) ns_x = MAX_X/120;
		if (ns_x > MAX_X/120) ns_x = 1;
		int ay = 30,ax = 120;
		for (k = 0; k < (MAX_Y / 30); k++) {
			if (ns_y == k+1) ym = ay;
			ay += 30;
		}
		for (k = 0; k < (MAX_X / 120); k++) {
			if (ns_x == k+1) xm = ax;
			ax += 120;
		}
		for (i = 0; i < MAX_Y; i++) {
			for (j = 0; j < MAX_X; j++) {
				if (world[i][j] == 1) tw[i][j] = dc;
				if (world[i][j] == 2) tw[i][j] = lc;
			}
			tw[i][MAX_X] = '\0';
		}
		for (i = ym-30; i < ym; i++) {
			printf("\n%.*s",120,tw[i] + xm-120);
		}
		printf("\nMove: %d, area_y: %d, area_x: %d",tm,ns_y,ns_x);
		a = getch();
		for (l = 0; l < nt; l++) {
			tm++;
			process();
		}
		nt = 1;
		printf("\033[H\033[2J\033[3J");
		if (a == 'w') ns_y--;
		if (a == 's') ns_y++;
		if (a == 'a') ns_x--;
		if (a == 'd') ns_x++;
		if (a == 't') {
			printf("\n:");
			scanf("%d",&nt);
		}
		if (a == 'm') {
			printf("\n_y:");
			scanf("%d",&ns_y);
			printf("\n_x:");
			scanf("%d",&ns_x);
		}
		if (a == 'x') akt = 0;
	}
	while (akt == 1);
	printf("\nOk");
	return 0;
}
