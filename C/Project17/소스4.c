
#include <stdio.h>
#include <string.h>
typedef struct tagEmail
{
	char title[30];
	char toname[20];
	char byname[20];
	char text[100];
	char date[20];
	int primary;

} Email;


void print_email(struct tagEmail *x)
{
	printf("%s\n%s\n%s\n", (*x).title, (*x).text, (*x).date);
}

void update_email(struct tagEmail* x, char *ch)
{
	strcpy_s((*x).date,sizeof((*x).date), ch);
}

void print_email1(char* title, char* date)
{
	printf("%s\n%s\n",title, date);
}

void main() 
{
	Email x;

	printf("제목: ");
	gets_s(x.title, sizeof(x.title));

	printf("수신자: ");
	gets_s(x.toname, sizeof(x.toname));

	printf("발신자: ");
	gets_s(x.byname, sizeof(x.byname));

	printf("본문: ");
	gets_s(x.text, sizeof(x.text));

	printf("보낸날짜(yymmdd): ");
	gets_s(x.date, sizeof(x.date));

	printf("우선순위: ");
	gets_s("%d", &x.primary, sizeof(x.primary));

	//문제1. Email에서 제목과 본문 내용과 보낸날짜만 출력하는 기능의 함수입니다.
	print_email(&x);

	//문제2. 메일의 정보 중 보낸날짜의 정보를 2번째 인자로 전달된 값으로 수정하세요.
	update_email(&x, "200421");

	//문제3. 제목과 보낸 날짜 정보를 출력하는 함수입니다. 
	print_email1(x.title, x.date);
}


