#include<stdio.h>


int g_num = 0;//전역변수
static g_snum;//정적전역변수//현재파일에서만 사용가능한 전역변수

int main()
{
	g_num = 12;
	return 0;
}


void foo()
{
	g_num = 11;
}