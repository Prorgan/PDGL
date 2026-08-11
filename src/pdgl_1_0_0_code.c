
// PDGL version 1.0.0

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int rnd,akt,tm,nm_cl,ic;
int i,j,k;
char world[30][101],a,tw[30][101];

void a_ge_map()
{
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 100; j++) {
			rnd = rand() % 6 + 1;
			if (rnd == 1) world[i][j] = '#';
			else world[i][j] = ' ';
		}
		world[i][100] = '\0';
	}
}

void b_ge_map()
{
	int gm_akt = 1,x = 1,y = 1;
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 100; j++) {
			world[i][j] = ' ';
		}
		world[i][100] = '\0';
	}
	do
	{
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 100; j++) {
				tw[i][j] = world[i][j];
			}
			tw[i][100] = '\0';
		}
		if ((x < 0) || (y < 0) || (x > 99) || (y > 29)) x = 1,y = 1;
		tw[y][x] = '>';
		for (i = 0; i < 30; i++) {
			printf("\n%s",tw[i]);
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
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 100; j++) {
			tw[i][j] = world[i][j];
		}
		tw[i][100] = '\0';
	}
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 100; j++) {
			if ((tw[i][j] == ' ') || (tw[i][j] == '#')) {
				nm_cl = 0,ti = i,tj = j;
				j++;
				if (j > 99) j = 0;
				if (j < 0) j = 99;
				if (i > 29) i = 0;
				if (i < 0) i = 29;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				j--;
				if (j > 99) j = 0;
				if (j < 0) j = 99;
				if (i > 29) i = 0;
				if (i < 0) i = 29;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i++;
				if (j > 99) j = 0;
				if (j < 0) j = 99;
				if (i > 29) i = 0;
				if (i < 0) i = 29;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i--;
				if (j > 99) j = 0;
				if (j < 0) j = 99;
				if (i > 29) i = 0;
				if (i < 0) i = 29;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i++,j++;
				if (j > 99) j = 0;
				if (j < 0) j = 99;
				if (i > 29) i = 0;
				if (i < 0) i = 29;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i--,j--;
				if (j > 99) j = 0;
				if (j < 0) j = 99;
				if (i > 29) i = 0;
				if (i < 0) i = 29;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i++,j--;
				if (j > 99) j = 0;
				if (j < 0) j = 99;
				if (i > 29) i = 0;
				if (i < 0) i = 29;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i--,j++;
				if (j > 99) j = 0;
				if (j < 0) j = 99;
				if (i > 29) i = 0;
				if (i < 0) i = 29;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				if (nm_cl < 2) world[i][j] = ' ';
				if (nm_cl > 3) world[i][j] = ' ';
				if (nm_cl == 3) world[i][j] = '#';
			}
		}
		world[i][100] = '\0';
	}
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nPublic Domain Game of Life (PDGL)");
	printf("\nVersion 1.0.0\n");
	srand(time(NULL));
	printf("\nR?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') ic = 1;
	else ic = 2;
	akt = 1,tm = 0;
	if (ic == 1)
		a_ge_map();
	if (ic == 2)
		b_ge_map();
	do
	{
		tm++;
		process();
		for (i = 0; i < 30; i++) {
			printf("\n%s",world[i]);
		}
		printf("\nMove: %d",tm);
		a = getch();
		printf("\033[H\033[2J\033[3J");
		if (a == 'x') akt = 0;
	}
	while (akt == 1);
	return 0;
}