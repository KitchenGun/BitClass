#include<iostream>
#include<time.h>
//���� �޸�

using namespace std;

/*
malloc & free
*/


// �������� 1�� ������ ������ ���� ����� �ʹ�

void exam1()
{
	int* pnum = (int*)malloc(sizeof(int));

	*pnum = 10;

	free(pnum);
}

//���� �迭 ����
void exam2()
{
	srand((unsigned int)time(0));

	int max;
	cout << "���������� �ִ� ũ��";
	cin >> max;
	 
	char* parr = (char*)malloc(sizeof(char) * max);

	for (int i = 0; i < max; i++)
	{
		char ch = rand() % 26 + 'A';
		parr[i] = ch;
	}

	for (int i = 0; i < max; i++)
	{
		cout << parr[i];
	}
	cout << endl;

	free(parr);
}

void exam3()
{
	int* pnum = new int;//������ ������� 1�� ����

	*pnum = 10;

	delete pnum;
	//
	char* pch1 = new char('A');//���ڸ� �����Ҽ��ִ� ���� 1�� ���� 'A'�� �ʱ�ȭ
	cout << *pch1 << endl;
	delete pch1;
	//
	cout << "�";
	int max;
	cin >> max;
	char* pch2 = new char[max];//sizeof(char)*max

	for (int i = 0; i < max; i++)
	{
		char ch = rand() % 26 + 'A';
		pch2[i] = ch;
	}

	for (int i = 0; i < max; i++)
	{
		cout << pch2[i];
	}
	cout << endl;

	delete[] pch2;
}

int main()
{
	exam3();
	return 0;
}
