
// MFCSyncThreadDlg.h : ͷ�ļ�
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

// CMFCSyncThreadDlg �Ի���
class CMFCSyncThreadDlg : public CDialogEx
{
// ����
public:
	CMFCSyncThreadDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CMFCSyncThreadDlg();//��������

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSYNCTHREAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
