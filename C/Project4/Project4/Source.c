#include<stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();
void exam8();
void test0();
void test1();
void test2();
void test3();
void test4();

void main()
{
	//exam8();
	test4();
}


void exam1()
{
	int a, b, c;

	a = 2000;
	b = 3000;
	c = a * b;

	printf("%d*%d=%d\n", a, b, c);
}

void exam2()
{
	char ch1 = 'A';
	ch1=ch1 + 3;

	printf("%d,%c", ch1, ch1);
}

void exam3()
{
	//����������
	//��ġ
	int a = 1;
	int b = ++a;

	printf("%d,%d\n", a, b); //2,2

	//��ġ
	int a1 = 1;
	int b1;

	b1 = a1++;

	printf("%d,%d\n", a1, b1);//2,1
}

void exam4()
{
	int a = 1;
	int b;
	b = ++a + ++a + ++a;//4+4+4;
	printf("%d,%d\n", a, b);

	int a1 = 1;
	int b1;
	b1 = a1++ + a1++ + a1++;//1+1+1;
	printf("%d,%d\n", a1, b1);//4,3
}

void exam5()
{
	int a = 1;
	int b;
	b = ++a + a++ + ++a + ++a;

	printf("%d,%d", a,b);//5,16
}

void exam6()
{
	int number = 92;
	int result = number >= 90 && number <= 100;
	printf("%d", result);//
}

void exam7()
{
	int a, b;
	int result;
	printf("ù��° ���ڸ� �Է��ϼ���");
	scanf_s("%d", &a);
	printf("�ι�° ���ڸ� �Է��ϼ���");
	scanf_s("%d", &b);
	result = a * b;
	printf("%d*%d=%d",a, b, result);
}

void exam8()
{
	char ch1, ch2;
	int result;
	printf("����1");
	scanf_s("%c", &ch1, sizeof(ch1));
	getchar();
	printf("����2");
	scanf_s("%c", &ch2, sizeof(ch2));
	getchar();
	result = ch1 > ch2;
	printf("%d", result);

}

void test0()
{
	int n;
	int result1, result2;

	scanf_s("%d", &n);

	result1 = n / 5;
	result2 = n % 5;

	printf("����:%d\n��:%d\n������:%d",n, result1, result2);
}

void test1()
{
	int a;

	double result;

	scanf_s("%d", &a);
	result = 3.1416 * (a*=a);

	printf("������: %d\n����:%.2f", a, result);

}

void test2()
{
	int c;
	double f;
	scanf_s("%d", &c);
	f = (double)c * 9 / 5 + 32;
	printf("����:%d\nȭ��:%f", c, f);
}

void test3()
{
	char ch;

	scanf_s("%c", &ch, sizeof(ch));
	getchar();
	printf("�Է�(�ҹ���):%c\n��ȯ(�빮��):%c", ch, ch - 32);

}

void test4()
{
	int a, b, c;
	int result1, result2;

	scanf_s("%d", &a);
	scanf_s("%d", &b); 
	scanf_s("%d", &c);
	result1 = a + b + c;
	result2 = (result1 / 3);

	printf("����1:%d\n����2:%d\n����3:%d\n------------\n�հ�:%d\n���:%d\n", a, b, c, result1, result2);
}