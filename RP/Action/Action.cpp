#include "../../pch.h"
#include "Action.h"
#include "../../Tools/BaseAddress/BaseAddress.h"
#include <iostream>
typedef  QWORD(FASTCALL* Function_useItemCall)(QWORD, QWORD, QWORD, QWORD);
typedef  QWORD(FASTCALL* Function_meditationCall)();
typedef  QWORD(FASTCALL* Function_cancelMeditationCall)();
typedef  QWORD(FASTCALL* Function_organizeBackpackCall)(QWORD);
typedef  void (FASTCALL* Function_remoteItemDestructionCall)(QWORD, QWORD);
typedef  void (FASTCALL* Function_packetizationCall)(QWORD, QWORD, QWORD);
typedef  void(FASTCALL* function_BagOfHoldingCall)(QWORD); 
typedef  void(FASTCALL* function_WarehouseCall)(QWORD, QWORD, QWORD, QWORD);
typedef  void(FASTCALL* function_OpenWarehouseCall)(QWORD,QWORD);
typedef  QWORD(FASTCALL* Function_CloseWarehouseCall)(QWORD);
typedef  QWORD(FASTCALL* Function_Open仓库老板金玲音对话界面Call)(QWORD, QWORD);
typedef  QWORD(FASTCALL* Function_BlockOutTheEnvironmentCall)(QWORD);
typedef  QWORD(FASTCALL* Function_UnityOfHeavenAndHumanityCall)(QWORD, QWORD, QWORD);
typedef  QWORD(FASTCALL* Function_RespawnCall)(QWORD, PTCHAR);
typedef  QWORD(FASTCALL* Function_ChangeServerCall)(QWORD, QWORD);
typedef  QWORD(FASTCALL* Function_SpellcastingCall)(QWORD, QWORD, QWORD, QWORD, QWORD);

extern   BaseAddress bAObject;

Action::Action()
{

}

Action::~Action()
{
}

QWORD Action:: useItem(IN QWORD 本人对象, IN QWORD rdx, IN QWORD 下标, IN QWORD r9)
{
	Function_useItemCall call = (Function_useItemCall)(bAObject.使用物品call());
	QWORD rax = call(本人对象, rdx, 下标, r9);

	return rax;
}

QWORD Action::meditation()
{
	Function_meditationCall call = (Function_meditationCall)(bAObject.获取打坐call());
	QWORD rax = call();

	return rax;
}

QWORD Action::cancelMeditation()
{
	Function_cancelMeditationCall call = (Function_cancelMeditationCall)(bAObject.取消打坐call());
	QWORD rax = call();
	
	return rax;
}

QWORD Action::organizeBackpack(IN QWORD rcx)
{
	Function_organizeBackpackCall call = (Function_organizeBackpackCall)(bAObject.整理装备call());
	QWORD rax = call(rcx);

	return rax;
}

void Action::remoteItemDestruction(IN QWORD itemIndex, IN QWORD itemId)
{   
	Function_remoteItemDestructionCall call = (Function_remoteItemDestructionCall)bAObject.getRemoteItemDestructionCall();
	call(itemIndex, itemId);
}

