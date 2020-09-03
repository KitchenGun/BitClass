//수신자 - GUI
#pragma comment (linker, "/subsystem:windows")
#include <Windows.h>
#include <tchar.h>	

#define WM_MESSAGE WM_USER+100
#define WM_RECTANGLE WM_USER+101
#define WM_ELLIPSE WM_USER+102
#define WM_LINE WM_USER+103

int count=0;
int x, y, x1, y1;
int setColor;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_MESSAGE:
		{
			HDC hdc = GetDC(hwnd);
			int x = LOWORD(wParam);		//하위 2byte값을 획득
			int y = LOWORD(lParam);		//상위 2byte값을 획득
	
			TCHAR buf[16];
			wsprintf(buf, TEXT("(%d,%d)"), x, y);
			TextOut(hdc,  x, y, buf, _tcsclen(buf));
			ReleaseDC(hwnd, hdc);
			return 0;
		}
		case WM_RECTANGLE:
		{
			if (count != 0)
			{
				HDC hdc = GetDC(hwnd);
				HBRUSH brush = CreateSolidBrush(setColor);
				HBRUSH oldbr = (HBRUSH)SelectObject(hdc, brush);
				x1 = LOWORD(lParam);//크기
				y1 = HIWORD(lParam);
				Rectangle(hdc, x, y, x+x1, y+y1);
				DeleteObject(SelectObject(hdc, oldbr));
				count = 0;
				return 0;
			}
			else
			{
				setColor = wParam;
				x = LOWORD(lParam);
				y = HIWORD(lParam);
				count++;
				return 0;
			}
	
		}
		case WM_ELLIPSE:
		{
			if (count != 0)
			{
				HDC hdc = GetDC(hwnd);
				HBRUSH brush = CreateSolidBrush(setColor);
				HBRUSH oldbr = (HBRUSH)SelectObject(hdc, brush);
				x1 = LOWORD(lParam);//크기
				y1 = HIWORD(lParam);
				Ellipse(hdc, x, y, x + x1, y + y1);
				DeleteObject(SelectObject(hdc, oldbr));
				count = 0;
				return 0;
			}
			else
			{
				setColor = wParam;
				x = LOWORD(lParam);
				y = HIWORD(lParam);
				count++;
				return 0;
			}

		}
		case WM_LINE:
		{
			if (count != 0)
			{
				HDC hdc = GetDC(hwnd);
				HPEN pen = CreatePen(PS_SOLID, 5, setColor);
				HPEN oldpen = (HPEN)SelectObject(hdc, pen);
				x1 = LOWORD(lParam);//크기
				y1 = HIWORD(lParam);
				SetPixel(hdc, x, y, setColor);
				MoveToEx(hdc, x, y, NULL);
				LineTo(hdc, x+x1, y+y1);
				DeleteObject(SelectObject(hdc, oldpen));
				count = 0;
				return 0;
			}
			else
			{
				setColor = wParam;
				x = LOWORD(lParam);
				y = HIWORD(lParam);
				count++;
				return 0;
			}

		}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmd, int nShow)
{
	// 1. 윈도우 클래스 만들기 
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;   //  DefWindowProc;
	wc.lpszClassName = _TEXT("First");
	wc.lpszMenuName = 0;
	wc.style = 0;

	// 2. 등록(레지스트리에)
	RegisterClass(&wc);

	// 3. 윈도우 창 만들기 
	HWND hwnd = CreateWindowEx(0,			// WS_EX_TOPMOST
		_TEXT("first"), _TEXT("Window"),
		WS_OVERLAPPEDWINDOW,				//  &~WS_MAXIMIZEBOX,	
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, 0, hInst, 0);

	// 4. 윈도우 보여주기
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