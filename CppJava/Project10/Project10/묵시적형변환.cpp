#include<iostream>
using namespace std;

#include <iostream>
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

    int getNum() const { return num; }

    //변환 연산자 
    operator int()
    {
        return num;
    }
    operator const char* ()
    {
        return name;
    }
};

int main()
{
    Stu stu(10, "홍길동");

    //홍길동의 학번을 얻고 싶다.
    int number = stu.getNum();
    cout << "학번 : " << number << endl;

    int number1 = stu;      // int = Stu : Stu를 int타입으로...
    cout << "학번 : " << number1 << endl;

    char name[20];
    strcpy_s(name, sizeof(name), stu);
    cout << "이름 : " << name << endl;

    return 0;
}
