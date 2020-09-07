#include<Windows.h>
#include<tchar.h>
#include"childproc.h"
#include"resource.h"
#include"handler.h"
#include"data.h"

DATA g_data;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	g_data.xcount = 5;//���η� 5�� �׸���
	g_data.ycount = 10;//���η� 10�� �׸���
	g_data.color = RGB(100, 100, 100);//�ʱ�ȭ	50,100,150,200
	return 0;
}
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	//��� 
	DATA temp = g_data;
	UINT ret = DialogBoxParam(GetModuleHandle(0),// hinstance
		MAKEINTRESOURCE(IDD_DIALOG1),
		hwnd, // �θ�
		ChildDlgProc, // �޼��� �Լ�.
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

	RECT rc;//â�� ũ�⸦ �����´�
	GetClientRect(hwnd, &rc);//�Ʒ��� ������ ���� ����Ͽ� ũ�⸦ �ľ�
	//�������� �׷�����
	int width = rc.right / (g_data.xcount + 1);
	for (int i = 1; i < g_data.xcount + 1; i++)
	{
		MoveToEx(hdc, (int)width * i, 0, 0);
		LineTo(hdc, (int)width * i, rc.bottom);
	}

	//������ �׸���
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
