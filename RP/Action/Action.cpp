#include "../../pch.h"
#include "Action.h"
#include "../../Tools/BaseAddress/BaseAddress.h"

typedef  QWORD(FASTCALL* Function_useItemCall)(QWORD, QWORD, QWORD, QWORD);
typedef  QWORD(FASTCALL* Function_meditationCall)();
typedef  QWORD(FASTCALL* Function_cancelMeditationCall)();
typedef  QWORD(FASTCALL* Function_organizeBackpackCall)(QWORD);
typedef  void (FASTCALL* Function_remoteItemDestructionCall)(QWORD, QWORD);
typedef  void (FASTCALL* Function_packetizationCall)(QWORD, QWORD, QWORD);
typedef  void(FASTCALL* function_BagOfHoldingCall)(QWORD);
extern   BaseAddress bAObject;

Action::Action()
{

}

Action::~Action()
{
}

QWORD Action:: useItem(IN QWORD ���˶���, IN QWORD rdx, IN QWORD �±�, IN QWORD r9)
{
	Function_useItemCall call = (Function_useItemCall)(bAObject.ʹ����Ʒcall());
	QWORD rax = call(���˶���, rdx, �±�, r9);

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

QWORD Action::organizeBackpack(IN QWORD rcx)
{
	Function_organizeBackpackCall call = (Function_organizeBackpackCall)(bAObject.����װ��call());
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
	//������ݻ�����
	BYTE packetizationBuffer[10] = { 0x20,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
	*((DWORD*)(&packetizationBuffer[2])) = itemIndex;
	*((DWORD*)(&packetizationBuffer[6])) = itemId;
	//���Call
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	QWORD rcx = *((QWORD*)(bAObject.��ȡδ֪����() + 0x40));
	Call(rcx, (QWORD)packetizationBuffer, 0x0A);
}

void Action::bagOfHolding(IN DWORD itemIndex)
{
	function_BagOfHoldingCall Call = (function_BagOfHoldingCall)bAObject.getBagOfHoldingCall();
	Call(itemIndex);
}

void Action::packetization_BagOfHolding(IN DWORD itemIndex)
{
	//������ݻ�����
	BYTE packetizationBuffer[6] = {0xDB,0x01,0x00,0x00,0x00,0x00};
	*((DWORD*)(&packetizationBuffer[2])) = itemIndex;
	//���Call
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	QWORD rcx = *((QWORD*)(bAObject.��ȡδ֪����() + 0x40));
	Call(rcx, (QWORD)packetizationBuffer, 0x06);
}

