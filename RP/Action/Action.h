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
};

#endif //__ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
