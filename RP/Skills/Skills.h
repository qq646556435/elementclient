#ifndef __SKILLS__H_E6B3361D_7CD4_B3A0_D74B_78B7FCA1A706
#define __SKILLS__H_E6B3361D_7CD4_B3A0_D74B_78B7FCA1A706
#pragma once
#include "../../Tools/DataStruct/DataStruct.h"
//技能类
class Skills
{


public:
	Skills();
	virtual ~Skills();
	//获取指定技能数据
	DataStruct::data_Skills virtual getSkillsData(IN DWORD SkillsId);
};

#endif // !__SKILLS__H_E6B3361D_7CD4_B3A0_D74B_78B7FCA1A706
