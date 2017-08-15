#include "stdafx.h"
#include "CurveFileSaver.h"


CCurveFileSaver::CCurveFileSaver(void)
{
    mpFile = NULL;
}


CCurveFileSaver::~CCurveFileSaver(void)
{
    if(mpFile)
    {
        fclose(mpFile);
    }
}

void CCurveFileSaver::setFileName(LPCTSTR strFileName)
{
    mFileName = strFileName;
}

void CCurveFileSaver::saveData(double val)
{
    if(mpFile == NULL)
    {
        if(!createFile())
        {
            return;
        }
    }

    CStringA tStr;
    tStr.Format("%f\r\n", val);
    fwrite((LPCSTR)tStr, 1, tStr.GetLength(), mpFile);
    fflush(mpFile);
}

BOOL CCurveFileSaver::createFile()
{
    CString strFilePath;
    GetModuleFileName(NULL, strFilePath.GetBufferSetLength(MAX_PATH), MAX_PATH);
    strFilePath.ReleaseBuffer();
    int index = strFilePath.ReverseFind('\\');
    if(index > 0)
    {
        strFilePath = strFilePath.Left(index + 1);
    }
    SYSTEMTIME st = {0};
    GetLocalTime(&st);
    CString tStr;
    tStr.Format(TEXT("%04d_%02d_%02d_%02d_%02d_%02d_%s.txt"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, mFileName);
    strFilePath += tStr;
    _tfopen_s(&mpFile, strFilePath, TEXT("wb"));
    return mpFile != NULL;
}
