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
	printf("for���� �̿��� �հ� : %d\n", sum);
	i = 1;
	sum = 0;
	while (i <= 10)
	{
		sum += i;
		i++;
	}
	printf("while���� �̿��� �հ� : %d\n", sum);

	i = 1;
	sum = 0;
	do
	{
		sum += i;
		i++;
	} while (i <= 10);
	printf("do ~ while���� �̿��� �հ� : %d\n", sum);
}