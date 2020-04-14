#include <stdio.h>

#include "sample.h"

#define DATAMAX 10
int g_arr[DATAMAX];

void sample_init()
{
	for (int idx = 0; idx < DATAMAX; idx++)
	{
		g_arr[idx] = -1;
	}
}

void sample_printall()
{
	for (int i = 0; i < DATAMAX; i++)
	{
		printf("%5d", i);
	}
	printf("\n");
	printf("-------------------------------------------------------------------------\n");
	for (int i = 0; i < DATAMAX; i++)
	{
		printf("%5d", g_arr[i]);
	}
	printf("\n");
}

void sample_insert()
{
	//저장위치와 저장값을 입력받고 전역 배열에 저장
	//결과를 출력
		
	int idx = 0;
	int	data = 0;
	
	printf("저장위치(0~%d) : ", DATAMAX - 1);
	scanf_s("%d", &idx);
	if (idx < 0 || idx >= DATAMAX)
	{
		printf("잘못된 인덱스를 입력하셨습니다.\n");
		return;
	}
	else
	{
		if (g_arr[idx] != -1)
		{
			printf("데이터가 존재합니다.\n");
			return;
		}
	}
	printf("저장값 : ");
	scanf_s("%d", &data);

	g_arr[idx] = data;

	printf("저장되었습니다.\n");
}


void sample_select()
{
	int data=0;
	int count=0;

	printf("숫자를 입력");

	scanf_s("%d", &data);

	for (int idx = 0; idx < 10; idx++)
	{
		if (g_arr[idx] == data)
		{
			printf("%d번째 인덱스 -> %d\n", idx, g_arr[idx]);
			count++;
		}
	}
	if (count == 0)
	{
		printf("숫자가 없습니다.\n");
		return;
	}
}

void sample_update()
{
	int data = 0;
	int count = 0;

	printf("숫자를 입력");

	scanf_s("%d", &data);

	for (int idx = 0; idx < 10; idx++)
	{
		if (g_arr[idx] == data)
		{
			printf("%d번째 인덱스 -> %d\n", idx, g_arr[idx]);
			printf("저장값 : ");
			scanf_s("%d", &data);
			g_arr[idx] = data;
			printf("저장되었습니다.\n");
			count++;
		}
	}
	if (count == 0)
	{
		printf("숫자가 없습니다.\n");
		return;
	}
}

void sample_delete()
{
	int data = 0;
	int count = 0;
	printf("숫자를 입력");

	scanf_s("%d", &data);

	for (int idx = 0; idx < 10; idx++)
	{
		if (g_arr[idx] == data)
		{
			printf("%d번째 인덱스 -> %d 초기화\n", idx, g_arr[idx]);
			
			g_arr[idx] = -1;
			count++;
		}
	}
	if (count == 0)
	{
		printf("숫자가 없습니다.\n");
		return;
	}
}