#include <stdio.h>
#include <stdlib.h>//system()
#include <conio.h>//_getchar();

#include "app.h"
#include "sample.h"

//�ʱ�ȭ ���
void app_init()
{
	loge();
	sample_init();
}
//���� ���
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
//���� ó�� ���
void app_exit()
{
	ending();
}

void loge()
{
	system("cls");
	printf("*************************************************************************************\n");
	printf("��� ��Ʈ �ܱ� c������\n");
	printf("�Լ��� �迭�� �̿��� ���α׷� \n");
	printf("2020:04:14\n");
	printf("ccm\n");
	printf("*************************************************************************************\n");
	system("pause");
}
void ending()
{
	system("cls");
	printf("*************************************************************************************\n");
	printf("���α׷��� �����մϴ�\n");
	printf("*************************************************************************************\n");
	system("pause");
}
char menuprint()
{

	printf("*************************************************************************************\n");
	printf("[1]�Է�(insert)\n");
	printf("[2]�˻�(select)\n");
	printf("[3]����(update)\n");
	printf("[4]����(delete)\n");
	printf("[5]����\n");
	printf("*************************************************************************************\n");
	
	return _getch();//����Ű ���� ���۷� ����
}
