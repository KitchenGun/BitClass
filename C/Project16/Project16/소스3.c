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
	printf("�л� �̸� �Է� : ");
	gets_s((*stu).name, sizeof((*stu).name));
	printf("�г� �Է� : ");
	scanf_s("%d", &(*stu).grad);
	printf("�а� �Է� : ");
	gets_s((*stu).name, sizeof((*stu).name));
	printf("�й� �Է� : ");
	scanf_s("%d", &(*stu).number);
}

void print_stu(struct tagstu stu)
{
	printf("�̸�%s\t�г�%d\t�а�%s\t�й�%d\n",stu.name,stu.grad,stu.subject,stu.number);
}

print_stu1(char *n, int g, char *s, int num)
{
	printf("�̸�%s\t�г�%d\t�а�%s\t�й�%d\n", n, g, s, num);
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