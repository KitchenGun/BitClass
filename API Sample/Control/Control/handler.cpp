#include <Windows.h>
#include "handler.h"
#include<tchar.h>

#define IDC_EDIT1		1
#define IDC_BUTTON1		2
#define IDC_LISTBOX1	3

HWND hedit1, hbutton2, hListBox1;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{//�����Ҷ� �����Ǵ� �͵�
	CreateWindow(TEXT("static"), TEXT("�� ��"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 10, 90, 20, hwnd, (HMENU)0, 0, 0);

	hedit1 = CreateWindow(TEXT("Edit"), TEXT(""),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		110, 10, 310, 20, hwnd, (HMENU)IDC_EDIT1, 0, 0);

	hbutton2 = CreateWindow(TEXT("button"), TEXT("Ŭ��"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		430, 10, 60, 20, hwnd, (HMENU)IDC_BUTTON1, 0, 0);

	hListBox1 = CreateWindow(TEXT("listbox"), TEXT(""),
		WS_CHILD | WS_VISIBLE | WS_BORDER|LBS_NOTIFY,
		110, 40, 310, 100, hwnd, (HMENU)IDC_LISTBOX1, 0, 0);

	return 0;

}

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{	//�����޼��� �ڽ�->�θ�
	switch (LOWORD(wParam))
	{
		case IDC_BUTTON1://��ư�� ���� �޼����� �ϳ��ۿ� ����.
		{
			TCHAR buf[100];
			GetWindowText(hedit1, buf, sizeof(buf));
			//SetWindowText(hwnd, buf);
			//����Ʈ�� �Է��� ���ڿ��� ����Ʈ �ڽ��� �߰�
			SendMessage(hListBox1, LB_ADDSTRING, 0, (LPARAM)buf);
			//����Ʈ���� ���ڿ� ����
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
