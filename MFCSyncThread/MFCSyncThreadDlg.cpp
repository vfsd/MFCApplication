
// MFCSyncThreadDlg.cpp : ʵ���ļ�
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

CCriticalSection* g_pCS;//�ٽ��������ڹ��캯���д���������������������
CMutex* g_pMutex;//����������
CSemaphore* g_pSemaphore;//�ź�������
CEvent* g_pEvent;//�¼�����

//�ٽ�����������߳�ͬ��
UINT ThreadProcessA(LPVOID pParam)
{
	for (int i = 0; i <= 100000; i++)
	{
		//����
		g_pCS->Lock();
		k = k * 2;
		k = k / 2;
		total += k;
		g_pCS->Unlock();//����

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//Sleep(200);
	}
	return 0;
}

//�ٽ�����������߳�ͬ��
UINT ThreadProcessC(LPVOID pParam)
{
	for (int i = 0; i <= 100000; i++)
	{
		g_pCS->Lock();
		k = k * 2;
		k = k / 2;
		total += k;
		//����
		g_pCS->Unlock();//

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//ʹ�û�������������߳�ͬ��
UINT ThreadProcessD(LPVOID pParam)
{
	CSingleLock singleLock(g_pMutex);
	for (int i = 0; i <= 10000; i++)
	{
		//����
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//����
			singleLock.Unlock();//
		}
		
		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//ʹ�û�������������߳�ͬ��
UINT ThreadProcessE(LPVOID pParam)
{
	CSingleLock singleLock(g_pMutex);
	for (int i = 0; i <= 10000; i++)
	{
		//����
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//����
			singleLock.Unlock();
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//ʹ���ź�����������߳�ͬ��
UINT ThreadProcessF(LPVOID pParam)
{
	CSingleLock singleLock(g_pSemaphore);//�ź�����
	for (int i = 0; i <= 10000; i++)
	{
		//����
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//����
			singleLock.Unlock();
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//ʹ���ź�����������߳�ͬ��
UINT ThreadProcessG(LPVOID pParam)
{
	CSingleLock singleLock(g_pSemaphore);//�ź�����
	for (int i = 0; i <= 10000; i++)
	{
		//����
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//����
			singleLock.Unlock();
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		//Sleep(800);
	}
	return 0;
}

//ʹ���¼���������߳�ͬ��
UINT ThreadProcessM(LPVOID pParam)
{
	CSingleLock singleLock(g_pEvent);//�ź�����
	for (int i = 0; i <= 10; i++)
	{
		//����
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//����
			singleLock.Unlock();
			g_pEvent->SetEvent();//���źŸ������̣߳����߶������߳̿��Լ�����
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		Sleep(800);
	}
	return 0;
}

//ʹ���¼���������߳�ͬ��
UINT ThreadProcessN(LPVOID pParam)
{
	CSingleLock singleLock(g_pEvent);//�ź�����
	for (int i = 0; i <= 10; i++)
	{
		//����
		singleLock.Lock();
		if (singleLock.IsLocked())
		{
			k = k * 2;
			k = k / 2;
			total += k;
			//����
			singleLock.Unlock();
			g_pEvent->SetEvent();//�����źţ����������߳̿��Լ�����
		}

		::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT2, total, false);
		//::SetDlgItemInt(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_STATIC_INPUT, i, false);
		Sleep(800);
	}
	return 0;
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


// CMFCSyncThreadDlg �Ի���



CMFCSyncThreadDlg::CMFCSyncThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCSYNCTHREAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//�����ٽ�������
	g_pCS = new CCriticalSection();
	//��������������
	g_pMutex = new CMutex();//
	//�����ź�������
	g_pSemaphore = new CSemaphore(1,1);
	//�����¼�����
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


// CMFCSyncThreadDlg ��Ϣ�������

BOOL CMFCSyncThreadDlg::OnInitDialog()
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCSyncThreadDlg::OnPaint()
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
HCURSOR CMFCSyncThreadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCSyncThreadDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxBeginThread(ThreadProcessA, NULL);//�ٽ���
	//AfxBeginThread(ThreadProcessD, NULL);//������
	//AfxBeginThread(ThreadProcessF, NULL);//�ź���
	AfxBeginThread(ThreadProcessM, NULL);//�¼�
}


void CMFCSyncThreadDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxBeginThread(ThreadProcessC, NULL);//�ٽ���
	//AfxBeginThread(ThreadProcessE, NULL);//������
	//AfxBeginThread(ThreadProcessG, NULL);//�ź���
	AfxBeginThread(ThreadProcessN, NULL);//�¼�
}
