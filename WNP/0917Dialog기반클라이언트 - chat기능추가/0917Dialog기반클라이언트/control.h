//control.h

#pragma once

void con_RecvData(TCHAR *buf);

//ȸ������
void con_NewMember(HWND hDlg);
//���α׷� �ʱ�ȭ
void con_OnInit(HWND hDlg);
//���α׷� ����
void con_Cancel(HWND hDlg);
//������ ����
void con_Login(HWND hDlg);
void con_ConnectServer(HWND hDlg);
void con_DisConnectServer(HWND hDlg);
void con_LogOut(HWND hDlg);
void con_SendData(HWND hDlg);
//��ư�� Ȱ��ȭ ��Ȱ��ȭ
void SetButtonState(HWND hDlg, BOOL b1, BOOL b2, BOOL b3, BOOL b4, BOOL b5, BOOL b6);