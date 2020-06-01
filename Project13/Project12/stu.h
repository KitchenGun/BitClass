#pragma once
#include"wbglobal.h"


class Stu
{
private:
	const int num; 	//상수 멤버 변수 
	char name[20];

	int c;//성적
	int cpp;//성적
	int java;//성적
	float average;//평균

public:
	//학번 이름만 인자전달로 초기화
	//성적 정보 는 기본 0값 초기화
	Stu(int _num, const char* _name) : num(_num),c(0),cpp(0),java(0)//맴버 초기화 
	{
		strcpy_s(name, sizeof(name), _name);
		average = 0.0f;
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
		os << "C언어:" << stu->c << "c++언어:" << stu->cpp;
		os << "java언어:" << stu->java << "평균:" << stu->average;
		return os;
	}

	void SetScore(int _c, int _cpp, int _java)
	{
		c = _c;
		cpp = _cpp;
		java = _java;
		average = (c + cpp + java) / 3.0f;
	}

};
