//TLS
#pragma comment (linker, "/subsystem:console")

#include <Windows.h>
#include<stdio.h>



void goo(char* name)//6�� ȣ��
{
	// TLS ������ ������ �����Ѵ�.
	__declspec(thread) static int c = 0;
	++c;

	static int sc = 0;
	++sc;
	printf("%s : %d : %d\n", name, c, sc); // �Լ��� ��� ȣ��Ǿ����� �˰� �ʹ�.
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
	//true ��ΰ� signal �ɶ� ����
	WaitForMultipleObjects(2, h, TRUE, INFINITE);// �ΰ��� �����尡 ���� ���ᰡ �Ǿ�� ������ �ȴ�

	CloseHandle(h1);
	CloseHandle(h2);
	return 0;
}