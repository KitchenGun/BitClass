#include <iostream>

using namespace std;

/*
class istream
{
public:
	operator bool(){cin�� ���¸� true�� false�� ��ȯ};
}
istream cin;
*/


void exam1()
{
	int num;
	cout << "�����Է� : ";
	cin >> num;

	if (cin)
	{
		cout << "sucess" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
	cout << "����Ȱ� " << num << endl;
}
//������ �ùٸ� ������ ��ȯ�ϴ� �Լ�
//cin ��ü�� �߸��� �Է��� �߻��ϸ� ���̻� ����Ҽ� ���� ���� �ٽ� �������� �����ؾ��Ѵ�.
int InputNumber(const char* msg)
{

	int num;
	while (true)
	{
		cout << msg << " : ";
		cin >> num;
		if (cin)
		{
			return num;
		}
		cin.clear();//��ü ����
		cin.ignore();//���� �ʱ�ȭ
	}

}

void exam2()
{
	cout << "����� : " << InputNumber("�����Է�") << endl;
}


int main()
{
	exam2();
	return 0;
}