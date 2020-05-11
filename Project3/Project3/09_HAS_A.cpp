/*
클래스와 클래스의 관계성
has a == 소유
is a == 상속
==============
학생이 펜을 가지고 있다 (소유)
객체 [학생,펜]

*/


#include<iostream>
using namespace std;
//일시적인 소유 관계 학생이 펜을 가지고 있다
//pen 클래스 정의 -> 추상화(일부만 표현 하는것)vs 정밀화(눈에 보이는것을 똑같이 표현하는것)=주로 추상화 사용함
class pen
{
	//1.맴버 변수
private:
	char color[20];
	int widht;
	//2. 생성자
public:
	pen(const char* _color,int _width)
	{
		strcpy_s(color, sizeof(color), _color);
		widht = _width;
	}
	~pen()
	{

	}
	//3.메서드 (맴버 함수)
public:
	void Write(const char *msg)
	{
		cout << "[" << color << ":";
		cout << widht << "]";
		cout << msg << endl;
	}
};
//이름 학번 
//펜으로 글씨를 쓸 수 있다.
class student
{
private:
	char name[20];
	int number;
	pen* mypen;
public:
	student(const char* _name, int _number)
	{
		strcpy_s(name, sizeof(name), _name);
		number = _number;
		mypen = NULL;//소유하지 않은 상태
	}
	~student()
	{

	}
public:
	void grappen(pen *_pen)
	{//펜소유가 일시적 발생
		mypen = _pen;
	}
	void droppen()
	{
		mypen = NULL;//소유하지 않은 상태
	}

	void write(const char *msg)
	{
		if (mypen == NULL)
		{//펜이 없을 경우
			return;
		}
		mypen->Write(msg);//펜을 소유한 이유 펜의 기능을 사용할려고
	}
};
int main()
{
	//객체 생성
	student stu("kang", 111);
	pen redpen("red", 2);
	pen blue("blue", 1);
	pen greenpen("green", 5);

	stu.grappen(&redpen);
	stu.write("글씨를 쓰고 있습니다");
	stu.droppen();

	stu.write(" 쓰는 중 ");
	return 0;
}