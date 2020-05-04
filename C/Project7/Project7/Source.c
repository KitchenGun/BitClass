#include <stdio.h>
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
{//while
	int i = 1;
	 
	while (i<6)
	{
		printf("%d hello world \n",i );
		i++;
	}
}


void exam2()
{//while
	int i = 1;

	while (i < 10)
	{
		printf("%d hello world \n", i);
		i+=2;
	}
}


void exam3()
{//while
	int sum = 0;
	int i = 1;

	while (i <= 10)
	{
		printf("%d \n", i);
		sum=sum+i;
		i++;
	}
	printf("%d \n", sum);
}

void exam4()
{//while
	int i = 1;

	do
	{
		printf("%d \n", i);
		i++;

	} while (i <= 10);

}


void exam5()
{
	for (int i = 0; i <= 10; i++)
	{
		printf("%2d\n", i);
	}
}

void exam6()
{
	int i;
	while (1)
	{
		printf("정수 입력");
		scanf_s("%d", &i, sizeof(i));
		if (i == 0)
		{
			break;
		}
	}
}
