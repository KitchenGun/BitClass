#include<iostream>
using namespace std;
/*
부모의 맴버 변수와 맴버 함수는 자식에게 상속된다

*/
class Parent
{//부모
	int num1;
public:
	void fun1()
	{
		cout << "fun1" << endl;
	}
};

class Child : public Parent
{//자식 //파생 클래스
	int num2;
public:
	void fun2()
	{
		cout << "fun2" << endl;
	}
};

int main()
{
	cout << sizeof(Parent) << endl;
	cout << sizeof(Child) << endl;

	Parent p1;
	p1.fun1();

	Child c1;
	c1.fun1();
	c1.fun2();
	return 0;
}