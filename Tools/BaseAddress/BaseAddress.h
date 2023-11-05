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
	inline QWORD ��ȡ���˶���()
	{
		return this->j���˶���;
	}
    inline QWORD ��ȡ����call()
	{
		return this->j����call;
	}
    inline QWORD ȡ������call()
	{
		return this->jȡ������call;
	}
    inline QWORD ����װ��call()
	{
		return this->j����װ��call;
	}
    inline QWORD ʹ����Ʒcall()
	{
		return this->jʹ����Ʒcall;
	}
    inline QWORD ���������ƫ��()
	{
		return this->j���������ƫ��;
	}
    inline QWORD getRemoteItemDestructionCall()
	{
		return this->jRemoteItemDestructionCall;
	}
    inline QWORD ��ȡδ֪����()
	{
		return this->jδ֪����;
	}
    inline QWORD getWarehouseOffsetValue()
	{
		return this->jWarehouseOffsetValue;
	}
	//��ȡǬ����Call
	inline QWORD getBagOfHoldingCall()
	{
		return this->jBagOfHoldingCall;
	}
	//��ȡ���Call
	inline QWORD getPacketizationCall()
	{
		return this->jPacketizationCall;
	}
    //��ȡ�ֿ�Call
	inline QWORD getWarehouseCall()
	{
		return this->jWarehouseCall;
	}
    //��ȡ�򿪲ֿ�Call
	inline QWORD getOpenWarehouseCall()
	{
		return this->jOpenWarehouseCall;
	}
	//��ȡ�رղֿ�Call
	inline QWORD getCloseWarehouseCall()
	{
		return this->jCloseWarehouseCall;
	}
    //��ȡδ֪ȫ�ֱ���
	inline QWORD getUnknownGlobalVariable()
	{
		return this->jUnknownGlobalVariable;
	}
    //��ȡ�򿪲ֿ��ϰ�������ĶԻ�����Call
	inline QWORD getOpen�ֿ��ϰ�������ĶԻ�����Call()
	{
		return this->jOpen�ֿ��ϰ�������ĶԻ�����Call;
	}
    //��ȡ3520ƫ��ֵ
	inline QWORD get3520OffsetValue()
	{
		return this->j3520OffsetValue;
	}
    //��ȡ���λ���Call
	inline QWORD getBlockOutTheEnvironmentCall()
	{
		return this->jBlockOutTheEnvironmentCall;
	}
    //��ȡ���˺�һCall
	inline QWORD getUnityOfHeavenAndHumanityCall()
	{
		return this->jUnityOfHeavenAndHumanityCall;
	}
    //��ȡ�������س��йص�ȫ�ֱ���
	inline QWORD get�������س��йص�ȫ�ֱ���()
	{
		return this->j�������س��йص�ȫ�ֱ���;
	}
    //��ȡ�����س�Call
	inline QWORD getResPawnCall()
	{
		return this->jResPawnCall;
	}
    //��ȡ����·Call
	inline QWORD getChangeServerCall()
	{
		return this->jChangeServerCall;
	}
    //��ȡ���������ƫ����
	inline QWORD getSkillsArrayOffsetValue()
	{
		return this->jSkillsArrayOffsetValue;
	}
    //��ȡ����������ƫ��ֵ
	inline QWORD getSkillsNumberOffsetValue()
	{
		return this->jSkillsNumberOffsetValue;
	}
    //��ȡѡ�н�ɫ����id��ƫ��ֵ
	inline QWORD getSelectCharacterObjectOfIdOffsetValue()
	{
		return this->jSelectCharacterObjectOfIdOffsetValue;
	}
	//��ȡ�ͷż���Call
	inline QWORD getCastSkillCall()
	{
		return this->jCastSkillCall;
	}
    //��ȡ�����ж�Call
	inline QWORD getActionDisruptionCall()
	{
		return this->jActionDisruptionCall;
	}
    //��ȡѰ·Call
	inline QWORD getPathfindingCall()
	{
		return this->jPathfindingCall;
	}
	//��ȡѰ·Call����1_rcxδ֪�Ľṹ�����͵�ȫ�ֱ���
	inline QWORD getPathfindingCall_Rcx()
	{
		return this->jPathfindingCall_Rcx;
	}
    //��ȡ��·Call_1
	inline QWORD getNavigate_1()
	{
		return this->jNavigateCall_1;
	}
    //��ȡ��·Call_2
	inline QWORD getNavigate_2()
	{
		return this->jNavigateCall_2;
	}
    //��ȡ��·Call_3
	inline QWORD getNavigate_3()
	{
		return this->jNavigateCall_3;
	}
    //��ȡѡ��NpcCall
	inline QWORD getSelectNpcCall()
	{
		return this->jSelectNpcCall;
	}
    //��ȡ��ַ����
	CString getBaseAddressData();
	BaseAddress& operator=(IN UINT value);
	
	
};





#endif

