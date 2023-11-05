#ifndef __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#define __BASEADDRESS__H_17272302_864F_4110_8584_DB23C6BE5CEE
#pragma once
#pragma warning(disable : 4996)
#include "../../pch.h"
#include "../FMC/FMC.h"

class BaseAddress :public FMC
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
	QWORD jActionDisruptionCall;//动作中断Call
	QWORD jPathfindingCall;//寻路Call 
	QWORD jPathfindingCall_Rcx;//寻路Call参数1_rcx未知的结构体类型的全局变量
	QWORD jNavigateCall_1;//走路Call
	QWORD jNavigateCall_2;
	QWORD jNavigateCall_3;
	QWORD jSelectNpcCall;//选中NpcCall

public:
	BaseAddress();
	virtual ~BaseAddress();
	bool virtual init();
	inline QWORD 获取本人对象()
	{
		return this->j本人对象;
	}
    inline QWORD 获取打坐call()
	{
		return this->j打坐call;
	}
    inline QWORD 取消打坐call()
	{
		return this->j取消打坐call;
	}
    inline QWORD 整理装备call()
	{
		return this->j整理装备call;
	}
    inline QWORD 使用物品call()
	{
		return this->j使用物品call;
	}
    inline QWORD 背包对象的偏移()
	{
		return this->j背包对象的偏移;
	}
    inline QWORD getRemoteItemDestructionCall()
	{
		return this->jRemoteItemDestructionCall;
	}
    inline QWORD 获取未知对象()
	{
		return this->j未知对象;
	}
    inline QWORD getWarehouseOffsetValue()
	{
		return this->jWarehouseOffsetValue;
	}
	//获取乾坤袋Call
	inline QWORD getBagOfHoldingCall()
	{
		return this->jBagOfHoldingCall;
	}
	//获取组包Call
	inline QWORD getPacketizationCall()
	{
		return this->jPacketizationCall;
	}
    //获取仓库Call
	inline QWORD getWarehouseCall()
	{
		return this->jWarehouseCall;
	}
    //获取打开仓库Call
	inline QWORD getOpenWarehouseCall()
	{
		return this->jOpenWarehouseCall;
	}
	//获取关闭仓库Call
	inline QWORD getCloseWarehouseCall()
	{
		return this->jCloseWarehouseCall;
	}
    //获取未知全局变量
	inline QWORD getUnknownGlobalVariable()
	{
		return this->jUnknownGlobalVariable;
	}
    //获取打开仓库老板金玲音的对话界面Call
	inline QWORD getOpen仓库老板金玲音的对话界面Call()
	{
		return this->jOpen仓库老板金玲音的对话界面Call;
	}
    //获取3520偏移值
	inline QWORD get3520OffsetValue()
	{
		return this->j3520OffsetValue;
	}
    //获取屏蔽环境Call
	inline QWORD getBlockOutTheEnvironmentCall()
	{
		return this->jBlockOutTheEnvironmentCall;
	}
    //获取天人合一Call
	inline QWORD getUnityOfHeavenAndHumanityCall()
	{
		return this->jUnityOfHeavenAndHumanityCall;
	}
    //获取和死亡回城有关的全局变量
	inline QWORD get和死亡回城有关的全局变量()
	{
		return this->j和死亡回城有关的全局变量;
	}
    //获取死亡回城Call
	inline QWORD getResPawnCall()
	{
		return this->jResPawnCall;
	}
    //获取换线路Call
	inline QWORD getChangeServerCall()
	{
		return this->jChangeServerCall;
	}
    //获取技能数组的偏移量
	inline QWORD getSkillsArrayOffsetValue()
	{
		return this->jSkillsArrayOffsetValue;
	}
    //获取技能总数的偏移值
	inline QWORD getSkillsNumberOffsetValue()
	{
		return this->jSkillsNumberOffsetValue;
	}
    //获取选中角色对象id的偏移值
	inline QWORD getSelectCharacterObjectOfIdOffsetValue()
	{
		return this->jSelectCharacterObjectOfIdOffsetValue;
	}
	//获取释放技能Call
	inline QWORD getCastSkillCall()
	{
		return this->jCastSkillCall;
	}
    //获取动作中断Call
	inline QWORD getActionDisruptionCall()
	{
		return this->jActionDisruptionCall;
	}
    //获取寻路Call
	inline QWORD getPathfindingCall()
	{
		return this->jPathfindingCall;
	}
	//获取寻路Call参数1_rcx未知的结构体类型的全局变量
	inline QWORD getPathfindingCall_Rcx()
	{
		return this->jPathfindingCall_Rcx;
	}
    //获取走路Call_1
	inline QWORD getNavigate_1()
	{
		return this->jNavigateCall_1;
	}
    //获取走路Call_2
	inline QWORD getNavigate_2()
	{
		return this->jNavigateCall_2;
	}
    //获取走路Call_3
	inline QWORD getNavigate_3()
	{
		return this->jNavigateCall_3;
	}
    //获取选中NpcCall
	inline QWORD getSelectNpcCall()
	{
		return this->jSelectNpcCall;
	}
    //获取基址数据
	CString getBaseAddressData();
	BaseAddress& operator=(IN UINT value);
	
	
};





#endif

