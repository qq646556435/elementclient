#include "BaseAddress.h"

BYTE j未知对象特征码[] = { 0x48, 0x89, 0x5C, 0x24, 0x18, 0x48, 0x89, 0x6C, 0x24, 0x20, 0x56, 0x57, 0x41, 0x54, 0x41, 0x55,0x41, 0x56 };
BYTE j打坐call特征码[] = { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x0F, 0xB6, 0xDA, 0x45, 0x33, 0xC0, 0x33, 0xD2 };
BYTE j取消打坐call特征码[] = { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x0F, 0xB6, 0xDA, 0x45, 0x33, 0xC0, 0x33, 0xD2 };
BYTE j使用物品call特征码[] = { 0x33, 0xC9, 0x44, 0x89, 0x49, 0x0C, 0x89, 0x49, 0x10, 0x48, 0x8B, 0x5C, 0x24, 0x08, 0xC3, 0x48,0x83, 0xC1, 0x08, 0x44, 0x89, 0x49, 0x0C, 0xC7, 0x41, 0x10, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8B,
0x5C, 0x24, 0x08, 0xC3 };
BYTE j整理装备call特征码[] = { 0x48, 0x8B, 0x5C, 0x24, 0x30, 0x48, 0x8B, 0x6C, 0x24, 0x38, 0x48, 0x8B, 0x74, 0x24, 0x40, 0x48,0x8B, 0x7C, 0x24, 0x48, 0x48, 0x83, 0xC4, 0x20, 0x41, 0x5E, 0xC3, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC,0xCC, 0xCC, 0x40, 0x57, 0x48, 0x83, 0xEC, 0x40, 0x48, 0x8B, 0xF9 };
BYTE j背包对象偏移的特征码[] = { 0x48, 0x8B, 0x07, 0x41, 0xB1, 0x01, 0x45, 0x33, 0xC0, 0x41, 0x0F, 0xB6, 0xD1, 0x48, 0x8B, 0xCF,
0x48, 0x8B, 0x6C, 0x24, 0x50, 0x48, 0x8B, 0x5C, 0x24, 0x58, 0x48, 0x8B, 0x74, 0x24, 0x60, 0x48,
0x83, 0xC4, 0x40, 0x5F };
BYTE jPacketizationFeatureCode[] = { 0x48, 0x81, 0xC4, 0x18, 0x01, 0x00, 0x00, 0x41, 0x5F, 0x41, 0x5E, 0x5F, 0x5E, 0x5B, 0x5D, 0xC3,0xCC, 0xCC, 0xCC, 0xCC, 0x48, 0x8B, 0xC4, 0x57, 0x48, 0x83, 0xEC, 0x60 };//组包特征码
BYTE jRemoteItemDestructionCallFeatureCode[] = { 0xB8, 0x63, 0x02, 0x00, 0x00, 0x41, 0xB8, 0x06, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3, 0x89, 0x7B, 0x02 };//远程销毁物品Call的特征码
BYTE jBagOfHoldingCallFeatureCode[] = { 0xB8, 0x2A, 0x01, 0x00, 0x00, 0x41, 0xB8, 0x02, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3 };//乾坤袋Call的特征码
BYTE jWarehouseOffsetValueFeatureCode[] = { 0x45, 0x33, 0xC9, 0x44, 0x8B, 0x43, 0x14, 0x48, 0x8B, 0xCE, 0x8B, 0x53, 0x18, 0x48, 0x8B, 0x5C,0x24, 0x30, 0x48, 0x8B, 0x74, 0x24, 0x38, 0x48, 0x83, 0xC4, 0x20, 0x5F };//仓库对象偏移值特征码
BYTE jWarehouseCallFeatureCode[] = { 0xB8, 0xF5, 0x00, 0x00, 0x00, 0x41, 0xB8, 0x07, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3, 0x40, 0x88, 0x73, 0x02, 0x89, 0x7B, 0x03 };
BYTE jOpenWarehouseCallFeatureCode[] = { 0x66, 0x44, 0x89, 0x5C, 0x24, 0x20, 0xC7, 0x44, 0x24, 0x22, 0x4A, 0x00, 0x00, 0x00, 0xC7, 0x44,0x24, 0x26, 0x34, 0x00, 0x00, 0x00, 0x44, 0x89, 0x54, 0x24, 0x2B, 0x66, 0x44, 0x89, 0x4C, 0x24,0x33, 0x88, 0x44, 0x24, 0x41 }; //打开仓库Call的特征码
BYTE jCloseWarehouseCallFeatureCode[] = { 0x40, 0x53, 0x48, 0x83, 0xEC, 0x30, 0x0F, 0xB6, 0xDA, 0xC7, 0x44, 0x24, 0x40, 0x5A, 0x00, 0x00,0x00, 0x48, 0x8D, 0x54, 0x24, 0x40, 0xC7, 0x44, 0x24, 0x20, 0x5A, 0x00, 0x00, 0x00, 0x48, 0x83,0xC1, 0x18, 0x48, 0xC7, 0x44, 0x24, 0x28, 0x00, 0x00, 0x00, 0x00, 0x4C, 0x8D, 0x44, 0x24, 0x20 };//关闭仓库Call的特征码
BYTE jUnknownGlobalVariableFeatureCode[] = { 0x05, 0xE8, 0x03, 0x00, 0x00, 0x89, 0x83, 0xAC, 0x03, 0x00, 0x00, 0x48, 0x8B, 0x03, 0x41, 0xB1,0x01, 0x45, 0x33, 0xC0, 0x33, 0xD2, 0x48, 0x8B, 0xCB }; //未知的全局变量的特征码
BYTE jOpen仓库老板金玲音的对话界面CallFeatureCode[] = { 0x8B, 0x87, 0xBC, 0x03, 0x00, 0x00, 0x89, 0x43, 0x38, 0x8B, 0x87, 0xC0, 0x03, 0x00, 0x00, 0x89,0x43, 0x3C, 0x8B, 0x87, 0xC4, 0x03, 0x00, 0x00, 0x89, 0x43, 0x40, 0x48, 0x8B, 0x43, 0x28, 0xC6,0x43, 0x4C, 0x01 }; //打开仓库老板金玲音的对话界面Call的特征码
BYTE j3520OffsetValueFeatureCode[] = { 0xC6, 0x44, 0x24, 0x50, 0x00, 0x49, 0x8B, 0x41, 0x10, 0x48, 0x8B, 0x88, 0xF8, 0x01, 0x00, 0x00,0x33, 0xD2 };//3520偏移值的特征码
BYTE jBlockOutTheEnvironmentCallFeatureCode[] = { 0x8B, 0x08, 0x89, 0x8B, 0x88, 0x02, 0x00, 0x00, 0x8B, 0x48, 0x04, 0x89, 0x8B, 0x8C, 0x02, 0x00,0x00, 0x8B, 0x40, 0x08, 0x89, 0x83,0x90, 0x02, 0x00, 0x00, 0x48, 0x8B, 0x47, 0x60, 0x48, 0x85,0xC0 }; //屏蔽环境的特征码
BYTE jUnityOfHeavenAndHumanityCallFeatureCode[] = { 0xB8, 0x96, 0x00, 0x00, 0x00, 0x41, 0xB8, 0x0C, 0x00, 0x00, 0x00, 0x66, 0x89, 0x03, 0x48, 0x8B,0xD3, 0x44, 0x89, 0x73, 0x02, 0x66,0x89, 0x6B, 0x06, 0x66, 0x89, 0x73, 0x08, 0x66, 0x89, 0x7B,0x0A }; //天人合一的特征码
BYTE j和死亡回城有关的全局变量FeatureCode[] = { 0x48, 0x8B, 0x01, 0x33, 0xD2, 0x48, 0x83, 0xC4, 0x28, 0x48, 0xFF, 0x60, 0x70, 0x48, 0x83, 0xC4, 0x28, 0xC3 }; //和死亡回城有关的全局变量的特征码
BYTE jChangeServerCallFeatureCode[] = { 0x48, 0x89, 0x44, 0x24, 0x28, 0xC7, 0x44, 0x24, 0x30, 0xAA, 0x0F, 0x00, 0x00, 0x89, 0x54, 0x24,0x38, 0x8B, 0x81, 0x1C, 0x02, 0x00, 0x00, 0x89, 0x44, 0x24, 0x3C, 0x45, 0x33, 0xC0, 0x48, 0x8D,0x54, 0x24, 0x28 }; //换线路Call的特征码
BYTE jSkillsArrayOffsetValueFeatureCode[] = { 0x48, 0x89, 0x5C, 0x24, 0x40, 0x48, 0x89, 0x6C, 0x24, 0x48, 0x48, 0x8D, 0x68, 0x04, 0x48, 0x89,0x74, 0x24, 0x50, 0x48, 0x89, 0x7C, 0x24, 0x58, 0x4C, 0x89, 0x74, 0x24, 0x20, 0x0F, 0x1F, 0x84,0x00, 0x00, 0x00, 0x00, 0x00 }; //技能数组偏移量的特征码
BYTE jSkillsNumberOffsetValueFeatureCode[] = { 0x48, 0x89, 0x5C, 0x24, 0x40, 0x48, 0x89, 0x6C, 0x24, 0x48, 0x48, 0x8D, 0x68, 0x04, 0x48, 0x89,0x74, 0x24, 0x50, 0x48, 0x89, 0x7C, 0x24, 0x58, 0x4C, 0x89, 0x74, 0x24, 0x20, 0x0F, 0x1F, 0x84,0x00, 0x00, 0x00, 0x00, 0x00 };//技能总数的偏移值
BYTE jSelectCharacterObjectOfIdOffsetValueFeatureCode[] = { 0xBF, 0x06, 0x00, 0x00, 0x00, 0x33, 0xF6, 0x0F, 0x1F, 0x00, 0x48, 0x8B, 0x0B, 0x48, 0x85, 0xC9 };//选中角色对象id的偏移值的特征码
BYTE jCastSkillCallFeatureCode[] = { 0x48, 0x8B, 0x5C, 0x24, 0x40, 0x48, 0x8B, 0x6C, 0x24, 0x48, 0x48, 0x8B, 0x74, 0x24, 0x50, 0x48,0x8B, 0x7C, 0x24, 0x58, 0x48, 0x83, 0xC4, 0x20, 0x41, 0x5F, 0x41, 0x5E, 0x41, 0x5C, 0xC3, 0xCC,0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x48, 0x89, 0x5C, 0x24, 0x08, 0x48, 0x89,0x6C, 0x24, 0x10, 0x48, 0x89, 0x74, 0x24, 0x18 };//释放技能Call的特征码
BYTE jActionDisruptionCallFeatureCode[] = { 0x4C, 0x8B, 0x7C, 0x24, 0x30, 0x48, 0x8B, 0x74, 0x24, 0x58, 0x48, 0x8B, 0x6C, 0x24, 0x50, 0x4C,0x8B, 0x74, 0x24, 0x60, 0x48, 0x83, 0xC4, 0x38, 0x5F, 0x5B, 0xC3, 0x0F, 0x1F, 0x00 }; //动作中断Call的特征码
BYTE jPathfindingCallFeatureCode[] = { 0x48, 0x89, 0x58, 0x10, 0x48, 0x89, 0x70, 0x18, 0x45, 0x8B, 0xE1, 0x4D, 0x8B, 0xF0, 0x4C, 0x8B,0xEA, 0x48, 0x8B, 0xF1 };//寻路Call的特征码
BYTE jPathfindingCall_RaxFeatureCode[] = { 0xF3, 0x0F, 0x10, 0x50, 0x50, 0xF3, 0x0F, 0x10, 0x48, 0x4C, 0xF3, 0x0F, 0x10, 0x40, 0x48, 0xF3,0x0F, 0x11, 0x45, 0x8F, 0xF3, 0x0F, 0x11, 0x4D, 0x93, 0xF3, 0x0F, 0x11, 0x55, 0x97, 0x44, 0x8B,0xCB, 0x4C, 0x8D, 0x44, 0x24, 0x58, 0x48, 0x8D, 0x55, 0x8F, 0xC6, 0x44, 0x24, 0x20, 0x01 }; //寻路Call参数1_rcx未知的结构体类型的全局变量的特征码
BYTE jNavigateCallFeatureCode[] = { 0xF3, 0x0F, 0x10, 0x64, 0x24, 0x60, 0xF3, 0x0F, 0x10, 0x5C, 0x24, 0x58, 0xF3, 0x0F, 0x5C, 0x67,0x50, 0xF3, 0x0F, 0x5C, 0x5F, 0x48, 0xF3, 0x0F, 0x59, 0xDB, 0xF3, 0x0F, 0x59, 0xE4, 0xF3, 0x0F,0x58, 0xDC };//走路Call的特征码
BYTE jSelectNpcCallFeatureCode[] = { 0x66, 0x89, 0x54, 0x24, 0x26, 0x48, 0x8D, 0x54, 0x24, 0x20, 0x66, 0x44, 0x89, 0x44, 0x24, 0x28,0x41, 0xB8, 0x0C, 0x00, 0x00, 0x00, 0x66, 0x89, 0x44, 0x24, 0x20, 0x66, 0x44, 0x89, 0x4C, 0x24,0x2A, 0x48, 0x8B, 0x49, 0x40 };//选中NpcCall的特征码
BaseAddress::BaseAddress()
{
	
	this->operator=(0);
	

}

