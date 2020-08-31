#include<iostream>

using namespace std;

//�Ϲ� ���� ���� �����Ϸ��� �������ִ� ���� �����ڸ� ����ϸ� �ȴ� 
//������ ���� �������� �ɹ� �����߿� heap�޸𸮿� ���� �����ϴ� ������ �ִٸ� ���� �����ڸ� ������ ������Ѵ�
class Sample
{
	char name[20];
	int age;
public :
	Sample(const char*_name,int _age)
	{
		strcpy_s(name, sizeof(name), _name);
		age = _age;
		cout << "sample" << endl;
	}
	~Sample()
	{
		cout << "~sample" << endl;
	}
	//���� ���� ������ ���� ����
	Sample(const Sample& sam)
	{
		strcpy_s(name, sizeof(name), sam.name);
		age = sam.age;
	}
public:
	void Print()
	{
		cout << name << "," << age << endl;
	}
};

int main()
{
	Sample sam1("ȫ�浿",10);
	Sample sam2(sam1);//���� ������

	sam1.Print();
	sam2.Print();
	return 0;
}