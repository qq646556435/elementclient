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
	
	this->��ɫ��Ϣ.�������� = (wchar_t*)(*((QWORD*)(bAObject.��ȡ���˶���() + 0x1218)));
	this->��ɫ��Ϣ.id =      *((PDWORD)(bAObject.��ȡ���˶���() + 0x540));
	this->��ɫ��Ϣ.��ǰѪ�� = *((QWORD*)(bAObject.��ȡ���˶���() + 0x558));
	this->��ɫ��Ϣ.���Ѫ�� = *((QWORD*)(bAObject.��ȡ���˶���() + 0x588));
	this->��ɫ��Ϣ.��ǰ���� = *((QWORD*)(bAObject.��ȡ���˶���() + 0x560));
	this->��ɫ��Ϣ.������� = *((QWORD*)(bAObject.��ȡ���˶���() + 0x590));
	this->��ɫ��Ϣ.x���� = *((float*)(bAObject.��ȡ���˶���() + 0x1370));
	this->��ɫ��Ϣ.y���� = *((float*)(bAObject.��ȡ���˶���() + 0x1378));

	return true;
}

DataStruct::data_OCInfo OC::��ȡ��ɫ��Ϣ()
{


	return this->��ɫ��Ϣ;
}
