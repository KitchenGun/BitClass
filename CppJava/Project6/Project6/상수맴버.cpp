#include <iostream>

using namespace std;

/*
��� �ɹ� ���� �ݵ�� �ݷ� �ʱ�ȭ ���� �ʱ�ȭ
��� �ɹ� �Լ� �ش� �Լ� �������� ����� �ɹ������� ���� ���� �� �� ����
				���� ��� �ɹ� �Լ� ������ ��� �ɹ� �Լ��� ȣ�⸸ ����
*/

class Member
{
	const int id;//��� ����
	int testnum;//�ɹ� ����
public :
	Member(int _id) :id(_id)
	{
		testnum = _id;
	}
public:
	void func1()
	{
		//id = 10;

		testnum = 10;

	}
	void func2()
	{

	}
	void func3() const
	{

	}

	void constfun1(int temp) const
	{//��� �ɹ� �Լ� 
		temp++;//���� ���� ���� ����
		//testnum++;//error�ɹ� ���� ���� �Ұ���
		//func2();//error�Ϲ� �ɹ� �Լ�
		func3();//ok��� �ɹ� �Լ�
	}
};

int main()
{
	Member member(10);
	member.constfun1(1);//���� �Ұ���

	return 0;
}