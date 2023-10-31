// MyDialog.cpp: 实现文件
//
#include "pch.h"
#include "elementclient.h"
#include "afxdialogex.h"
#include "MyDialog.h"
#include "Tools/BaseAddress/BaseAddress.h"
#include "RP/RP.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

HANDLE hThread_initDialogData = 0;//执行函数"初始化通话框数据"的线程句柄
//创建全局基址对象
BaseAddress bAObject;
//创建全局本人玩家对象
RP rpObject;

extern MyDialog myDialog;

//初始化通话框数据
void initDialogData()
{   //初始化基址
	bAObject.init();
	CString cstr; //用来将本人玩家的角色属性数据转换为文本
	while (true)
	{
		rpObject.init();
		//获取本人玩家的角色属性信息
		DataStruct::data_OCInfo ocInfo = rpObject.获取角色信息();
	    //延迟200毫秒
		Sleep(200);
		//将本人玩家的角色属性写入到编辑框控件中
		cstr.Format(L"%ws", ocInfo.本人名称);
		myDialog.idc_Edit_Name.SetWindowTextW(cstr.GetString());
		cstr.Format(L"%lld", ocInfo.当前血量);
		myDialog.idc_Edit_HP.SetWindowTextW(cstr.GetString());
		cstr.Format(L"%lld", ocInfo.当前蓝量);
		myDialog.idc_Edit_MP.SetWindowTextW(cstr.GetString());
		cstr.Format(L"x:%.3f y:%.3f", ocInfo.x坐标,ocInfo.y坐标);
		myDialog.idc_Edit_XY.SetWindowTextW(cstr.GetString());
		
	}
}
MyDialog::MyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	/*延迟2秒执行下面代码, 因为创建了一个全局的对话框对象导致
	  这个全局对话框对象的有参构造函数由系统调用会早于系统调用的DLL的初始化函数,
	  所以会导致崩溃。
	*/
	Sleep(2000);
	//创建一条线程执行函数"初始化通话框数据"
	hThread_initDialogData =::CreateThread(0, 0, (LPTHREAD_START_ROUTINE)initDialogData, 0, 0, 0);
}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_Name, idc_Edit_Name);
	DDX_Control(pDX, IDC_EDIT_HP, idc_Edit_HP);
	DDX_Control(pDX, IDC_EDIT_MP, idc_Edit_MP);
	DDX_Control(pDX, IDC_EDIT_ENERGY, idc_Edit_energy);
	DDX_Control(pDX, IDC_EDIT_XY, idc_Edit_XY);
	DDX_Control(pDX, IDC_EDIT_LOGGING, idc_Edit_Logging);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	
	ON_BN_CLICKED(IDC_BUTTON_useItem, &MyDialog::OnBnClickedButtonuseitem)
	ON_BN_CLICKED(IDC_BUTTON_TRAVERSAL, &MyDialog::OnBnClickedButtonTraversal)
	ON_BN_CLICKED(IDC_BUTTON_SHOWBASEADDRESS, &MyDialog::OnBnClickedButtonShowbaseaddress)
	ON_BN_CLICKED(IDC_BUTTON_MEDITATION, &MyDialog::OnBnClickedButtonMeditation)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL_MEDITATION, &MyDialog::OnBnClickedButtonCancelMeditation)
	ON_BN_CLICKED(IDC_BUTTON_ORGANIZE_BACKPACK, &MyDialog::OnBnClickedButtonOrganizeBackpack)
	ON_BN_CLICKED(IDC_BUTTON_REMOTE_ITEM_DESTRUCTION, &MyDialog::OnBnClickedButtonRemoteItemDestruction)
	ON_BN_CLICKED(IDC_BUTTON_BAG_OF_HOLDING, &MyDialog::OnBnClickedButtonBagOfHolding)
	ON_BN_CLICKED(IDC_BUTTON_TRAVERSAL_WAREHOUSE, &MyDialog::OnBnClickedButtonTraversalWarehouse)
	ON_BN_CLICKED(IDC_BUTTON_STORAGE_WAREHOUSE, &MyDialog::OnBnClickedButtonStorageWarehouse)
	ON_BN_CLICKED(IDC_BUTTON_RETRIEVE_FROM_THE_WAREHOUSE, &MyDialog::OnBnClickedButtonRetrieveFromTheWarehouse)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_WAREHOUSE, &MyDialog::OnBnClickedButtonOpenWarehouse)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_WAREHOUSE, &MyDialog::OnBnClickedButtonCloseWarehouse)
	ON_BN_CLICKED(IDC_BUTTON6, &MyDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MyDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MyDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &MyDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &MyDialog::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &MyDialog::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &MyDialog::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &MyDialog::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &MyDialog::OnBnClickedButton11)
