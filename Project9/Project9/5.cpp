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
	virtual void Think()
	{
		cout << "부모의 입장에서 생각" << endl;
	}
};

class Student :public Human
{
private:
	int number;
public:
	Student(const char* _name, int _number) :Human(_name)
	{
		number = _number;
	}
public:
	void Intro()
	{
		Human::Intro();
		cout << number << endl;
	}
	void Think()
	{
		cout << "자식의 입장에서 생각" << endl;
	}
	void Study()
	{
		cout << "공부를 합니다" << endl;
	}
};

void main()
{
	Student K("홍길동", 9506299);
	K.Intro();		//이름과 학번 출력
	K.Think();		// 부모의 함수를 재정의
		   //부모의 Think() : "부모의 입장에서 생각" 문자열 출력
		   //자식의 Think() : "자식의 입장에서 생각" 문자열 출력
	K.Study();		// 자식만 가지고 있는 함수
					// "공부를 합니다" 문자열 출력
}
