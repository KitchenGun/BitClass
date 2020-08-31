#include<iostream>

using namespace std;

class Human
{
private:
	char name[20];
public:
	Human(const char* _name)
	{
		strcpy_s(name, sizeof(name), _name);
	}
public:
	virtual void Intro()
	{
		cout << name << "\t";
	}
	virtual void Think()
	{
		cout << "�θ��� ���忡�� ����" << endl;
	}
};

class Student :public Human
{
private:
	int number;
public:
	Student(const char* _name, int _number) :Human(_name)
	{
		number = _number;
	}
public:
	void Intro()
	{
		Human::Intro();
		cout << number << endl;
	}
	void Think()
	{
		cout << "�ڽ��� ���忡�� ����" << endl;
	}
	void Study()
	{
		cout << "���θ� �մϴ�" << endl;
	}
};

void main()
{
	Student K("ȫ�浿", 9506299);
	K.Intro();		//�̸��� �й� ���
	K.Think();		// �θ��� �Լ��� ������
		   //�θ��� Think() : "�θ��� ���忡�� ����" ���ڿ� ���
		   //�ڽ��� Think() : "�ڽ��� ���忡�� ����" ���ڿ� ���
	K.Study();		// �ڽĸ� ������ �ִ� �Լ�
					// "���θ� �մϴ�" ���ڿ� ���
}
