#include<iostream>

/*
덧셈	정수1 2 연산() 결과출력()
뺄셈	정수1 2 연산() 결과출력()
나누셈	정수1 2 연산() 결과출력()
곱셈	정수1 2 연산() 결과출력()
---------------------------------
만들 객체 공동 부분을 갖는 부모 클래스를 생성
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
	cout << "문제 개수";
	cin >> number;
	Calculate* *callist = new Calculate*[number];
	//calculate*의 값을 저장하는 동적 배열
	//====================================
	for (int i = 0; i < number; i++)
	{
		int idx = rand() % 2;//(0~1)//덧셈 뺄셈 결정
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
	//-------------------결과 생성
	for (int i = 0; i < number; i++)
	{
		callist[i]->CalculateResult();
	}
	//-------------------결과 출력
	//for (int i = 0; i < number; i++)
	//{
	//	printf("[%03d]\n", i + 1);
	//	callist[i]->Print();
	//}
	//덧셈만 출력
	//rtti(runtime type infomation)
	for (int i = 0; i < number; i++)
	{
		//덧셈만 출력
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