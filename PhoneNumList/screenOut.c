/*
* 전화번호 관리 프로젝트 1단계
* Name : screenOut.c	ver1.0
* Contents : 콘솔 출력을 위한 함수 정의
* Last modified :
*/

#include "common.h"
#include "phoneData.h"

/*
* 함수 : void ShowMenu()
* 기능 : 선택을 위한 메뉴 출력
* 반환 : void
*/
void ShowMenu()
{
	system("cls");		//stdlib.h -- 콘솔화면 clear

	printf("--------------메뉴-------------\n");
	printf("1. 전화번호 입력\n2. 전체 정보 출력\n3. 전화번호 검색\n4. 전화번호 삭제\n5. 전화번호 변경\n6. 종료\n");
	printf("-------------------------------\n");
	printf("선택 >> ");
	//1.전화번호 입력 2.전체 정보 출력 3.전화번호 검색 4.전화번호 삭제 5.종료
}

/*
* 함수 : void ShowPhoneInfo(phoneData phone)
* 기능 : 이름과 전화번호 정보 출력
* 반환 : void
*/
void ShowPhoneInfo(phoneData phone)
{
	printf("┌──────────────────────────────────────\n");
	printf("│ ▶ 이름 : %s\n", phone.name);
	printf("│ ▶ 전화번호 : %s\n", phone.phoneNum);
	printf("└──────────────────────────────────────\n\n");
	getchar();
}

void ShowPhoneInfoByPtr(phoneData* phone)
{
	printf("%s", phone->name);
	printf("%s", phone->phoneNum);
	getchar();
	//name과 phoneNum을 포인터변수 phone으로 접근하여 출력
	/*코드 수정*/
}