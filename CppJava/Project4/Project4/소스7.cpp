//
///************************************************************
//  09. �Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ����
//	  Student Ŭ������ �ɹ� ������ �й�, �̸�, ������ �ִ�.
//
//	  ������ �����ε�		:
//	  Set �޼���			:
//	  Get �޼���			:
//*************************************************************/

#include <iostream>
using namespace std;

class Student
{
	char number[20];
	char name[20];
	int score;

public:
	void SetName(const char* _name)
	{
		strcpy_s(name, sizeof(name), _name);
	}
	char* GetName()
	{
		return name;
	}
	void SetNumber(int _num)
	{
		sprintf_s(number, "%d", _num);
	}
	char* GetStNum()
	{
		return number;
	}
	void SetScore(int _score)
	{
		if (_score < 0 || _score>100)
		{
			cout << "������ �� �ִ� ������ ������ϴ�." << endl;
			return;
		}
		score = _score;
	}
	int GetScore()
	{
		return score;
	}
	Student(int num) :score(0)
	{
		sprintf_s(number, "%d", num);
		strcpy_s(name, sizeof(name), "");
	}
	Student(const char* _name,int _score):score(_score)
	{
		SetName(_name);
	}
	~Student()
	{

	}
};

void main()
{
	Student Hong(906123);	// �й�
	Hong.SetName("ȫ�浿");

	Hong.SetScore(99);		// �� �ش� Set�޼��忡�� 0~100�� 
						   // ���� ó���� �� �ֵ��� �Ұ� 
	Hong.SetScore(101);		// "������ �� �ִ� ������ ������ϴ�."��� ���ڿ��� ����� ��

	cout << "�й� : " << Hong.GetStNum() << endl;
	cout << "�̸� : " << Hong.GetName() << endl;
	cout << "���� : " << Hong.GetScore() << endl;

	Student Kim("��浿", 80);	// �̸�, ����
	Kim.SetNumber(945126);	// �й�

}