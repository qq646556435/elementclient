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
	 BaseAddress& operator=(IN UINT value);
	CString getBaseAddressData();
};



#endif

