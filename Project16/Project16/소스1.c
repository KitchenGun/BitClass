#include<stdio.h>

/*
���� ��¥�� �����Ҽ��ִ�.
���� ��¥�� ���� �� �� �ִ�
��¥�� ����Ҽ� �ִ�.

*/
void input_today(int *y,int *m,int *d);
void print_date(const int y, const int m, const int d);
void change_nextday(int* y, int* m, int* d);

//�Լ� ������ �н��� ����
int main()
{
	
	//���� ����
	int year;
	int month;
	int day;
	//�ʱ�ȭ
	input_today(&year, &month, &day);
	//���
	printf("%04d-%02d-%02d\n", year, month, day);
	//������¥ ����
	change_nextday(&year, &month, &day);
	//���
	print_data(year, month, day);


	return 0;
}

void input_today(int *y, int *m, int *d)
{
	*y = 2020;
	*m = 4;
	*d = 20;
}

void print_date(const int y, const int m, const int d)
{
	//���
	printf("%04d-%02d-%02d\n", y, m, d);

}
void change_nextday(int* y, int* m, int* d)
{
	*d = *d + 1;
}