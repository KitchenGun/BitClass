/************************************************************
�Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ����
	   Student Ŭ������ �Ʒ��� �ɹ������� �Ʒ��� ����.
	   char number[20],  char name[20],  , int score
*************************************************************/
#include<iostream>
#include<string>

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
	char* GetStNum()
	{
		return number;
	}
	void SetScore(int _score)
	{
		if (_score < 0||_score>100)
			return;
		score = _score;
	}
	int GetScore()
	{
		return score;
	}
	Student(int num):score(0)
	{
		sprintf_s(number,"%d", num);//�̰� �´����𸣰ڽ��ϴ�
		strcpy_s(name, sizeof(name), "");
	}
	~Student()
	{

	}
};

int main()
{
	Student Kim(8906123);	// number�� ���޵������� �ʱ�ȭ, name�� "", score�� 0���� �ʱ�ȭ
	Kim.SetName("ȫ�浿");  // �̸� ����
	Kim.SetScore(99);	// �� �ش� Set�޼��忡�� 0~100��  ���� ó���� �� �ֵ��� �Ұ� 
					  // �� �̿��� ���� ������ ����

	cout << "�й� : " << Kim.GetStNum() << endl;   // GetStNum() : �й� ��ȯ
	cout << "�̸� : " << Kim.GetName() << endl;    // GetName() : �̸� ��ȯ
	cout << "���� : " << Kim.GetScore() << endl;     // GetScore() : ���� ��ȯ

	return 0;
}