#ifndef __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#define __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#pragma once
class Action
{
public:
	Action();
	virtual ~Action();
	//使用指定物品
	QWORD virtual useItem(IN QWORD 本人对象, IN QWORD rdx, IN QWORD 下标, IN QWORD r9);
	//打坐
	QWORD virtual meditation();
	//取消打坐
	QWORD virtual cancelMeditation();
	//整理背包
	QWORD virtual organizeBackpack(IN QWORD rcx);
	//远程销毁物品
	void virtual remoteItemDestruction(IN QWORD itemIndex, IN QWORD itemId);
	//组包销毁物品
	void virtual packetization_RemoteItemDestruction(IN DWORD itemIndex, IN DWORD itemId);
	//乾坤袋
	void virtual bagOfHolding(IN DWORD itemIndex);
	//组包乾坤袋
	void virtual packetization_BagOfHolding(IN DWORD itemIndex);
	//背包物品到仓库 
	void virtual backPackToWarehouse(IN QWORD unknownObject, IN QWORD rdx , IN QWORD targetWarehouseIndex, IN QWORD soureBackPackIndex);
	//组包背包物品到仓库
	void virtual packetization_BackPackToWarehouse(IN DWORD targetWarehouseIndex, IN DWORD soureBackPackIndex);
	//仓库物品到背包
	void virtual warehouseToBackPack(IN QWORD unknownObject, IN QWORD rdx , IN QWORD soureWarehouseIndex, IN QWORD targetBackPackIndex);
	//组包仓库物品到背包
	void virtual packetization_WarehouseToBackPack(IN DWORD soureWarehouseIndex, IN DWORD targetBackPackIndex);
	//打开仓库Call
	void virtual openWarehouseCall(IN QWORD unknownGlobalVariable,IN QWORD rdx);
	//组包打开仓库Call
	void virtual packetization_OpenWarehouseCall();
	//关闭仓库Call
	QWORD virtual closeWarehouseCall(IN QWORD unknownObject);
	//组包关闭仓库Call
	void virtual packetization_CloseWarehouseCall();
	//打开仓库老板金玲音对话界面的Call
	QWORD virtual open仓库老板金玲音对话界面Call(IN QWORD unknownObjectOne, IN QWORD unknownObjectTwo);
    //关闭仓库老板金玲音对话界面的Call
	void virtual Close仓库老板金玲音对话界面Call();
};

#endif //__ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
