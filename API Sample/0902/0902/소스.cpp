//마우스 클릭시 부가정보 획득
#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <tchar.h>		//범용타입 사용을 위한 h 
#include <vector>
using namespace std;

vector<POINT> pointlist;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_NCHITTEST:
	{
		//클릭된 위치(HIT test code값)
		DWORD code = DefWindowProc(hwnd, msg, wParam, lParam);
		if (code == HTCLIENT && GetKeyState(VK_CONTROL) < 0)
			code = HTCAPTION;
		if (code == HTLEFT) code = HTRIGHT;

		return code;
	}
	case WM_LBUTTONDOWN:
	{
		//좌표 획득(클라이언트 좌표)
		POINTS pt1 = MAKEPOINTS(lParam);
		POINT  pt2 = { LOWORD(lParam), HIWORD(lParam) };

		if (wParam & MK_CONTROL)//삭제
		{
			if (pointlist.size() <= 0)
				return 0;
			pointlist.pop_back();	//마지막 데이터 삭제
		}
		else//저장
		{
			pointlist.push_back(pt2);
		}

		//무효화영역발생
		InvalidateRect(hwnd, 0, TRUE); //3번째 인자
		//화면을 지울것인가(TRUE)? 말것인가(FALSE)?

		return 0;
	}

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		for (int i = 0; i < (int)pointlist.size(); i++)
		{
			POINT pt = pointlist[i];
			Rectangle(hdc, pt.x - 50, pt.y - 50, pt.x + 50, pt.y + 50);
		}

		EndPaint(hwnd, &ps);

		return 0;
	}

	case WM_CREATE:
		return 0;
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
		_TEXT("Hello"),
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
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return 0;
}
