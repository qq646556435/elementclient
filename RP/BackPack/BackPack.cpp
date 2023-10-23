#include "BackPack.h"
#include "../../Tools/BaseAddress/BaseAddress.h"
#include "../../Tools/MemoryCheck/MemoryCheck.h"
#include "../../MyDialog.h"
extern BaseAddress bAObject;
extern MyDialog  myDialog;


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
	//我要查询的物品名称
	wchar_t inItemName[40] = { 0 };
	wcscpy(inItemName, itemName);

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
					if (wcscmp(currentItemOneName, inItemName) == 0) //如果找到
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
					if (wcscmp(currentItemTwoName, inItemName) == 0) //如果找到
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
					if (wcscmp(currentItemthreeName, inItemName) == 0) //如果找到
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
					if (wcscmp(currentItemFourName, inItemName) == 0) //如果找到
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

void BackPack::TraversalBackPackItemData()
{
	//背包最大容量
	DWORD maxCap = *((QWORD*)(this->backPackOBject + 0x20));
	//物品对象数组首地址
	QWORD itmeObjectArrayFA = *((QWORD*)(this->backPackOBject + 0x18));
	//物品数据
	DataStruct::data_Item item = { 0 };
	//背包物品的数据
	CString cstr;
	//当前物品名称的地址
	QWORD currentItemNameAddress = 0;

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
			item = { 0 };
			//名称一
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x80));
			if (currentItemNameAddress)//如果当前物品名称的地址不是空的
			{
				if (IsMemoryReadableWritable((QWORD*)(currentItemNameAddress + 0x4)))//如果当前物品名称的地址是有效的
				{
					wcscpy(item.Name, (wchar_t*)(currentItemNameAddress + 0x4));
				}
				else
				{
					wcscpy(item.Name, L"未知");
				}
			}
			else
			{
				wcscpy(item.Name, L"未知");
			}
			//名称二
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x88));
			if (currentItemNameAddress)//如果当前物品名称的地址不是空的
			{
				if (IsMemoryReadableWritable((QWORD*)(currentItemNameAddress + 0x4)))//如果当前物品名称的地址是有效的
				{
					wcscpy(item.Name1, (wchar_t*)(currentItemNameAddress + 0x4));
				}
				else
				{
					wcscpy(item.Name1, L"未知");
				}
			}
			else
			{
				wcscpy(item.Name1, L"未知");
			}
			//名称三
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x90));
			if (currentItemNameAddress)//如果当前物品名称的地址不是空的
			{
				if (IsMemoryReadableWritable((QWORD*)(currentItemNameAddress + 0xc)))//如果当前物品名称的地址是有效的
				{
					wcscpy(item.Name2, (wchar_t*)(currentItemNameAddress + 0xc));
				}
				else
				{
					wcscpy(item.Name2, L"未知");
				}
			}
			else
			{
				wcscpy(item.Name2, L"未知");
			}
			//名称四
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x2b0));
			if (currentItemNameAddress)//如果当前物品名称的地址不是空的
			{
				if (IsMemoryReadableWritable((QWORD*)(currentItemNameAddress + 0x4)))//如果当前物品名称的地址是有效的
				{
					wcscpy(item.Name3, (wchar_t*)(currentItemNameAddress + 0x4));
				}
				else
				{
					wcscpy(item.Name3, L"未知");
				}
			}
			else
			{
				wcscpy(item.Name3, L"未知");
			}
			//id
			item.id = *((DWORD*)(currentItemOject + 0xc));
			//当前容量
			item.cic = *((DWORD*)(currentItemOject + 0x18));
			//最大容量
			item.cmic = *((DWORD*)(currentItemOject + 0x1c));

            cstr.AppendFormat(L"名称: %ws\r\n名称1: %ws\r\n名称2: %ws\r\n名称3: %ws\r\nid: %x\r\n类型: %ws\r\n容量: %ld\r\n最大容量: %ld\r\n\r\n",
				item.Name, item.Name1, item.Name2, item.Name3,
				item.id, item.typeName, item.cic, item.cmic);
		}
	}
	myDialog.idc_Edit_Logging.SetWindowTextW(cstr.GetString());
}

				/*
				item.id = *((DWORD*)(currentItemOject + 0xc));
				item.cic = *((DWORD*)(currentItemOject + 0x18));
				item.cmic = *((DWORD*)(currentItemOject + 0x1c));
				*/
	
			
		

					

						





















