/*
* Name : screenOut.h	ver1.1
  -- 3�ܰ�(ShowPhoneInfoByPtr �Լ����� �߰�)
* Contents : �ܼ� ����� ���� �Լ� ����
* Last modified :
*/

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h"

void ShowMenu();
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(phoneData* phone);		//�߰�

#endif