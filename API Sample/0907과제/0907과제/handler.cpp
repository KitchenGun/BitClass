#include <Windows.h>
#include<tchar.h>
#include <commctrl.h>
#include <vector>
#include"handler.h"
#include"Member.h"
#include"ChildDlgProc.h"
#include"resource.h"
#include"string"
using namespace std;

extern vector<Member> memlist;

HWND g_hDlg, g_hDlg1;

LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	//��޸��� ����
	if (g_hDlg == 0)
	{
		g_hDlg = CreateDialogParam(GetModuleHandle(0),// hinstance
			MAKEINTRESOURCE(IDD_DIALOG2),
			hwnd, // �θ�
			ChildDlgProc, // �޼��� �Լ�.
			(LPARAM)&memlist);

		ShowWindow(g_hDlg, SW_SHOW);
	}
	else
	{
		ShowWindow(g_hDlg, SW_SHOW);
	}
	return 0;
}


LRESULT OnLButton2Down(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	//��޸��� ����
	if (g_hDlg1 == 0)
	{
		g_hDlg1 = CreateDialogParam(GetModuleHandle(0),// hinstance
			MAKEINTRESOURCE(IDD_DIALOG3),
			hwnd, // �θ�
			ChildDlgProc, // �޼��� �Լ�.
			(LPARAM)&memlist);

		ShowWindow(g_hDlg1, SW_SHOW);
	}
	else
	{
		ShowWindow(g_hDlg1, SW_SHOW);
	}
	return 0;
	}
