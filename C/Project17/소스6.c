
#include <stdio.h>

typedef struct tagEmployee
{
	int id_number;
	char name[20];
	int ph_number;
	int age;
} Employee;
int select_number(Employee* people, int a, int b, int c);

Employee select_maxage(Employee* people, int a);

void print_employee(Employee em);
void main() 
{
	Employee people[5];
	int i, count = 0;

	for (i = 0; i < 5; i++) 
	{
		printf("%d��° ��������\n", i + 1);
		printf("�����ȣ: "); 	scanf_s("%d", &people[i].id_number);
		getchar();

		printf("�̸�: ");		gets_s(people[i].name, sizeof(people[i].name));

		printf("��ȭ��ȣ: ");	scanf_s("%d", &people[i].ph_number);

		printf("����: ");		scanf_s("%d", &people[i].age);
	}
	printf("\n");

	printf("���̰� 20�̻� 30������ ����\n");

	for (i = 0; i < 10; i++) 
	{
		if (people[i].age >= 20 && people[i].age <= 30) 
		{
			puts(people[i].name);
			count++;
		}
	}
	printf("�ش� ���ο�: %d��\n", count);

	//����1 �� ������ �Լ�ȭ ��Ű����.	
	//�������� : �迭, ���尳��, 20�̻�, 30������ ���� �� ��ȯ
	int retval = select_number(people, 5, 20, 30);
	printf("�ش� ���ο�: %d��\n", retval);

	//����2 ���� ���̰� ���� ������ ��ȯ�ϼ���.
	Employee em = select_maxage(people, 5);

	//����3 �ش� ������ ������ ����ϼ���.
	print_employee(em);
}


int select_number(Employee *people, int a, int b, int c)
{

	int i, count = 0;

	for (i = 0; i < a; i++)
	{
		printf("%d��° ��������\n", i + 1);
		printf("�����ȣ: "); 	scanf_s("%d", &people[i].id_number);
		getchar();

		printf("�̸�: ");		gets_s(people[i].name, sizeof(people[i].name));

		printf("��ȭ��ȣ: ");	scanf_s("%d", &people[i].ph_number);

		printf("����: ");		scanf_s("%d", &people[i].age);
	}
	printf("\n");

	printf("���̰� %d�̻� %d������ ����\n",b,c);

	for (i = 0; i < a; i++)
	{
		if (people[i].age >= b && people[i].age <= c)
		{
			puts(people[i].name);
			count++;
		}
	}
	return count;
}


Employee select_maxage(Employee* people, int a)
{
	int i, count = 0;
	int high=0;
	for (i = 0; i < a; i++)
	{
		
		if (people[i].age >= people[high].age)
		{
			high = i;
			count++;
		}
	}

	return people[high];
}


void print_employee(Employee em)
{

	printf("�����ȣ: %d\n", em.id_number);

	printf("�̸�: %s\n", em.name);

	printf("��ȭ��ȣ: %d\n", em.ph_number);

	printf("����: %d\n",em.age);
}