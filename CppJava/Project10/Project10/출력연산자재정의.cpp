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

    //친구맺으면 내부에 변수에 접근 가능하게 한다.
   friend void operator<<(ostream& os, Stu& stu)
    
};


//전역함수      외부와 친구먹을수있다 별로 좋은 문법아님 
    //친구를 맺으면 자신의 stu private 맴버도 접근 허락한다
ostream& operator<<(ostream &os, Stu &stu)
{
    os << stu.num << "," << stu.name;
    return os;
}

int main()
{
    Stu stu(10, "홍길동");
    stu.Print();
    //연산자 재정의를 cout 객체를 만든 클래스 내부에 해야한다.
    cout << stu << endl;

    cout << stu;//맴버함수 형태:cout.operator<<(stu)
                //전역함수 형태:operator<<(cout,stu);
}
