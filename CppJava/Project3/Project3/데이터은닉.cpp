//������ ����

#include <iostream>
using namespace std;

struct  bycle
{//ĸ��ȭ
	int gear;//�ɹ� ����
	void changeGear(int g)
	{//�ɹ� �Լ�
		if(g>=1&&g<=20)//�Է°� ����
		gear = g;
	}
	void printGear()
	{
		cout << "���� ������ : " << gear << "��" << endl;
	}
};

int main()
{
	bycle by1 = { 5 };
	bycle by2 = { 3 };

	by1.printGear();
	by2.printGear();
	//�������� ����ȭ
	//by1.gear = 100;
	//by2.gear = -10;
	
	by1.changeGear(8);
	by2.changeGear(10);

	by1.printGear();
	by2.printGear();

	return 0;
}
