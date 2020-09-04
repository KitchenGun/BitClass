#include <Windows.h>
#include "resource.h"
#include <tchar.h>

BOOL isCheck = FALSE;
COLORREF b_color = RGB(255, 0, 0);

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
		//���α׷� ����
	case ID_40001:				SendMessage(hwnd, WM_CLOSE, 0, 0);			break;
										//��ǥ
	case ID_40002:				isCheck = !isCheck;
										InvalidateRect(hwnd, 0, FALSE); break;
										//����
	case ID_40003:				b_color = RGB(255, 0, 0);
										InvalidateRect(hwnd, 0, FALSE); break;
	case ID_40004:				b_color = RGB(0, 255, 0);
										InvalidateRect(hwnd, 0, FALSE); break;
	case ID_40005:				b_color = RGB(0, 0, 255);
										InvalidateRect(hwnd, 0, FALSE); break;
	case ID_40007:				b_color = RGB(rand()%256, rand() % 256, rand() % 256);
										InvalidateRect(hwnd, 0, FALSE); break;
	}
	return 0;
}

LRESULT OnMouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (isCheck)
	{
		HDC hdc = GetDC(hwnd);

		POINT pt = { LOWORD(lParam), HIWORD(lParam) };
		TCHAR buf[100];
		wsprintf(buf, TEXT("%06d:%06d"), pt.x, pt.y);

		TextOut(hdc, 10, 10, buf, _tcslen(buf));

		ReleaseDC(hwnd, hdc);
		return 0;
	}
}

LRESULT  OnInitMenuPopup(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	//�����쿡 �����Ǿ��ִ� �޴��� �ڵ� ȹ��
	//hmenu h menu = getmenu(hwnd)
	HMENU hmenu = (HMENU)wParam;
	//üũ �ڽ�
	CheckMenuItem(hmenu, ID_40002, isCheck == TRUE ? MF_CHECKED : MF_UNCHECKED);
	//����
	EnableMenuItem(hmenu, ID_40003,
		b_color == RGB(255, 0, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40004,
		b_color == RGB(0, 255, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hmenu, ID_40005,
		b_color == RGB(0, 0, 255) ? MF_GRAYED : MF_ENABLED);

	return 0;
}

LRESULT  OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd,&ps);

	HBRUSH brush = CreateSolidBrush(b_color);
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

	Rectangle(hdc, 10, 30, 100, 130);

	DeleteObject(SelectObject(hdc, oldbrush));
	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT  OnContextMenu(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu
		= LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
	HMENU hSubMenu = GetSubMenu(hMenu, 2);
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };
	//��ũ�� ��ǥ
	TrackPopupMenu(hSubMenu, TPM_LEFTBUTTON, pt.x, pt.y, 0, hwnd, 0);
	return 0;
}