#include "BackPack.h"
#include "../../Tools/BaseAddress/BaseAddress.h"
#include "../../Tools/MemoryCheck/MemoryCheck.h"
extern BaseAddress bAObject;



void BackPack::memoryReadInDataTOItemStruct(IN QWORD currentItemOject, IN wchar_t* currentItemName, IN DataStruct::data_Item& item)
{
	//��ǰ��Ʒ�������Ƶĵ�ַ
	QWORD currentItemTypeNameAddress = *((QWORD*)(currentItemOject + 0x80));

	//��Ʒ��������
	wchar_t currentItemTypeName[40] = { 0 };
	if (IsMemoryReadableWritable((QWORD*)currentItemTypeNameAddress))//�����ǰ��ַ����Ч��
	{
		wcscpy(currentItemTypeName, (LPCWSTR)(currentItemTypeNameAddress + 0x4));

		if (wcscmp(currentItemName, currentItemTypeName) == 0)
		{
			wcscpy(item.Name, currentItemName);
			wcscpy(item.typeName, L"δ֪��Ʒ����");
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
		wcscpy(item.typeName, L"δ֪��Ʒ����");
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
	this->backPackOBject = *((QWORD*)(bAObject.��ȡ���˶���() + bAObject.���������ƫ��()));
}



DataStruct::data_Item BackPack::getItemData(IN wchar_t* itemName)
{


	//�����������
	DWORD maxCap = *((QWORD*)(this->backPackOBject + 0x20));

	//��Ʒ���������׵�ַ
	QWORD itmeObjectArrayFA = *((QWORD*)(this->backPackOBject + 0x18));
	//��Ʒ����
	DataStruct::data_Item item = { 0 };


	//��ʼ������������
	for (int i = 0; i < maxCap; ++i)
	{

		//��ǰ��Ʒ����
		QWORD currentItemOject = *((QWORD*)(itmeObjectArrayFA + (i * 8)));
		//�����ǰ��Ʒ����Ϊ��
		if (!currentItemOject)
		{
			//��������ѭ�� ������һ��ѭ��
			continue;
		}
		else//��ʼ������Ʒ
		{


			//��ǰ��Ʒ���Ƶĵ�ַ
			QWORD currentItemNameAddress = *((QWORD*)(currentItemOject + 0x80));
			if (currentItemNameAddress)//�����ǰ��Ʒ���Ƶĵ�ַ���ǿյ�
			{
				if (IsMemoryReadableWritable((QWORD*)currentItemNameAddress))
				{


					//��ǰ��Ʒ��һ������
					wchar_t currentItemOneName[40] = { 0 };
					wcscpy(currentItemOneName, (wchar_t*)(currentItemNameAddress + 0x4));
					if (wcscmp(currentItemOneName, itemName) == 0) //����ҵ�
					{
						this->memoryReadInDataTOItemStruct(currentItemOject, currentItemOneName, item);
						return item;
					}

				}

			}
			//��ǰ��Ʒ���Ƶ�ַ
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x88));
			if (currentItemNameAddress)//�����ǰ��Ʒ���Ƶĵ�ַ���ǿյ�
			{
				if (IsMemoryReadableWritable((QWORD*)currentItemNameAddress))
				{


					//��ǰ��Ʒ�ڶ�������
					wchar_t currentItemTwoName[40] = { 0 };
					wcscpy(currentItemTwoName, (wchar_t*)(currentItemNameAddress + 0x4));
					if (wcscmp(currentItemTwoName, itemName) == 0) //����ҵ�
					{
						this->memoryReadInDataTOItemStruct(currentItemOject, currentItemTwoName, item);
						return item;
					}
				}



			}
			//��ǰ��Ʒ���Ƶ�ַ
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x90));
			if (currentItemNameAddress)//�����ǰ��Ʒ���Ƶĵ�ַ���ǿյ�
			{
				if (IsMemoryReadableWritable((QWORD*)currentItemNameAddress))
				{

					//��ǰ��Ʒ����������
					wchar_t currentItemthreeName[40] = { 0 };
					wcscpy(currentItemthreeName, (wchar_t*)(currentItemNameAddress + 0xc));
					if (wcscmp(currentItemthreeName, itemName) == 0) //����ҵ�
					{
						this->memoryReadInDataTOItemStruct(currentItemOject, currentItemthreeName, item);
						return item;

					}

				}

			}
			//��ǰ��Ʒ���Ƶ�ַ
			currentItemNameAddress = *((QWORD*)(currentItemOject + 0x2b0));
			if (currentItemNameAddress)//�����ǰ��Ʒ���Ƶĵ�ַ���ǿյ�
			{
				if (IsMemoryReadableWritable((QWORD*)currentItemNameAddress))
				{

					//��ǰ��Ʒ���ĸ�����
					wchar_t currentItemFourName[40] = { 0 };
					wcscpy(currentItemFourName, (wchar_t*)(currentItemNameAddress + 0x4));
					if (wcscmp(currentItemFourName, itemName) == 0) //����ҵ�
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


