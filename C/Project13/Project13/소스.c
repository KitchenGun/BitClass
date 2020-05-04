#include <stdio.h>

/*매개변수 와 리턴없음
void exam1();


void main()
{
	exam1();
}


void exam1()
{
	printf("Hello");
}
*/
/*
int exam1(int a,int b);

void main()
{
	int num1 = 10;
	int num2 = 20;
	int result = 0;

	result = exam1(num1, num2);
	printf("result %d\n", result);
}


int exam1(int a, int b)
{
	int result = 0;
	result = a + b;
	return result;
}
*/

int getsum(n1,n2,n3);
float getaverage(f1, f2, f3);

void main()
{
	
	int result = 0;
	result = getsum(10,20,30);
	printf("%d\n", result);
	float average = 0;
	average = getaverage(21, 22, 35);
	printf("%.1f\n", average);
	if (isbigchar('c') == 1)
	{
		printf("대문자\n");
	}
	else
	{
		printf("소문자\n");
	}
}


int getsum(n1, n2, n3)
{
	int result = n1 + n2 + n3;
	return result;
}

float getaverage(f1, f2, f3)
{
	int result = f1 + f2 + f3;
	float average=0;
	average = (float)result / 3;
	return average;
}


int isbigchar(char ch)
{
	if (ch<'Z' && ch>'A')
	{
		return 1;
	}
	else if (ch<'z' && ch>'a')
	{
		return 0;
	}
}