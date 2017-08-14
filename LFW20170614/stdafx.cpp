
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// LFW20170614.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

#pragma comment(lib,"ws2_32")


void printLog(LPCTSTR lpszFmt, ...)
{
    va_list args;
    va_start(args, lpszFmt);
    int len = _vsctprintf(lpszFmt, args) + 4;
    len = min(1024 * 10, len);
    TCHAR *lpszBuf = (TCHAR*)_alloca(len * sizeof(TCHAR)); //ջ�з���, ����Ҫ�ͷ�
    len = _vstprintf_s(lpszBuf, len , lpszFmt, args);
    va_end(args);
    if(lpszBuf[len - 1] != '\n')
    {
        lpszBuf[len] = '\r';
        lpszBuf[len + 1] = '\n';
        lpszBuf[len + 2] = 0;
    }
    OutputDebugString(lpszBuf);
}
