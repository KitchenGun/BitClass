#pragma once
#include"wbglobal.h"
#include <time.h>


class Account
{
private:
	const int accnum; 	//��� ��� ���� 
	char name[20];

	int balance;//�ܾ�
	tm tmc;//������

public:
	//�й� �̸��� �������޷� �ʱ�ȭ
	//���� ���� �� �⺻ 0�� �ʱ�ȭ
	Account(int _num, const char* _name) : accnum(_num)//�ɹ� �ʱ�ȭ 
	{
		strcpy_s(name, sizeof(name), _name);
		balance = 0;
		//���� �����ɶ� ���� �Ͻø� ����
		time_t t = time(0);
		localtime_s(&tmc, &t);
	}

	Account(int _num, const char* _name,int _balance,int y,int m,int d) : accnum(_num)//�ɹ� �ʱ�ȭ 
	{
		strcpy_s(name, sizeof(name), _name);
		balance = _balance;

		//���� �����ɶ� ���� �Ͻø� ����
		tmc.tm_year = y - 1900;
		tmc.tm_mon = m - 1;
		tmc.tm_mday = d;
	}
public://get�޼���
	int GetNumber() const { return accnum; }
	const char* GetName() const { return name; }
	int GetBalance() const { return balance; }
	tm  GetTm() const { return tmc; }


	void SetName(const char* value)
	{
		strcpy_s(name, sizeof(name), value);
	}

public:
//	�Ա�& ���
	void InputMoney(int money)
	{
		if (money > 0)
		{
			balance += money;
			throw "�ԱݵǾ����ϴ�.";
		}
	}

	void OutputMoney(int money)
	{
		if (money <= 0)
			throw "�߸��� �Աݾ��Դϴ�.";
		if (money > balance)
			throw "�ܾ��� �����մϴ�.";

		balance -= money;
	}


	friend ostream& operator<<(ostream& os, Account* acc)
	{
		os << "���¹�ȣ : " << acc->accnum << "�̸� : " << acc->name;
		os << "�ܾ�:" << acc->balance << "��:";

		char str[80];
		strftime(str, sizeof(str), "%y-%m-%d %H:%M:%S", &acc->tmc);
		os<<"�����Ͻ�:"<<str;		
		return os;
	}

};