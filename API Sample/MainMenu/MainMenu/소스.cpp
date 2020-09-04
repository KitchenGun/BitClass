//skeleton �ڵ� 
//����������λ�븵Ŀ����
#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <tchar.h>		//����Ÿ�� ����� ���� h 
#include "resource.h"
#include"handler.h"
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITMENUPOPUP:	return OnInitMenuPopup(hwnd, wParam, lParam);
	case WM_COMMAND:			return OnCommand(hwnd,wParam,lParam);
	case WM_MOUSEMOVE:			return OnMouseMove(hwnd, wParam, lParam);
	case WM_PAINT:						return OnPaint(hwnd, wParam, lParam);
	case WM_CONTEXTMENU:	return OnContextMenu(hwnd, wParam, lParam);
	case WM_CREATE:
		MessageBox(0, TEXT("WM_CREATE"), TEXT("�˸�"), MB_OK);
		return 0;
	case WM_DESTROY:
		MessageBox(0, TEXT("WM_DESTROY"), TEXT("�˸�"), MB_OK);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmd, int nShow)
{
	// 1. ������ Ŭ���� ����� 
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;   //DefWindowProc;
	wc.lpszClassName = _TEXT("First");
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.style = 0;

	// 2. ���(������Ʈ����)
	RegisterClass(&wc);

	// 3. ������ â ����� 
	HWND hwnd = CreateWindowEx(0,			// WS_EX_TOPMOST
		_TEXT("first"),
		_TEXT("Hello"),
		WS_OVERLAPPEDWINDOW, //  &~WS_MAXIMIZEBOX,	
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, 0, hInst, 0);

	// 4. ������ �����ֱ�
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	// 5. Message
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return 0;
}