#include <stdio.h>
/*
1���� ����
2.����� ������ �ʱ�ȭ
-����� �Է�
3.���
*/

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();


void main()
{
	exam6();
}
//����ڷ� ���� ���̸� �޴� ���α׷�
//printf	����(%)�� ������� ���
//scanf		����(%)�� ������� �Է¹޴� �Լ�
void exam1()
{//����
	int age;
	printf("input the age ");
	scanf_s("%d", &age);

	printf("age %d\n",age);
}

void exam2()
{//�Ҽ�
	double weight1=0.0;
	double weight2=0.0;
	printf("input the 2 Weight");
	scanf_s("%lf", &weight1);
	scanf_s("%lf", &weight2);
	printf("result %lf,%lf\n", weight1,weight2);
}

void exam3()
{//����
	char ch1;
	char ch2;
	printf("input the 2 char\n");
	printf("1");
	scanf_s("%c", &ch1,sizeof(ch1));//���ڴ� �ڿ� ������ ����� �����Ѵ�
	getchar();//�Է� ���ۿ��� ���� �ϳ��� ������ �Լ�
	printf("2");
	scanf_s("%c", &ch2,sizeof(ch2));
	printf("result %c, %c\n", ch1,ch2);
}

void exam4()
{//���ڿ� ������ �޴¹�
	char ch1, ch2, ch3, ch4;
	printf("1����:");
	ch1 = getchar();
	getchar();
	printf("2����:");
	ch2 = getchar();
	getchar();
	printf("3����:");
	ch3 = getchar();
	getchar();
	printf("4����:");
	ch4 = getchar();
	getchar();
	printf("%c,%c,%c,%c\n", ch1, ch2, ch3, ch4);
	putchar(ch1);
	putchar('\n');
	putchar(ch2);
	putchar('\n');
	putchar(ch3);
	putchar('\n');
	putchar(ch4);
	putchar('\n');
}

void exam5()
{//�ѱ۵� ����
	char str1[20];//�迭
	char str2[20];

	printf("1���ڿ�");
	gets_s(str1, sizeof(str1));
	printf("2���ڿ�");
	gets_s(str2, sizeof(str2));

	puts("�����");
	puts(str1);
	puts(str2);
}

void exam6()
{//����� ����
	char name[20];
	char subject[20];
	int age;
	char gender;
	float weight;

	printf("�̸��Է�");
	gets_s(name,sizeof(name));
	printf("�а��Է�");
	scanf_s("%s",subject ,sizeof(subject));
	printf("�����Է�");
	scanf_s("%d", &age);
	getchar();
	printf("����(m:f)");
	scanf_s("%c", &gender, sizeof(gender));
	printf("������");
	scanf_s("%f", &weight);

	printf("�̸� : %s\n", name);
	printf("�а� : %s\n", subject);
	printf("���� : %d��\n", age);
	printf("���� : %c\n", gender);
	printf("������ : %.1f\n", weight);//�Ҽ��� 1�ڸ� ���� ���

}