#pragma once
#include "afxwin.h"
class CGdiMemDC :
    public CDC
{
public:
    CGdiMemDC(void);
    ~CGdiMemDC(void);
    CBitmap mBmp;
    CBitmap *mpOld;
    void create(CDC* pDC, int width, int height);
};

