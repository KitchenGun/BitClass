#pragma comment (linker, "/subsystem:windows")

#include <windows.h>
#include<tchar.h>


typedef struct _LINE
{
	POINTS ptFrom;
	POINTS ptTo;
} LINE;

DWORD WINAPI foo(void* p) //쓰레드 함수
{
	HWND hwnd = (HWND)p;
	HANDLE hEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, TEXT("DRAW_SIGNAL"));
	HANDLE hMap = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, TEXT("map"));
	if (hMap == 0)
	{
		MessageBox(0, TEXT("1번 프로그램을 먼저 실행하세요"), TEXT(""), MB_OK);
		return 0;
	}
	LINE* pData = (LINE*)MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
	while (1)
	{
			// Event를 대기한다.
		WaitForSingleObject(hEvent, INFINITE);
		// 이제 Line의 정보가 pData에 있다.
		HDC hdc = GetDC(hwnd);
		MoveToEx(hdc, pData->ptFrom.x, pData->ptFrom.y, 0);
		LineTo(hdc, pData->ptTo.x, pData->ptTo.y);
		ReleaseDC(hwnd, hdc);
	}
	UnmapViewOfFile(pData);
	CloseHandle(hMap);
	CloseHandle(hEvent);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		HANDLE h = CreateThread(0, 0, foo, hwnd, 0, 0);
		CloseHandle(h);
		return 0;
	}
	case WM_LBUTTONDOWN:
		return 0;
	case WM_RBUTTONDOWN:
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nShowCmd)
{
	// 1. 윈도우 클래스 만들기 
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;			// DefWindowProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;
	wc.style = 0;

	// 2. 등록(레지스트리에)
	RegisterClass(&wc);

	// 3. 윈도우 창 만들기 
	HWND hwnd = CreateWindowEx(0,					// WS_EX_TOPMOST
		TEXT("first"),				// 클래스 명
		TEXT("Receive"),				// 캡션바 내용
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,	// 초기 위치 
		0, 0,			// 부모 윈도우 핸들, 메뉴 핸들
		hInstance,		// WinMain의 1번째 파라미터 (exe 주소)
		0);			// 생성 인자



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