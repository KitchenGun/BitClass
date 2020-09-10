//대화 상자 기반
#pragma comment (linker, "/subsystem:windows")

#include <Windows.h>
#include<vector>
#include <tchar.h>		//범용타입 사용을 위한 h 
#include "resource.h"
#include"Member.h"
#include"ChildDlgProc.h"

using namespace std;

extern vector<Member> memlist;

BOOL CALLBACK ChildDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	Member member;
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		HWND hcombo = GetDlgItem(hDlg, IDC_COMBO1);
		SendMessage(hcombo, CB_ADDSTRING, 0, (LPARAM)TEXT("M"));
		SendMessage(hcombo, CB_ADDSTRING, 0, (LPARAM)TEXT("F"));
		//초기화
		return TRUE;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			//성별
			HWND hcombo = GetDlgItem(hDlg, IDC_COMBO1);
			int cursor = SendMessage(hcombo, CB_GETCURSEL, 0, 0);
			if (cursor == 1)
			{//성별 남자일경우
				member.gender = (char)'M';
			}
			else if (cursor == 0)
			{//여자일 경우
				member.gender = (char)'F';
			}
			if (memlist.size() == 0)
			{
				member.number = 1;
			}
			else
			{
				member.number = memlist.size() + 1;
			}

			GetDlgItemText(hDlg, IDC_EDIT1, member.name,20 );
			GetDlgItemText(hDlg, IDC_EDIT3, member.phone, 20);
			//변경된 정보전달
			
			memlist.push_back(member);

			SendMessage(GetParent(hDlg), WM_ADD_LIST, 0, 0);
			//자신을 죽이기
			EndDialog(hDlg, IDOK);
		}
		case IDCANCEL: EndDialog(hDlg, IDCANCEL); return 0;//종료
		}
		return TRUE;
	}
	//return  true를 하면 기본제공 사용안함
	return FALSE;//기본제공되는 프로시져를 실행
}


BOOL CALLBACK Child1DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	Member member;
	switch (msg)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			GetDlgItemText(hDlg, IDC_EDIT1, member.name, 20);
			for (int i = 0; i < memlist.size(); i++)
			{
				if (memlist[i].name == member.name)
				{
					SendMessage(GetParent(hDlg), WM_Find_LIST, 0, i);
				}
			}
			return TRUE;
		}
		case IDCANCEL: EndDialog(hDlg, IDCANCEL); return 0;//종료

			return TRUE;
		}
		//return  true를 하면 기본제공 사용안함
		return FALSE;//기본제공되는 프로시져를 실행
	}
}