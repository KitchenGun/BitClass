/************************************************************
 �Ʒ� �ڵ尡 ����� �� �ִ� Ŭ���� ����
	   ��, PositionŬ������ �Ʒ��� ���� �ɹ������� �����Ǿ� �ִ�.
	   int x,  int y, char ch
*************************************************************/
#include <iostream>
using namespace std;

class Position
{
	int x;
	int y;
	char ch;
public:
	void OutPosition()
	{
		cout <<"["<< x << ", " << y << "] => " << ch << endl;
	}

	Position(int _x=0, int _y=0, char _ch='X') :x(_x), y(_y), ch(_ch)
	{

	}
	Position(char _ch = 'X') :x(0), y(0), ch(_ch)
	{

	}

	~Position()
	{

	}

};
void main()
{
	Position Here(30, 10, 'A');  //x 30, y 10, ch 'A'�� �ʱ�ȭ
	Position There(40, 5);      //x 40, y 5, ch �� 'X'�� �ʱ�ȭ
	Position Where('K');      // x 0, y 0, ch �� 'K'�� �ʱ�ȭ

	Here.OutPosition();    //����� ������ ���·� ��� :  [30,20] => A
	There.OutPosition();
	Where.OutPosition();
}
