#include<iostream>

using namespace std;
/*
c������ �Լ� �ĺ��ڴ� �Լ���
c++ �Լ� �ĺ��ڴ� �Լ��� + �Ű����� ����Ʈ
�Լ��� �̸��� ������ �Ű������� �ٸ��� �ٸ� �Լ��� �����Ѵ�
*/

bool isequal(int n1, int n2)
{
	return n1 == n2;
}
bool isequal(float n1, float n2)
{
	return n1 == n2;
}

int add(int n1, int n2)
{
	return n1 + n2;
}
float add(float n1, float n2)
{
	return n1 + n2;
}
double add(double n1, double n2)
{
	return n1 + n2;
}



int main()
{
	cout << isequal(10, 20) << endl;
	cout << isequal(20, 20) << endl;
	cout << isequal(10.1f, 20.1f) << endl;
	cout << isequal(20.1f, 20.1f) << endl;
	//=============================
	cout << add(10, 20) << endl;
	cout << add(10.1f, 20.1f) << endl;
	cout << add(10.1, 20.1) << endl;
	return 0;
}