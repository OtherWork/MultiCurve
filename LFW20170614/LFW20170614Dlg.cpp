
// LFW20170614Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LFW20170614.h"
#include "LFW20170614Dlg.h"
#include "afxdialogex.h"

//���������,�������ģ����λ��TCP������, ��������.
//����Ҫ��ע�ʹ���, ��Ҫ�Ƿſ����д���
//#define RUN_TEST_SERVER

#ifdef RUN_TEST_SERVER
#include "ServerTCP.h"
#endif
#include "Curve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif





// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

    // �Ի�������
    enum { IDD = IDD_ABOUTBOX };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

    // ʵ��
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLFW20170614Dlg �Ի���




CLFW20170614Dlg::CLFW20170614Dlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(CLFW20170614Dlg::IDD, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    mOffsetX = 0;
    mLastOffsetX = 0;
    mIsCapture = FALSE;
}

void CLFW20170614Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_STATIC1, m_statc1);
    DDX_Control(pDX, IDC_STATIC2, m_statc2);
    DDX_Control(pDX, IDC_STATIC3, m_statc3);
    DDX_Control(pDX, IDC_STATIC4, m_statc4);
    DDX_Control(pDX, IDC_STATIC5, m_statc5);
    DDX_Control(pDX, IDC_STATIC6, m_statc6);
    DDX_Control(pDX, IDC_STATIC7, m_statc7);
    DDX_Control(pDX, IDC_STATIC8, m_statc8);
    DDX_Control(pDX, IDC_STATIC9, m_statc9);
    DDX_Control(pDX, IDC_STATIC10, m_statc10);
    DDX_Control(pDX, IDC_STATIC11, m_statc11);
    DDX_Control(pDX, IDC_STATIC12, m_statc12);
    DDX_Control(pDX, IDC_STATIC13, m_statc13);
    DDX_Control(pDX, IDC_STATIC14, m_statc14);
    DDX_Control(pDX, IDC_STATIC15, m_statc15);
    DDX_Control(pDX, IDC_STATIC16, m_statc16);
    DDX_Control(pDX, IDC_STATIC17, m_statc17);
    DDX_Control(pDX, IDC_STATIC18, m_statc18);
    DDX_Control(pDX, IDC_STATIC19, m_statc19);
    DDX_Control(pDX, IDC_STATIC20, m_statc20);
    DDX_Control(pDX, IDC_STATIC21, m_statc21);
    DDX_Control(pDX, IDC_STATIC22, m_statc22);
    DDX_Control(pDX, IDC_STATIC23, m_statc23);
    DDX_Control(pDX, IDC_STATIC24, m_statc24);
    DDX_Control(pDX, IDC_STATIC25, m_statc25);
    DDX_Control(pDX, IDC_STATIC26, m_statc26);
    DDX_Control(pDX, IDC_STATIC27, m_statc27);
    DDX_Control(pDX, IDC_STATIC28, m_statc28);
    DDX_Control(pDX, IDC_STATIC29, m_statc29);
    DDX_Control(pDX, IDC_STATIC30, m_statc30);
    DDX_Control(pDX, IDC_STATIC31, m_statc31);
    DDX_Control(pDX, IDC_STATIC32, m_statc32);
    DDX_Control(pDX, IDC_STATIC33, m_statc33);
    DDX_Control(pDX, IDC_STATIC34, m_statc34);
    DDX_Control(pDX, IDC_STATIC35, m_statc35);
    DDX_Control(pDX, IDC_STATIC36, m_statc36);
    DDX_Control(pDX, IDC_STATIC37, m_statc37);
    DDX_Control(pDX, IDC_STATIC38, m_statc38);
    DDX_Control(pDX, IDC_STATIC39, m_statc39);
    DDX_Control(pDX, IDC_STATIC40, m_statc40);
    DDX_Control(pDX, IDC_STATIC41, m_statc41);
    DDX_Control(pDX, IDC_STATIC42, m_statc42);
    DDX_Control(pDX, IDC_STATIC43, m_statc43);
    DDX_Control(pDX, IDC_STATIC44, m_statc44);
    DDX_Control(pDX, IDC_STATIC45, m_statc45);
    DDX_Control(pDX, IDC_STATIC46, m_statc46);
    DDX_Control(pDX, IDC_STATIC47, m_statc47);
    DDX_Control(pDX, IDC_STATIC48, m_statc48);
    DDX_Control(pDX, IDC_STATIC49, m_statc49);
    DDX_Control(pDX, IDC_STATIC50, m_statc50);
    DDX_Control(pDX, IDC_STATIC51, m_statc51);
    DDX_Control(pDX, IDC_STATIC52, m_statc52);
    DDX_Control(pDX, IDC_STATIC53, m_statc53);
    DDX_Control(pDX, IDC_STATIC54, m_statc54);
    DDX_Control(pDX, IDC_STATIC55, m_statc55);
    DDX_Control(pDX, IDC_STATIC56, m_statc56);
    DDX_Control(pDX, IDC_STATIC57, m_statc57);
    DDX_Control(pDX, IDC_STATIC58, m_statc58);
    DDX_Control(pDX, IDC_STATIC59, m_statc59);
    DDX_Control(pDX, IDC_STATIC60, m_statc60);
    DDX_Control(pDX, IDC_STATIC61, m_statc61);
    DDX_Control(pDX, IDC_STATIC62, m_statc62);
    DDX_Control(pDX, IDC_STATIC63, m_statc63);
    DDX_Control(pDX, IDC_STATIC64, m_statc64);
    DDX_Control(pDX, IDC_STATIC65, m_statc65);
    DDX_Control(pDX, IDC_STATIC66, m_statc66);
    DDX_Control(pDX, IDC_STATIC67, m_statc67);
    DDX_Control(pDX, IDC_STATIC68, m_statc68);
    DDX_Control(pDX, IDC_STATIC69, m_statc69);
    DDX_Control(pDX, IDC_STATIC70, m_statc70);
    DDX_Control(pDX, IDC_STATIC71, m_statc71);
    DDX_Control(pDX, IDC_STATIC72, m_statc72);
    DDX_Control(pDX, IDC_STATIC73, m_statc73);
    DDX_Control(pDX, IDC_STATIC74, m_statc74);
    DDX_Control(pDX, IDC_STATIC75, m_statc75);
    DDX_Control(pDX, IDC_STATIC76, m_statc76);
    DDX_Control(pDX, IDC_STATIC77, m_statc77);
}

