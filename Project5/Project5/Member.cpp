#include "member.h"
#include<iostream>
using namespace std;


Member::Member(int _number, const char* _name, const char _gender, const char* _phone)
{
	number = _number;
	strcpy_s(name, sizeof(name), _name);
	gender = _gender;
	strcpy_s(phone, sizeof(phone), _phone);
}


Member::~Member()
{

}


void Member::Print()
{
	cout << number << "\t\t" << name << "\t" << (gender == 'm' ? "��" : "��") << "\t" << phone << endl;
}


void Member::PrintIn()
{
	cout <<"��ȣ : "<< number << "\n�̸� : " << name << "\n���� : " << (gender == 'm' ? "��" : "��") << "\n���� : " << phone << endl;
}
