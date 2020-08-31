#include<iostream>

using namespace std;
/*
c에서의 함수 식별자는 함수명
c++ 함수 식별자는 함수명 + 매개변수 리스트
함수의 이름은 같더라도 매개변수가 다르면 다른 함수로 실행한다
*/

bool isequal(int n1, int n2)
{
	return n1 == n2;
}
bool isequal(float n1, float n2)
{
	return n1 == n2;
}

int add(int n1, int n2)
{
	return n1 + n2;
}
float add(float n1, float n2)
{
	return n1 + n2;
}
double add(double n1, double n2)
{
	return n1 + n2;
}



int main()
{
	cout << isequal(10, 20) << endl;
	cout << isequal(20, 20) << endl;
	cout << isequal(10.1f, 20.1f) << endl;
	cout << isequal(20.1f, 20.1f) << endl;
	//=============================
	cout << add(10, 20) << endl;
	cout << add(10.1f, 20.1f) << endl;
	cout << add(10.1, 20.1) << endl;
	return 0;
}