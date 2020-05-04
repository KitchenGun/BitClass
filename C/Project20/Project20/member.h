#pragma once//구조체 정의는 헤더 파일에서 그래야 모든 소스파일들이 해당 키워드를 알게 된다


typedef struct tagmember
{
	int flag;//0이면 없는 정보 1 저장된 정보
	int number;
	char name[20];
	char gender;
	char phone[20];

}member;
