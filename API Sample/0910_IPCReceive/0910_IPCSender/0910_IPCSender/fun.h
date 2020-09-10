//fun.h

#pragma once

#include "Member.h"

void fun_ControlInit(HWND hDlg);

void fun_GetWindowHandle(TCHAR * msg, HWND *phwnd);

void fun_GetMemberData(HWND hDlg, MEMBER *pmem);

void fun_GetMemberNameData(HWND hDlg, MEMBER* pmem);

void fun_SendData(HWND hDlg, HWND hwnd, MEMBER mem);

void fun_SendNameData(HWND hDlg, HWND hwnd, MEMBER mem);

void fun_SendEditData(HWND hDlg, HWND hwnd, MEMBER mem);

void fun_SearchData(HWND hDlg, HWND hwnd, MEMBER mem);

void fun_ControlDataInit(HWND hDlg);

void fun_DataReceive(HWND hDlg, LPARAM lParam);

