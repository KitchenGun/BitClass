/************************************************************
 class
 -> 아래 코드를 객체 중심의 코드로 변경하시오.
door라는 이름의 구조체를 정의할 것
맴버 변수는 int door 이며 나머지 함수들을 맴버 함수로
추가하고, 인자 전달을 제외할 것
*************************************************************/
#include <iostream>
using namespace std;

enum { OPEN = 1, CLOSE, UNKNOWN };

typedef struct door
{
	int door;

	void door_open()
	{
		door = OPEN;
	}

	void door_close()
	{
		door = CLOSE;
	}

	void show_door_status()
	{
		if (door == OPEN)
			cout << "Door is Open" << endl;

		else if (door == CLOSE)
			cout << "Door is Close" << endl;

		else
			cout << "I don't Know !!" << endl;
	}

}door;



void main()
{
	door d;
	d.show_door_status();
	d.door_open();
	d.show_door_status();

	d.door_close();
	d.show_door_status();
}
