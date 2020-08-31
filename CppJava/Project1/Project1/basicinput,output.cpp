#include<iostream>


using namespace std;

int main()
{
	//cout 출력객체 출력의 역할을 담당함
	//<<   출력연산자 출력객체를 이용하여 화면에 정보를 출력할때 사용되는 연산자
	//endl \n 와 fflush(stdout)2가지 기능을 제공하는 함수
	//cin  입력 연산자 >>

	char name[20];
	int age;
	char gender;
	float weight;
	//사용자 입력을 통한 초기화
	cout << "이름 : ";
	cin >> name;
	cout << "나이 : ";
	cin >> age;
	cout << "성별(m/f) : ";
	cin >> gender;
	cout << "몸무게 : ";
	cin >> weight;


	cout<< "이름 : "<<name<<endl;
	cout << "나이 : "<<age<<endl; 
	cout << "성별(m/f) : "<<gender<<endl;
	cout << "몸무게 : "<<weight<<endl;
	return 0;
}


