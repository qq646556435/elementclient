#ifndef __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#define __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#pragma once
#pragma warning(disable : 4996)
#include "../../pch.h"
#include "../FMC/FMC.h"

class BaseAddress:public FMC
{
private:

	QWORD j本人对象;
	QWORD j打坐call;
	QWORD j取消打坐call;
	QWORD j整理装备call;
	QWORD j使用物品call;
	QWORD j背包对象的偏移;
	
public:
	BaseAddress();
	virtual ~BaseAddress();
	bool virtual init();
	QWORD  获取本人对象();
	QWORD  获取打坐call();
	QWORD  取消打坐call();
	QWORD  整理装备call();
	QWORD  使用物品call();
	QWORD  背包对象的偏移();
	BaseAddress& operator=(IN UINT value);
};



#endif

