#include "OC.h"
#include "../../Tools/BaseAddress/BaseAddress.h"

extern BaseAddress bAObject;


OC::OC()
{

}

OC::~OC()
{
}

bool OC::init()
{
	
	this->角色信息.本人名称 = (wchar_t*)(*((QWORD*)(bAObject.获取本人对象() + 0x1218)));
	this->角色信息.id =      *((PDWORD)(bAObject.获取本人对象() + 0x540));
	this->角色信息.当前血量 = *((QWORD*)(bAObject.获取本人对象() + 0x558));
	this->角色信息.最大血量 = *((QWORD*)(bAObject.获取本人对象() + 0x588));
	this->角色信息.当前蓝量 = *((QWORD*)(bAObject.获取本人对象() + 0x560));
	this->角色信息.最大蓝量 = *((QWORD*)(bAObject.获取本人对象() + 0x590));
	this->角色信息.x坐标 = *((float*)(bAObject.获取本人对象() + 0x1370));
	this->角色信息.y坐标 = *((float*)(bAObject.获取本人对象() + 0x1378));

	return true;
}

DataStruct::data_OCInfo OC::获取角色信息()
{


	return this->角色信息;
}
