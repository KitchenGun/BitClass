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
	static void clrscr();//화면을 지우는 메서드
	static void pause();//화면을 잠시 멈추는 메서드
	static int getnum(const char* title);//수를 입력받는 메서드
	static const char* getstr(const char* title);//문자열을 입력받는 메서드
	static keydata getkey();//기능키를 입력받는 메서드

private://개체를 생성하지 못하게 하기위해 private으로 접근
	wbglobal()
	{

	}
};