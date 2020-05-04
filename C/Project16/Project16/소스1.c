#include<stdio.h>

/*
오늘 날짜를 저장할수있다.
다음 날짜로 변경 할 수 있다
날짜를 출력할수 있다.

*/
void input_today(int *y,int *m,int *d);
void print_date(const int y, const int m, const int d);
void change_nextday(int* y, int* m, int* d);

//함수 전까지 학습한 상태
int main()
{
	
	//변수 선언
	int year;
	int month;
	int day;
	//초기화
	input_today(&year, &month, &day);
	//출력
	printf("%04d-%02d-%02d\n", year, month, day);
	//다음날짜 변경
	change_nextday(&year, &month, &day);
	//출력
	print_data(year, month, day);


	return 0;
}

void input_today(int *y, int *m, int *d)
{
	*y = 2020;
	*m = 4;
	*d = 20;
}

void print_date(const int y, const int m, const int d)
{
	//출력
	printf("%04d-%02d-%02d\n", y, m, d);

}
void change_nextday(int* y, int* m, int* d)
{
	*d = *d + 1;
}