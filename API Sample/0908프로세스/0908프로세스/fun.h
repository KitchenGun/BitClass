#pragma once
#include<Windows.h>
#include<tchar.h>

void fun_WinExec(HWND hdlg);
void fun_CreateProcess(HWND hdlg);
void fun_ListBoxPrint(HWND hDlg);
void fun_List(HWND hDlg,WPARAM wparam);
void fun_TerminateProcess(HWND hDlg);
void fun_ProcessInfoPrint(HWND hDlg, int pid);
void fun_ExitCodeProcess(HWND hDlg, HANDLE phandle);