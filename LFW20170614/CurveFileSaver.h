#pragma once
class CCurveFileSaver
{
private:
    FILE *mpFile;
    CString mFileName;
public:
    CCurveFileSaver(void);
    ~CCurveFileSaver(void);
    void setFileName(LPCTSTR strFileName);
    void saveData(double val);
    BOOL createFile();
};

