#include<iostream>

using namespace std;

struct Data
{
public:
	Data()
	{
		cout << "Data()" << endl;
	}
	Data(int n)
	{
		cout << "Data(int)" << endl;
	}
	Data(char ch, int n)
	{
		cout << "Data(char,int)" << endl;
	}
};

int main()
{
	Data d1;//1개 호출
	Data n3[5];//5개 호출
	Data n4('a', 10);//1개 호출
	Data n5[5] = { Data(10),Data('a',10) };//5개 호출
	Data* n6;//0개 호출
	n6 = new Data;//1개 호출
	n6 = new Data(10);//1개 호출
	n6 = new Data[5];//5개 호출
}