#pragma once
#include<vector>
using namespace std;
#include"stu.h"


class stuManager
{
	vector<Stu*> base;//Stu* base[10];
	const int max;
public:
	stuManager();
	~stuManager();
public:
	void Run();
private:
	int SetMaxStu();
	keydata SelectMenu();
	void ListAll();
	void AddStu();//insert
	void RemoveStu();//delete
	void SearchStuByNum();//select
	void SearchStuByName();//select
	void UpdateStu();//update
};


