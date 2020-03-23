//entry point 함수 반드시 문법적으로 필요한 함수
//프로그램의 시작은 여기서 부터이다
#include<stdio.h>//헤더 파일 printf의 선언문을 가지고 있다.
void func1();
void func2();
void foo();

void main()
{
	//미리 만들어서 제공되는 함수 -> 라이브러리함수
	printf("main()\n");//printf함수 호출
	
	func1();
	func2();
	foo();
}

void func1()
{
	printf("func1()\n");
}


void func2()
{
	printf("func2()\n");
}