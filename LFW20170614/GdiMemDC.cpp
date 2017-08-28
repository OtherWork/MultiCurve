#include "stdafx.h"
#include "GdiMemDC.h"


CGdiMemDC::CGdiMemDC(void)
{
    mpOld = NULL;
}


CGdiMemDC::~CGdiMemDC(void)
{
    if(mpOld)
    {
        SelectObject(mpOld);
    }
}

void CGdiMemDC::create(CDC* pDC, int width, int height)
{
    CreateCompatibleDC(pDC);
    mBmp.CreateCompatibleBitmap(pDC, width, height);
    mpOld = SelectObject(&mBmp);
}
