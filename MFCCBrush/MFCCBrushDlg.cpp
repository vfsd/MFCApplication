
// MFCCBrushDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCCBrush.h"
#include "MFCCBrushDlg.h"
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


// CMFCCBrushDlg �Ի���



CMFCCBrushDlg::CMFCCBrushDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCCBRUSH_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCBrushDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_BRUSH, m_cmb_brush);
}

BEGIN_MESSAGE_MAP(CMFCCBrushDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_CMB_BRUSH, &CMFCCBrushDlg::OnCbnSelchangeCmbBrush)
END_MESSAGE_MAP()


// CMFCCBrushDlg ��Ϣ�������

BOOL CMFCCBrushDlg::OnInitDialog()
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
	m_bmp.LoadBitmapW(IDB_VFSD);//����λͼ
	//m_brush.CreatePatternBrush(&m_bmp);//��λͼ������ˢ
	//m_brush.CreateSolidBrush(RGB(255,255,255));//������ɫ��ˢ
	//m_brush.CreateHatchBrush(HS_DIAGCROSS,RGB(28,170,229));
	m_cmb_brush.SetCurSel(2);//Ĭ��ѡ�������б��еĵڶ��ֻ�ˢ
	OnCbnSelchangeCmbBrush();//���û�ˢ

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCCBrushDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCCBrushDlg::OnPaint()
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
HCURSOR CMFCCBrushDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CMFCCBrushDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if (m_brush.GetSafeHandle() && nCtlColor==CTLCOLOR_DLG)
	{
		return m_brush;
	}
	return hbr;
}


void CMFCCBrushDlg::OnCbnSelchangeCmbBrush()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ѡ�����ı�
	if (m_brush.GetSafeHandle())
	{
		m_brush.DeleteObject();
	}
	switch (m_cmb_brush.GetCurSel())
	{
	case 0:
		m_brush.CreateSolidBrush(RGB(220,10,50));
		break;
	case 1:
		m_brush.CreateHatchBrush(HS_DIAGCROSS,RGB(255,0,0));
		break;
	case 2:
		m_brush.CreatePatternBrush(&m_bmp);
		break;
	default:
		m_brush.CreateSolidBrush(RGB(220, 10, 50));
		break; 
	}
	Invalidate(TRUE);//ʧЧ����������ػ�
}