BEGIN_MESSAGE_MAP(CLFW20170614Dlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    //  ON_WM_CTLCOLOR()
    //ON_WM_CTLCOLOR()
    ON_WM_CTLCOLOR()
    ON_BN_CLICKED(IDC_BTN_SEND, &CLFW20170614Dlg::OnBnClickedBtnSend)
    ON_BN_CLICKED(IDC_BUTTON1, &CLFW20170614Dlg::OnBnClickedButton1)
    //ON_BN_CLICKED(IDC_BUTTON4, &CLFW20170614Dlg::OnBnClickedButton4)
    //ON_BN_CLICKED(IDC_BUTTON8, &CLFW20170614Dlg::OnBnClickedButton8)
    ON_WM_DESTROY()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CLFW20170614Dlg ��Ϣ�������

BOOL CLFW20170614Dlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();
    //��ť�ĸ�������
    LedFlag = 0;
    m_button.LoadBitmaps(IDB_BITMAP3);
    m_button.SubclassDlgItem(IDC_BUTTON1, this);
    m_button.SizeToContent();
    // ��������...���˵�����ӵ�ϵͳ�˵��С�
    //m_brush.CreateSolidBrush(RGB(255,255,0));
    // IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if(pSysMenu != NULL)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if(!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);         // ���ô�ͼ��
    SetIcon(m_hIcon, FALSE);        // ����Сͼ��

    // TODO: �ڴ���Ӷ���ĳ�ʼ������
    m_Font.CreatePointFont(150, _T("����"), NULL);
    m_statc1.SetFont(&m_Font, true);
    m_statc1.SetWindowTextW(_T("ZDϵͳѹ��"));
    m_statc2.SetFont(&m_Font, true);
    m_statc2.SetWindowTextW(_T("DDϵͳѹ��"));
    m_statc3.SetFont(&m_Font, true);
    m_statc3.SetWindowTextW(_T("JJϵͳѹ��"));
    m_statc4.SetFont(&m_Font, true);
    m_statc4.SetWindowTextW(_T("ZDJJ�����ѹ��"));
    m_statc5.SetFont(&m_Font, true);
    m_statc5.SetWindowTextW(_T("ZDJJ���˻�ѹ��"));
    m_statc6.SetFont(&m_Font, true);
    m_statc6.SetWindowTextW(_T("DDJJ�����ѹ��"));
    m_statc7.SetFont(&m_Font, true);
    m_statc7.SetWindowTextW(_T("DDJJ�����ѹ��"));
    m_statc8.SetFont(&m_Font, true);
    m_statc8.SetWindowTextW(_T("NBZC�����ѹ��"));
    m_statc9.SetFont(&m_Font, true);
    m_statc9.SetWindowTextW(_T("NBZC���˻�ѹ��"));
    m_statc10.SetFont(&m_Font, true);
    m_statc10.SetWindowTextW(_T("ZBZC�����ѹ��"));
    m_statc11.SetFont(&m_Font, true);
    m_statc11.SetWindowTextW(_T("ZBZC���˻�ѹ��"));
    m_statc12.SetFont(&m_Font, true);
    m_statc12.SetWindowTextW(_T("WBYJ�����ѹ��"));
    m_statc13.SetFont(&m_Font, true);
    m_statc13.SetWindowTextW(_T("WBYJ���˻�ѹ��"));
    m_statc14.SetFont(&m_Font, true);
    m_statc14.SetWindowTextW(_T("ZDϵͳѹ��"));
    m_statc15.SetFont(&m_Font, true);
    m_statc15.SetWindowTextW(_T("DDϵͳѹ��"));
    m_statc16.SetFont(&m_Font, true);
    m_statc16.SetWindowTextW(_T("JJϵͳѹ��"));
    m_statc17.SetFont(&m_Font, true);
    m_statc17.SetWindowTextW(_T("ZF"));
    m_statc18.SetFont(&m_Font, true);
    m_statc18.SetWindowTextW(_T("PL"));
    m_statc19.SetFont(&m_Font, true);
    m_statc19.SetWindowTextW(_T("SZʱ��"));
    m_statc20.SetFont(&m_Font, true);
    m_statc20.SetWindowTextW(_T("JZʱ��"));
    m_statc21.SetFont(&m_Font, true);
    m_statc21.SetWindowTextW(_T("������"));
    m_statc22.SetFont(&m_Font, true);
    m_statc22.SetWindowTextW(_T("Ԥѹ��"));
    m_statc23.SetFont(&m_Font, true);
    m_statc23.SetWindowTextW(_T("MCѹ��"));
    m_statc24.SetFont(&m_Font, true);
    m_statc24.SetWindowTextW(_T("DDѹ��"));
    m_statc25.SetFont(&m_Font, true);
    m_statc25.SetWindowTextW(_T("CHJX"));
    m_statc26.SetFont(&m_Font, true);
    m_statc26.SetWindowTextW(_T("SDL"));
    m_statc27.SetFont(&m_Font, true);
    m_statc27.SetWindowTextW(_T("YYSJ"));
    m_statc28.SetFont(&m_Font, true);
    m_statc28.SetWindowTextW(_T("MCSJ"));
    m_statc29.SetFont(&m_Font, true);
    m_statc29.SetWindowTextW(_T("DDSJ"));
    m_statc30.SetFont(&m_Font, true);
    m_statc30.SetWindowTextW(_T("XYSJ"));
    m_statc31.SetFont(&m_Font, true);
    m_statc31.SetWindowTextW(_T("HTSJ"));
    m_statc32.SetFont(&m_Font, true);
    m_statc32.SetWindowTextW(_T("MPa"));
    m_statc33.SetFont(&m_Font, true);
    m_statc33.SetWindowTextW(_T("MPa"));
    m_statc34.SetFont(&m_Font, true);
    m_statc34.SetWindowTextW(_T("MPa"));
    m_statc35.SetFont(&m_Font, true);
    m_statc35.SetWindowTextW(_T("MPa��"));
    m_statc36.SetFont(&m_Font, true);
    m_statc36.SetWindowTextW(_T("MPa"));
    m_statc37.SetFont(&m_Font, true);
    m_statc37.SetWindowTextW(_T("MPa"));
    m_statc38.SetFont(&m_Font, true);
    m_statc38.SetWindowTextW(_T("MPa"));
    m_statc39.SetFont(&m_Font, true);
    m_statc39.SetWindowTextW(_T("MPa"));
    m_statc40.SetFont(&m_Font, true);
    m_statc40.SetWindowTextW(_T("MPa"));
    m_statc41.SetFont(&m_Font, true);
    m_statc41.SetWindowTextW(_T("MPa"));
    m_statc42.SetFont(&m_Font, true);
    m_statc42.SetWindowTextW(_T("MPa"));
    m_statc43.SetFont(&m_Font, true);
    m_statc43.SetWindowTextW(_T("MPa"));
    m_statc44.SetFont(&m_Font, true);
    m_statc44.SetWindowTextW(_T("MPa"));
    m_statc45.SetFont(&m_Font, true);
    m_statc45.SetWindowTextW(_T("MPa"));
    m_statc46.SetFont(&m_Font, true);
    m_statc46.SetWindowTextW(_T("MPa"));
    m_statc47.SetFont(&m_Font, true);
    m_statc47.SetWindowTextW(_T("MPa"));
    m_statc48.SetFont(&m_Font, true);
    m_statc48.SetWindowTextW(_T("MPa"));
    m_statc49.SetFont(&m_Font, true);
    m_statc49.SetWindowTextW(_T("MPa"));
    m_statc50.SetFont(&m_Font, true);
    m_statc50.SetWindowTextW(_T("��"));
    m_statc51.SetFont(&m_Font, true);
    m_statc51.SetWindowTextW(_T("��"));
    m_statc52.SetFont(&m_Font, true);
    m_statc52.SetWindowTextW(_T("��"));
    m_statc53.SetFont(&m_Font, true);
    m_statc53.SetWindowTextW(_T("��"));
    m_statc54.SetFont(&m_Font, true);
    m_statc54.SetWindowTextW(_T("��"));
    m_statc55.SetFont(&m_Font, true);
    m_statc55.SetWindowTextW(_T("g'"));
    m_statc56.SetFont(&m_Font, true);
    m_statc56.SetWindowTextW(_T("Hz"));
    m_statc57.SetFont(&m_Font, true);
    m_statc57.SetWindowTextW(_T("��"));
    m_statc58.SetFont(&m_Font, true);
    m_statc58.SetWindowTextW(_T("��"));
    m_statc59.SetFont(&m_Font, true);
    m_statc59.SetWindowTextW(_T("MPa"));
    m_statc60.SetFont(&m_Font, true);
    m_statc60.SetWindowTextW(_T("MPa"));
    m_statc61.SetFont(&m_Font, true);
    m_statc61.SetWindowTextW(_T("MPa"));
    m_statc62.SetFont(&m_Font, true);
    m_statc62.SetWindowTextW(_T("ZDGWZ"));
    m_statc63.SetFont(&m_Font, true);
    m_statc63.SetWindowTextW(_T("SJZF"));
    m_statc64.SetFont(&m_Font, true);
    m_statc64.SetWindowTextW(_T("g'"));
    m_statc65.SetFont(&m_Font, true);
    m_statc65.SetWindowTextW(_T("mm"));
    m_statc66.SetFont(&m_Font, true);
    m_statc66.SetWindowTextW(_T("CGWZ"));
    m_statc67.SetFont(&m_Font, true);
    m_statc67.SetWindowTextW(_T("CGL"));
    m_statc68.SetFont(&m_Font, true);
    m_statc68.SetWindowTextW(_T("DGWZ"));
    m_statc69.SetFont(&m_Font, true);
    m_statc69.SetWindowTextW(_T("DGL"));
    m_statc70.SetFont(&m_Font, true);
    m_statc70.SetWindowTextW(_T("TZSDL"));
    m_statc71.SetFont(&m_Font, true);
    m_statc71.SetWindowTextW(_T("HJSDL"));
    m_statc72.SetFont(&m_Font, true);
    m_statc72.SetWindowTextW(_T("mm"));
    m_statc73.SetFont(&m_Font, true);
    m_statc73.SetWindowTextW(_T("��"));
    m_statc74.SetFont(&m_Font, true);
    m_statc74.SetWindowTextW(_T("mm"));
    m_statc75.SetFont(&m_Font, true);
    m_statc75.SetWindowTextW(_T("��"));
    m_statc76.SetFont(&m_Font, true);
    m_statc76.SetWindowTextW(_T("mm"));
    m_statc77.SetFont(&m_Font, true);
    m_statc77.SetWindowTextW(_T("mm"));



    SetDlgItemText(IDC_EDIT_SEND, TEXT("45.875")); //��ʼ�����ͱ༭����ֵ.


#ifdef RUN_TEST_SERVER
    //����ģ�������
    //////////////////////////////////////////////////////////////////////////

    //��ʽ�汾��Ҫɾ����
    CServerTCP *pServer = new CServerTCP(8888); //����ģ���������װ��
    mServerSock = pServer->getSock(); //������socket
    pServer->start(); //�����߳�
    Sleep(300); //sleep��Ϊ���÷���������ȫ��������, �����������
    //*/
    //////////////////////////////////////////////////////////////////////////
#endif

    //�ͻ���
    mClient.setListener(this); //�����¼�������
    mClient.setServer(TEXT("127.0.0.1"), 8888); //���÷�����IP�Ͷ˿�
    mClient.start(); //�������ݽ����߳�


    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CLFW20170614Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLFW20170614Dlg::OnPaint()
{
    if(IsIconic())
    {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CPaintDC dc(this);
        drawCurve();
        CDialogEx::OnPaint();
    }


}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLFW20170614Dlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}






