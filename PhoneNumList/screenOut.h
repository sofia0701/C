/*
* Name : screenOut.h	ver1.1
  -- 3단계(ShowPhoneInfoByPtr 함수원형 추가)
* Contents : 콘솔 출력을 위한 함수 선언
* Last modified :
*/

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h"

void ShowMenu();
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(phoneData* phone);		//추가

#endif