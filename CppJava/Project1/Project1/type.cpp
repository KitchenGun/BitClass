#include<iostream>

using namespace std;

int main()
{
	//bool true false 값을 가진다

	bool istest;
	istest = true;
	cout << istest << endl;
	istest = false;
	cout << istest << endl;
	//==============================
	istest = 1;
	//istest = -1;
	//bool 형에 정수타입 강제로 넣으면 경고가 뜬다
	cout << istest << endl;
	return 0;


}