#include<iostream>

using namespace std;

//c 언어 구조체 구조체 안에 맴버로 데이터만 둘수있다
struct wbtime{	int hour;	int min;	int second;};

void printtime(wbtime t)
{
	cout << t.hour << ":" << t.min << ":" << t.second << endl;
}

void currenttime(wbtime* t)
{
	t->hour = 21;
	t->min = 3;
	t->second = 35;
}

void changemintime(wbtime* t, int min)
{
	t->min = min;
}

int main()
{
	wbtime t1;
	currenttime(&t1);
	printtime(t1);
	changemintime(&t1, 6);
	printtime(t1);

	return 0;
}