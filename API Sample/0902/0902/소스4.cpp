#pragma comment (linker, "/subsystem:windows")
#include"shape.h"
//도형 관리 프로그램
/*
[구현 순서]
1. 도형 타입 정의
2. 전역 변수 선언
   저장변수, 현재 설정 정보 관리 변수
3. 전역 변수의 초기하
4. 현재 설정 정보 변수의 수정 기능
   수정된 결과를 눈으로 확인하기 위해 타이틀바에 출력
5. 도형을 출력하는 기능
   현재 설정 정보를 이용해서
*/

vector<SHAPE> shapelist;
SHAPE curshape;


const TCHAR* TypeToString(int idx)
{
	if (idx == 1)
		return TEXT("사각형");
	else if (idx == 2)
		return TEXT("타원");
	else if (idx == 3)
		return TEXT("삼각형");
	else
		return TEXT("잘못된 인덱스");
}

//타이틀 바에 출력하는 함수
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
	static POINTS pt = { 100,100 };//정적 지역변수
	switch (msg)
	{
		case WM_LBUTTONDOWN:
		{// 좌표 받아오기
			curshape.pt.x = LOWORD(lParam);
			curshape.pt.y = HIWORD(lParam);
			PrintInfo(hwnd);

			//저장
			shapelist.push_back(curshape);

			//무효화
			InvalidateRect(hwnd, 0, TRUE);
			return 0;
		}
		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				//크기
			case VK_F1: curshape.size = 25; 
				break;
			case VK_F2: curshape.size = 50; 
				break;
			case VK_F3:	curshape.size = 75; 
				break;
			case VK_F4:curshape.size = 100;
				break;
				//색갈
			case  'R': curshape.b_color = curshape.p_color = RGB(255, 0, 0);
				break;
			case 'G': curshape.b_color = curshape.p_color = RGB(0, 255, 0);
				break;
			case 'B':  curshape.b_color = curshape.p_color = RGB(0, 0, 255);
				break;
			case 'I':  curshape.b_color = curshape.p_color = RGB(rand()%256, rand() % 256, rand() % 256);
				break;
			case VK_UP: curshape.type++;
				if (curshape.type>3)
					curshape.type=1;
				break;
			case VK_DOWN: curshape.type--;
				if (curshape.type < 1)
					curshape.type = 3;
				break;
			}
			PrintInfo(hwnd);
			break;
		}
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			for (int i = 0; i < (int)shapelist.size(); i++)
			{
				SHAPE s = shapelist[i];
				HBRUSH hbr = CreateSolidBrush(s.b_color);
				HBRUSH oldbr = (HBRUSH)SelectObject(hdc, hbr);
				HPEN hpr = CreatePen(PS_SOLID, 1, s.p_color);
				HPEN oldpn = (HPEN)SelectObject(hdc, hpr);
				if (s.type == 1)//사각형
				{
					Rectangle(hdc, s.pt.x, s.pt.y, s.pt.x + s.size, s.pt.y + s.size);

				}
				else if (s.type == 2)//타원
				{
					Ellipse(hdc, s.pt.x, s.pt.y, s.pt.x + s.size, s.pt.y + s.size);
				}
				else if (s.type == 3)//삼각형
				{

				}
				DeleteObject(SelectObject(hdc, hbr));
				DeleteObject(SelectObject(hdc, hpr));
			}
			EndPaint(hwnd, &ps);
			return 0;
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
		TranslateMessage(&msg);//키보드 메세지를 가져왔는데
		DispatchMessage(&msg);
	}


	return 0;
}
