
// MFCTimeDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCTimeDemoApp: 
// �йش����ʵ�֣������ MFCTimeDemo.cpp
//

class CMFCTimeDemoApp : public CWinApp
{
public:
	CMFCTimeDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCTimeDemoApp theApp;