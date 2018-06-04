
// MFCTimeDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCTimeDemo.h"
#include "MFCTimeDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

VOID CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT_PTR uID, DWORD dwTime)
{
	HWND hGreen = ::GetDlgItem(hWnd,IDC_GREEN);
	int nShow;
	if (::IsWindowVisible(hGreen))
	{
		nShow = SW_HIDE;
	}
	else
	{
		nShow = SW_SHOW;
	}
	::ShowWindow(hGreen,nShow);
}

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCTimeDemoDlg �Ի���



CMFCTimeDemoDlg::CMFCTimeDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCTIMEDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_nRedID = m_nGreenID = 0;
}

void CMFCTimeDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCTimeDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_RED, &CMFCTimeDemoDlg::OnBnClickedButtonRed)
	ON_BN_CLICKED(IDC_BUTTON_GREEN, &CMFCTimeDemoDlg::OnBnClickedButtonGreen)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFCTimeDemoDlg ��Ϣ�������

BOOL CMFCTimeDemoDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCTimeDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCTimeDemoDlg::OnPaint()
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
HCURSOR CMFCTimeDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTimeDemoDlg::OnBnClickedButtonRed()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_nRedID == 0)
	{
		m_nRedID = SetTimer(1,500,NULL);
	}
	else
	{
		KillTimer(m_nRedID);
		m_nRedID = 0;
		//::ShowWindow(::GetDlgItem(m_hWnd,IDC_RED),SW_HIDE);
	}
}


void CMFCTimeDemoDlg::OnBnClickedButtonGreen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_nGreenID == 0)
	{
		m_nGreenID = SetTimer(2,1000,TimerProc);
	}
	else
	{
		KillTimer(m_nGreenID);
		m_nGreenID = 0;
		::ShowWindow(::GetDlgItem(m_hWnd,IDC_GREEN),SW_HIDE);
	}
}


void CMFCTimeDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == m_nRedID)
	{
		HWND hRed = ::GetDlgItem(m_hWnd,IDC_RED);//Windows  API ����
		int nShow;
		if (::IsWindowVisible(hRed))
		{
			nShow = SW_HIDE;
		}
		else
		{
			nShow = SW_SHOW;
		}
		::ShowWindow(hRed,nShow);
	}
	CDialogEx::OnTimer(nIDEvent);
}
