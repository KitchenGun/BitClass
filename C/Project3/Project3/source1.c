#include <stdio.h>
/*
1변수 선언
2.선언된 변수를 초기화
-사용자 입력
3.출력
*/

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();


void main()
{
	exam6();
}
//사용자로 부터 나이를 받는 프로그램
//printf	서식(%)을 기반으로 출력
//scanf		서식(%)을 기반으로 입력받는 함수
void exam1()
{//정수
	int age;
	printf("input the age ");
	scanf_s("%d", &age);

	printf("age %d\n",age);
}

void exam2()
{//소수
	double weight1=0.0;
	double weight2=0.0;
	printf("input the 2 Weight");
	scanf_s("%lf", &weight1);
	scanf_s("%lf", &weight2);
	printf("result %lf,%lf\n", weight1,weight2);
}

void exam3()
{//문자
	char ch1;
	char ch2;
	printf("input the 2 char\n");
	printf("1");
	scanf_s("%c", &ch1,sizeof(ch1));//문자는 뒤에 무조건 사이즈가 들어가야한다
	getchar();//입력 버퍼에서 문자 하나를 빼오는 함수
	printf("2");
	scanf_s("%c", &ch2,sizeof(ch2));
	printf("result %c, %c\n", ch1,ch2);
}

void exam4()
{//문자열 여러개 받는법
	char ch1, ch2, ch3, ch4;
	printf("1문자:");
	ch1 = getchar();
	getchar();
	printf("2문자:");
	ch2 = getchar();
	getchar();
	printf("3문자:");
	ch3 = getchar();
	getchar();
	printf("4문자:");
	ch4 = getchar();
	getchar();
	printf("%c,%c,%c,%c\n", ch1, ch2, ch3, ch4);
	putchar(ch1);
	putchar('\n');
	putchar(ch2);
	putchar('\n');
	putchar(ch3);
	putchar('\n');
	putchar(ch4);
	putchar('\n');
}

void exam5()
{//한글도 가능
	char str1[20];//배열
	char str2[20];

	printf("1문자열");
	gets_s(str1, sizeof(str1));
	printf("2문자열");
	gets_s(str2, sizeof(str2));

	puts("결과값");
	puts(str1);
	puts(str2);
}

void exam6()
{//입출력 정리
	char name[20];
	char subject[20];
	int age;
	char gender;
	float weight;

	printf("이름입력");
	gets_s(name,sizeof(name));
	printf("학과입력");
	scanf_s("%s",subject ,sizeof(subject));
	printf("나이입력");
	scanf_s("%d", &age);
	getchar();
	printf("성별(m:f)");
	scanf_s("%c", &gender, sizeof(gender));
	printf("몸무게");
	scanf_s("%f", &weight);

	printf("이름 : %s\n", name);
	printf("학과 : %s\n", subject);
	printf("나이 : %d세\n", age);
	printf("성별 : %c\n", gender);
	printf("몸무게 : %.1f\n", weight);//소수점 1자리 까지 출력

}