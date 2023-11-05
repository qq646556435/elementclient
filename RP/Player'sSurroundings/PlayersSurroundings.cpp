#include "PlayersSurroundings.h"
#include "../../Tools/BaseAddress/BaseAddress.h"
#include "../../Tools/DataStruct/DataStruct.h"

#define FORMAT_NPC_INFO(cNpc,npc, currentNpcObject,practiceNumber) \
    cNpc.AppendFormat(L"����-%lld������\r\n", practiceNumber); \
    cNpc.AppendFormat(L"npc����: %llx\r\n", currentNpcObject); \
    cNpc.AppendFormat(L"����: %ws\r\n", npc.Name); \
    cNpc.AppendFormat(L"id:  %lx\r\n", npc.id); \
    cNpc.AppendFormat(L"hp:  %ld\r\n", npc.hp); \
    cNpc.AppendFormat(L"maxHp:  %ld\r\n", npc.maxHp); \
    cNpc.AppendFormat(L"����: %ws\r\n", npc.nType); \
    cNpc.AppendFormat(L"x:   %.3f\r\n", npc.coordinates.x); \
    cNpc.AppendFormat(L"z:   %.3f\r\n", npc.coordinates.z); \
    cNpc.AppendFormat(L"y:   %.3f\r\n", npc.coordinates.y); \
    cNpc.AppendFormat(L"ˮƽ����: %.3f\r\n", npc.horizontalDistance); \
    cNpc.AppendFormat(L"�߶Ⱦ���: %.3f\r\n", npc.verticalDistance); \
    cNpc.AppendFormat(L"\r\n");


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
				FORMAT_NPC_INFO(monsterNpc, npc, currentNpcObject, practiceNumber);
				//��������ѭ��
				continue;
				
			}
			else if (nType == 0x07) //���������Npc
			{
				npc.nType = L"����Npc";
				//��ʼ��ӡ����npc��������Ϣ
				FORMAT_NPC_INFO(questNpc, npc, currentNpcObject, practiceNumber);
				//��������ѭ��
				continue;
			}
			else  //���������Npc
			{
				npc.nType = L"����Npc";
				//��ʼ��ӡ����Npc��������Ϣ
				FORMAT_NPC_INFO(otherNpc, npc, currentNpcObject, practiceNumber);
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
