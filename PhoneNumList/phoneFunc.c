/*
* 전화번호 관리 프로젝트 1단계
* Name : phoneFunc.c	ver1.0
* Contents : 전화번호 컨트롤 함수
* Last modified :
*/

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

//구조체 배열 phoneList[100]
//numofData : 구조체 배열 개수 저장
#define LIST_NUM 100
int numofData = 0;
phoneData* phoneList[LIST_NUM];

/*
* 함수 : void InputPhoneData()
* 기능 : 전화번호 관련 데이터 입력 받아서 저장
* 반환 : void
*/
void InputPhoneData()
{
	phoneData* pData;
	int i;				//추가(loop변수)

	if (numofData >= LIST_NUM)
		puts("메모리 공간이 부족합니다.");

	pData = (phoneData*)malloc(sizeof(phoneData));
	printf("이름 입력 : ");
	gets_s(pData->name, NAME_LEN);
	printf("전화번호 입력 : ");
	gets_s(pData->phoneNum, PHONE_LEN);

	//구조체 포인터 배열 요소를 순회하면서, 이름과 전화번호가 모두 일치한다면 "이미 입력된 데이터 입니다"를 출력
	//그리고 할당받은 동적메모리는 반납 후, 함수를 빠져나옴
	for (i = 0; i < numofData; i++)
	{
		if (pData->name == phoneList[i]->name && pData->phoneNum == phoneList[i]->phoneNum)
		{
			puts("이미 입력된 데이터 입니다.");
			getchar();
			return 0;
		}
	}

	phoneList[numofData] = pData;
	numofData++;

	puts("입력이 완료되었습니다.");
	getchar();
}


/*
* 함수 : void ShowAllData()
* 기능 : 저장된 데이터 전체 출력
* 반환 : void
*/
void ShowAllData()
{
	
	for (int i = 0; i < numofData; i++)
		ShowPhoneInfoByPtr(phoneList[i]);
		
	//return 0;
	/*코드 작성*/

	puts("출력이 완료되었습니다.");
	getchar();
}

void SearchPhoneData()
{
	int i;
	char searchName[NAME_LEN];
	int searchFlag = 0;		//추가 -- 찾으면 1, 못 찾으면 0

	printf("찾는 이름은? ");
	gets_s(searchName, NAME_LEN);

	//구조체포인터배열을 순회하면서, 찾는 이름과 같다면 ShowPhoneInfoByPtr를 호출하여 출력한다.
	//그리고 searchFlag는 1로 변경
	for (i = 0; i < numofData; i++)
	{
		if (strcmp(searchName, phoneList[i]->name)==0) {
			ShowPhoneInfoByPtr(phoneList[i]);
			searchFlag = 1;
		}
	}

	//만약, 못 찾았다면 "찾는 이름의 데이터가 존재하지 않습니다."을 출력하고, 찾았다면 "검색이 완료되었습니다"를 출력한다.
	if (searchFlag == 0)
		puts("찾는 이름의 데이터가 존재하지 않습니다.");

	else
		puts("검색이 완료되었습니다.");

	getchar();
}

