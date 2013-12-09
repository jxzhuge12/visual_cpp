
// C9HW12Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "C9HW12.h"
#include "C9HW12Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CC9HW12Dlg 对话框



CC9HW12Dlg::CC9HW12Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CC9HW12Dlg::IDD, pParent)
	, score(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CC9HW12Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_chk1);
	DDX_Control(pDX, IDC_CHECK2, m_chk2);
	DDX_Control(pDX, IDC_CHECK3, m_chk3);
	DDX_Control(pDX, IDC_CHECK4, m_chk4);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_RADIO1, m_rdo1);
	DDX_Control(pDX, IDC_RADIO2, m_rdo2);
	DDX_Control(pDX, IDC_RADIO3, m_rdo3);
	DDX_Control(pDX, IDC_RADIO4, m_rdo4);
	DDX_Text(pDX, IDC_EDIT1, score);
}

BEGIN_MESSAGE_MAP(CC9HW12Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CC9HW12Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CC9HW12Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &CC9HW12Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CC9HW12Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CC9HW12Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CC9HW12Dlg::OnBnClickedRadio4)
END_MESSAGE_MAP()


// CC9HW12Dlg 消息处理程序

BOOL CC9HW12Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CC9HW12Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CC9HW12Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CC9HW12Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CC9HW12Dlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CC9HW12Dlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	// TODO:  在此添加控件通知处理程序代码
	score = (m_chk1.GetCheck() * 10 + m_chk2.GetCheck() * 9 + m_chk3.GetCheck() * 8 + m_chk4.GetCheck() * 7)*(m_rdo1.GetCheck() * 100 + m_rdo2.GetCheck() * 90 + m_rdo3.GetCheck() * 80 + m_rdo4.GetCheck() * 70);
	UpdateData(FALSE);
}


void CC9HW12Dlg::OnBnClickedRadio1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_rdo1.SetCheck(1);
	m_rdo2.SetCheck(0);
	m_rdo3.SetCheck(0);
	m_rdo4.SetCheck(0);
}


void CC9HW12Dlg::OnBnClickedRadio2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_rdo1.SetCheck(0);
	m_rdo2.SetCheck(1);
	m_rdo3.SetCheck(0);
	m_rdo4.SetCheck(0);
}


void CC9HW12Dlg::OnBnClickedRadio3()
{
	// TODO:  在此添加控件通知处理程序代码
	m_rdo1.SetCheck(0);
	m_rdo2.SetCheck(0);
	m_rdo3.SetCheck(1);
	m_rdo4.SetCheck(0);
}


void CC9HW12Dlg::OnBnClickedRadio4()
{
	// TODO:  在此添加控件通知处理程序代码
	m_rdo1.SetCheck(0);
	m_rdo2.SetCheck(0);
	m_rdo3.SetCheck(0);
	m_rdo4.SetCheck(1);
}
