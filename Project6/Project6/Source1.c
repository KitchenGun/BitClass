#include <stdio.h>

void test0();
void test1();
void test3();
void test5();
void test6();
void test7();

void main()
{
	test7();
}

void test0()
{
	int n=0;
	char ch='A';


	if (n % 3 == 0 && n % 5 == 0)
	{
		printf("n이 3과 5의 배수이다");
	}
	else
	{
		printf("no");
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		printf("ch가 대문자 이다");
	}
	else
	{
		printf("소문자이다");
	}
	if (n < -5 && n>5)
	{
		printf("n이 -5보다 작거나 5보다 크다");
	}
	else
	{
		printf("no");
	}
	if (n % 2 == 0)
	{
		printf("n이 홀수가 아니다");
	}
	else
	{
		printf("짝수다");
	}
}

void test1()
{
	int score;


	printf("점수 :");
	scanf_s("%d", &score);
	if (score >= 60)
	{
		printf("결과 : 합격\n");
	}
	else
	{
		printf("결과 : 불합격\n");
	}
}

void test2()
{
	int a,b,c;

	printf("정수 (3개) :");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	if (180 == a + b + c)
	{
		printf("결과 : 가능\n");
	}
	else
	{
		printf("결과 : 불가능\n");
	}

}

void test3()
{
	int score;

	printf("정수 :");
	scanf_s("%d", &score);
	if (score % 2 != 0)
	{
		printf("결과 : 홀수\n");
	}
	else
	{
		printf("결과 : 짝수\n");
	}

}

void test4()
{
	int a, b, c, d, e;
	int plus, minor;

	printf("정수 (5개) :");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);
	scanf_s("%d", &e);
	plus = 0;
	minor = 0;
	if (a >= 0)
	{
		plus += a;
	}
	else
	{
		minor += a;
	}
	if (b >= 0)
	{
		plus += b;
	}
	else
	{
		minor += b;
	}
	if (c >= 0)
	{
		plus += c;
	}
	else
	{
		minor += c;
	}
	if (d >= 0)
	{
		plus += d;
	}
	else
	{
		minor += d;
	}
	if (e >= 0)
	{
		plus += e;
	}
	else
	{
		minor += e;
	}

	printf("음수 합계 : %d\n", minor);

	printf("양수 합계 : %d\n", plus);
}

void test5()
{
	char ch;
	int temp;

	printf("종류, 온도 :");
	scanf_s("%c", &ch, sizeof(ch));
	getchar(" ");
	scanf_s("%d", &temp);

	if (ch == 'c' || ch == 'C')
	{
		temp = (float)temp * (1.8f) + 32;
		ch = 'F';
	}
	else if (ch == 'f' || ch == 'F')
	{
		temp = ((float)temp - 32) / (1.8f);
		ch = 'C';
	}
	printf("\n변환 :%c %d", ch, temp);
}

void test6()
{
	char ch;

	printf("문자 : ");
	scanf_s("%c", &ch, sizeof(ch));

	if (ch >= 'A' && ch <= 'Z')
	{
		ch += ('a' - 'A');
		printf("변환 : %c",ch);
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		ch -= ('a' - 'A');
		printf("변환 : %c",ch);
	}

}

void test7()
{
	int score;
	printf("점수 : ");
	scanf_s("%d", &score);
	if (score >= 90)
	{
		printf("학점 : A");
	}
	else if (score>=80 &&score < 90)
	{
		printf("학점 : B");
	}
	else if (score >= 70 && score < 80)
	{
		printf("학점 : C");
	}
	else if (score >= 60 && score < 70)
	{
		printf("학점 : D");
	}
	else
	{
		printf("학점 : F");
	}
}