#pragma once
//wbclient.h

/*1. �ʱ�ȭ �������� �Ʒ� �Լ� ȣ��(ex : void con_Init(HWND hDlg))   sock_LibInit();2. ���� �������� �Ʒ� �Լ� ȣ��(ex : void con_Cancel(HWND hDlg))   sock_LibExit();3. ���� ���� ��û �Լ� ȣ��   sock_CreateSocket();--------------------------------------------------------------4. ������ ���۽� ȣ��   int sock_Send(char *buf, int length);5. ���� ���� ��û   sock_Close()6. ������ ���Ž� ó��(���� ������ ��ġ�� �Լ��� ����)	void con_RecvData(TCHAR *buf)	{	int *flag = (int*)buf;	if (*flag == ACK_NEWMEMBER_S)	{	MessageBox(0, TEXT("ȸ�����Լ���"), TEXT("�˸�"), MB_OK);	}	else if (*flag == ACK_NEWMEMBER_F)	{	MEMBER *pmem = (MEMBER*)buf;	//pmem->name	MessageBox(0, TEXT("ȸ�����Խ���"), TEXT("�˸�"), MB_OK);	}*/

void sock_Close();
void sock_LibInit();
void sock_LibExit();

void sock_CreateSocket();//���ο��� recv thread ȣ��
int sock_Send(char* buf, int length);

int Recv(SOCKET sock, char* buf);
int recvn(SOCKET s, char* buf, int len, int flags);
unsigned int __stdcall RecvThread(void* value);
