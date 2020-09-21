//control.cpp
#include "std.h"

BOOL g_isConnect = FALSE;
BOOL g_isLogin = FALSE;

HWND g_hDlg;

void con_NewMember(HWND hDlg)
{
	MEMBER data = { 0 };
	//모달
	UINT ret = DialogBoxParam(GetModuleHandle(0),// hinstance
		MAKEINTRESOURCE(IDD_DIALOG2),
		hDlg, // 부모
		NewMemberDlgProc, // 메세지 함수.
		(LPARAM)&data); // WM_INITDIALOG의 lParam로 전달된다.
	if (ret == IDOK)
	{
		//해당정보를 서버로 전송한다
		pack_SetNewMember(&data);
		sock_Send((char*)&data, sizeof(data));
	}
}

void con_OnInit(HWND hDlg)
{
	g_hDlg = hDlg;
	//소켓 코드
	sock_LibInit();
	SetButtonState(hDlg, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE);
	
}

void con_Cancel(HWND hDlg)
{
	sock_LibExit();
	EndDialog(hDlg, IDCANCEL);
}
//서버관련내용

void con_Login(HWND hDlg)
{
	LOGIN login;
	TCHAR id[20];
	TCHAR pw[20];
	GetDlgItemTextA(hDlg, IDC_EDIT1,login.id, sizeof(id));
	GetDlgItemTextA(hDlg, IDC_EDIT2,login.pw_name, sizeof(pw));

	//해당정보를 서버로 전송한다
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
	//소켓 close
	sockc_Close();
	sock_Close();
	//버튼 상태 변경
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
	//1[서버연결] 2[서버연결해제] 3[로그인] 4[회원가입] 5[로그아웃] 6[전송]
/*
최초				: 1          / 2,3,4,5,6
서버연결이 되었다.  : 2, 3, 4    / 1,5,6
로그인이 되었다     : 2, 5,6    / 1,3, 4
로그아웃이 되었다.  : 2, 3, 4   / 1,5,6
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
		MessageBox(0, TEXT("회원가입성공"), TEXT("알림"), MB_OK);
	}
	else if (*flag == ACK_NEWMEMBER_F)
	{
		MEMBER* pmem = (MEMBER*)buf;
		pmem->name;//print로는 나오는데 메세지 박스는 안나온다
		MessageBox(0, TEXT("회원가입실패"), TEXT("알림"), MB_OK);
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
		wsprintf(temp, TEXT("%s님이 로그인하셨습니다."), plogin->pw_name);
		SetWindowText(g_hDlg, temp);
		//------------------통신 서버 접속하겠다
		sockc_CreateSocket();

	}
	else if (*flag == ACK_LOGIN_F)
	{
		LOGIN* pmem = (LOGIN*)buf;
		MessageBox(0, TEXT("로그인 실패"), TEXT("알림"), MB_OK);
	}
	else if (*flag == ACK_DELETEMEMBER_S)
	{
		LOGIN* pmem = (LOGIN*)buf;
		CString name;
		name = pmem->pw_name;//c 스트링을 통해서 형변환
		MessageBox(0, name + TEXT("님 정보 삭제 성공"), TEXT("알림"), MB_OK);
	}
	else if (*flag == ACK_DELETEMEMBER_F)
	{
		LOGIN* pmem = (LOGIN*)buf;
		MessageBox(0, TEXT("삭제 실패"), TEXT("알림"), MB_OK);
	}
	else if (*flag == ACK_SHORTMESSAGE)
	{
		SHORTMSG* pmsg = (SHORTMSG*)buf;

		//리스트 박스 출력
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

		//리스트 박스 출력
		TCHAR temp[100];
		wsprintf(temp, TEXT("%s,%s"),pmsg->id, pmsg->name);
		SetDlgItemText(g_hDlg, IDC_EDIT9, temp);
		SetDlgItemText(g_hDlg, IDC_EDIT10, pmsg->msg);
	}
}
