#include<iostream>

using namespace std;

void exam1()//함수의 이름도 주소의 위치값을 가진다
{
	cout << exam1 << endl;
}

void foo(int n1)
{
	cout << n1 << endl;
}
int goo()
{
	cout << "goo"<<endl;
	return 10;
}
int add(int n1, int n2)
{
	return n1 + n2;
}

void exam2()
{
	int(*f3)(int, int);//선언
	f3 = add;//초기화
	cout << f3(10, 20) << endl;//호출

	int(*f2)() = goo;
	f2();//goo호출
	
	void (*f1)(int);
	f1 = foo;
	foo(10);//함수 호출: 해당주소이동
	f1(10);//함수 포인터 : 함수 포인터 호출
}
//======================================함수의 인자 전달
float add3(int n1, int n2)
{
	return n1 + n2;
}
float sub3(int n1, int n2)
{
	return n1 - n2;
}
float mul3(int n1, int n3)
{
	return n1 * n3;
}
float div3(int n1, int n3)
{
	return (float)n1 / n3;
}

float cal(int num1, int num2, float(*fun)(int, int))
{
	return fun(num1, num2);
}

void exam3()
{
	float value = cal(10, 20, add3);
	cout << value << endl;
	cout << cal(10,20,mul3) << endl;
}

//==================================
//함수 포인터와 typedef(기존타입명과 동일한 새로운 타입명을 만드는것)
typedef unsigned int unit;
typedef int(*FUN)(int, int);

int max4(int n1, int n2)
{
	return n1 > n2 ? n1 : n2;
}

void exam4()
{
	FUN fun2 = max4;
	cout << fun2(10, 20) << endl;
	int(*fun1)(int, int);
	fun1 = max4;
	cout << fun1(20, 40) << endl;

	unsigned int num1 = 10;
	unit num2 = 20;
}

int main()
{
	exam3();
	return 0;
}