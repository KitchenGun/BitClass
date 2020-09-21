//control.h

#pragma once

void con_RecvData(TCHAR *buf);

//회원가입
void con_NewMember(HWND hDlg);
//프로그램 초기화
void con_OnInit(HWND hDlg);
//프로그램 종료
void con_Cancel(HWND hDlg);
//서버와 관련
void con_Login(HWND hDlg);
void con_ConnectServer(HWND hDlg);
void con_DisConnectServer(HWND hDlg);
void con_LogOut(HWND hDlg);
void con_SendData(HWND hDlg);
//버튼의 활성화 비활성화
void SetButtonState(HWND hDlg, BOOL b1, BOOL b2, BOOL b3, BOOL b4, BOOL b5, BOOL b6);