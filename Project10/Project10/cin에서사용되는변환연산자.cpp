#include <iostream>

using namespace std;

/*
class istream
{
public:
	operator bool(){cin의 상태를 true와 false로 반환};
}
istream cin;
*/


void exam1()
{
	int num;
	cout << "정수입력 : ";
	cin >> num;

	if (cin)
	{
		cout << "sucess" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
	cout << "저장된값 " << num << endl;
}
//무조건 올바른 정수를 반환하는 함수
//cin 객체는 잘못된 입력이 발생하면 더이상 사용할수 없다 따라서 다시 정상으로 복구해야한다.
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
		cin.clear();//객체 복구
		cin.ignore();//버퍼 초기화
	}

}

void exam2()
{
	cout << "결과값 : " << InputNumber("정수입력") << endl;
}


int main()
{
	exam2();
	return 0;
}