#include<iostream>


using namespace std;

int main()
{
	//cout ��°�ü ����� ������ �����
	//<<   ��¿����� ��°�ü�� �̿��Ͽ� ȭ�鿡 ������ ����Ҷ� ���Ǵ� ������
	//endl \n �� fflush(stdout)2���� ����� �����ϴ� �Լ�
	//cin  �Է� ������ >>

	char name[20];
	int age;
	char gender;
	float weight;
	//����� �Է��� ���� �ʱ�ȭ
	cout << "�̸� : ";
	cin >> name;
	cout << "���� : ";
	cin >> age;
	cout << "����(m/f) : ";
	cin >> gender;
	cout << "������ : ";
	cin >> weight;


	cout<< "�̸� : "<<name<<endl;
	cout << "���� : "<<age<<endl; 
	cout << "����(m/f) : "<<gender<<endl;
	cout << "������ : "<<weight<<endl;
	return 0;
}


