#include<iostream>
using namespace std;

//데이터 저장용클래스에 주로 사용됨

//정수를 저장
class MyArr
{
	char* arr;//데이터 저장소
	int max;//데이터 최대 개수
	int size;//현재 저장 개수
public:
	MyArr(int _max)
	{
		max = _max;
		size = 0;
		arr = new char[max];//========================
	}
	~MyArr()
	{
		delete[] arr;
	}
public:
	int getSize()const
	{
		return size;
	}
public:
	void push_back(char value)
	{
		if (max <= size)
			throw "공간없음";
		arr[size] = value;
		size++;
	}
	char& operator[](int idx)
	{
		return arr[idx];
	}
};

int main()
{
	MyArr arr(26);
	try
	{
		for (int i = 0; i < 26; i++)
		{
			arr.push_back(i + 65);
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	//=====================insert
	//=====================select
	cout << arr[2] << endl;//C
	arr[2] = 'c';
	//======================selectall
	for (int i = 0; i < arr.getSize(); i++)
	{
		char value = arr[i];
		cout << value << "\t";
	}
	cout << endl;
	return 0;
}