#include<iostream>
using namespace std;

class Stu
{
    const int num;
    char name[20];
public:
    Stu(int _num, const char* _name) : num(_num)
    {
        strcpy_s(name, sizeof(name), _name);
    }

    void Print() const
    {
        cout << num << ", " << name << endl;
    }

    //ģ�������� ���ο� ������ ���� �����ϰ� �Ѵ�.
   friend void operator<<(ostream& os, Stu& stu)
    
};


//�����Լ�      �ܺο� ģ���������ִ� ���� ���� �����ƴ� 
    //ģ���� ������ �ڽ��� stu private �ɹ��� ���� ����Ѵ�
ostream& operator<<(ostream &os, Stu &stu)
{
    os << stu.num << "," << stu.name;
    return os;
}

int main()
{
    Stu stu(10, "ȫ�浿");
    stu.Print();
    //������ �����Ǹ� cout ��ü�� ���� Ŭ���� ���ο� �ؾ��Ѵ�.
    cout << stu << endl;

    cout << stu;//�ɹ��Լ� ����:cout.operator<<(stu)
                //�����Լ� ����:operator<<(cout,stu);
}
