#include "BaseAddress.h"

BYTE jδ֪����������[] = { 0x48, 0x89, 0x5C, 0x24, 0x18, 0x48, 0x89, 0x6C, 0x24, 0x20, 0x56, 0x57, 0x41, 0x54, 0x41, 0x55,0x41, 0x56 };
BYTE j����call������[] = { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x0F, 0xB6, 0xDA, 0x45, 0x33, 0xC0, 0x33, 0xD2 };
BYTE jȡ������call������[] = { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x0F, 0xB6, 0xDA, 0x45, 0x33, 0xC0, 0x33, 0xD2 };
BYTE jʹ����Ʒcall������[] = { 0x33, 0xC9, 0x44, 0x89, 0x49, 0x0C, 0x89, 0x49, 0x10, 0x48, 0x8B, 0x5C, 0x24, 0x08, 0xC3, 0x48,0x83, 0xC1, 0x08, 0x44, 0x89, 0x49, 0x0C, 0xC7, 0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8B,
0x5C, 0x24, 0x08, 0xC3 };
BYTE j����װ��call������[] = { 0x48, 0x8B, 0x5C, 0x24, 0x30, 0x48, 0x8B, 0x6C, 0x24, 0x38, 0x48, 0x8B, 0x74, 0x24, 0x40, 0x48,0x8B, 0x7C, 0x24, 0x48, 0x48, 0x83, 0xC4, 0x20, 0x41, 0x5E, 0xC3, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,0xCC, 0xCC, 0x40, 0x57, 0x48, 0x83, 0xEC, 0x40, 0x48, 0x8B, 0xF9 };
BYTE j��������ƫ�Ƶ�������[] = { 0x48, 0x8B, 0x07, 0x41, 0xB1, 0x01, 0x45, 0x33, 0xC0, 0x41, 0x0F, 0xB6, 0xD1, 0x48, 0x8B, 0xCF,
0x48, 0x8B, 0x6C, 0x24, 0x50, 0x48, 0x8B, 0x5C, 0x24, 0x58, 0x48, 0x8B, 0x74, 0x24, 0x60, 0x48,
0x83, 0xC4, 0x40, 0x5F };



BaseAddress::BaseAddress()
{
	this->operator=(0);
	

}


bool BaseAddress::init()
{

	FMC::init(::getpid(), L"elementclient64.exe");

	this->j���˶��� = this->�����붨λ��ַ(jδ֪����������, sizeof(jδ֪����������), 0x42, 3, 4, 7);
	if (!this->j���˶���)
	{
		return false;
	}
	this->j���˶��� = *((QWORD*)((*((QWORD*)((*((QWORD*)this->j���˶���)) + 0x38))) + 0x60));
	if (!this->j���˶���)
	{
		return false;
	}


	this->j����call = this->�����붨λ��ַ(j����call������, sizeof(j����call������), 0x21, 1, 4, 5);
	if (!this->j����call)
	{
		return false;
	}


	this->jȡ������call = this->�����붨λ��ַ(jȡ������call������, sizeof(jȡ������call������), 0x33, 1, 4, 5);
	if (!this->jȡ������call)
	{
		return false;
	}


	this->jʹ����Ʒcall = this->�����붨λcall(jʹ����Ʒcall������, sizeof(jʹ����Ʒcall������), 0x29);
	if (!this->jʹ����Ʒcall)
	{
		return false;
	}


	this->j����װ��call = this->�����붨λ��ַ(j����װ��call������, sizeof(j����װ��call������), -5, 1, 4, 5);
	if (!this->j����װ��call)
	{
		return false;
	}


	this->j���������ƫ�� = this->�����붨λƫ��(j��������ƫ�Ƶ�������, sizeof(j��������ƫ�Ƶ�������), 0x446, 3, 4);
	if (!this->j���������ƫ��)
	{
		return false;
	}


	return true;



}

QWORD BaseAddress::��ȡ���˶���()
{
	return this->j���˶���;
}

QWORD BaseAddress::��ȡ����call()
{
	return this->j����call;
}

QWORD BaseAddress::ȡ������call()
{
	return this->jȡ������call;
}

QWORD BaseAddress::����װ��call()
{
	return this->j����װ��call;
}

QWORD BaseAddress::ʹ����Ʒcall()
{
	return this->jʹ����Ʒcall;
}

QWORD BaseAddress::���������ƫ��()
{
	return this->j���������ƫ��;
}

BaseAddress& BaseAddress::operator=(IN UINT value)
{
	this->j���˶��� = value;
	this->j����call = value;
	this->jȡ������call = value;
	this->jʹ����Ʒcall = value;
	this->j���������ƫ�� = value;
	this->j����װ��call = value;

	return *this;
}

CString BaseAddress::getBaseAddressData()
{
	//��ַ����
	CString cstr;
	cstr.AppendFormat(L"���˶���: %llX\r\n", this->j���˶���);
	cstr.AppendFormat(L"����Call: %llX\r\n", this->j����call);
	cstr.AppendFormat(L"ȡ������Call: %llX\r\n", this->jȡ������call);
	cstr.AppendFormat(L"����װ��Call: %llX\r\n", this->j����װ��call);
	cstr.AppendFormat(L"ʹ����ƷCall: %llX\r\n", this->jʹ����Ʒcall);
	cstr.AppendFormat(L"���������ƫ��: %llX\r\n", this->j���������ƫ��);

	return cstr;
}

/*
	QWORD j���˶���;
	QWORD j����call;
	QWORD jȡ������call;
	QWORD j����װ��call;
	QWORD jʹ����Ʒcall;
	QWORD j���������ƫ��;
*/


BaseAddress::~BaseAddress()
{
	
}

