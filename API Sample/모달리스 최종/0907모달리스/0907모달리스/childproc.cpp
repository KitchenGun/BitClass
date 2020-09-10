//childproc.cpp

#include <Windows.h>
#include "childproc.h"
#include <tchar.h>		//범용타입 사용을 위한 h 
#include "resource.h"
#include "data.h"

extern HWND g_hDlg;		
//함수의 선언개념과 동일,어딘가에 반드시  HWND g_hDlg가 선언되어 있어야 함

DATA *ptemp;

BOOL CALLBACK ChildDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_HSCROLL:
	{
		OnChildHScroll(hDlg, wParam, lParam);
		return TRUE;
	}
	case WM_INITDIALOG:
	{
		ptemp = (DATA*)lParam;

		SetDlgItemInt(hDlg, IDC_EDIT1, ptemp->x, 0);
		SetDlgItemInt(hDlg, IDC_EDIT2, ptemp->y, 0);

		SetDlgItemInt(hDlg, IDC_STATIC1, GetRValue(ptemp->color), 0);
		SetDlgItemInt(hDlg, IDC_STATIC2, GetGValue(ptemp->color), 0);
		SetDlgItemInt(hDlg, IDC_STATIC3, GetBValue(ptemp->color), 0);

		//스크롤바 초기화
		HWND hscroll1 = GetDlgItem(hDlg, IDC_SCROLLBAR1);
		HWND hscroll2 = GetDlgItem(hDlg, IDC_SCROLLBAR2);
		HWND hscroll3 = GetDlgItem(hDlg, IDC_SCROLLBAR3);

		//Range : 스크롤바의 범위를 설정
		SetScrollRange(hscroll1, SB_CTL, 0, 255, TRUE);
		//Pos : 최초 스크롤바의 위치 
		SetScrollPos(hscroll1, SB_CTL, GetRValue(ptemp->color), TRUE);

		SetScrollRange(hscroll2, SB_CTL, 0, 255, TRUE);
		SetScrollPos(hscroll2, SB_CTL, GetGValue(ptemp->color), TRUE);

		SetScrollRange(hscroll3, SB_CTL, 0, 255, TRUE);
		SetScrollPos(hscroll3, SB_CTL, GetBValue(ptemp->color), TRUE);

		return TRUE;
	}

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{		
		//적용		
		case IDOK:
		{
			//변경시키면 됨.
			ptemp->x = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
			ptemp->y = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);

			//변경된 사실을 알림
			SendMessage(GetParent(hDlg), WM_APPLY_POSITION, 0, 0);

			return TRUE;
		}
		case IDCANCEL:  g_hDlg = 0;  EndDialog(hDlg, IDCANCEL); return 0;
		}
		return TRUE;
	}

	return FALSE;	// 제공되는 기본 프로서저를 호출하게 됨..... 
}


void OnChildHScroll(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	static int TempPos;
	static int Red		= GetRValue(ptemp->color);
	static int Green	= GetGValue(ptemp->color);
	static int Blue		= GetBValue(ptemp->color);

	HWND hRed	= GetDlgItem(hDlg, IDC_SCROLLBAR1);
	HWND hGreen = GetDlgItem(hDlg, IDC_SCROLLBAR2);
	HWND hBlue	= GetDlgItem(hDlg, IDC_SCROLLBAR3);

	if ((HWND)lParam == hRed)		TempPos = Red;// 
	if ((HWND)lParam == hGreen)		TempPos = Green;// 
	if ((HWND)lParam == hBlue)		TempPos = Blue;// 

	switch (LOWORD(wParam)) 
	{
	case SB_LINELEFT:
		TempPos = max(0, TempPos - 1);
		break;
	case SB_LINERIGHT:
		TempPos = min(255, TempPos + 1);
		break;
	case SB_PAGELEFT:
		TempPos = max(0, TempPos - 10);
		break;
	case SB_PAGERIGHT:
		TempPos = min(255, TempPos + 10);
		break;
	case SB_THUMBTRACK:
		TempPos = HIWORD(wParam);
		break;
	}

	if ((HWND)lParam == hRed)		Red = TempPos;
	if ((HWND)lParam == hGreen)		Green = TempPos;
	if ((HWND)lParam == hBlue)		Blue = TempPos;

	SetScrollPos((HWND)lParam, SB_CTL, TempPos, TRUE);

	//static 처리.
	SetDlgItemInt(hDlg, IDC_STATIC1, Red, 0);
	SetDlgItemInt(hDlg, IDC_STATIC2, Green, 0);
	SetDlgItemInt(hDlg, IDC_STATIC3, Blue, 0);


	//부모의 전역변수의 값을 수정하고, 부모에게 메시지를 전달(수정된 사실을 알림)
	ptemp->color = RGB(Red, Green, Blue);

	SendMessage(GetParent(hDlg), WM_APPLY_COLOR, 0, 0);
}