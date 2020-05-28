#include<iostream>
using namespace std;

//������ �����Ŭ������ �ַ� ����

//������ ����
class MyArr
{
	char* arr;//������ �����
	int max;//������ �ִ� ����
	int size;//���� ���� ����
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
			throw "��������";
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