#include<stdio.h>
/*
오늘 날짜를 저장할수있다.
다음 날짜로 변경 할 수 있다
날짜를 출력할수 있다.

날짜라는 타입을 정의
struct tagdata == int
*/

struct tagdate
{//구조체 타입 정의
	//맴버 리스트:정수 3개 저장하는 타입 12byte 
	int year;
	int month;
	int day;
};


void input_today(struct tagdate* d)
{
	(*d).year = 2020;
	(*d).month = 4;
	(*d).day = 20;
}

void print_date(struct tagdate d)
{
	//출력
	printf("%04d-%02d-%02d\n", d.year, d.month, d.day);

}
void change_nextday(struct tagdate* d)
{
	(*d).day = (*d).day + 1;
}

//구조체 배움
int main()
{

	//변수 선언
	struct tagdate d1;//정수 3개를 저장할수있는 공간이 생성
	//초기화
	input_today(&d1);
	//출력
	print_date(d1);
	//다음날짜 변경
	change_nextday(&d1);
	//출력
	print_date(d1);

	return 0;
}
