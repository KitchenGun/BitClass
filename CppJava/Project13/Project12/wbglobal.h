#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

enum keydata
{
	NO_DEFINED, F1, F2, F3, F4, F5, F6, F7, ESC
};

class wbglobal
{
public:
	static void clrscr();//ȭ���� ����� �޼���
	static void pause();//ȭ���� ��� ���ߴ� �޼���
	static int getnum(const char* title);//���� �Է¹޴� �޼���
	static const char* getstr(const char* title);//���ڿ��� �Է¹޴� �޼���
	static keydata getkey();//���Ű�� �Է¹޴� �޼���

private://��ü�� �������� ���ϰ� �ϱ����� private���� ����
	wbglobal()
	{

	}
};