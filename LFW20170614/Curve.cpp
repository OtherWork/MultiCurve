#include "stdafx.h"
#include "Curve.h"


CCurve::CCurve(void)
{
    setParam(100, 100, 5, 0, 200, 0xFF000000);
}


CCurve::~CCurve(void)
{
}


void CCurve::replace(vector<double>&datas)
{
    mDatas.clear();
    mDatas = datas;
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
    int originOffsetX = 30;
    int originOffsetY = 10;
    int len = mDatas.size();
    if(len == 0)
    {
        return;
    }

    Graphics gp(pDC->m_hDC);
    Color clr((mColor & 0x00FFFFFF) | 0xee000000);
    Pen pen(clr); //�������ɫ

    gp.SetSmoothingMode(SmoothingModeHighQuality); //ƽ��ģʽ


    //����offsetX��������Ҫ��ʾ�ĵ�,  �Ż���ʾ�ٶ�
    int startIndex = 0;
    if(offsetX < 0)
    {
        startIndex = (-offsetX) / mSpaceWidth;
        if(startIndex >= len)
        {
            startIndex = len - 1;
        }
    }

    double range = mRangeMax - mRangeMin; //����ֵ������
    int maxPtCount = mWidth / mSpaceWidth + 2;
    len -= startIndex;
    maxPtCount = min(len, maxPtCount);

    SolidBrush brush(clr);

    vector<Point> pts;
    for(int i = 0; i < maxPtCount; ++i)
    {
        Point pt;
        pt.X = (i + startIndex) * mSpaceWidth + offsetX + originOffsetX;
        pt.Y = mHeight - mDatas[i + startIndex] / range * mHeight - originOffsetY - 1; //����ֵ�����ȱ���,���������
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

    //�������ߺ���
    gp.DrawCurve(&pen, pts.data(), pts.size(), 1.0f);

}
