#include <Windows.h>
#include "handler.h"


int g_type = 1;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	// ���̵� 1 �� Ÿ�̸Ӱ� 1�� ������ �ݺ�����
	SetTimer(hwnd, 1, 1000, 0);
	SendMessage(hwnd, WM_TIMER, 1, 0);//1:wparam Ÿ�̸� id
	return 0;
}
LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	KillTimer(hwnd, 1);
	PostQuitMessage(0);
	return 0;
}

LRESULT OnTimer(HWND hwnd, WPARAM wParam, LPARAM lParam)
{//���� �ð� ���
	SYSTEMTIME st;
	GetLocalTime(&st);

	TCHAR buf[100];
	wsprintf(buf, TEXT("%04d�� %02d�� %02d��  %02d:%02d:%02d"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	SetWindowText(hwnd, buf);
	g_type++;
	if (g_type > 3)		g_type = 1;

	InvalidateRect(hwnd, 0, TRUE);

	return 0;
}


LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	if (g_type == 1)
	{
		Rectangle(hdc, 10, 10, 100, 100);
	}
	else if (g_type == 2)
	{
		Ellipse(hdc, 10, 10, 100, 100);
	}
	else if (g_type == 3)
	{
		POINT pts[] = { {55,10},{10,100},{100,100} };
		Polygon(hdc, pts, 3);
	}


	EndPaint(hwnd, &ps);

	return 0;
}

LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };


	HDC hdc = GetDC(hwnd);

	POINT pts[] = { { pt.x,pt.y },{ pt.x - 50, pt.y + 100 },{ pt.x + 50, pt.y + 100 } };
	Polygon(hdc, pts, 3);

	ReleaseDC(hwnd, hdc);

	return 0;
}
