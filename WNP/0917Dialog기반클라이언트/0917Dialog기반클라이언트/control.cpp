//control.cpp
#include "std.h"

BOOL g_isConnect = FALSE;
BOOL g_isLogin = FALSE;

HWND g_hDlg;

void con_NewMember(HWND hDlg)
{
	MEMBER data = { 0 };
	//���
	UINT ret = DialogBoxParam(GetModuleHandle(0),// hinstance
		MAKEINTRESOURCE(IDD_DIALOG2),
		hDlg, // �θ�
		NewMemberDlgProc, // �޼��� �Լ�.
		(LPARAM)&data); // WM_INITDIALOG�� lParam�� ���޵ȴ�.
	if (ret == IDOK)
	{
		//�ش������� ������ �����Ѵ�
		pack_SetNewMember(&data);
		sock_Send((char*)&data, sizeof(data));
	}
}

void con_OnInit(HWND hDlg)
{
	g_hDlg = hDlg;
	//���� �ڵ�
	sock_LibInit();
	SetButtonState(hDlg, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE);
	
}

void con_Cancel(HWND hDlg)
{
	sock_LibExit();
	EndDialog(hDlg, IDCANCEL);
}
//�������ó���

void con_Login(HWND hDlg)
{
	LOGIN login;
	TCHAR id[20];
	TCHAR pw[20];
	GetDlgItemTextA(hDlg, IDC_EDIT1,login.id, sizeof(id));
	GetDlgItemTextA(hDlg, IDC_EDIT2,login.pw_name, sizeof(pw));

	//�ش������� ������ �����Ѵ�
	pack_SetLogin(&login);
	sock_Send((char*)&login, sizeof(login));
}

void con_ConnectServer(HWND hDlg)
{
	sock_CreateSocket();
	g_isConnect = TRUE;
	SetButtonState(hDlg, FALSE, TRUE, TRUE, TRUE, FALSE, FALSE);
}

void con_DisConnectServer(HWND hDlg)
{
	g_isConnect = FALSE;
}

void con_LogOut(HWND hDlg)
{
	g_isLogin = false;
	//���� close
	sockc_Close();
	sock_Close();
	//��ư ���� ����
	SetButtonState(hDlg, FALSE, TRUE, TRUE, TRUE, FALSE, FALSE);
}

void con_SendData(HWND hDlg)
{
	SHORTMSG msg;

	GetDlgItemText(hDlg, IDC_EDIT6, msg.id, sizeof(msg.msg));
	GetDlgItemText(hDlg, IDC_EDIT8, msg.name, sizeof(msg.msg));
	GetDlgItemText(hDlg, IDC_EDIT3, msg.msg, sizeof(msg.msg));
	GetLocalTime(&msg.dt);

	pack_SetSendData(&msg);
	sockc_Send((char*)&msg, sizeof(msg));
}

void con_SendLongData(HWND hDlg)
{
	COPYPASTMSG msg;

	GetDlgItemText(hDlg, IDC_EDIT5, msg.msg, sizeof(msg.msg));
	GetDlgItemText(hDlg, IDC_EDIT6, msg.id, sizeof(msg.id));
	GetDlgItemText(hDlg, IDC_EDIT8, msg.name, sizeof(msg.name));
	GetLocalTime(&msg.dt);

	pack_SetSendLongData(&msg);
	sockc_Send((char*)&msg, sizeof(msg));
}

