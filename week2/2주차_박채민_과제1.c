#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int stick_sh=0;
	int pyramid_sh=0;
	float pyramid=0;
	int stick=0;
	printf("������ �׸����� ���̸� �Է��Ͻÿ� : ");
	scanf("%d", &stick_sh);
	printf("�Ƕ�̵� �׸����� ���̸� �Է��Ͻÿ� : ");
	scanf("%d", &pyramid_sh);
	printf("�������� ���̸� �Է��Ͻÿ� : ");
	scanf("%d", &stick);
	pyramid = (stick * pyramid_sh) / stick_sh;
	printf("�Ƕ�̵��� ���̴� %.2f�Դϴ�.", pyramid);
	return 0;
}