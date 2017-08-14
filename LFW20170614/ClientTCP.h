#pragma once
#include "ThreadBase.h"
#include "SocketTCP.h"

//�¼�������
class OnClientListener
{
public:
    virtual void onConnect(BOOL bSuccess) = 0; //�����¼�
    virtual void onRecv(const char *pBuf, int len) = 0; //���ݽ����¼�
    virtual void onDisconnect() = 0; //���ӶϿ��¼�
};

//�ͻ��˹�����
class CClientTCP: public CThreadBase
{
protected:
    CStringA mServerIP; //������IP
    int mServerPort; //�������˿�
    CSocketTCP mSock; //tcp socket��װ��
    OnClientListener *mpListener; //�¼�������ָ��
public:
    CClientTCP(void);
    ~CClientTCP(void);
    void setListener(OnClientListener *pListener); //�����¼�������ָ��
    void setServer(LPCTSTR strServerIP, int serverPort); //���÷�������Ϣ

    //ֹͣ/�Ͽ������������
    virtual void stop();

    //�Ͽ����������
    virtual void after();

    //�߳��еĹ�������
    virtual void run();

    //��������������ݵĺ���
    int send(const void *pBuf, int len);

};

