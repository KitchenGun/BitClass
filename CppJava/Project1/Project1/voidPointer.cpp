#include<iostream>
/*
1.���Ÿ���� �ּҸ� �����Ҽ��ִ�

*/

using namespace std;



int main()
{
	int num1 = 10;
	char ch = 'a';

	int* pt1 = &num1;
	//1.
	void* vf;
	vf = &num1;
	vf = &ch;
	//2.
	cout << *(char*)vf << endl;//'a'
	vf = &num1;

	*(int*)vf = 20;


	return 0;
}