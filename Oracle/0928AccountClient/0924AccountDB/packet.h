//packet.h
#pragma once


//클라이언트 -> 서버
#define PACK_INSERTACCOUNT		1	//계좌 생성
#define PACK_SELECTNAMETOID		2	//이름으로 계좌 번호 검색
#define PACK_SELECTACCOUNT		3
//서버 -> 클라이언트
#define ACK_INSERTACCOUNT_S		51	
#define ACK_INSERTACCOUNT_F		52
#define ACK_SELECTNAMETOID_S	53
#define ACK_SELECTNAMETOID_F	54
#define ACK_SELECTACCOUNT_S		55
#define ACK_SELECTACCOUNT_F		56

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


PACK_ACCOUNTINFO pack_SetInsertAccount(const ACCOUNT *pacc);
PACK_ACCOUNTINFO pack_SetSelectAccount(int id);

//이름으로 ID검색//[클라이언트] : flag, name//[서버]       : flag(u), name, count(n), id(n)

typedef struct tagPACK_GETNAME
{
	int flag;
	int id[50];//계좌 id 저장
	TCHAR name[20];
	int count;//계좌 생성 갯수
	SYSTEMTIME stime;
}PACK_GETNAME;

PACK_GETNAME pack_SetSelectNameToId(TCHAR* name);


