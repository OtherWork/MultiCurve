#include "stdafx.h"
#include "Curve.h"


CCurve::CCurve(void)
{
    setParam(100, 100, 5, 0, 200, 0xFF000000);
}


CCurve::~CCurve(void)
{
}


void CCurve::setParam(int width, int height, int spaceWidth, double minVal, double maxVal, int color)
{
    mWidth = width;
    mHeight = height;
    mSpaceWidth = spaceWidth;
    mRangeMin = minVal;
    mRangeMax = maxVal;
    mColor  = color;

}


void CCurve::add(double val)
{
    mDatas.push_back(val);
}

void CCurve::clear()
{
    mDatas.clear();
}

void CCurve::DrawCure(CDC *pDC, int offsetX)
{
    int originOffset = 30;
    int len = mDatas.size();
    if(len == 0)
    {
        return;
    }

    Graphics gp(pDC->m_hDC);
    Color clr((mColor & 0x00FFFFFF) | 0xee000000);
    Pen pen(clr); //坐标点颜色

    gp.SetSmoothingMode(SmoothingModeHighQuality); //平滑模式


    //根据offsetX来计算需要显示的点,  优化显示速度
    int startIndex = 0;
    if(offsetX < 0)
    {
        startIndex = (-offsetX) / mSpaceWidth;
        if(startIndex >= len)
        {
            startIndex = len - 1;
        }
    }

    double range = mRangeMax - mRangeMin; //计算值区间宽度
    int maxPtCount = mWidth / mSpaceWidth + 2;


    SolidBrush brush(clr);
    len = len - startIndex;
    vector<Point> pts;
    for(int i = 0; i < len; ++i)
    {
        Point pt;
        pt.X = i * mSpaceWidth + offsetX + originOffset;
        pt.Y = mHeight - mDatas[i + startIndex] / range * mHeight - originOffset - 1; //根据值区间宽度比例,换算成坐标
        if(pt.X < originOffset)
        {
            continue;
        }
        else
        {
            gp.FillEllipse(&brush, pt.X - 2, pt.Y - 2, 4, 4);
        }
        pts.push_back(pt);

    }

    //绘制曲线函数
    gp.DrawCurve(&pen, pts.data(), pts.size(), 1.0f);

}
