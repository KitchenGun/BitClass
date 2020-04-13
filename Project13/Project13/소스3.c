#include <stdio.h>

int inputnumber();
int inputchar();
int getresult(int n1, int n2, char oper, float* result);
void printfresult(int n1, int n2, char oper, float result);


int main(){	int num1, num2;	char oper;	float result;	num1 = inputnumber();	num2 = inputnumber();	oper = inputchar();	int isresult = getresult(num1,num2,oper,&result);	if (isresult == 0)	{		printf("잘못된 연산의 결과\n");		return 0;	}	printfresult(num1, num2, oper, result);		return 0;}


int inputnumber()
{
	int num;
	printf("정수입력 :");
	scanf_s("%d", &num);
	getchar();
	return num;
}


int inputchar()
{
	char oper;
	printf("연산자 입력 (+,-,/,*) : ");
	scanf_s("%c",&oper ,sizeof(oper));
	getchar();
	return oper;
}

int getresult(int n1, int n2, char oper,float* result)
{
	switch (oper)	{	case '+':   *result = (float)n1 + n2; break;	case '-':   *result = (float)n1 - n2; break;	case '*':   *result = (float)n1 * n2; break;	case '/':   *result = (float)n1 / n2; break;	default:	return 0;	}
	return 1;
}

void printfresult(int n1, int n2, char oper, float result)
{
	printf("%d %c %d = %.1f\n", n1, oper, n2, result);
}