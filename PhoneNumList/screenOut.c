/*
* ��ȭ��ȣ ���� ������Ʈ 1�ܰ�
* Name : screenOut.c	ver1.0
* Contents : �ܼ� ����� ���� �Լ� ����
* Last modified :
*/

#include "common.h"
#include "phoneData.h"

/*
* �Լ� : void ShowMenu()
* ��� : ������ ���� �޴� ���
* ��ȯ : void
*/
void ShowMenu()
{
	system("cls");		//stdlib.h -- �ܼ�ȭ�� clear

	printf("--------------�޴�-------------\n");
	printf("1. ��ȭ��ȣ �Է�\n2. ��ü ���� ���\n3. ��ȭ��ȣ �˻�\n4. ��ȭ��ȣ ����\n5. ��ȭ��ȣ ����\n6. ����\n");
	printf("-------------------------------\n");
	printf("���� >> ");
	//1.��ȭ��ȣ �Է� 2.��ü ���� ��� 3.��ȭ��ȣ �˻� 4.��ȭ��ȣ ���� 5.����
}

/*
* �Լ� : void ShowPhoneInfo(phoneData phone)
* ��� : �̸��� ��ȭ��ȣ ���� ���
* ��ȯ : void
*/
void ShowPhoneInfo(phoneData phone)
{
	printf("������������������������������������������������������������������������������\n");
	printf("�� �� �̸� : %s\n", phone.name);
	printf("�� �� ��ȭ��ȣ : %s\n", phone.phoneNum);
	printf("������������������������������������������������������������������������������\n\n");
	getchar();
}

void ShowPhoneInfoByPtr(phoneData* phone)
{
	printf("%s", phone->name);
	printf("%s", phone->phoneNum);
	getchar();
	//name�� phoneNum�� �����ͺ��� phone���� �����Ͽ� ���
	/*�ڵ� ����*/
}