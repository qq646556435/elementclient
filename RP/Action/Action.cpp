#include "../../pch.h"
#include "Action.h"

typedef  QWORD(FASTCALL* useItemCall)(QWORD, QWORD, QWORD, QWORD);

Action::Action()
{

}

Action::~Action()
{
}

QWORD Action:: useItem(IN QWORD 本人对象, IN QWORD rdx, IN QWORD 下标, IN QWORD r9, IN QWORD 使用物品call)
{
	useItemCall call = (useItemCall)使用物品call;
	QWORD rax = call(本人对象, rdx, 下标, r9);

	return rax;
}

