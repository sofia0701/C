/*
* ��ȭ��ȣ ���� ������Ʈ 1�ܰ�
* Name : main.c	ver1.0
* Contents : main �Լ�
* Last modified :
*/

#include "common.h" 
#include "screenOut.h" 
#include "phoneFunc.h" 

//������ : ��ȣ������� �� �ִ� �ڷ�, �� ������ 0���� ����
enum { INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT };

/*
* �Լ� : int main()
* ��� : ����� ���� ó��
* ��ȯ : ���� ���� �� 0
*/
int main()
{
	//����ڷκ��� �Է� ���� �޴�(1~3)�� �����ϱ� ���� ����
	int inputMenu = 0;

	/*
	* �޴� ��� -- ShowMenu() ȣ��
	* ����ڷκ��� �޴��� �Է� �޴´�.
	* 1.�̸��� ��ȭ��ȣ�� �Է� -- InputPhoneData() ȣ��
	* 2.��ü ������ ��� -- ShowAllData() ȣ��
	* 3."�̿��� �ּż� ������!"�� ����ϰ�
		�ݺ��� ����� �Բ� ���α׷��� �����Ѵ�.
	*/
	
	
	while (1){
		ShowMenu();
		printf("�����ϼ��� : ");
		scanf_s("%d", &inputMenu);
		getchar();

		if (inputMenu == QUIT)
		{
		puts("�̿��� �ּż� ������!");
		CallFree();
		break;
		}

		switch (inputMenu) {
		case INPUT:
			InputPhoneData();
			break;
		case SHOWALL:
			ShowAllData();
			break;
		case SEARCH:
			SearchPhoneData();
			break;
	
		case DELETE:
			DeletePhoneData();
			break;
		case CHANGE:
			ChangePhoneData();
			break;
		}
	}
	return 0;
}