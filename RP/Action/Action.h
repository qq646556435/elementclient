#ifndef __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#define __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#pragma once
#include "../../Tools/DataStruct/DataStruct.h"
using  Function_useItemCall = QWORD(FASTCALL*)(QWORD, QWORD, QWORD, QWORD);
using  Function_meditationCall = QWORD(FASTCALL*)();
using  Function_cancelMeditationCall = QWORD(FASTCALL*)();
using  Function_organizeBackpackCall = QWORD(FASTCALL*)(QWORD);
using  Function_remoteItemDestructionCall = void (FASTCALL*)(QWORD, QWORD);
using  Function_packetizationCall = void (FASTCALL*)(QWORD, QWORD, QWORD);
using  function_BagOfHoldingCall = void(FASTCALL*)(QWORD);
using  function_WarehouseCall = void(FASTCALL*)(QWORD, QWORD, QWORD, QWORD);
using  function_OpenWarehouseCall = void(FASTCALL*)(QWORD, QWORD);
using  Function_CloseWarehouseCall = QWORD(FASTCALL*)(QWORD);
using  Function_Open仓库老板金玲音对话界面Call = QWORD(FASTCALL*)(QWORD, QWORD);
using  Function_BlockOutTheEnvironmentCall = QWORD(FASTCALL*)(QWORD);
using  Function_UnityOfHeavenAndHumanityCall = QWORD(FASTCALL*)(QWORD, QWORD, QWORD);
using  Function_RespawnCall = QWORD(FASTCALL*)(QWORD, PTCHAR);
using  Function_ChangeServerCall = QWORD(FASTCALL*)(QWORD, QWORD);
using  Function_SpellcastingCall = QWORD(FASTCALL*)(QWORD, QWORD, QWORD, QWORD, QWORD);
using  Function_ActionDisruptionCall = QWORD(FASTCALL*)(QWORD);
using  Function_PathfindingCall = QWORD(FASTCALL*)(QWORD, PQWORD, PQWORD, QWORD, byte);
using  Function_NacigateCall_1 = QWORD(FASTCALL*)(QWORD, DWORD);
using  Function_NacigateCall_2 = void (FASTCALL*)(QWORD, DWORD, PQWORD);
using  Function_NacigateCall_3 = QWORD(FASTCALL*)(QWORD, DWORD, QWORD, DWORD, BYTE);
using  Function_SelectNpcCall = QWORD(FASTCALL*)(DWORD);

class Action
{
public:
	Action();
	virtual ~Action();
	//使用指定物品
	QWORD virtual useItem(IN QWORD 下标);
	//打坐
	QWORD virtual meditation();
	//取消打坐
	QWORD virtual cancelMeditation();
	//整理背包
	QWORD virtual organizeBackpack();
	//远程销毁物品
	void virtual remoteItemDestruction(IN PTCHAR itemName);
	//组包销毁物品
	void virtual packetization_RemoteItemDestruction(IN PTCHAR itemName);
	//乾坤袋
	void virtual bagOfHolding(IN PTCHAR itemName);
	//组包乾坤袋
	void virtual packetization_BagOfHolding(IN PTCHAR itemName);
	//背包物品到仓库 
	void virtual backPackToWarehouse(IN PTCHAR itemName);
	//组包背包物品到仓库
	void virtual packetization_BackPackToWarehouse(IN PTCHAR itemName);
	//仓库物品到背包
	void virtual warehouseToBackPack(IN PTCHAR itemName);
	//组包仓库物品到背包
	void virtual packetization_WarehouseToBackPack(IN PTCHAR itemName);
	//打开仓库Call
	void virtual openWarehouseCall();
	//组包打开仓库Call
	void virtual packetization_OpenWarehouseCall();
	//关闭仓库Call
	QWORD virtual closeWarehouseCall();
	//组包关闭仓库Call
	void virtual packetization_CloseWarehouseCall();
	//打开仓库老板金玲音对话界面的Call
	QWORD virtual open仓库老板金玲音对话界面Call();
    //关闭仓库老板金玲音对话界面的Call
	void virtual Close仓库老板金玲音对话界面Call();
	//屏蔽环境Call
	QWORD virtual blockOutTheEnvironmentCall();
	//开启天人合一
	QWORD virtual openUnityOfHeavenAndHumanity();
	//关闭天人合一
	QWORD virtual closeUnityOfHeavenAndHumanity();
	//组包开启天人合一
	void virtual packetization_OpenUnityOfHeavenAndHumanity();
	//组包关闭天人合一
	void virtual packetization_CloseUnityOfHeavenAndHumanity();
	//死亡回城
	QWORD virtual resPawn();
	//换线路
	QWORD virtual changeServer(IN UINT server);
	//获取选中的角色对象id
	DWORD virtual getSelectCharacterObjectOfId();
	//自我施法
	QWORD virtual selfCasting(IN QWORD skillId);
	//施法: pInGameCharacterObject(指向游戏内角色对象id的指针)
	QWORD virtual casting(IN QWORD skillId, IN PQWORD pInGameCharacterObject);
	//动作中断
	QWORD virtual actionDisruption();
	//组包动作中断
	void virtual  packetization_ActionDisruption();
	/*
	  寻路Call:
	  参数1:(in) 目的坐标
      返回值: ture或者false	
	*/
	QWORD virtual pathfinding(IN DataStruct::data_Coordinates* targetCoordinates);
	/*
	  走路Call:
	  参数1:(in) 目的坐标
	  返回值: ture或者false
	*/
	QWORD virtual navigate(IN DataStruct::data_Coordinates* targetCoordinates);
	/*
	  选中NpcCall
	  参数1:(in) Npc对象的id
	  返回值: ture或者false
	*/
	QWORD virtual selectNpcCall(IN DWORD npcObjectId);
};

#endif //__ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
