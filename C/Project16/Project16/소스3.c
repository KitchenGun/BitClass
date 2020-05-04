#include<stdio.h>

struct tagstu
{
	char name[20];
	int grad;
	char subject[20];
	int number;
};

void input_stu(struct tagstu* stu)
{
	printf("학생 이름 입력 : ");
	gets_s((*stu).name, sizeof((*stu).name));
	printf("학년 입력 : ");
	scanf_s("%d", &(*stu).grad);
	printf("학과 입력 : ");
	gets_s((*stu).name, sizeof((*stu).name));
	printf("학번 입력 : ");
	scanf_s("%d", &(*stu).number);
}

void print_stu(struct tagstu stu)
{
	printf("이름%s\t학년%d\t학과%s\t학번%d\n",stu.name,stu.grad,stu.subject,stu.number);
}

print_stu1(char *n, int g, char *s, int num)
{
	printf("이름%s\t학년%d\t학과%s\t학번%d\n", n, g, s, num);
}

void update_stu(struct tagstu *stu, int grad)
{
	(*stu).grad = grad;
}
int main()
{
	struct tagstu stu1;

	input_stu(&stu1);
	print_stu(stu1);
	update_stu(&stu1, 3);
	print_stu1(stu1.name,stu1.grad,stu1.subject,stu1.number);

	return 0;
}