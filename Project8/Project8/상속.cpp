#include<iostream>
/*자식객체의 공통 부분을 해결하는 법
강아지:소리냄
고양이:소리냄
*/
using namespace std;
class Animal
{
public:
	void Sound()
	{
		cout << "???????????" << endl;
	}
};

class Dog :public Animal
{
public:
	void Sound()
	{
		cout << "멍멍" << endl;
	}
};

class Cat:public Animal
{
public:
	void Sound()
	{
		cout << "야옹" << endl;
	}
};

int main()
{
	Dog dog;
	dog.Sound();
	Cat cat;
	cat.Sound();
	return 0;
}