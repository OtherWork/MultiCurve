#include "stdafx.h"
#include "CurveFileLoader.h"


CCurveFileLoader::CCurveFileLoader(void)
{
}


CCurveFileLoader::~CCurveFileLoader(void)
{
}

BOOL CCurveFileLoader::load(vector<ItemData> &datas, LPCTSTR strTime)
{
    datas.clear();

    //��ȡ��ǰ·���µ�DataĿ¼
    CString strFilePath;
    GetModuleFileName(NULL, strFilePath.GetBufferSetLength(MAX_PATH), MAX_PATH);
    strFilePath.ReleaseBuffer();
    int index = strFilePath.ReverseFind('\\');
    if(index > 0)
    {
        strFilePath = strFilePath.Left(index + 1);
    }
    strFilePath += TEXT("data\\");

    //��ѯDataĿ¼��,��ָ��ʱ�俪ͷ��ȫ���ļ�
    CFileFind finder;
    BOOL bWorking = finder.FindFile(strFilePath + _T("*.*"));
    vector<CString> files;
    while(bWorking)
    {
        bWorking = finder.FindNextFile();
        if(finder.IsDirectory() || finder.IsDots())
        {
            continue;
        }
        CString strFileName = finder.GetFileName();
        if(strFileName.Find(strTime) >= 0)
        {
            files.push_back(finder.GetFilePath());
        }
    }

    //�����ļ��е�����
    int len = files.size();
    for(int i = 0; i < len; ++i)
    {
        CString strFile = files[i];
        FILE *pFile = NULL;
        _tfopen_s(&pFile, strFile, TEXT("rb"));
        if(pFile)
        {
            char buf[0x100] = {0};
            ItemData item;
            //ȡ���ļ��Զ�������
            int index = strFile.ReverseFind('.');
            if(index > 0)
            {
                strFile = strFile.Left(index);
            }
            index = strFile.ReverseFind('_');
            if(index > 0)
            {
                strFile = strFile.Right(strFile.GetLength() - index - 1);
            }
            item.mFileName = strFile;

            //��������(ÿ��һ������)
            while(fgets(buf, 0x100, pFile) != NULL)
            {
                double val = atof(buf);
                item.mDatas.push_back(val);
                memset(buf, 0, 0x100);
            }

            fclose(pFile);
            datas.push_back(item);
        }
    }


    return !datas.empty();
}
