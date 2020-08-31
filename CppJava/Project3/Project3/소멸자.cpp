//소멸자
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
	~Data()
	{
		cout << "~Data()" << endl;
	}
};

int main()
{
	Data d1;//1개 호출
	//Data n3[5];//5개 호출
	//Data n4('a', 10);//1개 호출
	//Data n5[5] = { Data(10),Data('a',10) };//5개 호출
	Data* n6;//0개 호출
	//n6 = new Data;//1개 호출
	//힙메모리에 생성
	//delete n6;//해당주소에 생성된 객체 소멸
	//n6 = new Data(10);//1개 호출
	//delete n6;
	n6 = new Data[5];//5개 호출
	delete[] n6;
	return 0;
}