void SetButtonState(HWND hDlg, BOOL b1, BOOL b2, BOOL b3, BOOL b4, BOOL b5, BOOL b6)
{
	//1[��������] 2[������������] 3[�α���] 4[ȸ������] 5[�α׾ƿ�] 6[����]
/*
����				: 1          / 2,3,4,5,6
���������� �Ǿ���.  : 2, 3, 4    / 1,5,6
�α����� �Ǿ���     : 2, 5,6    / 1,3, 4
�α׾ƿ��� �Ǿ���.  : 2, 3, 4   / 1,5,6
*/

	HWND h1 = GetDlgItem(hDlg, IDC_BUTTON1);
	HWND h2 = GetDlgItem(hDlg, IDC_BUTTON2);
	HWND h3 = GetDlgItem(hDlg, IDC_BUTTON3);
	HWND h4 = GetDlgItem(hDlg, IDC_BUTTON4);
	HWND h5 = GetDlgItem(hDlg, IDC_BUTTON5);
	HWND h6 = GetDlgItem(hDlg, IDC_BUTTON6);

	EnableWindow (GetDlgItem(hDlg, IDC_BUTTON1),b1);
	EnableWindow(GetDlgItem(hDlg, IDC_BUTTON2),b2);
	EnableWindow(GetDlgItem(hDlg, IDC_BUTTON3),b3);
	EnableWindow(GetDlgItem(hDlg, IDC_BUTTON4),b4);
	EnableWindow(GetDlgItem(hDlg, IDC_BUTTON5),b5);
	EnableWindow(GetDlgItem(hDlg, IDC_BUTTON6),b6);
}

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
		pmem->name;//print�δ� �����µ� �޼��� �ڽ��� �ȳ��´�
		MessageBox(0, TEXT("ȸ�����Խ���"), TEXT("�˸�"), MB_OK);
	}
	else if (*flag == ACK_LOGIN_S)
	{
		g_isLogin = TRUE;
		SetButtonState(g_hDlg, FALSE, TRUE, FALSE, FALSE, TRUE, TRUE);
		LOGIN* plogin = (LOGIN*)buf;
		CString name;
		SetDlgItemText(g_hDlg, IDC_EDIT6, plogin->id);
		SetDlgItemText(g_hDlg, IDC_EDIT8, plogin->pw_name);
		TCHAR temp[100];
		wsprintf(temp, TEXT("%s���� �α����ϼ̽��ϴ�."), plogin->pw_name);
		SetWindowText(g_hDlg, temp);
		//------------------��� ���� �����ϰڴ�
		sockc_CreateSocket();

	}
	else if (*flag == ACK_LOGIN_F)
	{
		LOGIN* pmem = (LOGIN*)buf;
		MessageBox(0, TEXT("�α��� ����"), TEXT("�˸�"), MB_OK);
	}
	else if (*flag == ACK_DELETEMEMBER_S)
	{
		LOGIN* pmem = (LOGIN*)buf;
		CString name;
		name = pmem->pw_name;//c ��Ʈ���� ���ؼ� ����ȯ
		MessageBox(0, name + TEXT("�� ���� ���� ����"), TEXT("�˸�"), MB_OK);
	}
	else if (*flag == ACK_DELETEMEMBER_F)
	{
		LOGIN* pmem = (LOGIN*)buf;
		MessageBox(0, TEXT("���� ����"), TEXT("�˸�"), MB_OK);
	}
	else if (*flag == ACK_SHORTMESSAGE)
	{
		SHORTMSG* pmsg = (SHORTMSG*)buf;

		//����Ʈ �ڽ� ���
		TCHAR temp[100];
		wsprintf(temp, TEXT("[%s,%s] %s (%02d:%02d:%02d)"),
			pmsg->id, pmsg->name, pmsg->msg,
			pmsg->dt.wHour, pmsg->dt.wMinute, pmsg->dt.wSecond);
		HWND hList = GetDlgItem(g_hDlg, IDC_LIST1);
		SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)temp);

	}
	else if (*flag == ACK_TEXTMESSAGE)
	{
		COPYPASTMSG  *pmsg = (COPYPASTMSG*)buf;

		//����Ʈ �ڽ� ���
		TCHAR temp[100];
		wsprintf(temp, TEXT("%s,%s"),pmsg->id, pmsg->name);
		SetDlgItemText(g_hDlg, IDC_EDIT9, temp);
		SetDlgItemText(g_hDlg, IDC_EDIT10, pmsg->msg);
	}
}
