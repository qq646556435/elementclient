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
BYTE jPacketizationFeatureCode[] = { 0x48, 0x81, 0xC4, 0x18, 0x01, 0x00, 0x00, 0x41, 0x5F, 0x41, 0x5E, 0x5F, 0x5E, 0x5B, 0x5D, 0xC3,0xCC, 0xCC, 0xCC, 0xCC, 0x48, 0x8B, 0xC4, 0x57, 0x48, 0x83, 0xEC, 0x60 };//组包特征码
BYTE jRemoteItemDestructionCallFeatureCode[] = { 0xB8, 0x63, 0x02, 0x00, 0x00, 0x41, 0xB8, 0x06, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3, 0x89, 0x7B, 0x02 };//远程销毁物品Call的特征码
BYTE jBagOfHoldingCallFeatureCode[] = { 0xB8, 0x2A, 0x01, 0x00, 0x00, 0x41, 0xB8, 0x02, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3 };//乾坤袋Call的特征码

BaseAddress::BaseAddress()
{
	this->operator=(0);
	

}


bool BaseAddress::init()
{

	FMC::init(::getpid(), L"elementclient64.exe");

	this->j未知对象指针 = this->特征码定位基址(j未知对象特征码, sizeof(j未知对象特征码), 0x42, 3, 4, 7);
	if (!this->j未知对象指针)
	{
		return false;
	}
	this->j本人对象 = *((QWORD*)((*((QWORD*)((*((QWORD*)this->j未知对象指针)) + 0x38))) + 0x60));
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

	this->jRemoteItemDestructionCall = this->特征码定位call(jRemoteItemDestructionCallFeatureCode, sizeof(jRemoteItemDestructionCallFeatureCode), 0x42);
	if (!this->jRemoteItemDestructionCall)
	{
		return false;
	}

	this->j未知对象 = *((QWORD*)this->j未知对象指针);
	if (!this->j未知对象)
	{
		return false;
	}

	this->jPacketizationCall = this->特征码定位call(jPacketizationFeatureCode, sizeof(jPacketizationFeatureCode), 0x114);
	if (!this->jPacketizationCall)
	{
		return false;
	}

	this->jBagOfHoldingCall = this->特征码定位call(jBagOfHoldingCallFeatureCode, sizeof(jBagOfHoldingCallFeatureCode), 0x38);
	if (!this->jBagOfHoldingCall)
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

QWORD BaseAddress::getRemoteItemDestructionCall()
{
	return this->jRemoteItemDestructionCall;
}

QWORD BaseAddress::获取未知对象()
{
	return this->j未知对象;
}

QWORD BaseAddress::getBagOfHoldingCall()
{
	return this->jBagOfHoldingCall;
}

QWORD BaseAddress::getPacketizationCall()
{
	return this->jPacketizationCall;
}

BaseAddress& BaseAddress::operator=(IN UINT value)
{
	this->j本人对象 = value;
	this->j打坐call = value;
	this->j取消打坐call = value;
	this->j使用物品call = value;
	this->j背包对象的偏移 = value;
	this->j整理装备call = value;
	this->jRemoteItemDestructionCall = value;
	this->j未知对象 = value;
	this->j未知对象指针 = value;
	this->jPacketizationCall = value;
	this->jBagOfHoldingCall = value;
	return *this;
}

CString BaseAddress::getBaseAddressData()
{
	//基址数据
	CString cstr;
	cstr.AppendFormat(L"本人对象: %llX\r\n", this->j本人对象);
	cstr.AppendFormat(L"打坐Call: %llX\r\n", this->j打坐call);
	cstr.AppendFormat(L"取消打坐Call: %llX\r\n", this->j取消打坐call);
	cstr.AppendFormat(L"整理装备Call: %llX\r\n", this->j整理装备call);
	cstr.AppendFormat(L"使用物品Call: %llX\r\n", this->j使用物品call);
	cstr.AppendFormat(L"背包对象的偏移: %llX\r\n", this->j背包对象的偏移);
	cstr.AppendFormat(L"远程销毁物品Call: %llX\r\n", this->jRemoteItemDestructionCall);
	cstr.AppendFormat(L"未知对象: %llX\r\n", this->j未知对象);
	cstr.AppendFormat(L"未知对象指针: %llX\r\n", this->j未知对象指针);
	cstr.AppendFormat(L"组包Call: %llx\r\n", this->jPacketizationCall);
	return cstr;
}

/*
	QWORD j本人对象;
	QWORD j打坐call;
	QWORD j取消打坐call;
	QWORD j整理装备call;
	QWORD j使用物品call;
	QWORD j背包对象的偏移;
*/


BaseAddress::~BaseAddress()
{
	
}

