#include<stdio.h>
int main() {
	int a, b, c, cnt, temp;
	a = 1;
	b = 1;
	c = 0;
	temp = 0;
	printf("���° �ұ��� ���ұ��? ");
	scanf_s("%d", &cnt);
	printf("%d %d", a, b);
	for (int i = 0; i < cnt-2; i++) {
		c = a + b;
		a = b;
		b = c;
		printf(" %d", c);
	}
	return 0;
}