#include "std.h"

void con_RecvData(TCHAR* buf)
{
	int* flag = (int*)buf;
	if (*flag == ACK_NEWMEMBER_S)
	{
		MessageBox(0, TEXT("ȸ�����Լ���"), TEXT("�˸�"), MB_OK);
	}
	else if (*flag == ACK_NEWMEMBER_F)
	{
		MEMBER* pmem = (MEMBER*)buf;
		//pmem->name
		MessageBox(0, TEXT("ȸ�����Խ���"), TEXT("�˸�"), MB_OK);
	}
}

void con_Init(HWND hDlg)
{

}

void con_InsertAccount(HWND hDlg)
{
	ACCOUNT acc = { 0 };

	ui_GetAccount(hDlg, &acc);

}


void con_Exit(HWND hDlg)
{
	socket_exit();
	EndDialog(hDlg, IDCANCEL);
}


void hComboAdd(HWND hDlg, int id)
{//�޺��ڽ��� �߰�
	HWND hcombo = GetDlgItem(hDlg, IDC_COMBO1);
	TCHAR charid[10];
	wsprintf(charid, TEXT("%d"), id);
	SendMessage(hcombo, CB_ADDSTRING, 0, (LPARAM)charid);
}

void con_Connect(HWND hDlg)
{
	sock_CreateSocket();

}
void con_InsertAccount(HWND hDlg){	ACCOUNT acc = { 0 };	ui_GetAccount(hDlg, &acc);	//������ ����		PACK_ACCOUNTINFO acinfo = pack_SetInsertAccount(&acc);	sock_Send((char*)& acinfo, sizeof(acinfo));}
