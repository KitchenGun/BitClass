//TLS
#pragma comment (linker, "/subsystem:console")

#include <Windows.h>
#include<stdio.h>



void goo(char* name)//6번 호출
{
	// TLS 공간에 변수를 생성한다.
	__declspec(thread) static int c = 0;
	++c;

	static int sc = 0;
	++sc;
	printf("%s : %d : %d\n", name, c, sc); // 함수가 몇번 호출되었는지 알고 싶다.
}

DWORD WINAPI foo(void* p)
{
	char* name = (char*)p;
	goo(name);
	goo(name);
	goo(name);

	return 0;
}

int  main()
{
	HANDLE h1 = CreateThread(0, 0, foo, (LPVOID)"A", 0, 0);
	HANDLE h2 = CreateThread(0, 0, foo, (LPVOID)"\tB", 0, 0);

	HANDLE h[2] = { h1, h2 };
	//true 모두가 signal 될때 까지
	WaitForMultipleObjects(2, h, TRUE, INFINITE);// 두개의 쓰레드가 전부 종료가 되어야 리턴이 된다

	CloseHandle(h1);
	CloseHandle(h2);
	return 0;
}