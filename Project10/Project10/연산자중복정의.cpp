#include<iostream>
//이항 연산자 (산술:+,-,*,/ 비교:==)
using namespace std;

class MyDate
{
	int year;
	int month;
	int day;
public:
	MyDate(int y, int m, int d) :year(y), month(m), day(d)
	{

	}
public:
	void Print() const
	{
		cout.width(4);//printf("02%d");
		cout.fill('0');
		cout << year << "-";
		cout.width(2);
		cout.fill('0');
		cout << month << "-";
		cout.width(2);
		cout.fill('0');
		cout << day << endl;
	}
	bool Equal(const MyDate& d)
	{
		if (year == d.year && month == d.month && day == d.day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator==(const MyDate &d)
	{
		if (year == d.year && month == d.month && day == d.day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	MyDate operator+(int _day)
	{
		MyDate temp(year,month,day+_day);

		return temp;
	}
};

int main()
{
	MyDate d1(2020, 5, 7), d2(2020, 5, 7);
	d1.Print();
	d2.Print();
	//두 객체 날짜가 동일한지
	//bool b1 = d1.Equal(d2);
	
	if (d1 == d2)//d1.operator == (d2)
	{
		cout << "같다" << endl;
	}
	else
	{
		cout << "다르다" << endl;
	}
	//산술 연산 int num = 10+2;
	MyDate d3 = d1 + 2;//d1.operator+(2);
	d3.Print();
	return 0;
}