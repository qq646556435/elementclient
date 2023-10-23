// elementclient.cpp: 定义 DLL 的初始化例程。
//

#include "pch.h"
#include "framework.h"
#include "elementclient.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为以下项中的第一个语句:
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CelementclientApp

BEGIN_MESSAGE_MAP(CelementclientApp, CWinApp)
END_MESSAGE_MAP()


// CelementclientApp 构造

CelementclientApp::CelementclientApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CelementclientApp 对象

CelementclientApp theApp;

extern HANDLE hThread_initDialogData;
// CelementclientApp 初始化
//显示对话框
MyDialog myDialog;
void DisplayDialog()
{
	//显示对话框
	myDialog.DoModal();
	//关闭 执行函数"初始化通话框数据"的线程句柄
	::TerminateThread(hThread_initDialogData, 0);
	//卸载Dll
	::FreeLibraryAndExitThread(theApp.m_hInstance, 1);
}

BOOL CelementclientApp::InitInstance()
{
	CWinApp::InitInstance();
	//创建一条线程执行显示对话框的函数
	::CreateThread(0, 0,(LPTHREAD_START_ROUTINE)DisplayDialog,0,0,0);

	return TRUE;
}
