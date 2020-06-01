#pragma once
#include<vector>
using namespace std;
#include"account.h"//������ Ŭ����


class accManager
{
	vector<Account*> base;//Stu* base[10];
	const int max;
public:
	accManager();
	~accManager();
public:
	void Run();
private:
	int SetMax();
	keydata SelectMenu();
	void ListAll();
	void AddAccount();//insert
	void RemoveAccount();//delete
	void SearchAccountByNum();//select
	void SearchAccountByName();//select
	void UpdateInputAccount();//update
	void UpdateOutputAccount();
	int NumToIdx(int accnum);
};

