#pragma comment (linker, "/subsystem:console")
#include <iostream>
using namespace std;
//window api���
#include <Windows.h>

int main()
{
	//window�ڵ��� �������� �ڵ��� �ý��ۿ� ������ ������ ������ �ִ�.
	//1. Ŭ������
	//2. Ÿ��Ʋ �̸�
	HWND hwnd = FindWindow(0, TEXT("����"));
	if (hwnd == 0)
	{
		MessageBox(0, TEXT("���� ������"), TEXT("�˸�"), MB_OK);
		return 0;
	}
	printf("������ �ڵ鰪%d",(int)hwnd);

	MoveWindow(hwnd, 0, 0, 100, 100, FALSE);
	return 0;
}