
// MFCSyncThread.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCSyncThreadApp: 
// �йش����ʵ�֣������ MFCSyncThread.cpp
//

class CMFCSyncThreadApp : public CWinApp
{
public:
	CMFCSyncThreadApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCSyncThreadApp theApp;