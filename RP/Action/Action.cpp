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
typedef  QWORD(FASTCALL* Function_Open�ֿ��ϰ�������Ի�����Call)(QWORD, QWORD);
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

QWORD Action:: useItem(IN QWORD �±�)
{
	
	Function_useItemCall call = (Function_useItemCall)(bAObject.ʹ����Ʒcall());
	QWORD rax = call(bAObject.��ȡ���˶���(), 0, �±�, 1);

	return rax;
}

QWORD Action::meditation()
{
	Function_meditationCall call = (Function_meditationCall)(bAObject.��ȡ����call());
	QWORD rax = call();

	return rax;
}

QWORD Action::cancelMeditation()
{
	Function_cancelMeditationCall call = (Function_cancelMeditationCall)(bAObject.ȡ������call());
	QWORD rax = call();
	
	return rax;
}

QWORD Action::organizeBackpack()
{
	Function_organizeBackpackCall call = (Function_organizeBackpackCall)(bAObject.����װ��call());
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
	QWORD rcx = *((QWORD*)(bAObject.��ȡδ֪����() + 0x40));
	BYTE  packetizationBuffer[14] = { 0x25,0x00 ,0x0F ,0x00 ,0x00 ,0x00 ,0x04 ,0x00 ,0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	QWORD r8 = 0x0E;
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	Call(rcx, (QWORD)packetizationBuffer, r8);
	
}

QWORD Action::closeWarehouseCall()
{
	QWORD rcx = *((QWORD*)(bAObject.��ȡδ֪����() + 0x40));

	Function_CloseWarehouseCall Call = (Function_CloseWarehouseCall)(bAObject.getCloseWarehouseCall());
	QWORD rax = Call(rcx);
	return rax;
}

void Action::packetization_CloseWarehouseCall()
{
	QWORD rcx = *((QWORD*)(bAObject.��ȡδ֪����() + 0x40));
	BYTE  packetizationBuffer[2] = { 0x2A ,0x00 };
	QWORD r8 = 0x02;
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	Call(rcx, (QWORD)packetizationBuffer, r8);
}

QWORD Action::open�ֿ��ϰ�������Ի�����Call()
{
	QWORD unknownObjectOne = *((PQWORD)(*((PQWORD)(*((PQWORD)(bAObject.��ȡ���˶���() + bAObject.get3520OffsetValue()))+0x68))+(2*8)));
	QWORD unknownObjectTwo = *((PQWORD)(*((PQWORD)(*((PQWORD)(*((PQWORD)(*((PQWORD)(bAObject.��ȡδ֪����() + 0x38))+0x10))+0x50))+0x98))+(0x4e*8)));
	Function_Open�ֿ��ϰ�������Ի�����Call call = (Function_Open�ֿ��ϰ�������Ի�����Call)bAObject.getOpen�ֿ��ϰ�������ĶԻ�����Call();
	
	QWORD rax= call(unknownObjectOne, unknownObjectTwo);

	return rax;
}

void Action::Close�ֿ��ϰ�������Ի�����Call()
{
	
	HWND hwnd = ::FindWindow(L"ZElementClient Window", 0);
	::SetForegroundWindow(hwnd);
	// ģ�ⰴ��ESC��
	keybd_event(VK_ESCAPE, 0, 0, 0);

	// ģ���ͷ�ESC��
	keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
	
	
}

QWORD Action::blockOutTheEnvironmentCall()
{
	QWORD unknownObject = *((QWORD*)(bAObject.��ȡδ֪����() + 0x38));
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
	QWORD rcx = *((QWORD*)(bAObject.��ȡδ֪����() + 0x40));
	BYTE  packetizationBuffer[5] = { 0x72 ,0x00 ,0x01 ,0x00,0x00 };
	QWORD r8 = 0x05;
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	Call(rcx, (QWORD)packetizationBuffer, r8);
}

void Action::packetization_CloseUnityOfHeavenAndHumanity()
{
	QWORD rcx = *((QWORD*)(bAObject.��ȡδ֪����() + 0x40));
	BYTE  packetizationBuffer[5] = { 0x72 ,0x00 ,0x00 ,0x00,0x00 };
	QWORD r8 = 0x05;
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	Call(rcx, (QWORD)packetizationBuffer, r8);
}

QWORD Action::resPawn()
{
	QWORD mRcx = *((QWORD*)(*((QWORD*)(bAObject.get�������س��йص�ȫ�ֱ���() + 0x8)) + 0x10));
	PTCHAR mRdx = L"confirm";
	Function_RespawnCall mCall = (Function_RespawnCall)(bAObject.getResPawnCall());
	QWORD mRax = 0;
	
	mRax = mCall(mRcx, mRdx);

	return mRax;
		
}

QWORD Action::changeServer(IN UINT server)
{
	

	QWORD unknownObject = *((QWORD*)(bAObject.��ȡδ֪����() + 0x40));
	Function_ChangeServerCall call = (Function_ChangeServerCall)(bAObject.getChangeServerCall());
	QWORD rax = call(unknownObject, server);

	return rax;
}

DWORD Action::getSelectCharacterObjectOfId()
{
	DWORD id = *((PDWORD)(bAObject.��ȡ���˶���() + bAObject.getSelectCharacterObjectOfIdOffsetValue()));
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

