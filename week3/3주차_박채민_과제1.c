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
		printf("연산을 선택하시오 : ");
		scanf_s("%c", &calc, 1);
		// rewind(stdin);
		if (calc == 'Q')
			break;
		else if (calc == 'A') {
			printf("두 수를 공백으로 분리하여 입력하시오 : ");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", a + b);
		}
		else if (calc == 'S') {
			printf("두 수를 공백으로 분리하여 입력하시오 : ");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", a - b);
		}
		else  if (calc == 'M') {
			printf("두 수를 공백으로 분리하여 입력하시오 : ");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", a * b);
		}
		else if (calc == 'D') {
			printf("두 수를 공백으로 분리하여 입력하시오 : ");
			scanf_s("%d %d", &a, &b);
			printf("%d\n", a / b);
		}
		else {
			printf("calc='%c'", calc);
			printf("지원되지 않는 연산자입니다.\n");
		}
	}
	return 0;
}