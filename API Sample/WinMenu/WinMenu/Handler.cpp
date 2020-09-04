#include<vector>
#include"Handler.h"
#include"account.h"
#include"fun.h"

vector<ACCOUNT> acclist;

BOOL  OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	fun_GetControlHandle(hDlg);
	return TRUE;
}

BOOL  OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))//id 구분(메뉴, 컨트롤)
	{
	case IDCANCEL:			OnCancel(hDlg);						return 0; //통지 메세지
	case IDC_BUTTON1:		fun_Insert(hDlg);						break;
	case IDC_BUTTON2:		fun_Update(hDlg);						break;
	case IDC_BUTTON3:		fun_Delete(hDlg);						break;
	case IDC_LIST1:		fun_ListSelect(hDlg, wParam);	break;
	}
	return TRUE;
}

//사용자 정의 핸들러 ---------------------------------------------
void OnCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);
}


