//������
//��ü ������ �ɹ� ���� �ʱ�ȭ�� �������� ���� Ư���� �Լ� �̴�.
#include <iostream>
using namespace std;

//struct Sample
//{
//private:
//	int num1;
//	int num2;
//	int result;
//public:
//	void Add() 
//	{
//		result = num1 + num2;
//	}
////	void Sub()
//	{
//		result = num1 - num2;
//	}
////
////	void Print() 
//	{
//		cout << num1 << "+" << num2 << "=" <<result;
//	}
//};
//
//int main()
//{
//	//�������� ����ü���� ������ ���ÿ� �ʱ�ȭ ���� ���̻� ��� �Ұ���
//	//�����Ͱ� �ܺο��� �����Ҽ������� ���еǾ��� �����̴�.
//	//����� �ʱ�ȭ�� ���� ������ ���
//	Sample sam = { 10,20 };
//
//	sam.Add();
//	sam.Print();
//	return 0;
//}



//�����ڴ� ��ü������ �ڵ����� ȣ��
//�����ڴ� ���� Ÿ�� ���� ����ü ��� �����ؾ��Ѵ� �Ű������� ����
//-�����ε� �⺻��
struct Sample
{
private:
	int n1;
	int n2;
public:
	Sample()
	{
		n1 = 0;
		n2 = 0;
		cout << "������()" << endl;
	}
	Sample(int num1 ,int num2)
	{
		n1 = num1;
		n2 = num2;
		cout << "������()" << endl;
	}
	void Print()
	{
		cout << n1 <<","<< n2 << endl;
	}
};


int main()
{
	Sample sam1;//��ü ����
	sam1.Print();
	Sample sam2(10, 20);
	sam2.Print();
	cout << sizeof(sam1) << endl;//8

	return 0;

}