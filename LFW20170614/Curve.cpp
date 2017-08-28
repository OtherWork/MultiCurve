#include "stdafx.h"
#include "Curve.h"


CCurve::CCurve(void)
{
    mRangeMin = 99999;
    mRangeMax = 0;
    setParam(TEXT(""), 100, 100, 100, 0xFF000000);
}


CCurve::~CCurve(void)
{
}


void CCurve::replace(vector<double>&datas)
{
    mDatas.clear();
    mDatas = datas;
    calcRange(mRangeMin, mRangeMax);
}

int CCurve::getColor()
{
    return mColor;
}

LPCTSTR CCurve::getName()
{
    return mName;
}

void CCurve::setParam(LPCTSTR strName, int width, int height, int sampleTimes,  int color)
{
    mWidth = width;
    mHeight = height;
    mSpaceWidth = sampleTimes / PixelMili;
    if(mSpaceWidth == 0)
    {
        mSpaceWidth = 1;
    }
    mColor  = color;
    mName = strName;
}


void CCurve::add(double val)
{
    mDatas.push_back(val);
    mRangeMin = min(mRangeMin, val);
    mRangeMax = max(mRangeMax, val);
}

void CCurve::clear()
{
    mDatas.clear();
}

void CCurve::DrawCure(CDC *pDC, int offsetX, double minRange, double maxRange)
{
    int originOffsetX = 30;
    int originOffsetY = 10;
    int len = mDatas.size();
    if(len == 0)
    {
        return;
    }

    Graphics gp(pDC->m_hDC);
    Color clr(mColor);
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

    double range = maxRange - minRange; //计算值区间宽度
    int maxPtCount = mWidth / mSpaceWidth + 2;
    len -= startIndex;
    maxPtCount = min(len, maxPtCount);

    SolidBrush brush(clr);

    vector<Point> pts;
    for(int i = 0; i < maxPtCount; ++i)
    {
        Point pt;
        pt.X = (i + startIndex) * mSpaceWidth + offsetX + originOffsetX;
        pt.Y = mHeight - mDatas[i + startIndex] / range * mHeight - originOffsetY - 1; //根据值区间宽度比例,换算成坐标
        if(pt.X < originOffsetX)
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
    gp.DrawCurve(&pen, pts.data(), pts.size(), 0.5f);

}

void CCurve::DrawLegend(CDC *pDC, int x, int y)
{
    BYTE *buf = (BYTE*)&mColor;
    pDC->FillSolidRect(x - 4, y - 4, 8, 8, RGB(buf[2], buf[1], buf[0]));
    CRect rcText;
    pDC->DrawText(mName, &rcText, DT_CALCRECT);
    CRect rcDraw(x + 8, y - rcText.Height() / 2, x + 8 + rcText.Width(), y + rcText.Height() / 2);
    pDC->DrawText(mName, &rcDraw, DT_CENTER);
}

int CCurve::getNeedWidth(int &pointWidth)
{
    pointWidth = mSpaceWidth;
    return mDatas.size() * mSpaceWidth;
}

double CCurve::getRange()
{
    return mRangeMax - mRangeMin;
}

double CCurve::getMaxRange()
{
    return mRangeMax;
}

void CCurve::calcRange(double &minRange, double &maxRange)
{
    int nCount = mDatas.size();
    if(nCount == 0)
    {
        minRange = 0;
        maxRange = 0;
        return ;
    }
    minRange = 99999999;
    maxRange = 0;
    for(int i = 0; i < nCount; ++i)
    {
        minRange = min(mDatas[i], minRange);
        maxRange = max(maxRange, mDatas[i]);
    }
}

