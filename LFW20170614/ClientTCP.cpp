#include "stdafx.h"
#include "ClientTCP.h"


CClientTCP::CClientTCP(void)
{
    mpListener = nullptr;
    mServerPort = 0;
    mIsSelfDelete = FALSE;
}


CClientTCP::~CClientTCP(void)
{
}

void CClientTCP::setListener(OnClientListener *pListener)
{
    mpListener = pListener;
}

void CClientTCP::setServer(LPCTSTR strServerIP, int serverPort)
{
    mServerIP = strServerIP;
    mServerPort = serverPort;
}

void CClientTCP::stop()
{
    __super::stop();
    mSock.close(); //�ͷ�tcp socket
    mSock.create();
}

void CClientTCP::after()
{
    mSock.close();  //�ͷ�tcp socket
    mSock.create();
}

void CClientTCP::run()
{
    printLog(TEXT("client begin recv thread\n"));
    //���ӷ�����
    if(mSock.connect(mServerIP, mServerPort, 5000) == false)
    {
        printLog(TEXT("����ʧ��\n"));
        if(mpListener)
        {
            mpListener->onConnect(FALSE); //����ʧ��, ����ʧ���¼�֪ͨ
        }
        return;
    }
    printLog(TEXT("���ӳɹ�\n"));
    if(mpListener)
    {
        mpListener->onConnect(TRUE); //�������ӳɹ��¼�
    }

    int ret = 0;
    char buf[0x100] = {0};
    while(mIsRun)
    {
        ret = mSock.recv(buf, 14); //ÿ�ν���14�ֽ�
        if(ret < 1) //ʧ��, ��������
        {
            printLog(TEXT("����ʧ��\n"));
            break;
        }
        if(mpListener)
        {
            mpListener->onRecv(buf, ret); //���ճɹ�, �������ݽ����¼�.
        }
    }

    printLog(TEXT("�Ͽ�����\n"));
    if(mpListener)
    {
        mpListener->onDisconnect();//�����Ͽ������¼�.
    }
}

int CClientTCP::send(const void *pBuf, int len)
{
    return mSock.send(pBuf, len);//�����˷�������
}
