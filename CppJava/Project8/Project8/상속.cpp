#include<iostream>
/*�ڽİ�ü�� ���� �κ��� �ذ��ϴ� ��
������:�Ҹ���
�����:�Ҹ���
*/
using namespace std;
class Animal
{
public:
	void Sound()
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

class Cat:public Animal
{
public:
	void Sound()
	{
		cout << "�߿�" << endl;
	}
};

int main()
{
	Dog dog;
	dog.Sound();
	Cat cat;
	cat.Sound();
	return 0;
}