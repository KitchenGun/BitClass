// Network 기본 코드 복사해 오세요..

#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <windows.h>	
#include <winsock2.h>	
#pragma comment(lib, "ws2_32.lib")

char filename[260] = TEXT("c:\\a.zip"); // 전송할 파일

struct FILE_INFO
{
	char FileName[260]; // 전송할 파일 이름.
	int  size;			// 화일 크기
};

// 접속한 Client에게 파일을 전송한다.
DWORD WINAPI FileServer(void* p)
{
	SOCKET s = (SOCKET)p;

	// 전송할 파일Open
	HANDLE hFile = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ,
		0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		printf("Can't Open File\n");
		closesocket(s);
		return 0;
	}
	// 크기를 구하고 화일의 정보를 전송한다.
	DWORD size1;
	DWORD size2 = GetFileSize(hFile, &size1);

	FILE_INFO fi;
	strcpy(fi.FileName, filename);
	fi.size = size2;

	send(s, (char*)&fi, sizeof(fi), 0);
	//-------------------------------------------------
	// 화일 전송
	int total = size2; // 전송할 전체 크기
	int current = 0;   // 전송한 크기
	int nRead = 0;
	char buf[800];    // 4k 버퍼.

	while (total > current)
	{
		DWORD len;
		//파일 읽어옴
		nRead = ReadFile(hFile, buf, 800, &len, 0);

		if (len <= 0) break;

		int nSend = send(s, buf, len, 0);
		if (nSend <= 0) break;

		current += nSend;
	}
	if (total != current)	printf("전송에러\n");
	else					printf("전송완료 \n");

	closesocket(s);
	CloseHandle(hFile);
	return 0;
}
