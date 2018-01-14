
// MFCCBrushDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFCCBrushDlg �Ի���
class CMFCCBrushDlg : public CDialogEx
{
// ����
public:
	CMFCCBrushDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCBRUSH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	CBrush m_brush;//��ˢ
	CBitmap m_bmp;//λͼ

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CComboBox m_cmb_brush;
	afx_msg void OnCbnSelchangeCmbBrush();
};
