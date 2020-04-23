#include <stdio.h>
#include<malloc.h>



void exam1();
void exam2();
void exam3();
void exam4();

int main()
{
	exam4();
	return 0;
}

//정수 문자 실수 하나씩 저장할수있는 동적메모리 요구
void exam1()
{
	int* p1 = malloc(sizeof(int));
	char* p2 = malloc(sizeof(char));
	float* p3 = malloc(sizeof(float));
	//================================

	*p1 = 10;
	*p2 = 'a';
	*p3 = 10.1f;

	printf("%d, %c, %.1f\n", *p1, *p2, *p3);

	//================================
	free(p1);
	free(p2);
	free(p3);
}
//================================
int* g_arr[5];

void insert()
{
	int num = 10;
	g_arr[0] = &num;
}

void insert1()
{
	int num1 = 20;
	g_arr[1] = &num1;
}

void exam2()
{
	insert();//함수가 종료되면 내부의 메모리가 사라진다//지역변수의 주소는 저장하면 안된다
	insert1();
	printf("%d\n", *(g_arr[0]));

	printf("%d\n", *(g_arr[1]));
}

//================================
int* g_arr1[5];
void insert11()
{
	int* pnum = (int*)malloc(sizeof(int));
	*pnum = 10;
	g_arr1[0] = pnum;
}

void insert12(){	int* pnum = (int*)malloc(sizeof(int));	*pnum = 20;	g_arr1[1] = pnum;}

void exam3()
{
	insert11();
	printf("%d\n",*g_arr1[0]);
}


void exam4()
{
	int arr1[10];//정수10개만 저장할수있다.

	int size=0;
	printf("정수 몇개 저장: ");
	scanf_s("%d", &size);
	int* arr = (int*)malloc(sizeof(int) * size);

	//초기화
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	//
	for (int i = 0; i < size; i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}