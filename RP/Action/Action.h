#ifndef __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#define __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#pragma once
#include "../../Tools/DataStruct/DataStruct.h"
class Action
{
public:
	Action();
	virtual ~Action();
	//ʹ��ָ����Ʒ
	QWORD virtual useItem(IN QWORD �±�);
	//����
	QWORD virtual meditation();
	//ȡ������
	QWORD virtual cancelMeditation();
	//������
	QWORD virtual organizeBackpack();
	//Զ��������Ʒ
	void virtual remoteItemDestruction(IN PTCHAR itemName);
	//���������Ʒ
	void virtual packetization_RemoteItemDestruction(IN PTCHAR itemName);
	//Ǭ����
	void virtual bagOfHolding(IN PTCHAR itemName);
	//���Ǭ����
	void virtual packetization_BagOfHolding(IN PTCHAR itemName);
	//������Ʒ���ֿ� 
	void virtual backPackToWarehouse(IN PTCHAR itemName);
	//���������Ʒ���ֿ�
	void virtual packetization_BackPackToWarehouse(IN PTCHAR itemName);
	//�ֿ���Ʒ������
	void virtual warehouseToBackPack(IN PTCHAR itemName);
	//����ֿ���Ʒ������
	void virtual packetization_WarehouseToBackPack(IN PTCHAR itemName);
	//�򿪲ֿ�Call
	void virtual openWarehouseCall();
	//����򿪲ֿ�Call
	void virtual packetization_OpenWarehouseCall();
	//�رղֿ�Call
	QWORD virtual closeWarehouseCall();
	//����رղֿ�Call
	void virtual packetization_CloseWarehouseCall();
	//�򿪲ֿ��ϰ�������Ի������Call
	QWORD virtual open�ֿ��ϰ�������Ի�����Call();
    //�رղֿ��ϰ�������Ի������Call
	void virtual Close�ֿ��ϰ�������Ի�����Call();
	//���λ���Call
	QWORD virtual blockOutTheEnvironmentCall();
	//�������˺�һ
	QWORD virtual openUnityOfHeavenAndHumanity();
	//�ر����˺�һ
	QWORD virtual closeUnityOfHeavenAndHumanity();
	//����������˺�һ
	void virtual packetization_OpenUnityOfHeavenAndHumanity();
	//����ر����˺�һ
	void virtual packetization_CloseUnityOfHeavenAndHumanity();
	//�����س�
	QWORD virtual resPawn();
	//����·
	QWORD virtual changeServer(IN UINT server);
	//��ȡѡ�еĽ�ɫ����id
	DWORD virtual getSelectCharacterObjectOfId();
	//����ʩ��
	QWORD virtual selfCasting(IN QWORD skillId);
	//ʩ��: pInGameCharacterObject(ָ����Ϸ�ڽ�ɫ����id��ָ��)
	QWORD virtual casting(IN QWORD skillId, IN PQWORD pInGameCharacterObject);
	//�����ж�
	QWORD virtual actionDisruption();
	//��������ж�
	void virtual  packetization_ActionDisruption();
	/*
	  Ѱ·Call:
	  ����1:(in) Ŀ������
      ����ֵ: ture����false	
	*/
	QWORD virtual pathfinding(IN DataStruct::data_Coordinates* targetCoordinates);
	/*
	  ��·Call:
	  ����1:(in) Ŀ������
	  ����ֵ: false Navigate
	*/
	QWORD virtual navigate(IN DataStruct::data_Coordinates* targetCoordinates);
	
};

#endif //__ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
