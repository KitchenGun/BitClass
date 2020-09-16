//wbclient.h
#pragma once

void sock_LibInit();
void sock_LibExit();

void sock_CreateSocket();//내부에서 recv thread 호출
int sock_Send(char *buf, int length);

int Recv(SOCKET sock, char* buf);
int recvn(SOCKET s, char* buf, int len, int flags);
unsigned int __stdcall RecvThread(void* value);
