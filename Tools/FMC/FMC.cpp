#include "FMC.h"
#include <tlhelp32.h>
FMC::FMC()
{
	this->operator=(0);
}

FMC::FMC(IN QWORD pid, IN std::wstring 模块名称)
{
	this->operator=(0);
	获取模块内存区域(pid, 模块名称);
	this->进程句柄 = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
}

FMC::~FMC()
{
	CloseHandle(进程句柄);
}



QWORD FMC::获取模块内存区域(IN QWORD pid, IN std::wstring 模块名称)
{

	//创建进程快照
	HANDLE  快照句柄 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	//如果快照句柄获取失败
	if (快照句柄 == INVALID_HANDLE_VALUE)
	{
		return GetLastError();
	}
	//获取第一个模块的信息
	MODULEENTRY32 模块信息 = { 0 };
	模块信息.dwSize = sizeof(MODULEENTRY32);
	bool 是否找到了模块 = Module32First(快照句柄, &模块信息);
	if (!是否找到了模块)
	{
		return GetLastError();
	}
	//如果找到了指定的模块,获取指定模块的信息
	int  i = 模块名称.compare(模块信息.szModule);
	if (!模块名称.compare(模块信息.szModule))
	{
		this->起始地址 = (QWORD)模块信息.modBaseAddr;

		this->结束地址 = ((QWORD)模块信息.modBaseAddr) + 模块信息.modBaseSize;




		return true;
	}
	//如果没有找到继续获取下一个模块信息
	是否找到了模块 = Module32Next(快照句柄, &模块信息);
	if (!是否找到了模块)
	{
		return GetLastError();
	}



	return false;
}
bool FMC::init(IN QWORD pid, IN std::wstring 模块名称)
{
	if (!获取模块内存区域(pid, 模块名称))
	{
		return false;
	}

	this->进程句柄 = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (!this->进程句柄)
	{
		return false;
	}

	return true;
}
QWORD FMC::特征码定位基址(IN LPBYTE 特征码, IN size_t 特征码长度, IN int 偏移, IN int 偏移2, IN int 偏移3, IN int 偏移4)
{

	BYTE 缓冲区[4096] = { 0 };
	size_t 缓冲区中的偏移量 = 0;
	size_t 缓冲区长度 = 0;
	QWORD 临时起始地址 = this->起始地址;
	QWORD 临时结束地址 = this->结束地址;


	while (临时起始地址 < 临时结束地址)
	{
		// 计算本次读取的缓冲区长度，不能超过4096字节
		缓冲区长度 = min(4096 - 特征码长度, 临时结束地址 - 临时起始地址);

		// 读取缓冲区数据
		BOOL 读临时缓冲区 = ReadProcessMemory(进程句柄, (LPCVOID)临时起始地址, 缓冲区, 缓冲区长度, NULL);
		if (读临时缓冲区 == 0)
		{
			DWORD 错误码 = GetLastError();
			// 处理读取失败的情况
		}

		// 在缓冲区内进行匹配特征码
		for (size_t i = 0; i <= 缓冲区长度 - 特征码长度; ++i)
		{

			// 开始匹配
			if (memcmp(缓冲区 + i, 特征码, 特征码长度) == 0)
			{
				缓冲区中的偏移量 = i;
				QWORD 地址 = (临时起始地址 + 缓冲区中的偏移量) + 偏移;

				int 后四位字节偏移量 = 0;
				ReadProcessMemory(进程句柄, (LPCVOID)(地址 + 偏移2), &后四位字节偏移量, 偏移3, NULL);
				QWORD 基址 = (地址 + 后四位字节偏移量) + 偏移4;
				return 基址;

			}
		}

		临时起始地址 += 缓冲区长度;
	}



	return 0;
}
QWORD FMC::特征码定位偏移(IN LPBYTE 特征码, IN size_t 特征码长度, IN int 偏移, IN int 偏移2, IN int 偏移3)
{
	BYTE 缓冲区[4096] = { 0 };
	size_t 缓冲区中的偏移量 = 0;
	size_t 缓冲区长度 = 0;
	QWORD 临时起始地址 = this->起始地址;
	QWORD 临时结束地址 = this->结束地址;

	while (临时起始地址 < 临时结束地址)
	{
		// 计算本次读取的缓冲区长度，不能超过4096字节
		缓冲区长度 = min(4096 - 特征码长度, 临时结束地址 - 临时起始地址);

		// 读取缓冲区数据
		BOOL 读临时缓冲区 = ReadProcessMemory(进程句柄, (LPCVOID)临时起始地址, 缓冲区, 缓冲区长度, NULL);
		if (读临时缓冲区 == 0)
		{
			DWORD 错误码 = GetLastError();
			// 处理读取失败的情况
		}

		// 在缓冲区内进行匹配特征码
		for (size_t i = 0; i <= 缓冲区长度 - 特征码长度; ++i)
		{
			// 开始匹配
			if (memcmp(缓冲区 + i, 特征码, 特征码长度) == 0)
			{
				缓冲区中的偏移量 = i;
				QWORD 地址 = (临时起始地址 + 缓冲区中的偏移量) + 偏移;
				int 后四位字节偏移量 = 0;
				ReadProcessMemory(进程句柄, (LPCVOID)(地址 + 偏移2), &后四位字节偏移量, 偏移3, NULL);
				QWORD jub偏移 = 后四位字节偏移量;
				return 后四位字节偏移量;

			}
		}

		临时起始地址 += 缓冲区长度;
	}

	return 0;

}
QWORD FMC::特征码定位call(IN LPBYTE 特征码, IN size_t 特征码长度, IN int 偏移)
{
	BYTE 缓冲区[4096] = { 0 };
	size_t 缓冲区中的偏移量 = 0;
	size_t 缓冲区长度 = 0;
	QWORD 临时起始地址 = this->起始地址;
	QWORD 临时结束地址 = this->结束地址;

	while (临时起始地址 < 临时结束地址)
	{
		// 计算本次读取的缓冲区长度，不能超过4096字节
		缓冲区长度 = min(4096 - 特征码长度, 临时结束地址 - 临时起始地址);

		// 读取缓冲区数据
		BOOL 读临时缓冲区 = ReadProcessMemory(进程句柄, (LPCVOID)临时起始地址, 缓冲区, 缓冲区长度, NULL);
		if (读临时缓冲区 == 0)
		{
			DWORD 错误码 = GetLastError();
			// 处理读取失败的情况
		}

		// 在缓冲区内进行匹配特征码
		for (size_t i = 0; i <= 缓冲区长度 - 特征码长度; ++i)
		{
			// 开始匹配
			if (memcmp(缓冲区 + i, 特征码, 特征码长度) == 0)
			{
				缓冲区中的偏移量 = i;
				QWORD 地址 = (临时起始地址 + 缓冲区中的偏移量) + 偏移;

				return 地址;

			}
		}

		临时起始地址 += 缓冲区长度;
	}

	return 0;
}
FMC& FMC::operator=(IN UINT  数值)
{
	this->进程句柄 = (HANDLE)数值;
	this->起始地址 = 数值;
	this->结束地址 = 数值;

	return *this;

}
