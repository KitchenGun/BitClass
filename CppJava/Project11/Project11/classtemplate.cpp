#include<iostream>
using namespace std;

//데이터 저장용클래스에 주로 사용됨

//정수를 저장
class MyArr
{
	int* arr;//데이터 저장소
	int max;//데이터 최대 개수
	int size;//현재 저장 개수
public:
	MyArr(int _max)
	{
		max = _max;
		size = 0;
		arr = new int[max];
	}
	~MyArr()
	{
		delete[] arr;
	}
public :
	int getSize()const
	{
		return size;
	}
public:
	void push_back(int value)
	{
		if (max <= size)
			throw "공간없음";
		arr[size] = value;
		size++;
	}
	int& operator[](int idx)
	{
		return arr[idx];
	}
};

int main()
{
	MyArr arr(30);
	try
	{
		for (int i = 0; i < 5; i++)
		{
			arr.push_back(i + 1);
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	//=====================insert
	//=====================select
	cout << arr[2] << endl;
	arr[2] = 30;
	//======================selectall
	for (int i = 0; i < arr.getSize(); i++)
	{
		int value = arr[i];
		cout << value << "\t";
	}
	cout << endl;
	return 0;

}