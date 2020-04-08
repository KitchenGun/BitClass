#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();
void exam8();
void exam9();
void exam10();

void main()
{
	exam1();
}


void exam1()
{
	int p1[5];
	int p2[3][5];
	char p4[20];
	char p5[2][20];
	int* num1[3];

	printf("%d byte\n", sizeof(p1));
	printf("%d byte\n", sizeof(p2));
	printf("%d byte\n", sizeof(p4));
	printf("%d byte\n", sizeof(p5));
}

void exam2()
{
	int num[4] = {1,2,3,4};

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			printf("%d번째 인덱스의 값 : %d\n", i,num[i]);
		}
		if (i == 3)
		{
			printf("%d번째 인덱스의 주소값 : %d", i, &num[i]);
		}
	}
}

void exam3()
{
	int arr1[10];
	int arr2[10];
	char ch[26];

	for (int i = 0; i < 10; i++)
	{
		arr1[i] = 0;
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		arr2[i] = i+1;
		printf("%d ", arr2[i]);
	}

	printf("\n");

	ch[0] = 'a';
	for (int i = 0;i<26;i++)
	{
		ch[i] = i+'a';
		printf("%c ", ch[i]);
	}
}

void exam4()
{
	int random[12];

	srand((unsigned)time(NULL));


	printf("첨자 :");
	for (int i = 0; i < 12; i++)
	{
		
		printf("%3d", i);
	}
	printf("\n");
	printf("요소 :");
	for (int i = 0; i < 12; i++)
	{
		random[i] = rand() % 20;
		printf("%3d", random[i]);

	}
	
}

void exam5()
{
	int random[12];
	int random2[12];
	srand((unsigned)time(NULL));

	printf("첨자 :");
	for (int i = 0; i < 12; i++)
	{

		printf("%3d", i);
	}
	printf("\n");
	printf("요소 :");
	for (int i = 0; i < 12; i++)
	{
		random[i] = rand() % 20;
		printf("%3d", random[i]);

	}
	printf("\n");
	printf("변환 :");
	for (int i = 0; i < 12; i++)
	{
		random2[i] = 2*random[i];
		printf("%3d", random2[i]);

	}
}

void exam6()
{
	int random[12];
	int num=0;
	srand((unsigned)time(NULL));

	printf("첨자 :");
	for (int i = 0; i < 12; i++)
	{

		printf("%3d", i);
	}
	printf("\n");
	printf("요소 :");
	for (int i = 0; i < 12; i++)
	{
		random[i] = rand() % 20;
		printf("%3d", random[i]);

	}
	printf("\n");
	printf("최대 :");
	for (int i = 0; i < 12; i++)
	{
		if (num < random[i])
		{
			num = random[i];
		}
	}
	printf("%3d", num);

	
}

void exam7()
{
	int random[12];
	int num = 20;
	srand((unsigned)time(NULL));

	printf("첨자 :");
	for (int i = 0; i < 12; i++)
	{

		printf("%3d", i);
	}
	printf("\n");
	printf("요소 :");
	for (int i = 0; i < 12; i++)
	{
		random[i] = rand() % 20;
		printf("%3d", random[i]);

	}
	printf("\n");
	printf("최소 :");
	for (int i = 0; i < 12; i++)
	{
		if (num > random[i])
		{
			num = random[i];
		}
	}
	printf("%3d", num);


}

void exam8()
{
	int num[5];
	int result = 0;
	double average;

	for (int i = 0; i < 5; i++)
	{
		printf(">>%d번째 입력 : ",i+1);
		scanf_s("%d", &num[i]);
		result += num[i];
	}
	printf("\n\n합계 : %d\n", result);
	average = (double)result / 5;
	printf("평균 : %.2f", average);
}

void exam9()
{
	char ch[100];
	int small=0;
	int big=0;
	int num=0;
	int space=0;

	printf("문자열 : ");
	gets_s(ch,sizeof(ch));

	for (int i = 0; i < 100; i++)
	{
		if (ch[i] >= 'a' && ch[i] <= 'z')
		{
			small++;
		}
		if (ch[i] >= 'A' && ch[i] <= 'Z')
		{
			big ++;
		}
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			num ++;
		}
		if (ch[i] == ' ')
		{
			space++;
		}
	}
	printf("소문자 : %d\n대문자 : %d\n숫  자 : %d\n공  백 : %d\n", small, big, num, space);

}

void exam10()
{
	int arr[10] = { 1,2,3,4,5,6,7}; //1,2,3,4,5,6,7,0,0,0
	int* parr = arr + 1;

	for (int i = 0; i < 10; i++)
	{
		if (i == 8)
		{
			arr[i] = arr[0] + arr[1];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 8)
		{
			parr[i] = parr[0] + parr[2];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n");


}