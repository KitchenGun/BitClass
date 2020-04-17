#include <stdio.h>
#include<string.h>
#include "sample.h"

/*ȸ����ȣ(����)�̸�(���ڿ�)����(����)��ȭ��ȣ(���ڿ�)
ȸ����ȣ�� �迭�� �ε��� +1 �� ������ �ڵ� ���� �ȴ�
*/
int g_number[DATAMAX];//ȸ����ȣ
char g_gender[DATAMAX];//����
char g_name[20][DATAMAX];//�̸�
char g_phone[20][DATAMAX];//��ȭ
//ȸ�� ��ȣ�� -1 �̸� ������ ����

void sample_init()
{
	for (int idx = 0; idx < DATAMAX; idx++)
	{
		g_number[idx] = -1;
	}
}

void sample_printall()
{
	printf("ȸ����ȣ\t�̸�\t����\t��ȭ��ȣ\n");
	printf("======================================================\n");
	for (int i = 0; i < DATAMAX; i++)
	{
		if (g_number[i] != -1)
		{
			printf("[%02d]\t\t%s\t%s\t%s\n", g_number[i], g_name[i], g_gender[i] == 'm' ? "��" : "��",g_phone[i]);
		}
	}
}

void sample_insert()
{
	//������ġ�� ���尪�� �Է¹ް� ���� �迭�� ����
	//����� ���
	int idx = 0;
	char gender='0';
	char name[DATAMAX];
	char phone[DATAMAX];
	

	printf("������ġ(0~%d) : ", DATAMAX - 1);
	scanf_s("%d", &idx);
	getchar();
	printf("�̸� : ");
	gets_s(name, sizeof(name));
	printf("���� : ");
	scanf_s("%c", &gender, sizeof(gender));
	getchar();
	printf("��ȭ��ȣ : ");
	gets_s(phone, sizeof(phone));

	//���ڿ��� ���� ������ �����Ҷ��� �ٸ� ����� �ִ�.
	strcpy_s(g_name[idx],sizeof(g_name[idx]),name);
	g_gender[idx] = gender;
	g_number[idx] = idx + 1;
	strcpy_s(g_phone[idx], sizeof(g_phone[idx]), phone);
	printf("����Ǿ����ϴ�.\n");
}


void sample_select()
{
	//�˻��� ȸ�� id �Է¹޴´�
	int data=0;

	printf("ȸ�� ID�� �Է�");

	scanf_s("%d", &data);

	for (int idx = 0; idx < DATAMAX; idx++)
	{
		if (g_number[idx] == data)
		{
			printf("%d��° �ε���\n", idx);
			printf("ȸ����ȣ: %d\n", g_number[idx]);
			printf("����	: %s\n", (g_gender[idx] == 'm') ? "��" : "��");
			printf("�̸�	: %s\n", g_name[idx]);
			printf("��ȭ��ȣ: %s\n", g_phone[idx]);
			return;
		}
	}
	printf("ȸ����ȣ�� �����ϴ�.\n");
	
}

void sample_update()
{
	
	char gender = '0';
	char name[20];
	char phone[20];

	printf("ȸ�� �̸��� �Է�");

	gets_s(name, sizeof(name));

	for (int idx = 0; idx < 10; idx++)
	{
		if (strcmp(g_name[idx],name)==0)//�迭�� �̸� ��
		{
			printf("��ȭ��ȣ : ");
			gets_s(phone, sizeof(phone));
			strcpy_s(g_phone[idx], sizeof(g_phone[idx]), phone);
			printf("����Ǿ����ϴ�.");
			return;
		}
	}
}

void sample_delete()
{
	
	int data = 0;
	printf("���ڸ� �Է�");

	scanf_s("%d", &data);

	for (int idx = 0; idx < DATAMAX; idx++)
	{
		if (g_number[idx] == data)
		{
			g_number[idx] = -1;
			strcpy_s(g_name,sizeof(g_name),"");
			strcpy_s(g_phone, sizeof(g_phone), "");

			printf("���� �Ǿ����ϴ�.\n");
			return;
		}
	}
	printf("���ڰ� �����ϴ�.\n");
	
}