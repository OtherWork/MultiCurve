
// LFW20170614.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLFW20170614App:
// �йش����ʵ�֣������ LFW20170614.cpp
//

class CLFW20170614App : public CWinApp
{
public:
	CLFW20170614App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLFW20170614App theApp;