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

};

#endif //__ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
