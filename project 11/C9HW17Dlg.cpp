
// C9HW17Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "C9HW17.h"
#include "C9HW17Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static int red = 0;
static int green = 0;
static int blue = 0;
static int red1 = 0;
static int green1 = 0;
static int blue1 = 0;
static int type = -1;
CRect m_draw = CRect(450, 50, 500, 100);

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CC9HW17Dlg �Ի���



CC9HW17Dlg::CC9HW17Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CC9HW17Dlg::IDD, pParent)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CC9HW17Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_RADIO6, m_rdo6);
	DDX_Control(pDX, IDC_RADIO7, m_rdo7);
	DDX_Control(pDX, IDC_RADIO8, m_rdo8);
	DDX_Control(pDX, IDC_RADIO9, m_rdo9);
	DDX_Control(pDX, IDC_RADIO10, m_rdo10);
	DDX_Control(pDX, IDC_RADIO11, m_rdo11);
	DDX_Control(pDX, IDC_RADIO12, m_rdo12);
	DDX_Control(pDX, IDC_RADIO13, m_rdo13);
}

BEGIN_MESSAGE_MAP(CC9HW17Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CC9HW17Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CC9HW17Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO6, &CC9HW17Dlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CC9HW17Dlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CC9HW17Dlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO9, &CC9HW17Dlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &CC9HW17Dlg::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_RADIO11, &CC9HW17Dlg::OnBnClickedRadio11)
	ON_BN_CLICKED(IDC_RADIO12, &CC9HW17Dlg::OnBnClickedRadio12)
	ON_BN_CLICKED(IDC_RADIO13, &CC9HW17Dlg::OnBnClickedRadio13)
END_MESSAGE_MAP()


// CC9HW17Dlg ��Ϣ�������

BOOL CC9HW17Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_list.AddString(L"Line");
	m_list.AddString(L"Circle");
	m_list.AddString(L"Rectangle");
	m_list.AddString(L"RoundRectangle");
	m_combo1.AddString(L"Blue");
	m_combo1.AddString(L"Green");
	m_combo1.AddString(L"Red");
	m_combo2.AddString(L"Blue");
	m_combo2.AddString(L"Green");
	m_combo2.AddString(L"Red");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CC9HW17Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CC9HW17Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		if (m_rdo6.GetCheck() == 1){
			CPen pen(PS_SOLID, 1, RGB(red1, green1, blue1));
			if (m_rdo10.GetCheck() == 1){
				CBrush br(RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo11.GetCheck() == 1){
				CBrush br(HS_CROSS, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo12.GetCheck() == 1){
				CBrush br(HS_FDIAGONAL, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo13.GetCheck() == 1){
				CBrush br(HS_BDIAGONAL, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
		}
		else if (m_rdo7.GetCheck() == 1){
			CPen pen(PS_DASH, 1, RGB(red1, green1, blue1));
			if (m_rdo10.GetCheck() == 1){
				CBrush br(RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo11.GetCheck() == 1){
				CBrush br(HS_CROSS, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo12.GetCheck() == 1){
				CBrush br(HS_FDIAGONAL, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo13.GetCheck() == 1){
				CBrush br(HS_BDIAGONAL, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
		}
		else if (m_rdo8.GetCheck() == 1){
			CPen pen(PS_DOT, 1, RGB(red1, green1, blue1));
			if (m_rdo10.GetCheck() == 1){
				CBrush br(RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo11.GetCheck() == 1){
				CBrush br(HS_CROSS, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo12.GetCheck() == 1){
				CBrush br(HS_FDIAGONAL, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo13.GetCheck() == 1){
				CBrush br(HS_BDIAGONAL, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
		}
		else if (m_rdo9.GetCheck() == 1){
			CPen pen(PS_DASHDOT, 1, RGB(red1, green1, blue1));
			if (m_rdo10.GetCheck() == 1){
				CBrush br(RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo11.GetCheck() == 1){
				CBrush br(HS_CROSS, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo12.GetCheck() == 1){
				CBrush br(HS_FDIAGONAL, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
			else if (m_rdo13.GetCheck() == 1){
				CBrush br(HS_BDIAGONAL, RGB(red, green, blue));
				if (type == 0){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Ellipse(m_draw);
					CRgn rgn;
					rgn.CreateEllipticRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 1){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.MoveTo(450, 50);
					dc.LineTo(500, 100);
					dc.SelectObject(pOldPen);
				}
				else if (type == 2){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.Rectangle(m_draw);
					CRgn rgn;
					rgn.CreateRectRgnIndirect(m_draw);
					dc.FillRgn(&rgn, &br);
				}
				else if (type == 3){
					CPaintDC dc(this);
					CPen *pOldPen = dc.SelectObject(&pen);
					dc.RoundRect(450, 50, 500, 100, 10, 10);
					CRgn rgn;
					rgn.CreateRoundRectRgn(450, 50, 500, 100, 10, 10);
					dc.FillRgn(&rgn, &br);
				}
			}
		}
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CC9HW17Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CC9HW17Dlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CC9HW17Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	type = m_list.GetCurSel();
	if (m_combo1.GetCurSel() == 0){
		red1 = 0;
		green1 = 0;
		blue1 = 255;
	}
	else if (m_combo1.GetCurSel() == 1){
		red1 = 0;
		green1 = 255;
		blue1 = 0;
	}
	else if (m_combo1.GetCurSel() == 2){
		red1 = 255;
		green1 = 0;
		blue1 = 0;
	}
	if (m_combo2.GetCurSel() == 0){
		red = 0;
		green = 0;
		blue = 255;
	}
	else if (m_combo2.GetCurSel() == 1){
		red = 0;
		green = 255;
		blue = 0;
	}
	else if (m_combo2.GetCurSel() == 2){
		red = 255;
		green = 0;
		blue = 0;
	}
	Invalidate();
}


void CC9HW17Dlg::OnBnClickedRadio6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo6.SetCheck(1);
	m_rdo7.SetCheck(0);
	m_rdo8.SetCheck(0);
	m_rdo9.SetCheck(0);
}


void CC9HW17Dlg::OnBnClickedRadio7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo6.SetCheck(0);
	m_rdo7.SetCheck(1);
	m_rdo8.SetCheck(0);
	m_rdo9.SetCheck(0);
}


void CC9HW17Dlg::OnBnClickedRadio8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo6.SetCheck(0);
	m_rdo7.SetCheck(0);
	m_rdo8.SetCheck(1);
	m_rdo9.SetCheck(0);
}


void CC9HW17Dlg::OnBnClickedRadio9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo6.SetCheck(0);
	m_rdo7.SetCheck(0);
	m_rdo8.SetCheck(0);
	m_rdo9.SetCheck(1);
}


void CC9HW17Dlg::OnBnClickedRadio10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo10.SetCheck(1);
	m_rdo11.SetCheck(0);
	m_rdo12.SetCheck(0);
	m_rdo13.SetCheck(0);
}


void CC9HW17Dlg::OnBnClickedRadio11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo10.SetCheck(0);
	m_rdo11.SetCheck(1);
	m_rdo12.SetCheck(0);
	m_rdo13.SetCheck(0);
}


void CC9HW17Dlg::OnBnClickedRadio12()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo10.SetCheck(0);
	m_rdo11.SetCheck(0);
	m_rdo12.SetCheck(1);
	m_rdo13.SetCheck(0);
}


void CC9HW17Dlg::OnBnClickedRadio13()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo10.SetCheck(0);
	m_rdo11.SetCheck(0);
	m_rdo12.SetCheck(0);
	m_rdo13.SetCheck(1);
}
