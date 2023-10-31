#ifndef __BACKPACK__H_899980B2_79E8_4D5B_9A52_F8B6FADD064E
#define __BACKPACK__H_899980B2_79E8_4D5B_9A52_F8B6FADD064E
#pragma once
#include "../../pch.h"
#include "../../Tools/DataStruct/DataStruct.h"
#define NO_EMPTY_INVENTORY_SLOT -1; //背包没有存储位置

//背包类
class BackPack
{
protected:
	//DWORD maxCap;//背包最大容量
	//std::vector<Item> itemOject;//物品对象数组
	QWORD backPackOBject; //背包对象
	 
protected:
	//从内存读入数据到 item结构体 中
	void memoryReadInDataTOItemStruct(IN QWORD currentItemOject, IN wchar_t* currentItemName, IN DataStruct::data_Item & item,IN UINT index);
	
public:
	BackPack();
	virtual ~BackPack() = default;
	//初始化数据
	void virtual init();
	//获取背包指定物品的数据,根据物品名称获取
	DataStruct::data_Item virtual getItemData(IN wchar_t* itemName);
	//遍历背包物品数据
	CString virtual TraversalBackPackItemData();
	//获取背包空白下标
	DWORD virtual retrieveEmptyBackpackIndex();
};


#endif // !__BACKPACK__H_899980B2_79E8_4D5B_9A52_F8B6FADD064E