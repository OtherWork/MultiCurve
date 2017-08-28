#pragma once
#include <vector>
using namespace std;

class ItemData
{
public:
    CString mFileName;
    vector<double> mDatas;
};



class CCurveFileLoader
{
public:
    CCurveFileLoader(void);
    ~CCurveFileLoader(void);

    static BOOL load(vector<ItemData> &datas, LPCTSTR strTime);
};

