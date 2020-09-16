//control.cpp
#include "std.h"

vector<memberdata> g_memlist;

void con_init()
{
	sock_LibInit();
	sock_CreateSocket();
}

void con_run()
{
	printf("���� ���� ���̴�(61.81.98.100:9000).....\n");
	unsigned int hthread = _beginthreadex(0, 0, sock_ListenThread, 0, 0, 0);

	WaitForSingleObject((HANDLE)hthread, INFINITE);
	CloseHandle((HANDLE)hthread);
}

void con_exit()
{
	sock_LibExit();
}

void PrintMemberList()
{
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < (int)g_memlist.size(); i++)
	{
		memberdata mem = g_memlist[i];
		printf("[%s] %s\t%s\t%s\t%d\n",mem.islogin ? "0" : "X",
			mem.id, mem.pw, mem.name, mem.age);
	}
	printf("-------------------------------------------------------------\n");
}

//Ŭ���̾�Ʈ���� ���� ������ 
void con_RecvData(char* buf,int* size)
{
	int* flag = (int*)buf;	
	if (*flag == PACK_NEWMEMBER)
	{
		RecvNewMember((MEMBER*)buf);
		*size = sizeof(MEMBER);
	}
	else if (*flag == PACK_LOGIN)
	{
		RecvLogin((LOGIN*)buf);
		*size = sizeof(LOGIN);
	}
	else if (*flag == PACK_LOGOUT)
	{
		RecvLogout((LOGIN*)buf);
		*size = sizeof(LOGIN);
	}
	else if (*flag == PACK_DELETEMEMBER)
	{
		RecvDelMember((LOGIN*)buf);
		*size = sizeof(LOGIN);
	}
}

void RecvNewMember(MEMBER* pmem)
{
	int count = 0;
	//����ó��
	for (int i = 0; i < (int)g_memlist.size(); i++)
	{
		memberdata mem = g_memlist[i];
		if (strcmp(mem.id, pmem->id) == 0)
		{
			strcpy_s(pmem->name, sizeof(pmem->name), "�ߺ� ���̵�");
			pmem->flag = ACK_NEWMEMBER_F;
			return;
		}
	}
	memberdata mem;
	strcpy_s(mem.id, sizeof(mem.id), pmem->id);
	strcpy_s(mem.pw, sizeof(mem.pw), pmem->pw);
	strcpy_s(mem.name, sizeof(mem.name), pmem->name);
	mem.age = pmem->age;
	mem.islogin = false;
	g_memlist.push_back(mem);

	//���� �޼����� ����� ���� ó�� ������ 
	//ȸ�� ���� ��û�� ���� ���� ��Ŷ�� Ŭ���̾�Ʈ�� ���� ������ �״�� ����ְ� flag �� ������
	pmem->flag = ACK_NEWMEMBER_S;
	PrintMemberList();	//<================= ��� Ȯ��
}

void RecvLogin(LOGIN* plogin)
{
	int count = 0;
	for (int i = 0; i < (int)g_memlist.size(); i++)
	{
		memberdata mem = g_memlist[i];
		if (strcmp(mem.id, plogin->id) == 0 && strcmp(mem.pw, plogin->pw_name) == 0)
		{
			g_memlist[i].islogin = true;
			plogin->flag = ACK_LOGIN_S;
			strcpy_s(plogin->pw_name,sizeof(plogin->pw_name),mem.name);
			PrintMemberList();//=======��� Ȯ��
			//�α��� ���� ��Ŷ�� �����ؼ� Ŭ���̾�Ʈ�� ����#define���� ���� ����
			//plogin->pw_name���⿡ �α��� �� ��� �̸� ���� 
			return;
		}
		else
		{
			++count;
			if (count == (int)g_memlist.size())
			{
				plogin->flag = ACK_LOGIN_F;
				//�α��� ���� ��Ŷ�� ����
			}
		}
	}
}

void RecvLogout(LOGIN* plogin)
{
	for (int i = 0; i < (int)g_memlist.size(); i++)
	{
		memberdata mem = g_memlist[i];
		if (strcmp(mem.id, plogin->id) == 0)
		{
			g_memlist[i].islogin = false;
			PrintMemberList();//��� Ȯ��
			return;
		}
	}
}

void RecvDelMember(LOGIN* plogin)
{
	int count = 0;
	for (int i = 0; i < (int)g_memlist.size(); i++)
	{
		memberdata mem = g_memlist[i];
		if (strcmp(mem.id, plogin->id) == 0)
		{
			//����ҿ��� ����
			vector<memberdata>::iterator itr = g_memlist.begin();
			g_memlist.erase(itr + i);
			plogin->flag = ACK_DELETEMEMBER_S;
			strcpy_s(plogin->pw_name, sizeof(plogin->pw_name), mem.name);
			PrintMemberList();//��� Ȯ��
			return;
		}
	}

	plogin->flag = ACK_DELETEMEMBER_F;
	return;
}