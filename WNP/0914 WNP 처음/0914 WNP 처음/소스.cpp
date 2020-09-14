#pragma comment(lib, "ws2_32.lib")//소켓 라이브러리 구현부의 정보 파일 연결
#define _WINSOCK_DEPRECATED_NO_WARNINGS//2019 버전은 필요
#include <stdio.h>
#include <WinSock2.h>//소켓 라이브러리의 h

void exam1();
void exam2();
void exam3();

int main()
{
	exam3();
	return 0;
}

//01_소켓 라이브러리
void exam1()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패!\n");
		return;
	}

	printf("윈도우 소켓 초기화 성공!\n");
	WSACleanup();
}
//02_주소 변환 정수형(0x81998161 -> pc or  소켓 api) <-> 문자열 (문자열 : 61.81.99.81->사용자)
// inet_addr() : 문자열주소 -> 정수형 주소 
// inet_ntoa() : 정수형주소 -> 문자열 주소 
void exam2()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패!\n");
		return;
	}

	// 문자열 주소 출력
	char* ipaddr = "230.200.12.5";
	printf("IP 문자열 주소 : %s\n", ipaddr);
	// 문자열 주소를 4byte 정수로 변환
	printf("IP 문자열 주소 = > 정수 = 0x%08X\n", inet_addr(ipaddr));

	// 4byte 정수를 문자열 주소로 변환
	IN_ADDR in_addr;
	in_addr.s_addr = inet_addr(ipaddr);
	printf("IP 정수 => 문자열 주소 = %s\n", inet_ntoa(in_addr));
	WSACleanup();
}

//03_데이터 정렬 방식의 변환 함수
void exam3()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패!\n");
	}
	unsigned short us = 0x1234;
	unsigned long ul = 0x12345678;
	
	// 호스트 바이트를 네트워크 바이트로 변환한다.
	printf("0x%08X = > 0x%08X\n", us, htons(us));//host to network
	printf("0x%08X = > 0x%08X\n", ul, htonl(ul));// s : short  l : long
	unsigned short n_us = htons(us);
	unsigned long n_ul = htonl(ul);

	// 네트워크 바이트를 호스트 바이트로 변환한다.
	printf("0x%08X = > 0x%08X\n", n_us, ntohs(n_us)); // network to host
	printf("0x%08X = > 0x%08X\n", n_ul, ntohl(n_ul));
	WSACleanup();
}

