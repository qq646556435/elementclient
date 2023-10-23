#include "BackPack.h"
#include "../../Tools/BaseAddress/BaseAddress.h"
#include "../../Tools/MemoryCheck/MemoryCheck.h"
extern BaseAddress bAObject;



void BackPack::memoryReadInDataTOItemStruct(IN QWORD currentItemOject, IN wchar_t* currentItemName, IN DataStruct::data_Item& item)
{
	//当前物品类型名称的地址
	QWORD currentItemTypeNameAddress = *((QWORD*)(currentItemOject + 0x80));

	//物品类型名称
	wchar_t currentItemTypeName[40] = { 0 };
	if (IsMemoryReadableWritable((QWORD*)currentItemTypeNameAddress))//如果当前地址是有效的
	{
		wcscpy(currentItemTypeName, (LPCWSTR)(currentItemTypeNameAddress + 0x4));

		if (wcscmp(currentItemName, currentItemTypeName) == 0)
		{
			wcscpy(item.Name, currentItemName);
			wcscpy(item.typeName, L"未知物品类型");
		}
		else
		{
			wcscpy(item.Name, currentItemName);
			wcscpy(item.typeName, currentItemTypeName);
		}

	}
	else
	{
		wcscpy(item.Name, currentItemName);
		wcscpy(item.typeName, L"未知物品类型");
	}

	item.id = *((DWORD*)(currentItemOject + 0xc));
	item.cic = *((DWORD*)(currentItemOject + 0x18));
	item.cmic = *((DWORD*)(currentItemOject + 0x1c));

}

BackPack::BackPack() :backPackOBject(0)
{
}

void BackPack::init()
{
	this->backPackOBject = *((QWORD*)(bAObject.获取本人对象() + bAObject.背包对象的偏移()));
}



DataStruct::data_Item BackPack::getItemData(IN wchar_t* itemName)
{


	//背包最大容量
	DWORD maxCap = *((QWORD*)(this->backPackOBject + 0x20));

	//物品对象数组首地址
	QWORD itmeObjectArrayFA = *((QWORD*)(this->backPackOBject + 0x18));
	//物品数据
	DataStruct::data_Item item = { 0 };


	//开始遍历对象数组
	for (int i = 0; i < maxCap; ++i)
	{

		//当前物品对象
		QWORD currentItemOject = *((QWORD*)(itmeObjectArrayFA + (i * 8)));
		//如果当前物品对象为空
		if (!currentItemOject)
		{
			//跳出本次循环 进入下一次循环
			continue;
		}
		else//开始查找物品
		{


			//当前物品名称的地址
			QWORD currentItemNameAddress = *((QWORD*)(currentItemOject + 0x80));
			if (currentItemNameAddress)//如果当前物品名称的地址不是空的
			{
				if (IsMemoryReadableWritable((QWORD*)currentItemNameAddress))
				{


					//当前物品第一个名称
					wchar_t currentItemOneName[40] = { 0 };
					wcscpy(currentItemOneName, (wchar_t*)(currentItemNameAddress + 0x4));
					if (wcscmp(currentItemOneName, itemName) == 0) //如果找到
					{
						this->memoryReadInDataTOItemStruct(currentItemOject, currentItemOneName, item);
						return item;
					}

				}

			}
			//当前物品名称地址
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x88));
			if (currentItemNameAddress)//如果当前物品名称的地址不是空的
			{
				if (IsMemoryReadableWritable((QWORD*)currentItemNameAddress))
				{


					//当前物品第二个名称
					wchar_t currentItemTwoName[40] = { 0 };
					wcscpy(currentItemTwoName, (wchar_t*)(currentItemNameAddress + 0x4));
					if (wcscmp(currentItemTwoName, itemName) == 0) //如果找到
					{
						this->memoryReadInDataTOItemStruct(currentItemOject, currentItemTwoName, item);
						return item;
					}
				}



			}
			//当前物品名称地址
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x90));
			if (currentItemNameAddress)//如果当前物品名称的地址不是空的
			{
				if (IsMemoryReadableWritable((QWORD*)currentItemNameAddress))
				{

					//当前物品第三个名称
					wchar_t currentItemthreeName[40] = { 0 };
					wcscpy(currentItemthreeName, (wchar_t*)(currentItemNameAddress + 0xc));
					if (wcscmp(currentItemthreeName, itemName) == 0) //如果找到
					{
						this->memoryReadInDataTOItemStruct(currentItemOject, currentItemthreeName, item);
						return item;

					}

				}

			}
			//当前物品名称地址
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x2b0));
			if (currentItemNameAddress)//如果当前物品名称的地址不是空的
			{
				if (IsMemoryReadableWritable((QWORD*)currentItemNameAddress))
				{

					//当前物品第四个名称
					wchar_t currentItemFourName[40] = { 0 };
					wcscpy(currentItemFourName, (wchar_t*)(currentItemNameAddress + 0x4));
					if (wcscmp(currentItemFourName, itemName) == 0) //如果找到
					{
						this->memoryReadInDataTOItemStruct(currentItemOject, currentItemFourName, item);
						return item;
					}


				}
			}
		}
	}

	return item;
}


