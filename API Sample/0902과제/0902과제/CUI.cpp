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
		cout << "Hello 먼저 실행" << endl;
		return 0;
	}

	int idx;
	while (true)
	{
		cout << "타입 선택(1 : 저장된 그림 그리기 , 2 : 종료)" << endl;
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
			cout<< "잘못 입력" << endl;
		}
	}
	return 0;
}

