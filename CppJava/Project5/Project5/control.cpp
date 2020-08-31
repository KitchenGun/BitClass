
#include<iostream>
using namespace std;
#include "control.h"

control::control()
{
	for (int i = 0; i < DATAMAX; i++)
	{
		memlist[i] = NULL;
	}
}


control::~control()
{

}

void control::SelectAll()
{

	cout<<"ȸ����ȣ\t�̸�\t����\t��ȭ��ȣ"<<endl;
	cout<<"----------------------------------------------"<<endl;
	for (int i = 0; i < DATAMAX; i++)
	{
		Member* mem = memlist[i];

		//�����Ͱ� ������ ���� ��� 
		if (mem != NULL)
			mem->Print();
	}
}

void control::Insert()
{
	int idx;
	char name[20], phone[20];
	char gender;

	cout<<"������ġ(0 ~ "<< DATAMAX - 1<<") : ";
	cin>>idx;
	cin.ignore();
	//getchar();
	if (idx < 0 || idx >= DATAMAX)
	{
		cout<<"�߸��� �ε����� �Է��ϼ̽��ϴ�."<<endl;
		return;
	}
	else
	{
		if (memlist[idx] != NULL)
		{
			cout<<"�����Ͱ� �����մϴ�."<<endl;
			return;
		}
	}

	cout << "�̸� : ";
	cin.getline(name, sizeof(name));//c �ڵ��� gets_s�� ���ϱ��

	cout<<"����(m or f) : ";
	cin>>gender;
	cin.ignore();
	//getchar();
	cout<<"��ȭ��ȣ : ";
	cin.getline(phone, sizeof(phone));

	//���ڿ��� ��������� ������ ���� �ٸ� ����� �ִ�. 
	Member* pmem = new Member(idx, name, gender, phone);
	memlist[idx] = pmem;

	cout<<"����Ǿ����ϴ�."<<endl;
}

void control::Select()
{
	//�˻��� ȸ��ID�� �Է¹޴´�.
	int number;
	cout<<"ȸ��ID �Է� : ";
	cin>>number;

	//�˻� �˰��� 
	int idx = NumberToIdx(number);
	if (idx == -1)
	{
		cout<<"�����Ͱ� �����ϴ�."<<endl;
		return;
	}

	cout << "[" << idx << "��° �ε���]" << endl;
	memlist[idx]->PrintIn();

}


int control::NumberToIdx(int number)
{
	for (int i = 0; i < DATAMAX; i++)
	{
		Member* mem = memlist[i];
		if (mem != NULL && mem->GetNumber() == number)
			return i;
	}
	return -1;
}

int control::NameToIdx(const char* name)
{
	for (int i = 0; i < DATAMAX; i++)
	{
		Member* mem = memlist[i];
		if (mem != NULL && strcmp(mem->GetName(), name) == 0)
			return i;
	}
	return -1;
}
