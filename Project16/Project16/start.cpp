#include <iostream>
using namespace std;
#include"stuManager.h"
/*
학생의 성적관리 프로그램
1. 학생 클래스 정의
2. 학생 객체를 다수 관리할수 있는 관리 클래스
3. 객체 없이 접근 할 수 있는, 클래스 맴버들을 보관하는 전역 클래스

*/
int main()
{
	stuManager sm;
	sm.Run();
	return 0;
}