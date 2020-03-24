/*주석 컴파일러에 안보이는 문장


프로그램
1)데이터: 원하는 데이터 모양(형식)을 생성(저장소)
2)기능: 생성된 데이터에 값을 저장
	데이터의 값을 출력

*/
#include<stdio.h>//헤더 파일 : 코드를 작성할때 필요한 함수의 선언 부를 갖고 있는 파일
	
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
{
	//--------생성
	int num; // 저장공간 생성 그 공간의 이름은 num
	int num1;

	//-------저장
	//대입연산
	//저장공간 = 저장값
	num = 10;
	num1 = 20;
	//-------출력
	//"" 문자열
	//printf는 문자열을 출력하는기능
	//%d 정수값 치환
	//\n 개행문자 한줄띄우기
	printf("정수출력 %d:%d\n",num,num1);

}

void exam2()
{
	int number;

	number = 1;
	printf("number => %d\n", number);
	number = 11;
	printf("number => %d\n", number);
}

void exam3()
{//c프로그램에서 제공 받는 타입은 
 //정수:int		10 0 -10	%d
 //문자:char	'a','1'		%c
 //실수:double	10.1,-10.1	%lf,f
	int num;
	char ch;
	double dnumber;

	num = 10;
	ch = 'a';
	dnumber = 12.234;

	printf("정수 num=> %d\n문자 ch => %c\n실수 dnumber => %lf\n", num, ch, dnumber);

}

//int a =10 10진법 %d
//int b= 012 8진법 %o
//int c =0xa 16진법%16
void exam4()
{
	int num = 65;
	char ch = 'A';

	printf("%d %d\n", num, ch); 
	printf("%c %c\n", num, ch);
	
	const int NUM = 10;//상수
	//NUM=10;//error

	printf("%d\n", NUM);

}

void exam5()
{
	int num1 = 10;
	int num2;
	const int NUM3 = 30;//선언과 동시에 초기화 필요
	
	num2 = 20;
	num1 += num2;
	printf("%d,%d,%d\n", num1, num2, NUM3);//30,20,30
}