void Action::packetization_RemoteItemDestruction(IN DWORD itemIndex, IN DWORD itemId)
{
	//组包数据缓冲区
	BYTE packetizationBuffer[10] = { 0x20,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
	*((DWORD*)(&packetizationBuffer[2])) = itemIndex;
	*((DWORD*)(&packetizationBuffer[6])) = itemId;
	//组包Call
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	Call(rcx, (QWORD)packetizationBuffer, 0x0A);
}

void Action::bagOfHolding(IN DWORD itemIndex)
{
	function_BagOfHoldingCall Call = (function_BagOfHoldingCall)bAObject.getBagOfHoldingCall();
	Call(itemIndex);
}

void Action::packetization_BagOfHolding(IN DWORD itemIndex)
{
	//组包数据缓冲区
	BYTE packetizationBuffer[6] = {0xDB,0x01,0x00,0x00,0x00,0x00};
	*((DWORD*)(&packetizationBuffer[2])) = itemIndex;
	//组包Call
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	Call(rcx, (QWORD)packetizationBuffer, 0x06);
}

void Action::backPackToWarehouse(IN QWORD unknownObject, IN QWORD rdx=0, IN QWORD targetWarehouseIndex=0, IN QWORD soureBackPackIndex=0)
{
	function_WarehouseCall Call = (function_WarehouseCall)(bAObject.getWarehouseCall());
	Call(unknownObject, rdx, targetWarehouseIndex, soureBackPackIndex);
}

void Action::packetization_BackPackToWarehouse(IN DWORD targetWarehouseIndex, IN DWORD soureBackPackIndex)
{
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	BYTE packetizationBuffer[10] = { 0x3A ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,0x00 ,0x00 ,0x00 };
	*((DWORD*)(&packetizationBuffer[2])) = targetWarehouseIndex;
	*((DWORD*)(&packetizationBuffer[6])) = soureBackPackIndex;
	Call(rcx, (QWORD)packetizationBuffer, 0x0A);
}

void Action::warehouseToBackPack(IN QWORD unknownObject, IN QWORD rdx=0, IN QWORD soureWarehouseIndex=0, IN QWORD targetBackPackIndex=0)
{
	function_WarehouseCall Call = (function_WarehouseCall)(bAObject.getWarehouseCall());
	Call(unknownObject, rdx, soureWarehouseIndex, targetBackPackIndex);
}

void Action::packetization_WarehouseToBackPack(IN DWORD soureWarehouseIndex, IN DWORD targetBackPackIndex)
{
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	BYTE packetizationBuffer[10] = { 0x3A ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,0x00 ,0x00 ,0x00 };
	*((DWORD*)(&packetizationBuffer[2])) = soureWarehouseIndex;
	*((DWORD*)(&packetizationBuffer[6])) = targetBackPackIndex;
	Call(rcx, (QWORD)packetizationBuffer, 0x0A);
}

void Action::openWarehouseCall(IN QWORD unknownGlobalVariable, IN QWORD rdx)
{
	function_OpenWarehouseCall Call = (function_OpenWarehouseCall)(bAObject.getOpenWarehouseCall());
	Call(unknownGlobalVariable,rdx);
}

void Action::packetization_OpenWarehouseCall()
{
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	BYTE  packetizationBuffer[14] = { 0x25,0x00 ,0x0F ,0x00 ,0x00 ,0x00 ,0x04 ,0x00 ,0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	QWORD r8 = 0x0E;
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	Call(rcx, (QWORD)packetizationBuffer, r8);
	
}

QWORD Action::closeWarehouseCall(IN QWORD unknownObject)
{

	Function_CloseWarehouseCall Call = (Function_CloseWarehouseCall)(bAObject.getCloseWarehouseCall());
	QWORD rax = Call(unknownObject);
	return rax;
}

void Action::packetization_CloseWarehouseCall()
{
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	BYTE  packetizationBuffer[2] = { 0x2A ,0x00 };
	QWORD r8 = 0x02;
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	Call(rcx, (QWORD)packetizationBuffer, r8);
}

QWORD Action::open仓库老板金玲音对话界面Call(IN QWORD unknownObjectOne, IN QWORD unknownObjectTwo)
{
	
	return 0;
}



void Action::Close仓库老板金玲音对话界面Call()
{
	
	HWND hwnd = ::FindWindow(L"ZElementClient Window", 0);
	::SetForegroundWindow(hwnd);
	// 模拟按下ESC键
	keybd_event(VK_ESCAPE, 0, 0, 0);

	// 模拟释放ESC键
	keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
	
	
}

QWORD Action::blockOutTheEnvironmentCall()
{
	QWORD unknownObject = *((QWORD*)(bAObject.获取未知对象() + 0x38));
	Function_BlockOutTheEnvironmentCall call = (Function_BlockOutTheEnvironmentCall)(bAObject.getBlockOutTheEnvironmentCall());
	QWORD rax = call(unknownObject);
	return rax;
}

QWORD Action::openUnityOfHeavenAndHumanity()
{
	Function_UnityOfHeavenAndHumanityCall call = (Function_UnityOfHeavenAndHumanityCall)(bAObject.getUnityOfHeavenAndHumanityCall());
	QWORD rax = call(1, 0, 0);
	return rax;
}

QWORD Action::closeUnityOfHeavenAndHumanity()
{
	Function_UnityOfHeavenAndHumanityCall call = (Function_UnityOfHeavenAndHumanityCall)(bAObject.getUnityOfHeavenAndHumanityCall());
	QWORD rax = call(0, 0, 0);
	return rax;
}

void Action::packetization_OpenUnityOfHeavenAndHumanity()
{
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	BYTE  packetizationBuffer[5] = { 0x72 ,0x00 ,0x01 ,0x00,0x00 };
	QWORD r8 = 0x05;
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	Call(rcx, (QWORD)packetizationBuffer, r8);
}

void Action::packetization_CloseUnityOfHeavenAndHumanity()
{
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	BYTE  packetizationBuffer[5] = { 0x72 ,0x00 ,0x00 ,0x00,0x00 };
	QWORD r8 = 0x05;
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	Call(rcx, (QWORD)packetizationBuffer, r8);
}

QWORD Action::resPawn()
{
	QWORD mRcx = *((QWORD*)(*((QWORD*)(bAObject.get和死亡回城有关的全局变量() + 0x8)) + 0x10));
	PTCHAR mRdx = L"confirm";
	Function_RespawnCall mCall = (Function_RespawnCall)(bAObject.getResPawnCall());
	QWORD mRax = 0;
	
	mRax = mCall(mRcx, mRdx);

	return mRax;
		
}

QWORD Action::changeServer(IN UINT server)
{
	

	QWORD unknownObject = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	Function_ChangeServerCall call = (Function_ChangeServerCall)(bAObject.getChangeServerCall());
	QWORD rax = call(unknownObject, server);

	return rax;
}

DWORD Action::getSelectCharacterObjectOfId()
{
	DWORD id = *((PDWORD)(bAObject.获取本人对象() + bAObject.getSelectCharacterObjectOfIdOffsetValue()));
	return id;
}

DWORD Action::selfCasting(IN QWORD skillId)
{

	return true;
}

DWORD Action::casting(IN QWORD skillId, IN PQWORD pInGameCharacterObject)
{
	QWORD mSkillId = skillId;
	QWORD rdx = 0x80;
	QWORD r8 = 0x01;
	QWORD r9 = (QWORD)pInGameCharacterObject;
	QWORD rsp_0x20 = 0x0;
	Function_SpellcastingCall call = (Function_SpellcastingCall)bAObject.getCastSkillCall();
	QWORD rax = call(mSkillId, rdx, r8, r9, rsp_0x20);
	return rax;
}

