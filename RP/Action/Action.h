#ifndef __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#define __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#pragma once
#include "../../Tools/DataStruct/DataStruct.h"
using  Function_useItemCall = QWORD(FASTCALL*)(QWORD, QWORD, QWORD, QWORD);
using  Function_meditationCall = QWORD(FASTCALL*)();
using  Function_cancelMeditationCall = QWORD(FASTCALL*)();
using  Function_organizeBackpackCall = QWORD(FASTCALL*)(QWORD);
using  Function_remoteItemDestructionCall = void (FASTCALL*)(QWORD, QWORD);
using  Function_packetizationCall = void (FASTCALL*)(QWORD, QWORD, QWORD);
using  function_BagOfHoldingCall = void(FASTCALL*)(QWORD);
using  function_WarehouseCall = void(FASTCALL*)(QWORD, QWORD, QWORD, QWORD);
using  function_OpenWarehouseCall = void(FASTCALL*)(QWORD, QWORD);
using  Function_CloseWarehouseCall = QWORD(FASTCALL*)(QWORD);
using  Function_Open�ֿ��ϰ�������Ի�����Call = QWORD(FASTCALL*)(QWORD, QWORD);
using  Function_BlockOutTheEnvironmentCall = QWORD(FASTCALL*)(QWORD);
using  Function_UnityOfHeavenAndHumanityCall = QWORD(FASTCALL*)(QWORD, QWORD, QWORD);
using  Function_RespawnCall = QWORD(FASTCALL*)(QWORD, PTCHAR);
using  Function_ChangeServerCall = QWORD(FASTCALL*)(QWORD, QWORD);
using  Function_SpellcastingCall = QWORD(FASTCALL*)(QWORD, QWORD, QWORD, QWORD, QWORD);
using  Function_ActionDisruptionCall = QWORD(FASTCALL*)(QWORD);
using  Function_PathfindingCall = QWORD(FASTCALL*)(QWORD, PQWORD, PQWORD, QWORD, byte);
using  Function_NacigateCall_1 = QWORD(FASTCALL*)(QWORD, DWORD);
using  Function_NacigateCall_2 = void (FASTCALL*)(QWORD, DWORD, PQWORD);
using  Function_NacigateCall_3 = QWORD(FASTCALL*)(QWORD, DWORD, QWORD, DWORD, BYTE);
using  Function_SelectNpcCall = QWORD(FASTCALL*)(DWORD);

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
	  ����ֵ: ture����false
	*/
	QWORD virtual navigate(IN DataStruct::data_Coordinates* targetCoordinates);
	/*
	  ѡ��NpcCall
	  ����1:(in) Npc�����id
	  ����ֵ: ture����false
	*/
	QWORD virtual selectNpcCall(IN DWORD npcObjectId);
};

#endif //__ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
