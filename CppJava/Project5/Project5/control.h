//control.h
#pragma once
#include"member.h"

#define DATAMAX 10

class control
{
private:
	//(클래스 배열 생성)저장할수있는 *공간* 만들기
	Member* memlist[DATAMAX];
public:
	control();
	~control();
public:
	void SelectAll();
	void Insert();
	void Select();
private:
	int NumberToIdx(int number);
	int NameToIdx(const char* name);
};




