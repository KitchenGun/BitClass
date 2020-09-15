//쓰레드를 사용한 다중 접속 서부 구현
#include <stdio.h>
#include <WinSock2.h>	
#pragma comment(lib, "ws2_32.lib")  
#include <ws2tcpip.h>
#include<process.h>//thread 선언부

#define SERVER_PORT		9000

void sock_LibInit();
void sock_LibExit();
void sock_CreateSocket();

unsigned int __stdcall sock_ListenThread(void* value);
unsigned int __stdcall sock_WorkThread(void* value);

SOCKET sock_Accept(SOCKADDR_IN* addr);
int sock_Recv(SOCKET sock, SOCKADDR_IN clientaddr, char* buf);
int sock_Send(SOCKET sock, const char* buf);
void sock_DisplayMessage();


SOCKET listen_socket = 0;

int main()
{
	sock_LibInit();

	//1. 소켓 생성, 주소셋팅, 연결
	sock_CreateSocket();

	//2.sock_ListenThread 생성 접속 처리 역할
	unsigned int  hthread = _beginthreadex(0, 0, sock_ListenThread, 0, 0, 0);

	
	//3. sock_ListenThread
	WaitForSingleObject((HANDLE)hthread, INFINITE);
	CloseHandle((HANDLE)hthread);
	sock_LibExit();

	return 0;
}

void sock_LibInit()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패!\n");
		exit(0);	//프로그램 종료
	}
}

void sock_LibExit()
{
	WSACleanup();
}

void sock_CreateSocket()
{
	//1. 소켓 생성 
	listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listen_socket == INVALID_SOCKET)
	{
		sock_DisplayMessage();
		exit(0);
	}

	//2. 주소 연결
	int retval;

	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr)); //1번째인자의 주소부터 2번째 인자크기
												 // 모든 바이트를 0으로 초기화

	serveraddr.sin_family = AF_INET;				//주소체계
	serveraddr.sin_port = htons(SERVER_PORT);	//지역포트번호
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);	//지역IP 주소

	retval = bind(listen_socket, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		sock_DisplayMessage();
		exit(0);
	}


	//3. 연결
	//접속대기 큐의 크기 : TCP 상태를 LISTENING 변경
	retval = listen(listen_socket, SOMAXCONN);
	// 
	if (retval == SOCKET_ERROR)
	{
		sock_DisplayMessage();
		exit(0);
	}
}

SOCKET sock_Accept(SOCKADDR_IN* addr)
{
	SOCKADDR_IN clientaddr;
	int addrlen = sizeof(clientaddr);		//반드시 초기화... 

											//1. 접속 처리 
	printf("서버 실행 중이다(61.81.98.100:9000).....\n");
	SOCKET sock = accept(listen_socket, (SOCKADDR*)&clientaddr, &addrlen);
	if (sock == SOCKET_ERROR)
	{
		sock_DisplayMessage();
		exit(0);
	}
	*addr = clientaddr;		//주소값 복사.<==================================
	//2. 접속 결과 출력
	//inset_ntoa : 숫자 -> 문자열로 변환(네트웤바이트오더->호스트바이트오더)
	char buf[50];
	inet_ntop(AF_INET, &clientaddr.sin_addr, buf, sizeof(buf));

	printf("===================================================================\n");
	//	printf("클라이언트 접속: %s:%d\n",
	//		inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
	printf("클라이언트 접속: %s:%d\n", buf, ntohs(clientaddr.sin_port));
	printf("===================================================================\n");

	return sock;
}

int sock_Recv(SOCKET sock, SOCKADDR_IN clientaddr, char* buf)
{
	int retval;
	int buf_size = 1024;

	retval = recv(sock, buf, buf_size, 0);
	if (retval == SOCKET_ERROR) // -1
	{
		sock_DisplayMessage();
		return 0;
	}
	else if (retval == 0)
	{
		sock_DisplayMessage();
		return 0;
	}
	else
	{
		//retval :  모든 IO는 반환값이 IO결과 byte 크기이다. 
		// 받은 데이터 출력=============================================
		char buf1[50];
		inet_ntop(AF_INET, &clientaddr.sin_addr, buf1, sizeof(buf1));

		buf[retval] = '\0';
		printf("[%s:%d] %s\n", buf1, ntohs(clientaddr.sin_port), buf);
		//==================================================================
		return 1;
	}
}

int sock_Send(SOCKET sock, const char* buf)
{
	// 서버에 데이터 보내기
	int retval = send(sock, buf, strlen(buf), 0);
	if (retval == SOCKET_ERROR)
	{
		printf("전송 오류 : 클라언트가 죽었을때\n");
		return 0;
	}
	printf("%d바이트를 전송, %s\n", retval, buf);
	return retval;
}

void sock_DisplayMessage()
{
	LPVOID pMsg;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | // 오류 메시지 저장 메모리를 내부에서 할당하라
		FORMAT_MESSAGE_FROM_SYSTEM, //운영체제로 부터 오류 메시지를 가져온다
		NULL,
		WSAGetLastError(), //오류 코드
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), //언어(제어판 설정 언어)
		(LPTSTR)&pMsg, // 오류 메시지 outparam : 유니코드 
		0, NULL);
	//================== 유니코드 -> 멀티바이트 ================================
	char wtoa[250];
	WideCharToMultiByte(CP_ACP, 0, (LPCWCH)pMsg, -1, wtoa, 250, NULL, NULL);
	//==========================================================================
	printf("%s\n", wtoa);// 오류 메시지 출력 : 멀티바이트 
	LocalFree(pMsg); // 오류 메시지 저장 메모리 반환
}

unsigned int __stdcall sock_ListenThread(void* value)
{
	SOCKET sock;
	SOCKADDR_IN clientaddr;
	while (true)
	{
		sock = sock_Accept(&clientaddr);

		//통신 thread 생성
		unsigned int  hthread = _beginthreadex(0, 0, sock_WorkThread, (void*)sock, 0, 0);
		CloseHandle((HANDLE)hthread);
	}
	return 0;
}

unsigned int __stdcall sock_WorkThread(void* value)
{
	SOCKET sock = (SOCKET)value;
	//연결소켓이 있으면 socket을 통해서 상대방과 나의 주소를 얻을 수 있다.
	//getpeername상대방, getsockname 자신
	SOCKADDR_IN clientaddr;
	int length = sizeof(clientaddr);
	getpeername(sock, (SOCKADDR*)&clientaddr, &length);

	char buf[1024];//수신 버퍼 & 송신 버퍼 
	//2. 대화(recv)	

	while (true)
	{
		// 데이터 받기====================================================
		if (sock_Recv(sock, clientaddr, buf) == 0)
			break;

		//받은 데이터를 전송==============================================
		sock_Send(sock, buf);
	}

	//3. 종료처리
	closesocket(sock);				//통신소켓
									//송신

	return 0;
}