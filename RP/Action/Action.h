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

};

#endif //__ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
