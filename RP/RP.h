#ifndef __RP__H_31BD5917_6F7F_4411_A83D_9BF1F215DC98
#define __RP__H_31BD5917_6F7F_4411_A83D_9BF1F215DC98

#include "../pch.h"
#include "../RP/OC/OC.h"
#include "../RP/BackPack/BackPack.h"
#include "../RP/Action/Action.h"
#include "../RP/Warehouse/Warehouse.h"
#include "../RP/Skills/Skills.h"
//本人玩家
class RP:public OC , public BackPack, public Action,public Warehouse,public Skills
{
public:
	RP();
	virtual ~RP() = default;
	void virtual init();
	//自我施法
	DWORD virtual selfCasting(IN QWORD skillId);
};

#endif