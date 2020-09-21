// Network �⺻ �ڵ� ������ ������..

#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <windows.h>	
#include <winsock2.h>	
#pragma comment(lib, "ws2_32.lib")

char filename[260] = TEXT("c:\\a.zip"); // ������ ����

struct FILE_INFO
{
	char FileName[260]; // ������ ���� �̸�.
	int  size;			// ȭ�� ũ��
};

// ������ Client���� ������ �����Ѵ�.
DWORD WINAPI FileServer(void* p)
{
	SOCKET s = (SOCKET)p;

	// ������ ����Open
	HANDLE hFile = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ,
		0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		printf("Can't Open File\n");
		closesocket(s);
		return 0;
	}
	// ũ�⸦ ���ϰ� ȭ���� ������ �����Ѵ�.
	DWORD size1;
	DWORD size2 = GetFileSize(hFile, &size1);

	FILE_INFO fi;
	strcpy(fi.FileName, filename);
	fi.size = size2;

	send(s, (char*)&fi, sizeof(fi), 0);
	//-------------------------------------------------
	// ȭ�� ����
	int total = size2; // ������ ��ü ũ��
	int current = 0;   // ������ ũ��
	int nRead = 0;
	char buf[800];    // 4k ����.

	while (total > current)
	{
		DWORD len;
		//���� �о��
		nRead = ReadFile(hFile, buf, 800, &len, 0);

		if (len <= 0) break;

		int nSend = send(s, buf, len, 0);
		if (nSend <= 0) break;

		current += nSend;
	}
	if (total != current)	printf("���ۿ���\n");
	else					printf("���ۿϷ� \n");

	closesocket(s);
	CloseHandle(hFile);
	return 0;
}
