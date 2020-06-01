#pragma once
#include"wbglobal.h"


class Stu
{
private:
	const int num; 	//상수 멤버 변수 
	char name[20];

public:
	Stu(int _num, const char* _name) : num(_num)//맴버 초기화 
	{
		strcpy_s(name, sizeof(name), _name);
	}

	int GetNum()const
	{
		return num;
	}

	const char* GetName()const
	{
		return name;
	}

	void SetName(const char* value)
	{
		strcpy_s(name, sizeof(name), value);
	}

	friend ostream& operator<<(ostream& os, Stu* stu)
	{
		os << "번호 : " << stu->num << "이름 : " << stu->name;
		return os;
	}
};
