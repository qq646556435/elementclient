#include "FMC.h"
#include <tlhelp32.h>
FMC::FMC()
{
	this->operator=(0);
}

FMC::FMC(IN QWORD pid, IN std::wstring ģ������)
{
	this->operator=(0);
	��ȡģ���ڴ�����(pid, ģ������);
	this->���̾�� = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
}

FMC::~FMC()
{
	CloseHandle(���̾��);
}



QWORD FMC::��ȡģ���ڴ�����(IN QWORD pid, IN std::wstring ģ������)
{

	//�������̿���
	HANDLE  ���վ�� = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	//������վ����ȡʧ��
	if (���վ�� == INVALID_HANDLE_VALUE)
	{
		return GetLastError();
	}
	//��ȡ��һ��ģ�����Ϣ
	MODULEENTRY32 ģ����Ϣ = { 0 };
	ģ����Ϣ.dwSize = sizeof(MODULEENTRY32);
	bool �Ƿ��ҵ���ģ�� = Module32First(���վ��, &ģ����Ϣ);
	if (!�Ƿ��ҵ���ģ��)
	{
		return GetLastError();
	}
	//����ҵ���ָ����ģ��,��ȡָ��ģ�����Ϣ
	int  i = ģ������.compare(ģ����Ϣ.szModule);
	if (!ģ������.compare(ģ����Ϣ.szModule))
	{
		this->��ʼ��ַ = (QWORD)ģ����Ϣ.modBaseAddr;

		this->������ַ = ((QWORD)ģ����Ϣ.modBaseAddr) + ģ����Ϣ.modBaseSize;




		return true;
	}
	//���û���ҵ�������ȡ��һ��ģ����Ϣ
	�Ƿ��ҵ���ģ�� = Module32Next(���վ��, &ģ����Ϣ);
	if (!�Ƿ��ҵ���ģ��)
	{
		return GetLastError();
	}



	return false;
}
bool FMC::init(IN QWORD pid, IN std::wstring ģ������)
{
	if (!��ȡģ���ڴ�����(pid, ģ������))
	{
		return false;
	}

	this->���̾�� = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (!this->���̾��)
	{
		return false;
	}

	return true;
}
QWORD FMC::�����붨λ��ַ(IN LPBYTE ������, IN size_t �����볤��, IN int ƫ��, IN int ƫ��2, IN int ƫ��3, IN int ƫ��4)
{

	BYTE ������[4096] = { 0 };
	size_t �������е�ƫ���� = 0;
	size_t ���������� = 0;
	QWORD ��ʱ��ʼ��ַ = this->��ʼ��ַ;
	QWORD ��ʱ������ַ = this->������ַ;


	while (��ʱ��ʼ��ַ < ��ʱ������ַ)
	{
		// ���㱾�ζ�ȡ�Ļ��������ȣ����ܳ���4096�ֽ�
		���������� = min(4096 - �����볤��, ��ʱ������ַ - ��ʱ��ʼ��ַ);

		// ��ȡ����������
		BOOL ����ʱ������ = ReadProcessMemory(���̾��, (LPCVOID)��ʱ��ʼ��ַ, ������, ����������, NULL);
		if (����ʱ������ == 0)
		{
			DWORD ������ = GetLastError();
			// �����ȡʧ�ܵ����
		}

		// �ڻ������ڽ���ƥ��������
		for (size_t i = 0; i <= ���������� - �����볤��; ++i)
		{

			// ��ʼƥ��
			if (memcmp(������ + i, ������, �����볤��) == 0)
			{
				�������е�ƫ���� = i;
				QWORD ��ַ = (��ʱ��ʼ��ַ + �������е�ƫ����) + ƫ��;

				int ����λ�ֽ�ƫ���� = 0;
				ReadProcessMemory(���̾��, (LPCVOID)(��ַ + ƫ��2), &����λ�ֽ�ƫ����, ƫ��3, NULL);
				QWORD ��ַ = (��ַ + ����λ�ֽ�ƫ����) + ƫ��4;
				return ��ַ;

			}
		}

		��ʱ��ʼ��ַ += ����������;
	}



	return 0;
}
QWORD FMC::�����붨λƫ��(IN LPBYTE ������, IN size_t �����볤��, IN int ƫ��, IN int ƫ��2, IN int ƫ��3)
{
	BYTE ������[4096] = { 0 };
	size_t �������е�ƫ���� = 0;
	size_t ���������� = 0;
	QWORD ��ʱ��ʼ��ַ = this->��ʼ��ַ;
	QWORD ��ʱ������ַ = this->������ַ;

	while (��ʱ��ʼ��ַ < ��ʱ������ַ)
	{
		// ���㱾�ζ�ȡ�Ļ��������ȣ����ܳ���4096�ֽ�
		���������� = min(4096 - �����볤��, ��ʱ������ַ - ��ʱ��ʼ��ַ);

		// ��ȡ����������
		BOOL ����ʱ������ = ReadProcessMemory(���̾��, (LPCVOID)��ʱ��ʼ��ַ, ������, ����������, NULL);
		if (����ʱ������ == 0)
		{
			DWORD ������ = GetLastError();
			// �����ȡʧ�ܵ����
		}

		// �ڻ������ڽ���ƥ��������
		for (size_t i = 0; i <= ���������� - �����볤��; ++i)
		{
			// ��ʼƥ��
			if (memcmp(������ + i, ������, �����볤��) == 0)
			{
				�������е�ƫ���� = i;
				QWORD ��ַ = (��ʱ��ʼ��ַ + �������е�ƫ����) + ƫ��;
				int ����λ�ֽ�ƫ���� = 0;
				ReadProcessMemory(���̾��, (LPCVOID)(��ַ + ƫ��2), &����λ�ֽ�ƫ����, ƫ��3, NULL);
				QWORD jubƫ�� = ����λ�ֽ�ƫ����;
				return ����λ�ֽ�ƫ����;

			}
		}

		��ʱ��ʼ��ַ += ����������;
	}

	return 0;

}
QWORD FMC::�����붨λcall(IN LPBYTE ������, IN size_t �����볤��, IN int ƫ��)
{
	BYTE ������[4096] = { 0 };
	size_t �������е�ƫ���� = 0;
	size_t ���������� = 0;
	QWORD ��ʱ��ʼ��ַ = this->��ʼ��ַ;
	QWORD ��ʱ������ַ = this->������ַ;

	while (��ʱ��ʼ��ַ < ��ʱ������ַ)
	{
		// ���㱾�ζ�ȡ�Ļ��������ȣ����ܳ���4096�ֽ�
		���������� = min(4096 - �����볤��, ��ʱ������ַ - ��ʱ��ʼ��ַ);

		// ��ȡ����������
		BOOL ����ʱ������ = ReadProcessMemory(���̾��, (LPCVOID)��ʱ��ʼ��ַ, ������, ����������, NULL);
		if (����ʱ������ == 0)
		{
			DWORD ������ = GetLastError();
			// �����ȡʧ�ܵ����
		}

		// �ڻ������ڽ���ƥ��������
		for (size_t i = 0; i <= ���������� - �����볤��; ++i)
		{
			// ��ʼƥ��
			if (memcmp(������ + i, ������, �����볤��) == 0)
			{
				�������е�ƫ���� = i;
				QWORD ��ַ = (��ʱ��ʼ��ַ + �������е�ƫ����) + ƫ��;

				return ��ַ;

			}
		}

		��ʱ��ʼ��ַ += ����������;
	}

	return 0;
}
FMC& FMC::operator=(IN UINT  ��ֵ)
{
	this->���̾�� = (HANDLE)��ֵ;
	this->��ʼ��ַ = ��ֵ;
	this->������ַ = ��ֵ;

	return *this;

}
