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
	Data d1;//1�� ȣ��
	Data n3[5];//5�� ȣ��
	Data n4('a', 10);//1�� ȣ��
	Data n5[5] = { Data(10),Data('a',10) };//5�� ȣ��
	Data* n6;//0�� ȣ��
	n6 = new Data;//1�� ȣ��
	n6 = new Data(10);//1�� ȣ��
	n6 = new Data[5];//5�� ȣ��
}