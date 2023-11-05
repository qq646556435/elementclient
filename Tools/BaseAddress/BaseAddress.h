#ifndef __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#define __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#pragma once
#pragma warning(disable : 4996)
#include "../../pch.h"
#include "../FMC/FMC.h"

class BaseAddress :public FMC
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
	QWORD j�������س��йص�ȫ�ֱ���;//�������س��йص�ȫ�ֱ���
	QWORD jResPawnCall;//�����س�Call
	QWORD jChangeServerCall;//����·Call
	QWORD jSkillsArrayOffsetValue;//��������ƫ��ֵ
	QWORD jSkillsNumberOffsetValue;//��������ƫ��ֵ
	QWORD jSelectCharacterObjectOfIdOffsetValue;//ѡ�н�ɫ�����Idƫ��ֵ
	QWORD jCastSkillCall;//�ͷż���Call
	QWORD jActionDisruptionCall;//�����ж�Call
	QWORD jPathfindingCall;//Ѱ·Call 
	QWORD jPathfindingCall_Rcx;//Ѱ·Call����1_rcxδ֪�Ľṹ�����͵�ȫ�ֱ���
	QWORD jNavigateCall_1;//��·Call
	QWORD jNavigateCall_2;
	QWORD jNavigateCall_3;
	QWORD jSelectNpcCall;//ѡ��NpcCall

public:
	BaseAddress();
	virtual ~BaseAddress();
	bool virtual init();
	QWORD ��ȡ���˶���();
    QWORD ��ȡ����call();
	QWORD ȡ������call();
	QWORD ����װ��call();
	QWORD ʹ����Ʒcall();
	QWORD ���������ƫ��();
	QWORD getRemoteItemDestructionCall();
	QWORD ��ȡδ֪����();
	QWORD getWarehouseOffsetValue();
	//��ȡǬ����Call
	QWORD getBagOfHoldingCall();
	//��ȡ���Call
	QWORD getPacketizationCall();
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
	//��ȡ�������س��йص�ȫ�ֱ���
	QWORD get�������س��йص�ȫ�ֱ���();
	//��ȡ�����س�Call
	QWORD getResPawnCall();
	//��ȡ����·Call
	QWORD getChangeServerCall();
	//��ȡ���������ƫ����
	QWORD getSkillsArrayOffsetValue();
	//��ȡ����������ƫ��ֵ
	QWORD getSkillsNumberOffsetValue();
    //��ȡѡ�н�ɫ����id��ƫ��ֵ
	QWORD getSelectCharacterObjectOfIdOffsetValue();
	//��ȡ�ͷż���Call
	QWORD getCastSkillCall();
	//��ȡ�����ж�Call
	QWORD getActionDisruptionCall();
	//��ȡѰ·Call
	QWORD getPathfindingCall();
    //��ȡѰ·Call����1_rcxδ֪�Ľṹ�����͵�ȫ�ֱ���
	QWORD getPathfindingCall_Rcx();
	//��ȡ��·Call_1
	QWORD getNavigate_1();
	//��ȡ��·Call_2
	QWORD getNavigate_2();
	//��ȡ��·Call_3
	QWORD getNavigate_3();
	//��ȡѡ��NpcCall
	QWORD getSelectNpcCall();
	//��ȡ��ַ����
	CString getBaseAddressData();
	BaseAddress& operator=(IN UINT value);
	
	
};





#endif

