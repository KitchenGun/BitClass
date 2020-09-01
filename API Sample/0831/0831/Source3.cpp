#pragma comment (linker, "/subsystem:console")
#include <iostream>
using namespace std;
//window api사용
#include <Windows.h>

int main()
{
	//window핸들얻기 윈도우의 핸들은 시스템에 전역적 성질을 가지고 있다.
	//1. 클래스명
	//2. 타이틀 이름
	HWND hwnd = FindWindow(0, TEXT("계산기"));
	if (hwnd == 0)
	{
		MessageBox(0, TEXT("계산기 실행전"), TEXT("알림"), MB_OK);
		return 0;
	}
	printf("계산기의 핸들값%d",(int)hwnd);

	MoveWindow(hwnd, 0, 0, 100, 100, FALSE);
	return 0;
}