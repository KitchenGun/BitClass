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
		printf("DB ���� ����\n");
		exit(0);
	}
	printf("DB���� ����\n\n");
}

void con_run()
{
	printf("���� ���� ���̴�.....\n");
	unsigned int hthread = _beginthreadex(0, 0, sock_ListenThread, 0, 0, 0);

	WaitForSingleObject((HANDLE)hthread, INFINITE);
	CloseHandle((HANDLE)hthread);
}

void con_exit()
{
	sock_LibExit();
}

//Ŭ���̾�Ʈ���� ���� ������ -=============================
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
	//������ ȹ��
	ACCOUNT acc;
	_tcscpy_s(acc.name, _countof(acc.name), accinfo->name);
	acc.balance = accinfo->balance;
	//db����
	//�������� �߻�  ������Ŷ ���� 
	if (wb_dbInsertAccout(&acc) == TRUE)
	{

	}
	else
	{

	}

	//Ŭ��� ����
}
