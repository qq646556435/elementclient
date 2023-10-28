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
	QWORD jδ֪����;
	QWORD jδ֪����ָ��;
	QWORD jRemoteItemDestructionCall;//Զ��������ƷCall
	QWORD jPacketizationCall;//���Call
	QWORD jBagOfHoldingCall;//Ǭ����Call
	QWORD jWarehouseOffsetValue;//�ֿ�����ƫ��ֵ
	QWORD jWarehouseCall;//�ֿ�Call
	QWORD jOpenWarehouseCall;//�򿪲ֿ�Call
	QWORD jCloseWarehouseCall;//�رղֿ�Call
	QWORD jUnknownGlobalVariable;//δ֪��ȫ�ֱ���
	QWORD jOpen�ֿ��ϰ�������ĶԻ�����Call;//�򿪲ֿ��ϰ�������ĶԻ�����Call
	QWORD j3520OffsetValue;//3520ƫ��ֵ
	QWORD jBlockOutTheEnvironmentCall;//���λ���Call
	QWORD jUnityOfHeavenAndHumanityCall;//���˺�һCall
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
	QWORD  getRemoteItemDestructionCall();
	QWORD  ��ȡδ֪����();
	QWORD  getWarehouseOffsetValue();
	//��ȡǬ����Call
	QWORD  getBagOfHoldingCall();
	//��ȡ���Call
	QWORD  getPacketizationCall();
	//��ȡ�ֿ�Call
	QWORD getWarehouseCall();
	//��ȡ�򿪲ֿ�Call
	QWORD getOpenWarehouseCall();
	//��ȡ�رղֿ�Call
	QWORD getCloseWarehouseCall();
	//��ȡδ֪ȫ�ֱ���
	QWORD getUnknownGlobalVariable();
	//��ȡ�򿪲ֿ��ϰ�������ĶԻ�����Call
	QWORD getOpen�ֿ��ϰ�������ĶԻ�����Call();
	//��ȡ3520ƫ��ֵ
	QWORD get3520OffsetValue();
	//��ȡ���λ���Call
	QWORD getBlockOutTheEnvironmentCall();
    //��ȡ���˺�һCall
	QWORD getUnityOfHeavenAndHumanityCall();
	BaseAddress& operator=(IN UINT value);
	CString getBaseAddressData();
};



#endif

