//handler.h

#pragma once

//send
BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam);
BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);
BOOL OnCopyData(HWND hDlg, WPARAM wParam, LPARAM lParam);

void OnSendData(HWND hDlg);
void OnSearch(HWND hDlg);
void OnEdit(HWND hDlg);
void OnDelete(HWND hDlg);