bool BaseAddress::init()
{

	FMC::init(::getpid(), L"elementclient64.exe");

	this->j未知对象指针 = this->特征码定位基址(j未知对象特征码, sizeof(j未知对象特征码), 0x42, 3, 4, 7);
	if (!this->j未知对象指针)
	{
		return false;
	}
	this->j本人对象 = *((QWORD*)((*((QWORD*)((*((QWORD*)this->j未知对象指针)) + 0x38))) + 0x60));
	if (!this->j本人对象)
	{
		return false;
	}


	this->j打坐call = this->特征码定位基址(j打坐call特征码, sizeof(j打坐call特征码), 0x21, 1, 4, 5);
	if (!this->j打坐call)
	{
		return false;
	}


	this->j取消打坐call = this->特征码定位基址(j取消打坐call特征码, sizeof(j取消打坐call特征码), 0x33, 1, 4, 5);
	if (!this->j取消打坐call)
	{
		return false;
	}


	this->j使用物品call = this->特征码定位call(j使用物品call特征码, sizeof(j使用物品call特征码), 0x29);
	if (!this->j使用物品call)
	{
		return false;
	}


	this->j整理装备call = this->特征码定位基址(j整理装备call特征码, sizeof(j整理装备call特征码), -5, 1, 4, 5);
	if (!this->j整理装备call)
	{
		return false;
	}


	this->j背包对象的偏移 = this->特征码定位偏移(j背包对象偏移的特征码, sizeof(j背包对象偏移的特征码), 0x446, 3, 4);
	if (!this->j背包对象的偏移)
	{
		return false;
	}

	this->jRemoteItemDestructionCall = this->特征码定位call(jRemoteItemDestructionCallFeatureCode, sizeof(jRemoteItemDestructionCallFeatureCode), 0x42);
	if (!this->jRemoteItemDestructionCall)
	{
		return false;
	}

	this->j未知对象 = *((QWORD*)this->j未知对象指针);
	if (!this->j未知对象)
	{
		return false;
	}

	this->jPacketizationCall = this->特征码定位call(jPacketizationFeatureCode, sizeof(jPacketizationFeatureCode), 0x114);
	if (!this->jPacketizationCall)
	{
		return false;
	}

	this->jBagOfHoldingCall = this->特征码定位call(jBagOfHoldingCallFeatureCode, sizeof(jBagOfHoldingCallFeatureCode), 0x38);
	if (!this->jBagOfHoldingCall)
	{
		return false;
	}

	this->jWarehouseOffsetValue = this->特征码定位偏移(jWarehouseOffsetValueFeatureCode, sizeof(jWarehouseOffsetValueFeatureCode), 0x110, 0x3, 0x4);
	if (!this->jWarehouseOffsetValue)
	{
		return false;
	}

	this->jWarehouseCall = this->特征码定位call(jWarehouseCallFeatureCode, sizeof(jWarehouseCallFeatureCode), -0xC7);
	if (!this->jWarehouseCall)
	{
		return false;
	}

	this->jOpenWarehouseCall = this->特征码定位call(jOpenWarehouseCallFeatureCode, sizeof(jOpenWarehouseCallFeatureCode), 0x5A);
	if (!this->jOpenWarehouseCall)
	{
		return false;
	}

	this->jCloseWarehouseCall = this->特征码定位call(jCloseWarehouseCallFeatureCode, sizeof(jCloseWarehouseCallFeatureCode), 0x60);
	if (!this->jCloseWarehouseCall)
	{
		return false;
	}

	this->jUnknownGlobalVariable = this->特征码定位基址(jUnknownGlobalVariableFeatureCode, sizeof(jUnknownGlobalVariableFeatureCode), 0x142, 3, 3, 7);
	if (!this->jUnknownGlobalVariable)
	{
		return false;
	}

	this->jOpen仓库老板金玲音的对话界面Call = this->特征码定位call(jOpen仓库老板金玲音的对话界面CallFeatureCode, sizeof(jOpen仓库老板金玲音的对话界面CallFeatureCode), 0x27F);
	if (!this->jOpen仓库老板金玲音的对话界面Call)
	{
		return false;
	}

	this->j3520OffsetValue = this->特征码定位偏移(j3520OffsetValueFeatureCode, sizeof(j3520OffsetValueFeatureCode), 0x1CC, 3, 4);
	if (!this->j3520OffsetValue)
	{
		return false;
	}

	this->jBlockOutTheEnvironmentCall = this->特征码定位call(jBlockOutTheEnvironmentCallFeatureCode, sizeof(jBlockOutTheEnvironmentCallFeatureCode), 0x226);
	if (!this->jBlockOutTheEnvironmentCall)
	{
		return false;
	}

	this->jUnityOfHeavenAndHumanityCall = this->特征码定位call(jUnityOfHeavenAndHumanityCallFeatureCode, sizeof(jUnityOfHeavenAndHumanityCallFeatureCode), 0x56);
	if (!this->jUnityOfHeavenAndHumanityCall)
	{
		return false;
	}

	this->j和死亡回城有关的全局变量 = this->特征码定位基址(j和死亡回城有关的全局变量FeatureCode, sizeof(j和死亡回城有关的全局变量FeatureCode), 0x15, 3, 4, 7);
	if (!this->j和死亡回城有关的全局变量)
	{
		return false;
	}

	this->jResPawnCall = *((QWORD*)(*((QWORD*)(this->j和死亡回城有关的全局变量 + 0x8)) + 0x8));
	if (!this->jResPawnCall)
	{
		return false;
	}

	this->jChangeServerCall = this->特征码定位call(jChangeServerCallFeatureCode, sizeof(jChangeServerCallFeatureCode), 0x3C);
	if (!this->jChangeServerCall)
	{
		return false;
	}

	this->jSkillsArrayOffsetValue = this->特征码定位偏移(jSkillsArrayOffsetValueFeatureCode, sizeof(jSkillsArrayOffsetValueFeatureCode), 0x3A, 3, 4);
	if (!this->jSkillsArrayOffsetValue)
	{
		return false;
	}

	this->jSkillsNumberOffsetValue = this->特征码定位偏移(jSkillsNumberOffsetValueFeatureCode, sizeof(jSkillsNumberOffsetValueFeatureCode), 0x25, 3, 4);
	if (!this->jSkillsNumberOffsetValue)
	{
		return false;
	}

	this->jSelectCharacterObjectOfIdOffsetValue = this->特征码定位偏移(jSelectCharacterObjectOfIdOffsetValueFeatureCode, sizeof(jSelectCharacterObjectOfIdOffsetValueFeatureCode), 0x98, 2, 4);
	if (!this->jSelectCharacterObjectOfIdOffsetValue)
	{
		return false;
	}

	this->jCastSkillCall = this->特征码定位call(jCastSkillCallFeatureCode, sizeof(jCastSkillCallFeatureCode), 0xE9);
	if (!this->jCastSkillCall)
	{
		return false;
	}

	this->jActionDisruptionCall = this->特征码定位call(jActionDisruptionCallFeatureCode, sizeof(jActionDisruptionCallFeatureCode), 0x1AE);
	if (!this->jActionDisruptionCall)
	{
		return false;
	}

	this->jPathfindingCall = this->特征码定位call(jPathfindingCallFeatureCode, sizeof(jPathfindingCallFeatureCode), -0x1A);
	if (!this->jPathfindingCall)
	{
		return false;
	}

	this->jPathfindingCall_Rcx = this->特征码定位基址(jPathfindingCall_RaxFeatureCode, sizeof(jPathfindingCall_RaxFeatureCode), 0x2f, 3, 4, 7);
	if (!this->jPathfindingCall_Rcx)
	{
		return false;
	}

	this->jNavigateCall_1 = this->特征码定位基址(jNavigateCallFeatureCode, sizeof(jNavigateCallFeatureCode), 0x4A, 1, 4, 5);
	if (!this->jNavigateCall_1)
	{
		return false;
	}

	this->jNavigateCall_2 = this->特征码定位基址(jNavigateCallFeatureCode, sizeof(jNavigateCallFeatureCode), 0x5C, 1, 4, 5);
	if (!this->jNavigateCall_2)
	{
		return false;
	}

	this->jNavigateCall_3 = this->特征码定位基址(jNavigateCallFeatureCode, sizeof(jNavigateCallFeatureCode), 0x88, 1, 4, 5);
	if (!this->jNavigateCall_3)
	{
		return false;
	}

	this->jSelectNpcCall = this->特征码定位call(jSelectNpcCallFeatureCode, sizeof(jSelectNpcCallFeatureCode), 0xDD);
	if (!this->jSelectNpcCall)
	{
		return false;
	}
	return true;




}

