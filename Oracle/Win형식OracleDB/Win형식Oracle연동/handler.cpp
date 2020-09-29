#include "std.h"

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Init(hDlg);
	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{ 
	
	switch (LOWORD(wParam))
	{
		case IDC_BUTTON1: con_InsertAccount(hDlg);	break;
		case IDC_BUTTON2: con_
		case IDC_COMBO1:
			switch (HIWORD(wParam))
			{
				case CBN_SELCHANGE:
					con_comboSelect(hDlg);
					break;
			}
			break;
		case IDCANCEL: con_Exit(hDlg);	return 0;
		
	}

	return TRUE;
}
