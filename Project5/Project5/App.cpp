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
	system("cls");	//"cls" : ȭ���� ����� ��ɾ�
	printf("*****************************************************\n");
	printf(" ��ۺ�Ʈ �ܱ� ??�� C��� ����\n");
	printf(" ����ü�� �̿��� ȸ�� ���� ���α׷�\n");
	printf(" 2020�� 04�� 24��\n");
	printf(" ccm\n");
	printf("*****************************************************\n");
	system("pause");	//"pause" : ��� ���� ��ɾ�
}
char App::Menuprint() 
{
	printf("*****************************************************\n");
	printf("[1] �� ��(insert)\n");
	printf("[2] �� ��(select)\n");
	printf("[3] �� ��(update)\n");
	printf("[4] �� ��(delete)\n");
	printf("[5] ����\n");
	printf("*****************************************************\n");

	return _getch();
}
void App::Ending()
{
	system("cls");
	printf("*****************************************************\n");
	printf(" ���α׷��� �����մϴ�.\n");
	printf("*****************************************************\n");
	system("pause");

	//	char idx;
	//	idx = _getch();		//Ư���� ������ ���� �Է��Լ�
	//	return idx;			//ȭ�鿡 ���� ����� X
	//return _getch();	//����Ű ���� ���۷� ����
}