QWORD BaseAddress::获取本人对象()
{
return this->j本人对象;
}

QWORD BaseAddress::获取打坐call()
{
return this->j打坐call;
}

QWORD BaseAddress::取消打坐call()
{
return this->j取消打坐call;
}

QWORD BaseAddress::整理装备call()
{
return this->j整理装备call;
}

QWORD BaseAddress::使用物品call()
{
return this->j使用物品call;
}

QWORD BaseAddress::背包对象的偏移()
{
return this->j背包对象的偏移;
}

QWORD BaseAddress::getRemoteItemDestructionCall()
{
return this->jRemoteItemDestructionCall;
}

QWORD BaseAddress::获取未知对象()
{
return this->j未知对象;
}

QWORD BaseAddress::getWarehouseOffsetValue()
{
return this->jWarehouseOffsetValue;
}

QWORD BaseAddress::getBagOfHoldingCall()
{
return this->jBagOfHoldingCall;
}

QWORD BaseAddress::getPacketizationCall()
{
return this->jPacketizationCall;
}

QWORD BaseAddress::getWarehouseCall()
{
return this->jWarehouseCall;
}

QWORD BaseAddress::getOpenWarehouseCall()
{
return this->jOpenWarehouseCall;
}

QWORD BaseAddress::getCloseWarehouseCall()
{
return this->jCloseWarehouseCall;
}

