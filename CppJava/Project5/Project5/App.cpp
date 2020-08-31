#include<iostream>
using namespace std; 
#include<conio.h>
#include "app.h"


App::App()
{
	con = new control;
}

App::~App()
{
	delete con;
}

void App::InitInstance()
{

}
void App::Run() 
{
	char idx;
	while (true)
	{
		system("cls");
		con->SelectAll();//con_selectall();
		idx = Menuprint();
		switch (idx)
		{
		case '1':	con->Insert();		break;
		case '2':	con->Select();		break;
		//case '3':	con_update();		break;
		//case '4':	con_delete();		break;
		case '5':   return;
		}
		system("pause");
	}
}
void App::ExitInstance()
{

}

void App::Logo()
{
	system("cls");	//"cls" : 화면을 지우는 명령어
	printf("*****************************************************\n");
	printf(" 우송비트 단기 ??차 C언어 과정\n");
	printf(" 구조체를 이용한 회원 관리 프로그램\n");
	printf(" 2020년 04월 24일\n");
	printf(" ccm\n");
	printf("*****************************************************\n");
	system("pause");	//"pause" : 잠깐 멈춤 명령어
}
char App::Menuprint() 
{
	printf("*****************************************************\n");
	printf("[1] 입 력(insert)\n");
	printf("[2] 검 색(select)\n");
	printf("[3] 수 정(update)\n");
	printf("[4] 삭 제(delete)\n");
	printf("[5] 종료\n");
	printf("*****************************************************\n");

	return _getch();
}
void App::Ending()
{
	system("cls");
	printf("*****************************************************\n");
	printf(" 프로그램을 종료합니다.\n");
	printf("*****************************************************\n");
	system("pause");

	//	char idx;
	//	idx = _getch();		//특수한 형태의 문자 입력함수
	//	return idx;			//화면에 문자 출력을 X
	//return _getch();	//엔터키 없이 버퍼로 전송
}