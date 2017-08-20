
// LFW20170614Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "ClientTCP.h"
#include "Curve.h"
#include "CurveFileSaver.h"

// CLFW20170614Dlg �Ի���
class CLFW20170614Dlg : public CDialogEx, public OnClientListener
{
    // ����
public:
    CLFW20170614Dlg(CWnd* pParent = NULL);  // ��׼���캯��

    // �Ի�������
    enum { IDD = IDD_LFW20170614_DIALOG };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��


    //ʵ�������¼�����
    virtual void onConnect(BOOL bSuccess);

    //ʵ�����ݽ����¼�����
    virtual void onRecv(const char *pBuf, int len);

    //ʵ�ֶϿ��¼�����
    virtual void onDisconnect();

    CClientTCP mClient;   //�ͻ��˷�װ��

    SOCKET mServerSock; //ģ�������(��λ��).----��ʽ�汾����ɾ����

    int mOffsetX;
    int mLastOffsetX;
    BOOL mIsCapture;
    CPoint mLastPoint;
    void drawXY(CDC *pDC, int width, int height, int xUnits, int yUnits, int offsetX);
    void drawCurve();

    vector<CCurve> mCurves;//������̬����
    vector<CCurve> mStaticCurves;//������̬����;
    vector<CCurveFileSaver> mSavers; //�ļ�������
    void initCurve();

private:
    CFont m_Font;
    CBitmapButton m_button;
    bool LedFlag;
    // ʵ��
protected:
    HICON m_hIcon;
    //CBrush m_brush;
    // ���ɵ���Ϣӳ�亯��
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnBnClickedBtnSend(); //������Ӧ����
    DECLARE_MESSAGE_MAP()
public:
    CStatic m_statc1;
    CStatic m_statc2;
    CStatic m_statc3;
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    CStatic m_statc4;
    CStatic m_statc5;
    CStatic m_statc6;
    CStatic m_statc7;
    CStatic m_statc8;
    CStatic m_statc9;
    CStatic m_statc10;
    CStatic m_statc11;
    CStatic m_statc12;
    CStatic m_statc13;
    CStatic m_statc14;
    CStatic m_statc15;
    CStatic m_statc16;

    CStatic m_statc17;
    CStatic m_statc18;
    CStatic m_statc19;
    CStatic m_statc20;
    CStatic m_statc21;
    CStatic m_statc22;
    CStatic m_statc23;
    CStatic m_statc24;
    CStatic m_statc25;
    CStatic m_statc26;
    CStatic m_statc27;
    CStatic m_statc28;
    CStatic m_statc29;
    CStatic m_statc30;
    CStatic m_statc31;
    CStatic m_statc32;
    CStatic m_statc33;
    CStatic m_statc34;
    CStatic m_statc35;
    CStatic m_statc36;
    CStatic m_statc37;
    CStatic m_statc38;
    CStatic m_statc39;
    CStatic m_statc40;
    CStatic m_statc41;
    CStatic m_statc42;
    CStatic m_statc43;
    CStatic m_statc44;
    CStatic m_statc45;
    CStatic m_statc46;
    CStatic m_statc47;
    CStatic m_statc48;
    CStatic m_statc49;
    CStatic m_statc50;
    CStatic m_statc51;
    CStatic m_statc52;
    CStatic m_statc53;
    CStatic m_statc54;
    CStatic m_statc55;
    CStatic m_statc56;
    CStatic m_statc57;
    CStatic m_statc58;
    CStatic m_statc59;
    CStatic m_statc60;
    CStatic m_statc61;
    CStatic m_statc62;
    CStatic m_statc63;
    CStatic m_statc64;
    CStatic m_statc65;
    CStatic m_statc66;
    CStatic m_statc67;
    CStatic m_statc68;
    CStatic m_statc69;
    CStatic m_statc70;
    CStatic m_statc71;
    CStatic m_statc72;
    CStatic m_statc73;
    CStatic m_statc74;
    CStatic m_statc75;
    CStatic m_statc76;
    CStatic m_statc77;

    //afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton1();
    //afx_msg void OnBnClickedButton8();
    afx_msg void OnStnClickedStatic1();
    afx_msg void OnDestroy();

    afx_msg LRESULT OnMyUpdateUI(WPARAM wParam, LPARAM lParam);

    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnBnClickedShowstatic();
    afx_msg void OnBnClickedButton8();
};
