#include "Warehouse.h"
#include "../../Tools/BaseAddress/BaseAddress.h"
extern BaseAddress bAObject;
void Warehouse::init()
{
	this->backPackOBject = *((QWORD*)(bAObject.��ȡ���˶���() + bAObject.getWarehouseOffsetValue()));
}
