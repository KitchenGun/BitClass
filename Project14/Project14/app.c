#include <stdio.h>
#include <stdlib.h>//system()
#include <conio.h>//_getchar();

#include "app.h"
#include "sample.h"

//초기화 기능
void app_init()
{
	loge();
	sample_init();
}
//엔진 기능
void app_run()
{
	char idx;
	while (1)
	{
		system("cls");
		sample_printall();
		idx = menuprint();
		
		switch (idx)
		{
		case '1':
			sample_insert();
			break;
		case '2':
			sample_select();
			break;
		case '3':
			sample_update();
			break;
		case '4':
			sample_delete();
			break;
		case '5':
			return;
		}
		system("pause");
	}
}
//종료 처리 기능
void app_exit()
{
	ending();
}

void loge()
{
	system("cls");
	printf("*************************************************************************************\n");
	printf("우송 비트 단기 c언어과정\n");
	printf("함수와 배열을 이용한 프로그램 \n");
	printf("2020:04:14\n");
	printf("ccm\n");
	printf("*************************************************************************************\n");
	system("pause");
}
void ending()
{
	system("cls");
	printf("*************************************************************************************\n");
	printf("프로그램을 종료합니다\n");
	printf("*************************************************************************************\n");
	system("pause");
}
char menuprint()
{

	printf("*************************************************************************************\n");
	printf("[1]입력(insert)\n");
	printf("[2]검색(select)\n");
	printf("[3]수정(update)\n");
	printf("[4]삭제(delete)\n");
	printf("[5]종료\n");
	printf("*************************************************************************************\n");
	
	return _getch();//엔터키 없이 버퍼로 전송
}
