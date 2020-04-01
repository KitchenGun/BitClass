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
{//특정 문장을 실행하거나 실행하지 않는 구조
	int Score;

	Score = 91;

	//만약 score가 90보다 크다면?
	if (Score > 90)
	{//조건을 만족하면 실행
		printf("크다");
	}
	
}

void exam2()
{//상황에 따라서 선택적으로 출력하는 구조 if else
	char gender;

	gender = 'm';

	if (gender == 'm')
		printf("남자\n");
	else
		printf("남자\n");
}

void exam3()
{//3개 이상의 문장을 상황에 따라서 선택적으로 출력하는 구조

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
	printf("점수는 %d  학점은 %c", score, ch);

}

void exam4()
{
	char ch;

	printf("영문 입력 :");
	scanf_s("%c", &ch, sizeof(ch));
	
	if (ch >= 'A' && ch <= 'Z')
	{
		printf("대문자 입니다\n");
		ch += ('a' - 'A');
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		printf("소문자 입니다\n");
		ch -= ('a' - 'A');
	}
	printf("변경된 결과는%c\n", ch);
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