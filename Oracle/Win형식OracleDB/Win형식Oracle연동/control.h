#pragma once

void con_Init(HWND hDlg);
void con_Exit(HWND hDlg);
void con_Connect(HWND hDlg);

void con_InsertAccount(HWND hDlg);

//�޺��ڽ� �ʱ�ȭ
void hComboAdd(HWND hDlg, int id);
void con_comboSelect(HWND hDlg);

void con_RecvData(TCHAR* buf);