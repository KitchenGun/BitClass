//entry point �Լ� �ݵ�� ���������� �ʿ��� �Լ�
//���α׷��� ������ ���⼭ �����̴�
#include<stdio.h>//��� ���� printf�� ������ ������ �ִ�.
void func1();
void func2();
void foo();

void main()
{
	//�̸� ���� �����Ǵ� �Լ� -> ���̺귯���Լ�
	printf("main()\n");//printf�Լ� ȣ��
	
	func1();
	func2();
	foo();
}

void func1()
{
	printf("func1()\n");
}


void func2()
{
	printf("func2()\n");
}