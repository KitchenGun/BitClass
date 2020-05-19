#include<iostream>

using namespace std;

//일반 적인 경우는 컴파일러가 제공해주는 복사 생성자를 사용하면 된다 
//하지만 복사 생성자의 맴버 변수중에 heap메모리에 값을 저장하는 변수가 있다면 복사 생성자를 재정의 해줘야한다
class Sample
{
	char name[20];
	int age;
public :
	Sample(const char*_name,int _age)
	{
		strcpy_s(name, sizeof(name), _name);
		age = _age;
		cout << "sample" << endl;
	}
	~Sample()
	{
		cout << "~sample" << endl;
	}
	//내가 복사 생성자 제작 가능
	Sample(const Sample& sam)
	{
		strcpy_s(name, sizeof(name), sam.name);
		age = sam.age;
	}
public:
	void Print()
	{
		cout << name << "," << age << endl;
	}
};

int main()
{
	Sample sam1("홍길동",10);
	Sample sam2(sam1);//복사 생성자

	sam1.Print();
	sam2.Print();
	return 0;
}