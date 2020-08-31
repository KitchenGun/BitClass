#include<Windows.h>
#include<iostream>
#include<conio.h>
/*
[�߻�ȭ ����:�ɹ����� �ɹ� �Լ��� �����ϴ� ����]
�Ϲ� ����:���� ��ȣ, �̸�, �ܾ�					�Ա�() ���() �������()
�ſ� ����:���� ��ȣ, �̸�, �ܾ�, ������			�Ա�() ���() �������()
��� ����:���� ��ȣ, �̸�, �ܾ�, ��α� �Ѿ�	�Ա�() ���() �������()
�Ϲ� ���� �Ա��Ҷ�
�Ա�(1000)-> �ܾ� = �ܾ� +1000
�ſ���� �Ա��Ҷ�
�Ա�(1000)-> �ܾ� = �ܾ� +1000+(1000*0.01)
��ΰ��¿� �Ա��� ���� �Աݾ��� 1%�� ��α����� �����Ѵ�.
�Ա�(1000) --> �ܾ� = �ܾ� + 1000 - (1000*0.01)
		   --> ��α��Ѿ� = ��α��Ѿ� + (1000*0.01)

*/
using namespace std;

class Account
{
private://�ɹ�����
	int accid;
	char name[20];
	int balance;
public:// ������
	Account(int _accid, const char* _name)
	{
		accid = _accid;
		strcpy_s(name, sizeof(name), _name);
		balance = 0;
	}
	Account(int _accid,const char*_name,int _balance)
	{
		accid = _accid;
		strcpy_s(name, sizeof(name), _name);
		balance = _balance;
	}
public://�Լ�
	virtual bool InputMoney(int money)
	{
		if (money < 0)
		{
			return false;
		}
		balance += money;
		return true;
	}
	int OutputMoney(int money)
	{
		if (money < 0)
		{
			return -1;
		}
		if (money > balance)
		{
			return -2;
		}
		balance = balance - money;
		balance -= money;
		return 1;
	}
	virtual void PrintData() const
	{
		cout << "[���� ��ȣ]" << accid << "\t";
		cout << "[�̸�]" << name << "\t";
		cout << "[�ܾ�]" << balance << "��" << "\t";
	}
};


class FaithAccount:public Account
{

public:
	FaithAccount(int _accid, const char* _name):Account(_accid,_name)
	{

	}

	FaithAccount(int _accid, const char* _name, int _balance):Account(_accid, _name,_balance)
	{
	
	}
public:
	bool InputMoney(int money)
	{
		return Account::InputMoney((int)(money + money * 0.01));
	}
};

class ContriAccount:public Account
{
private:
	int contribution;
public:
	ContriAccount(int _accid, const char* _name) : Account(_accid, _name)
	{
		contribution = 0;
	}
	ContriAccount(int _accid, const char* _name, int _balance) :Account(_accid, _name, (int)(_balance+_balance*0.01))
	{
		contribution = (int)(_balance * 0.01f);
	}
public:
	bool InputMoney(int money)
	{
		if (Account::InputMoney((int)money - (money * 0.01f))==false)
		{
			return false;
		}
		contribution += (int)(money * 0.01f);
		return true;
	}
	void PrintData()
	{
		Account::PrintData();
		cout << "[����Ѿ�]" << contribution << "��" << "\t";
	}
};

int main()
{
	//=================init================
	srand((unsigned int)time_t(NULL));

	Account* acclist[3];
	acclist[0] = new Account(1111, "hong");
	acclist[1] = new FaithAccount(2222, "kang");
	acclist[2] = new ContriAccount(3333, "kim");
	cout << "start";
	_getch();//conio.h
	//==================run=================
	while (true)
	{
		system("cls");

		//���� �����ϰ� ���� & ����ݱݾ�
		int io = rand() % 10;       //0~9
		int money = ((rand() % 9) + 1) * 10000; //10000~90000

		//��/��¿���(��� ���¿� ����)
		if (io >= 8)        //�Ա�
		{
			cout << "[�Ա�] " << money << "��" << endl;
			for (int i = 0; i < 3; i++)
			{
				acclist[i]->InputMoney(money);
			}
		}
		else                //���
		{
			cout << "[���] " << money << "��" << endl;
			for (int i = 0; i < 3; i++)
			{
				acclist[i]->OutputMoney(money);
			}
		}

		//������
		for (int i = 0; i < 3; i++)
		{
			acclist[i]->PrintData();    cout << endl;
		}

		Sleep(500); //0.5�� ���߱�      #include <Windows.h>
	}
	return 0;
}


