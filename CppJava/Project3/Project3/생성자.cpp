//생성자
//객체 생성시 맴버 변수 초기화를 목적으로 갖는 특별한 함수 이다.
#include <iostream>
using namespace std;

//struct Sample
//{
//private:
//	int num1;
//	int num2;
//	int result;
//public:
//	void Add() 
//	{
//		result = num1 + num2;
//	}
////	void Sub()
//	{
//		result = num1 - num2;
//	}
////
////	void Print() 
//	{
//		cout << num1 << "+" << num2 << "=" <<result;
//	}
//};
//
//int main()
//{
//	//전통적인 구조체에서 생성과 동시에 초기화 문법 더이상 사용 불가능
//	//데이터가 외부에서 접근할수없도록 은닉되었기 때문이다.
//	//대안은 초기화를 위한 생성자 사용
//	Sample sam = { 10,20 };
//
//	sam.Add();
//	sam.Print();
//	return 0;
//}



//생성자는 객체생성시 자동으로 호출
//생성자는 리턴 타입 없음 구조체 명과 동일해야한다 매개변수는 존재
//-오버로딩 기본값
struct Sample
{
private:
	int n1;
	int n2;
public:
	Sample()
	{
		n1 = 0;
		n2 = 0;
		cout << "생성자()" << endl;
	}
	Sample(int num1 ,int num2)
	{
		n1 = num1;
		n2 = num2;
		cout << "생성자()" << endl;
	}
	void Print()
	{
		cout << n1 <<","<< n2 << endl;
	}
};


int main()
{
	Sample sam1;//객체 생성
	sam1.Print();
	Sample sam2(10, 20);
	sam2.Print();
	cout << sizeof(sam1) << endl;//8

	return 0;

}