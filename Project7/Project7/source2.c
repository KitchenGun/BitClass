#include <stdio.h>

void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();

void main()
{
	test9();
}

void test0()
{
	int sum = 0;
	int i;
	//for (int i = 1; i <= 10; i++)
	//{
	//	sum += i;
	//}
	//printf("for���� �̿��� �հ� : %d\n", sum);
	//i = 1;
	//sum = 0;
	//while (i <= 10)
	//{
	//	sum += i;
	//	i++;
	//}
	//printf("while���� �̿��� �հ� : %d\n", sum);
	//
	i = 1;
	sum = 0;
	do
	{
		sum += i;
		i++;
	} while (i<=10);

	printf("do ~ while���� �̿��� �հ� : %d\n", sum);
}  

void test1()
{
	int i;
	int sum = 0;

	//for (i=1;i<=100;i++)
	//{
	//	sum += i;
	//	i++;
	//}
	//printf("�հ�(for) : %d\n",sum);
	//i = 1;
	//sum = 0;
	//while (i <= 100)
	//{
	//	if (i % 2 != 0)
	//	{
	//		sum += i;
	//	}
	//	i++;
	//}
	//printf("�հ�(while) : %d\n",sum);
	//
	i = 1;
	sum = 0;
	while (i <= 100)
	{
		if (i % 2 != 0)
		{
			sum += i;
		}
		i++;
	}
	printf("�հ�(do) : %d\n", sum);

}

void test2()
{
	int i;
	int sum=0;
	while (1)
	{
		printf("����(����:0) : ");
		scanf_s("%d", &i);
		if (i == 0)
		{
			printf(" �հ� : %d", sum);
			break;
		}
		else
		{
			sum += i;
		}
	}
}

void test3()
{
	for (int a = 'A'; a <= 'Z'; a++)
	{
		printf("%c", a);
	}
	printf("\n");
	for (int a = 'Z'; a >= 'A'; a--)
	{
		printf("%c", a);
	}
}

void test4()
{
	int pw = 1234;
	int answer;

	while (1)
	{
		printf("��ȣ : ");
		scanf_s("%d", &answer);
		if (answer == pw)
		{
			printf("��ȣ ��ġ\n");
			break;
		}
		else
		{
			printf("��ȣ ����ġ\n");
		}
	}

}

void test5()
{
	int i;
	int aw;
	printf("��<2-9> : ");
	scanf_s("%d", &i);
	printf("\n");
	for (int a = 1; a <= 9; a++)
	{
		aw = i * a;
		printf("%d * %d = %2d\n", i, a, aw);
		aw = 0;
	}

}

void test6()
{
	printf("����\tȭ��\n");
	printf("--------------------------------");
	
	int f=0, c=0;

	while (c <= 100)
	{
		f = (double)c * ((double)9/5) + 32;
		
		printf("\n%3d\t%3d\n", c, f);
		c+=10;
	}
	

}

void test7()
{
	int b=1;
	for (int a = 32; a <= 127; a++)
	{
		printf("%c ", a);
		if (b % 16 == 0)
		{
			printf("\n");
			b = 0;
		}
		b++;
	}
}

void test8()
{
	int aw;
	for (int a = 0; a <= 9; a++)
	{
		printf("%3d", a);
		for (int b = 0; b <= 9; b++)
		{
			aw = a + (b * 10);
			printf("%3d", aw);
			if (b == 9)
			{
				printf("\n");
			}
		}
	}
}

void test9()
{
	char ch;

	for (;;)
	{
		printf(">> �����Է� : ");
		scanf_s("%c", &ch, sizeof(ch));
		getchar();
		if (ch == 'X')
		{
			printf("�ݺ����� �����մϴ�\n");
			break;
		}
	}	
}