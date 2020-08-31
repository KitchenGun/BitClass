//member.h

#pragma once
#include<string.h>

class Member
{
private:
	int number;		//회원번호
	char name[20];	//이름
	char gender;	//성별
	char phone[20];	//전화번호
public:
	Member(int number,const char* _name,const char _gender,const char* _phone);
	~Member();
	//get set 메서드 맴버 변수의 외부노출 기능
public:
	int GetNumber()
	{
		return number;
	}
	const char* GetName()
	{
		return name;
	}
	char GetGender()
	{
		return gender;
	}
	const char* GetPhone()
	{
		return phone;
	}
	void SetNumber(int value)
	{
		number = value;
	}
	void SetName(const char* value)
	{
		strcpy_s(name, sizeof(name), value);
	}
	void SetGender(char value)
	{
		if (gender == 'm' || gender == 'f')
			gender = value;
	}
	void SetPhone(const char* value) 
	{ 
		strcpy_s(phone, sizeof(phone), value); 
	}
public:
	void Print();
	void PrintIn();
};
