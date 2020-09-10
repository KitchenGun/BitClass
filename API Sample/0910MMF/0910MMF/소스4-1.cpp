#pragma comment (linker, "/subsystem:windows")

#include<Windows.h>
#include<tchar.h>
#include "resource.h"

typedef struct tagDATA
{
	TCHAR str1[20];
	TCHAR str2[20];
	int num;
}DATA;


BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) 
	{
	case WM_COPYDATA:
	{
		COPYDATASTRUCT* ps = (COPYDATASTRUCT*)lParam;
		DATA* pData = (DATA*)ps->lpData;
		SetDlgItemText(hDlg, IDC_EDIT1, pData->str1);
		SetDlgItemText(hDlg, IDC_EDIT2, pData->str2);
		SetDlgItemInt(hDlg, IDC_EDIT3, pData->num, FALSE);
	}
	return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL: EndDialog(hDlg, IDCANCEL); return 0;
		}
		return TRUE;
	case WM_DESTROY:
		return 0;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, PSTR lpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,// instance 
		MAKEINTRESOURCE(IDD_DIALOG2), // 다이얼로그 선택 
		0, // 부모 윈도우 
		DlgProc); // Proc.. 
	return 0;
}
