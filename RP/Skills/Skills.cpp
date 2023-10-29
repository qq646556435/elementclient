#include "Skills.h"
#include "../../Tools/BaseAddress/BaseAddress.h"
extern BaseAddress bAObject;
Skills::Skills()
{
}

Skills::~Skills()
{
}

DataStruct::data_Skills Skills::getSkillsData(IN DWORD SkillsId)
{
	DataStruct::data_Skills skills = { 0 };
	//技能数量
	BYTE skillnumber = *((PBYTE)(bAObject.获取本人对象() + bAObject.getSkillsNumberOffsetValue()));
	for (size_t i = 0; i < skillnumber; ++i)
	{
		//第i个技能对象
		QWORD currentSkillObject = *((PQWORD)((*((PQWORD)(bAObject.获取本人对象() + bAObject.getSkillsArrayOffsetValue()))) + (i * 8)));
		//第i个技能对象的id
		DWORD currentSkillObjectId = *((PDWORD)(currentSkillObject + 0x10));
		if (currentSkillObjectId== SkillsId)//如果找到
		{
			//开始初始化数据
			skills.id = currentSkillObjectId;
			skills.cooldownTimer = *((PDWORD)(currentSkillObject + 0x14));
			skills.maximumCooldown = *((PDWORD)(currentSkillObject + 0x18));
			skills.cooldownFlag = *((PBYTE)(currentSkillObject + 0x1c));
			return skills;
		}
		
	}

	return skills;
}

