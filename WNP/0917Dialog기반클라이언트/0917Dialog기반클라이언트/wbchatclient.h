#pragma once
//wbchatclient.h
//로그인 성공시 chat 서버 접속
//언제 control 함수
//누구 호출 wbchatclinet함수//sockc_CreateSocket함수


void sockc_CreateSocket();//내부에서 recv thread 호출
int sockc_Send(char* buf, int length);

int CRecv(SOCKET sock, char* buf);
int crecvn(SOCKET s, char* buf, int len, int flags);
unsigned int __stdcall CRecvThread(void* value);

void sockc_Close();
