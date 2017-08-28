#pragma once

#include <vector>
using namespace std;

#define PixelMili 10

class CCurve
{
private:
    int mWidth;
    int mHeight;
    int mSpaceWidth;
    double mRangeMin;
    double mRangeMax;
    int mColor;
    CString mName;
public:
    CCurve(void);
    ~CCurve(void);
    vector<double> mDatas;

    void replace(vector<double>&datas);
    int getColor();
    LPCTSTR getName();

    /**
    *
    * @param: LPCTSTR strName 线条名字
    * @param: int width 绘制区域宽度
    * @param: int height 绘制高度
    * @param: int sampleTimes 采样周期(最低是PixelMili) 单位:(毫秒ms)
    * @param: double minVal 最小值
    * @param: double maxVal 最大值
    * @param: int color 线条颜色
    * @returns:   void
    */
    void setParam(LPCTSTR strName, int width, int height, int sampleTimes,  int color);

    //添加数据点
    void add(double val);

    //清空全部数据
    void clear();
    //绘制曲线
    void DrawCure(CDC *pDC, int offsetX, double minRange, double maxRange);

    void DrawLegend(CDC *pDC, int x, int y);

    //计算需要的宽度.
    int getNeedWidth(int &pointWidth);

    double getRange();

    double getMaxRange();
    void calcRange(double &minRange, double &maxRange);
};

