
// PDGL version 1.0.1

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int rnd,akt,tm,nm_cl,ic,ns;
int i,j,k;
char world[90][121],a,tw[90][121];

void a_ge_map()
{
	for (i = 0; i < 90; i++) {
		for (j = 0; j < 120; j++) {
			rnd = rand() % 3 + 1;
			if (rnd == 1) world[i][j] = '#';
			else world[i][j] = ' ';
		}
		world[i][120] = '\0';
	}
}

void b_ge_map()
{
	int gm_akt = 1,x = 1,y = 1;
	for (i = 0; i < 90; i++) {
		for (j = 0; j < 120; j++) {
			world[i][j] = ' ';
		}
		world[i][120] = '\0';
	}
	do
	{
		for (i = 0; i < 90; i++) {
			for (j = 0; j < 120; j++) {
				tw[i][j] = world[i][j];
			}
			tw[i][120] = '\0';
		}
		if ((x < 0) || (y < 0) || (x > 119) || (y > 89)) x = 1,y = 1;
		if (y < 30) ns = 1;
		if ((y > 29) && (y < 60)) ns = 2;
		if (y > 59) ns = 3;
		tw[y][x] = '>';
		if (ns == 1) {
			for (i = 0; i < 30; i++) {
				printf("\n%s",tw[i]);
			}
		}
		if (ns == 2) {
			for (i = 30; i < 60; i++) {
				printf("\n%s",tw[i]);
			}
		}
		if (ns == 3) {
			for (i = 60; i < 90; i++) {
				printf("\n%s",tw[i]);
			}
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
	for (i = 0; i < 90; i++) {
		for (j = 0; j < 120; j++) {
			tw[i][j] = world[i][j];
		}
		tw[i][120] = '\0';
	}
	for (i = 0; i < 90; i++) {
		for (j = 0; j < 120; j++) {
			if ((tw[i][j] == ' ') || (tw[i][j] == '#')) {
				nm_cl = 0,ti = i,tj = j;
				j++;
				if (j > 119) j = 0;
				if (j < 0) j = 119;
				if (i > 89) i = 0;
				if (i < 0) i = 89;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				j--;
				if (j > 119) j = 0;
				if (j < 0) j = 119;
				if (i > 89) i = 0;
				if (i < 0) i = 89;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i++;
				if (j > 119) j = 0;
				if (j < 0) j = 119;
				if (i > 89) i = 0;
				if (i < 0) i = 89;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i--;
				if (j > 119) j = 0;
				if (j < 0) j = 119;
				if (i > 89) i = 0;
				if (i < 0) i = 89;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i++,j++;
				if (j > 119) j = 0;
				if (j < 0) j = 119;
				if (i > 89) i = 0;
				if (i < 0) i = 89;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i--,j--;
				if (j > 119) j = 0;
				if (j < 0) j = 119;
				if (i > 89) i = 0;
				if (i < 0) i = 89;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i++,j--;
				if (j > 119) j = 0;
				if (j < 0) j = 119;
				if (i > 89) i = 0;
				if (i < 0) i = 89;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				i--,j++;
				if (j > 119) j = 0;
				if (j < 0) j = 119;
				if (i > 89) i = 0;
				if (i < 0) i = 89;
				if (tw[i][j] == '#') nm_cl++;
				i = ti,j = tj;
				if (nm_cl < 2) world[i][j] = ' ';
				if (nm_cl > 3) world[i][j] = ' ';
				if (nm_cl == 3) world[i][j] = '#';
			}
		}
		world[i][120] = '\0';
	}
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nPublic Domain Game of Life (PDGL)");
	printf("\nVersion 1.0.1\n");
	srand(time(NULL));
	printf("\nR?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') ic = 1;
	else ic = 2;
	akt = 1,tm = 0,ns = 1;
	if (ic == 1)
		a_ge_map();
	if (ic == 2)
		b_ge_map();
	do
	{
		tm++;
		if (ns < 1) ns = 1;
		if (ns > 3) ns = 3;
		process();
		if (ns == 1) {
			for (i = 0; i < 30; i++) {
				printf("\n%s",tw[i]);
			}
		}
		if (ns == 2) {
			for (i = 30; i < 60; i++) {
				printf("\n%s",tw[i]);
			}
		}
		if (ns == 3) {
			for (i = 60; i < 90; i++) {
				printf("\n%s",tw[i]);
			}
		}
		printf("\nMove: %d, area: %d",tm,ns);
		a = getch();
		printf("\033[H\033[2J\033[3J");
		if (a == 'w') ns--;
		if (a == 's') ns++;
		if (a == 'x') akt = 0;
	}
	while (akt == 1);
	return 0;
}