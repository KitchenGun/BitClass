#include <iostream>
using namespace std;

/*
구문 작성시 정상적인 흐름 <---> 비정상적인 흐름(예외)
*/
void exam1()
{
	int num1 = 10, num2 = 0;
	if (num2 == 0)
	{
		cout << "0으로 나눌수없다" << endl;
	}
	else
	{
		float result = (float)num1 / num2;//0으로 나눌수없다.
		cout << result << endl;
	}
}

void exam2()
{
	try
	{
		int num1 = 10, num2 = 0;

		if (num2 == 0)
			throw 10;//"0으로 나눌 수 없습니다";//예외 발생

		float result = (float)num1 / num2;//0으로 나눌수없다.
		cout << result << endl;
	}
	catch (const char* msg)//try 구문안에서 예외 발생시 호출된다
	{
		cout << msg << endl;
	}
	catch (int msg)
	{
		cout << msg << endl;
	}
	catch (...)
	{
		cout << "모든타입을 받을수있음" << endl;
	}
}

float mydiv(int n1, int n2)
{
	float result;
	if (n2 == 0)
	{
		throw "0으로 나눌수없음";
	}
	result = (float)n1 / n2;
	return result;
}

void exam3()
{
	try
	{
		float r = mydiv(10, 20);
		cout << "결과값:" << r << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

int main()
{
	exam3();
	return 0;
}