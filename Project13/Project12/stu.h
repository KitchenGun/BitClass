#pragma once
#include"wbglobal.h"


class Stu
{
private:
	const int num; 	//��� ��� ���� 
	char name[20];

	int c;//����
	int cpp;//����
	int java;//����
	float average;//���

public:
	//�й� �̸��� �������޷� �ʱ�ȭ
	//���� ���� �� �⺻ 0�� �ʱ�ȭ
	Stu(int _num, const char* _name) : num(_num),c(0),cpp(0),java(0)//�ɹ� �ʱ�ȭ 
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
		os << "��ȣ : " << stu->num << "�̸� : " << stu->name;
		os << "C���:" << stu->c << "c++���:" << stu->cpp;
		os << "java���:" << stu->java << "���:" << stu->average;
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
