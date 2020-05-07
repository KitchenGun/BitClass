//데이터 은닉

#include <iostream>
using namespace std;

struct  bycle
{//캡슐화
	int gear;//맴버 변수
	void changeGear(int g)
	{//맴버 함수
		if(g>=1&&g<=20)//입력값 제한
		gear = g;
	}
	void printGear()
	{
		cout << "현재 기어상태 : " << gear << "단" << endl;
	}
};

int main()
{
	bycle by1 = { 5 };
	bycle by2 = { 3 };

	by1.printGear();
	by2.printGear();
	//비정상적 값변화
	//by1.gear = 100;
	//by2.gear = -10;
	
	by1.changeGear(8);
	by2.changeGear(10);

	by1.printGear();
	by2.printGear();

	return 0;
}
