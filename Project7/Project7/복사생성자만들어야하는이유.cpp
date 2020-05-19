#include<iostream>

using namespace std;
//-자신과 동일 한 객체를 생성할때 생성하는 복사 생성자
//다른 생성자와는 달리 컴파일러가 기본적으로 지원해 주는 생성자
//전달 객체 정보를 복사해서 새로운 객체를 생성
class Sample
{
	char* name;
	int age;
public:
	Sample(const char* _name, int _age)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		age = _age;
		cout << "sample" << endl;
	}
	~Sample()
	{
		delete[] name;
		cout << "~sample" << endl;
	}
	//내가 복사 생성자 제작 가능
	Sample(const Sample& sam)
	{
		name = new char[strlen(sam.name) + 1]; 
		strcpy_s(name, strlen(sam.name) + 1, sam.name);
		age = sam.age;
	}
public:
	void SetName(const char* value)
	{
		strcpy_s(name, strlen(value) + 1, value);

	}
	void Print()
	{
		cout << name << "," << age << endl;
	}
};

int main()
{
	Sample sam1("홍길동", 10);
	Sample sam2(sam1);//복사 생성자
	sam1.SetName("이길동");
	sam1.Print();
	sam2.Print();
	return 0;
}