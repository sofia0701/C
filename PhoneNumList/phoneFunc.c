/*
* ��ȭ��ȣ ���� ������Ʈ 1�ܰ�
* Name : phoneFunc.c	ver1.0
* Contents : ��ȭ��ȣ ��Ʈ�� �Լ�
* Last modified :
*/

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

//����ü �迭 phoneList[100]
//numofData : ����ü �迭 ���� ����
#define LIST_NUM 100
int numofData = 0;
phoneData* phoneList[LIST_NUM];

/*
* �Լ� : void InputPhoneData()
* ��� : ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
* ��ȯ : void
*/
void InputPhoneData()
{
	phoneData* pData;
	int i;				//�߰�(loop����)

	if (numofData >= LIST_NUM)
		puts("�޸� ������ �����մϴ�.");

	pData = (phoneData*)malloc(sizeof(phoneData));
	printf("�̸� �Է� : ");
	gets_s(pData->name, NAME_LEN);
	printf("��ȭ��ȣ �Է� : ");
	gets_s(pData->phoneNum, PHONE_LEN);

	//����ü ������ �迭 ��Ҹ� ��ȸ�ϸ鼭, �̸��� ��ȭ��ȣ�� ��� ��ġ�Ѵٸ� "�̹� �Էµ� ������ �Դϴ�"�� ���
	//�׸��� �Ҵ���� �����޸𸮴� �ݳ� ��, �Լ��� ��������
	for (i = 0; i < numofData; i++)
	{
		if (pData->name == phoneList[i]->name && pData->phoneNum == phoneList[i]->phoneNum)
		{
			puts("�̹� �Էµ� ������ �Դϴ�.");
			getchar();
			return 0;
		}
	}

	phoneList[numofData] = pData;
	numofData++;

	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	getchar();
}


