#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include <commctrl.h>
#include<vector>
#include <tchar.h>		//범용타입 사용을 위한 h 
#include"Member.h"
#include"handler.h"
#include"resource.h"
#include<string>
#include<cstdlib>

using namespace std;

vector<Member> memlist;

HWND g_hList;        //IDC_LIST1
extern vector<Member> g_memberlist;

void ui_GetControlHandle(HWND hDlg)
{
	g_hList = GetDlgItem(hDlg, IDC_LIST1);
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LVCOLUMN COL;
	
	switch (msg)
	{
		case WM_INITDIALOG: 
		{
			hDlg = CreateWindow(WC_LISTVIEW, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
				LVS_REPORT, 10, 10, 500, 200, hDlg, NULL, GetModuleHandle(0), NULL);
			// 헤더를 추가한다.
			COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
			COL.fmt = LVCFMT_LEFT;
			COL.cx = 40;
			COL.pszText = (LPSTR)_T("Num");				// 첫 번째 헤더
			COL.iSubItem = 0;
			SendMessage(hDlg, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

			COL.pszText = (LPSTR)_T("Name");			// 두 번째 헤더
			COL.cx = 100;
			COL.iSubItem = 1;
			SendMessage(hDlg, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);

			COL.cx = 60;
			COL.pszText = (LPSTR)_T("Gender");				// 세 번째 헤더
			COL.iSubItem = 2;
			SendMessage(hDlg, LVM_INSERTCOLUMN, 2, (LPARAM)&COL);

			COL.cx = 120;
			COL.pszText = (LPSTR)_T("Phone");			// 네 번째 헤더
			COL.iSubItem = 3;
			SendMessage(hDlg, LVM_INSERTCOLUMN, 3, (LPARAM)&COL);

			ListView_DeleteAllItems(hDlg);
			for (int unsigned i = 0; i < memlist.size(); i++)
			{
				LVITEM LI;
				LI.mask = LVIF_TEXT;

				LI.iSubItem = 0;
				LI.iItem = i;
				TCHAR tempid[20];
				wsprintf(tempid, TEXT("%d"), memlist[i].number);
				LI.pszText = tempid;//숫자
				SendMessage(hDlg, LVM_INSERTITEM, 0, (LPARAM)&LI);

				LI.iSubItem = 1;
				LI.iItem = i;
				TCHAR tempname[20];
				wsprintf(tempname, TEXT("%s"), memlist[i].name);
				LI.pszText = tempname;				// 이름
				SendMessage(hDlg, LVM_SETITEM, 0, (LPARAM)&LI);

				LI.iSubItem = 2;
				LI.iItem = i;
				TCHAR tempgen[20];
				wsprintf(tempgen, TEXT("%c"), memlist[i].gender);
				LI.pszText = tempgen;		// 성별
				SendMessage(hDlg, LVM_SETITEM, 0, (LPARAM)&LI);

				LI.iSubItem = 3;
				LI.iItem = i;
				TCHAR tempphone[20];
				wsprintf(tempphone, TEXT("%s"), memlist[i].phone);
				LI.pszText = tempphone;				// 숫자
				SendMessage(hDlg, LVM_SETITEM, 0, (LPARAM)&LI);
			}
			return 0;
		}
		
		case WM_ADD_LIST:
		{
			hDlg = CreateWindow(WC_LISTVIEW, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
			LVS_REPORT, 10, 10, 500, 200, hDlg, NULL, GetModuleHandle(0), NULL);
			// 헤더를 추가한다.
			COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
			COL.fmt = LVCFMT_LEFT;
			COL.cx = 40;
			COL.pszText = (LPSTR)_T("Num");				// 첫 번째 헤더
			COL.iSubItem = 0;
			SendMessage(hDlg, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

			COL.pszText = (LPSTR)_T("Name");			// 두 번째 헤더
			COL.cx = 100;
			COL.iSubItem = 1;
			SendMessage(hDlg, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);

			COL.cx = 60;
			COL.pszText = (LPSTR)_T("Gender");				// 세 번째 헤더
			COL.iSubItem = 2;
			SendMessage(hDlg, LVM_INSERTCOLUMN, 2, (LPARAM)&COL);

			COL.cx = 120;
			COL.pszText = (LPSTR)_T("Phone");			// 네 번째 헤더
			COL.iSubItem = 3;
			SendMessage(hDlg, LVM_INSERTCOLUMN, 3, (LPARAM)&COL);

			ListView_DeleteAllItems(hDlg);
			for (int unsigned i = 0; i < memlist.size(); i++)
			{
				LVITEM LI;
				LI.mask = LVIF_TEXT;

				LI.iSubItem = 0;
				LI.iItem = i;
				TCHAR tempid[20];
				wsprintf(tempid, TEXT("%d"), memlist[i].number);
				LI.pszText = tempid;//숫자
				SendMessage(hDlg, LVM_INSERTITEM, 0, (LPARAM)&LI);

				LI.iSubItem = 1;
				LI.iItem = i;
				TCHAR tempname[20];
				wsprintf(tempname, TEXT("%s"), memlist[i].name);
				LI.pszText = tempname;				// 이름
				SendMessage(hDlg, LVM_SETITEM, 0, (LPARAM)&LI);

				LI.iSubItem = 2;
				LI.iItem = i;
				TCHAR tempgen[20];
				wsprintf(tempgen, TEXT("%c"), memlist[i].gender);
				LI.pszText = tempgen;		// 성별
				SendMessage(hDlg, LVM_SETITEM, 0, (LPARAM)&LI);

				LI.iSubItem = 3;
				LI.iItem = i;
				TCHAR tempphone[20];
				wsprintf(tempphone, TEXT("%s"), memlist[i].phone);
				LI.pszText = tempphone;				// 숫자
				SendMessage(hDlg, LVM_SETITEM, 0, (LPARAM)&LI);
				return 0;
			}
		}
		case WM_Find_LIST:
		{
			int i = lParam;
			TCHAR tempid[20];
			wsprintf(tempid, TEXT("%d"), memlist[i].number);
			SetDlgItemText(hDlg,IDC_EDIT1, tempid);
			TCHAR tempname[20];
			wsprintf(tempname, TEXT("%s"), memlist[i].name);
			SetDlgItemText(hDlg, IDC_EDIT1, tempid);
			SetDlgItem(hDlg,IDC_EDIT1)->memlist[i].number;
			SetDlgItem(IDC_EDIT2)-> memlist[i].name;
			SetDlgItem(IDC_EDIT3)-> memlist[i].gender;
			SetDlgItem(IDC_EDIT4)->memlist[i].phone;
			return 0;
		}
		case WM_LBUTTONDOWN:		return 0;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
			case IDC_BUTTON1: return OnLButtonDown(hDlg, wParam, lParam);
			case IDC_BUTTON2: return OnLButton2Down(hDlg, wParam, lParam);
			case IDCANCEL: EndDialog(hDlg, IDCANCEL); return 0;//종료
			}
			return TRUE;
	}
	//return  true를 하면 기본제공 사용안함
	return FALSE;//기본제공되는 프로시져를 실행
}


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, PSTR lpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,// instance 
		MAKEINTRESOURCE(IDD_DIALOG1), // 다이얼로그 선택 
		HWND_DESKTOP, // 부모 윈도우 
		DlgProc); // Proc.. 
	return 0;
}
