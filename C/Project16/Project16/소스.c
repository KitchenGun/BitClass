#include<stdio.h>

/*
오늘 날짜를 저장할수있다.
다음 날짜로 변경 할 수 있다
날짜를 출력할수 있다.

*/


//함수 전까지 학습한 상태
int main()
{
	//변수 선언
	int year;
	int month;
	int day;
	//초기화
	year = 2020;
	month = 4;
	day = 20;
	//출력
	printf("%04d-%02d-%02d\n", year, month, day);
	//다음날짜 변경
	day++;
	//출력
	printf("%04d-%02d-%02d\n", year, month, day);


	return 0;
}