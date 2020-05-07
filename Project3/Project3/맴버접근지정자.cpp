//맴버 접근 지정자
/*
private

public

protected
*/
#include <iostream>
using namespace std;
//
//struct Sample
//{
//	int num;
//
//	void foo() {}
//	void woo() {}
//};
//
//struct Sample1
//{
//private:
//	int num;
//public:
//	void foo() {}
//	void woo() {}
//};
////int main()
//{
//	Sample1 sam2;
//	//sam2.num;
//	sam2.foo();
//	sam2.woo();
//	Sample sam1;
//	//외부에서 접근을 허용하는 구조
//	sam1.num;
//	sam1.foo();
//	sam1.woo();
//
//	return 0;
//}


struct Sample
{
private:
	int num1;
private:
	void test1() {}
public:
	void test2() {}
};

int main()
{
	Sample sam1;
	sam1.test2();
}