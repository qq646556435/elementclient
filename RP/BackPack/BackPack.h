#ifndef __BACKPACK__H_899980B2_79E8_4D5B_9A52_F8B6FADD064E
#define __BACKPACK__H_899980B2_79E8_4D5B_9A52_F8B6FADD064E
#pragma once
#include "../../pch.h"
#include "../../Tools/DataStruct/DataStruct.h"
#define NO_EMPTY_INVENTORY_SLOT -1; //����û�д洢λ��

//������
class BackPack
{
protected:
	//DWORD maxCap;//�����������
	//std::vector<Item> itemOject;//��Ʒ��������
	QWORD backPackOBject; //��������
	 
protected:
	//���ڴ�������ݵ� item�ṹ�� ��
	void memoryReadInDataTOItemStruct(IN QWORD currentItemOject, IN wchar_t* currentItemName, IN DataStruct::data_Item & item,IN UINT index);
	
public:
	BackPack();
	virtual ~BackPack() = default;
	//��ʼ������
	void virtual init();
	//��ȡ����ָ����Ʒ������,������Ʒ���ƻ�ȡ
	DataStruct::data_Item virtual getItemData(IN wchar_t* itemName);
	//����������Ʒ����
	CString virtual TraversalBackPackItemData();
	//��ȡ�����հ��±�
	DWORD virtual retrieveEmptyBackpackIndex();
};


#endif // !__BACKPACK__H_899980B2_79E8_4D5B_9A52_F8B6FADD064E