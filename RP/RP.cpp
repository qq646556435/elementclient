#include "RP.h"
#include "../Tools/BaseAddress/BaseAddress.h"
typedef  QWORD(FASTCALL* Function_SpellcastingCall)(QWORD, QWORD, QWORD, QWORD, QWORD);
extern BaseAddress bAObject;
RP::RP()
{

}

void RP::init()
{
	this->OC::init();
	this->BackPack::init();
	this->Warehouse::init();
}

DWORD RP::selfCasting(IN QWORD skillId)
{
	QWORD mSkillid = skillId;
	QWORD rdx = 0x80;
	QWORD r8 = 0x01;
	//本人玩家的角色对象id
	PDWORD pMyCharacterObjectId = (PDWORD) & this->角色信息.id;
	QWORD r9 = (QWORD)pMyCharacterObjectId;
	QWORD rsp_20 = 0x0;
	Function_SpellcastingCall call = (Function_SpellcastingCall)bAObject.getCastSkillCall();
	QWORD rax = call(mSkillid, rdx, r8, r9, rsp_20);

	return rax;
}

