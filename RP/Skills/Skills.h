#ifndef __SKILLS__H_E6B3361D_7CD4_B3A0_D74B_78B7FCA1A706
#define __SKILLS__H_E6B3361D_7CD4_B3A0_D74B_78B7FCA1A706
#pragma once
#include "../../Tools/DataStruct/DataStruct.h"
//������
class Skills
{


public:
	Skills();
	virtual ~Skills();
	//��ȡָ����������
	DataStruct::data_Skills virtual getSkillsData(IN DWORD SkillsId);
};

#endif // !__SKILLS__H_E6B3361D_7CD4_B3A0_D74B_78B7FCA1A706
