#include "Warehouse.h"
#include "../../Tools/BaseAddress/BaseAddress.h"
extern BaseAddress bAObject;
void Warehouse::init()
{
	this->backPackOBject = *((QWORD*)(bAObject.获取本人对象() + bAObject.getWarehouseOffsetValue()));
}
