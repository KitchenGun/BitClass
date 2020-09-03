//송신자 - CUI
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
		cout << "핸들 획득 실패" << endl;
		return 0;
	}
	while (true)
	{
		cout << "1.메시지 " << "2.사각형 " << "3.타원 " << "4.선 " << "5.종료 " << endl;
		cin >> selectNum;
		switch (selectNum)
		{
		case 1:
			cout << "좌표 2개를 입력하세요" << endl;
			cout << "X축";
			cin >> pt.x;
			cout << "Y축";
			cin >> pt.y;

			SendMessage(hwnd, WM_MESSAGE, pt.x, pt.y);
			break;
		case 2://사각형
			cout << "RGB값입력하세요" << endl;
			cout << "R:";
			cin >> rgbNum[0];
			cout << "G:";
			cin >> rgbNum[1];
			cout << "B:";
			cin >> rgbNum[2];

			cout << "좌표 2개를 입력하세요" << endl;
			cout << "X축";
			cin >> pt.x;
			cout << "Y축";
			cin >> pt.y;
			cout << "X축크기";
			cin >> pt1.x;
			cout << "Y축크기";
			cin >> pt1.y;
			
			SendMessage(hwnd, WM_RECTANGLE, RGB(rgbNum[0], rgbNum[1], rgbNum[2]), MAKELPARAM(pt.x, pt.y));
			SendMessage(hwnd, WM_RECTANGLE, 0, MAKELONG(pt1.x, pt1.y));
			break;
		case 3://타원
			cout << "RGB값입력하세요" << endl;
			cout << "R:";
			cin >> rgbNum[0];
			cout << "G:";
			cin >> rgbNum[1];
			cout << "B:";
			cin >> rgbNum[2];

			cout << "좌표 2개를 입력하세요" << endl;
			cout << "X축";
			cin >> pt.x;
			cout << "Y축";
			cin >> pt.y;
			cout << "X축크기";
			cin >> pt1.x;
			cout << "Y축크기";
			cin >> pt1.y;

			SendMessage(hwnd, WM_ELLIPSE, RGB(rgbNum[0], rgbNum[1], rgbNum[2]), MAKELONG(pt.x, pt.y));
			SendMessage(hwnd, WM_ELLIPSE, 0, MAKELONG(pt1.x, pt1.y));
			break;
		case 4://라인
			cout << "RGB값입력하세요" << endl;
			cout << "R:";
			cin >> rgbNum[0];
			cout << "G:";
			cin >> rgbNum[1];
			cout << "B:";
			cin >> rgbNum[2];

			cout << "좌표 2개를 입력하세요" << endl;
			cout << "X축";
			cin >> pt.x;
			cout << "Y축";
			cin >> pt.y;
			cout << "X축";
			cin >> pt1.x;
			cout << "Y축";
			cin >> pt1.y;

			SendMessage(hwnd, WM_LINE, RGB(rgbNum[0], rgbNum[1], rgbNum[2]), MAKELONG(pt.x, pt.y));
			SendMessage(hwnd, WM_LINE, 0, MAKELONG(pt1.x, pt1.y));
			break;
		case 5://종료
			cout << "종료" << endl;
			return 0;

		}
	}
}