/*
* 함수 : void DeletePhoneData()
* 기능 : 이름을 참조하여 데이터 삭제
* 반환 : void
*/
void DeletePhoneData()
{
	int i, j;
	char delName[NAME_LEN];
	char delPhoneNum[PHONE_LEN];		//추가 -- 삭제하고자 하는 전화번호를 저장하기 위한 공간
	int matchedCount = 0;
	int indexOfMatching;			//추가 -- 동명이인이 인원 수

	printf("찾는 이름은? ");
	gets_s(delName, NAME_LEN);

	//구조체포인터배열을 순회하면서 동명이인이 있는지 확인하고 인원수 체크
	for (i = 0; i < numofData; i++)
	{
		/* 코드 완성 */
		if (strcmp(delName, phoneList[i]->name)==0) {
			ShowPhoneInfoByPtr(phoneList[i]);
			matchedCount++;
			indexOfMatching = 1;
		}
	}

	//만약, 동명이인이 없다면 "찾는 이름의 데이터가 존재하지 않습니다" 출력하고 함수를 빠져나간다.
	if (matchedCount == 0)
	{
		/* 코드 완성 */
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
		getchar();
		return 0;
	}
	else if (matchedCount == 1) {
		ShowPhoneInfoByPtr(phoneList[indexOfMatching]);
	}
	//그렇지 않다면, 동명이인이 존재하므로 전화번호도 추가로 입력받는다.
	else
	{
		/* 코드 완성 */
		puts("동명이인이 존재합니다. 전화번호를 입력하세요 : ");
		gets_s(delPhoneNum, PHONE_LEN);
		for (i = 0;i < numofData;i++) {
			if ((strcmp(phoneList[i]->name, delName) == 0) && (strcmp(phoneList[i]->phoneNum, delPhoneNum) == 0)) {
				indexOfMatching = i;
				ShowPhoneInfoByPtr(phoneList[indexOfMatching]);
			}
		}
	}

	//구조체포인터배열을 순회하면서 이름과 전화번호가 모두 일치한다면
	//삭제할 대상의 정보를 ShowPhoneInfoByPtr함수를 호출하여 출력하고 삭제한다.
	for (i = indexOfMatching; i < numofData; i++)
		phoneList[i] = phoneList[i + 1];

	numofData--;
	puts("삭제가 완료되었습니다.");
	getchar();		
}
void ChangePhoneData()
{
	int i;
	char searchName[NAME_LEN];
	char searchPhoneNumber[PHONE_LEN];	//동명이인이 있다면 변경하고자 하는 전화번호
	char newPhoneNumber[PHONE_LEN];		//새로운 전화번호
	int matchedCount = 0;
	int idxOfMatching;					//변경하고자 하는 값이 들어있는 인덱스 번호를 저장

	printf("변경 대상의 이름은? ");
	gets_s(searchName, NAME_LEN);

	//구조체포인터배열을 순회하면서 동명이인이 있는지 확인하고 인원수 체크 및 해당 인덱스 번호 저장한다
	for (i = 0; i < numofData; i++)
	{
		if (strcmp(searchName, phoneList[i]->name) == 0) {
			ShowPhoneInfoByPtr(phoneList[i]);
			matchedCount++;
			idxOfMatching = 1;
		}
		/* 코드 완성 */
	}

	//동명이인이 없다면 "변경 대상 이름이 존재하지 않습니다" 출력하고 함수를 빠져나간다
	if (matchedCount==0)
	{
		/* 코드 완성 */
		puts("변경 대상 이름이 존재하지 않습니다.");
		getchar();
		return 0;
	}

	//matchedCount가 1이라면 변경하고자하는 이름의 데이터가 하나만 존재하므로 변경 대상의 정보를 출력한다
	else if (matchedCount==1)
	{
		ShowPhoneInfoByPtr(phoneList[idxOfMatching]);
		/* 코드 완성 */
	}

	//그렇지 않다면, 동명이인이 존재하므로 전화번호도 추가로 입력받는다
	//구조체포인터배열을 순회하면서 이름과 전화번호가 모두 일치한다면 인덱스번호를 저장하고,
	//변경할 대상의 정보를 출력한다
	else
	{
		puts("동명이인이 존재합니다. 전화번호를 입력하세요 : ");
		gets_s(searchPhoneNumber, PHONE_LEN);
		for (i = 0;i < numofData;i++) {
			if ((strcmp(phoneList[i]->name, searchName) == 0) && (strcmp(phoneList[i]->phoneNum, searchPhoneNumber) == 0)) {
				idxOfMatching = i;
				ShowPhoneInfoByPtr(phoneList[idxOfMatching]);
			}
		}
		/* 코드 완성 */
	}

	//변경할 전화번호를 입력 받은 후, 구조체의 phoneNum에 변경 전화번호로 수정한다. -- strcpy함수
	/* 코드 완성 */

	puts("변경할 전화번호는?");
	gets_s(newPhoneNumber, PHONE_LEN);
	strcpy_s(phoneList[idxOfMatching]->phoneNum , PHONE_LEN, newPhoneNumber);
	puts("변경이 완료되었습니다.");
	getchar();
}
void CallFree() {
	int i;
	for (i = 0;i < numofData;i++) {
		free(phoneList[i]);
	}
}