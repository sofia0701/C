#include<stdio.h>
int main() {
	char calc;
	int a, b;
	while (1) {
		//calc = 'Q';
		printf("************\n");
		printf("A----Add\n");
		printf("S----Subsract\n");
		printf("M----Multiply\n");
		printf("D----Divide\n");
		printf("Q----Quit\n");
		printf("************\n");
		printf("������ �����Ͻÿ� : ");
		scanf_s("%c", &calc, 1);
		// rewind(stdin);
		if (calc == 'Q')
			break;
		else if (calc == 'A') {
			printf("�� ���� �������� �и��Ͽ� �Է��Ͻÿ� : ");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", a + b);
		}
		else if (calc == 'S') {
			printf("�� ���� �������� �и��Ͽ� �Է��Ͻÿ� : ");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", a - b);
		}
		else  if (calc == 'M') {
			printf("�� ���� �������� �и��Ͽ� �Է��Ͻÿ� : ");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", a * b);
		}
		else if (calc == 'D') {
			printf("�� ���� �������� �и��Ͽ� �Է��Ͻÿ� : ");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", a / b);
		}
		else {
			printf("calc='%c'", calc);
			printf("�������� �ʴ� �������Դϴ�.\n");
		}
	}
	return 0;
}