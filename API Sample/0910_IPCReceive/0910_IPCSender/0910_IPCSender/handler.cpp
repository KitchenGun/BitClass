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
	case IDCANCEL:			EndDialog(hDlg, IDCANCEL); return 0;//����
	}
	return TRUE;
}

void OnSendData(HWND hDlg)
{
	try
	{
		//1. �ڵ鰪 ȹ��
		HWND hwnd;
		fun_GetWindowHandle(TEXT("receive"), &hwnd);

		//2. �������� ȹ��
		MEMBER mem;
		fun_GetMemberData(hDlg, &mem);

		//3. ����
		fun_SendData(hDlg, hwnd, mem);

		//4. ������Ʈ���� �ʱ�ȭ
		fun_ControlDataInit(hDlg);
	}
	catch (const TCHAR *msg)
	{
		MessageBox(0, msg, TEXT("����"), MB_OK);
	}	
}

void OnEdit(HWND hDlg)
{
	try
	{
		//1. �ڵ鰪 ȹ��
		HWND hwnd;
		fun_GetWindowHandle(TEXT("receive"), &hwnd);

		//2. �������� ȹ��
		MEMBER mem;
		fun_GetMemberNameData(hDlg, &mem);

		//3. ����
		fun_SendEditData(hDlg, hwnd, mem);

		//4. ������Ʈ���� �ʱ�ȭ
		fun_ControlDataInit(hDlg);
	}
	catch (const TCHAR* msg)
	{
		MessageBox(0, msg, TEXT("���� �Ϸ�"), MB_OK);
	}
}

void OnSearch(HWND hDlg)
{
	try
	{
		//1. �ڵ鰪 ȹ��
		HWND hwnd;
		fun_GetWindowHandle(TEXT("receive"), &hwnd);

		//2. �������� ȹ��
		MEMBER mem;
		fun_GetMemberNameData(hDlg, &mem);

		//3. ����
		fun_SearchData(hDlg, hwnd, mem);

	}
	catch (const TCHAR* msg)
	{
		MessageBox(0, msg, TEXT("���� �Ϸ�"), MB_OK);
	}
}

void OnDelete(HWND hDlg)
{
	try
	{
		//1. �ڵ鰪 ȹ��
		HWND hwnd;
		fun_GetWindowHandle(TEXT("receive"), &hwnd);

		//2. �������� ȹ��
		MEMBER mem;
		fun_GetMemberNameData(hDlg, &mem);

		//3. ����
		fun_SendNameData(hDlg, hwnd, mem);

		//4. ������Ʈ���� �ʱ�ȭ
		fun_ControlDataInit(hDlg);
	}
	catch (const TCHAR* msg)
	{
		MessageBox(0, msg, TEXT("���� �Ϸ�"), MB_OK);
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
		MessageBox(0, msg, TEXT("�˻� ��� ������"), MB_OK);
	}
	return TRUE;
}