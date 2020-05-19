#include<iostream>
using namespace std;
//객체 초기화는 자신의 생성자에서 


class Person
{
protected:
	char name[20];
	int age;
public:
	Person(const char* _name, int _age)
	{
		strcpy_s(name, sizeof(name), _name);
		age = _age;
	}
public:
	void Print() const
	{
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
	}
	int getAge()const
	{
		return age;
	}
	const char* getName()const
	{
		return name;
	}
};

class Student:Person
{
	char subject[20];
	int number;
public:
	//자식 생성자에서는 부모 생성시 어떤 생성자를 호출할지를 결정해 줘야한다
	//만약 결정을 안해주면 부모는 인자 없는 디폴트 생성자를 호출하면서 생성된다
	Student(const char* _name,int _age,const char* _subj,int _num)
		:Person(_name,_age)
	{
		strcpy_s(subject, sizeof(subject), _subj);
		number = _num;
	}
public:
	void Print() const
	{//재정의 오버라이드
		//부모의 맴버함수의 형태를 리턴타입 이름 매개변수 리스트 동일하게 자식에게 적용
		cout << "name : " << name << endl;		//protected
		cout << "age : " << getAge() << endl;		//getset 호출/////////////////제일 권장되는 방식

		Person::Print();
		cout << "subject : " << subject << endl;
		cout << "number : " << number << endl;
	}
	

};

int main()
{
	Student stu("홍길동",20,"컴퓨터",1111);
	stu.Print();
	return 0;

}