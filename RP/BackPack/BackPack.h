#ifndef __BACKPACK__H_899980B2_79E8_4D5B_9A52_F8B6FADD064E
#define __BACKPACK__H_899980B2_79E8_4D5B_9A52_F8B6FADD064E
#pragma once
#include "../../pch.h"
#include "../../Tools/DataStruct/DataStruct.h"


//������
class BackPack
{
private:
	//DWORD maxCap;//�����������
	//std::vector<Item> itemOject;//��Ʒ��������
	QWORD backPackOBject; //��������
protected:
	//���ڴ�������ݵ� item�ṹ�� ��
	void memoryReadInDataTOItemStruct(IN QWORD currentItemOject, IN wchar_t* currentItemName, IN DataStruct::data_Item & item);
	
public:
	BackPack();
	virtual ~BackPack() = default;
	//��ʼ������
	void virtual init();
	//��ȡ����ָ����Ʒ������,������Ʒ���ƻ�ȡ
	DataStruct::data_Item virtual getItemData(IN wchar_t* itemName);
};


#endif // !__BACKPACK__H_899980B2_79E8_4D5B_9A52_F8B6FADD064E