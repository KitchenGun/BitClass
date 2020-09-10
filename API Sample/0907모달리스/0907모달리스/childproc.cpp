
#include <Windows.h>
#include "childproc.h"
#include <tchar.h>		//����Ÿ�� ����� ���� h 
#include "resource.h"
#include"data.h"

extern HWND g_hDlg;
//�Լ��� ���� ������ ����� ���� �׷��� ����ִ� ���� �� ���� ������ �ݵ�� hwnd �����־����

DATA* ptemp;

BOOL CALLBACK ChildDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG: 
	{
		//�ʱ�ȭ
		ptemp = (DATA*)lParam;
		SetDlgItemInt(hDlg, IDC_EDIT1, ptemp->x, 0);
		SetDlgItemInt(hDlg, IDC_EDIT2, ptemp->x, 0);

		SetDlgItemInt(hDlg, IDC_STATIC1, GetRValue(ptemp->color),0);
		SetDlgItemInt(hDlg, IDC_STATIC2, GetGValue(ptemp->color),0);
		SetDlgItemInt(hDlg, IDC_STATIC2, GetBValue(ptemp->color),0);

		HWND hscroll1 = GetDlgItem(hDlg, IDC_SCROLLBAR1);
		HWND hscroll2 = GetDlgItem(hDlg, IDC_SCROLLBAR2);
		HWND hscroll3 = GetDlgItem(hDlg, IDC_SCROLLBAR3);

		//��ũ�ѹ� �Ÿ� ����
		SetScrollRange(hscroll1, SB_CTL, 0, 255, TRUE);
		//��ũ�ѹ� ��ġ ����
		SetScrollPos(hscroll1, SB_CTL, GetRValue(ptemp->color, TRUE),0);

		SetScrollRange(hscroll2, SB_CTL, 0, 255, TRUE);
		SetScrollPos(hscroll2, SB_CTL, GetGValue(ptemp->color, TRUE),0);

		SetScrollRange(hscroll3, SB_CTL, 0, 255, TRUE);
		SetScrollPos(hscroll3, SB_CTL, GetBValue(ptemp->color, TRUE),0);
		return TRUE;
	}
	case WM_HSCROLL:
	{
		OnChildHScroll(hDlg, wParam, lParam);
		return 0;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			//����
			ptemp->x = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
			ptemp->y = GeDlgItemInt(hDlg, IDC_EDIT2, 0, 0);

			//����� ��������
			SendMessage(GetParent(hDlg), WM_APPLY_POSITION, 0, 0);

			return TRUE;
		}
		case IDCANCEL:	g_hDlg = 0;   EndDialog(hDlg, IDCANCEL); return 0;//����
		}
		return TRUE;
	}
	//return  true�� �ϸ� �⺻���� ������
	return FALSE;//�⺻�����Ǵ� ���ν����� ����
}

void OnChildHScroll(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	static int TempPos;
	static int Red = GetRValue(ptemp->color);
	static int Green = GetGValue(ptemp->color);
	static int Blue = GetBValue(ptemp->color);

	HWND hRed = GetDlgItem(hDlg, IDC_SCROLLBAR1);
	HWND hGreen = GetDlgItem(hDlg, IDC_SCROLLBAR2);
	HWND hBlue = GetDlgItem(hDlg, IDC_SCROLLBAR3);

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

	SetDlgItemInt(hDlg, IDC_STATIC1, GetRValue(ptemp->color), 0);
	SetDlgItemInt(hDlg, IDC_STATIC2, GetGValue(ptemp->color), 0);
	SetDlgItemInt(hDlg, IDC_STATIC3, GetBValue(ptemp->color), 0);

	if ((HWND)lParam == hRed)		Red = TempPos;
	if ((HWND)lParam == hGreen)		Green = TempPos;
	if ((HWND)lParam == hBlue)		Blue = TempPos;
	SetScrollPos((HWND)lParam, SB_CTL, TempPos, TRUE);

	//�θ��� ���� ���� ���� �����ϰ� �θ𿡰� �޽����� ���� ������� �˸�
	ptemp->color = RGB(Red, Green, Blue);

	SendMessage(GetParent(hDlg), WM_APPLY_COLOR, 0, 0);
}
