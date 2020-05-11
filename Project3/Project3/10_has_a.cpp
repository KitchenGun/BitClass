/*
강력한 has a 관계
(라이프 사이클이 동일 생성과 종료시점 동일)

*/
#include<iostream>
using namespace std;
class gun
{
private:
	int count;//총알 개수
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
	man()//man 이 만들어지면 gun도 만들어짐
	{
		g1 = new gun(2);
	}
	~man()//man 이 소멸되면 같이 소멸됨
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