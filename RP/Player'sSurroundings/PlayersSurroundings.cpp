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
	CString questNpc;//任务npc
	CString monsterNpc; //怪物npc
	CString otherNpc; //其他npc
	CString extraNpcDetails; //额外的Npc信息
	std::vector<CString> cNpc;
	//未知对象
	QWORD unknownObject = *((PQWORD)(*((PQWORD)(*((PQWORD)(bAObject.获取未知对象() + 0x38)) + 0x10)) + 0x50)); //未知对象
	QWORD arrayFirstaddress = *((PQWORD)(unknownObject + 0x98)); //任务npc和怪物npc的数组首地址
	size_t number = *((PDWORD)(unknownObject + 0x28)); //任务npc和怪物npc的数量
	size_t practiceNumber = 0; //实际数量
	//开始遍历
	for (int i = 0; i < number; ++i)
	{
		//第i个任务npc和怪物npc
		QWORD currentNpcObject = *((PQWORD)(arrayFirstaddress + (i * 8)));
		if (currentNpcObject)//如果当前npc对象不为空
		{
			
			//实际的任务Npc和怪物Npc的数量
			++practiceNumber;
			/*
			npc+368    npc的名称
			npc+168    npc的id (dword)
			npc+48     npc的x坐标
			npc+4c     npc的z坐标
			npc+50     npc的y坐标
			npc+3a8   npc的水平距离 float
			npc+3a4    npc的高度距离 float
			*/
			//开始从内存读入数据
			DataStruct::data_Npc npc = { 0 };//npc属性信息
			npc.Name = (PTCHAR)(*((PQWORD)(currentNpcObject + 0x368)));//npc的名称
			npc.id = *((PDWORD)(currentNpcObject + 0x168));//npc的id
			npc.hp = *((PDWORD)(currentNpcObject + 0x180)); //npc的hp
			npc.maxHp = *((PDWORD)(currentNpcObject + 0x1b0)); //npc的最大血量
			npc.coordinates.x = *((float*)(currentNpcObject + 0x48));//npc的x坐标
			npc.coordinates.z = *((float*)(currentNpcObject + 0x4c));//npc的z坐标
			npc.coordinates.y = *((float*)(currentNpcObject + 0x50));//npc的y坐标
			npc.horizontalDistance = *((float*)(currentNpcObject + 0x3a8));//npc的水平距离
			npc.verticalDistance = *((float*)(currentNpcObject + 0x3a4));//npc的高度距离
			DWORD nType = *((PDWORD)(currentNpcObject + 0xe0)); //Npc类型 0x06怪物类型 0x07任务npc类型
			if (nType == 0x06) //如果是怪物Npc
			{
				npc.nType = L"怪物Npc";
				//开始打印怪物npc的属性信息
				monsterNpc.AppendFormat(L"——-%lld———\r\n", practiceNumber);
				monsterNpc.AppendFormat(L"npc对象: %llx\r\n", currentNpcObject);
				monsterNpc.AppendFormat(L"名称: %ws\r\n", npc.Name);
				monsterNpc.AppendFormat(L"id:  %lx\r\n", npc.id);
				monsterNpc.AppendFormat(L"hp:  %ld\r\n", npc.hp);
				monsterNpc.AppendFormat(L"maxHp:  %ld\r\n", npc.maxHp);
				monsterNpc.AppendFormat(L"类型: %ws\r\n", npc.nType);
				monsterNpc.AppendFormat(L"x:   %3.f\r\n", npc.coordinates.x);
				monsterNpc.AppendFormat(L"z:   %3.f\r\n", npc.coordinates.z);
				monsterNpc.AppendFormat(L"y:   %3.f\r\n", npc.coordinates.y);
				monsterNpc.AppendFormat(L"水平距离: %3.f\r\n", npc.horizontalDistance);
				monsterNpc.AppendFormat(L"高度距离: %3.f\r\n", npc.verticalDistance);
				monsterNpc.AppendFormat(L"\r\n");
				//跳过本次循环
				continue;
				
			}
			else if (nType == 0x07) //如果是任务Npc
			{
				npc.nType = L"任务Npc";
				//开始打印任务npc的属性信息
				questNpc.AppendFormat(L"——-%lld———\r\n", practiceNumber);
				questNpc.AppendFormat(L"npc对象: %llx\r\n", currentNpcObject);
				questNpc.AppendFormat(L"名称: %ws\r\n", npc.Name);
				questNpc.AppendFormat(L"id:  %lx\r\n", npc.id);
				questNpc.AppendFormat(L"hp:  %ld\r\n", npc.hp);
				questNpc.AppendFormat(L"maxHp:  %ld\r\n", npc.maxHp);
				questNpc.AppendFormat(L"类型: %ws\r\n", npc.nType);
				questNpc.AppendFormat(L"x:   %3.f\r\n", npc.coordinates.x);
				questNpc.AppendFormat(L"z:   %3.f\r\n", npc.coordinates.z);
				questNpc.AppendFormat(L"y:   %3.f\r\n", npc.coordinates.y);
				questNpc.AppendFormat(L"水平距离: %3.f\r\n", npc.horizontalDistance);
				questNpc.AppendFormat(L"高度距离: %3.f\r\n", npc.verticalDistance);
				questNpc.AppendFormat(L"\r\n");
				//跳过本次循环
				continue;
			}
			else
			{
				npc.nType = L"其他Npc";
				//开始打印其他Npc的属性信息
				otherNpc.AppendFormat(L"——-%lld———\r\n", practiceNumber);
				otherNpc.AppendFormat(L"npc对象: %llx\r\n", currentNpcObject);
				otherNpc.AppendFormat(L"名称: %ws\r\n", npc.Name);
				otherNpc.AppendFormat(L"id:  %lx\r\n", npc.id);
				otherNpc.AppendFormat(L"hp:  %ld\r\n", npc.hp);
				otherNpc.AppendFormat(L"maxHp:  %ld\r\n", npc.maxHp);
				otherNpc.AppendFormat(L"类型: %ws\r\n", npc.nType);
				otherNpc.AppendFormat(L"x:   %3.f\r\n", npc.coordinates.x);
				otherNpc.AppendFormat(L"z:   %3.f\r\n", npc.coordinates.z);
				otherNpc.AppendFormat(L"y:   %3.f\r\n", npc.coordinates.y);
				otherNpc.AppendFormat(L"水平距离: %3.f\r\n", npc.horizontalDistance);
				otherNpc.AppendFormat(L"高度距离: %3.f\r\n", npc.verticalDistance);
				otherNpc.AppendFormat(L"\r\n");
				//跳过本次循环
				continue;
			}
			
			
			
			
		}
	}
	//npc的额外信息
	extraNpcDetails.AppendFormat(L"\r\n");
	extraNpcDetails.AppendFormat(L"\r\n");
	extraNpcDetails.AppendFormat(L"周围的任务Npc和怪物Npc的数量: %lld\r\n",practiceNumber);
	
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