HBRUSH CLFW20170614Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    // TODO:  �ڴ˸��� DC ���κ�����
    if(nCtlColor == CTLCOLOR_STATIC)
    {
        pDC->SetTextColor(RGB(0, 0, 255));
        pDC->SetBkColor(RGB(0, 255, 0));
    }
    // TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
    return hbr;
}

void CLFW20170614Dlg::OnBnClickedButton1()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    if(LedFlag)
    {
        m_button.LoadBitmaps(IDB_BITMAP3);
        LedFlag = !LedFlag;
        m_button.Invalidate();

    }
    else
    {
        m_button.LoadBitmaps(IDB_BITMAP4);
        LedFlag = !LedFlag;
        m_button.Invalidate();

    }

}


/*void CLFW20170614Dlg::OnBnClickedButton2()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

}*/


/*void CLFW20170614Dlg::OnBnClickedButton4()
{

    // TODO: �ڴ���ӿؼ�֪ͨ����������

}*/


/*void CLFW20170614Dlg::OnBnClickedButton8()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������

}*/



void CLFW20170614Dlg::OnBnClickedBtnSend()
{
    CString tStr;
    GetDlgItemText(IDC_EDIT_SEND, tStr); //��ȡ�༭��������ķ��͵�����
    float val = _ttof(tStr);
    char buf[0x10] = {0};
    *(float*)buf = val;
    buf[4] = ',';
    mClient.send(buf, 5); //��������
}


