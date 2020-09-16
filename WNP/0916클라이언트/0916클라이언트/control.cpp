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
//=========================클라이언트->서버
//회원가입 기능
void con_netmember()
{
	MEMBER  mem;

	printf(">> 아이디 : ");
	gets_s(mem.id, sizeof(mem.id));

	printf(">> 패스워드 : ");
	gets_s(mem.pw, sizeof(mem.pw));

	printf(">> 이름 : ");
	gets_s(mem.name, sizeof(mem.name));

	printf(">> 나이 : ");
	scanf_s("%d", &mem.age);

	getchar();

	//서버로 전송
	pack_SetNewMember(&mem);
	sock_Send((char*)&mem, sizeof(mem));

	printf("서버로 회원가입 정보를 보냈습니다.\n");
}

void con_login()
{
	LOGIN  login;

	printf(">> 아이디 : ");
	gets_s(login.id, sizeof(login.id));

	printf(">> 패스워드 : ");
	gets_s(login.pw_name, sizeof(login.pw_name));

	//서버로 전송
	pack_SetLogin(&login);
	sock_Send((char*)&login, sizeof(login));

	printf("서버로 회원가입 정보를 보냈습니다.\n");
}

void con_logout()
{
	LOGIN  login;

	printf(">> 아이디 : ");
	gets_s(login.id, sizeof(login.id));


	//서버로 전송
	pack_SetLogout(&login);
	sock_Send((char*)&login, sizeof(login));

}

void con_delete()
{
	LOGIN  delmem;

	printf(">> 아이디 : ");
	gets_s(delmem.id, sizeof(delmem.id));
	
	//서버로 전송
	pack_SetDeleteMember(&delmem);
	sock_Send((char*)&delmem, sizeof(delmem));
}
//===================서버-> 클라이언트
void con_RecvData(char* buf)
{
	int* flag=(int*)buf;
	if (*flag == ACK_NEWMEMBER_S)
	{
		MessageBox(0, TEXT("회원가입성공"), TEXT("알림"), MB_OK);
	}
	else if(*flag == ACK_NEWMEMBER_F)
	{
		MEMBER* pmem = (MEMBER*)buf;
		pmem->name;//print로는 나오는데 메세지 박스는 안나온다
		MessageBox(0, TEXT("회원가입실패"), TEXT("알림"), MB_OK);
	}
	else if (*flag == ACK_LOGIN_S)
	{
		LOGIN* pmem = (LOGIN*)buf;
		 CString name;
		 name = pmem->pw_name;//c 스트링을 통해서 형변환
		MessageBox(0,name+TEXT("님 로그인 성공"), TEXT("알림"), MB_OK);
	}
	else if (*flag == ACK_LOGIN_F)
	{
		LOGIN* pmem = (LOGIN*)buf;
		MessageBox(0, TEXT("로그인 실패"), TEXT("알림"), MB_OK);
	}
	else if (*flag == ACK_DELETEMEMBER_S)
	{
		LOGIN* pmem = (LOGIN*)buf;
		CString name;
		name = pmem->pw_name;//c 스트링을 통해서 형변환
		MessageBox(0,name+TEXT("님 정보 삭제 성공"), TEXT("알림"), MB_OK);
	}
	else if (*flag == ACK_DELETEMEMBER_F)
	{
		LOGIN* pmem = (LOGIN*)buf;
		MessageBox(0, TEXT("삭제 실패"), TEXT("알림"), MB_OK);
	}
}