#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();

void main()
{
	exam5();
}


void exam1()
{//Ư�� ������ �����ϰų� �������� �ʴ� ����
	int Score;

	Score = 91;

	//���� score�� 90���� ũ�ٸ�?
	if (Score > 90)
	{//������ �����ϸ� ����
		printf("ũ��");
	}
	
}

void exam2()
{//��Ȳ�� ���� ���������� ����ϴ� ���� if else
	char gender;

	gender = 'm';

	if (gender == 'm')
		printf("����\n");
	else
		printf("����\n");
}

void exam3()
{//3�� �̻��� ������ ��Ȳ�� ���� ���������� ����ϴ� ����

	int score;
	char ch;

	score = 82;

	if (score >= 90 && score <= 100)
		ch = 'A';
	else if (score >= 80 && score < 90)
		ch = 'B';
	else if (score >= 70 && score < 79)
		ch = 'C';
	else
		ch = 'F';
	printf("������ %d  ������ %c", score, ch);

}

void exam4()
{
	char ch;

	printf("���� �Է� :");
	scanf_s("%c", &ch, sizeof(ch));
	
	if (ch >= 'A' && ch <= 'Z')
	{
		printf("�빮�� �Դϴ�\n");
		ch += ('a' - 'A');
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		printf("�ҹ��� �Դϴ�\n");
		ch -= ('a' - 'A');
	}
	printf("����� �����%c\n", ch);
}

void exam5()
{
	char ch = 'B';
	switch (ch)
	{
	case'A':
		printf("1\n");
		printf("2\n");
		printf("3\n");
		break;
	case'B':
		printf("4\n");
		printf("5\n");
		break;
	case 'C':
		printf("6\n");
		break;
	}
}