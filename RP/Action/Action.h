#ifndef __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#define __ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
#pragma once
class Action
{
public:
	Action();
	virtual ~Action();
	QWORD virtual useItem(IN QWORD 本人对象, IN QWORD rdx, IN QWORD 下标, IN QWORD r9, IN QWORD 使用物品call);


};

#endif //__ACTION__H_7205A58E_B2CE_4438_8B38_55016F7E473B
