#include "RP.h"
#include "../Tools/BaseAddress/BaseAddress.h"

 
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
QWORD RP::selfCasting(IN QWORD skillId)
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
void RP::remoteItemDestruction(IN PTCHAR itemName)
{
    DataStruct::data_Item item = BackPack::getItemData(itemName);
    Function_remoteItemDestructionCall call = (Function_remoteItemDestructionCall)bAObject.getRemoteItemDestructionCall();
	call(item.index,item.id);
}
void RP::packetization_RemoteItemDestruction(IN PTCHAR itemName)
{
	DataStruct::data_Item item = BackPack::getItemData(itemName);
	//组包数据缓冲区
	BYTE packetizationBuffer[10] = { 0x20,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
	*((DWORD*)(&packetizationBuffer[2])) = item.index;
	*((DWORD*)(&packetizationBuffer[6])) = item.id;
	//组包Call
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	Call(rcx, (QWORD)packetizationBuffer, 0x0A);
}
void RP::bagOfHolding(IN PTCHAR itemName)
{
	DataStruct::data_Item item = BackPack::getItemData(itemName);
	function_BagOfHoldingCall Call = (function_BagOfHoldingCall)bAObject.getBagOfHoldingCall();
	Call(item.index);
}
void RP::packetization_BagOfHolding(IN PTCHAR itemName)
{
	DataStruct::data_Item item = BackPack::getItemData(itemName);
	//组包数据缓冲区
	BYTE packetizationBuffer[6] = { 0xDB,0x01,0x00,0x00,0x00,0x00 };
	*((DWORD*)(&packetizationBuffer[2])) = item.index;
	//组包Call
	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());
	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	Call(rcx, (QWORD)packetizationBuffer, 0x06);
}
void RP::backPackToWarehouse(IN PTCHAR itemName)
{
	DataStruct::data_Item item = BackPack::getItemData(itemName);
	function_WarehouseCall Call = (function_WarehouseCall)(bAObject.getWarehouseCall());
	QWORD unknownObject = *((PQWORD)(bAObject.获取未知对象() + 0x40));
	QWORD rdx = 0x0;
	DWORD targetWarehouseIndex = this->Warehouse::retrieveEmptyBackpackIndex();

	Call(unknownObject, rdx, targetWarehouseIndex, item.index);
}
void RP::packetization_BackPackToWarehouse(IN PTCHAR itemName)
{
	DataStruct::data_Item item = BackPack::getItemData(itemName);
	DWORD targetWarehouseIndex = this->Warehouse::retrieveEmptyBackpackIndex();
    Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());

	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	BYTE packetizationBuffer[10] = { 0x3A ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,0x00 ,0x00 ,0x00 };
    *((DWORD*)(&packetizationBuffer[2])) = targetWarehouseIndex;
	*((DWORD*)(&packetizationBuffer[6])) = item.index;
	Call(rcx, (QWORD)packetizationBuffer, 0x0A);
}
void RP::warehouseToBackPack(IN PTCHAR itemName)
{
	DataStruct::data_Item WarehouseItem = this->Warehouse::getItemData(itemName);
	DWORD backPackItemEmptyIndex = this->BackPack::retrieveEmptyBackpackIndex();

	function_WarehouseCall Call = (function_WarehouseCall)(bAObject.getWarehouseCall());
	QWORD unknownObject = *((PQWORD)(bAObject.获取未知对象() + 0x40));
	QWORD rdx = 0x0;
   Call(unknownObject, rdx, WarehouseItem.index, backPackItemEmptyIndex);
}
void RP::packetization_WarehouseToBackPack(IN PTCHAR itemName)
{
	DataStruct::data_Item WarehouseItem = this->Warehouse::getItemData(itemName);
	DWORD backPackItemEmptyIndex = this->BackPack::retrieveEmptyBackpackIndex();

	Function_packetizationCall Call = (Function_packetizationCall)(bAObject.getPacketizationCall());

	QWORD rcx = *((QWORD*)(bAObject.获取未知对象() + 0x40));
	BYTE packetizationBuffer[10] = { 0x3A ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00,0x00 ,0x00 ,0x00 };
	*((DWORD*)(&packetizationBuffer[2])) = WarehouseItem.index;
	*((DWORD*)(&packetizationBuffer[6])) = backPackItemEmptyIndex;
	Call(rcx, (QWORD)packetizationBuffer, 0x0A);
}