#pragma once
#include<Windows.h>
#include<tchar.h>

typedef struct tagMember
{
	int number;
	TCHAR name[20];
	char gender;
	TCHAR phone[20];
}Member;


#define WM_ADD_LIST	WM_USER+101
#define WM_Find_LIST	WM_USER+102