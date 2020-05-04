
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
		printf("%d번째 직원정보\n", i + 1);
		printf("사원번호: "); 	scanf_s("%d", &people[i].id_number);
		getchar();

		printf("이름: ");		gets_s(people[i].name, sizeof(people[i].name));

		printf("전화번호: ");	scanf_s("%d", &people[i].ph_number);

		printf("나이: ");		scanf_s("%d", &people[i].age);
	}
	printf("\n");

	printf("나이가 20이상 30이하인 직원\n");

	for (i = 0; i < 10; i++) 
	{
		if (people[i].age >= 20 && people[i].age <= 30) 
		{
			puts(people[i].name);
			count++;
		}
	}
	printf("해당 총인원: %d명\n", count);

	//문제1 위 연산을 함수화 시키세요.	
	//전달인자 : 배열, 저장개수, 20이상, 30이하인 직원 수 반환
	int retval = select_number(people, 5, 20, 30);
	printf("해당 총인원: %d명\n", retval);

	//문제2 가장 나이가 많은 직원을 반환하세요.
	Employee em = select_maxage(people, 5);

	//문제3 해당 직원의 정보를 출력하세요.
	print_employee(em);
}


int select_number(Employee *people, int a, int b, int c)
{

	int i, count = 0;

	for (i = 0; i < a; i++)
	{
		printf("%d번째 직원정보\n", i + 1);
		printf("사원번호: "); 	scanf_s("%d", &people[i].id_number);
		getchar();

		printf("이름: ");		gets_s(people[i].name, sizeof(people[i].name));

		printf("전화번호: ");	scanf_s("%d", &people[i].ph_number);

		printf("나이: ");		scanf_s("%d", &people[i].age);
	}
	printf("\n");

	printf("나이가 %d이상 %d이하인 직원\n",b,c);

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

	printf("사원번호: %d\n", em.id_number);

	printf("이름: %s\n", em.name);

	printf("전화번호: %d\n", em.ph_number);

	printf("나이: %d\n",em.age);
}