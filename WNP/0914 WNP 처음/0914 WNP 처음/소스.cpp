#pragma comment(lib, "ws2_32.lib")//���� ���̺귯�� �������� ���� ���� ����
#define _WINSOCK_DEPRECATED_NO_WARNINGS//2019 ������ �ʿ�
#include <stdio.h>
#include <WinSock2.h>//���� ���̺귯���� h

void exam1();
void exam2();
void exam3();

int main()
{
	exam3();
	return 0;
}

//01_���� ���̺귯��
void exam1()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����!\n");
		return;
	}

	printf("������ ���� �ʱ�ȭ ����!\n");
	WSACleanup();
}
//02_�ּ� ��ȯ ������(0x81998161 -> pc or  ���� api) <-> ���ڿ� (���ڿ� : 61.81.99.81->�����)
// inet_addr() : ���ڿ��ּ� -> ������ �ּ� 
// inet_ntoa() : �������ּ� -> ���ڿ� �ּ� 
void exam2()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����!\n");
		return;
	}

	// ���ڿ� �ּ� ���
	char* ipaddr = "230.200.12.5";
	printf("IP ���ڿ� �ּ� : %s\n", ipaddr);
	// ���ڿ� �ּҸ� 4byte ������ ��ȯ
	printf("IP ���ڿ� �ּ� = > ���� = 0x%08X\n", inet_addr(ipaddr));

	// 4byte ������ ���ڿ� �ּҷ� ��ȯ
	IN_ADDR in_addr;
	in_addr.s_addr = inet_addr(ipaddr);
	printf("IP ���� => ���ڿ� �ּ� = %s\n", inet_ntoa(in_addr));
	WSACleanup();
}

//03_������ ���� ����� ��ȯ �Լ�
void exam3()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����!\n");
	}
	unsigned short us = 0x1234;
	unsigned long ul = 0x12345678;
	
	// ȣ��Ʈ ����Ʈ�� ��Ʈ��ũ ����Ʈ�� ��ȯ�Ѵ�.
	printf("0x%08X = > 0x%08X\n", us, htons(us));//host to network
	printf("0x%08X = > 0x%08X\n", ul, htonl(ul));// s : short  l : long
	unsigned short n_us = htons(us);
	unsigned long n_ul = htonl(ul);

	// ��Ʈ��ũ ����Ʈ�� ȣ��Ʈ ����Ʈ�� ��ȯ�Ѵ�.
	printf("0x%08X = > 0x%08X\n", n_us, ntohs(n_us)); // network to host
	printf("0x%08X = > 0x%08X\n", n_ul, ntohl(n_ul));
	WSACleanup();
}