//�����¼�
void CLFW20170614Dlg::onConnect(BOOL bSuccess)
{
    if(bSuccess == FALSE)
    {
        //MessageBox(TEXT("���ӷ�����ʧ��!!! �����Զ��˳�"));
        //PostMessage(WM_CLOSE);
    }
}

//�����¼�
void CLFW20170614Dlg::onRecv(const char *pBuf, int len)
{
    //�յ�����, ��������������
    float val1 = *(float*)pBuf;
    float val2 = *(float*)&pBuf[5];
    float val3 = *(float*)&pBuf[10];

    //�ֱ��������������ʾ���༭����.
    CString tStr;
    tStr.Format(TEXT("%.02f"), val1);
    SetDlgItemText(IDC_EDIT_VAL1, tStr);

    tStr.Format(TEXT("%.02f"), val2);
    SetDlgItemText(IDC_EDIT_VAL2, tStr);

    tStr.Format(TEXT("%.02f"), val3);
    SetDlgItemText(IDC_EDIT_VAL3, tStr);
}

//�Ͽ������¼�
void CLFW20170614Dlg::onDisconnect()
{
#ifdef RUN_TEST_SERVER
    //////////////////////////////////////////////////////////////////////////
    //��ʽ�汾��Ҫɾ����
    CSocketTCP sock(mServerSock);
    sock.close();
    //////////////////////////////////////////////////////////////////////////*/
#endif

    MessageBox(TEXT("�����Ѿ��Ͽ�!!!!! �����Զ��˳�"));
    PostMessage(WM_CLOSE);

}



