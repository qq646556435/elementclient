#ifndef __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#define __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#pragma once
class Action
{
public:
	Action();
	virtual ~Action();
	//ʹ��ָ����Ʒ
	QWORD virtual useItem(IN QWORD ���˶���, IN QWORD rdx, IN QWORD �±�, IN QWORD r9);
	//����
	QWORD virtual meditation();
	//ȡ������
	QWORD virtual cancelMeditation();
	//������
	QWORD virtual organizeBackpack(IN QWORD rcx);
	//Զ��������Ʒ
	void virtual remoteItemDestruction(IN QWORD itemIndex, IN QWORD itemId);
	//���������Ʒ
	void virtual packetization_RemoteItemDestruction(IN DWORD itemIndex, IN DWORD itemId);
	//Ǭ����
	void virtual bagOfHolding(IN DWORD itemIndex);
	//���Ǭ����
	void virtual packetization_BagOfHolding(IN DWORD itemIndex);
	//������Ʒ���ֿ� 
	void virtual backPackToWarehouse(IN QWORD unknownObject, IN QWORD rdx , IN QWORD targetWarehouseIndex, IN QWORD soureBackPackIndex);
	//���������Ʒ���ֿ�
	void virtual packetization_BackPackToWarehouse(IN DWORD targetWarehouseIndex, IN DWORD soureBackPackIndex);
	//�ֿ���Ʒ������
	void virtual warehouseToBackPack(IN QWORD unknownObject, IN QWORD rdx , IN QWORD soureWarehouseIndex, IN QWORD targetBackPackIndex);
	//����ֿ���Ʒ������
	void virtual packetization_WarehouseToBackPack(IN DWORD soureWarehouseIndex, IN DWORD targetBackPackIndex);
	//�򿪲ֿ�Call
	void virtual openWarehouseCall(IN QWORD unknownGlobalVariable,IN QWORD rdx);
	//����򿪲ֿ�Call
	void virtual packetization_OpenWarehouseCall();
	//�رղֿ�Call
	QWORD virtual closeWarehouseCall(IN QWORD unknownObject);
	//����رղֿ�Call
	void virtual packetization_CloseWarehouseCall();
	//�򿪲ֿ��ϰ�������Ի������Call
	QWORD virtual open�ֿ��ϰ�������Ի�����Call(IN QWORD unknownObjectOne, IN QWORD unknownObjectTwo);
    //�رղֿ��ϰ�������Ի������Call
	void virtual Close�ֿ��ϰ�������Ի�����Call();
};

#endif //__ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
