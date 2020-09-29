#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
#include <sql.h>
#include <sqlext.h>
#include"wb_db.h"

void init()
{
	printf("SQL * Plus: Release 11.2.0.1.0 Production on 목 9월 24 09 : 28 : 08 2020\n");
	printf("Copyright(c) 1982, 2010, Oracle.All rights reserved.\n");
	TCHAR id[20], pw[20];
	//DB접속 처리 코드
	while (true)
	{		
		printf("사용자명 입력 : ");	gets_s(id, sizeof(id));
		printf("비밀번호 입력 : ");	gets_s(pw, sizeof(pw));

		//DB의 접속 요청
		if (wb_DBConnect(id, pw) == FALSE)
			printf("접속오류입니다\n\n");
		else
			break;
	}
}

void run()
{
	//접속 후 로그 
	printf("\n다음에 접속됨 :\n");
	printf("Oracle Database 11g Enterprise Edition Release 11.2.0.1.0 - Production\n");
	printf("With the Partitioning, OLAP, Data Mining and Real Application Testing options\n");

	TCHAR msg[256];		//쿼리문 전체
	TCHAR flag[256];	//쿼리문 첫 문자(키워드)
	while (true)
	{
		printf("SQL> ");		gets_s(msg, sizeof(msg));
		//================= 토큰 분리================================
		// 단방향 : DDL문(create, drop...) DML(insert, update, delete)
		//--------------------------------------------------------------
		// 양방향 : DML-DQL(select)
		//----------------------------------------------------------
		//입력된 0번째 문자부터 공백문자 전까지 획득... 어떤 명령어인지 분리		
		TCHAR* next_token1 = NULL;
		_tcscpy_s(flag, sizeof(flag), msg);
		strtok_s(flag, " ", &next_token1);
		//===========================================================
		if (_tcscmp(msg, TEXT("exit")) == 0)
		{
			break;
		}
		else if (_tcscmp(flag, TEXT("select")) == 0)
		{
			wb_DBSendSelectData(msg);
		}
		else
		{
			wb_DBSendOtherData(msg);
		}
	}
}



void exit()
{
	wb_DBDisConnect();
	printf("\nOracle Database 11g Enterprise Edition Release 11.2.0.1.0 - Production\n");
	printf("With the Partitioning, OLAP, Data Mining and Real Application Testing options에서 분리되었습니다.\n\n");
}


int main()
{
	init();
	run();
	exit();

	return 0;
}