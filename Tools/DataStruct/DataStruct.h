#ifndef __DATASTRUCT__H_106A8FA3_F78F_4257_AC81_69AF2F5A6F9A
#define __DATASTRUCT__H_106A8FA3_F78F_4257_AC81_69AF2F5A6F9A
#pragma once
#include "../../pch.h"
namespace DataStruct
{
	//��Ʒ���ݽṹ
	struct data_Item
	{
		/*
		[��Ʒ����+90]+C ��Ʒ����
		[��Ʒ����+88]+4 ��Ʒ����
		[��Ʒ����+80]+4 ��Ʒ����
		[��Ʒ����+2b0]+4 ��Ʒ����\��Ʒ����
		[��Ʒ����+c]   ��Ʒid Dword
		[��Ʒ����+18] ��ǰ��Ʒ����ֵ Dword
		[��Ʒ����+1c] ��ǰ��Ʒ�������ֵ Dword

		*/

		wchar_t Name[40];//��һ������
		wchar_t Name1[40];//�ڶ�������
		wchar_t Name2[40];//����������
		wchar_t Name3[40];//���ĸ�����
		wchar_t typeName[40];//��Ʒ����
		DWORD id;//��Ʒid
		DWORD cic;//��ǰ��Ʒ����
		DWORD cmic;//��ǰ��Ʒ�������
		UINT index;//��ǰ��Ʒ���±�

	};
	//������ҵĽ�ɫ������Ϣ
	struct data_OCInfo
	{
		wchar_t* ��������;
		QWORD ��ǰѪ��;
		QWORD ���Ѫ��;
		QWORD ��ǰ����;
		QWORD �������;
		float x����;
		float y����;
	};

}

#endif





