#include<stdio.h>
int main() {
	char* name[3] = { "Áø", "Á¤±¹", "ºß" };
	int score[3][4] = { {90,85,75,0},{65,75,88,0},{100,88,95,0} };
	float av[3] = { 0, };
	char grade[3] = { " " };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			score[i][3] += score[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		av[i] = (float)score[i][3] / 3;
	}
	for (int i = 0; i < 3; i++) {
		if (av[i] >= 90)
			grade[i] = 'A';
		if (av[i] >= 80 && av[i] < 90)
			grade[i] = 'B';
		if (av[i] >= 70 && av[i] < 80)
			grade[i] = 'C';
	}
	for (int i = 0; i < 3; i++) {
		printf("%s	%d %d %d %d %.2f %c\n", name[i], score[i][0], score[i][1], score[i][2], score[i][3], av[i], grade[i]);
	}
}