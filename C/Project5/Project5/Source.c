#include<stdio.h>

void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();


void main()
{
	test9();
}


void test0()
{
	printf("* - * - * - * - * - * - * - * - * - * - * - * - * -\n\n");
	printf("�̸� : ����\n���� : 23\n��ȭ��ȣ : 010-5331-5896\n\n");
	printf("* - * - * - * - * - * - * - * - * - * - * - * - * -\n\n");
}

void test1()
{
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("*\t\t�̸� : ����\t\t\t*\n*\t\t���� : 23\t\t\t*\n*\t\t��ȭ��ȣ : 010-5331-5896\t*\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

void test2()
{
	int a, b=0, c=0, d=0;
	a = 65;
	b =a+1;
	c =b+1;
	d =c+1;
	printf("* * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t����\t10����\t16����\n");
	printf("\t%c\t%d\t%#x\n", a, a, a);
	printf("\t%c\t%d\t%#x\n", b, b, b);
	printf("\t%c\t%d\t%#x\n", c, c, c);
	printf("\t%c\t%d\t%#x\n", d, d, d);
	printf("* * * * * * * * * * * * * * * * * * * * *\n");
}

void test3()
{
	int familyNum = 0;
	int year;
	double	record;
	char grade1,grade2,grade3;

	printf("���� �� :");
	scanf_s("%d", &familyNum);
	printf("����� ������ ��� %d���Դϴ�.\n",familyNum);
	
	printf("���� :");
	scanf_s("%d", &year);
	printf("��� :");
	scanf_s("%lf", &record);
	printf("����� ������ ��� %d���� %.1lf�� �Դϴ�.\n", year,record);
	
	printf("���� �Է�(3��):");
	scanf_s("%c", &grade1, sizeof(grade1));
	getchar(" ");
	scanf_s("%c", &grade2, sizeof(grade2));
	getchar(" ");
	scanf_s("%c", &grade3, sizeof(grade3));
	getchar(" ");
	printf("C��� : %c\nCPP��� : %c\n�ڷᱸ�� : %c\n",grade1,grade2,grade3);
}

void test4()
{
	char a;
	int b;
	float c;
	double d;

	printf(" type\tsize");
	printf("\n--------------\n");
	printf(" char\t%d\n",sizeof(a));
	printf(" int\t%d\n", sizeof(b));
	printf(" float\t%d\n", sizeof(c));
	printf(" double\t%d\n", sizeof(d));
}

void test5()
{
	char a;
	int b;
	printf("Ű����κ��� �� ���ڸ� �Է� ���� ����,\n�Է� ���� ���ڿ� �ش� ������ �ƽ�Ű �ڵ尪�� ����Ͻÿ�.\n");
	printf("\n���� :");
	scanf_s("%c", &a, sizeof(a));
	printf("�� :%d",a);

	printf("\nŰ����κ��� 0~127 ������ ������ �Է� ���� ����, �Է� ���� ������ ����Ű�� �ƽ�Ű ���ڸ� ����Ͻÿ�.");
	printf("\n\n���� :");
	scanf_s("%d", &b);
	printf("���� :%c", b);
}

void test6()
{
	int a, b;
	double a1, b1;
	int result;
	double result1;

	printf("���� 1:");
	scanf_s("%d", &a);
	
	printf("\n���� 2:");
	scanf_s("%d", &b);
	
	result = a + b;
	printf("\n%d+%d=%d\n", a, b, result);
	result = a - b;
	printf("\n%d-%d=%d\n", a, b, result);
	result = a * b;
	printf("\n%d*%d=%d\n", a, b, result);
	a1 = a;
	b1 = b;
	result1 = a1 / b1;
	printf("\n%d/%d=%.1f\n", a, b, result1);
}	

void test7()
{
	int a, b, c;
	double a1, b1, c1;
	int result;
	double average;
	printf("3���� ���� �Է� :");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	
	result = a + b + c;
	printf("\n�� = %d\n\n", result);
	a1 = a;
	b1 = b;
	c1 = c;
	average = (a1+b1+c1)/ 3;
	printf("��� = %.1f",average);
}

void test8()
{
	int score;
	int result;
	printf("���� �Է� :");
	scanf_s("%d", &score);
	result = score >= 60;
	printf("\n��� : %d", result);
}

void test9()
{
	int a;
	int result;
	printf("���� �Է� :");
	scanf_s("%d", &a);
	a = a%2;
	result= a <= 0;
	printf("\n��� : %d", result);
}
