#include "../../pch.h"
#include "Action.h"

typedef  QWORD(FASTCALL* useItemCall)(QWORD, QWORD, QWORD, QWORD);

Action::Action()
{

}

Action::~Action()
{
}

QWORD Action:: useItem(IN QWORD ���˶���, IN QWORD rdx, IN QWORD �±�, IN QWORD r9, IN QWORD ʹ����Ʒcall)
{
	useItemCall call = (useItemCall)ʹ����Ʒcall;
	QWORD rax = call(���˶���, rdx, �±�, r9);

	return rax;
}

