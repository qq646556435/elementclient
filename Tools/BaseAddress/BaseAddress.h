#ifndef __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#define __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#pragma once
#pragma warning(disable : 4996)
#include "../../pch.h"
#include "../FMC/FMC.h"

class BaseAddress:public FMC
{
private:

	QWORD j本人对象;
	QWORD j打坐call;
	QWORD j取消打坐call;
	QWORD j整理装备call;
	QWORD j使用物品call;
	QWORD j背包对象的偏移;
	QWORD j未知对象;
	QWORD j未知对象指针;
	QWORD jRemoteItemDestructionCall;//远程销毁物品Call
	QWORD jPacketizationCall;//组包Call
	QWORD jBagOfHoldingCall;//乾坤袋Call
	QWORD jWarehouseOffsetValue;//仓库对象的偏移值
	QWORD jWarehouseCall;//仓库Call
	QWORD jOpenWarehouseCall;//打开仓库Call
	QWORD jCloseWarehouseCall;//关闭仓库Call
	QWORD jUnknownGlobalVariable;//未知的全局变量
	QWORD jOpen仓库老板金玲音的对话界面Call;//打开仓库老板金玲音的对话界面Call
	QWORD j3520OffsetValue;//3520偏移值
	QWORD jBlockOutTheEnvironmentCall;//屏蔽环境Call
	QWORD jUnityOfHeavenAndHumanityCall;//天人合一Call
	QWORD j和死亡回城有关的全局变量;//和死亡回城有关的全局变量
	QWORD jResPawnCall;//死亡回城Call
	QWORD jChangeServerCall;//换线路Call
	QWORD jSkillsArrayOffsetValue;//技能数组偏移值
	QWORD jSkillsNumberOffsetValue;//技能总数偏移值
	QWORD jSelectCharacterObjectOfIdOffsetValue;//选中角色对象的Id偏移值
	QWORD jCastSkillCall;//释放技能Call
	
public:
	BaseAddress();
	virtual ~BaseAddress();
	bool virtual init();
	QWORD  获取本人对象();
	QWORD  获取打坐call();
	QWORD  取消打坐call();
	QWORD  整理装备call();
	QWORD  使用物品call();
	QWORD  背包对象的偏移();
	QWORD  getRemoteItemDestructionCall();
	QWORD  获取未知对象();
	QWORD  getWarehouseOffsetValue();
	//获取乾坤袋Call
	QWORD  getBagOfHoldingCall();
	//获取组包Call
	QWORD  getPacketizationCall();
	//获取仓库Call
	QWORD getWarehouseCall();
	//获取打开仓库Call
	QWORD getOpenWarehouseCall();
	//获取关闭仓库Call
	QWORD getCloseWarehouseCall();
	//获取未知全局变量
	QWORD getUnknownGlobalVariable();
	//获取打开仓库老板金玲音的对话界面Call
	QWORD getOpen仓库老板金玲音的对话界面Call();
	//获取3520偏移值
	QWORD get3520OffsetValue();
	//获取屏蔽环境Call
	QWORD getBlockOutTheEnvironmentCall();
    //获取天人合一Call
	QWORD getUnityOfHeavenAndHumanityCall();
	//获取和死亡回城有关的全局变量
	QWORD get和死亡回城有关的全局变量();
	//获取死亡回城Call
	QWORD getResPawnCall();
	//获取换线路Call
	QWORD getChangeServerCall();
	//获取技能数组的偏移量
	QWORD getSkillsArrayOffsetValue();
	//获取技能总数的偏移值
	QWORD getSkillsNumberOffsetValue();
	//获取选中角色对象id的偏移值
	QWORD getSelectCharacterObjectOfIdOffsetValue();
	//获取释放技能Call
	QWORD getCastSkillCall();
	BaseAddress& operator=(IN UINT value);
	CString getBaseAddressData();
};



#endif

