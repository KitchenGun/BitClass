#include <stdio.h>


void exam1();
void exam2();
void exam3();
void exam4();

void initarr();
void printarr();
void Insertarr();
void deletearr();
int arr[10];

void main()
{
	initarr();
	printarr();
	Insertarr();
	deletearr();
	exam5();

	int idx;
	while (1) {
		printf("[1]입력[2]전체출력[3] 삭제[4] 종료\n");
		scanf_s("%d", &idx);
		switch (idx)
		{
		case 1:
			Insertarr();
			break;
		case 2:
			printarr();
			break;
		case 3:
			deletearr();
			break;
		case 4:
			return;
		}
	}
}

void initarr()
{
	for (int i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
	printarr();
}

void printarr()
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d", arr[i]);
	}
}

void Insertarr()
{
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printarr();
}

void deletearr()
{
	int i = 0;

	scanf_s("%d", &i);
	arr[i] = 0;
	printarr();
}

void exam1()
{
	char* p1; 
	char** p2;
	int* p3[5];
	double* p4;
	printf("\t타입 값/주소값 개수 메모리크기 차수\n");
	printf("p1\t");
	printf("char  주소값   1개 %7d\t1차\n", sizeof(p1));
	printf("p2\t");
	printf("char  주소값   1개 %7d\t2차\n", sizeof(p2));
	printf("p3\t");
	printf("int   주소값   5개 %7d\t2차\n", sizeof(p3));
	printf("p4\t");
	printf("double   주소값 1개 %7d\t1차\n", sizeof(p4));
}

void exam2()
{
	int num;
	int* pnum;

	scanf_s("%d", &num);
	pnum = &num;
	printf("\n%d,%p", num, &num);

	printf("\n%p,%d", pnum, *pnum);

	*pnum = 50;
	printf("\n%d", num);
	printf("\n--------------------------------------------\n");
	char arr[5] = {'a','b','c','d','e'};
	char* pch1;
	char* pch2;

	pch1 = arr;
	pch2 = arr + 2;
	printf("%c,%c\n", arr[1], *(pch1 + 1));
	printf("%c,%c\n", arr[0], *(pch2-2));
	printf("%c\n",*(pch1+3)-('a'-'A'));
	printf("%c\n", *(pch2 + 2) - ('a' - 'A'));

	for (int i = 0; i < 5; i++)
	{
		printf("%c", arr[i]);
	}
}

void exam3()
{
	int a[6] = { 2,3,4,5,6,8 };
	printf( "%d\n", sizeof(a));
	printf( "%d\n", sizeof(a[0]));
	printf( "%d\n", (*a + 5));
	printf( "%d\n", *(a + 4));
	printf( "%d\n", *a);
}		

void exam4()
{
	int arr[5] = { 10,20,30,40,50 };
	int* ip = arr;

	printf("%d\n", arr);
	printf("%d\n", ip);
	printf("%d\n", ip + 2);
	printf("%d\n", ip[2]);
	printf("%d\n", *(arr + 1));
}
