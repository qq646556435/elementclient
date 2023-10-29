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
	//��������
	BYTE skillnumber = *((PBYTE)(bAObject.��ȡ���˶���() + bAObject.getSkillsNumberOffsetValue()));
	for (size_t i = 0; i < skillnumber; ++i)
	{
		//��i�����ܶ���
		QWORD currentSkillObject = *((PQWORD)((*((PQWORD)(bAObject.��ȡ���˶���() + bAObject.getSkillsArrayOffsetValue()))) + (i * 8)));
		//��i�����ܶ����id
		DWORD currentSkillObjectId = *((PDWORD)(currentSkillObject + 0x10));
		if (currentSkillObjectId== SkillsId)//����ҵ�
		{
			//��ʼ��ʼ������
			skills.id = currentSkillObjectId;
			skills.cooldownTimer = *((PDWORD)(currentSkillObject + 0x14));
			skills.maximumCooldown = *((PDWORD)(currentSkillObject + 0x18));
			skills.cooldownFlag = *((PBYTE)(currentSkillObject + 0x1c));
			return skills;
		}
		
	}

	return skills;
}

