#pragma once
#include "afxdialogex.h"

// MyDialog 对话框

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MyDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	CEdit idc_Edit_Name;
	CEdit idc_Edit_HP;
	CEdit idc_Edit_MP;
	CEdit idc_Edit_energy;
	CEdit idc_Edit_XY;
	CEdit idc_Edit_Logging;
	afx_msg void OnBnClickedButtonuseitem();
};
