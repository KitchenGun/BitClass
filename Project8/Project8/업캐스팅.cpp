#include<iostream>
using namespace std;
//up cast	자식->부모에게 대입
//down cast	부모->자식에게 대입


class Animal
{
public:
	void Sound()
	{
		cout << "???????????" << endl;
	}
	void Eat()
	{
		cout << "냠냠" << endl;
	}
};

class Dog :public Animal
{
public:
	void Sound()
	{
		cout << "멍멍" << endl;
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
		cout << "야옹" << endl;
	}
	void scratch()
	{
		cout << "scratch" << endl;
	}

};

int main()
{
	//up casting 정상 문법
	Animal* ani = new Dog;
	Animal* ani1 = new Cat;
	
	Dog dog;
	dog.Sound();
	dog.bite();

	Cat cat;
	cat.scratch();
	//컴파일러 입장에서 ani2의 타입은 animal*
	Animal* ani2 = &dog;
	//down casting조심해야할 형 변환
	Cat* pCat = (Cat*)ani2;//현재 강아지에서 고양이됨
	pCat->scratch();


	return 0;
}