#include "BaseAddress.h"

BYTE j未知对象特征码[] = { 0x48, 0x89, 0x5C, 0x24, 0x18, 0x48, 0x89, 0x6C, 0x24, 0x20, 0x56, 0x57, 0x41, 0x54, 0x41, 0x55,0x41, 0x56 };
BYTE j打坐call特征码[] = { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x0F, 0xB6, 0xDA, 0x45, 0x33, 0xC0, 0x33, 0xD2 };
BYTE j取消打坐call特征码[] = { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x0F, 0xB6, 0xDA, 0x45, 0x33, 0xC0, 0x33, 0xD2 };
BYTE j使用物品call特征码[] = { 0x33, 0xC9, 0x44, 0x89, 0x49, 0x0C, 0x89, 0x49, 0x10, 0x48, 0x8B, 0x5C, 0x24, 0x08, 0xC3, 0x48,0x83, 0xC1, 0x08, 0x44, 0x89, 0x49, 0x0C, 0xC7, 0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8B,
0x5C, 0x24, 0x08, 0xC3 };
BYTE j整理装备call特征码[] = { 0x48, 0x8B, 0x5C, 0x24, 0x30, 0x48, 0x8B, 0x6C, 0x24, 0x38, 0x48, 0x8B, 0x74, 0x24, 0x40, 0x48,0x8B, 0x7C, 0x24, 0x48, 0x48, 0x83, 0xC4, 0x20, 0x41, 0x5E, 0xC3, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,0xCC, 0xCC, 0x40, 0x57, 0x48, 0x83, 0xEC, 0x40, 0x48, 0x8B, 0xF9 };
BYTE j背包对象偏移的特征码[] = { 0x48, 0x8B, 0x07, 0x41, 0xB1, 0x01, 0x45, 0x33, 0xC0, 0x41, 0x0F, 0xB6, 0xD1, 0x48, 0x8B, 0xCF,
0x48, 0x8B, 0x6C, 0x24, 0x50, 0x48, 0x8B, 0x5C, 0x24, 0x58, 0x48, 0x8B, 0x74, 0x24, 0x60, 0x48,
0x83, 0xC4, 0x40, 0x5F };



BaseAddress::BaseAddress()
{
	this->operator=(0);
	

}


bool BaseAddress::init()
{

	FMC::init(::getpid(), L"elementclient64.exe");

	this->j本人对象 = this->特征码定位基址(j未知对象特征码, sizeof(j未知对象特征码), 0x42, 3, 4, 7);
	if (!this->j本人对象)
	{
		return false;
	}
	this->j本人对象 = *((QWORD*)((*((QWORD*)((*((QWORD*)this->j本人对象)) + 0x38))) + 0x60));
	if (!this->j本人对象)
	{
		return false;
	}


	this->j打坐call = this->特征码定位基址(j打坐call特征码, sizeof(j打坐call特征码), 0x21, 1, 4, 5);
	if (!this->j打坐call)
	{
		return false;
	}


	this->j取消打坐call = this->特征码定位基址(j取消打坐call特征码, sizeof(j取消打坐call特征码), 0x33, 1, 4, 5);
	if (!this->j取消打坐call)
	{
		return false;
	}


	this->j使用物品call = this->特征码定位call(j使用物品call特征码, sizeof(j使用物品call特征码), 0x29);
	if (!this->j使用物品call)
	{
		return false;
	}


	this->j整理装备call = this->特征码定位基址(j整理装备call特征码, sizeof(j整理装备call特征码), -5, 1, 4, 5);
	if (!this->j整理装备call)
	{
		return false;
	}


	this->j背包对象的偏移 = this->特征码定位偏移(j背包对象偏移的特征码, sizeof(j背包对象偏移的特征码), 0x446, 3, 4);
	if (!this->j背包对象的偏移)
	{
		return false;
	}


	return true;



}

QWORD BaseAddress::获取本人对象()
{
	return this->j本人对象;
}

QWORD BaseAddress::获取打坐call()
{
	return this->j打坐call;
}

QWORD BaseAddress::取消打坐call()
{
	return this->j取消打坐call;
}

QWORD BaseAddress::整理装备call()
{
	return this->j整理装备call;
}

QWORD BaseAddress::使用物品call()
{
	return this->j使用物品call;
}

QWORD BaseAddress::背包对象的偏移()
{
	return this->j背包对象的偏移;
}

BaseAddress& BaseAddress::operator=(IN UINT value)
{
	this->j本人对象 = value;
	this->j打坐call = value;
	this->j取消打坐call = value;
	this->j使用物品call = value;
	this->j背包对象的偏移 = value;
	this->j整理装备call = value;

	return *this;
}

BaseAddress::~BaseAddress()
{

}


