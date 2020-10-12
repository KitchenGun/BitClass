//wbserver.h
#pragma once
#ifdef DLL_SOURCE
#define DLLFUNC __declspec(dllexport) 
#else
#define DLLFUNC __declspec(dllimport)
#endif

//1.함수 포인터 타입 선언
typedef void (*RECVFUN)(char* buf, int* size);

extern "C" DLLFUNC void sock_LibInit();
extern "C" DLLFUNC void sock_LibExit();

extern "C" DLLFUNC void sock_CreateSocket(RECVFUN fun);

extern "C" DLLFUNC unsigned int __stdcall sock_ListenThread(void * value);
unsigned int __stdcall WorkThread(void * value);

int Recv(SOCKET sock, SOCKADDR_IN clientaddr, char* buf);
int Send(SOCKET sock, const char* buf, int datasize);
int recvn(SOCKET s, char *buf, int len, int flags);

SOCKET Accept(SOCKADDR_IN *addr);
void DisplayMessage();


