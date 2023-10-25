#include "../../pch.h"
#include "Action.h"
#include "../../Tools/BaseAddress/BaseAddress.h"

typedef  QWORD(FASTCALL* Function_useItemCall)(QWORD, QWORD, QWORD, QWORD);
typedef  QWORD(FASTCALL* Function_meditationCall)();
typedef  QWORD(FASTCALL* Function_cancelMeditationCall)();
typedef  QWORD(FASTCALL* Function_organizeBackpackCall)(QWORD);
typedef  void (FASTCALL* Function_remoteItemDestructionCall)(QWORD, QWORD);
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

