#include <stdio.h>

void cal(num1, num2, num3, size, sum, average);

int main()
{
	int num1 = 10, num2 = 22, num3 = 31;
	int sum=0;
	float average=0;
	cal(num1, num2, num3, 3 ,&sum, &average);
	
	printf("%.1f", average);
}

void cal(int num1,int num2,int num3, int size ,int* sum,float* average)
{
	*sum = num1 + num2 + num3;
	*average = (float)* sum / size;

}