//control.h
#pragma once
#include"member.h"

#define DATAMAX 10

class control
{
private:
	//(Ŭ���� �迭 ����)�����Ҽ��ִ� *����* �����
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




