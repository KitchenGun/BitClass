#pragma comment (linker, "/subsystem:console")
#include <iostream>
using namespace std;
#include <Windows.h>
#include "shape.h"

#define WM_MSGPRINT WM_USER+100

int main()
{
	HWND hwnd = FindWindow(0, TEXT("GUI"));
	if (hwnd == 0)
	{
		cout << "Hello ���� ����" << endl;
		return 0;
	}

	int idx;
	while (true)
	{
		cout << "Ÿ�� ����(1 : ����� �׸� �׸��� , 2 : ����)" << endl;
		cin >> idx;
		if (idx == 1)
		{
			SendMessage(hwnd, WM_MSGPRINT,0,0);
		}
		else if (idx == 2)
		{
			break;
		}
		else
		{
			cout<< "�߸� �Է�" << endl;
		}
	}
	return 0;
}

