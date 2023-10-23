#include "../../pch.h"
#include "MemoryCheck.h"
BOOL IsMemoryReadableWritable(LPVOID address)
{
	MEMORY_BASIC_INFORMATION mbi;

	// ��ѯ�ڴ��������Ϣ
	if (VirtualQuery(address, &mbi, sizeof(mbi)) != 0)
	{
		// ����ڴ����������
		if ((mbi.Protect & PAGE_NOACCESS) == 0 &&
			(mbi.Protect & PAGE_READONLY) == 0 &&
			(mbi.Protect & PAGE_EXECUTE) == 0 &&
			(mbi.State & MEM_COMMIT) != 0)
		{
			// �ڴ��ǿɶ���д��
			return TRUE;
		}
	}

	// �ڴ治�ǿɶ���д��
	return FALSE;
}