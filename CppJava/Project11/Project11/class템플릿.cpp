#include<iostream>
using namespace std;

//������ �����Ŭ������ �ַ� ����

//������ ����
template<typename T>
class MyArr
{
	T* arr;//������ �����
	int max;//������ �ִ� ����
	int size;//���� ���� ����
public:
	MyArr(int _max)
	{
		max = _max;
		size = 0;
		arr = new T[max];//========================
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
	void push_back(T value)
	{
		if (max <= size)
			throw "��������";
		arr[size] = value;
		size++;
	}
	T& operator[](int idx)
	{
		return arr[idx];
	}
};

int main()
{
	MyArr<int>arr(26);//Ŭ���� ���ø��� ������� ����
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
		int value = arr[i];
		cout << value << "\t";
	}
	cout << endl;
	return 0;
}