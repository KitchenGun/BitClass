#include<iostream>
using namespace std;
/*
�ɹ� ���� �տ� static Ű���� �߰�
Ŭ���� �ɹ��� �θ� (�ν��Ͻ� �ƴ�)
�ν��Ͻ�=��ü�� ���鶧 ������ �޸� ���� ������ �ִ� ��

*/



class  card
{
	static int width;//����
	static int height;//����
private:
	int number;//1~10,j11q12k13
	string shape;//���̾� Ŭ�ι� �����̵� ��Ʈ
	//�ν��Ͻ� �ɹ��� �ƴϴ� Ŭ���� �ɹ��� ��� ��ü�� ������ ���� ������������
	

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