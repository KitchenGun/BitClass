//control.cpp

#include "std.h"
#define DB_ID TEXT("kang")
#define DB_PW TEXT("keon")


void con_init()
{
	sock_LibInit();
	sock_CreateSocket();
	if (wb_DBConnect(DB_ID, DB_PW) == FALSE)
	{
		printf("DB 연결 오류\n");
		exit(0);
	}
	printf("DB연결 성공\n\n");
}

void con_run()
{
	printf("서버 실행 중이다.....\n");
	unsigned int hthread = _beginthreadex(0, 0, sock_ListenThread, 0, 0, 0);

	WaitForSingleObject((HANDLE)hthread, INFINITE);
	CloseHandle((HANDLE)hthread);
}

void con_exit()
{
	sock_LibExit();
}

//클라이언트에서 보낸 데이터 -=============================
void con_RecvData(char* buf, int *size)
{	
	int *flag = (int*)buf;	//????
	if (*flag == PACK_INSERTACCOUNT)
	{
		RecvInsertAccount((PACK_ACCOUNTINFO*)buf);
		*size = sizeof(PACK_ACCOUNTINFO);
	}
	//else if (*flag == PACK_LOGIN)
	//{
	//	RecvLogin((LOGIN*)buf);
	//	*size = sizeof(LOGIN);
	//}
	//else if (*flag == PACK_LOGOUT)
	//{
	//	RecvLogOut((LOGIN*)buf);
	//	*size = sizeof(LOGIN);
	//}
}


void RecvInsertAccount(PACK_ACCOUNTINFO* accinfo)
{
	//데이터 획득
	ACCOUNT acc;
	_tcscpy_s(acc.name, _countof(acc.name), accinfo->name);
	acc.balance = accinfo->balance;
	//db저장
	//성공실패 발생  응답패킷 전송 
	if (wb_dbInsertAccout(&acc) == TRUE)
	{

	}
	else
	{

	}

	//클라로 전송
}
