//�۽��� - CUI
#pragma comment (linker, "/subsystem:console")

#include <iostream>
using namespace std;
#include <Windows.h>


#define WM_MESSAGE WM_USER+100
#define WM_RECTANGLE WM_USER+101
#define WM_ELLIPSE WM_USER+102
#define WM_LINE WM_USER+103


int main()
{
	HWND  hwnd = FindWindow(0, TEXT("Window"));
	int selectNum;
	POINTS pt;
	POINTS pt1;
	int* rgbNum = new int[3];

	if (hwnd == 0)
	{
		cout << "�ڵ� ȹ�� ����" << endl;
		return 0;
	}
	while (true)
	{
		cout << "1.�޽��� " << "2.�簢�� " << "3.Ÿ�� " << "4.�� " << "5.���� " << endl;
		cin >> selectNum;
		switch (selectNum)
		{
		case 1:
			cout << "��ǥ 2���� �Է��ϼ���" << endl;
			cout << "X��";
			cin >> pt.x;
			cout << "Y��";
			cin >> pt.y;

			SendMessage(hwnd, WM_MESSAGE, pt.x, pt.y);
			break;
		case 2://�簢��
			cout << "RGB���Է��ϼ���" << endl;
			cout << "R:";
			cin >> rgbNum[0];
			cout << "G:";
			cin >> rgbNum[1];
			cout << "B:";
			cin >> rgbNum[2];

			cout << "��ǥ 2���� �Է��ϼ���" << endl;
			cout << "X��";
			cin >> pt.x;
			cout << "Y��";
			cin >> pt.y;
			cout << "X��ũ��";
			cin >> pt1.x;
			cout << "Y��ũ��";
			cin >> pt1.y;
			
			SendMessage(hwnd, WM_RECTANGLE, RGB(rgbNum[0], rgbNum[1], rgbNum[2]), MAKELPARAM(pt.x, pt.y));
			SendMessage(hwnd, WM_RECTANGLE, 0, MAKELONG(pt1.x, pt1.y));
			break;
		case 3://Ÿ��
			cout << "RGB���Է��ϼ���" << endl;
			cout << "R:";
			cin >> rgbNum[0];
			cout << "G:";
			cin >> rgbNum[1];
			cout << "B:";
			cin >> rgbNum[2];

			cout << "��ǥ 2���� �Է��ϼ���" << endl;
			cout << "X��";
			cin >> pt.x;
			cout << "Y��";
			cin >> pt.y;
			cout << "X��ũ��";
			cin >> pt1.x;
			cout << "Y��ũ��";
			cin >> pt1.y;

			SendMessage(hwnd, WM_ELLIPSE, RGB(rgbNum[0], rgbNum[1], rgbNum[2]), MAKELONG(pt.x, pt.y));
			SendMessage(hwnd, WM_ELLIPSE, 0, MAKELONG(pt1.x, pt1.y));
			break;
		case 4://����
			cout << "RGB���Է��ϼ���" << endl;
			cout << "R:";
			cin >> rgbNum[0];
			cout << "G:";
			cin >> rgbNum[1];
			cout << "B:";
			cin >> rgbNum[2];

			cout << "��ǥ 2���� �Է��ϼ���" << endl;
			cout << "X��";
			cin >> pt.x;
			cout << "Y��";
			cin >> pt.y;
			cout << "X��";
			cin >> pt1.x;
			cout << "Y��";
			cin >> pt1.y;

			SendMessage(hwnd, WM_LINE, RGB(rgbNum[0], rgbNum[1], rgbNum[2]), MAKELONG(pt.x, pt.y));
			SendMessage(hwnd, WM_LINE, 0, MAKELONG(pt1.x, pt1.y));
			break;
		case 5://����
			cout << "����" << endl;
			return 0;

		}
	}
}