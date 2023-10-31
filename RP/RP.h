#ifndef __RP__H_31BD5917_6F7F_4411_A83D_9BF1F215DC98
#define __RP__H_31BD5917_6F7F_4411_A83D_9BF1F215DC98

#include "../pch.h"
#include "../RP/OC/OC.h"
#include "../RP/BackPack/BackPack.h"
#include "../RP/Action/Action.h"
#include "../RP/Warehouse/Warehouse.h"
#include "../RP/Skills/Skills.h"
//本人玩家
class RP:public OC , public BackPack, public Action,public Warehouse,public Skills
{
public:
	RP();
	virtual ~RP() = default;
	void virtual init();
	//自我施法
	QWORD virtual selfCasting(IN QWORD skillId);
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
};

#endif