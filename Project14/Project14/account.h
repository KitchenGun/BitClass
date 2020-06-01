#pragma once
#include"wbglobal.h"
#include <time.h>


class Account
{
private:
	const int accnum; 	//상수 멤버 변수 
	char name[20];

	int balance;//잔액
	tm tmc;//개설일

public:
	//학번 이름만 인자전달로 초기화
	//성적 정보 는 기본 0값 초기화
	Account(int _num, const char* _name) : accnum(_num)//맴버 초기화 
	{
		strcpy_s(name, sizeof(name), _name);
		balance = 0;
		//계좌 생성될때 현재 일시를 저장
		time_t t = time(0);
		localtime_s(&tmc, &t);
	}

	Account(int _num, const char* _name,int _balance,int y,int m,int d) : accnum(_num)//맴버 초기화 
	{
		strcpy_s(name, sizeof(name), _name);
		balance = _balance;

		//계좌 생성될때 전달 일시를 저장
		tmc.tm_year = y - 1900;
		tmc.tm_mon = m - 1;
		tmc.tm_mday = d;
	}
public://get메서드
	int GetNumber() const { return accnum; }
	const char* GetName() const { return name; }
	int GetBalance() const { return balance; }
	tm  GetTm() const { return tmc; }


	void SetName(const char* value)
	{
		strcpy_s(name, sizeof(name), value);
	}

public:
//	입금& 출금
	void InputMoney(int money)
	{
		if (money > 0)
		{
			balance += money;
			throw "입금되었습니다.";
		}
	}

	void OutputMoney(int money)
	{
		if (money <= 0)
			throw "잘못된 입금액입니다.";
		if (money > balance)
			throw "잔액이 부족합니다.";

		balance -= money;
	}


	friend ostream& operator<<(ostream& os, Account* acc)
	{
		os << "계좌번호 : " << acc->accnum << "이름 : " << acc->name;
		os << "잔액:" << acc->balance << "원:";

		char str[80];
		strftime(str, sizeof(str), "%y-%m-%d %H:%M:%S", &acc->tmc);
		os<<"개설일시:"<<str;		
		return os;
	}

};