#include<Windows.h>
#include<tchar.h>
#include"childproc.h"
#include"resource.h"
#include"handler.h"
#include"data.h"

DATA g_data;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	g_data.xcount = 5;//세로로 5줄 그린다
	g_data.ycount = 10;//가로로 10줄 그린다
	g_data.color = RGB(100, 100, 100);//초기화	50,100,150,200
	return 0;
}
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	//모달 
	DATA temp = g_data;
	UINT ret = DialogBoxParam(GetModuleHandle(0),// hinstance
		MAKEINTRESOURCE(IDD_DIALOG1),
		hwnd, // 부모
		ChildDlgProc, // 메세지 함수.
		(LPARAM)&temp); // 
	if (ret == IDOK)
	{
		g_data = temp;
		InvalidateRect(hwnd, 0, TRUE);
	}
	return 0;
}	
LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	HPEN pen = CreatePen(PS_SOLID, 1, g_data.color);
	HPEN oldpen = (HPEN)SelectObject(hdc, pen);

	RECT rc;//창의 크기를 가져온다
	GetClientRect(hwnd, &rc);//아래와 오른쪽 값을 사용하여 크기를 파악
	//세로줄을 그려보자
	int width = rc.right / (g_data.xcount + 1);
	for (int i = 1; i < g_data.xcount + 1; i++)
	{
		MoveToEx(hdc, (int)width * i, 0, 0);
		LineTo(hdc, (int)width * i, rc.bottom);
	}

	//가로줄 그리기
	int height = rc.bottom / (g_data.ycount + 1);
	for (int i = 1;i< g_data.ycount + 1; i++)
	{
		MoveToEx(hdc, 0, (int)height * i, 0);
		LineTo(hdc, rc.right, (int)height * i);
	}



	DeleteObject(SelectObject(hdc, oldpen));
	EndPaint(hwnd, &ps);
	return 0;
}
