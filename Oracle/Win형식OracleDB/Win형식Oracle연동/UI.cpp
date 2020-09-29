#include "std.h"

void ui_GetAccount(HWND hDlg, ACCOUNT* pacc)
{
	GetDlgItemText(hDlg, IDC_EDIT2, pacc->name, sizeof(pacc->name));
	pacc->balance = GetDlgItemInt(hDlg, IDC_EDIT3, 0, 0);
}
