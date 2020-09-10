#include<Windows.h>
#include<tchar.h>
#include "resource.h"
#include "handler.h"
#include"fun.h"
#include"myprocess.h"
#include<vector>
using namespace std;


BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
		//프로세스 생성 
	case IDC_LIST1:		fun_List(hDlg, wParam);		break;
	case IDC_BUTTON1:	fun_WinExec(hDlg);			break;
	case IDC_BUTTON2:	fun_CreateProcess(hDlg);	break;
	case IDC_BUTTON3:	fun_TerminateProcess(hDlg);	break;
	case IDCANCEL: EndDialog(hDlg, IDCANCEL); return 0;
	}
	return TRUE;
}