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

    //获取当前路径下的Data目录
    CString strFilePath;
    GetModuleFileName(NULL, strFilePath.GetBufferSetLength(MAX_PATH), MAX_PATH);
    strFilePath.ReleaseBuffer();
    int index = strFilePath.ReverseFind('\\');
    if(index > 0)
    {
        strFilePath = strFilePath.Left(index + 1);
    }
    strFilePath += TEXT("data\\");

    //查询Data目录下,以指定时间开头的全部文件
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

    //解析文件中的数据
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
            //取出文件自定义名字
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

            //解析数据(每行一个数据)
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
