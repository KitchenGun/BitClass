#include<iostream>
using namespace std;
/*
맴버 변수 앞에 static 키워드 추가
클래스 맴버라 부름 (인스턴스 아님)
인스턴스=객체를 만들때 별도의 메모리 공간 가지고 있는 것

*/



class  card
{
	static int width;//길이
	static int height;//높이
private:
	int number;//1~10,j11q12k13
	string shape;//다이아 클로버 스페이드 하트
	//인스턴스 맴버가 아니다 클래스 맴버다 모든 객체가 동일한 값을 가져야함으로
	

public:
	card(int _number, string _shape)
	{
		number = _number;
		shape = _shape;
	}
public:
	void Print() const
	{
		cout << number << ", " << shape << ", " << width << ", " << height << endl;
	}

};

int card::width = 200;
int card::height = 600;


int main()
{
	card c1(1, "clober");
	card c2(2, "dieamond");
	return 0;
}