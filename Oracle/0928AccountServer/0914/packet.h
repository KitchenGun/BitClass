#pragma once
//클라이언트 -> 서버
#define PACK_INSERTACCOUNT		1	//계좌 생성



//서버 -> 클라이언트
#define ACK_INSERTACCOUNT_S		51
#define ACK_INSERTACCOUNT_F		52



//패킷 구조체
//계좌 생성 : flag, name, balance 
//            ==> flag(u), id(n), name, balance, stime(n)
typedef struct tagPACK_ACCOUNTINFO
{
	int flag;
	int id;
	TCHAR name[20];
	int balance;
	SYSTEMTIME stime;
}PACK_ACCOUNTINFO;

PACK_ACCOUNTINFO pack_SetInsertAccount(const ACCOUNT* pacc);
