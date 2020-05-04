#include<stdio.h>

typedef struct tagstudent
{
	char name[20];
	int grad;
	int kor;
	int eng;
	int mat;
	float average;
}student;

void inputstudent(student* pstu)
{
	printf("name : ");
	scanf_s("%s",pstu->name, sizeof(pstu->name));
	printf("grade(1~4): ");
	scanf_s("%d", &pstu->grad);
	printf("kor : ");
	scanf_s("%d", &pstu->kor);
	printf("eng : ");
	scanf_s("%d", &pstu->eng);
	printf("math : ");
	scanf_s("%d", &pstu->mat);

}

void calaverage(student* pstu)
{
	pstu->average=(pstu->kor + pstu->eng + pstu->mat)/3.0f;
}

printstu(const student* stu)
{
	printf("name : %s\n", stu->name);
	printf("grade : %d\n", stu->grad);
	printf("kor : %d\n", stu->kor);
	printf("eng : %d\n", stu->eng);
	printf("mat : %d\n", stu->mat);
	printf("average : %.1f\n", stu->average);

}

int main()
{
	student stu1;

	inputstudent(&stu1);
	calaverage(&stu1);
	printstu(&stu1);

	return 0;
}