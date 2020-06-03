
#pragma once
#include<vector>
using namespace std;
#include"account.h"//데이터 클래스


class accManager
{
	vector<Account*> base;//Stu* base;
public:
	accManager();
	~accManager();
public:
	void Run();
private:
	keydata SelectMenu();
	void ListAll();
	void AddAccount();//insert
	void RemoveAccount();//delete
	void SearchAccountByNum();//select
	void SearchAccountByNum1();
	void SearchAccountByName();//select
	void UpdateInputAccount();//update
	void UpdateOutputAccount();

	int NumToIdx(int accnum);//select
};

