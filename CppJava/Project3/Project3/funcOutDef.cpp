#include<iostream>

using namespace std;
//.h파일에서 클래스 정의
class Sample
{
	int num;
public://클래스 내부에서 함수의 선언부만 작성
	void foo();
	int goo(int n1, int n2);
};

//.cpp 파일에 맴버 함수를 정의
//맴버 함수를 외부 정의
void Sample :: foo()
{

}
int Sample :: goo(int n1, int n2)
{

}