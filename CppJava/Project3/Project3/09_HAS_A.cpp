/*
Ŭ������ Ŭ������ ���輺
has a == ����
is a == ���
==============
�л��� ���� ������ �ִ� (����)
��ü [�л�,��]

*/


#include<iostream>
using namespace std;
//�Ͻ����� ���� ���� �л��� ���� ������ �ִ�
//pen Ŭ���� ���� -> �߻�ȭ(�Ϻθ� ǥ�� �ϴ°�)vs ����ȭ(���� ���̴°��� �Ȱ��� ǥ���ϴ°�)=�ַ� �߻�ȭ �����
class pen
{
	//1.�ɹ� ����
private:
	char color[20];
	int widht;
	//2. ������
public:
	pen(const char* _color,int _width)
	{
		strcpy_s(color, sizeof(color), _color);
		widht = _width;
	}
	~pen()
	{

	}
	//3.�޼��� (�ɹ� �Լ�)
public:
	void Write(const char *msg)
	{
		cout << "[" << color << ":";
		cout << widht << "]";
		cout << msg << endl;
	}
};
//�̸� �й� 
//������ �۾��� �� �� �ִ�.
class student
{
private:
	char name[20];
	int number;
	pen* mypen;
public:
	student(const char* _name, int _number)
	{
		strcpy_s(name, sizeof(name), _name);
		number = _number;
		mypen = NULL;//�������� ���� ����
	}
	~student()
	{

	}
public:
	void grappen(pen *_pen)
	{//������� �Ͻ��� �߻�
		mypen = _pen;
	}
	void droppen()
	{
		mypen = NULL;//�������� ���� ����
	}

	void write(const char *msg)
	{
		if (mypen == NULL)
		{//���� ���� ���
			return;
		}
		mypen->Write(msg);//���� ������ ���� ���� ����� ����ҷ���
	}
};
int main()
{
	//��ü ����
	student stu("kang", 111);
	pen redpen("red", 2);
	pen blue("blue", 1);
	pen greenpen("green", 5);

	stu.grappen(&redpen);
	stu.write("�۾��� ���� �ֽ��ϴ�");
	stu.droppen();

	stu.write(" ���� �� ");
	return 0;
}