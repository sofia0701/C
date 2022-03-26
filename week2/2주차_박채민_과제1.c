#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int stick_sh=0;
	int pyramid_sh=0;
	float pyramid=0;
	int stick=0;
	printf("지팡이 그림자의 길이를 입력하시오 : ");
	scanf("%d", &stick_sh);
	printf("피라미드 그림자의 길이를 입력하시오 : ");
	scanf("%d", &pyramid_sh);
	printf("지팡이의 길이를 입력하시오 : ");
	scanf("%d", &stick);
	pyramid = (stick * pyramid_sh) / stick_sh;
	printf("피라미드의 높이는 %.2f입니다.", pyramid);
	return 0;
}