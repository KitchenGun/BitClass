#include<stdio.h>


int g_num = 0;//��������
static g_snum;//������������//�������Ͽ����� ��밡���� ��������

int main()
{
	g_num = 12;
	return 0;
}


void foo()
{
	g_num = 11;
}