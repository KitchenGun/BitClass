#include<stdio.h>
/*
���� ��¥�� �����Ҽ��ִ�.
���� ��¥�� ���� �� �� �ִ�
��¥�� ����Ҽ� �ִ�.

��¥��� Ÿ���� ����
struct tagdata == int
*/

struct tagdate
{//����ü Ÿ�� ����
	//�ɹ� ����Ʈ:���� 3�� �����ϴ� Ÿ�� 12byte 
	int year;
	int month;
	int day;
};


void input_today(struct tagdate* d)
{
	(*d).year = 2020;
	(*d).month = 4;
	(*d).day = 20;
}

void print_date(struct tagdate d)
{
	//���
	printf("%04d-%02d-%02d\n", d.year, d.month, d.day);

}
void change_nextday(struct tagdate* d)
{
	(*d).day = (*d).day + 1;
}

//����ü ���
int main()
{

	//���� ����
	struct tagdate d1;//���� 3���� �����Ҽ��ִ� ������ ����
	//�ʱ�ȭ
	input_today(&d1);
	//���
	print_date(d1);
	//������¥ ����
	change_nextday(&d1);
	//���
	print_date(d1);

	return 0;
}
