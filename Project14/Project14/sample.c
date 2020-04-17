#include <stdio.h>
#include<string.h>
#include "sample.h"

/*회원번호(정수)이름(문자열)성별(문자)전화번호(문자열)
회원번호는 배열의 인덱스 +1 의 값으로 자동 설정 된다
*/
int g_number[DATAMAX];//회원번호
char g_gender[DATAMAX];//성별
char g_name[20][DATAMAX];//이름
char g_phone[20][DATAMAX];//전화
//회원 번호가 -1 이면 데이터 없음

void sample_init()
{
	for (int idx = 0; idx < DATAMAX; idx++)
	{
		g_number[idx] = -1;
	}
}

void sample_printall()
{
	printf("회원번호\t이름\t성별\t전화번호\n");
	printf("======================================================\n");
	for (int i = 0; i < DATAMAX; i++)
	{
		if (g_number[i] != -1)
		{
			printf("[%02d]\t\t%s\t%s\t%s\n", g_number[i], g_name[i], g_gender[i] == 'm' ? "남" : "여",g_phone[i]);
		}
	}
}

void sample_insert()
{
	//저장위치와 저장값을 입력받고 전역 배열에 저장
	//결과를 출력
	int idx = 0;
	char gender='0';
	char name[DATAMAX];
	char phone[DATAMAX];
	

	printf("저장위치(0~%d) : ", DATAMAX - 1);
	scanf_s("%d", &idx);
	getchar();
	printf("이름 : ");
	gets_s(name, sizeof(name));
	printf("성별 : ");
	scanf_s("%c", &gender, sizeof(gender));
	getchar();
	printf("전화번호 : ");
	gets_s(phone, sizeof(phone));

	//문자열을 저장 공간에 대입할때는 다른 방법이 있다.
	strcpy_s(g_name[idx],sizeof(g_name[idx]),name);
	g_gender[idx] = gender;
	g_number[idx] = idx + 1;
	strcpy_s(g_phone[idx], sizeof(g_phone[idx]), phone);
	printf("저장되었습니다.\n");
}


void sample_select()
{
	//검색할 회원 id 입력받는다
	int data=0;

	printf("회원 ID를 입력");

	scanf_s("%d", &data);

	for (int idx = 0; idx < DATAMAX; idx++)
	{
		if (g_number[idx] == data)
		{
			printf("%d번째 인덱스\n", idx);
			printf("회원번호: %d\n", g_number[idx]);
			printf("성별	: %s\n", (g_gender[idx] == 'm') ? "남" : "여");
			printf("이름	: %s\n", g_name[idx]);
			printf("전화번호: %s\n", g_phone[idx]);
			return;
		}
	}
	printf("회원번호가 없습니다.\n");
	
}

void sample_update()
{
	
	char gender = '0';
	char name[20];
	char phone[20];

	printf("회원 이름를 입력");

	gets_s(name, sizeof(name));

	for (int idx = 0; idx < 10; idx++)
	{
		if (strcmp(g_name[idx],name)==0)//배열의 이름 비교
		{
			printf("전화번호 : ");
			gets_s(phone, sizeof(phone));
			strcpy_s(g_phone[idx], sizeof(g_phone[idx]), phone);
			printf("변경되었습니다.");
			return;
		}
	}
}

void sample_delete()
{
	
	int data = 0;
	printf("숫자를 입력");

	scanf_s("%d", &data);

	for (int idx = 0; idx < DATAMAX; idx++)
	{
		if (g_number[idx] == data)
		{
			g_number[idx] = -1;
			strcpy_s(g_name,sizeof(g_name),"");
			strcpy_s(g_phone, sizeof(g_phone), "");

			printf("삭제 되었습니다.\n");
			return;
		}
	}
	printf("숫자가 없습니다.\n");
	
}