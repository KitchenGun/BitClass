#pragma once
//Ŭ���̾�Ʈ -> ����
#define PACK_INSERTACCOUNT		1	//���� ����



//���� -> Ŭ���̾�Ʈ
#define ACK_INSERTACCOUNT_S		51
#define ACK_INSERTACCOUNT_F		52



//��Ŷ ����ü
//���� ���� : flag, name, balance 
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