END_MESSAGE_MAP()


// MyDialog 消息处理程序




//使用物品Call
void MyDialog::OnBnClickedButtonuseitem()
{

	CString itemName;
	this->idc_Edit_Logging.GetWindowTextW(itemName);
   DataStruct::data_Item item = rpObject.BackPack::getItemData((wchar_t*)itemName.GetString());
	QWORD rax = rpObject.useItem(item.index);
	
	
}

//遍历背包物品
void MyDialog::OnBnClickedButtonTraversal()
{
	CString cstr;
	rpObject.BackPack::init();
	cstr = rpObject.BackPack::TraversalBackPackItemData();
	this->idc_Edit_Logging.SetWindowTextW(cstr.GetString());
	
}

//显示基址数据
void MyDialog::OnBnClickedButtonShowbaseaddress()
{
	CString cstr;
	cstr = bAObject.getBaseAddressData();
	this->idc_Edit_Logging.SetWindowTextW(cstr.GetString());
}

//打坐Call
void MyDialog::OnBnClickedButtonMeditation()
{
	rpObject.meditation();
	
	
}

//取消打坐Call
void MyDialog::OnBnClickedButtonCancelMeditation()
{
	rpObject.cancelMeditation();
	
}

//整理背包Call
void MyDialog::OnBnClickedButtonOrganizeBackpack()
{
	rpObject.organizeBackpack();
	
	
}


void MyDialog::OnBnClickedButtonRemoteItemDestruction()
{
	CString itemName;
	this->idc_Edit_Logging.GetWindowTextW(itemName);
	rpObject.remoteItemDestruction((PTCHAR)itemName.GetString());
	
}


void MyDialog::OnBnClickedButtonBagOfHolding()
{
	CString itemName;
	this->idc_Edit_Logging.GetWindowTextW(itemName);
	
	rpObject.bagOfHolding((PTCHAR)itemName.GetString());
}


void MyDialog::OnBnClickedButtonTraversalWarehouse()
{
	CString itemData;
	itemData = rpObject.Warehouse::TraversalBackPackItemData();
	this->idc_Edit_Logging.SetWindowTextW(itemData.GetString());
}


void MyDialog::OnBnClickedButtonStorageWarehouse()
{
	CString itemName;
	this->idc_Edit_Logging.GetWindowTextW(itemName);
	rpObject.backPackToWarehouse((PTCHAR)itemName.GetString());
}


void MyDialog::OnBnClickedButtonRetrieveFromTheWarehouse()
{
	CString itemName;
	this->idc_Edit_Logging.GetWindowTextW(itemName);
	rpObject.warehouseToBackPack((PTCHAR)itemName.GetString());
}


void MyDialog::OnBnClickedButtonOpenWarehouse()
{
	rpObject.openWarehouseCall();
}


void MyDialog::OnBnClickedButtonCloseWarehouse()
{
	
	rpObject.packetization_CloseWarehouseCall();
}


void MyDialog::OnBnClickedButton6()
{
	rpObject.open仓库老板金玲音对话界面Call();
	
}


void MyDialog::OnBnClickedButton1()
{
	rpObject.Close仓库老板金玲音对话界面Call();
}


void MyDialog::OnBnClickedButton2()
{
	rpObject.blockOutTheEnvironmentCall();
}


void MyDialog::OnBnClickedButton3()
{
	rpObject.packetization_OpenUnityOfHeavenAndHumanity();
}



void MyDialog::OnBnClickedButton4()
{
	rpObject.packetization_CloseUnityOfHeavenAndHumanity();
}


void MyDialog::OnBnClickedButton5()
{
	
	rpObject.resPawn();
}


void MyDialog::OnBnClickedButton7()
{
	
	rpObject.changeServer(5);
	
	
}


void MyDialog::OnBnClickedButton8()
{
	rpObject.getSkillsData(220);
}


void MyDialog::OnBnClickedButton9()
{
	DWORD id = rpObject.getSelectCharacterObjectOfId();
	CString cstr;
	cstr.Format(L"选中的当前角色对象的ID: %ld", id);
	this->idc_Edit_Logging.SetWindowTextW(cstr.GetString());
}


void MyDialog::OnBnClickedButton10()
{
	rpObject.selfCasting(0x932);
}


void MyDialog::OnBnClickedButton11()
{
	QWORD InGameCharacterObject = 0x0034A344;
	rpObject.casting(0x932, &InGameCharacterObject);
}
