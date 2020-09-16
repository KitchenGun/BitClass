//control.cpp

#include "std.h"

void con_init()
{
	sock_LibInit();
	sock_CreateSocket();
}

void con_exit()
{
	sock_LibExit();
}
//=========================Ŭ���̾�Ʈ->����
//ȸ������ ���
void con_netmember()
{
	MEMBER  mem;

	printf(">> ���̵� : ");
	gets_s(mem.id, sizeof(mem.id));

	printf(">> �н����� : ");
	gets_s(mem.pw, sizeof(mem.pw));

	printf(">> �̸� : ");
	gets_s(mem.name, sizeof(mem.name));

	printf(">> ���� : ");
	scanf_s("%d", &mem.age);

	getchar();

	//������ ����
	pack_SetNewMember(&mem);
	sock_Send((char*)&mem, sizeof(mem));

	printf("������ ȸ������ ������ ���½��ϴ�.\n");
}

void con_login()
{
	LOGIN  login;

	printf(">> ���̵� : ");
	gets_s(login.id, sizeof(login.id));

	printf(">> �н����� : ");
	gets_s(login.pw_name, sizeof(login.pw_name));

	//������ ����
	pack_SetLogin(&login);
	sock_Send((char*)&login, sizeof(login));

	printf("������ ȸ������ ������ ���½��ϴ�.\n");
}

void con_logout()
{
	LOGIN  login;

	printf(">> ���̵� : ");
	gets_s(login.id, sizeof(login.id));


	//������ ����
	pack_SetLogout(&login);
	sock_Send((char*)&login, sizeof(login));

}

void con_delete()
{
	LOGIN  delmem;

	printf(">> ���̵� : ");
	gets_s(delmem.id, sizeof(delmem.id));
	
	//������ ����
	pack_SetDeleteMember(&delmem);
	sock_Send((char*)&delmem, sizeof(delmem));
}
//===================����-> Ŭ���̾�Ʈ
void con_RecvData(char* buf)
{
	int* flag=(int*)buf;
	if (*flag == ACK_NEWMEMBER_S)
	{
		MessageBox(0, TEXT("ȸ�����Լ���"), TEXT("�˸�"), MB_OK);
	}
	else if(*flag == ACK_NEWMEMBER_F)
	{
		MEMBER* pmem = (MEMBER*)buf;
		pmem->name;//print�δ� �����µ� �޼��� �ڽ��� �ȳ��´�
		MessageBox(0, TEXT("ȸ�����Խ���"), TEXT("�˸�"), MB_OK);
	}
	else if (*flag == ACK_LOGIN_S)
	{
		LOGIN* pmem = (LOGIN*)buf;
		 CString name;
		 name = pmem->pw_name;//c ��Ʈ���� ���ؼ� ����ȯ
		MessageBox(0,name+TEXT("�� �α��� ����"), TEXT("�˸�"), MB_OK);
	}
	else if (*flag == ACK_LOGIN_F)
	{
		LOGIN* pmem = (LOGIN*)buf;
		MessageBox(0, TEXT("�α��� ����"), TEXT("�˸�"), MB_OK);
	}
	else if (*flag == ACK_DELETEMEMBER_S)
	{
		LOGIN* pmem = (LOGIN*)buf;
		CString name;
		name = pmem->pw_name;//c ��Ʈ���� ���ؼ� ����ȯ
		MessageBox(0,name+TEXT("�� ���� ���� ����"), TEXT("�˸�"), MB_OK);
	}
	else if (*flag == ACK_DELETEMEMBER_F)
	{
		LOGIN* pmem = (LOGIN*)buf;
		MessageBox(0, TEXT("���� ����"), TEXT("�˸�"), MB_OK);
	}
}