QWORD BaseAddress::getUnknownGlobalVariable()
{
return this->jUnknownGlobalVariable;
}

QWORD BaseAddress::getOpen仓库老板金玲音的对话界面Call()
{
return this->jOpen仓库老板金玲音的对话界面Call;
}

QWORD BaseAddress::get3520OffsetValue()
{
return this->j3520OffsetValue;
}

QWORD BaseAddress::getBlockOutTheEnvironmentCall()
{
return this->jBlockOutTheEnvironmentCall;
}

QWORD BaseAddress::getUnityOfHeavenAndHumanityCall()
{
return this->jUnityOfHeavenAndHumanityCall;
}

QWORD BaseAddress::get和死亡回城有关的全局变量()
{
return this->j和死亡回城有关的全局变量;
}

QWORD BaseAddress::getResPawnCall()
{
return this->jResPawnCall;
}

QWORD BaseAddress::getChangeServerCall()
{
return this->jChangeServerCall;
}

QWORD BaseAddress::getSkillsArrayOffsetValue()
{
return this->jSkillsArrayOffsetValue;
}

QWORD BaseAddress::getSkillsNumberOffsetValue()
{
return this->jSkillsNumberOffsetValue;
}

QWORD BaseAddress::getSelectCharacterObjectOfIdOffsetValue()
{
return this->jSelectCharacterObjectOfIdOffsetValue;
}

