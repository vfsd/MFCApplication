
// MFCCBrushDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCCBrush.h"
#include "MFCCBrushDlg.h"
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


// CMFCCBrushDlg 对话框



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


// CMFCCBrushDlg 消息处理程序

BOOL CMFCCBrushDlg::OnInitDialog()
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
	m_bmp.LoadBitmapW(IDB_VFSD);//加载位图
	//m_brush.CreatePatternBrush(&m_bmp);//用位图创建画刷
	//m_brush.CreateSolidBrush(RGB(255,255,255));//创建颜色画刷
	//m_brush.CreateHatchBrush(HS_DIAGCROSS,RGB(28,170,229));
	m_cmb_brush.SetCurSel(2);//默认选中下拉列表中的第二种画刷
	OnCbnSelchangeCmbBrush();//调用画刷

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCCBrushDlg::OnPaint()
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
HCURSOR CMFCCBrushDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CMFCCBrushDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if (m_brush.GetSafeHandle() && nCtlColor==CTLCOLOR_DLG)
	{
		return m_brush;
	}
	return hbr;
}


void CMFCCBrushDlg::OnCbnSelchangeCmbBrush()
{
	// TODO: 在此添加控件通知处理程序代码
	//选择发生改变
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
	Invalidate(TRUE);//失效，察除背景重画
}
