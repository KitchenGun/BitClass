#include<iostream>
using namespace std;
//up cast	�ڽ�->�θ𿡰� ����
//down cast	�θ�->�ڽĿ��� ����


class Animal
{
public:
	void Sound()
	{
		cout << "???????????" << endl;
	}
	void Eat()
	{
		cout << "�ȳ�" << endl;
	}
};

class Dog :public Animal
{
public:
	void Sound()
	{
		cout << "�۸�" << endl;
	}
	void bite()
	{
		cout << "bite" << endl;
	}

};

class Cat :public Animal
{
public:
	void Sound()
	{
		cout << "�߿�" << endl;
	}
	void scratch()
	{
		cout << "scratch" << endl;
	}

};

int main()
{
	//up casting ���� ����
	Animal* ani = new Dog;
	Animal* ani1 = new Cat;
	
	Dog dog;
	dog.Sound();
	dog.bite();

	Cat cat;
	cat.scratch();
	//�����Ϸ� ���忡�� ani2�� Ÿ���� animal*
	Animal* ani2 = &dog;
	//down casting�����ؾ��� �� ��ȯ
	Cat* pCat = (Cat*)ani2;//���� ���������� ����̵�
	pCat->scratch();


	return 0;
}