#pragma once
#include<Windows.h>
#include<tchar.h>
#include"account.h"
#include"resource.h"
#include<vector>

using namespace std;

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam);

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);

void OnCancel(HWND hDlg);
