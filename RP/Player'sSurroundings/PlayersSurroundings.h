#ifndef __PLAYERS__SURROUNDINGS__H__04E8161E__C190__3A26__2B51__FB530F73E655  
#define __PLAYERS__SURROUNDINGS__H__04E8161E__C190__3A26__2B51__FB530F73E655
#pragma once
#include "../../pch.h"
#include <vector>
class PlayersSurroundings
{
public:
	PlayersSurroundings();
	virtual ~PlayersSurroundings();
	//遍历任务Npc和怪物Npc
	 std::vector<CString> virtual iterateThroughQuestNpcsAndMonster();
};

#endif //__PLAYERS__SURROUNDINGS__H__04E8161E__C190__3A26__2B51__FB530F73E655

