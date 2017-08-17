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

    void replace(vector<double>&datas);

    /**
    *
    * @param: int width 绘制区域宽度
    * @param: int height 绘制高度
    * @param: int spaceWidth 方向每个单位像素
    * @param: double minVal 最小值
    * @param: double maxVal 最大值
    * @param: int color 线条颜色
    * @returns:   void
    */
    void setParam(int width, int height, int spaceWidth, double minVal, double maxVal, int color);

    void add(double val);
    void clear();
    //绘制曲线
    void DrawCure(CDC *pDC, int offsetX);
};