/*
* �Լ� : void ShowAllData()
* ��� : ����� ������ ��ü ���
* ��ȯ : void
*/
void ShowAllData()
{
	
	for (int i = 0; i < numofData; i++)
		ShowPhoneInfoByPtr(phoneList[i]);
		
	//return 0;
	/*�ڵ� �ۼ�*/

	puts("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

void SearchPhoneData()
{
	int i;
	char searchName[NAME_LEN];
	int searchFlag = 0;		//�߰� -- ã���� 1, �� ã���� 0

	printf("ã�� �̸���? ");
	gets_s(searchName, NAME_LEN);

	//����ü�����͹迭�� ��ȸ�ϸ鼭, ã�� �̸��� ���ٸ� ShowPhoneInfoByPtr�� ȣ���Ͽ� ����Ѵ�.
	//�׸��� searchFlag�� 1�� ����
	for (i = 0; i < numofData; i++)
	{
		if (strcmp(searchName, phoneList[i]->name)==0) {
			ShowPhoneInfoByPtr(phoneList[i]);
			searchFlag = 1;
		}
	}

	//����, �� ã�Ҵٸ� "ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�."�� ����ϰ�, ã�Ҵٸ� "�˻��� �Ϸ�Ǿ����ϴ�"�� ����Ѵ�.
	if (searchFlag == 0)
		puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");

	else
		puts("�˻��� �Ϸ�Ǿ����ϴ�.");

	getchar();
}

/*
* �Լ� : void DeletePhoneData()
* ��� : �̸��� �����Ͽ� ������ ����
* ��ȯ : void
*/
void DeletePhoneData()
{
	int i, j;
	char delName[NAME_LEN];
	char delPhoneNum[PHONE_LEN];		//�߰� -- �����ϰ��� �ϴ� ��ȭ��ȣ�� �����ϱ� ���� ����
	int matchedCount = 0;
	int indexOfMatching;			//�߰� -- ���������� �ο� ��

	printf("ã�� �̸���? ");
	gets_s(delName, NAME_LEN);

	//����ü�����͹迭�� ��ȸ�ϸ鼭 ���������� �ִ��� Ȯ���ϰ� �ο��� üũ
	for (i = 0; i < numofData; i++)
	{
		/* �ڵ� �ϼ� */
		if (strcmp(delName, phoneList[i]->name)==0) {
			ShowPhoneInfoByPtr(phoneList[i]);
			matchedCount++;
			indexOfMatching = 1;
		}
	}

	//����, ���������� ���ٸ� "ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�" ����ϰ� �Լ��� ����������.
	if (matchedCount == 0)
	{
		/* �ڵ� �ϼ� */
		puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
		getchar();
		return 0;
	}
	else if (matchedCount == 1) {
		ShowPhoneInfoByPtr(phoneList[indexOfMatching]);
	}
	//�׷��� �ʴٸ�, ���������� �����ϹǷ� ��ȭ��ȣ�� �߰��� �Է¹޴´�.
	else
	{
		/* �ڵ� �ϼ� */
		puts("���������� �����մϴ�. ��ȭ��ȣ�� �Է��ϼ��� : ");
		gets_s(delPhoneNum, PHONE_LEN);
		for (i = 0;i < numofData;i++) {
			if ((strcmp(phoneList[i]->name, delName) == 0) && (strcmp(phoneList[i]->phoneNum, delPhoneNum) == 0)) {
				indexOfMatching = i;
				ShowPhoneInfoByPtr(phoneList[indexOfMatching]);
			}
		}
	}

	//����ü�����͹迭�� ��ȸ�ϸ鼭 �̸��� ��ȭ��ȣ�� ��� ��ġ�Ѵٸ�
	//������ ����� ������ ShowPhoneInfoByPtr�Լ��� ȣ���Ͽ� ����ϰ� �����Ѵ�.
	for (i = indexOfMatching; i < numofData; i++)
		phoneList[i] = phoneList[i + 1];

	numofData--;
	puts("������ �Ϸ�Ǿ����ϴ�.");
	getchar();		
}
void ChangePhoneData()
{
	int i;
	char searchName[NAME_LEN];
	char searchPhoneNumber[PHONE_LEN];	//���������� �ִٸ� �����ϰ��� �ϴ� ��ȭ��ȣ
	char newPhoneNumber[PHONE_LEN];		//���ο� ��ȭ��ȣ
	int matchedCount = 0;
	int idxOfMatching;					//�����ϰ��� �ϴ� ���� ����ִ� �ε��� ��ȣ�� ����

	printf("���� ����� �̸���? ");
	gets_s(searchName, NAME_LEN);

	//����ü�����͹迭�� ��ȸ�ϸ鼭 ���������� �ִ��� Ȯ���ϰ� �ο��� üũ �� �ش� �ε��� ��ȣ �����Ѵ�
	for (i = 0; i < numofData; i++)
	{
		if (strcmp(searchName, phoneList[i]->name) == 0) {
			ShowPhoneInfoByPtr(phoneList[i]);
			matchedCount++;
			idxOfMatching = 1;
		}
		/* �ڵ� �ϼ� */
	}

	//���������� ���ٸ� "���� ��� �̸��� �������� �ʽ��ϴ�" ����ϰ� �Լ��� ����������
	if (matchedCount==0)
	{
		/* �ڵ� �ϼ� */
		puts("���� ��� �̸��� �������� �ʽ��ϴ�.");
		getchar();
		return 0;
	}

	//matchedCount�� 1�̶�� �����ϰ����ϴ� �̸��� �����Ͱ� �ϳ��� �����ϹǷ� ���� ����� ������ ����Ѵ�
	else if (matchedCount==1)
	{
		ShowPhoneInfoByPtr(phoneList[idxOfMatching]);
		/* �ڵ� �ϼ� */
	}

	//�׷��� �ʴٸ�, ���������� �����ϹǷ� ��ȭ��ȣ�� �߰��� �Է¹޴´�
	//����ü�����͹迭�� ��ȸ�ϸ鼭 �̸��� ��ȭ��ȣ�� ��� ��ġ�Ѵٸ� �ε�����ȣ�� �����ϰ�,
	//������ ����� ������ ����Ѵ�
	else
	{
		puts("���������� �����մϴ�. ��ȭ��ȣ�� �Է��ϼ��� : ");
		gets_s(searchPhoneNumber, PHONE_LEN);
		for (i = 0;i < numofData;i++) {
			if ((strcmp(phoneList[i]->name, searchName) == 0) && (strcmp(phoneList[i]->phoneNum, searchPhoneNumber) == 0)) {
				idxOfMatching = i;
				ShowPhoneInfoByPtr(phoneList[idxOfMatching]);
			}
		}
		/* �ڵ� �ϼ� */
	}

	//������ ��ȭ��ȣ�� �Է� ���� ��, ����ü�� phoneNum�� ���� ��ȭ��ȣ�� �����Ѵ�. -- strcpy�Լ�
	/* �ڵ� �ϼ� */

	puts("������ ��ȭ��ȣ��?");
	gets_s(newPhoneNumber, PHONE_LEN);
	strcpy_s(phoneList[idxOfMatching]->phoneNum , PHONE_LEN, newPhoneNumber);
	puts("������ �Ϸ�Ǿ����ϴ�.");
	getchar();
}
void CallFree() {
	int i;
	for (i = 0;i < numofData;i++) {
		free(phoneList[i]);
	}
}