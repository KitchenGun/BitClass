#include<iostream>

using namespace std;

//�ټ��� ��������� ����� ��ü�� �����ؼ� �����ϰ��� �Ѵٸ�?
//�߰��� ������ ������ �þ�ٸ�
//������ �迭�� ������ ���� ��ĳ������ ����ϸ� �迭 �Ѱ��� ������
class Animal
{
public:
	//�ڽ��� ����� ������ �ɸ��� �Լ��� ���� �ɹ� �Լ��� ����� 
	//�θ��� �����ͷ� �ش� �޼��带 ȣ���ϸ� �ڽ��� ������ �Լ��� ȣ���Ѵ�
	virtual void Sound()
	{
		cout << "???????????" << endl;
	}
};

class Dog :public Animal
{
public:
	void Sound()
	{
		cout << "�۸�" << endl;
	}

};

class Cat :public Animal
{
public:
	void Sound()
	{
		cout << "�߿�" << endl;
	}

};

int main()
{
	Animal* woori[10];//10���� ��ü�� �ּҸ� �����Ҽ��ִ� �迭 ����
	woori[0] = new Dog;
	woori[1] = new Cat;
	woori[2] = new Cat;
	woori[3] = new Cat;
	for (int i=0; i < 4; i++)
	{//��� ������ �Ҹ��� ������ ��ü�� �̿��ؼ� ȣ��
		//��¿���� ���Ҹ� ��¿���� ����� �Ҹ��� ����
		//�̸� �������̶�� �Ѵ�
		woori[i]->Sound();
	}
	return 0;
}