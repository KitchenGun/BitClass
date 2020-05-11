/************************************************************
다음 class 가 정상적으로 동작하도록 생성자를 완성하시오
	  생성자에서 받은 인자를 data에 저장하시오.
*************************************************************/
#include <iostream>

using namespace std;

class Sample
{
	int    data;
public:
	//생성자 구현
	Sample() :data(0)
	{

	}
	Sample(int n1):data(n1)
	{

	}
public:
	
	void Print() { cout << "저장값 : " << data << endl; }
};

void main()
{
	Sample   a1(10);
	Sample   a2;       // 전달된 값이 없으므로 0으로 초기화 할것

	a1.Print();
	a2.Print();
}
