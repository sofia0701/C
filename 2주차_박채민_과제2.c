#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	float pi = 3.14;
	int dis = 0;
	float degree = 0;
	double r;
	printf("�Ÿ��� �Է��Ͻÿ� (km) : ");
	scanf("%d", &dis);
	printf("������ �Է��Ͻÿ� : ");
	scanf("%f", &degree);
	r = (360 * dis) / (degree * 2 * pi);
	printf("%lf", r);
	printf("������ �������� %.3lf km", r);
	return 0;
}