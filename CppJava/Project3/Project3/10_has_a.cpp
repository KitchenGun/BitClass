/*
������ has a ����
(������ ����Ŭ�� ���� ������ ������� ����)

*/
#include<iostream>
using namespace std;
class gun
{
private:
	int count;//�Ѿ� ����
public:
	gun(int _count = 10)
	{
		count = _count;
	}
public:
	void shoot()
	{
		if (count > 0)
		{
			cout << "Fire" << endl;
			count--;
		}
		else
		{
			cout << "out of ammo" << endl;
		}
	}
};

class man
{
private:
	gun* g1;
public:
	man()//man �� ��������� gun�� �������
	{
		g1 = new gun(2);
	}
	~man()//man �� �Ҹ�Ǹ� ���� �Ҹ��
	{
		delete g1;
	}
public:
	void gunshoot()
	{
		g1->shoot();
	}
};

int main()
{
	man man1;
	man1.gunshoot();
	return 0;
}