QWORD BaseAddress::getCastSkillCall()
{
return this->jCastSkillCall;
}

QWORD BaseAddress::getActionDisruptionCall()
{
return this->jActionDisruptionCall;
}

QWORD BaseAddress::getPathfindingCall()
{
	return this->jPathfindingCall;
}

QWORD BaseAddress::getPathfindingCall_Rcx()
{
	return this->jPathfindingCall_Rcx;
}

QWORD BaseAddress::getNavigate_1()
{
	return this->jNavigateCall_1;
}

QWORD BaseAddress::getNavigate_2()
{
	return this->jNavigateCall_2;
}

QWORD BaseAddress::getNavigate_3()
{
	return this->jNavigateCall_3;
}

QWORD BaseAddress::getSelectNpcCall()
{
	return this->jSelectNpcCall;
}

BaseAddress& BaseAddress::operator=(IN UINT value)
{
this->j本人对象 = value;
this->j打坐call = value;
this->j取消打坐call = value;
this->j使用物品call = value;
this->j背包对象的偏移 = value;
this->j整理装备call = value;
this->jRemoteItemDestructionCall = value;
this->j未知对象 = value;
this->j未知对象指针 = value;
this->jPacketizationCall = value;
this->jBagOfHoldingCall = value;
this->jWarehouseOffsetValue = value;
this->jWarehouseCall = value;
this->jOpenWarehouseCall = value;
this->jCloseWarehouseCall = value;
this->jUnknownGlobalVariable = value;
this->jOpen仓库老板金玲音的对话界面Call = value;
this->j3520OffsetValue = value;
this->jBlockOutTheEnvironmentCall = value;
this->jUnityOfHeavenAndHumanityCall = value;
this->j和死亡回城有关的全局变量 = value;
this->jResPawnCall = value;
this->jChangeServerCall = value;
this->jSkillsArrayOffsetValue = value;
this->jSkillsNumberOffsetValue = value;
this->jSelectCharacterObjectOfIdOffsetValue = value;
this->jCastSkillCall = value;
this->jActionDisruptionCall = value;
this->jPathfindingCall = value;
this->jPathfindingCall_Rcx = value;
this->jNavigateCall_1 = value;
this->jNavigateCall_2 = value;
this->jNavigateCall_3 = value;
this->jSelectNpcCall = value;

return *this;
}

