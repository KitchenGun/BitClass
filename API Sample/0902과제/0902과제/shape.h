#pragma once
//���� ���� ���α׷�
/*
[���� ����]
1. ���� Ÿ�� ����
2. ���� ���� ����
   ���庯��, ���� ���� ���� ���� ����
3. ���� ������ �ʱ���
4. ���� ���� ���� ������ ���� ���
   ������ ����� ������ Ȯ���ϱ� ���� Ÿ��Ʋ�ٿ� ���
5. ������ ����ϴ� ���
   ���� ���� ������ �̿��ؼ�
*/
#include <Windows.h>
#include<tchar.h>
#include<vector>
using namespace std;

typedef struct tagSHAPE
{
	POINT pt;//��ǥ
	int size; //ũ��(25,50,75,100)
	COLORREF b_color;
	COLORREF p_color;	//�� ����
	int type;			//Ÿ��(�簢��, Ÿ��, �ﰢ��)
}SHAPE;


