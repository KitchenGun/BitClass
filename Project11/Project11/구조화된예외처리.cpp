#include <iostream>
using namespace std;

/*
���� �ۼ��� �������� �帧 <---> ���������� �帧(����)
*/
void exam1()
{
	int num1 = 10, num2 = 0;
	if (num2 == 0)
	{
		cout << "0���� ����������" << endl;
	}
	else
	{
		float result = (float)num1 / num2;//0���� ����������.
		cout << result << endl;
	}
}

void exam2()
{
	try
	{
		int num1 = 10, num2 = 0;

		if (num2 == 0)
			throw 10;//"0���� ���� �� �����ϴ�";//���� �߻�

		float result = (float)num1 / num2;//0���� ����������.
		cout << result << endl;
	}
	catch (const char* msg)//try �����ȿ��� ���� �߻��� ȣ��ȴ�
	{
		cout << msg << endl;
	}
	catch (int msg)
	{
		cout << msg << endl;
	}
	catch (...)
	{
		cout << "���Ÿ���� ����������" << endl;
	}
}

float mydiv(int n1, int n2)
{
	float result;
	if (n2 == 0)
	{
		throw "0���� ����������";
	}
	result = (float)n1 / n2;
	return result;
}

void exam3()
{
	try
	{
		float r = mydiv(10, 20);
		cout << "�����:" << r << endl;
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