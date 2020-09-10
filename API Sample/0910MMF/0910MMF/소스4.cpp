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
	switch (msg) {
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			HWND hwnd = FindWindow(0, TEXT("B"));
			DATA data;
			
			GetDlgItemText(hDlg, IDC_EDIT1, data.str1, sizeof(data.str1));
			GetDlgItemText(hDlg, IDC_EDIT2, data.str2, sizeof(data.str2));
			data.num = GetDlgItemInt(hDlg, IDC_EDIT3, FALSE, FALSE);
			// �������� Pointer�� �����ϱ� ���� �޼��� - WM_COPYDATA
			COPYDATASTRUCT cds;
			cds.cbData = sizeof(DATA); // ������ data ũ��
			cds.dwData = 1;
			// �ĺ���
			cds.lpData = &data; // ������ Pointer
			SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&cds);
		}
		return 0;
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
		MAKEINTRESOURCE(IDD_DIALOG1), // ���̾�α� ���� 
		0, // �θ� ������ 
		DlgProc); // Proc.. 
	return 0;
}
