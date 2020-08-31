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


class Product
{
private:
	char company[20];
	char product[20];
	int price;
	Date* pdate;
public:
	Product(const char* _company, const char* _product,int _year,int _month,int _day,int _price)
	{
		pdate = new Date(_year, _month, _day);
		strcpy_s(company, sizeof(company), _company);
		strcpy_s(product, sizeof(product), _product);
		price = _price;
	}
public:
	void OutProduct()
	{
		cout << company << " " << product << " ";
		pdate->OutNow();
		cout << price << " ";
	}
};

int main()
{
	Product S("새우깡", "농심", 2009, 8, 15, 900);
	S.OutProduct();                   //제품의 모든 정보 출력
	return 0;
}