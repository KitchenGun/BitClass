#include<stdio.h>



/*step2
void printchar();
void main()
{	//반복적 기능은 함수
	//함수의 기능을 재사용==>함수호출
	for (int i = 0; i < 5; i++)
	{
		printchar();
	}
	

}

void printchar()
{
	for (int i = 0; i < 10; i++)
	{
		printf("*");
	}
	printf("\n");
}



void main()step1
{//반복적 기능은 함수
	for (int i = 0; i < 10; i++)
	{
		printf("*");
	}
	printf("\n");

}
*/



/*
void printchar(int a);
void main()//step3P
{
	for (int i = 0; i < 1; i++)
	{
		printchar(20);
		printchar(100);
	}
}

void printchar(int a)
{
	for (int i = 0; i < a; i++)
	{
		printf("*");
	}
	printf("\n");
}
*/

/*
void printchar(char ch,int a);

void main()//step3
{
	for (int i = 0; i < 1; i++)
	{
		printchar('^',20);
		printchar('.',100);
	}
}

void printchar(char ch,int a)
{
	for (int i = 0; i < a; i++)
	{
		printf("%c",ch);
	}
	printf("\n");
}*/


void foo(int n1, int n2)//매개변수
{
	int n3;//지역변수
}//모든변수 foo stack메모리에 저장됨

void main()
{

}

