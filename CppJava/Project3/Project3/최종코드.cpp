//���� �ڵ�
#include<iostream>
using namespace std;

//��ü�������α׷��� class  �� �����
//struct->class
//����ü�� �⺻�� public �̸� Ŭ������ �⺻�� private�̴�
class Student
{
private://�ɹ� ���� ����
	char name[20];
	int number;
	char subject[20];
	char gender;
public://������ ����
	Student(const char* _name, int _number,const char* _subj, char _gender)
	{
		strcpy_s(name, sizeof(name), _name);
		number = _number;
		strcpy_s(subject, sizeof(subject), _subj);
		gender = _gender;
	}
	~Student()
	{

	}
	void Print()	{		cout << "�̸� : " << name << endl;		cout << "�й� : " << number << endl;		cout << "�а� : " << subject << endl;		cout << "���� : " << gender << endl;	}
};

int main()
{
	//���ÿ� ��ü�� ����
	Student stu("ȫ�浿", 1111,"��ǻ��",'m');
	stu.Print();
	//����ü�� ����
	Student* pstu = new Student("ȫ���", 2222, "it", 'f');
	pstu->Print();
	delete pstu;
	return 0;
}