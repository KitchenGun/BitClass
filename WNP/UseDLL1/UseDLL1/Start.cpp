#include<stdio.h>
//-------------------------------------------------dll �Ͻ��� ��� �����ϰ� ����� �ִ� �ڵ�
#include"cal.h" //dll �����
#pragma comment(lib,"DLL1.lib")//dll�� ����
//-------------------------------------------------

int main()
{
	printf("%.1f\n", add(10, 20));
	printf("%.1f\n", sub(10, 20));
	printf("%.1f\n", mul(10, 20));
	printf("%.1f\n", div(10, 20));

	getchar();
	return 0;
}