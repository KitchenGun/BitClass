#include<iostream>

using namespace std;

void exam1()//�Լ��� �̸��� �ּ��� ��ġ���� ������
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
	int(*f3)(int, int);//����
	f3 = add;//�ʱ�ȭ
	cout << f3(10, 20) << endl;//ȣ��

	int(*f2)() = goo;
	f2();//gooȣ��
	
	void (*f1)(int);
	f1 = foo;
	foo(10);//�Լ� ȣ��: �ش��ּ��̵�
	f1(10);//�Լ� ������ : �Լ� ������ ȣ��
}
//======================================�Լ��� ���� ����
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
//�Լ� �����Ϳ� typedef(����Ÿ�Ը�� ������ ���ο� Ÿ�Ը��� ����°�)
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