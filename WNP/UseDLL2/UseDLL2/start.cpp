#include<stdio.h>
#include<Windows.h>
//함수 포인터 타입을 정의(FUNC:타입 키워드)
//void(*)(int, int) :저장 타입 - 리턴 float 매개변수가int,int인 함수의 주소
typedef float (*FUNC)(int, int);

int main()
{
	//필요할때 dll 로드
	HMODULE hDll = LoadLibrary(TEXT("DLL1.dll"));
	if (hDll == 0)
	{
		//1.dll 파일명 확인
		printf("dll 을 찾을수가 없습니다.\n");
	}
	//=================================
	FUNC f_add = (FUNC)GetProcAddress(hDll, "add");
	FUNC f_sub = (FUNC)GetProcAddress(hDll, "sub");
	FUNC f_mul = (FUNC)GetProcAddress(hDll, "mul");
	FUNC f_div = (FUNC)GetProcAddress(hDll, "div");

	printf("%.1f\n", f_add(10, 20));
	printf("%.1f\n", f_sub(10, 20));
	printf("%.1f\n", f_mul(10, 20));
	printf("%.1f\n", f_div(10, 20));

	//=================================
	//필요없을때 dll 해제
	FreeLibrary(hDll);

	return 0;
}