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
QWORD Action::actionDisruption()
{  
   QWORD playerCharacterObject = bAObject.��ȡ���˶���(); //������Ҷ���
   Function_ActionDisruptionCall call = (Function_ActionDisruptionCall)bAObject.getActionDisruptionCall();//�����ж�Call
   QWORD rax = 0;//����ֵ
   //���ö����ж�Call
   rax = call(playerCharacterObject);
   //����ֵ����
   return rax;
}
void Action::packetization_ActionDisruption()
{
	QWORD unknownObject = *((QWORD*)(bAObject.��ȡδ֪����() + 0x40));//δ֪����
	BYTE  packetizationBuffer[2] = { 0x2A,0x00 };//������ݻ�����
	QWORD r8 = 0x02;//����İ���
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());//���Call
	//�������Call
	Call(unknownObject, (QWORD)packetizationBuffer, r8);
}
QWORD Action::pathfinding(IN DataStruct::data_Coordinates* targetCoordinates)
{
	/*
	[[[[0x000000014156D1A0]+0x38]+0x10]+0x138]
	mov byte[rsp+20],0x01
	mov r9,���ڵ�ͼ��id
	mov r8,Ŀ������
	mov rdx,��ǰ����
	mov rcx,δ֪�Ľṹ�����͵�ȫ�ֱ���
	Call Ѱ·Call
	mov rax,rax
	unknownglobal variable
	Current Coordinates
	*/
	QWORD unknownGlobalVariable = bAObject.getPathfindingCall_Rcx();//δ֪�Ľṹ�����͵�ȫ�ֱ���
	PQWORD pCurrentCoordinates = (PQWORD)(bAObject.��ȡ���˶���() + 0x1370);//ָ��ǰ�����ָ��
	PQWORD pTargetCoordinates = (PQWORD)targetCoordinates;//ָ��Ŀ�������ָ��
	QWORD  currentMapId = *((PQWORD)(*((PQWORD)(*((PQWORD)(bAObject.��ȡδ֪����() + 0x38))+0x10))+0x138));//��ǰ��ͼ��id
	byte   rsp_20 = 0x01;//Ĭ�ϲ���0x01
	Function_PathfindingCall call = (Function_PathfindingCall)bAObject.getPathfindingCall();//Ѱ·Call
	QWORD rax = 0;
	//����Ѱ·Call
	rax = call(unknownGlobalVariable, pCurrentCoordinates, pTargetCoordinates, currentMapId, rsp_20);
	
	//����ֵ
	return rax;

}
QWORD Action::navigate(IN DataStruct::data_Coordinates* targetCoordinates)
{
	/*
	 mov edx,0x1
	mov rcx,[���˶���+3520]
	Call ��·Call_1
	mov rbx,rax
	mov r8 ,Ŀ������
	mov edx,0x0
	mov rcx,rax
	Call ��·Call_2
	mov byte ptr ss:[rsp+0x20],0x0
	mov r9d,0x1
	mov r8,rbx
	mov edx,0x01
	mov rcx,[���˶���+3520]
	Call ��·Call_3
	mov rax,rax
	
	*/
	Function_NacigateCall_1 navigateCall_1 = (Function_NacigateCall_1)bAObject.getNavigate_1();//��·Call_1
	Function_NacigateCall_2 navigateCall_2 = (Function_NacigateCall_2)bAObject.getNavigate_2();//��·Call_2
	Function_NacigateCall_3 navigateCall_3 = (Function_NacigateCall_3)bAObject.getNavigate_3();//��·Call_3
	QWORD rcx = *((PQWORD)(bAObject.��ȡ���˶���() + bAObject.get3520OffsetValue()));
	DWORD edx = 0x01;
	QWORD rax = 0;
	rax = navigateCall_1(rcx, edx);

	rcx = rax;
	edx = 0x0;
	PQWORD r8 = (PQWORD)targetCoordinates;
	navigateCall_2(rcx, edx, r8);

	rcx = *((PQWORD)(bAObject.��ȡ���˶���() + bAObject.get3520OffsetValue()));
	edx = 0x01;
	QWORD r8_1 = rax;
	DWORD r9 = 0x01;
	BYTE rsp_20 = 0x0;
	rax = navigateCall_3(rcx, edx, r8_1, r9, rsp_20);

	return rax;
}
QWORD Action::selectNpcCall(IN DWORD npcObjectId)
{
	DWORD rcx = npcObjectId;//npc�����id
	Function_SelectNpcCall call = (Function_SelectNpcCall)bAObject.getSelectNpcCall();//ѡ��NpcCall
	//����ѡ��NpcCall
	DWORD rax = call(rcx);
	//����ֵ
	return rax;
}
