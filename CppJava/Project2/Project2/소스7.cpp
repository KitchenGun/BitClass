/************************************************************
 class
 -> �Ʒ� �ڵ带 ��ü �߽��� �ڵ�� �����Ͻÿ�.
door��� �̸��� ����ü�� ������ ��
�ɹ� ������ int door �̸� ������ �Լ����� �ɹ� �Լ���
�߰��ϰ�, ���� ������ ������ ��
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
