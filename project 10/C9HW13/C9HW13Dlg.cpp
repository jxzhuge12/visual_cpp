
// C9HW13Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "C9HW13.h"
#include "C9HW13Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static int red = 0;
static int green = 0;
static int blue = 0;
CRect m_Ellipses = CRect(300, 30, 500, 100);
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


// CC9HW13Dlg 对话框



CC9HW13Dlg::CC9HW13Dlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CC9HW13Dlg::IDD, pParent)
	//, red(0)
	//, green(0)
	//, blue(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CC9HW13Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_sb1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_sb2);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_sb3);
	//  DDX_Scroll(pDX, IDC_SCROLLBAR1, red);
	//  DDV_MinMaxInt(pDX, red, 0, 255);
	//  DDX_Scroll(pDX, IDC_SCROLLBAR2, green);
	//  DDV_MinMaxInt(pDX, green, 0, 255);
	//  DDX_Scroll(pDX, IDC_SCROLLBAR3, blue);
	//  DDV_MinMaxInt(pDX, blue, 0, 255);
}

BEGIN_MESSAGE_MAP(CC9HW13Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CC9HW13Dlg 消息处理程序

BOOL CC9HW13Dlg::OnInitDialog()
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
	m_sb1.SetScrollRange(0, 255);
	m_sb2.SetScrollRange(0, 255);
	m_sb3.SetScrollRange(0, 255);
	m_sb1.SetScrollPos(0);
	m_sb2.SetScrollPos(0);
	m_sb3.SetScrollPos(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CC9HW13Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CC9HW13Dlg::OnPaint()
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
		CPaintDC dc(this);
		CBrush br(RGB(red, green, blue));
		dc.SelectStockObject(NULL_BRUSH);
		dc.Ellipse(m_Ellipses);
		CRgn rgn;
		rgn.CreateEllipticRgnIndirect(m_Ellipses);
		dc.FillRgn(&rgn, &br);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CC9HW13Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CC9HW13Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	int iNowPos;
	switch (nSBCode){
	case SB_THUMBTRACK:
		if (pScrollBar == &m_sb1){
			m_sb1.SetScrollPos(nPos);
			red = m_sb1.GetScrollPos();
		}
		else if (pScrollBar == &m_sb2){
			m_sb2.SetScrollPos(nPos);
			green = m_sb2.GetScrollPos();
		}
		else if (pScrollBar == &m_sb3){
			m_sb3.SetScrollPos(nPos);
			blue = m_sb3.GetScrollPos();
		}
		Invalidate();
		break;
	case SB_LINERIGHT:
		if (pScrollBar == &m_sb1){
			iNowPos = m_sb1.GetScrollPos();
			iNowPos++;
			if (iNowPos > 255)
				iNowPos = 255;
			m_sb1.SetScrollPos(iNowPos);
			red = iNowPos;
		}
		else if (pScrollBar == &m_sb2){
			iNowPos = m_sb2.GetScrollPos();
			iNowPos++;
			if (iNowPos > 255)
				iNowPos = 255;
			m_sb2.SetScrollPos(iNowPos);
			green = iNowPos;
		}
		else if (pScrollBar == &m_sb3){
			iNowPos = m_sb3.GetScrollPos();
			iNowPos++;
			if (iNowPos > 255)
				iNowPos = 255;
			m_sb3.SetScrollPos(iNowPos);
			blue = iNowPos;
		}
		Invalidate();
		break;
	case SB_LINELEFT:
		if (pScrollBar == &m_sb1){
			iNowPos = m_sb1.GetScrollPos();
			iNowPos--;
			if (iNowPos < 0)
				iNowPos = 0;
			m_sb1.SetScrollPos(iNowPos);
			red = iNowPos;
		}
		else if (pScrollBar == &m_sb2){
			iNowPos = m_sb2.GetScrollPos();
			iNowPos--;
			if (iNowPos < 0)
				iNowPos = 0;
			m_sb2.SetScrollPos(iNowPos);
			green = iNowPos;
		}
		else if (pScrollBar == &m_sb3){
			iNowPos = m_sb3.GetScrollPos();
			iNowPos--;
			if (iNowPos < 0)
				iNowPos = 0;
			m_sb3.SetScrollPos(iNowPos);
			blue = iNowPos;
		}
		Invalidate();
		break;
	case SB_PAGERIGHT:
		if (pScrollBar == &m_sb1){
			iNowPos = m_sb1.GetScrollPos();
			iNowPos = iNowPos + 3;
			if (iNowPos > 255)
				iNowPos = 255;
			m_sb1.SetScrollPos(iNowPos);
			red = iNowPos;
		}
		else if (pScrollBar == &m_sb2){
			iNowPos = m_sb2.GetScrollPos();
			iNowPos = iNowPos + 3;
			if (iNowPos > 255)
				iNowPos = 255;
			m_sb2.SetScrollPos(iNowPos);
			green = iNowPos;
		}
		else if (pScrollBar == &m_sb3){
			iNowPos = m_sb3.GetScrollPos();
			iNowPos = iNowPos + 3;
			if (iNowPos > 255)
				iNowPos = 255;
			m_sb3.SetScrollPos(iNowPos);
			blue = iNowPos;
		}
		Invalidate();
		break;
	case SB_PAGELEFT:
		if (pScrollBar == &m_sb1){
			iNowPos = m_sb1.GetScrollPos();
			iNowPos = iNowPos - 3;
			if (iNowPos < 0)
				iNowPos = 0;
			m_sb1.SetScrollPos(iNowPos);
			red = iNowPos;
		}
		else if (pScrollBar == &m_sb2){
			iNowPos = m_sb2.GetScrollPos();
			iNowPos = iNowPos - 3;
			if (iNowPos < 0)
				iNowPos = 0;
			m_sb2.SetScrollPos(iNowPos);
			green = iNowPos;
		}
		else if (pScrollBar == &m_sb3){
			iNowPos = m_sb3.GetScrollPos();
			iNowPos = iNowPos - 3;
			if (iNowPos < 0)
				iNowPos = 0;
			m_sb3.SetScrollPos(iNowPos);
			blue = iNowPos;
		}
		Invalidate();
		break;
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
