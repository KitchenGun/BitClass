#include<iostream>

using namespace std;
//-�ڽŰ� ���� �� ��ü�� �����Ҷ� �����ϴ� ���� ������
//�ٸ� �����ڿʹ� �޸� �����Ϸ��� �⺻������ ������ �ִ� ������
//���� ��ü ������ �����ؼ� ���ο� ��ü�� ����
class Sample
{
	char* name;
	int age;
public:
	Sample(const char* _name, int _age)
	{
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		age = _age;
		cout << "sample" << endl;
	}
	~Sample()
	{
		delete[] name;
		cout << "~sample" << endl;
	}
	//���� ���� ������ ���� ����
	Sample(const Sample& sam)
	{
		name = new char[strlen(sam.name) + 1]; 
		strcpy_s(name, strlen(sam.name) + 1, sam.name);
		age = sam.age;
	}
public:
	void SetName(const char* value)
	{
		strcpy_s(name, strlen(value) + 1, value);

	}
	void Print()
	{
		cout << name << "," << age << endl;
	}
};

int main()
{
	Sample sam1("ȫ�浿", 10);
	Sample sam2(sam1);//���� ������
	sam1.SetName("�̱浿");
	sam1.Print();
	sam2.Print();
	return 0;
}