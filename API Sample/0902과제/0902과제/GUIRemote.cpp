#pragma comment (linker, "/subsystem:windows")
#include"shape.h"

#define WM_MSGPOINT  WM_USER+101
#define WM_MSGSIZE   WM_USER+102
#define WM_MSGTYPE   WM_USER+103
#define WM_MSGCOLOR  WM_USER+104

SHAPE curshape;

const TCHAR* TypeToString(int idx)
{
	if (idx == 1)
		return TEXT("사각형");
	else if (idx == 2)
		return TEXT("타원");
	else
		return TEXT("잘못된 인덱스");
}

void PrintInfo(HWND hwnd)
{
	TCHAR buf[100];
	wsprintf(buf, TEXT("[좌표]%d,%d [색상]%d, %d, %d [폭]%d [타입]%s"),
		curshape.pt.x, curshape.pt.y,
		GetRValue(curshape.b_color), GetGValue(curshape.b_color), GetBValue(curshape.b_color),//RGB색가져오기
		curshape.size, TypeToString(curshape.type));
	SetWindowText(hwnd, buf);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HWND	GUI = FindWindow(0, TEXT("GUI"));//GUI찾기;
	static POINTS pt = { 100,100 };//정적 지역변수
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{// 좌표 받아오기
		curshape.pt.x = LOWORD(lParam);
		curshape.pt.y = HIWORD(lParam);
		PrintInfo(hwnd);
		SendMessage(GUI, WM_MSGPOINT, 0, lParam);//값 전달
	}
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
			//크기
		case VK_F1: curshape.size = 25;
			SendMessage(GUI, WM_MSGSIZE, wParam, 0);
			break;
		case VK_F2: curshape.size = 50;
			SendMessage(GUI, WM_MSGSIZE, wParam, 0);
			break;
		case VK_F3:	curshape.size = 75;
			SendMessage(GUI, WM_MSGSIZE, wParam, 0);
			break;
		case VK_F4:curshape.size = 100;
			SendMessage(GUI, WM_MSGSIZE, wParam, 0);//키를 전달한다
			break;
			//색갈
		case  'R': curshape.b_color = curshape.p_color = RGB(255, 0, 0);
			SendMessage(GUI, WM_MSGCOLOR, curshape.p_color, 0);
			break;
		case 'G': curshape.b_color = curshape.p_color = RGB(0, 255, 0);
			SendMessage(GUI, WM_MSGCOLOR, curshape.p_color, 0);
			break;
		case 'B':  curshape.b_color = curshape.p_color = RGB(0, 0, 255);
			SendMessage(GUI, WM_MSGCOLOR, curshape.p_color, 0);
			break;
		case 'I':  curshape.b_color = curshape.p_color = RGB(rand() % 256, rand() % 256, rand() % 256);
			SendMessage(GUI, WM_MSGCOLOR, curshape.p_color, 0);//랜덤값이 달라지는 문제를 해결하기 위해서 이렇게 함
			break;
			//타입
		case VK_UP: curshape.type++;
			if (curshape.type > 3)
				curshape.type = 1;
			SendMessage(GUI, WM_MSGTYPE, curshape.type, 0);
			break;
		case VK_DOWN: curshape.type--;
			if (curshape.type < 1)
				curshape.type = 3;
			SendMessage(GUI, WM_MSGTYPE, curshape.type, 0);//역시 화살표로 값을 정할수없어서 값을 전달
			break;
		}
		PrintInfo(hwnd);
		break;
	}
	case WM_CREATE:
	{
		curshape.pt.x = 0;
		curshape.pt.y = 0;
		curshape.b_color = RGB(255, 0, 0);
		curshape.p_color = RGB(255, 0, 0);
		curshape.size = 1;//25
		curshape.type = 1;//사각형
		PrintInfo(hwnd);
		if (GUI == 0)
		{
			SendMessage(hwnd, WM_DESTROY, 0, 0);
			return 0;
		}
		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
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
	wc.lpfnWndProc = WndProc;   //DefWindowProc;
	wc.lpszClassName = _TEXT("First");
	wc.lpszMenuName = 0;
	wc.style = 0;

	// 2. 등록(레지스트리에)
	RegisterClass(&wc);

	// 3. 윈도우 창 만들기 
	HWND hwnd = CreateWindowEx(0,			// WS_EX_TOPMOST
		_TEXT("first"),
		_TEXT("GUIRemote"),
		WS_OVERLAPPEDWINDOW, //  &~WS_MAXIMIZEBOX,	
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, 0, hInst, 0);

	// 4. 윈도우 보여주기
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	// 5. Message
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);//키보드 메세지를 가져왔는데
		DispatchMessage(&msg);
	}


	return 0;
}

