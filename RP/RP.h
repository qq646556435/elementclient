#ifndef __RP__H_31BD5917_6F7F_4411_A83D_9BF1F215DC98
#define __RP__H_31BD5917_6F7F_4411_A83D_9BF1F215DC98

#include "../pch.h"
#include "../RP/OC/OC.h"
#include "../RP/BackPack/BackPack.h"
#include "../RP/Action/Action.h"
#include "../RP/Warehouse/Warehouse.h"
#include "../RP/Skills/Skills.h"
//�������
class RP:public OC , public BackPack, public Action,public Warehouse,public Skills
{
public:
	RP();
	virtual ~RP() = default;
	void virtual init();
	//����ʩ��
	QWORD virtual selfCasting(IN QWORD skillId);
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
};

#endif