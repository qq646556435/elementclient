#include "../../pch.h"
#include "MemoryCheck.h"
BOOL IsMemoryReadableWritable(LPVOID address)
{
	MEMORY_BASIC_INFORMATION mbi;

	// 查询内存区域的信息
	if (VirtualQuery(address, &mbi, sizeof(mbi)) != 0)
	{
		// 检查内存区域的属性
		if ((mbi.Protect & PAGE_NOACCESS) == 0 &&
			(mbi.Protect & PAGE_READONLY) == 0 &&
			(mbi.Protect & PAGE_EXECUTE) == 0 &&
			(mbi.State & MEM_COMMIT) != 0)
		{
			// 内存是可读可写的
			return TRUE;
		}
	}

	// 内存不是可读可写的
	return FALSE;
}