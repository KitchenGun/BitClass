/************************************************************
 ������ 2���� ��ȯ�ϴ� swap �Լ��� ���۷����� ����ؼ� �����Ͻÿ�.
*************************************************************/

#include <iostream>
using namespace std;
//������
void swap(int&n,int&n1,int &c);

int main()
{
	int num = 10, num1 = 20;
	int c;
	swap(num,num1,c);
	return 0;
}


void swap(int& n, int& n1,int &c)
{
	c = n;
	n = n1;
	n1 = c;

	cout << n << n1;
}
