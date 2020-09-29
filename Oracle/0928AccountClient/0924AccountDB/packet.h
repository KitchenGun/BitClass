//packet.h
#pragma once


//Ŭ���̾�Ʈ -> ����
#define PACK_INSERTACCOUNT		1	//���� ����
#define PACK_SELECTNAMETOID		2	//�̸����� ���� ��ȣ �˻�
#define PACK_SELECTACCOUNT		3
//���� -> Ŭ���̾�Ʈ
#define ACK_INSERTACCOUNT_S		51	
#define ACK_INSERTACCOUNT_F		52
#define ACK_SELECTNAMETOID_S	53
#define ACK_SELECTNAMETOID_F	54
#define ACK_SELECTACCOUNT_S		55
#define ACK_SELECTACCOUNT_F		56

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


PACK_ACCOUNTINFO pack_SetInsertAccount(const ACCOUNT *pacc);
PACK_ACCOUNTINFO pack_SetSelectAccount(int id);

//�̸����� ID�˻�//[Ŭ���̾�Ʈ] : flag, name//[����]       : flag(u), name, count(n), id(n)

typedef struct tagPACK_GETNAME
{
	int flag;
	int id[50];//���� id ����
	TCHAR name[20];
	int count;//���� ���� ����
	SYSTEMTIME stime;
}PACK_GETNAME;

PACK_GETNAME pack_SetSelectNameToId(TCHAR* name);


