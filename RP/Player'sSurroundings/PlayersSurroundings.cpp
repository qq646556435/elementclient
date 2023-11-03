#include "PlayersSurroundings.h"
#include "../../Tools/BaseAddress/BaseAddress.h"
#include "../../Tools/DataStruct/DataStruct.h"
extern BaseAddress bAObject;
PlayersSurroundings::PlayersSurroundings()
{
}

PlayersSurroundings::~PlayersSurroundings()
{
}

std::vector<CString> PlayersSurroundings::iterateThroughQuestNpcsAndMonster()
{
	//[[[[[[0x14156D1A0]+38]+10] +50]+00000098]+r8*8]+000003A8
	CString questNpc;//����npc
	CString monsterNpc; //����npc
	CString otherNpc; //����npc
	CString extraNpcDetails; //�����Npc��Ϣ
	std::vector<CString> cNpc;
	//δ֪����
	QWORD unknownObject = *((PQWORD)(*((PQWORD)(*((PQWORD)(bAObject.��ȡδ֪����() + 0x38)) + 0x10)) + 0x50)); //δ֪����
	QWORD arrayFirstaddress = *((PQWORD)(unknownObject + 0x98)); //����npc�͹���npc�������׵�ַ
	size_t number = *((PDWORD)(unknownObject + 0x28)); //����npc�͹���npc������
	size_t practiceNumber = 0; //ʵ������
	//��ʼ����
	for (int i = 0; i < number; ++i)
	{
		//��i������npc�͹���npc
		QWORD currentNpcObject = *((PQWORD)(arrayFirstaddress + (i * 8)));
		if (currentNpcObject)//�����ǰnpc����Ϊ��
		{
			
			//ʵ�ʵ�����Npc�͹���Npc������
			++practiceNumber;
			/*
			npc+368    npc������
			npc+168    npc��id (dword)
			npc+48     npc��x����
			npc+4c     npc��z����
			npc+50     npc��y����
			npc+3a8   npc��ˮƽ���� float
			npc+3a4    npc�ĸ߶Ⱦ��� float
			*/
			//��ʼ���ڴ��������
			DataStruct::data_Npc npc = { 0 };//npc������Ϣ
			npc.Name = (PTCHAR)(*((PQWORD)(currentNpcObject + 0x368)));//npc������
			npc.id = *((PDWORD)(currentNpcObject + 0x168));//npc��id
			npc.hp = *((PDWORD)(currentNpcObject + 0x180)); //npc��hp
			npc.maxHp = *((PDWORD)(currentNpcObject + 0x1b0)); //npc�����Ѫ��
			npc.coordinates.x = *((float*)(currentNpcObject + 0x48));//npc��x����
			npc.coordinates.z = *((float*)(currentNpcObject + 0x4c));//npc��z����
			npc.coordinates.y = *((float*)(currentNpcObject + 0x50));//npc��y����
			npc.horizontalDistance = *((float*)(currentNpcObject + 0x3a8));//npc��ˮƽ����
			npc.verticalDistance = *((float*)(currentNpcObject + 0x3a4));//npc�ĸ߶Ⱦ���
			DWORD nType = *((PDWORD)(currentNpcObject + 0xe0)); //Npc���� 0x06�������� 0x07����npc����
			if (nType == 0x06) //����ǹ���Npc
			{
				npc.nType = L"����Npc";
				//��ʼ��ӡ����npc��������Ϣ
				monsterNpc.AppendFormat(L"����-%lld������\r\n", practiceNumber);
				monsterNpc.AppendFormat(L"npc����: %llx\r\n", currentNpcObject);
				monsterNpc.AppendFormat(L"����: %ws\r\n", npc.Name);
				monsterNpc.AppendFormat(L"id:  %lx\r\n", npc.id);
				monsterNpc.AppendFormat(L"hp:  %ld\r\n", npc.hp);
				monsterNpc.AppendFormat(L"maxHp:  %ld\r\n", npc.maxHp);
				monsterNpc.AppendFormat(L"����: %ws\r\n", npc.nType);
				monsterNpc.AppendFormat(L"x:   %3.f\r\n", npc.coordinates.x);
				monsterNpc.AppendFormat(L"z:   %3.f\r\n", npc.coordinates.z);
				monsterNpc.AppendFormat(L"y:   %3.f\r\n", npc.coordinates.y);
				monsterNpc.AppendFormat(L"ˮƽ����: %3.f\r\n", npc.horizontalDistance);
				monsterNpc.AppendFormat(L"�߶Ⱦ���: %3.f\r\n", npc.verticalDistance);
				monsterNpc.AppendFormat(L"\r\n");
				//��������ѭ��
				continue;
				
			}
			else if (nType == 0x07) //���������Npc
			{
				npc.nType = L"����Npc";
				//��ʼ��ӡ����npc��������Ϣ
				questNpc.AppendFormat(L"����-%lld������\r\n", practiceNumber);
				questNpc.AppendFormat(L"npc����: %llx\r\n", currentNpcObject);
				questNpc.AppendFormat(L"����: %ws\r\n", npc.Name);
				questNpc.AppendFormat(L"id:  %lx\r\n", npc.id);
				questNpc.AppendFormat(L"hp:  %ld\r\n", npc.hp);
				questNpc.AppendFormat(L"maxHp:  %ld\r\n", npc.maxHp);
				questNpc.AppendFormat(L"����: %ws\r\n", npc.nType);
				questNpc.AppendFormat(L"x:   %3.f\r\n", npc.coordinates.x);
				questNpc.AppendFormat(L"z:   %3.f\r\n", npc.coordinates.z);
				questNpc.AppendFormat(L"y:   %3.f\r\n", npc.coordinates.y);
				questNpc.AppendFormat(L"ˮƽ����: %3.f\r\n", npc.horizontalDistance);
				questNpc.AppendFormat(L"�߶Ⱦ���: %3.f\r\n", npc.verticalDistance);
				questNpc.AppendFormat(L"\r\n");
				//��������ѭ��
				continue;
			}
			else
			{
				npc.nType = L"����Npc";
				//��ʼ��ӡ����Npc��������Ϣ
				otherNpc.AppendFormat(L"����-%lld������\r\n", practiceNumber);
				otherNpc.AppendFormat(L"npc����: %llx\r\n", currentNpcObject);
				otherNpc.AppendFormat(L"����: %ws\r\n", npc.Name);
				otherNpc.AppendFormat(L"id:  %lx\r\n", npc.id);
				otherNpc.AppendFormat(L"hp:  %ld\r\n", npc.hp);
				otherNpc.AppendFormat(L"maxHp:  %ld\r\n", npc.maxHp);
				otherNpc.AppendFormat(L"����: %ws\r\n", npc.nType);
				otherNpc.AppendFormat(L"x:   %3.f\r\n", npc.coordinates.x);
				otherNpc.AppendFormat(L"z:   %3.f\r\n", npc.coordinates.z);
				otherNpc.AppendFormat(L"y:   %3.f\r\n", npc.coordinates.y);
				otherNpc.AppendFormat(L"ˮƽ����: %3.f\r\n", npc.horizontalDistance);
				otherNpc.AppendFormat(L"�߶Ⱦ���: %3.f\r\n", npc.verticalDistance);
				otherNpc.AppendFormat(L"\r\n");
				//��������ѭ��
				continue;
			}
			
			
			
			
		}
	}
	//npc�Ķ�����Ϣ
	extraNpcDetails.AppendFormat(L"\r\n");
	extraNpcDetails.AppendFormat(L"\r\n");
	extraNpcDetails.AppendFormat(L"��Χ������Npc�͹���Npc������: %lld\r\n",practiceNumber);
	
	/*cNpc[0] = monsterNpc;
	cNpc[1] = questNpc;
	cNpc[2] = otherNpc;
	cNpc[3] = extraNpcDetails;*/
	cNpc.push_back(monsterNpc);
	cNpc.push_back(questNpc);
	cNpc.push_back(otherNpc);
	cNpc.push_back(extraNpcDetails);
	return cNpc;
}
