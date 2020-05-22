#include<iostream>
using namespace std;


class Date
{
private:
	int year, month, day;
public:
	Date(int _year, int _month, int _day) 
	{
		year = _year;
		month = _month;
		day = _day;
	}
public:
	void OutNow()
	{
		cout << year << "-" << month << "-" << day << "\t";
	}
};

class Time
{
private:
	int hour, min, sec;
public:
	Time(int _hour, int _min, int _sec)
	{
		hour = _hour;
		min = _min;
		sec = _sec;
	}
	void OutNow()
	{
		cout << hour << ":" << min << ":" << sec << "\t";
	}
};


class Now:public Date,public Time
{
public:
	Now(int _year, int _month, int _day, int _hour, int _min, int _sec) :Date(_year, _month, _day), Time(_hour, _min, _sec)
	{

	}
public:
	void OutNow()
	{
		Date::OutNow();
		Time::OutNow();
	}
};

int main()
{
	Now N(2009, 5, 10, 12, 30, 58);
	N.OutNow();		// 날짜 시간 출력 ex)"2020-05-22 09:10:25"
	return 0;
}