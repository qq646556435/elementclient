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
BYTE jPacketizationFeatureCode[] = { 0x48, 0x81, 0xC4, 0x18, 0x01, 0x00, 0x00, 0x41, 0x5F, 0x41, 0x5E, 0x5F, 0x5E, 0x5B, 0x5D, 0xC3,0xCC, 0xCC, 0xCC, 0xCC, 0x48, 0x8B, 0xC4, 0x57, 0x48, 0x83, 0xEC, 0x60 };//���������
BYTE jRemoteItemDestructionCallFeatureCode[] = { 0xB8, 0x63, 0x02, 0x00, 0x00, 0x41, 0xB8, 0x06, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3, 0x89, 0x7B, 0x02 };//Զ��������ƷCall��������
BYTE jBagOfHoldingCallFeatureCode[] = { 0xB8, 0x2A, 0x01, 0x00, 0x00, 0x41, 0xB8, 0x02, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3 };//Ǭ����Call��������
BYTE jWarehouseOffsetValueFeatureCode[] = { 0x45, 0x33, 0xC9, 0x44, 0x8B, 0x43, 0x14, 0x48, 0x8B, 0xCE, 0x8B, 0x53, 0x18, 0x48, 0x8B, 0x5C,0x24, 0x30, 0x48, 0x8B, 0x74, 0x24, 0x38, 0x48, 0x83, 0xC4, 0x20, 0x5F };//�ֿ����ƫ��ֵ������
BYTE jWarehouseCallFeatureCode[] = { 0xB8, 0xF5, 0x00, 0x00, 0x00, 0x41, 0xB8, 0x07, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3, 0x40, 0x88, 0x73, 0x02, 0x89, 0x7B, 0x03 };
BYTE jOpenWarehouseCallFeatureCode[] = { 0x66, 0x44, 0x89, 0x5C, 0x24, 0x20, 0xC7, 0x44, 0x24, 0x22, 0x4A, 0x00, 0x00, 0x00, 0xC7, 0x44,0x24, 0x26, 0x34, 0x00, 0x00, 0x00, 0x44, 0x89, 0x54, 0x24, 0x2B, 0x66, 0x44, 0x89, 0x4C, 0x24,0x33, 0x88, 0x44, 0x24, 0x41 }; //�򿪲ֿ�Call��������
BYTE jCloseWarehouseCallFeatureCode[] = { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x30, 0x0F, 0xB6, 0xDA, 0xC7, 0x44, 0x24, 0x40, 0x5A, 0x00, 0x00,0x00, 0x48, 0x8D, 0x54, 0x24, 0x40, 0xC7, 0x44, 0x24, 0x20, 0x5A, 0x00, 0x00, 0x00, 0x48, 0x83,0xC1, 0x18, 0x48, 0xC7, 0x44, 0x24, 0x28, 0x00, 0x00, 0x00, 0x00, 0x4C, 0x8D, 0x44, 0x24, 0x20 };//�رղֿ�Call��������
BYTE jUnknownGlobalVariableFeatureCode[] = { 0x05, 0xE8, 0x03, 0x00, 0x00, 0x89, 0x83, 0xAC, 0x03, 0x00, 0x00, 0x48, 0x8B, 0x03, 0x41, 0xB1,0x01, 0x45, 0x33, 0xC0, 0x33, 0xD2, 0x48, 0x8B, 0xCB }; //δ֪��ȫ�ֱ�����������
BYTE jOpen�ֿ��ϰ�������ĶԻ�����CallFeatureCode[] = { 0x8B, 0x87, 0xBC, 0x03, 0x00, 0x00, 0x89, 0x43, 0x38, 0x8B, 0x87, 0xC0, 0x03, 0x00, 0x00, 0x89,0x43, 0x3C, 0x8B, 0x87, 0xC4, 0x03, 0x00, 0x00, 0x89, 0x43, 0x40, 0x48, 0x8B, 0x43, 0x28, 0xC6,0x43, 0x4C, 0x01 }; //�򿪲ֿ��ϰ�������ĶԻ�����Call��������
BYTE j3520OffsetValueFeatureCode[] = { 0xC6, 0x44, 0x24, 0x50, 0x00, 0x49, 0x8B, 0x41, 0x10, 0x48, 0x8B, 0x88, 0xF8, 0x01, 0x00, 0x00,0x33, 0xD2 };//3520ƫ��ֵ��������
BYTE jBlockOutTheEnvironmentCallFeatureCode[] = { 0x8B, 0x08, 0x89, 0x8B, 0x88, 0x02, 0x00, 0x00, 0x8B, 0x48, 0x04, 0x89, 0x8B, 0x8C, 0x02, 0x00,0x00, 0x8B, 0x40, 0x08, 0x89, 0x83,0x90, 0x02, 0x00, 0x00, 0x48, 0x8B, 0x47, 0x60, 0x48, 0x85,0xC0 }; //���λ�����������
BYTE jUnityOfHeavenAndHumanityCallFeatureCode[] = { 0xB8, 0x96, 0x00, 0x00, 0x00, 0x41, 0xB8, 0x0C, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3, 0x44, 0x89, 0x73, 0x02, 0x66,0x89, 0x6B, 0x06, 0x66, 0x89, 0x73, 0x08, 0x66, 0x89, 0x7B,0x0A }; //���˺�һ��������

