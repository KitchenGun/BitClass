#include<iostream>
// ĸ��ȭ
using namespace std;
//c++ ��� ����ü �ȿ� �ɹ��� �����Ϳ� �Լ��� �Ѽ��ִ�
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