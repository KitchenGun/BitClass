/************************************************************
 정수값 2개를 교환하는 swap 함수를 레퍼런스를 사용해서 구현하시오.
*************************************************************/

#include <iostream>
using namespace std;
//참조자
void swap(int&n,int&n1,int &c);

int main()
{
	int num = 10, num1 = 20;
	int c;
	swap(num,num1,c);
	return 0;
}


void swap(int& n, int& n1,int &c)
{
	c = n;
	n = n1;
	n1 = c;

	cout << n << n1;
}
