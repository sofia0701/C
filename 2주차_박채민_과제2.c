#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	float pi = 3.14;
	int dis = 0;
	float degree = 0;
	double r;
	printf("거리를 입력하시오 (km) : ");
	scanf("%d", &dis);
	printf("각도를 입력하시오 : ");
	scanf("%f", &degree);
	r = (360 * dis) / (degree * 2 * pi);
	printf("%lf", r);
	printf("지구의 반지름은 %.3lf km", r);
	return 0;
}