/************************************************************
  08. 다음 출력 결과를 만족하는 클래스를 구현하시오.
		결과 :
		2020/5/8
		2020/5/8
		2020/5/8
		true
		false
*************************************************************/
#include <iostream>

using namespace std;


class  Date		// 1) 클래스명 
{
	int year;	int month;	int day;
public:
	Date():year(2020),month(5),day(8)
	{

	}
	//2) 인자를 3개 받는 생성자
	Date(int _year, int _month, int _day) :year(_year), month(_month), day(_day)
	{

	}


	//3) print 메서드
	void print()
	{
		cout << year << "/" << month << "/" << day << endl;
	}


   //4) 객체를 인자로 받는 cmp 메서드
	int cmp(Date _arr)
	{
		if (year == _arr.year)
		{
			if (month == _arr.month)
			{
				if (day == _arr.day)
				{
					return 1;
				}
			}
		}
		return 0;
	}


   //5) 정수형 인자 3개를 받는 cmp 메서드
	int cmp(int _year, int _month, int _day)
	{
		if (year == _year)
		{
			if (month == _month)
			{
				if (day == _day)
				{
					return 1;
				}
			}
		}
		return 0;
	}


};

void main()
{
	Date arr[3];        
	int i;

	for (i = 0; i < 3; i++)
		arr[i].print();// 모두 2020/5/8 

	arr[1].cmp(arr[0]) ? cout << "true" << endl : cout << "false" << endl;
	arr[1].cmp(1990, 2, 1) ? cout << "true" << endl : cout << "false" << endl;
}
