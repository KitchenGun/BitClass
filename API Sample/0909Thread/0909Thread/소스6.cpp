//TLS:�����ڿ� �ܼ� ȭ�鿡 2���� �����尡 ���ÿ� �����Ͽ� ��� ��û�� �ϴ� ����
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
		cout<<msg<<"---------------"<<"�׽�Ʈ ���ڿ�"<<endl;
		Sleep(10);
	}
	return 0;
}

unsigned int _stdcall woo(void* p)
{
	char* msg = (char*)p;
	for (int i = 0; i < 10; i++)
	{
		cout << msg << "---------------" << "�׽�Ʈ ���ڿ�" << endl;
		Sleep(10);
	}
	return 0;
}

int  main()
{
	unsigned int h1 = _beginthreadex(0, 0, foo, (LPVOID)"A", 0, 0);
	unsigned int h2 = _beginthreadex(0, 0, foo, (LPVOID)"\tB", 0, 0);

	unsigned int h[2] = { h1, h2 };
	//true ��ΰ� signal �ɶ� ����
	WaitForMultipleObjects(2, (HANDLE*)h, TRUE, INFINITE);// �ΰ��� �����尡 ���� ���ᰡ �Ǿ�� ������ �ȴ�

	CloseHandle((HANDLE)h1);
	CloseHandle((HANDLE)h2);
	return 0;
}