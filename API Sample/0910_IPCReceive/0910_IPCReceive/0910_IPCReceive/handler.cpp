#include"Member.h"

HWND g_hView;
vector<MEMBER> memlist;

//receive
BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	fun_GetHandle(hDlg);

	fun_ListViewHeader(hDlg, g_hView);

	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL: EndDialog(hDlg, IDCANCEL); return 0;//종료
	}
	return TRUE;
}

BOOL OnCopyData(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	try
	{
		fun_Data(hDlg, lParam);

		fun_ListViewPrint(hDlg);
	}
	catch (const TCHAR* msg)
	{
		MessageBox(0, msg, TEXT("결과"), MB_OK);
	}
	return TRUE;
}