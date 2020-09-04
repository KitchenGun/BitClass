#pragma once
#include<Windows.h>

#define IDC_EDIT1		1
#define IDC_BUTTON1		2
#define IDC_LISTBOX1	3

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam);

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam);