BaseAddress::BaseAddress()
{
	this->operator=(0);
	

}



bool BaseAddress::init()
{

	FMC::init(::getpid(), L"elementclient64.exe");

	this->jδ֪����ָ�� = this->�����붨λ��ַ(jδ֪����������, sizeof(jδ֪����������), 0x42, 3, 4, 7);
	if (!this->jδ֪����ָ��)
	{
		return false;
	}
	this->j���˶��� = *((QWORD*)((*((QWORD*)((*((QWORD*)this->jδ֪����ָ��)) + 0x38))) + 0x60));
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

	this->jRemoteItemDestructionCall = this->�����붨λcall(jRemoteItemDestructionCallFeatureCode, sizeof(jRemoteItemDestructionCallFeatureCode), 0x42);
	if (!this->jRemoteItemDestructionCall)
	{
		return false;
	}

	this->jδ֪���� = *((QWORD*)this->jδ֪����ָ��);
	if (!this->jδ֪����)
	{
		return false;
	}

	this->jPacketizationCall = this->�����붨λcall(jPacketizationFeatureCode, sizeof(jPacketizationFeatureCode), 0x114);
	if (!this->jPacketizationCall)
	{
		return false;
	}

	this->jBagOfHoldingCall = this->�����붨λcall(jBagOfHoldingCallFeatureCode, sizeof(jBagOfHoldingCallFeatureCode), 0x38);
	if (!this->jBagOfHoldingCall)
	{
		return false;
	}

	this->jWarehouseOffsetValue = this->�����붨λƫ��(jWarehouseOffsetValueFeatureCode, sizeof(jWarehouseOffsetValueFeatureCode), 0x110, 0x3, 0x4);
	if (!this->jWarehouseOffsetValue)
	{
		return false;
	}

	this->jWarehouseCall = this->�����붨λcall(jWarehouseCallFeatureCode, sizeof(jWarehouseCallFeatureCode), -0xC7);
	if (!this->jWarehouseCall)
	{
		return false;
	}
	
	this->jOpenWarehouseCall = this->�����붨λcall(jOpenWarehouseCallFeatureCode, sizeof(jOpenWarehouseCallFeatureCode), 0x5A);
	if (!this->jOpenWarehouseCall)
	{
		return false;
	}

	this->jCloseWarehouseCall = this->�����붨λcall(jCloseWarehouseCallFeatureCode, sizeof(jCloseWarehouseCallFeatureCode), 0x60);
	if (!this->jCloseWarehouseCall)
	{
		return false;
	}

	this->jUnknownGlobalVariable = this->�����붨λ��ַ(jUnknownGlobalVariableFeatureCode, sizeof(jUnknownGlobalVariableFeatureCode), 0x142, 3, 3, 4);
	if (!this->jUnknownGlobalVariable)
	{
		return false;
	}

	this->jOpen�ֿ��ϰ�������ĶԻ�����Call = this->�����붨λcall(jOpen�ֿ��ϰ�������ĶԻ�����CallFeatureCode, sizeof(jOpen�ֿ��ϰ�������ĶԻ�����CallFeatureCode), 0x27F);
	if (!this->jOpen�ֿ��ϰ�������ĶԻ�����Call)
	{
		return false;
	}

	this->j3520OffsetValue = this->�����붨λƫ��(j3520OffsetValueFeatureCode, sizeof(j3520OffsetValueFeatureCode), 0x1CC, 3, 4);
	if (!this->j3520OffsetValue)
	{
		return false;
	}

	this->jBlockOutTheEnvironmentCall = this->�����붨λcall(jBlockOutTheEnvironmentCallFeatureCode, sizeof(jBlockOutTheEnvironmentCallFeatureCode), 0x226);
	if (!this->jBlockOutTheEnvironmentCall)
	{
		return false;
	}

	this->jUnityOfHeavenAndHumanityCall = this->�����붨λcall(jUnityOfHeavenAndHumanityCallFeatureCode, sizeof(jUnityOfHeavenAndHumanityCallFeatureCode), 0x56);
	if (!this->jUnityOfHeavenAndHumanityCall)
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

QWORD BaseAddress::getRemoteItemDestructionCall()
{
	return this->jRemoteItemDestructionCall;
}

QWORD BaseAddress::��ȡδ֪����()
{
	return this->jδ֪����;
}

QWORD BaseAddress::getWarehouseOffsetValue()
{
	return this->jWarehouseOffsetValue;
}

QWORD BaseAddress::getBagOfHoldingCall()
{
	return this->jBagOfHoldingCall;
}

QWORD BaseAddress::getPacketizationCall()
{
	return this->jPacketizationCall;
}

QWORD BaseAddress::getWarehouseCall()
{
	return this->jWarehouseCall;
}

QWORD BaseAddress::getOpenWarehouseCall()
{
	return this->jOpenWarehouseCall;
}

QWORD BaseAddress::getCloseWarehouseCall()
{
	return this->jCloseWarehouseCall;
}

QWORD BaseAddress::getUnknownGlobalVariable()
{
	return this->jUnknownGlobalVariable;
}

QWORD BaseAddress::getOpen�ֿ��ϰ�������ĶԻ�����Call()
{
	return this->jOpen�ֿ��ϰ�������ĶԻ�����Call;
}

QWORD BaseAddress::get3520OffsetValue()
{
	return this->j3520OffsetValue;
}

QWORD BaseAddress::getBlockOutTheEnvironmentCall()
{
	return this->jBlockOutTheEnvironmentCall;
}

QWORD BaseAddress::getUnityOfHeavenAndHumanityCall()
{
	return this->jUnityOfHeavenAndHumanityCall;
}

BaseAddress& BaseAddress::operator=(IN UINT value)
{
	this->j���˶��� = value;
	this->j����call = value;
	this->jȡ������call = value;
	this->jʹ����Ʒcall = value;
	this->j���������ƫ�� = value;
	this->j����װ��call = value;
	this->jRemoteItemDestructionCall = value;
	this->jδ֪���� = value;
	this->jδ֪����ָ�� = value;
	this->jPacketizationCall = value;
	this->jBagOfHoldingCall = value;
	this->jWarehouseOffsetValue = value;
	this->jWarehouseCall = value;
	this->jOpenWarehouseCall = value;
	this->jCloseWarehouseCall = value;
	this->jUnknownGlobalVariable = value;
	this->jOpen�ֿ��ϰ�������ĶԻ�����Call = value;
	this->j3520OffsetValue = value;
	this->jBlockOutTheEnvironmentCall = value;
	this->jUnityOfHeavenAndHumanityCall = value;
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
	cstr.AppendFormat(L"Զ��������ƷCall: %llX\r\n", this->jRemoteItemDestructionCall);
	cstr.AppendFormat(L"δ֪����: %llX\r\n", this->jδ֪����);
	cstr.AppendFormat(L"δ֪����ָ��: %llX\r\n", this->jδ֪����ָ��);
	cstr.AppendFormat(L"���Call: %llx\r\n", this->jPacketizationCall);
	cstr.AppendFormat(L"�ֿ�����ƫ��: %llx\r\n", this->jWarehouseOffsetValue);
	cstr.AppendFormat(L"�ֿ�Call: %llx\r\n", this->jWarehouseCall);
	cstr.AppendFormat(L"�򿪲ֿ�Call: %llx\r\n", this->jOpenWarehouseCall);
	cstr.AppendFormat(L"�رղֿ�Call: %llx\r\n", this->jCloseWarehouseCall);
	cstr.AppendFormat(L"δ֪��ȫ�ֱ���: %llx\r\n", this->jUnknownGlobalVariable);
	cstr.AppendFormat(L"�򿪲ֿ��ϰ�������ĶԻ�����Call: %llx\r\n", this->jOpen�ֿ��ϰ�������ĶԻ�����Call);
	cstr.AppendFormat(L"���λ���Call: %llx\r\n", this->jBlockOutTheEnvironmentCall);
	cstr.AppendFormat(L"���˺�һCall: %llx\r\n", this->jUnityOfHeavenAndHumanityCall);
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

