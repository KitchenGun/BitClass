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
	printf("이름 : 강건\n나이 : 23\n전화번호 : 010-5331-5896\n\n");
	printf("* - * - * - * - * - * - * - * - * - * - * - * - * -\n\n");
}

void test1()
{
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("*\t\t이름 : 강건\t\t\t*\n*\t\t나이 : 23\t\t\t*\n*\t\t전화번호 : 010-5331-5896\t*\n");
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
	printf("\t모음\t10진수\t16진수\n");
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

	printf("가족 수 :");
	scanf_s("%d", &familyNum);
	printf("당신의 가족은 모두 %d명입니다.\n",familyNum);
	
	printf("연도 :");
	scanf_s("%d", &year);
	printf("기록 :");
	scanf_s("%lf", &record);
	printf("당신의 가족은 모두 %d년의 %.1lf초 입니다.\n", year,record);
	
	printf("학점 입력(3개):");
	scanf_s("%c", &grade1, sizeof(grade1));
	getchar(" ");
	scanf_s("%c", &grade2, sizeof(grade2));
	getchar(" ");
	scanf_s("%c", &grade3, sizeof(grade3));
	getchar(" ");
	printf("C언어 : %c\nCPP언어 : %c\n자료구조 : %c\n",grade1,grade2,grade3);
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
	printf("키보드로부터 한 문자를 입력 받은 다음,\n입력 받은 문자와 해당 문자의 아스키 코드값을 출력하시오.\n");
	printf("\n문자 :");
	scanf_s("%c", &a, sizeof(a));
	printf("값 :%d",a);

	printf("\n키보드로부터 0~127 사이의 정수를 입력 받은 다음, 입력 받은 정수가 가리키는 아스키 문자를 출력하시오.");
	printf("\n\n정수 :");
	scanf_s("%d", &b);
	printf("문자 :%c", b);
}

void test6()
{
	int a, b;
	double a1, b1;
	int result;
	double result1;

	printf("정수 1:");
	scanf_s("%d", &a);
	
	printf("\n정수 2:");
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
	printf("3개의 정수 입력 :");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	
	result = a + b + c;
	printf("\n합 = %d\n\n", result);
	a1 = a;
	b1 = b;
	c1 = c;
	average = (a1+b1+c1)/ 3;
	printf("평균 = %.1f",average);
}

void test8()
{
	int score;
	int result;
	printf("점수 입력 :");
	scanf_s("%d", &score);
	result = score >= 60;
	printf("\n결과 : %d", result);
}

void test9()
{
	int a;
	int result;
	printf("정수 입력 :");
	scanf_s("%d", &a);
	a = a%2;
	result= a <= 0;
	printf("\n결과 : %d", result);
}
