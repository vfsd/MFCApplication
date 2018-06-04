
// MFCTimeDemoDlg.h : ͷ�ļ�
//

#pragma once


// CMFCTimeDemoDlg �Ի���
class CMFCTimeDemoDlg : public CDialogEx
{
// ����
public:
	CMFCTimeDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTIMEDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	UINT m_nRedID;
	UINT m_nGreenID;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonRed();
	afx_msg void OnBnClickedButtonGreen();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