CString BaseAddress::getBaseAddressData()
{
//基址数据
CString cstr;
cstr.AppendFormat(L"本人对象: %llX\r\n", this->j本人对象);
cstr.AppendFormat(L"打坐Call: %llX\r\n", this->j打坐call);
cstr.AppendFormat(L"取消打坐Call: %llX\r\n", this->j取消打坐call);
cstr.AppendFormat(L"整理装备Call: %llX\r\n", this->j整理装备call);
cstr.AppendFormat(L"使用物品Call: %llX\r\n", this->j使用物品call);
cstr.AppendFormat(L"背包对象的偏移: %llX\r\n", this->j背包对象的偏移);
cstr.AppendFormat(L"远程销毁物品Call: %llX\r\n", this->jRemoteItemDestructionCall);
cstr.AppendFormat(L"未知对象: %llX\r\n", this->j未知对象);
cstr.AppendFormat(L"未知对象指针: %llX\r\n", this->j未知对象指针);
cstr.AppendFormat(L"组包Call: %llx\r\n", this->jPacketizationCall);
cstr.AppendFormat(L"仓库对象的偏移: %llx\r\n", this->jWarehouseOffsetValue);
cstr.AppendFormat(L"仓库Call: %llx\r\n", this->jWarehouseCall);
cstr.AppendFormat(L"打开仓库Call: %llx\r\n", this->jOpenWarehouseCall);
cstr.AppendFormat(L"关闭仓库Call: %llx\r\n", this->jCloseWarehouseCall);
cstr.AppendFormat(L"未知的全局变量: %llx\r\n", this->jUnknownGlobalVariable);
cstr.AppendFormat(L"打开仓库老板金玲音的对话界面Call: %llx\r\n", this->jOpen仓库老板金玲音的对话界面Call);
cstr.AppendFormat(L"屏蔽环境Call: %llx\r\n", this->jBlockOutTheEnvironmentCall);
cstr.AppendFormat(L"天人合一Call: %llx\r\n", this->jUnityOfHeavenAndHumanityCall);
cstr.AppendFormat(L"和死亡回城有关的全局变量: %llx\r\n", this->j和死亡回城有关的全局变量);
cstr.AppendFormat(L"和死亡回城Call: %llx\r\n", this->jResPawnCall);
cstr.AppendFormat(L"换线路Call: %llx\r\n", this->jChangeServerCall);
cstr.AppendFormat(L"技能数组偏移量: %llx\r\n", this->jSkillsArrayOffsetValue);
cstr.AppendFormat(L"技能总数偏移值: %llx\r\n", this->jSkillsNumberOffsetValue);
cstr.AppendFormat(L"选中角色对象id的偏移值: %llx\r\n", this->jSelectCharacterObjectOfIdOffsetValue);
cstr.AppendFormat(L"释放技能Call: %llx\r\n", this->jCastSkillCall);
cstr.AppendFormat(L"动作中断Call: %llx\r\n", this->jActionDisruptionCall);
cstr.AppendFormat(L"寻路Call:    %llx\r\n", this->jPathfindingCall);
cstr.AppendFormat(L"寻路Call参数1_rcx未知的结构体类型的全局变量: %llx\r\n", this->jPathfindingCall_Rcx);
cstr.AppendFormat(L"走路Call_1: %llx\r\n", this->jNavigateCall_1);
cstr.AppendFormat(L"走路Call_2: %llx\r\n", this->jNavigateCall_2);
cstr.AppendFormat(L"走路Call_3: %llx\r\n", this->jNavigateCall_3);
cstr.AppendFormat(L"选中NpcCall: %llx\r\n",this->jSelectNpcCall);
return cstr;
}



BaseAddress::~BaseAddress()
{
	
}





