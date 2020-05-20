#include<iostream>

/*
����	����1 2 ����() ������()
����	����1 2 ����() ������()
������	����1 2 ����() ������()
����	����1 2 ����() ������()
---------------------------------
���� ��ü ���� �κ��� ���� �θ� Ŭ������ ����
*/
using namespace std;

class Calculate
{
private:
	int num1;
	int num2;
	float result;
public:
	Calculate()
	{
		num1 = num2 = 0;
		result = 0.0f;
	}
	Calculate(int _num1, int _num2)
	{
		num1 = _num1;
		num2 = _num2;
		result = 0.0f;
	}
	int getNum1() const
	{
		return num1;
	}
	int getNum2() const
	{
		return num2;
	}
	float getResult() const
	{
		return result;
	}
	void setResult(float value)
	{
		result = value;
	}
public:
	virtual void CalculateResult()
	{
		 
	}
	virtual void Print() const
	{
		
	}
};

class Add :public Calculate
{
public:
	Add()
	{
		
	}
	Add(int n1, int n2):Calculate(n1,n2)
	{

	}
public:
	void CalculateResult()
	{
		setResult((float)getNum1() + getNum2());
	}
	void Print() const
	{
		cout << getNum1() << "+";
		cout << getNum2() << "=";
		cout << getResult() << endl;
	}
};
class Sub :public Calculate
{
public:
	Sub()
	{

	}
	Sub(int n1, int n2) :Calculate(n1, n2)
	{

	}
public:
	void CalculateResult()
	{
		setResult((float)getNum1() - getNum2());
	}
	void Print() const
	{
		cout << getNum1() << "-" ;
		cout << getNum2() << "=" ;
		cout << getResult() << endl;
	}
};


int main()
{
	srand((unsigned int)time_t(NULL));
	int number;
	cout << "���� ����";
	cin >> number;
	Calculate* *callist = new Calculate*[number];
	//calculate*�� ���� �����ϴ� ���� �迭
	//====================================
	for (int i = 0; i < number; i++)
	{
		int idx = rand() % 2;//(0~1)//���� ���� ����
		int num1 = (rand() % 9) + 1;//(1~9);
		int num2 = (rand() % 9) + 1;//(1~9);
		if (idx == 0)
		{
			callist[i] = new Add(num1, num2);
		}
		else
		{
			callist[i] = new Sub(num1, num2);
		}
	}
	//-------------------��� ����
	for (int i = 0; i < number; i++)
	{
		callist[i]->CalculateResult();
	}
	//-------------------��� ���
	//for (int i = 0; i < number; i++)
	//{
	//	printf("[%03d]\n", i + 1);
	//	callist[i]->Print();
	//}
	//������ ���
	//rtti(runtime type infomation)
	for (int i = 0; i < number; i++)
	{
		//������ ���
		//Add* add = dynamic_cast<Add*>(callist[i]);
		//if (add != NULL)
		{
			printf("[%03d]", i + 1);
			callist[i]->Print();
		}
	}
	delete[] callist;
	return 0;
}