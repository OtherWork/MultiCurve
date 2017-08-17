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
    * @param: int width ����������
    * @param: int height ���Ƹ߶�
    * @param: int spaceWidth ����ÿ����λ����
    * @param: double minVal ��Сֵ
    * @param: double maxVal ���ֵ
    * @param: int color ������ɫ
    * @returns:   void
    */
    void setParam(int width, int height, int spaceWidth, double minVal, double maxVal, int color);

    void add(double val);
    void clear();
    //��������
    void DrawCure(CDC *pDC, int offsetX);
};