void CLFW20170614Dlg::OnDestroy()
{
    __super::OnDestroy();

    mClient.stop();

#ifdef RUN_TEST_SERVER
    //////////////////////////////////////////////////////////////////////////
    //��ʽ�汾��Ҫɾ����
    CSocketTCP sock(mServerSock);
    sock.close();
    //////////////////////////////////////////////////////////////////////////*/
#endif
}



/**
* Method:    drawXY
* FullName:  CLFW20170614Dlg::drawXY
* Access:    protected
* Qualifier:
* @param: CDC * pDC
* @param: int width ����������
* @param: int height ��������߶�
* @param: int xUnits  �������ܵ�λ��(�ֳɶ��ٸ�)
* @param: int yUnits �������ܵ�λ��(�ֳɸ���)
* @param: int offsetX x����ƫ��
* @returns:   void
*/
void CLFW20170614Dlg::drawXY(CDC *pDC, int width, int height, int xUnits, int yUnits, int offsetX)
{
    int orginOffset = 30;
    int margin = 5;

    //���ƺ���������
    pDC->MoveTo(orginOffset, margin);
    pDC->LineTo(orginOffset, height - orginOffset - margin);
    pDC->LineTo(width - margin, height - orginOffset - margin);

    //���ƺ����ͷ.
    pDC->MoveTo(width - margin - margin, height - orginOffset - margin - margin);
    pDC->LineTo(width - margin, height - orginOffset - margin);
    pDC->LineTo(width - margin - margin, height - orginOffset);

    //�����������ͷ
    pDC->MoveTo(orginOffset - margin, margin + margin);
    pDC->LineTo(orginOffset, margin);
    pDC->LineTo(orginOffset + margin, margin + margin);

    width -= orginOffset + margin;
    height -= orginOffset + margin;


    pDC->SetBkMode(TRANSPARENT);
    //����x����---ÿ10������Ϊ100ms
    for(int x = 10 + offsetX; x < width - offsetX; x += 10)
    {
        int addx = (((x - offsetX) % 100) == 0) ? margin : 0;
        if(x  + orginOffset < orginOffset)
        {
            continue;
        }
        pDC->MoveTo(x + orginOffset , height);
        pDC->LineTo(x + orginOffset, height - margin - addx);

        if(addx > 0)
        {
            CString tStr;
            tStr.Format(TEXT("%d"), (x - offsetX) / 10);
            CRect rcArea ;
            pDC->DrawText(tStr, &rcArea, DT_CENTER | DT_CALCRECT);
            rcArea.OffsetRect(x + orginOffset - rcArea.Width() / 2, height);
            pDC->DrawText(tStr, &rcArea, DT_CENTER);
        }

    }

    int val = yUnits - xUnits;
    if(val == 0)
    {
        val = 1;
    }
    if(val > height)
    {
        val = height;
    }

    double perPixel = (double)val / (double)height;

    //����y����----�������ֵ,��Сֵ���㵥λ
    for(int y = 10; y < height; y += 10)
    {
        int addy = ((y % 100) == 0) ? margin : 0;
        pDC->MoveTo(orginOffset,  height - y);
        pDC->LineTo(orginOffset + margin + addy, height - y);

        if(addy > 0)
        {
            CString tStr;
            tStr.Format(TEXT("%d"), (int)(y * perPixel));
            CRect rcArea ;
            pDC->DrawText(tStr, &rcArea, DT_CENTER | DT_CALCRECT);
            rcArea.OffsetRect(orginOffset - rcArea.Width(), height - y - rcArea.Height() / 2);
            pDC->DrawText(tStr, &rcArea, DT_CENTER);
        }
    }

}


