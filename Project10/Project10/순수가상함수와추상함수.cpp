#include <iostream>using namespace std;//추상 클래스class Animal{public:	virtual void Sound() const { cout << "............." << endl; }};//부모의 수상 메서드를 재정의하지 않으면 자식도 추상클래스가 된다 //virtual 정의 하면 된다class Dog : public Animal{public:	void Sound() const	{		cout << "멍멍!!!" << endl;	}};int main(){	Animal* p = new Dog;	p->Sound();	delete p;	Dog dog;	dog.Sound();	return 0;}