inline QWORD BaseAddress::��ȡ���˶���()
{
	return this->j���˶���;
}
inline QWORD BaseAddress::��ȡ����call()
{
	return this->j����call;
}
inline QWORD BaseAddress::ȡ������call()
{
	return this->jȡ������call;
}
inline QWORD BaseAddress::����װ��call()
{
	return this->j����װ��call;
}
inline QWORD BaseAddress::ʹ����Ʒcall()
{
	return this->jʹ����Ʒcall;
}
inline QWORD BaseAddress::���������ƫ��()
{
	return this->j���������ƫ��;
}
inline QWORD BaseAddress::getRemoteItemDestructionCall()
{
	return this->jRemoteItemDestructionCall;
}
inline QWORD BaseAddress::��ȡδ֪����()
{
	return this->jδ֪����;
}
inline QWORD BaseAddress::getWarehouseOffsetValue()
{
	return this->jWarehouseOffsetValue;
}
//��ȡǬ����Call
inline QWORD BaseAddress::getBagOfHoldingCall()
{
	return this->jBagOfHoldingCall;
}
//��ȡ���Call
inline QWORD BaseAddress::getPacketizationCall()
{
	return this->jPacketizationCall;
}
//��ȡ�ֿ�Call
inline QWORD BaseAddress::getWarehouseCall()
{
	return this->jWarehouseCall;
}
//��ȡ�򿪲ֿ�Call
inline QWORD BaseAddress::getOpenWarehouseCall()
{
	return this->jOpenWarehouseCall;
}
//��ȡ�رղֿ�Call
inline QWORD BaseAddress::getCloseWarehouseCall()
{
	return this->jCloseWarehouseCall;
}
//��ȡδ֪ȫ�ֱ���
inline QWORD BaseAddress::getUnknownGlobalVariable()
{
	return this->jUnknownGlobalVariable;
}
//��ȡ�򿪲ֿ��ϰ�������ĶԻ�����Call
inline QWORD BaseAddress::getOpen�ֿ��ϰ�������ĶԻ�����Call()
{
	return this->jOpen�ֿ��ϰ�������ĶԻ�����Call;
}
//��ȡ3520ƫ��ֵ
inline QWORD BaseAddress::get3520OffsetValue()
{
	return this->j3520OffsetValue;
}
//��ȡ���λ���Call
inline QWORD BaseAddress::getBlockOutTheEnvironmentCall()
{
	return this->jBlockOutTheEnvironmentCall;
}
//��ȡ���˺�һCall
inline QWORD BaseAddress::getUnityOfHeavenAndHumanityCall()
{
	return this->jUnityOfHeavenAndHumanityCall;
}
//��ȡ�������س��йص�ȫ�ֱ���
inline QWORD BaseAddress::get�������س��йص�ȫ�ֱ���()
{
	return this->j�������س��йص�ȫ�ֱ���;
}
//��ȡ�����س�Call
inline QWORD BaseAddress::getResPawnCall()
{
	return this->jResPawnCall;
}
//��ȡ����·Call
inline QWORD BaseAddress::getChangeServerCall()
{
	return this->jChangeServerCall;
}
//��ȡ���������ƫ����
inline QWORD BaseAddress::getSkillsArrayOffsetValue()
{
	return this->jSkillsArrayOffsetValue;
}
//��ȡ����������ƫ��ֵ
inline QWORD BaseAddress::getSkillsNumberOffsetValue()
{
	return this->jSkillsNumberOffsetValue;
}
//��ȡѡ�н�ɫ����id��ƫ��ֵ
inline QWORD BaseAddress::getSelectCharacterObjectOfIdOffsetValue()
{
	return this->jSelectCharacterObjectOfIdOffsetValue;
}
//��ȡ�ͷż���Call
inline QWORD BaseAddress::getCastSkillCall()
{
	return this->jCastSkillCall;
}
//��ȡ�����ж�Call
inline QWORD BaseAddress::getActionDisruptionCall()
{
	return this->jActionDisruptionCall;
}
//��ȡѰ·Call
inline QWORD BaseAddress::getPathfindingCall()
{
	return this->jPathfindingCall;
}
//��ȡѰ·Call����1_rcxδ֪�Ľṹ�����͵�ȫ�ֱ���
inline QWORD BaseAddress::getPathfindingCall_Rcx()
{
	return this->jPathfindingCall_Rcx;
}
//��ȡ��·Call_1
inline QWORD BaseAddress::getNavigate_1()
{
	return this->jNavigateCall_1;
}
//��ȡ��·Call_2
inline QWORD BaseAddress::getNavigate_2()
{
	return this->jNavigateCall_2;
}
//��ȡ��·Call_3
inline QWORD BaseAddress::getNavigate_3()
{
	return this->jNavigateCall_3;
}
//��ȡѡ��NpcCall
inline QWORD BaseAddress::getSelectNpcCall()
{
	return this->jSelectNpcCall;
}