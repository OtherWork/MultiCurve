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
    * @param: LPCTSTR strName ��������
    * @param: int width ����������
    * @param: int height ���Ƹ߶�
    * @param: int sampleTimes ��������(�����PixelMili) ��λ:(����ms)
    * @param: double minVal ��Сֵ
    * @param: double maxVal ���ֵ
    * @param: int color ������ɫ
    * @returns:   void
    */
    void setParam(LPCTSTR strName, int width, int height, int sampleTimes,  int color);

    //������ݵ�
    void add(double val);

    //���ȫ������
    void clear();
    //��������
    void DrawCure(CDC *pDC, int offsetX, double minRange, double maxRange);

    void DrawLegend(CDC *pDC, int x, int y);

    //������Ҫ�Ŀ��.
    int getNeedWidth(int &pointWidth);

    double getRange();

    double getMaxRange();
    void calcRange(double &minRange, double &maxRange);
};

