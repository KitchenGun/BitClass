#include<stdio.h>
//-------------------------------------------------dll 암시적 사용 가능하게 만들어 주는 코드
#include"cal.h" //dll 선언부
#pragma comment(lib,"DLL1.lib")//dll의 정보
//-------------------------------------------------

int main()
{
	printf("%.1f\n", add(10, 20));
	printf("%.1f\n", sub(10, 20));
	printf("%.1f\n", mul(10, 20));
	printf("%.1f\n", div(10, 20));

	getchar();
	return 0;
}