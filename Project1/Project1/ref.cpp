#include<iostream>

//������ == ����

using namespace std;

void exam1()
{
	int num = 10;
	int& rnum = num;//rnum ���۷���:=>:num ������ ����

	//=========================
	cout << rnum << endl;

	rnum = 20;
	cout << num << endl;

	cout << &rnum << endl;
	cout << &num << endl;
}

void exam2_1(int n1 ,int* n2, int& n3)//��, �ּҰ�, ������
{
	n1 = 20;
	//�Ű����� ����
	*n2 = 30;//���� �޸𸮿� �ִ� num1������ ����
	n3 = //n3�� ���ø޸𸮿� �ִ� num1�� ��Ī
}

void exam2()
{//������ ��뿹
	//�Ű����� ����
	/*
	������ call by value
	�ּҰ� ���� call by address//���� �� �������
	������ ���� call by reference// ���� ���ް� ������ ��� ����
	*/

	int num1 = 10;
	exam2_1(num1, &num1, num1);
	cout << num1 << endl;
}

int arr[3] = { 1,2,3 };//�������� �Լ��� �������� ->���� �����޸𸮿� ����

int exam3_1(int idx)
{
	return arr[idx];
}

int& exam3_2(int idx)
{
	return arr[idx];
}
void exam3()
{
	int n1 = exam3_1(2); //int n1 =30
	cout << n1 << endl;

	int n1 = exam3_2(2);//int n1 =arr[2]
	cout << n1 << endl;
	//======================================
	//exam3_1(2) = 200;//30=200//�Լ��� ȣ���� ���Կ��� Rvalue���� �̷�����
	exam3_2(2) = 200;//arr[2]=200

	cout << arr[0] << "," << arr[1] << "," << arr[2] << endl;
}

int main()
{
	exam3();

	return 0;
}