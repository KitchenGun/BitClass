//TLS:공유자원 콘솔 화면에 2개의 쓰레드가 동시에 접근하여 출력 요청을 하는 과정
#pragma comment (linker, "/subsystem:console")

#include <Windows.h>
#include<iostream>
#include<process.h>
using namespace std;

unsigned int _stdcall foo(void* p)
{
	char* msg = (char*)p;
	for (int i = 0; i < 10; i++)
	{
		cout<<msg<<"---------------"<<"테스트 문자열"<<endl;
		Sleep(10);
	}
	return 0;
}

unsigned int _stdcall woo(void* p)
{
	char* msg = (char*)p;
	for (int i = 0; i < 10; i++)
	{
		cout << msg << "---------------" << "테스트 문자열" << endl;
		Sleep(10);
	}
	return 0;
}

int  main()
{
	unsigned int h1 = _beginthreadex(0, 0, foo, (LPVOID)"A", 0, 0);
	unsigned int h2 = _beginthreadex(0, 0, foo, (LPVOID)"\tB", 0, 0);

	unsigned int h[2] = { h1, h2 };
	//true 모두가 signal 될때 까지
	WaitForMultipleObjects(2, (HANDLE*)h, TRUE, INFINITE);// 두개의 쓰레드가 전부 종료가 되어야 리턴이 된다

	CloseHandle((HANDLE)h1);
	CloseHandle((HANDLE)h2);
	return 0;
}