#include <stdio.h>

#define EXAM1 void exam1();//치환
#define MSG1 "문자열정의"

void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();
void exam8();


EXAM1

int main()
{
	exam8();

	return 0;
}

void exam1()
{
	int n1, n2;
	printf("0x%p,0x%p\n");
	printf("%s, 0x%p\n", "문자열정의",&"문자열정의");
	printf("%s\n", MSG1);
}

void exam2()
{
	char arr[10] = { "abcdefg" };
	printf("%s\n", arr);
	printf("%c\n", arr[3]);
	printf("%s\n", arr + 2);
	printf("%c\n", *(arr + 2));
}

void exam3()
{
	char arr[10] = { "abc\0def\0" };
	printf("%s\n",arr);
	printf("%s\n", arr + 4);
}

void exam4()
{
	char arr[4][5] = { "abcd","efhg","ijkl","mnop" };
	//문자 0차
	printf("%c\n", arr[0][2]);//c
	printf("%c\n", arr[2][1]);//j
	//문자열 1차
	printf("%s\n", arr[0]);//abcd;
	printf("%s\n", arr[2]);//ijkl;
}

void exam5()
{
	char arr1[10] = {"abc"};
	char arr2[10] = {"ABCDEFG"};
	int i;
	for (i = 0; arr1[i] != '\0'; i++)
	{
		arr2[i] = arr1[i];
	}
	arr2[i] = '\0';
	printf("%s\n", arr2);
}

void mystrcpy(char* s1, char* s2)
{
	int i;
	for (i = 0; s1[i] != '\0'; i++)
	{
		s1[i] = s2[i];
	}
	s1[i] = '\0';
}

void exam6()
{
	char arr1[10] = { "한글" };
	char arr2[10] = { "ABCDEFG" };

	mystrcpy(arr2, arr1);
	printf("%s\n", arr2);
}

void exam7()
{
	int num1 = 10;
	int num2 = 20;

	// 역참조를 통해서 원본의 변경이 불가능함
	const int* pn;
	pn = &num1;
	printf("%d\n", *pn);
	pn = &num2;
	printf("%d\n", *pn);

}

void setnum1(int* n)
{
	*n = 10;
}

void printfnum1(int n)
{
	printf("%d\n", n);
}

void setarr(char* parr, int i, char ch)
{
	printf("%c\n", parr[i]);
	parr[i] = ch;
	printf("%c\n",parr[i]);

}
void printarr(const char* parr)//출력함수에서 수정하기 거부용으로 const사용
{
	for (int i = 0; i <= 5; i++)
	{
		printf("%c ", parr[i]);
	}
	printf("\n");
}

void exam8()
{
	//함수 인자 전달 (값 전달,주소값 전달)
	int num1;
	setnum1(&num1);
	printfnum1(num1);

	char arr[6] = { "abcde" };

	setarr(arr,2,'C');//주소 전달
	printarr(arr);//값전달은 불가능
}