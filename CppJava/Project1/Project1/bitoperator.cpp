#include<iostream>

using namespace std;

void exam1()
{
	int num1 = 7;
	int num2 = 4;
	int result;

	result = num1 & num2;
	//num1 0000 0111  //num2 0000 0100
	//&    0000 0100//4
	cout << result;

	result = num1 | num2;
	//num1 0000 0111  //num2 0000 0100
	//&    0000 0111//7
	cout << result;
	//보수 연산//-를 2진수로 저장할때 2의 보수를 취해서 저장한다
	//~붙으면 2진법의 숫자를 0이면 1 1이면 0으로 반전이 된다
	result = ~num1;
	//num1 0000 0111  
	//~    1111 1000//-8
	cout << result;

	result = ~num2;
	//num1 0000 0100  
	//~    1111 1011//-5
	cout << result;

	result = ~num1+1;//7
	cout << result;//-7
	//두개가 다를경우에 참
	result = num1 ^ num2;
	//num1 0000 0111  //num2 0000 0100
	//&    0000 0011//3
	cout << result;
	//비트 시프트 연산자
	result = num1 << 2;
	//num1 0000 0111 
	//<<2  0001 1100
	//2의 3승 곱연산 7*(2^3)=56
	cout << result;
}
//비트 켜기| 비트끄기 ~& 비트마스크 &
void exam2()
{
	int attend = 0;//0000 0000

	//출석체크 0->1
	//2번 학생 출석
	attend = attend | 4;
	//attend 0000 0000
	//4		 0000 0100
	//|		 0000 0100;
	attend = attend | 32;
	//attend 0000 0100;
	//32	 0010 0000;
	//|		 0010 0100;
	//x번째 학생의 출석확인은 비트마스크이다
	int result = attend & 4;//2번째
	//attend 0010 0100;
	//4		 0000 0100
	//&		 0000 0100
	result = attend & 8;//3번째
	//attend 0010 0100;
	//8		 0000 1000
	//&		 0000 0000

	//출석 취소는 비트끄기연산
	attend = attend & ~4;
	//attend 0010 0100;
	//4		 0000 0100
	//~4	 1111 1011;
	//&      0010 0000;
}

int main()
{
	//비트 켜기 끄기 마스크
	//데이터 사용단위 byte
	//저장의 최소단위 bit
	//1byte = 8bit
	//문자는 1byte의 크기로 구성된다 문자는 8bit크기로 구성된다
	//1bit2개 0 1 
	//2bit4개 00 01 10 11
	//3bit8개 000,001,010,011,100,101.110,111
	//4bit16개 0000~1111
	//비트 연산자
	exam1();
	return 0;
}