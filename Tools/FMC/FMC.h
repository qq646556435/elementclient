#ifndef __FMC__H_7D44A502_85A6_43E4_B551_503AF56766E8
#define __FMC__H_7D44A502_85A6_43E4_B551_503AF56766E8
#pragma once
#include "../../pch.h"
#include <iostream>

class FMC
{
private:
	HANDLE ���̾��;
	QWORD ��ʼ��ַ;
	QWORD ������ַ;
private:
	QWORD ��ȡģ���ڴ�����(IN QWORD pid, IN std::wstring ģ������);

public:
	FMC();
	FMC(IN QWORD pid, IN std::wstring ģ������);
	virtual ~FMC();
	bool virtual init(IN QWORD pid, IN std::wstring ģ������);
	QWORD virtual �����붨λ��ַ(IN LPBYTE ������, IN size_t �����볤��, IN int ƫ��, IN int ƫ��2, IN int ƫ��3, IN int ƫ��4);
	QWORD virtual �����붨λƫ��(IN LPBYTE ������, IN size_t �����볤��, IN int ƫ��, IN int ƫ��2, IN int ƫ��3);
	QWORD virtual �����붨λcall(IN LPBYTE ������, IN size_t �����볤��, IN int ƫ��);
	FMC& operator=(IN UINT  ��ֵ);
};



#endif // __FMC__H_7D44A502_85A6_43E4_B551_503AF56766E8



