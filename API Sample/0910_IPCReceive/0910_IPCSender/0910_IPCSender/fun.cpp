// fun.cpp

#include <Windows.h>
#include"Member.h"
#include "fun.h"
#include "resource.h"
#include<string>
extern HWND hCombo;

void fun_ControlInit(HWND hDlg)
{
	hCombo = GetDlgItem(hDlg, IDC_COMBO1);

	SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)"M");
	SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)"F");
}

void fun_GetWindowHandle(TCHAR * msg, HWND *phwnd)
{
	HWND hwnd = FindWindow(0, msg);
	if (hwnd == 0)
		throw TEXT("�������ڵ��� ã�� ���߽��ϴ�.");

	*phwnd = hwnd;
}

void fun_GetMemberData(HWND hDlg, MEMBER *pmem)
{
	pmem->id = GetDlgItemInt(hDlg, IDC_EDIT1, FALSE, FALSE);//id

	GetDlgItemText(hDlg, IDC_EDIT2, pmem->name, sizeof(pmem->name));//�̸�

	int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);//����
	if (i == 0)
		pmem->gender = 'm';
	else if (i == 1)
		pmem->gender = 'f';

	GetDlgItemText(hDlg, IDC_EDIT3, pmem->phone, sizeof(pmem->phone));//�̸�
}

void fun_GetMemberNameData(HWND hDlg, MEMBER* pmem)
{
	GetDlgItemText(hDlg, IDC_EDIT2, pmem->name, sizeof(pmem->name));//�̸�

	GetDlgItemText(hDlg, IDC_EDIT3, pmem->phone, sizeof(pmem->phone));//��ȭ��ȣ
}

void fun_SendData(HWND hDlg, HWND hwnd, MEMBER mem)
{
	COPYDATASTRUCT cds;
	cds.dwData = 0;
	cds.cbData = sizeof(MEMBER); // ������ data ũ��	
	cds.lpData = &mem; // ������ Pointer

	SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&cds);
}

void fun_SendNameData(HWND hDlg, HWND hwnd, MEMBER mem)
{
	COPYDATASTRUCT cds;
	cds.dwData = 1;
	cds.cbData = sizeof(MEMBER); // ������ data ũ��	
	cds.lpData = &mem; // ������ Pointer

	SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&cds);
}

void fun_SearchData(HWND hDlg, HWND hwnd, MEMBER mem)
{
	COPYDATASTRUCT cds;
	cds.dwData = 3;//
	cds.cbData = sizeof(MEMBER); // ������ data ũ��	
	cds.lpData = &mem; // ������ Pointer

	SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&cds);
}

void fun_SendEditData(HWND hDlg, HWND hwnd, MEMBER mem)
{
	COPYDATASTRUCT cds;
	cds.dwData = 2;
	cds.cbData = sizeof(MEMBER); // ������ data ũ��	
	cds.lpData = &mem; // ������ Pointer

	SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&cds);
}


void fun_ControlDataInit(HWND hDlg)
{
	SetDlgItemText(hDlg, IDC_EDIT1, TEXT(""));	//id
	SetDlgItemText(hDlg, IDC_EDIT2, TEXT(""));	//�̸�	
	SendMessage(hCombo, CB_SETCURSEL, 0, 0);	//����
	SetDlgItemText(hDlg, IDC_EDIT3, TEXT(""));	//��ȭ��ȣ	
}

void fun_DataReceive(HWND hDlg, LPARAM lParam)
{
	COPYDATASTRUCT* ps = (COPYDATASTRUCT*)lParam;
	MEMBER* pData = (MEMBER*)ps->lpData;
	TCHAR buf[20];
	_stprintf(buf, TEXT("%d"), pData->id);
	SetDlgItemText(hDlg,IDC_EDIT1,buf);	//id
	SetDlgItemText(hDlg, IDC_EDIT2, pData->name);
	if (pData->gender == 'm')
		SendDlgItemMessage(hDlg, IDC_COMBO1, CB_SETITEMDATA, 0, 0);
	else
		SendDlgItemMessage(hDlg, IDC_COMBO1, CB_SETITEMDATA, 0, 1);
	SetDlgItemText(hDlg, IDC_EDIT3,  pData->phone);
}