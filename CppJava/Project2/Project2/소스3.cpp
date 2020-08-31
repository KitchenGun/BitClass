/************************************************************
 function overloading
 -> 아래 코드가 정상적으로 동작할 수 있도록 함수 오버로딩을
	이용하여 구현하시오.
	출력 결과는 주석과 같이
*************************************************************/

#include <iostream>
using namespace std;


void foo(int a, int b, int c, int d)
{
	cout << a<<" : "<< b << " : " << c << " : " << d<<endl;
}
void foo(int a, int b, int c)
{
	cout << a << " : " << b << " : " << c << endl;
}
void foo(int a, int b)
{
	cout << a << " : " << b << endl;
}
void foo(int a)
{
	cout << a << endl;
}
int main()
{
	foo(10, 20, 30, 40);	// 10 : 20 : 30 : 40 
	foo(10, 20, 30);		// 10 : 20 : 30
	foo(10, 20);				// 10 : 20
	foo(10);				// 10 

	return 0;
}
