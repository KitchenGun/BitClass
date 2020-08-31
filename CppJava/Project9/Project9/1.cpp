#include<iostream>
using namespace std;


class Human
{
private:
	char name[20];
public:
	Human(const char* _name)
	{
		strcpy_s(name, sizeof(name), _name);
	}
public:
	virtual void Intro()
	{
		cout << name << "\t";
	}
};

class Student :public Human
{
private:
	int number;
public:
	Student(const char* _name,int _number):Human(_name)
	{
		number = _number;
	}
public:
	void Intro()
	{
		Human::Intro();
		cout << number << "\t";
	}
};


int main()
{
	Human H("����");
	Student S("���л�", 1234567);

	Human* pH;
	Student* pS;

	pH = &H;
	pS = &S;

	pH->Intro();		// ���� ���� ���
	pS->Intro();		// ���� ���� ���
	
	return 0;
}