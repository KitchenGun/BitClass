#include <Windows.h>
#include<tchar.h>
#include "handler.h"
#include"Member.h"
#include "fun.h"
#include"resource.h"

HWND hCombo;

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	fun_ControlInit(hDlg);

	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDOK:					OnSendData(hDlg);		break;
	case IDC_BUTTON1:		OnEdit(hDlg);				 break;
	case IDC_BUTTON2:		OnSearch(hDlg);			 break;
	case IDC_BUTTON3:		OnDelete(hDlg);			 break;
	case IDCANCEL:			EndDialog(hDlg, IDCANCEL); return 0;//종료
	}
	return TRUE;
}

void OnSendData(HWND hDlg)
{
	try
	{
		//1. 핸들값 획득
		HWND hwnd;
		fun_GetWindowHandle(TEXT("receive"), &hwnd);

		//2. 전달정보 획득
		MEMBER mem;
		fun_GetMemberData(hDlg, &mem);

		//3. 전송
		fun_SendData(hDlg, hwnd, mem);

		//4. 전송컨트롤을 초기화
		fun_ControlDataInit(hDlg);
	}
	catch (const TCHAR *msg)
	{
		MessageBox(0, msg, TEXT("오류"), MB_OK);
	}	
}

void OnEdit(HWND hDlg)
{
	try
	{
		//1. 핸들값 획득
		HWND hwnd;
		fun_GetWindowHandle(TEXT("receive"), &hwnd);

		//2. 전달정보 획득
		MEMBER mem;
		fun_GetMemberNameData(hDlg, &mem);

		//3. 전송
		fun_SendEditData(hDlg, hwnd, mem);

		//4. 전송컨트롤을 초기화
		fun_ControlDataInit(hDlg);
	}
	catch (const TCHAR* msg)
	{
		MessageBox(0, msg, TEXT("수정 완료"), MB_OK);
	}
}

void OnSearch(HWND hDlg)
{
	try
	{
		//1. 핸들값 획득
		HWND hwnd;
		fun_GetWindowHandle(TEXT("receive"), &hwnd);

		//2. 전달정보 획득
		MEMBER mem;
		fun_GetMemberNameData(hDlg, &mem);

		//3. 전송
		fun_SearchData(hDlg, hwnd, mem);

	}
	catch (const TCHAR* msg)
	{
		MessageBox(0, msg, TEXT("삭제 완료"), MB_OK);
	}
}

void OnDelete(HWND hDlg)
{
	try
	{
		//1. 핸들값 획득
		HWND hwnd;
		fun_GetWindowHandle(TEXT("receive"), &hwnd);

		//2. 전달정보 획득
		MEMBER mem;
		fun_GetMemberNameData(hDlg, &mem);

		//3. 전송
		fun_SendNameData(hDlg, hwnd, mem);

		//4. 전송컨트롤을 초기화
		fun_ControlDataInit(hDlg);
	}
	catch (const TCHAR* msg)
	{
		MessageBox(0, msg, TEXT("삭제 완료"), MB_OK);
	}
}

BOOL OnCopyData(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	try
	{
		fun_DataReceive(hDlg, lParam);
	}
	catch (const TCHAR* msg)
	{
		MessageBox(0, msg, TEXT("검색 결과 가져옴"), MB_OK);
	}
	return TRUE;
}