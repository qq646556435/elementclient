#ifndef __OC__H_E5AB1099_D223_4C2A_94AE_34622F422177
#define __OC__H_E5AB1099_D223_4C2A_94AE_34622F422177
#pragma once

#include "../../pch.h"
#include "../../Tools/DataStruct/DataStruct.h"


class OC
{
private:
	
 DataStruct::data_OCInfo 角色信息 = { 0 };

public:

	OC();
	virtual ~OC();
	bool init();
	DataStruct::data_OCInfo virtual 获取角色信息();

};

#endif // !__OC__H_E5AB1099_D223_4C2A_94AE_34622F422177

