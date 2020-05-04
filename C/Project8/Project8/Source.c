#include <stdio.h>

void test0();


void main()
{
	test0();
}

void test0()
{
	int sum = 0;
	int i;
	for (int i = 1; i <= 10; i++)
	{
		sum += i;
	}
	printf("for문을 이용한 합계 : %d\n", sum);
	i = 1;
	sum = 0;
	while (i <= 10)
	{
		sum += i;
		i++;
	}
	printf("while문을 이용한 합계 : %d\n", sum);

	i = 1;
	sum = 0;
	do
	{
		sum += i;
		i++;
	} while (i <= 10);
	printf("do ~ while문을 이용한 합계 : %d\n", sum);
}