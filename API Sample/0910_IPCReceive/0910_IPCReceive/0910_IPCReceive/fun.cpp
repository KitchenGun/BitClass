#include"Member.h"

extern vector<MEMBER> memlist;
extern HWND g_hView;
HWND g_send=0;

void fun_GetHandle(HWND hDlg)
{
	g_hView = GetDlgItem(hDlg, IDC_LIST1);
}

void fun_ListViewHeader(HWND hDlg, HWND g_hView)
{
	LVCOLUMN COL;

	// ����� �߰��Ѵ�.
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 80;
	COL.pszText = TEXT("ȸ����ȣ");				// ù ��° ���
	COL.iSubItem = 0;
	SendMessage(g_hView, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.pszText = TEXT("ȸ���̸�");			// �� ��° ���
	COL.cx = 120;
	COL.iSubItem = 1;
	SendMessage(g_hView, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);

	COL.cx = 90;
	COL.pszText = TEXT("����");				// �� ��° ���
	COL.iSubItem = 2;
	SendMessage(g_hView, LVM_INSERTCOLUMN, 2, (LPARAM)&COL);

	COL.cx = 150;
	COL.pszText = TEXT("��ȭ��ȣ");				// �� ��° ���
	COL.iSubItem = 3;
	SendMessage(g_hView, LVM_INSERTCOLUMN, 3, (LPARAM)&COL);

	ListView_SetExtendedListViewStyle(g_hView,
		LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP);
}

void fun_Data(HWND hDlg, LPARAM lParam)
{
	COPYDATASTRUCT* ps = (COPYDATASTRUCT*)lParam;
	MEMBER* pData = (MEMBER*)ps->lpData;
	if (ps->dwData == 0)
	{
		fun_Save(hDlg, lParam);
	}
	else if(ps->dwData == 1)
	{
		fun_Delete(hDlg, lParam);
	}
	else if (ps->dwData == 2)
	{
		fun_Edit(hDlg, lParam);

	}
	else if (ps->dwData == 3)
	{
		g_send = FindWindow(0,TEXT("send"));
		fun_Search(hDlg, lParam);
	}
}

void fun_Save(HWND hDlg, LPARAM lParam)
{
	COPYDATASTRUCT* ps = (COPYDATASTRUCT*)lParam;
	MEMBER* pData = (MEMBER*)ps->lpData;
	memlist.push_back(*pData);
}


void fun_Edit(HWND hDlg, LPARAM lParam)
{
	COPYDATASTRUCT* ps = (COPYDATASTRUCT*)lParam;
	MEMBER* pData = (MEMBER*)ps->lpData;
	for (int i = 0; i < (int)memlist.size(); i++)
	{
		MEMBER mem = memlist[i];
		if (_tcscmp(mem.name, pData->name) == 0)
		{
			//���� ����
			_tcscpy_s(memlist[i].phone, _countof(mem.phone), pData->phone);
			//����Ʈ�並 �ٽ� ���
			fun_ListViewPrint(hDlg);

			throw TEXT("���� �Ϸ�");
			break;
		}
	}
}

void fun_Search(HWND hDlg, LPARAM lParam)
{
	COPYDATASTRUCT* ps = (COPYDATASTRUCT*)lParam;
	MEMBER* pData = (MEMBER*)ps->lpData;
	for (int i = 0; i < (int)memlist.size(); i++)
	{
		MEMBER mem = memlist[i];
		if (_tcscmp(mem.name, pData->name) == 0)
		{
			COPYDATASTRUCT cds;
			cds.dwData = 0;
			cds.cbData = sizeof(MEMBER); // ������ data ũ��	
			cds.lpData = &mem; // ������ Pointer

			SendMessage(g_send, WM_COPYDATA, 0, (LPARAM)&cds);
			throw TEXT("�˻� �Ϸ�");
			break;
		}
	}
}

void fun_Delete(HWND hDlg, LPARAM lParam)
{
	COPYDATASTRUCT* ps = (COPYDATASTRUCT*)lParam;
	MEMBER* pData = (MEMBER*)ps->lpData;
	for (int i = 0; i < (int)memlist.size(); i++)
	{
		MEMBER mem = memlist[i];
		if (_tcscmp(mem.name, pData->name) == 0)
		{
			//����ҿ��� ����
			vector<MEMBER>::iterator itr = memlist.begin();
			memlist.erase(itr + i);

			//����Ʈ�並 �ٽ� ���
			fun_ListViewPrint(hDlg);
			
			throw TEXT("���� �Ϸ�");
			break;
		}
	}
}

void fun_ListViewPrint(HWND hDlg)
{
	//����Ʈ�ڽ���ü ����
	ListView_DeleteAllItems(g_hView);

	//��ü ���������� ���
	TCHAR temp[20];
	for (int i = 0; i < (int)memlist.size(); i++)
	{
		MEMBER mem = memlist[i];

		// �ؽ�Ʈ�� �̹����� ���� �����۵��� ����Ѵ�.
		LVITEM LI;

		LI.mask = LVIF_TEXT | LVIF_IMAGE;

		LI.iImage = 0;
		LI.iItem = i;	//���� ����
		LI.iSubItem = 0;//�������� �÷��ε���
		wsprintf(temp, TEXT("%d"), mem.id);
		LI.pszText = temp;			// ù ��° ������
		SendMessage(g_hView, LVM_INSERTITEM, 0, (LPARAM)&LI);

		LI.iSubItem = 1;	// �������� �÷��ε��� 
		LI.pszText = mem.name;
		SendMessage(g_hView, LVM_SETITEM, 0, (LPARAM)&LI);

		LI.iSubItem = 2;
		wsprintf(temp, TEXT("%s"), (mem.gender == 'm' ? TEXT("����") : TEXT("����")));
		LI.pszText = temp;
		SendMessage(g_hView, LVM_SETITEM, 0, (LPARAM)&LI);

		LI.iSubItem = 3;
		LI.pszText = mem.phone;
		SendMessage(g_hView, LVM_SETITEM, 0, (LPARAM)&LI);
	}
}