
// MFCCBrush.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCCBrushApp: 
// �йش����ʵ�֣������ MFCCBrush.cpp
//

class CMFCCBrushApp : public CWinApp
{
public:
	CMFCCBrushApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCCBrushApp theApp;