void CLFW20170614Dlg::drawCurve()
{
    CWnd *pWnd = GetDlgItem(IDC_STATIC_CURVE);
    CRect rcWnd;
    pWnd->GetClientRect(&rcWnd);
    CDC *pDC = pWnd -> GetDC();

    CDC cdc;
    cdc.CreateCompatibleDC(pDC);

    CBitmap bmp;
    bmp.CreateCompatibleBitmap(pDC, rcWnd.Width(), rcWnd.Height());
    CBitmap *pOld = cdc.SelectObject(&bmp);
    //���Ʊ���
    cdc.FillSolidRect(0, 0, rcWnd.Width(), rcWnd.Height(), RGB(0xF0, 0xF0, 0xF0));

    //��������
    drawXY(&cdc , rcWnd.Width(), rcWnd.Height(), 0, 200, mOffsetX);

    //��������
    CCurve cu;
    cu.setParam(rcWnd.Width(), rcWnd.Height(), 10, 0, 200, 0xFFFF0000);

    srand(GetTickCount());
    for(int i = 0; i < 400; ++i)
    {
        cu.add(i + 2);
    }

    cu.DrawCure(&cdc, mOffsetX);

    pDC->BitBlt(0, 0, rcWnd.Width(), rcWnd.Height(), &cdc, 0, 0, SRCCOPY);

    cdc.SelectObject(pOld);

    pWnd->ReleaseDC(pDC);
}


void CLFW20170614Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    CWnd *pWnd = GetDlgItem(IDC_STATIC_CURVE);
    CRect rcWnd;
    pWnd->GetWindowRect(&rcWnd);
    ScreenToClient(&rcWnd);
    if(rcWnd.PtInRect(point))
    {
        mIsCapture = TRUE;
        mLastPoint = point;
        mLastOffsetX = mOffsetX;
        SetCapture();
    }
    __super::OnLButtonDown(nFlags, point);
}


void CLFW20170614Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    if(mIsCapture)
    {
        mIsCapture = FALSE;
        ReleaseCapture();
    }
    __super::OnLButtonUp(nFlags, point);
}


void CLFW20170614Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    if(mIsCapture)
    {
        mOffsetX =  mLastOffsetX +  point.x - mLastPoint.x ;
        if(mOffsetX > 0)
        {
            mOffsetX = 0;
        }
        drawCurve();
    }
    __super::OnMouseMove(nFlags, point);
}
