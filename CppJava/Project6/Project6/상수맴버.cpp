#include <iostream>

using namespace std;

/*
상수 맴버 변수 반드시 콜론 초기화 에서 초기화
상수 맴버 함수 해당 함수 내에서는 절대로 맴버변수의 값을 수정 할 수 없다
				따라서 상수 맴버 함수 에서는 상수 맴버 함수의 호출만 가능
*/

class Member
{
	const int id;//상수 변수
	int testnum;//맴버 변수
public :
	Member(int _id) :id(_id)
	{
		testnum = _id;
	}
public:
	void func1()
	{
		//id = 10;

		testnum = 10;

	}
	void func2()
	{

	}
	void func3() const
	{

	}

	void constfun1(int temp) const
	{//상수 맴버 함수 
		temp++;//지역 변수 수정 가능
		//testnum++;//error맴버 변수 수정 불가능
		//func2();//error일반 맴버 함수
		func3();//ok상수 맴버 함수
	}
};

int main()
{
	Member member(10);
	member.constfun1(1);//수정 불가능

	return 0;
}