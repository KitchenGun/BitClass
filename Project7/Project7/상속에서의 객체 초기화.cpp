#include<iostream>
using namespace std;
//��ü �ʱ�ȭ�� �ڽ��� �����ڿ��� 


class Person
{
protected:
	char name[20];
	int age;
public:
	Person(const char* _name, int _age)
	{
		strcpy_s(name, sizeof(name), _name);
		age = _age;
	}
public:
	void Print() const
	{
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
	}
	int getAge()const
	{
		return age;
	}
	const char* getName()const
	{
		return name;
	}
};

class Student:Person
{
	char subject[20];
	int number;
public:
	//�ڽ� �����ڿ����� �θ� ������ � �����ڸ� ȣ�������� ������ ����Ѵ�
	//���� ������ �����ָ� �θ�� ���� ���� ����Ʈ �����ڸ� ȣ���ϸ鼭 �����ȴ�
	Student(const char* _name,int _age,const char* _subj,int _num)
		:Person(_name,_age)
	{
		strcpy_s(subject, sizeof(subject), _subj);
		number = _num;
	}
public:
	void Print() const
	{//������ �������̵�
		//�θ��� �ɹ��Լ��� ���¸� ����Ÿ�� �̸� �Ű����� ����Ʈ �����ϰ� �ڽĿ��� ����
		cout << "name : " << name << endl;		//protected
		cout << "age : " << getAge() << endl;		//getset ȣ��/////////////////���� ����Ǵ� ���

		Person::Print();
		cout << "subject : " << subject << endl;
		cout << "number : " << number << endl;
	}
	

};

int main()
{
	Student stu("ȫ�浿",20,"��ǻ��",1111);
	stu.Print();
	return 0;

}