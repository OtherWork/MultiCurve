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
    int len = mDatas.size();
    if(len == 0)
    {
        return;
    }

    Graphics gp(pDC->m_hDC);
    Color clr(mColor);
    Pen pen(clr); //坐标点颜色

    gp.SetSmoothingMode(SmoothingModeHighQuality); //平滑模式


    //修正offsetX.
    if(len * mSpaceWidth + offsetX < mWidth) //
    {
        offsetX = mWidth - len * mSpaceWidth;
    }
    if(offsetX > 0)
    {
        offsetX = 0;
    }

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

    SolidBrush brush(clr);
    len = len - startIndex;
    Point *pPts = new Point[len];
    for(int i = 0; i < len; ++i)
    {
        pPts[i].X = i * mSpaceWidth + offsetX;
        pPts[i].Y = mHeight - mDatas[i + startIndex] / range * mHeight; //根据值区间宽度比例,换算成坐标
        gp.FillEllipse(&brush, pPts[i].X - 2, pPts[i].Y - 2, 4, 4);
    }
    //绘制曲线函数
    gp.DrawCurve(&pen, pPts, len, 1.0f);

    delete[] pPts;
}
