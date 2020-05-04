#include<iostream>
// 캡슐화
using namespace std;
//c++ 언어 구조체 안에 맴버로 데이터와 함수를 둘수있다
struct wbtime
{
	int hour;
	int min;
	int second;

	void printtime()
	{
		cout << hour << ":" << min << ":" << second << endl;
	}

	void currenttime()
	{
		hour = 21;
		min = 3;
		second = 35;
	}

	void changemintime(int _min)
	{
		min = _min;
	}
};



int main()
{
	wbtime t1;
	t1.currenttime();
	t1.printtime();
	t1.changemintime(6);
	t1.printtime();

	return 0;
}