#pragma once
#include"wbglobal.h"


class Stu
{
private:
	const int num; 	//��� ��� ���� 
	char name[20];

public:
	Stu(int _num, const char* _name) : num(_num)//�ɹ� �ʱ�ȭ 
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
		os << "��ȣ : " << stu->num << "�̸� : " << stu->name;
		return os;
	}
};
