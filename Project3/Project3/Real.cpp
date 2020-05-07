//최종 코드
#include<iostream>
using namespace std;

//객체지향프로그램은 class  만 사용함
//struct->class
//구조체는 기본이 public 이면 클래스는 기본이 private이다
class Student
{
private://맴버 변수 정의
	char* name;
	int number;
	char* subject;
	char gender;
public://생성자 구현
	Student(const char* _name, int _number, const char* _subj, char _gender)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		number = _number;
		subject = new char[strlen(_subj) + 1];
		strcpy_s(subject, strlen(_subj) + 1, _subj);
		gender = _gender;
	}
	~Student()
	{
		delete[] name;//동적 메모리
		delete[] subject;//동적 메모리
	}
	void Print()	{		cout << "이름 : " << name << endl;		cout << "학번 : " << number << endl;		cout << "학과 : " << subject << endl;		cout << "성별 : " << gender << endl;	}
};

int main()
{
	//스택에 객체를 생성
	Student stu("홍길동", 1111, "컴퓨터", 'm');
	stu.Print();
	//힙객체를 생성
	Student* pstu = new Student("홍길순", 2222, "it", 'f');

}