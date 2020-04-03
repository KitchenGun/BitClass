#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();

void main()
{
	exam6();
}

void exam1()
{
	//변수선언 
	int num;
	int arr[3];//배열변수

	//초기화
	num = 11;
	arr[0] = 20;
	arr[1] = 30;
	arr[2] = 40;
	

	printf(">>정수 입력 : ");
	scanf_s("%d", &num);
	for (int i = 0; i < 3; i++)
	{
		printf(">>정수 입력 : ");
		scanf_s("%d", &arr[i]);
	}
	//printf(">>정수 입력 : ");
	//scanf_s("%d", &arr[0]);
	//printf(">>정수 입력 : ");
	//scanf_s("%d", &arr[1]);
	//printf(">>정수 입력 : ");
	//scanf_s("%d", &arr[2]);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr[i]);
	}
}

void exam2()
{
	int num[3];
	int result=0;

	for (int i = 0; i < 3; i++)
	{
		printf(">>정수 입력 : ");
		scanf_s("%d", &num[i]);
		result += num[i];
	}
	printf("%d\n", result);
}

void exam3()
{
	int num[4];
	int result = 0;
	double average;

	for (int i = 0; i < 4; i++)
	{
		printf(">>정수 입력 : ");
		scanf_s("%d", &num[i]);
		result += num[i];
	}
	average = (double)result / 4;
	printf("%.1f\n",average);
}

//#define 
#define MAXDATA 1000
void exam4()
{
	int num[MAXDATA];
	int result = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < MAXDATA; i++)
	{

		if (i % 20 == 0&&i!=0)
		{
			printf("\n");
		}
		int r = (rand() % 99) + 1;//1~99
		num[i] = r;
		printf("%3d", num[i]);
	}
	
}

void exam5()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		int r = (rand() % 99) + 1;//1~99
		printf("%d\n", r);
	}
}

#define ARRNUM 1000

void exam6()
{
	int num[ARRNUM];
	int result = 0;
	double average;

	srand((unsigned)time(NULL));

	for (int i = 0; i < ARRNUM; i++)
	{
		num[i] = (rand() % 99) + 1;//1~99
		result += num[i];
	}
	average = (double)result / ARRNUM;
	printf("%3.1f\n", average);
	printf("%3d\n", result);
	//============================
	int number;
	int count = 0;
	printf("정수입력(1~99) : ");
	scanf_s("%d", &number);

	for (int i = 0; i < ARRNUM; i++)
	{
		if (num[i] == number)
		{
			count++;
		}
	}
	printf("%d", count);
}



