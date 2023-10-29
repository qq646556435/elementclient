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
	afx_msg void OnBnClickedButtonTraversal();
	afx_msg void OnBnClickedButtonShowbaseaddress();
	afx_msg void OnBnClickedButtonMeditation();
	afx_msg void OnBnClickedButtonCancelMeditation();
	afx_msg void OnBnClickedButtonOrganizeBackpack();
	afx_msg void OnBnClickedButtonRemoteItemDestruction();
	afx_msg void OnBnClickedButtonBagOfHolding();
	afx_msg void OnBnClickedButtonTraversalWarehouse();
	afx_msg void OnBnClickedButtonStorageWarehouse();
	afx_msg void OnBnClickedButtonRetrieveFromTheWarehouse();
	afx_msg void OnBnClickedButtonOpenWarehouse();
	afx_msg void OnBnClickedButtonCloseWarehouse();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
};
