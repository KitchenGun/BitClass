#include"Member.h"

HWND g_hView;
vector<MEMBER> memlist;

BOOL OnInitDialog(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HWND hCombo = GetDlgItem(hDlg, IDC_COMBO1);

	SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)"M");
	SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)"F");

	return TRUE;
}

BOOL OnOK(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//����
	MEMBER mem;
	HWND hCombo = GetDlgItem(hDlg, IDC_COMBO1);
	HWND hwnd = FindWindow(0, TEXT("receive"));
	if (hwnd == 0)
	{
		MessageBox(hDlg,TEXT( "����"),0,0);
	}
	else
	{
		//����
		mem.id = GetDlgItemInt(hDlg, IDC_EDIT1, FALSE, FALSE);//id

		GetDlgItemText(hDlg, IDC_EDIT2, mem.name, sizeof(mem.name));//�̸�

		int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);//����
		if (i == 0)
		{
			mem.gender = 'm';
		}
		else if (i == 1)
		{
			mem.gender = 'f';
		}


		GetDlgItemText(hDlg, IDC_EDIT3, mem.phone, sizeof(mem.phone));//�̸�


		// �������� Pointer�� �����ϱ� ���� �޼��� - WM_COPYDATA
		COPYDATASTRUCT cds;
		cds.cbData = sizeof(MEMBER); // ������ data ũ��
		cds.dwData = 0;
		// �ĺ���
		cds.lpData = &mem; // ������ Pointer
		SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&cds);
	}
	return TRUE;
}

//receive
BOOL OnReceiveInitDialog(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	g_hView = GetDlgItem(hDlg, IDC_LIST1);

	//��� �ʱ�ȭ
	fun_ListViewHeader(hDlg, g_hView);
	return TRUE;
}

BOOL OnCopyDataStruct(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	COPYDATASTRUCT* ps = (COPYDATASTRUCT*)lParam;
	MEMBER* pData = (MEMBER*)ps->lpData;
	memlist.push_back(*pData);

	fun_ListViewPrint(hDlg);
	return TRUE;
}