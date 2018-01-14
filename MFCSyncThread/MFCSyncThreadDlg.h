
// MFCSyncThreadDlg.h : 头文件
//

#pragma once

UINT ThreadProcessA(LPVOID pParam);
UINT ThreadProcessB(LPVOID pParam);
UINT ThreadProcessC(LPVOID pParam);
UINT ThreadProcessD(LPVOID pParam);
UINT ThreadProcessE(LPVOID pParam);
UINT ThreadProcessF(LPVOID pParam);
UINT ThreadProcessG(LPVOID pParam);
UINT ThreadProcessM(LPVOID pParam);
UINT ThreadProcessN(LPVOID pParam);

// CMFCSyncThreadDlg 对话框
class CMFCSyncThreadDlg : public CDialogEx
{
// 构造
public:
	CMFCSyncThreadDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CMFCSyncThreadDlg();//析构函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSYNCTHREAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
