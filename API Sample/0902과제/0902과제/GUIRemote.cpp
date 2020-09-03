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
		return TEXT("�簢��");
	else if (idx == 2)
		return TEXT("Ÿ��");
	else
		return TEXT("�߸��� �ε���");
}

void PrintInfo(HWND hwnd)
{
	TCHAR buf[100];
	wsprintf(buf, TEXT("[��ǥ]%d,%d [����]%d, %d, %d [��]%d [Ÿ��]%s"),
		curshape.pt.x, curshape.pt.y,
		GetRValue(curshape.b_color), GetGValue(curshape.b_color), GetBValue(curshape.b_color),//RGB����������
		curshape.size, TypeToString(curshape.type));
	SetWindowText(hwnd, buf);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HWND	GUI = FindWindow(0, TEXT("GUI"));//GUIã��;
	static POINTS pt = { 100,100 };//���� ��������
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{// ��ǥ �޾ƿ���
		curshape.pt.x = LOWORD(lParam);
		curshape.pt.y = HIWORD(lParam);
		PrintInfo(hwnd);
		SendMessage(GUI, WM_MSGPOINT, 0, lParam);//�� ����
	}
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
			//ũ��
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
			SendMessage(GUI, WM_MSGSIZE, wParam, 0);//Ű�� �����Ѵ�
			break;
			//����
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
			SendMessage(GUI, WM_MSGCOLOR, curshape.p_color, 0);//�������� �޶����� ������ �ذ��ϱ� ���ؼ� �̷��� ��
			break;
			//Ÿ��
		case VK_UP: curshape.type++;
			if (curshape.type > 3)
				curshape.type = 1;
			SendMessage(GUI, WM_MSGTYPE, curshape.type, 0);
			break;
		case VK_DOWN: curshape.type--;
			if (curshape.type < 1)
				curshape.type = 3;
			SendMessage(GUI, WM_MSGTYPE, curshape.type, 0);//���� ȭ��ǥ�� ���� ���Ҽ���� ���� ����
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
		curshape.type = 1;//�簢��
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
	wc.lpszMenuName = 0;
	wc.style = 0;

	// 2. ���(������Ʈ����)
	RegisterClass(&wc);

	// 3. ������ â ����� 
	HWND hwnd = CreateWindowEx(0,			// WS_EX_TOPMOST
		_TEXT("first"),
		_TEXT("GUIRemote"),
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
		TranslateMessage(&msg);//Ű���� �޼����� �����Դµ�
		DispatchMessage(&msg);
	}


	return 0;
}

