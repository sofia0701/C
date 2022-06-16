/*
* 전화번호 관리 프로젝트 1단계
* Name : main.c	ver1.0
* Contents : main 함수
* Last modified :
*/

#include "common.h" 
#include "screenOut.h" 
#include "phoneFunc.h" 

//열거형 : 기호상수들이 모여 있는 자료, 값 생략시 0부터 시작
enum { INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT };

/*
* 함수 : int main()
* 기능 : 사용자 선택 처리
* 반환 : 정상 종료 시 0
*/
int main()
{
	//사용자로부터 입력 받은 메뉴(1~3)를 저장하기 위한 변수
	int inputMenu = 0;

	/*
	* 메뉴 출력 -- ShowMenu() 호출
	* 사용자로부터 메뉴를 입력 받는다.
	* 1.이름과 전화번호를 입력 -- InputPhoneData() 호출
	* 2.전체 정보를 출력 -- ShowAllData() 호출
	* 3."이용해 주셔서 고마워요!"를 출력하고
		반복문 종료와 함께 프로그램도 종료한다.
	*/
	
	
	while (1){
		ShowMenu();
		printf("선택하세요 : ");
		scanf_s("%d", &inputMenu);
		getchar();

		if (inputMenu == QUIT)
		{
		puts("이용해 주셔서 고마워요!");
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