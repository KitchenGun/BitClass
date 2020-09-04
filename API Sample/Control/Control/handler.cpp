#include <Windows.h>
#include "handler.h"
#include<tchar.h>

#define IDC_EDIT1		1
#define IDC_BUTTON1		2
#define IDC_LISTBOX1	3

HWND hedit1, hbutton2, hListBox1;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{//시작할때 생성되는 것들
	CreateWindow(TEXT("static"), TEXT("이 름"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 10, 90, 20, hwnd, (HMENU)0, 0, 0);

	hedit1 = CreateWindow(TEXT("Edit"), TEXT(""),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		110, 10, 310, 20, hwnd, (HMENU)IDC_EDIT1, 0, 0);

	hbutton2 = CreateWindow(TEXT("button"), TEXT("클릭"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		430, 10, 60, 20, hwnd, (HMENU)IDC_BUTTON1, 0, 0);

	hListBox1 = CreateWindow(TEXT("listbox"), TEXT(""),
		WS_CHILD | WS_VISIBLE | WS_BORDER|LBS_NOTIFY,
		110, 40, 310, 100, hwnd, (HMENU)IDC_LISTBOX1, 0, 0);

	return 0;

}

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{	//통지메세지 자식->부모
	switch (LOWORD(wParam))
	{
		case IDC_BUTTON1://버튼의 통지 메세지는 하나밖에 없다.
		{
			TCHAR buf[100];
			GetWindowText(hedit1, buf, sizeof(buf));
			//SetWindowText(hwnd, buf);
			//에디트에 입력한 문자열을 리스트 박스에 추가
			SendMessage(hListBox1, LB_ADDSTRING, 0, (LPARAM)buf);
			//에디트에서 문자열 제거
			SetWindowText(hedit1, TEXT(""));

			SetFocus(hedit1);
			break;
		}
		case IDC_LISTBOX1:
		{
			switch (HIWORD(wParam)) {
				case LBN_SELCHANGE:
				{
					TCHAR str[50];
					int i = SendMessage(hListBox1, LB_GETCURSEL, 0, 0);
					SendMessage(hListBox1, LB_GETTEXT, i, (LPARAM)str);
					SetWindowText(hwnd, str);
					break;
				}
			}
			break;
		}
	}
	return 0;
}
