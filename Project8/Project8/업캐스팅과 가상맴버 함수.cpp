#include<iostream>

using namespace std;

//다수의 강아지들과 고양이 객체를 생성해서 관리하고자 한다면?
//추가로 동물의 종류가 늘어난다면
//동물별 배열의 갯수가 증가 업캐스팅을 사용하면 배열 한개로 끝난다
class Animal
{
public:
	//자식이 생기면 재정의 될만한 함수는 가상 맴버 함수로 만든다 
	//부모의 포인터로 해당 메서드를 호출하면 자식의 재정의 함수로 호출한다
	virtual void Sound()
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

class Cat :public Animal
{
public:
	void Sound()
	{
		cout << "야옹" << endl;
	}

};

int main()
{
	Animal* woori[10];//10개의 객체의 주소를 저장할수있는 배열 생성
	woori[0] = new Dog;
	woori[1] = new Cat;
	woori[2] = new Cat;
	woori[3] = new Cat;
	for (int i=0; i < 4; i++)
	{//모든 동물의 소리를 동일한 객체를 이용해서 호출
		//어쩔때는 개소리 어쩔때는 고양이 소리가 난다
		//이를 다형성이라고 한다
		woori[i]->Sound();
	}
	return 0;
}