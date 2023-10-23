#ifndef __FMC__H_7D44A502_85A6_43E4_B551_503AF56766E8
#define __FMC__H_7D44A502_85A6_43E4_B551_503AF56766E8
#pragma once
#include "../../pch.h"
#include <iostream>

class FMC
{
private:
	HANDLE 进程句柄;
	QWORD 起始地址;
	QWORD 结束地址;
private:
	QWORD 获取模块内存区域(IN QWORD pid, IN std::wstring 模块名称);

public:
	FMC();
	FMC(IN QWORD pid, IN std::wstring 模块名称);
	virtual ~FMC();
	bool virtual init(IN QWORD pid, IN std::wstring 模块名称);
	QWORD virtual 特征码定位基址(IN LPBYTE 特征码, IN size_t 特征码长度, IN int 偏移, IN int 偏移2, IN int 偏移3, IN int 偏移4);
	QWORD virtual 特征码定位偏移(IN LPBYTE 特征码, IN size_t 特征码长度, IN int 偏移, IN int 偏移2, IN int 偏移3);
	QWORD virtual 特征码定位call(IN LPBYTE 特征码, IN size_t 特征码长度, IN int 偏移);
	FMC& operator=(IN UINT  数值);
};



#endif // __FMC__H_7D44A502_85A6_43E4_B551_503AF56766E8



