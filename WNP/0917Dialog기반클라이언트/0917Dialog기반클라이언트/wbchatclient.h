#pragma once
//wbchatclient.h
//�α��� ������ chat ���� ����
//���� control �Լ�
//���� ȣ�� wbchatclinet�Լ�//sockc_CreateSocket�Լ�


void sockc_CreateSocket();//���ο��� recv thread ȣ��
int sockc_Send(char* buf, int length);

int CRecv(SOCKET sock, char* buf);
int crecvn(SOCKET s, char* buf, int len, int flags);
unsigned int __stdcall CRecvThread(void* value);

void sockc_Close();
