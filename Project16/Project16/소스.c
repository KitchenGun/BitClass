#include<stdio.h>

/*
���� ��¥�� �����Ҽ��ִ�.
���� ��¥�� ���� �� �� �ִ�
��¥�� ����Ҽ� �ִ�.

*/


//�Լ� ������ �н��� ����
int main()
{
	//���� ����
	int year;
	int month;
	int day;
	//�ʱ�ȭ
	year = 2020;
	month = 4;
	day = 20;
	//���
	printf("%04d-%02d-%02d\n", year, month, day);
	//������¥ ����
	day++;
	//���
	printf("%04d-%02d-%02d\n", year, month, day);


	return 0;
}