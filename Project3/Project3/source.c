/*�ּ� �����Ϸ��� �Ⱥ��̴� ����


���α׷�
1)������: ���ϴ� ������ ���(����)�� ����(�����)
2)���: ������ �����Ϳ� ���� ����
	�������� ���� ���

*/
#include<stdio.h>//��� ���� : �ڵ带 �ۼ��Ҷ� �ʿ��� �Լ��� ���� �θ� ���� �ִ� ����
	
void exam1();
void exam2();
void exam3();
void exam4();
void exam5();

void main()
{
	exam5();
}

void exam1()
{
	//--------����
	int num; // ������� ���� �� ������ �̸��� num
	int num1;

	//-------����
	//���Կ���
	//������� = ���尪
	num = 10;
	num1 = 20;
	//-------���
	//"" ���ڿ�
	//printf�� ���ڿ��� ����ϴ±��
	//%d ������ ġȯ
	//\n ���๮�� ���ٶ���
	printf("������� %d:%d\n",num,num1);

}

void exam2()
{
	int number;

	number = 1;
	printf("number => %d\n", number);
	number = 11;
	printf("number => %d\n", number);
}

void exam3()
{//c���α׷����� ���� �޴� Ÿ���� 
 //����:int		10 0 -10	%d
 //����:char	'a','1'		%c
 //�Ǽ�:double	10.1,-10.1	%lf,f
	int num;
	char ch;
	double dnumber;

	num = 10;
	ch = 'a';
	dnumber = 12.234;

	printf("���� num=> %d\n���� ch => %c\n�Ǽ� dnumber => %lf\n", num, ch, dnumber);

}

//int a =10 10���� %d
//int b= 012 8���� %o
//int c =0xa 16����%16
void exam4()
{
	int num = 65;
	char ch = 'A';

	printf("%d %d\n", num, ch); 
	printf("%c %c\n", num, ch);
	
	const int NUM = 10;//���
	//NUM=10;//error

	printf("%d\n", NUM);

}

void exam5()
{
	int num1 = 10;
	int num2;
	const int NUM3 = 30;//����� ���ÿ� �ʱ�ȭ �ʿ�
	
	num2 = 20;
	num1 += num2;
	printf("%d,%d,%d\n", num1, num2, NUM3);//30,20,30
}