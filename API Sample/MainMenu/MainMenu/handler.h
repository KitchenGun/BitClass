#pragma once
#include<Windows.h>

LRESULT  OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT  OnMouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT  OnInitMenuPopup(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT  OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT  OnContextMenu(HWND hwnd, WPARAM wParam, LPARAM lParam);