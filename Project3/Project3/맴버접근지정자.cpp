//�ɹ� ���� ������
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
//	//�ܺο��� ������ ����ϴ� ����
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