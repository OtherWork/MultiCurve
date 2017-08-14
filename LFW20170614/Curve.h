#pragma once

#include <vector>
using namespace std;

class CCurve
{
private:
    int mWidth;
    int mHeight;
    int mSpaceWidth;
    double mRangeMin;
    double mRangeMax;
    int mColor;
public:
    CCurve(void);
    ~CCurve(void);
    vector<double> mDatas;

    void setParam(int width, int height, int spaceWidth, double minVal, double maxVal, int color);

    void add(double val);
    void clear();
    //»æÖÆÇúÏß
    void DrawCure(CDC *pDC, int offsetX);
};

