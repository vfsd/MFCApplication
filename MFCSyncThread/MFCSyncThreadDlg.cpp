
// MFCSyncThreadDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCSyncThread.h"
#include "MFCSyncThreadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int k = 1;
int total = 0;

CCriticalSection* g_pCS;//临界区对象，在构造函数中创建，在析构函数中销毁
CMutex* g_pMutex;//互斥量对象
CSemaphore* g_pSemaphore;//信号量对象
CEvent* g_pEvent;//事件对象

//临界区对象进行线程同步
UINT ThreadProcessA(LPVOID pParam)
{
	for (int i = 0; i <= 100000; i++)
	{
		//枷锁
		g_pCS->Lock();
		k = k * 2;
		k = k / 2;
		total += k;
		g_pCS->Unlock();//解锁

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//Sleep(200);
	}
	return 0;
}

//临界区对象进行线程同步
UINT ThreadProcessC(LPVOID pParam)
{
	for (int i = 0; i <= 100000; i++)
	{
		g_pCS->Lock();
		k = k * 2;
		k = k / 2;
		total += k;
		//解锁
		g_pCS->Unlock();//

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//使用互斥量对象进行线程同步
UINT ThreadProcessD(LPVOID pParam)
{
	CSingleLock singleLock(g_pMutex);
	for (int i = 0; i <= 10000; i++)
	{
		//枷锁
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//解锁
			singleLock.Unlock();//
		}
		
		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//使用互斥量对象进行线程同步
UINT ThreadProcessE(LPVOID pParam)
{
	CSingleLock singleLock(g_pMutex);
	for (int i = 0; i <= 10000; i++)
	{
		//枷锁
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//解锁
			singleLock.Unlock();
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//使用信号量对象进行线程同步
UINT ThreadProcessF(LPVOID pParam)
{
	CSingleLock singleLock(g_pSemaphore);//信号量锁
	for (int i = 0; i <= 10000; i++)
	{
		//枷锁
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//解锁
			singleLock.Unlock();
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//使用信号量对象进行线程同步
UINT ThreadProcessG(LPVOID pParam)
{
	CSingleLock singleLock(g_pSemaphore);//信号量锁
	for (int i = 0; i <= 10000; i++)
	{
		//枷锁
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//解锁
			singleLock.Unlock();
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//使用事件对象进行线程同步
UINT ThreadProcessM(LPVOID pParam)
{
	CSingleLock singleLock(g_pEvent);//信号量锁
	for (int i = 0; i <= 10; i++)
	{
		//枷锁
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//解锁
			singleLock.Unlock();
			g_pEvent->SetEvent();//发信号给其他线程，告诉读其他线程可以加锁了
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		Sleep(800);
	}
	return 0;
}

//使用事件对象进行线程同步
UINT ThreadProcessN(LPVOID pParam)
{
	CSingleLock singleLock(g_pEvent);//信号量锁
	for (int i = 0; i <= 10; i++)
	{
		//枷锁
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//解锁
			singleLock.Unlock();
			g_pEvent->SetEvent();//发送信号，告诉其他线程可以加锁了
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT2, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		Sleep(800);
	}
	return 0;
}

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCSyncThreadDlg 对话框



CMFCSyncThreadDlg::CMFCSyncThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCSYNCTHREAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//创建临界区对象
	g_pCS = new CCriticalSection();
	//创建互斥量对象
	g_pMutex = new CMutex();//
	//创建信号量对象
	g_pSemaphore = new CSemaphore(1,1);
	//创建事件对象
	g_pEvent = new CEvent(TRUE);
}

CMFCSyncThreadDlg::~CMFCSyncThreadDlg()
{
	delete g_pCS;
	g_pCS = NULL;
	delete g_pMutex;
	g_pMutex = NULL;
	delete g_pSemaphore;
	g_pSemaphore = NULL;
	delete g_pEvent;
	g_pEvent = NULL;
}

void CMFCSyncThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCSyncThreadDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCSyncThreadDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCSyncThreadDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCSyncThreadDlg 消息处理程序

BOOL CMFCSyncThreadDlg::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCSyncThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCSyncThreadDlg::OnPaint()
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
HCURSOR CMFCSyncThreadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCSyncThreadDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//AfxBeginThread(ThreadProcessA, NULL);//临界区
	//AfxBeginThread(ThreadProcessD, NULL);//互斥量
	//AfxBeginThread(ThreadProcessF, NULL);//信号量
	AfxBeginThread(ThreadProcessM, NULL);//事件
}


void CMFCSyncThreadDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//AfxBeginThread(ThreadProcessC, NULL);//临界区
	//AfxBeginThread(ThreadProcessE, NULL);//互斥量
	//AfxBeginThread(ThreadProcessG, NULL);//信号量
	AfxBeginThread(ThreadProcessN, NULL);//事件
}
