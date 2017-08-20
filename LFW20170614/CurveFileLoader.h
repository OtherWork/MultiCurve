#pragma once

#include <vector>
using namespace std;

class CCurveFileLoader
{
public:
    CCurveFileLoader(void);
    ~CCurveFileLoader(void);

    static BOOL load(vector<vector<double>> &datas, LPCTSTR strTime);
};

