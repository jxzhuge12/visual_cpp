
// C9HW12Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "C9HW12.h"
#include "C9HW12Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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


// CC9HW12Dlg �Ի���



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


// CC9HW12Dlg ��Ϣ�������

BOOL CC9HW12Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CC9HW12Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CC9HW12Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CC9HW12Dlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CC9HW12Dlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	score = (m_chk1.GetCheck() * 10 + m_chk2.GetCheck() * 9 + m_chk3.GetCheck() * 8 + m_chk4.GetCheck() * 7)*(m_rdo1.GetCheck() * 100 + m_rdo2.GetCheck() * 90 + m_rdo3.GetCheck() * 80 + m_rdo4.GetCheck() * 70);
	UpdateData(FALSE);
}


void CC9HW12Dlg::OnBnClickedRadio1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo1.SetCheck(1);
	m_rdo2.SetCheck(0);
	m_rdo3.SetCheck(0);
	m_rdo4.SetCheck(0);
}


void CC9HW12Dlg::OnBnClickedRadio2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo1.SetCheck(0);
	m_rdo2.SetCheck(1);
	m_rdo3.SetCheck(0);
	m_rdo4.SetCheck(0);
}


void CC9HW12Dlg::OnBnClickedRadio3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo1.SetCheck(0);
	m_rdo2.SetCheck(0);
	m_rdo3.SetCheck(1);
	m_rdo4.SetCheck(0);
}


void CC9HW12Dlg::OnBnClickedRadio4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_rdo1.SetCheck(0);
	m_rdo2.SetCheck(0);
	m_rdo3.SetCheck(0);
	m_rdo4.SetCheck(1);
}
