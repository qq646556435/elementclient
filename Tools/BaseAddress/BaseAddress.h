#ifndef __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#define __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#pragma once
#pragma warning(disable : 4996)
#include "../../pch.h"
#include "../FMC/FMC.h"

class BaseAddress:public FMC
{
private:

	QWORD j���˶���;
	QWORD j����call;
	QWORD jȡ������call;
	QWORD j����װ��call;
	QWORD jʹ����Ʒcall;
	QWORD j���������ƫ��;
	
public:
	BaseAddress();
	virtual ~BaseAddress();
	bool virtual init();
	QWORD  ��ȡ���˶���();
	QWORD  ��ȡ����call();
	QWORD  ȡ������call();
	QWORD  ����װ��call();
	QWORD  ʹ����Ʒcall();
	QWORD  ���������ƫ��();
	BaseAddress& operator=(IN UINT value);
};



#endif

