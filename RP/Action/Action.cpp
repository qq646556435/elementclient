#include "../../pch.h"
#include "Action.h"
#include "../../Tools/BaseAddress/BaseAddress.h"

extern   BaseAddress bAObject;


Action::Action()
{

}
Action::~Action()
{
}
QWORD Action:: useItem(IN QWORD 下标)
{
	
	Function_useItemCall call = (Function_useItemCall)(bAObject.使用物品call());
	QWORD rax = call(bAObject.获取本人对象(), 0, 下标, 1);

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
QWORD Action::organizeBackpack()
{
	Function_organizeBackpackCall call = (Function_organizeBackpackCall)(bAObject.整理装备call());
	QWORD rax = call(0);

	return rax;
}
void Action::remoteItemDestruction(IN PTCHAR itemName)
{   
	
}
void Action::packetization_RemoteItemDestruction(IN PTCHAR itemName)
{

}
void Action::bagOfHolding(IN PTCHAR itemName)
{
	
}
void Action::packetization_BagOfHolding(IN PTCHAR itemName)
{
	
}
void Action::backPackToWarehouse(IN PTCHAR itemName)
{
	
}
void Action::packetization_BackPackToWarehouse(IN PTCHAR itemName)
{
	
}
void Action::warehouseToBackPack(IN PTCHAR itemName)
{
	
}
void Action::packetization_WarehouseToBackPack(IN PTCHAR itemName)
{
	
}
void Action::openWarehouseCall()
{
	QWORD unknownGlobalVariable = bAObject.getUnknownGlobalVariable();
	QWORD rdx = 0x0;
	function_OpenWarehouseCall Call = (function_OpenWarehouseCall)(bAObject.getOpenWarehouseCall());

	Call(unknownGlobalVariable, rdx);
}
void Action::packetization_OpenWarehouseCall()
{
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	BYTE  packetizationBuffer[14] = { 0x25,0x00 ,0x0F ,0x00 ,0x00 ,0x00 ,0x04 ,0x00 ,0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	QWORD r8 = 0x0E;
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	Call(rcx, (QWORD)packetizationBuffer, r8);
	
}
QWORD Action::closeWarehouseCall()
{
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));

	Function_CloseWarehouseCall Call = (Function_CloseWarehouseCall)(bAObject.getCloseWarehouseCall());
	QWORD rax = Call(rcx);
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
QWORD Action::open仓库老板金玲音对话界面Call()
{
	QWORD unknownObjectOne = *((PQWORD)(*((PQWORD)(*((PQWORD)(bAObject.获取本人对象() + bAObject.get3520OffsetValue()))+0x68))+(2*8)));
	QWORD unknownObjectTwo = *((PQWORD)(*((PQWORD)(*((PQWORD)(*((PQWORD)(*((PQWORD)(bAObject.获取未知对象() + 0x38))+0x10))+0x50))+0x98))+(0x4e*8)));
	Function_Open仓库老板金玲音对话界面Call call = (Function_Open仓库老板金玲音对话界面Call)bAObject.getOpen仓库老板金玲音的对话界面Call();
	
	QWORD rax= call(unknownObjectOne, unknownObjectTwo);

	return rax;
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
QWORD Action::selfCasting(IN QWORD skillId)
{

	return true;
}
QWORD Action::casting(IN QWORD skillId, IN PQWORD pInGameCharacterObject)
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
QWORD Action::actionDisruption()
{  
   QWORD playerCharacterObject = bAObject.获取本人对象(); //本人玩家对象
   Function_ActionDisruptionCall call = (Function_ActionDisruptionCall)bAObject.getActionDisruptionCall();//动作中断Call
   QWORD rax = 0;//返回值
   //调用动作中断Call
   rax = call(playerCharacterObject);
   //返回值返回
   return rax;
}
void Action::packetization_ActionDisruption()
{
	QWORD unknownObject = *((QWORD*)(bAObject.获取未知对象() + 0x40));//未知对象
	BYTE  packetizationBuffer[2] = { 0x2A,0x00 };//组包数据缓冲区
	QWORD r8 = 0x02;//组包的包长
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());//组包Call
	//调用组包Call
	Call(unknownObject, (QWORD)packetizationBuffer, r8);
}
QWORD Action::pathfinding(IN DataStruct::data_Coordinates* targetCoordinates)
{
	/*
	[[[[0x000000014156D1A0]+0x38]+0x10]+0x138]
	mov byte[rsp+20],0x01
	mov r9,所在地图的id
	mov r8,目的坐标
	mov rdx,当前坐标
	mov rcx,未知的结构体类型的全局变量
	Call 寻路Call
	mov rax,rax
	unknownglobal variable
	Current Coordinates
	*/
	QWORD unknownGlobalVariable = bAObject.getPathfindingCall_Rcx();//未知的结构体类型的全局变量
	PQWORD pCurrentCoordinates = (PQWORD)(bAObject.获取本人对象() + 0x1370);//指向当前坐标的指针
	PQWORD pTargetCoordinates = (PQWORD)targetCoordinates;//指向目的坐标的指针
	QWORD  currentMapId = *((PQWORD)(*((PQWORD)(*((PQWORD)(bAObject.获取未知对象() + 0x38))+0x10))+0x138));//当前地图的id
	byte   rsp_20 = 0x01;//默认参数0x01
	Function_PathfindingCall call = (Function_PathfindingCall)bAObject.getPathfindingCall();//寻路Call
	QWORD rax = 0;
	//调用寻路Call
	rax = call(unknownGlobalVariable, pCurrentCoordinates, pTargetCoordinates, currentMapId, rsp_20);
	
	//返回值
	return rax;

}
QWORD Action::navigate(IN DataStruct::data_Coordinates* targetCoordinates)
{
	/*
	 mov edx,0x1
	mov rcx,[本人对象+3520]
	Call 走路Call_1
	mov rbx,rax
	mov r8 ,目的坐标
	mov edx,0x0
	mov rcx,rax
	Call 走路Call_2
	mov byte ptr ss:[rsp+0x20],0x0
	mov r9d,0x1
	mov r8,rbx
	mov edx,0x01
	mov rcx,[本人对象+3520]
	Call 走路Call_3
	mov rax,rax
	
	*/
	Function_NacigateCall_1 navigateCall_1 = (Function_NacigateCall_1)bAObject.getNavigate_1();//走路Call_1
	Function_NacigateCall_2 navigateCall_2 = (Function_NacigateCall_2)bAObject.getNavigate_2();//走路Call_2
	Function_NacigateCall_3 navigateCall_3 = (Function_NacigateCall_3)bAObject.getNavigate_3();//走路Call_3
	QWORD rcx = *((PQWORD)(bAObject.获取本人对象() + bAObject.get3520OffsetValue()));
	DWORD edx = 0x01;
	QWORD rax = 0;
	rax = navigateCall_1(rcx, edx);

	rcx = rax;
	edx = 0x0;
	PQWORD r8 = (PQWORD)targetCoordinates;
	navigateCall_2(rcx, edx, r8);

	rcx = *((PQWORD)(bAObject.获取本人对象() + bAObject.get3520OffsetValue()));
	edx = 0x01;
	QWORD r8_1 = rax;
	DWORD r9 = 0x01;
	BYTE rsp_20 = 0x0;
	rax = navigateCall_3(rcx, edx, r8_1, r9, rsp_20);

	return rax;
}
QWORD Action::selectNpcCall(IN DWORD npcObjectId)
{
	DWORD rcx = npcObjectId;//npc对象的id
	Function_SelectNpcCall call = (Function_SelectNpcCall)bAObject.getSelectNpcCall();//选中NpcCall
	//调用选中NpcCall
	DWORD rax = call(rcx);
	//返回值
	return rax;
}
