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
	switch (LOWORD(wParam))//id ����(�޴�, ��Ʈ��)
	{
	case IDCANCEL:			OnCancel(hDlg);						return 0; //���� �޼���
	case IDC_BUTTON1:		fun_Insert(hDlg);						break;
	case IDC_BUTTON2:		fun_Update(hDlg);						break;
	case IDC_BUTTON3:		fun_Delete(hDlg);						break;
	case IDC_LIST1:		fun_ListSelect(hDlg, wParam);	break;
	}
	return TRUE;
}

//����� ���� �ڵ鷯 ---------------------------------------------
void OnCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);
}


