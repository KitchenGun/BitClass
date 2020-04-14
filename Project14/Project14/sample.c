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
	//������ġ�� ���尪�� �Է¹ް� ���� �迭�� ����
	//����� ���
		
	int idx = 0;
	int	data = 0;
	
	printf("������ġ(0~%d) : ", DATAMAX - 1);
	scanf_s("%d", &idx);
	if (idx < 0 || idx >= DATAMAX)
	{
		printf("�߸��� �ε����� �Է��ϼ̽��ϴ�.\n");
		return;
	}
	else
	{
		if (g_arr[idx] != -1)
		{
			printf("�����Ͱ� �����մϴ�.\n");
			return;
		}
	}
	printf("���尪 : ");
	scanf_s("%d", &data);

	g_arr[idx] = data;

	printf("����Ǿ����ϴ�.\n");
}


void sample_select()
{
	int data=0;
	int count=0;

	printf("���ڸ� �Է�");

	scanf_s("%d", &data);

	for (int idx = 0; idx < 10; idx++)
	{
		if (g_arr[idx] == data)
		{
			printf("%d��° �ε��� -> %d\n", idx, g_arr[idx]);
			count++;
		}
	}
	if (count == 0)
	{
		printf("���ڰ� �����ϴ�.\n");
		return;
	}
}

void sample_update()
{
	int data = 0;
	int count = 0;

	printf("���ڸ� �Է�");

	scanf_s("%d", &data);

	for (int idx = 0; idx < 10; idx++)
	{
		if (g_arr[idx] == data)
		{
			printf("%d��° �ε��� -> %d\n", idx, g_arr[idx]);
			printf("���尪 : ");
			scanf_s("%d", &data);
			g_arr[idx] = data;
			printf("����Ǿ����ϴ�.\n");
			count++;
		}
	}
	if (count == 0)
	{
		printf("���ڰ� �����ϴ�.\n");
		return;
	}
}

void sample_delete()
{
	int data = 0;
	int count = 0;
	printf("���ڸ� �Է�");

	scanf_s("%d", &data);

	for (int idx = 0; idx < 10; idx++)
	{
		if (g_arr[idx] == data)
		{
			printf("%d��° �ε��� -> %d �ʱ�ȭ\n", idx, g_arr[idx]);
			
			g_arr[idx] = -1;
			count++;
		}
	}
	if (count == 0)
	{
		printf("���ڰ� �����ϴ�.\n");
		return;
	}
}