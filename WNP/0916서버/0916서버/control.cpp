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
	printf("서버 실행 중이다(61.81.98.100:9000).....\n");
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

//클라이언트에서 보낸 데이터 
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
	//예외처리
	for (int i = 0; i < (int)g_memlist.size(); i++)
	{
		memberdata mem = g_memlist[i];
		if (strcmp(mem.id, pmem->id) == 0)
		{
			strcpy_s(pmem->name, sizeof(pmem->name), "중복 아이디");
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

	//응답 메세지를 만들어 전송 처리 시작점 
	//회원 가입 요청에 대한 응답 패킷은 클라이언트가 보낸 정보가 그대로 담겨있고 flag 만 변경함
	pmem->flag = ACK_NEWMEMBER_S;
	PrintMemberList();	//<================= 결과 확인
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
			PrintMemberList();//=======결과 확인
			//로그인 성공 패킷을 생성해서 클라이언트에 전송#define으로 정의 했음
			//plogin->pw_name여기에 로그인 한 사람 이름 저장 
			return;
		}
		else
		{
			++count;
			if (count == (int)g_memlist.size())
			{
				plogin->flag = ACK_LOGIN_F;
				//로그인 실패 패킷을 생성
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
			PrintMemberList();//결과 확인
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
			//저장소에서 삭제
			vector<memberdata>::iterator itr = g_memlist.begin();
			g_memlist.erase(itr + i);
			plogin->flag = ACK_DELETEMEMBER_S;
			strcpy_s(plogin->pw_name, sizeof(plogin->pw_name), mem.name);
			PrintMemberList();//결과 확인
			return;
		}
	}

	plogin->flag = ACK_DELETEMEMBER_F;
	return;
}