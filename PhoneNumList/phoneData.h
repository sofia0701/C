/*
* Name : phoneData.h	ver1.0
* Contents : ����ü phoneData�� ���� �� ����
* Last modified :
*/

#ifndef __PHONEDATA_H__
#define __PHONEDATA_H__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __phoneData
{
	char name[NAME_LEN];		//�̸�
	char phoneNum[PHONE_LEN];	//��ȭ��ȣ
} phoneData;

#endif

